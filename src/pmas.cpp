/****************************************************************************\
PMAS - Pika Macro ASsembler
by Rafael Vuijk (aka DarkFader)
http://darkfader.net/pm/

TODO:
	more tests
	instruction tree for faster lookups
	function-like macro's
	reduce symbol output
\****************************************************************************/

/*
 * Includes
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef WIN32
#include <io.h>			// for unlink
#else
#include <unistd.h>		// for unlink
#endif
#include "pmas.h"
#include "eval.h"
#include "macrolist.h"
#include "instruction.h"
#include "mem.h"
#include "misc.h"
#include "symbol.h"
#include "tmplabel.h"

/****************************************************************************\
 File
\****************************************************************************/

File *file;

//#define MAX_INCLUDELEVEL	16

/*
struct FileType
{
	FILE *fi;
	int line_num;
	char *filename;

	void Free() { if (fi) { fclose(fi); fi = 0; }; if (filename) { free(filename); filename = 0; } }/
	FileType() { fi=0; line_num=0; filename=0; }
	~ValueType() { Free(); }
};

typedef Stack<FileType> FileStack;
FileStack fileStack;
*/

#define MAX_CONDSTACK			64

#define MAX_INCLUDEPATHS		32
char *includepaths[MAX_INCLUDEPATHS];		// no trailing slashes
int includepaths_count = 0;
   
char tmp[TMPSIZE];

#ifndef VERSION
	#define VERSION
#endif

//extern File files[];			// TODO: put into stack
//extern int currentfile;


/****************************************************************************\
 Misc
\****************************************************************************/

int option_ram_base;			// RAM base address
const char* option_output_ext;	// Default output extension
const char *default_cpu = "pm";

int condition_stack;			// condition stack level
bool condition[MAX_CONDSTACK];		// conditional assembling
bool condition_met[MAX_CONDSTACK];	// conditional already met?
int repeat;					// macro repeat count

/****************************************************************************\
 Directive
\****************************************************************************/

#define PARSE_COND_DIRECTIVES		1
#define PARSE_MACRO_DIRECTIVES		2
#define PARSE_REPT_DIRECTIVES		4
#define PARSE_OTHER_DIRECTIVES		8
#define PARSE_ALL_DIRECTIVES		(PARSE_COND_DIRECTIVES | PARSE_MACRO_DIRECTIVES | PARSE_REPT_DIRECTIVES | PARSE_OTHER_DIRECTIVES)

int option_directive;		// invalid directive error (default = 1)
int parse_directives;		// what to parse


// macro that checks validity and wether it should be handled
#define DIRECTIVE(name, category)	\
	(strword(line, name) && (valid_directive = true, (parse_directives & category)))

/*
 * SpecialSymbols
 */
bool SpecialSymbols(const char *name, ValueType &out)
{
	     if (strcmp(name, "__PMAS__") == 0) out = ValueType(VERSION);
	else if (strcmp(name, "__LINE__") == 0) out = ValueType(file->line_num);
	else if (strcmp(name, "__FILE__") == 0) out = ValueType(file->filename);
	else if (strcmp(name, "__RAMBASE__") == 0) out = ValueType(option_ram_base);
	else return false;
	return true;
}

/*
 * ParseDirective
 * Note: macro directives are handled before recording
 */
void ParseDirective(const char *cline)
{
	char *line = strdup(strltrim(cline) + 1);	// skip '.' and allow strtok
//printf("'%s'\n", file->line);
//printf("'%s'\n", line);
	bool valid_directive = false;
	//bool done_directive = true;
//printf("Line: [%s]\n", cline);
	
	/*
	 * macro ending directives
	 */

	if (DIRECTIVE("endm", PARSE_MACRO_DIRECTIVES))
	{
		current_macro = 0;
		parse_directives = PARSE_ALL_DIRECTIVES;
	}
	else if (DIRECTIVE("endr", PARSE_REPT_DIRECTIVES))
	{
		current_macro = 0;
		parse_directives = PARSE_ALL_DIRECTIVES;
		while (repeat-- > 0) MacroExecute("_rept");
	}

	/*
	 * record to macro
	 */
	if (current_macro)
	{
		MacroLine(cline);		// record full line
		goto exit;				// only process macro ending directives
	}

	/*
	 * macro starting directives
	 */
	if (DIRECTIVE("macro", PARSE_MACRO_DIRECTIVES) || DIRECTIVE("macroicase", PARSE_MACRO_DIRECTIVES))
	{
		char *name = strtok((char *)strskipspace(line), delim_chars);
		current_macro = FindMacro(name);
		if (pass != PASS_ASM)
		{
			if (current_macro) { eprintf(file, "Macro name already defined.\n"); eexit(); }
			current_macro = NewMacro(name, DIRECTIVE("macroicase", PARSE_MACRO_DIRECTIVES));
EEKS{printf("new macro at %p\n", current_macro);}
			char *paramname;
			while ((paramname = strtok(0, delim_chars)))
			{
				if (isspace2(paramname[0])) paramname = strskipspace(paramname);
				if (strchr(endline_chars, *paramname)) break;

				current_macro->AddParameter(paramname);
			}
		}
		parse_directives = PARSE_MACRO_DIRECTIVES;
	}
	else if (DIRECTIVE("rept", PARSE_REPT_DIRECTIVES))
	{
		repeat = EvaluateExpression(strskipspace(line));
		current_macro = NewMacro("_rept", false);
		parse_directives = PARSE_REPT_DIRECTIVES;
	}

	/*
	 * conditional directives
	 */

	else if (DIRECTIVE("if", PARSE_COND_DIRECTIVES))
	{
		condition_stack++;
		if (condition_stack >= MAX_CONDSTACK) { eprintf(file, "Conditions stack exceeded.\n"); eexit(); }
		condition[condition_stack] = EvaluateExpression(strskipspace(line));
		condition_met[condition_stack] = condition[condition_stack];
		if (!condition[condition_stack-1]) condition[condition_stack] = false;	// parent must be true
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}
	else if (DIRECTIVE("elif", PARSE_COND_DIRECTIVES) || DIRECTIVE("elsif", PARSE_COND_DIRECTIVES) /*|| DIRECTIVE("elseif", PARSE_COND_DIRECTIVES)*/)
	{
		if (condition_stack <= 0) { eprintf(file, ".elif without .if\n"); eexit(); }	// NOTE: .elif was added later
		if (condition_met[condition_stack])
		{
			condition[condition_stack] = false;
		}
		else
		{
			condition[condition_stack] = EvaluateExpression(strskipspace(line));
			condition_met[condition_stack] |= condition[condition_stack];
		}
		if (!condition[condition_stack-1]) condition[condition_stack] = false;	// parent must be true
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}
	else if (DIRECTIVE("else", PARSE_COND_DIRECTIVES))
	{
		if (condition_stack <= 0) { eprintf(file, ".else without .if\n"); eexit(); }
		condition[condition_stack] = !condition_met[condition_stack];
		if (!condition[condition_stack-1]) condition[condition_stack] = false;	// parent must be true
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}
	else if (DIRECTIVE("endif", PARSE_COND_DIRECTIVES))
	{
		if (condition_stack <= 0) { eprintf(file, ".endif without .if\n"); eexit(); }
		condition_stack--;
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}
	else if (DIRECTIVE("ifdef", PARSE_COND_DIRECTIVES) || DIRECTIVE("ifndef", PARSE_COND_DIRECTIVES))
	{
		condition_stack++;
		if (condition_stack >= MAX_CONDSTACK) { eprintf(file, "Conditions stack exceeded.\n"); eexit(); }
		char *defname = strtok((char *)strskipspace(line), delim_chars);
		condition[condition_stack] = IsSymbolDefined(defname) ^ (DIRECTIVE("ifndef", PARSE_COND_DIRECTIVES));
		condition_met[condition_stack] = condition[condition_stack];
		if (!condition[condition_stack-1]) condition[condition_stack] = false;	// parent must be true
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}
	else if (DIRECTIVE("ifstring", PARSE_COND_DIRECTIVES) || DIRECTIVE("ifnstring", PARSE_COND_DIRECTIVES))
	{
		condition_stack++;
		if (condition_stack >= MAX_CONDSTACK) { eprintf(file, "Conditions stack exceeded.\n"); eexit(); }
		char *defname = strtok((char *)strskipspace(line), delim_chars);
		if (DIRECTIVE("ifnstring", PARSE_COND_DIRECTIVES))
			condition[condition_stack] = EvaluateExpression(defname).getString() == NULL;
		else
			condition[condition_stack] = EvaluateExpression(defname).getString() != NULL;
		condition_met[condition_stack] = condition[condition_stack];
		if (!condition[condition_stack-1]) condition[condition_stack] = false;	// parent must be true
		parse_directives = condition[condition_stack] ? PARSE_ALL_DIRECTIVES : PARSE_COND_DIRECTIVES;
	}

	/*
	 * other directives
	 */

	else if (DIRECTIVE("db", PARSE_OTHER_DIRECTIVES))
	{
EEKS{printf("%d %s\n", parse_directives, line);}
		const char *p = strskipspace(line);
		
		while (p)
		{
EEKS{printf("'%s'\n", p);}
			ValueType n = EvaluateExpression(p, &p);

			const char *s = n.getString();
			if (s)
			{
				while (*s)
				{
					if (pass == PASS_ASM) reloc_data[addr] = *s;
					addr++;
					s++;
				}
			}
			else
			{
				if (pass == PASS_ASM) reloc_data[addr] = n;
				addr++;
			}
		}
	}
	else if (DIRECTIVE("dw", PARSE_OTHER_DIRECTIVES))
	{
		const char *p = strskipspace(line);
		//p = strtok(p, ",");
		while (p)
		{
			long number = EvaluateExpression(p, &p);
			if (pass == PASS_ASM)
			{
				reloc_data[addr+0] = number;
				reloc_data[addr+1] = number >> 8;
			}
			addr += 2;
			//p = strtok(0, ",");
		}
	}
	else if (DIRECTIVE("dd", PARSE_OTHER_DIRECTIVES))
	{
		const char *p = strskipspace(line);
		//p = strtok(p, ",");
		while (p)
		{
			long number = EvaluateExpression(p, &p);
			if (pass == PASS_ASM)
			{
				reloc_data[addr+0] = number;
				reloc_data[addr+1] = number >> 8;
				reloc_data[addr+2] = number >> 16;
				reloc_data[addr+3] = number >> 24;
			}
			addr += 4;
			//p = strtok(0, ",");
		}
	}
	else if (DIRECTIVE("ram", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("ramicase", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		char *expr = strtok(0, "");
		int size = 0;
		if (expr) size = EvaluateExpression(expr);
		if (size <= 0)
		{
			eprintf(file, "Invalid ram size.\n");
		}
		SetSymbolValue(name, ValueType(option_ram_base), DIRECTIVE("ramicase", PARSE_OTHER_DIRECTIVES) ? SYM_RAM_ICASE : SYM_RAM);
		option_ram_base += size;
	}
	else if (DIRECTIVE("equ", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("set", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("define", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		const char *expr = strtok(0, "");
		if (DIRECTIVE("define", PARSE_OTHER_DIRECTIVES)) if (strisempty(expr)) expr = "1";	// value is optional for .define
		if (!expr) expr = "";
EEKS{printf("equ '%s'='%s'\n", name, expr);}
		SetSymbolExpression(name, expr, SYM_DEF);
EEKS{printf("verify "); GetSymbolValue(name).print();}
	}
	else if (DIRECTIVE("equicase", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("seticase", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("defineicase", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		const char *expr = strtok(0, "");
		if (DIRECTIVE("define", PARSE_OTHER_DIRECTIVES)) if (strisempty(expr)) expr = "1";	// value is optional for .define
		if (!expr) expr = "";
EEKS{printf("equ '%s'='%s'\n", name, expr);}
		SetSymbolExpression(name, expr, SYM_DEF_ICASE);
EEKS{printf("verify "); GetSymbolValue(name).print();}
	}
	else if (DIRECTIVE("option", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		ValueType value = EvaluateExpression(strtok(0, ""));
		if (!strcmp(name, "directive")) option_directive = value;
		else if (!strcmp(name, "range")) option_range = value;
		else if (!strcmp(name, "base")) option_base = value;
		else if (!strcmp(name, "farjump")) option_farjump = value;
		else if (!strcmp(name, "localjump")) option_localjump = value;
		else if (!strcmp(name, "word")) option_word = value;
		else if (!strcmp(name, "fill")) option_fill = value;
		else if (!strcmp(name, "ram_base")) option_ram_base = value;
		else if (!strcmp(name, "multipass")) eprintf(file, "Multipass only supported on PMAS+.\n");
		else if (!strcmp(name, "symoutput")) option_symoutput = value;
		else if (!strcmp(name, "output_ext")) option_output_ext = value.getString();
		else eprintf(file, "Unknown option '%s'.\n", name);
	}
	else if (DIRECTIVE("unset", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("undefine", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		UnsetSymbol(name);
	}
	else if (DIRECTIVE("instruction", PARSE_OTHER_DIRECTIVES))
	{
		const char *p = strskipspace(line);
		Instruction *instruction = new Instruction;
		strncpy(instruction->fmt, EvaluateExpression(p, &p).getString(), 19);
		instruction->flags = EvaluateExpression(p, &p);
		instruction->fixed = EvaluateExpression(p, &p);
		instruction->size = EvaluateExpression(p, &p);
		instruction->argnum = EvaluateExpression(p, &p);
		for (unsigned int i=0; i<instruction->argnum; i++)
		{
			instruction->argInfo[i].shift = EvaluateExpression(p, &p);
			instruction->argInfo[i].flags = EvaluateExpression(p, &p);
		}
		AddInstruction(instruction);
	}
	else if (DIRECTIVE("org", PARSE_OTHER_DIRECTIVES) || DIRECTIVE("orgfill", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		addr = EvaluateExpression(s);
	}
	else if (DIRECTIVE("reloc", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		if (!*s || (s == strpbrk(s, endline_chars)))		// default = 0
			reloc_offset = addr;
		else
			reloc_offset = addr - EvaluateExpression(s);
		addr = addr - reloc_offset;
	}
	else if (DIRECTIVE("endreloc", PARSE_OTHER_DIRECTIVES))
	{
		addr += reloc_offset;
		reloc_offset = 0;
	}
	else if (DIRECTIVE("align", PARSE_OTHER_DIRECTIVES))
	{
		int value = EvaluateExpression(strskipspace(line));
		int check = value; while (~check & 1) check >>= 1;
		if (check != 1) { eprintf(file, "Value must be power of 2.\n"); eexit(); }
		addr = (addr + (value-1)) / value * value;
	}
	else if (DIRECTIVE("ds", PARSE_OTHER_DIRECTIVES))
	{
		const char *next;
		int size = EvaluateExpression(strskipspace(line), &next);
		int fill = next ? (int)EvaluateExpression(next) : -1;

		if ((pass == PASS_ASM) && (fill >= 0))
		{
			while (size--) reloc_data[addr++] = fill;
		}
		else
		{
			addr += size;
		}
	}
	else if (DIRECTIVE("parse", PARSE_OTHER_DIRECTIVES))
	{
		ValueType n = EvaluateExpression(strskipspace(line));
		const char *s = n.getString();
		if (!s) { eprintf(file, "String expression expected.\n"); goto exit; }
EEKS{printf("'%s' '%s'\n", strskipspace(line), s);}
		char tmp[TMPSIZE];
		strcpy(tmp, s);
		//file->line = tmp;
		ParseLine(tmp);			// TODO: parse more lines?
	}
	else if (DIRECTIVE("localprefix", PARSE_OTHER_DIRECTIVES))
	{
		char *s = strskipspace(line);
		char *name = strtok(s, delim_chars);
		strcpy(locallabelprefix, name);
		locallabelprefix_set = true;
	}
	else if (DIRECTIVE("include", PARSE_OTHER_DIRECTIVES))
	{
		const char *p = strskipspace(line);
		char *name = ParseString(p);
		ParseFile(name);
		free(name);
	}
	else if (DIRECTIVE("incbin", PARSE_OTHER_DIRECTIVES))
	{
		const char *p = strskipspace(line);
		char *name = ParseString(p);
		FILE *fb = NULL;

		for (int i=0; i<includepaths_count; i++)
		{
			char fullpath[TMPSIZE];
			strcpy(fullpath, includepaths[i]);
			strcat(fullpath, name);
			fb = fopen(fullpath, "rb");
			if (fb) break;
		}

		if (!fb) { eprintf(file, "Cannot open binary file '%s'.\n", name); eexit(); }
		if (pass == PASS_ASM)
		{
			while (1)
			{
				int c = fgetc(fb);
				if (c < 0) break;
				reloc_data[addr++] = c;
			}
		}
		else
		{
			fseek(fb, 0, SEEK_END);
			addr += ftell(fb);
		}
		fclose(fb);
		free(name);
	}
	else if (DIRECTIVE("printf", PARSE_OTHER_DIRECTIVES))
	{
//printf("printf %d %d\n", parse_directives, PARSE_OTHER_DIRECTIVES);
		if (pass == PASS_ASM)
		{
			const char *inp = strskipspace(line);
			ValueType n = EvaluateExpression(inp, &inp);
			char *fmtp = (char *)n.getString();
			while (fmtp && *fmtp)
			{
				// find a formatted parameter
				char *p = strchr(fmtp, '%');
				if (p)
				{
					if (*(p+1) == '%')		// two %'s
					{
						*(p+1) = 0;
						p += 2;
					}
					else
					{
						// find end of parameter
						while (*p && !((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))) p++;
						if (*p)
						{
							// temporarily null-terminal and print formatted output
							p++;
							char backup = *p;
							*p = 0;
							ValueType n = EvaluateExpression(inp, &inp);
							const char *s = n.getString();
							if (s)
								printf(fmtp, s);
							else
								printf(fmtp, (int)n);
							*p = backup;
							fmtp = p;
							continue;		// ok, next
						}
					}
				}
				printf("%s", fmtp);		// not formatted
				fmtp = p;
			}
		}
	}
	else if (DIRECTIVE("error", PARSE_OTHER_DIRECTIVES))
	{
		if (pass == PASS_ASM)
		{
			ValueType n = EvaluateExpression(strskipspace(line));
			const char *s = n.getString();
			if (!s) { eprintf(file, "String expression expected.\n"); goto exit; }
			fprintf(stderr, "%s, line %d: Error : %s\n",
				file->filename, file->line_num, s
			);
			if (++errors >= MAX_ERRORS)
			{
				fprintf(stderr, "Maximum number of errors reached.\n"); eexit();
			}
		}
	}
	else if (DIRECTIVE("warning", PARSE_OTHER_DIRECTIVES))
	{
		if (pass == PASS_ASM)
		{
			ValueType n = EvaluateExpression(strskipspace(line));
			const char *s = n.getString();
			if (!s) { eprintf(file, "String expression expected.\n"); goto exit; }
			printf("%s, line %d: Warning : %s\n",
				file->filename, file->line_num, s
			);
		}
	}
	else if (DIRECTIVE("exit", PARSE_OTHER_DIRECTIVES))
	{
		if (pass == PASS_ASM)
		{
			eprintf(file, "Exiting.\n");
			eexit();
		}
	}
	else if (DIRECTIVE("end", PARSE_OTHER_DIRECTIVES))
	{
		fseek(file->fi, 0, SEEK_END);
	}
	
	/*
	 * check valid directive
	 */
	if (!valid_directive && option_directive)		// test for unknown directive
	{
		eprintf(file, "Unknown directive.\n");
	}
exit:
	free(line);
}

/****************************************************************************\
 Label
\****************************************************************************/

/*
 * ParseLabel
 */
void ParseLabel(const char *cline)
{
	if (!condition[condition_stack])
	{
	}
	else if (current_macro)
	{
		MacroLine(cline);
	}
	else
	{
		char *line = strdup(strltrim(cline));
		char *p = strchr(line, ':');
		if (!p) { eprintf(file, "Label does not end with a colon (':').\n"); return; }
		*p = 0;
		if (strlen(line) == 0)	// temporary label
		{
			if (pass == PASS_DEF)
			{
				NewTmpLabel(addr);
			}
		}
		else if (*line == '_')	// local label
		{
			if (pass != PASS_ASM)
			{
				char tmp[TMPSIZE];
				strcpy(tmp, locallabelprefix);
				strcat(tmp, line);
				if (IsSymbolDefined(tmp)) { eprintf(file, "Symbol already defined.\n"); return; }
				SetSymbolValue(tmp, ValueType(addr), SYM_LOC);
			}
		}
		else	// normal label
		{
			strcpy(locallabelprefix, line);
			if (pass != PASS_ASM)
			{
				if (IsSymbolDefined(line)) { eprintf(file, "Symbol already defined.\n"); return; }
EEKS{printf("label %06X\n", addr);}
				SetSymbolValue(line, ValueType(addr), SYM_LAB);
			}
		}
		if (p) { /*file->line = p+1;*/ ParseLine(p + 1); }	// parse after colon
		free(line);
	}
}

/****************************************************************************\
 Parse
\****************************************************************************/

/*
 * ParseInstruction
 */
void ParseInstruction(const char *cline)
{
	if (!condition[condition_stack])
	{
		return;
	}
	else if (current_macro)
	{
		MacroLine(cline);	// record whole line
		return;
	}
	else
	{
		cline = strltrim(cline);
		if (TryInstructions(cline)) return;		// try instructions
		if (MacroExecute(cline)) return;		// try macro's otherwise

		if (!instructions)		// try default cpu
		{
			char *fn = get_cpu_file_from_name("", default_cpu);
			ParseFile(fn);
			free(fn);
			if (TryInstructions(cline)) return;
		}

		eprintf(file, "Unknown instruction or invalid arguments.\n");
	}
}

/*
 * MacroLine
 */
void MacroLine(const char *cline)
{
	if (pass != PASS_ASM)
	{
EEKS{printf("record %s\n", cline);}
		current_macro->AddLine(cline);
	}
}

/*
 * ParseLine
 */
void ParseLine(const char *cline)
{
EEKS{printf("parseline %s\n", cline);}

	// C PreProcessor filename + linenumber fix
	if (cline[0] == '#')
	{
		int new_line_num = strtoul(cline+2,0,10);
		if (new_line_num > 0)
		{
			file->line_num = new_line_num - 1;
			FREE(file->filename);		// wrong filename
			char *p, *s = strdup(strskipspace((char *)cline+2));
			if ((p = strchr(s,'\r'))) *p = 0;
			if ((p = strchr(s,'\n'))) *p = 0;
			file->filename = s;
			return;
		}
	}

	const char *line = strltrim(cline);
	bool leadingspace = (line != cline);
	strcpy(file->origline, line);

	if (isendline(line[0]))		// comment line
	{
	}
	else if (line[0] == '.')	// directive
	{
		ParseDirective(cline);
	}
	else if (leadingspace)		// instruction
	{
		ParseInstruction(cline);
	}
	else	// label
	{
		ParseLabel(cline);
	}

	tmplabel_goffset++;
	UpdateMaxAddr();
}

/*
 * ParseFile
 */
void ParseFile(const char *filename)
{
	for (int i=0; i<includepaths_count; i++)
	{
		char fullpath[TMPSIZE];
		strcpy(fullpath, includepaths[i]);
		//strcat(fullpath, "/");
		strcat(fullpath, filename);
		
		FILE *fi = strcmp(filename, "-") ? fopen(fullpath, "rt") : stdin;

		//printf("%s\n", fullpath);
		
		if (fi)
		{
			File _file;
			File *calling_file = file;
			file = &_file;

			//if (currentfile == MAX_INCLUDELEVEL - 1) { eprintf(file, "Maximum include level reached.\n"); eexit(); }
			//currentfile++;
			file->fi = fi;
			file->filename = strdup(filename);
			file->line_num = 0;
//printf("%s\n", file->filename);

			char *line = NULL;
			int len = 0;
			while (1)
			{
				char tmpline[TMPSIZE];
				if (!fgets(tmpline, TMPSIZE-1, file->fi)) break;
				file->line_num++;

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

			FREE(file->filename);
			fclose(file->fi);
			//currentfile--;

			file = calling_file;
			return;
		}
	}
	fprintf(stderr, "Cannot open include file '%s'.\n", filename); eexit();
}

/****************************************************************************\
 stdin
\****************************************************************************/

FILE *stdinfile = 0;		// copy of stdin

/*
 * RemoveStdinTmp
 */
void RemoveStdinTmp()
{
	unlink("stdin.tmp");
}

/****************************************************************************\
 main
\****************************************************************************/

/*
 * main
 */
int main(int argc, char *argv[])
{
	// show title when not stdout
	if ((argc < 3) || strcmp(argv[2], "-"))
	{
		printf("Pika Macro ASsembler v" VERSION " (build " __DATE__ ") originally by Rafael Vuijk. https://github.com/logicplace/PMAS\n");
	}

	// show help
	if (argc < 3)
	{
		printf("Syntax: pmas input.s [output.min [symbols.sym]]\n");
		printf("Syntax: pmas input.s [-o output.min] [-s symbols.sym | -S]\n");
		printf("\n");
		printf("Use '-' for filenames to use stdin/stdout.\n");
		eexit();
	}

	// parse parameters
	const char *inputfile = NULL;
	char *outputfile = NULL;
	char *symbolfile = NULL;
	bool newstyleparams = false;
	bool oldstyleparams = false;
	for (int a=1; a<argc; a++)
	{
		if ((argv[a][0] == '-') && (argv[a][1] != 0))
		{
			switch (argv[a][1])
			{
				case 'c':
					default_cpu = argv[++a];
					if (strchr(default_cpu, '/') || strchr(default_cpu, '\\')) {
						eprintf("CPU name cannot contain slashes.\n");
						eexit();
					}
					break;

				case 'o':
					newstyleparams = true;
					if (outputfile) { eprintf("Output file already specified.\n"); eexit(); }
					outputfile = argv[++a];
					break;
				
				case 's':
					newstyleparams = true;
					if (symbolfile) { eprintf("Symbol file already specified.\n"); eexit(); }
					symbolfile = argv[++a];
					break;

				case 'S':
					symbolfile = (char*)1;
					break;
				
				default:
					break;
			}
		}
		else
		{
			oldstyleparams = true;
			if (!inputfile) inputfile = argv[a];
			else if (!outputfile) outputfile = argv[a];
			else if (!symbolfile) symbolfile = argv[a];
		}
	}
	
	// check conflicting parameter style
	if (newstyleparams && oldstyleparams) { eprintf("Cannot use old and new style parameters together.\n"); eexit(); }

	// stdin
	if (inputfile && !strcmp(inputfile, "-"))
	{
		stdinfile = fopen("stdin.tmp", "wt");
		if (!stdinfile) { fprintf(stderr, "Cannot create temporary file.\n"); eexit(); }
		char c; while ((c = fgetc(stdin)) >= 0) fputc(c, stdinfile);
		fclose(stdinfile);
		inputfile = "stdin.tmp";
		atexit(RemoveStdinTmp);
	}

	/*
	 * Include paths
	 */

	// add default directory to include path
	includepaths[includepaths_count++] = strdup("");
	
	// add PMAS executable directory to include path
	char tmp[TMPSIZE];
	strcpy(tmp, argv[0]);
	char *p = strrchr(tmp, '/');
	if (!p) p = strrchr(tmp, '\\');
	if (p) *++p = 0;
	includepaths[includepaths_count++] = strdup(tmp);

	// add cpu directories to the include path
	struct dirent *dp;
	DIR *dfd;

	strcat(tmp, "cpu/");
	includepaths[includepaths_count++] = strdup(tmp);

	if ((dfd = opendir(tmp)) != NULL)
	{
		char subdir[TMPSIZE];
		while ((dp = readdir(dfd)) != NULL)
		{
			struct stat stbuf;
			sprintf(subdir, "%s%s/", tmp, dp->d_name);
			if (
				stat(subdir, &stbuf) != -1
				&& (stbuf.st_mode & S_IFMT) == S_IFDIR
				&& dp->d_name[0] != '.'
			)
			{
				includepaths[includepaths_count++] = strdup(subdir);
			}
		}
	}

	/*
	 * Special symbols
	 */
	SetSymbolValue("__PMAS__", ValueType(VERSION), 0);
	SetSymbolValue("__LINE__", ValueType((long int)0), 0);
	SetSymbolValue("__FILE__", ValueType(""), 0);
	SetSymbolValue("__RAMBASE__", ValueType((long int)0), 0);

	/*
	 * parse
	 */

	for (pass=PASS_DEF; pass<=PASS_ASM; pass++)
	{
		addr = 0;
		reloc_offset = 0;
		//currentfile = -1;
		option_directive = 1;
		option_range = 0;
		option_base = 0;
		option_localjump = 1;
		option_farjump = 1;
		option_word = 0;
		option_fill = 0xFF;
		option_ram_base = 0;
		current_macro = 0;
		parse_directives = PARSE_ALL_DIRECTIVES;
		macro_id = 0;
		repeat = 0;
		condition_stack = 0;
		condition[condition_stack] = true;
		strcpy(locallabelprefix, "");
		tmplabel_goffset = 0;
		
		FreeInstructions();

		ParseFile(inputfile);

		if ((condition_stack != 0) && (pass == PASS_ASM)) {
			fprintf(stderr, "Error : detected open ifs.\n");
			errors++;
		}

		if (errors > 0)
		{
			fprintf(stderr, "%d error(s) found.\n", errors);
			eexit();
		}
	}

	/*
	 * write output
	 */

	if (!outputfile)
	{
		const char *end = strrchr(inputfile, '.');
		int len = end - inputfile;
		outputfile = (char*)malloc(len + strlen(option_output_ext) + 1);
		strncpy(outputfile, inputfile, len);
		strcpy(outputfile + len, option_output_ext);
	}
	WriteOutput(outputfile);
	
	/*
	 * write symbols
	 */

	if (symbolfile) {
		if (symbolfile == (char*)1) {
			// Take name from output file
			char *end = strrchr(outputfile, '.');
			int len = end - outputfile + 1;
			symbolfile = (char*)malloc(len + 3 + 1);
			strncpy(symbolfile, outputfile, len);
			strcpy(symbolfile + len, "sym");
		}
		WriteSymbols(symbolfile);
	}

	return 0;
}
