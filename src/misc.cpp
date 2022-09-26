/*
 * Includes
 */
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "misc.h"

/*
 * Variables
 */
int errors = 0;				// increased in eprintf
const char endline_chars[] = "#;\r\n";			// match with 'isendline'. Note: the expression evaluator checks for it too and handles strings correctly.
const char delim_chars[] = ", \t\r\n";			// use with strtok

/*
 * strisempty
 * return true if empty or null
 */
bool strisempty(const char *s)
{
	if (!s) return true;
	while (*s && isspace2(*s)) s++;
	return (*s == 0);
}


/*
 * strskipspace
 * return next word
 */
char *strskipspace(char *s)
{
	while (*s && !isspace2(*s)) s++;	// skip current word
	while (isspace2(*s)) s++;	// skip spaces
	return s;
}

/*
 * strword
 * check begin of word
 */
int strword(const char *s, const char *lookfor)
{
	while (*s && *lookfor && (*s == *lookfor)) { s++; lookfor++; }
	return ((*lookfor == 0) && (isspace2(*s) || (*s == 0)));
}

/*
 * strreplace
 * replace once
 */
int strreplace(char *s, char *from, char *to)
{
	char *where = strstr(s, from);
	if (where)	// found?
	{
		char tmp[TMPSIZE];
		strcpy(tmp, where + strlen(from));
		strcpy(where, to);
		strcat(where, tmp);
		return 1;
	}
	return 0;
}

/*
 * HexValue
 */
int HexValue(char c)
{
	const char hexChars[] = "0123456789ABCDEF";
	return strchr(hexChars, toupper2(c)) - hexChars;
}

/*
 * ParseStringChar
 * returns next character value
 * handles few escape sequences including hexadecimal notation
 */
char ParseStringChar(const char *&p)
{
	if (*p == '\\')		// special character
	{
		p++;
		switch (*p)
		{
			case 'r': p++; return '\r';
			case 'n': p++; return '\n';
			case 't': p++; return '\t';
			case '0': p++; return '\0';
			case 'x':
			{
				p++;
				int c = HexValue(*p++) << 4;
				return c | HexValue(*p++);
			}
			default: return *p++;
		}
	}
	else
	{
		return *p++;
	}
}

/*
 * ParseString
 */
char *ParseString(const char *&p)
{
	char *s = (char *)malloc(TMPSIZE), *q = s;
	const char *delims = delim_chars;
	if (*p == '"') { delims = "\""; p++; }
	while (*p && !strchr(delims, *p))
	{
		*q++ = ParseStringChar(p);
	}
	*q++ = 0;		// terminate
	if (*p) p++;	// skip delim
	return s;
}

/*
 * get_cpu_file_from_name
 */
char *get_cpu_file_from_name(const char *arg0, const char *name) {
	char *cpu_file = (char *)calloc(TMPSIZE, 1);
	if (arg0 && arg0[0]) {
		// Name of exe's directory
		strcpy(cpu_file, arg0);
		char *p = strrchr(cpu_file, '/');
		if (!p) p = strrchr(cpu_file, '\\');
		if (p) *++p = 0;
		else *cpu_file = 0;
	}
	strcat(cpu_file, "cpu/");
	if (!name || !strcmp(name, "pm")) {
		strcat(cpu_file, "pm.s");
	}
	else {
		strcat(cpu_file, name);
		strcat(cpu_file, "/");
		strcat(cpu_file, name);
		strcat(cpu_file, ".s");
	}
	return cpu_file;
}

/*
 * eprintf
 * Print error
 */
void veprintf(File *file, const char *fmt, va_list marker)
{
	char errormsg[TMPSIZE];
	/*int r =*/ vsprintf(errormsg, fmt, marker);
	char *p;
	if (file != NULL) {
		if ((p = strchr(file->origline, '\r'))) *p = 0;
		if ((p = strchr(file->origline, '\n'))) *p = 0;
		while ((p = strchr(file->origline, '\t'))) *p = ' ';
		fprintf(stderr, "%s, line %d: \'%s\' : %s",
			file->filename, file->line_num, file->origline, errormsg
		);
	}
	if (++errors >= MAX_ERRORS)
	{
		fprintf(stderr, "Maximum number of errors reached.\n"); eexit();
	}
}

void eprintf(File *file, const char *fmt, ...)
{
	va_list marker;
	va_start(marker, fmt);
	veprintf(file, fmt, marker);
	va_end(marker);
}

void eprintf(const char *fmt, ...) {
	va_list marker;
	va_start(marker, fmt);
	veprintf(NULL, fmt, marker);
	va_end(marker);
}

/*
 * eexit
 */
void eexit()
{
	exit(1);
}
