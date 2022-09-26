#ifndef _MEM_H
#define _MEM_H


/*
 * Typedefs
 */
struct RelocData
{
	unsigned char & operator [] (int i);
};

/*
 * Variables
 */
extern RelocData reloc_data;
extern int reloc_offset;
extern unsigned int addr;

extern int option_fill;				// byte to fill uninitialized data with
extern unsigned int option_base;	// start address of output file (default = 0)

/*
 * Prototypes
 */
void WriteOutput(const char *filename);
void UpdateMaxAddr();

#endif	// _MEM_H
