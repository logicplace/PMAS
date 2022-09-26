/****************************************************************************\
Pika Macro DISassembler
by Rafael Vuijk (aka DarkFader)
http://darkfader.net/pm/

TODO:
	read a symbol file
	uh... macro's? :)
\****************************************************************************/

/*
 * Includes
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pmdis.h"
#include "eval.h"
#include "instruction.h"
#include "misc.h"
#include "symbol.h"


#ifndef VERSION
	#define VERSION
#endif

/*
 * Variables
 */
File *file;
Instruction instructions_00[256];
Instruction instructions_CE[256];
Instruction instructions_CF[256];
unsigned char *memory;
unsigned int size;
unsigned int NUM_INSTRUCTIONS;

/*
 * tolower2
 */
inline int tolower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

/*
 * dummy stuff
 */
int inside_macro = 0;
bool SpecialSymbols(const char *name, ValueType &out)
{
	return false;
}

/*
 * ParseLine
 */
void ParseLine(const char *cline)
{
EEKS{printf("parseline %s\n", cline);}

	char *line = strdup(strltrim(cline));

	if (strword(line, ".equ") || strword(line, ".set") || strword(line, ".define"))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		const char *expr = strtok(0, "");
		if (!strcmp(line, ".define")) if (strisempty(expr)) expr = "1";	// value is optional for .define
		if (!expr) expr = "";
EEKS{printf("equ '%s'='%s'\n", name, expr);}
		SetSymbolExpression(name, expr, SYM_DEF);
EEKS{printf("verify "); GetSymbolValue(name).print();}
	}
	else if (strword(line, ".unset") || strword(line, ".undefine"))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		UnsetSymbol(name);
	}
	else if (strword(line, ".instruction"))	// directive
	{
		const char *p = strskipspace(line);
		Instruction *instruction = new Instruction;
		strncpy(instruction->fmt, EvaluateExpression(p, &p).getString(), 19);
		instruction->flags = EvaluateExpression(p, &p);
		if (instruction->flags & FLAG_DISASMTO) {
			instruction->fixed = EvaluateExpression(p, &p);
			instruction->size = EvaluateExpression(p, &p);
			instruction->argnum = EvaluateExpression(p, &p);
			for (unsigned int i=0; i<instruction->argnum; i++)
			{
				instruction->argInfo[i].shift = EvaluateExpression(p, &p);
				instruction->argInfo[i].flags = EvaluateExpression(p, &p);
			}
			AddInstruction(instruction);
			++NUM_INSTRUCTIONS;
		}
	}
}

/*
 * ParseFile
 */
void ParseFile(const char *filename)
{
	FILE *fi = fopen(filename, "rt");

	//printf("%s\n", fullpath);
	
	if (fi)
	{
		char *line = NULL;
		int len = 0;
		while (1)
		{
			char tmpline[TMPSIZE];
			if (!fgets(tmpline, TMPSIZE-1, fi)) break;

			len += strlen(tmpline);
			if (line != NULL)
			{
				line = (char *)realloc(line, len + 1);
				strcat(line, tmpline);
			}
			else
				line = strdup(tmpline);

			// strip multiline escaping
			char *p = line + len;
			if (p > line && p[-1] == '\n') p--;
			if (p > line && p[-1] == '\r') p--;
			if (p > line && p[-1] == '\\')
			{
				*--p = '\0';
				len = p - line;
			}
			else	// process the multiline
			{
				ParseLine(line);
				FREE(line);
				len = 0;
			}
		}

		fclose(fi);
		return;
	}
	fprintf(stderr, "Cannot open include file '%s'.\n", filename); eexit();
}

/*
 * InitInstructions
 */
void InitInstructions(char *cpu_file)
{
	ParseFile(cpu_file);

	Instruction *instruction = instructions;
	memset(instructions_00, 0, sizeof(instructions_00));
	memset(instructions_CE, 0, sizeof(instructions_CE));
	memset(instructions_CF, 0, sizeof(instructions_CF));

	for (unsigned int i=0; i<NUM_INSTRUCTIONS; i++)
	{
		unsigned char extended = 0x00;
		if (instruction->flags & FLAG_EXTENDED) extended = instruction->fixed & 0xFF;
		switch (extended)
		{
			case 0x00: instructions_00[instruction->fixed & 0xFF] = *instruction; break;
			case 0xCE: instructions_CE[instruction->fixed >> 8 & 0xFF] = *instruction; break;
			case 0xCF: instructions_CF[instruction->fixed >> 8 & 0xFF] = *instruction; break;
			default: exit(1);
		}
		instruction = instruction->next;
	}
}

/*
 * ReadMiniFile
 */
int ReadMiniFile(const char *filename)
{	
	FILE *fi = fopen(filename, "rb");
	if (!fi) { fprintf(stderr, "Cannot open input file!\n"); return -1; }
	fseek(fi, 0, SEEK_END);
	size = ftell(fi);
	memory = new unsigned char [size];
	fseek(fi, 0, SEEK_SET);
	auto ret = fread(memory, 1, size, fi);
	fclose(fi);
	return (int)ret;
}

/*
 * Disassemble
 */
unsigned int Disassemble(char *q, unsigned char *memory, unsigned int addr)
{
	char *qp = q; *qp = 0;
	unsigned int opcode_addr = addr;
	Instruction *instruction;
	switch (memory[addr])
	{
		case 0xCE: addr++; instruction = instructions_CE + memory[addr++]; break;
		case 0xCF: addr++; instruction = instructions_CF + memory[addr++]; break;
		default: instruction = instructions_00 + memory[addr++]; break;
	}

	//unsigned char argbytes[MAX_ARGS];
	//for (unsigned int j=0; j<instruction->argbytes; j++) argbytes[j] = memory[addr++];
	
	char *s = instruction->fmt;
	while (*s)
	{
		if (*s == '~')
		{
			s++;
			int argsrc = *s++ - '0';
			unsigned int argflags = instruction->argInfo[argsrc].flags;
			unsigned int tmp = *(unsigned int *)(memory + addr);
			unsigned int bitmask = ~(0xFFFFFFFF << (argflags & ARGFLAG_BITS));
			int value = tmp & bitmask;

			if (argflags & ARGFLAG_HIGH) value <<= 8;
			
			if (argflags & ARGFLAG_S)
			{
				if (value & ((argflags & ARGFLAG_BITS)-1)) value -= (1 << (argflags & ARGFLAG_BITS));
			}

			if (argflags & ARGFLAG_REL)
			{
				value += instruction->size - 1;
				qp += sprintf(qp, ".%+d ", value);
				value += opcode_addr - 1;
				qp += sprintf(qp, ";@%06X", value);
			}
			else if ((argflags & ARGFLAG_BITS) >= 16)
			{
				qp += sprintf(qp, "$%04X", value);
			}
			else
			{
				qp += sprintf(qp, "$%02X", value);
			}
		}
		else
		{
			*qp++ = tolower2(*s++);
			*qp = 0;
		}
	}

	if (!*s && instruction->size) return opcode_addr + instruction->size;

	qp = q;
	qp += sprintf(qp, ".db $%02X", memory[opcode_addr]);
	return opcode_addr + 1;
}

/*
 * main
 */
int main(int argc, char *argv[])
{
	fprintf(stderr,
		"Pika Macro DISassembler " VERSION " (build " __DATE__ ") originally by Rafael Vuijk. http://darkfader.net/pm/\n"
	);
	
	if (argc < 3)
	{
		fprintf(stderr,
			"Syntax: pmdis [-c cpu] input.min output.s\n"	//[symbols.sym]
			"Use '-' for output filename to use stdout.\n"
		);
		exit(0);
	}

	// parse parameters
	const char *cpu_name = "pm";
	const char *inputfile = NULL;
	char *outputfile = NULL;
	for (int a=1; a<argc; a++)
	{
		if ((argv[a][0] == '-') && (argv[a][1] != 0))
		{
			switch (argv[a][1])
			{
				case 'c':
					cpu_name = argv[++a];
					if (strchr(cpu_name, '/') || strchr(cpu_name, '\\')) {
						eprintf("CPU name cannot contain slashes.\n");
						eexit();
					}
					break;

				default:
					break;
			}
		}
		else
		{
			if (!inputfile) inputfile = argv[a];
			else if (!outputfile) outputfile = argv[a];
		}
	}

	char *cpu_file = get_cpu_file_from_name(argv[0], cpu_name);
	InitInstructions(cpu_file);
	FREE(cpu_file);

	if (ReadMiniFile(inputfile) < 0) exit(1);

	FILE *fo = strcmp(outputfile, "-") ? fopen(outputfile, "wt") : stdout;
	if (!fo) { fprintf(stderr, "Cannot open output file!\n"); exit(1); }
	fprintf(fo, "; disassembly of %s\n", inputfile);
	if (strcmp(cpu_name, "pm")) {
		fprintf(fo, ".include	%s.s\n", cpu_name);
	}
	fputc('\n', fo);

	unsigned int addr = 0;
	while (addr < size)
	{
		char s[256];
		fprintf(fo, "L%06X: ", addr);
		addr = Disassemble(s, memory, addr);
		fprintf(fo, "%s\n", s);
	}
	fclose(fo);

	return 0;
}
