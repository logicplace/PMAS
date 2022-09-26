#ifndef _MISC_H
#define _MISC_H
#include <stdio.h>

/*
 * Defines
 */
#define TMPSIZE				1024
#define FREE(x)				{ if (x) free(x); x = 0; }
#ifdef DEBUG
	#define EEKS				if (1)
	#define MAX_ERRORS			1
#else
	#define EEKS				if (0)
	#define MAX_ERRORS			20
#endif

/*
 * Enum
 */
enum
{
	PASS_PRE,
	PASS_MID,
	PASS_DEF = 256,
	PASS_ASM
};

/*
 * Variables
 */
extern int pass;					// pass 1..2
extern int errors;
extern const char endline_chars[];
extern const char delim_chars[];

/*
 * Typedefs
 */
struct File
{
	FILE *fi;
	int line_num;
	char *filename;
	char origline[TMPSIZE];		// set in ParseLine, used to print error line
};

/*
 * Prototypes
 */
void eprintf(const char *fmt, ...);
bool strisempty(const char *s);
char *strskipspace(char *s);		// skip current word and followed space
int strword(const char *s, const char *lookfor);
int strreplace(char *s, char *from, char *to);
int HexValue(char c);
char ParseStringChar(const char *&p);
char *ParseString(const char *&p);		// returns _new_ string
char *get_cpu_file_from_name(const char *arg0, const char *name);
void eprintf(const char *fmt, ...);
void eprintf(File *file, const char *fmt, ...);
void eexit();

/*
 * isalpha2
 */
inline int isalpha2(int c)
{
	return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

/*
 * isspace2
 */
inline bool isspace2(char c)
{
	return (c == ' ') || (c == '\t') || (c == '\r') || (c == '\n');
}

/*
 * isdigit2
 */
inline int isdigit2(int c)
{
	return (c >= '0') && (c <= '9');
}

/*
 * toupper2
 */
inline int toupper2(int c)
{
	return ((c >= 'a') && (c <= 'z')) ? c - 'a' + 'A' : c;
}

/*
 * isidentifier
 */
inline int isidentifier(char c, bool firstchar)
{
	return (c == '_') || isalpha2(c) || (!firstchar && isdigit2(c));
}

/*
 * isendline
 */
inline bool isendline(char c)
{
	return (c == '#') || (c == ';') || (c == '\r') || (c == '\n') || (c == 0);
}

/*
 * strltrim
 */
inline const char *strltrim(const char *line)
{
	while (isspace2(*line)) line++;
	return line;
}

#endif	// _MISC_H

