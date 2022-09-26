#ifndef _PMAS_H
#define _PMAS_H

/*
 * Includes
 */
#include <stdio.h>
#include "misc.h"
#include "valuetype.h"

/*
 * Variables
 */
extern File *file;

/*
 * Prototypes
 */
bool SpecialSymbols(const char *name, ValueType &out);
void ParseFile(const char *filename);
void ParseLine(const char *file_line);
void MacroLine(const char *file_line);

#endif	// _PMAS_H
