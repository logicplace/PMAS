#define CPU s1c88
#include "instruction.h"

// TODO: fixed bits

// TODO: argument flags

// the instructions :)
const Instruction instructions[] =
{
{"ADC A,A",0x01,0x08,1,0},
{"ADC A,B",0x01,0x09,1,0},
{"ADC A,[HL]",0x01,0x0B,1,0},
{"ADC A,[NN+~0]",0x01,0x0C,2,1,8,262216},
{"ADC A,[X+L]",0x04,0xACE,2,0},
{"ADC A,[X+~0]",0x04,0x8CE,3,1,16,262216},
{"ADC A,[X]",0x01,0x0E,1,0},
{"ADC A,[Y+L]",0x04,0xBCE,2,0},
{"ADC A,[Y+~0]",0x04,0x9CE,3,1,16,262216},
{"ADC A,[Y]",0x01,0x0F,1,0},
{"ADC A,[~0]",0x01,0x0D,3,1,8,262224},
{"ADC A,~0",0x01,0x0A,2,1,8,131144},
{"ADC BA,BA",0x04,0x4CF,2,0},
{"ADC BA,HL",0x04,0x5CF,2,0},
{"ADC BA,X",0x04,0x6CF,2,0},
{"ADC BA,Y",0x04,0x7CF,2,0},
{"ADC BA,~0",0x04,0x60CF,4,1,16,131152},
{"ADC HL,BA",0x04,0x24CF,2,0},
{"ADC HL,HL",0x04,0x25CF,2,0},
{"ADC HL,X",0x04,0x26CF,2,0},
{"ADC HL,Y",0x04,0x27CF,2,0},
{"ADC HL,~0",0x04,0x61CF,4,1,16,131152},
{"ADC [HL],A",0x04,0xCCE,2,0},
{"ADC [HL],[X]",0x04,0xECE,2,0},
{"ADC [HL],[Y]",0x04,0xFCE,2,0},
{"ADC [HL],~0",0x04,0xDCE,3,1,16,131144},
{"ADD A,A",0x01,0x00,1,0},
{"ADD A,B",0x01,0x01,1,0},
{"ADD A,[HL]",0x01,0x03,1,0},
{"ADD A,[NN+~0]",0x01,0x04,2,1,8,262216},
{"ADD A,[X+L]",0x04,0x2CE,2,0},
{"ADD A,[X+~0]",0x04,0xCE,3,1,16,262216},
{"ADD A,[X]",0x01,0x06,1,0},
{"ADD A,[Y+L]",0x04,0x3CE,2,0},
{"ADD A,[Y+~0]",0x04,0x1CE,3,1,16,262216},
{"ADD A,[Y]",0x01,0x07,1,0},
{"ADD A,[~0]",0x01,0x05,3,1,8,262224},
{"ADD A,~0",0x01,0x02,2,1,8,131144},
{"ADD BA,BA",0x04,0xCF,2,0},
{"ADD BA,HL",0x04,0x1CF,2,0},
{"ADD BA,X",0x04,0x2CF,2,0},
{"ADD BA,Y",0x04,0x3CF,2,0},
{"ADD BA,~0",0x01,0xC0,3,1,8,131152},
{"ADD HL,BA",0x04,0x20CF,2,0},
{"ADD HL,HL",0x04,0x21CF,2,0},
{"ADD HL,X",0x04,0x22CF,2,0},
{"ADD HL,Y",0x04,0x23CF,2,0},
{"ADD HL,~0",0x01,0xC1,3,1,8,131152},
{"ADD SP,BA",0x04,0x44CF,2,0},
{"ADD SP,HL",0x04,0x45CF,2,0},
{"ADD SP,~0",0x04,0x68CF,4,1,16,131152},
{"ADD X,BA",0x04,0x40CF,2,0},
{"ADD X,HL",0x04,0x41CF,2,0},
{"ADD X,~0",0x01,0xC2,3,1,8,131152},
{"ADD Y,BA",0x04,0x42CF,2,0},
{"ADD Y,HL",0x04,0x43CF,2,0},
{"ADD Y,~0",0x01,0xC3,3,1,8,131152},
{"ADD [HL],A",0x04,0x4CE,2,0},
{"ADD [HL],[X]",0x04,0x6CE,2,0},
{"ADD [HL],[Y]",0x04,0x7CE,2,0},
{"ADD [HL],~0",0x04,0x5CE,3,1,16,131144},
{"ADDB A,A",0x01,0x00,1,0},
{"ADDB A,B",0x01,0x01,1,0},
{"ADDB A,[HL]",0x01,0x03,1,0},
{"ADDB A,[NN+~0]",0x01,0x04,2,1,8,262216},
{"ADDB A,[X+L]",0x04,0x2CE,2,0},
{"ADDB A,[X+~0]",0x04,0xCE,3,1,16,262216},
{"ADDB A,[X]",0x01,0x06,1,0},
{"ADDB A,[Y+L]",0x04,0x3CE,2,0},
{"ADDB A,[Y+~0]",0x04,0x1CE,3,1,16,262216},
{"ADDB A,[Y]",0x01,0x07,1,0},
{"ADDB A,[~0]",0x01,0x05,3,1,8,262224},
{"ADDB A,~0",0x01,0x02,2,1,8,131144},
{"ADDB [HL],A",0x04,0x4CE,2,0},
{"ADDB [HL],[X]",0x04,0x6CE,2,0},
{"ADDB [HL],[Y]",0x04,0x7CE,2,0},
{"ADDB [HL],~0",0x04,0x5CE,3,1,16,131144},
{"ADDCB A,A",0x01,0x08,1,0},
{"ADDCB A,B",0x01,0x09,1,0},
{"ADDCB A,[HL]",0x01,0x0B,1,0},
{"ADDCB A,[NN+~0]",0x01,0x0C,2,1,8,262216},
{"ADDCB A,[X+L]",0x04,0xACE,2,0},
{"ADDCB A,[X+~0]",0x04,0x8CE,3,1,16,262216},
{"ADDCB A,[X]",0x01,0x0E,1,0},
{"ADDCB A,[Y+L]",0x04,0xBCE,2,0},
{"ADDCB A,[Y+~0]",0x04,0x9CE,3,1,16,262216},
{"ADDCB A,[Y]",0x01,0x0F,1,0},
{"ADDCB A,[~0]",0x01,0x0D,3,1,8,262224},
{"ADDCB A,~0",0x01,0x0A,2,1,8,131144},
{"ADDCB [HL],A",0x04,0xCCE,2,0},
{"ADDCB [HL],[X]",0x04,0xECE,2,0},
{"ADDCB [HL],[Y]",0x04,0xFCE,2,0},
{"ADDCB [HL],~0",0x04,0xDCE,3,1,16,131144},
{"ADDCW BA,BA",0x04,0x4CF,2,0},
{"ADDCW BA,HL",0x04,0x5CF,2,0},
{"ADDCW BA,X",0x04,0x6CF,2,0},
{"ADDCW BA,Y",0x04,0x7CF,2,0},
{"ADDCW HL,BA",0x04,0x24CF,2,0},
{"ADDCW HL,HL",0x04,0x25CF,2,0},
{"ADDCW HL,X",0x04,0x26CF,2,0},
{"ADDCW HL,Y",0x04,0x27CF,2,0},
{"ADDW BA,BA",0x04,0xCF,2,0},
{"ADDW BA,HL",0x04,0x1CF,2,0},
{"ADDW BA,X",0x04,0x2CF,2,0},
{"ADDW BA,Y",0x04,0x3CF,2,0},
{"ADDW BA,~0",0x01,0xC0,3,1,8,131152},
{"ADDW HL,BA",0x04,0x20CF,2,0},
{"ADDW HL,HL",0x04,0x21CF,2,0},
{"ADDW HL,X",0x04,0x22CF,2,0},
{"ADDW HL,Y",0x04,0x23CF,2,0},
{"ADDW HL,~0",0x01,0xC1,3,1,8,131152},
{"ADDW SP,BA",0x04,0x44CF,2,0},
{"ADDW SP,HL",0x04,0x45CF,2,0},
{"ADDW SP,~0",0x04,0x68CF,4,1,16,131152},
{"ADDW X,~0",0x01,0xC2,3,1,8,131152},
{"ADDW X,BA",0x04,0x40CF,2,0},
{"ADDW X,HL",0x04,0x41CF,2,0},
{"ADDW Y,BA",0x04,0x42CF,2,0},
{"ADDW Y,HL",0x04,0x43CF,2,0},
{"ADDW Y,~0",0x01,0xC3,3,1,8,131152},
{"AND A,A",0x01,0x20,1,0},
{"AND A,B",0x01,0x21,1,0},
{"AND A,[HL]",0x01,0x23,1,0},
{"AND A,[NN+~0]",0x01,0x24,2,1,8,262216},
{"AND A,[X+L]",0x04,0x22CE,2,0},
{"AND A,[X+~0]",0x04,0x20CE,3,1,16,262216},
{"AND A,[X]",0x01,0x26,1,0},
{"AND A,[Y+L]",0x04,0x23CE,2,0},
{"AND A,[Y+~0]",0x04,0x21CE,3,1,16,262216},
{"AND A,[Y]",0x01,0x27,1,0},
{"AND A,[~0]",0x01,0x25,3,1,8,262224},
{"AND A,~0",0x01,0x22,2,1,8,131144},
{"AND B,~0",0x04,0xB0CE,3,1,16,131144},
{"AND F,~0",0x01,0x9C,2,1,8,131144},
{"AND H,~0",0x04,0xB2CE,3,1,16,131144},
{"AND L,~0",0x04,0xB1CE,3,1,16,131144},
{"AND [HL],A",0x04,0x24CE,2,0},
{"AND [HL],[X]",0x04,0x26CE,2,0},
{"AND [HL],[Y]",0x04,0x27CE,2,0},
{"AND [HL],~0",0x04,0x25CE,3,1,16,131144},
{"AND [NN+~0],~1",0x01,0xD8,3,2,8,131144,16,262216},
{"ANDB A,A",0x01,0x20,1,0},
{"ANDB A,B",0x01,0x21,1,0},
{"ANDB A,[HL]",0x01,0x23,1,0},
{"ANDB A,[NN+~0]",0x01,0x24,2,1,8,262216},
{"ANDB A,[X+L]",0x04,0x22CE,2,0},
{"ANDB A,[X+~0]",0x04,0x20CE,3,1,16,262216},
{"ANDB A,[X]",0x01,0x26,1,0},
{"ANDB A,[Y+L]",0x04,0x23CE,2,0},
{"ANDB A,[Y+~0]",0x04,0x21CE,3,1,16,262216},
{"ANDB A,[Y]",0x01,0x27,1,0},
{"ANDB A,[~0]",0x01,0x25,3,1,8,262224},
{"ANDB A,~0",0x01,0x22,2,1,8,131144},
{"ANDB B,~0",0x04,0xB0CE,3,1,16,131144},
{"ANDB FLAGS,~0",0x01,0x9C,2,1,8,131144},
{"ANDB H,~0",0x04,0xB2CE,3,1,16,131144},
{"ANDB L,~0",0x04,0xB1CE,3,1,16,131144},
{"ANDB [HL],A",0x04,0x24CE,2,0},
{"ANDB [HL],[X]",0x04,0x26CE,2,0},
{"ANDB [HL],[Y]",0x04,0x27CE,2,0},
{"ANDB [HL],~0",0x04,0x25CE,3,1,16,131144},
{"ANDB [NN+~0],~1",0x01,0xD8,3,2,8,131144,16,262216},
{"BCDD",0x01,0xDF,1,0},
{"BCDE",0x01,0xDE,1,0},
{"BCDX A",0x01,0xF6,1,0},
{"BCDX [HL]",0x01,0xF7,1,0},
{"CALL [~0]",0x01,0xFB,3,1,8,262224},
{"CALL ~0",0x03,0xF2,3,1,8,400},
{"CALLB ~0",0x03,0xF0,2,1,8,392},
{"CALLC ~0",0x03,0xE8,3,1,8,400},
{"CALLCB ~0",0x03,0xE0,2,1,8,392},
{"CALLCW ~0",0x03,0xE8,3,1,8,400},
{"CALLG ~0",0x06,0xF2CE,3,1,16,392},
{"CALLGE ~0",0x06,0xF3CE,3,1,16,392},
{"CALLL ~0",0x06,0xF0CE,3,1,16,392},
{"CALLLE ~0",0x06,0xF1CE,3,1,16,392},
{"CALLNC ~0",0x03,0xE9,3,1,8,400},
{"CALLNCB ~0",0x03,0xE1,2,1,8,392},
{"CALLNCW ~0",0x03,0xE9,3,1,8,400},
{"CALLNO ~0",0x06,0xF5CE,3,1,16,392},
{"CALLNS ~0",0x06,0xF6CE,3,1,16,392},
{"CALLNZ ~0",0x03,0xEB,3,1,8,400},
{"CALLNZB ~0",0x03,0xE3,2,1,8,392},
{"CALLNZW ~0",0x03,0xEB,3,1,8,400},
{"CALLO ~0",0x06,0xF4CE,3,1,16,392},
{"CALLS ~0",0x06,0xF7CE,3,1,16,392},
{"CALLW ~0",0x03,0xF2,3,1,8,400},
{"CALLZ ~0",0x03,0xEA,3,1,8,400},
{"CALLZB ~0",0x03,0xE2,2,1,8,392},
{"CALLZW ~0",0x03,0xEA,3,1,8,400},
{"CINT ~0",0x01,0xFC,2,1,9,524359},
{"CMP A,A",0x01,0x30,1,0},
{"CMP A,B",0x01,0x31,1,0},
{"CMP A,[HL]",0x01,0x33,1,0},
{"CMP A,[NN+~0]",0x01,0x34,2,1,8,262216},
{"CMP A,[X+L]",0x04,0x32CE,2,0},
{"CMP A,[X+~0]",0x04,0x30CE,3,1,16,262216},
{"CMP A,[X]",0x01,0x36,1,0},
{"CMP A,[Y+L]",0x04,0x33CE,2,0},
{"CMP A,[Y+~0]",0x04,0x31CE,3,1,16,262216},
{"CMP A,[Y]",0x01,0x37,1,0},
{"CMP A,[~0]",0x01,0x35,3,1,8,262224},
{"CMP A,~0",0x01,0x32,2,1,8,131144},
{"CMP B,~0",0x04,0xBCCE,3,1,16,131144},
{"CMP BA,BA",0x04,0x18CF,2,0},
{"CMP BA,HL",0x04,0x19CF,2,0},
{"CMP BA,X",0x04,0x1ACF,2,0},
{"CMP BA,Y",0x04,0x1BCF,2,0},
{"CMP BA,~0",0x01,0xD4,3,1,8,131152},
{"CMP H,~0",0x04,0xBECE,3,1,16,131144},
{"CMP HL,BA",0x04,0x38CF,2,0},
{"CMP HL,HL",0x04,0x39CF,2,0},
{"CMP HL,X",0x04,0x3ACF,2,0},
{"CMP HL,Y",0x04,0x3BCF,2,0},
{"CMP HL,~0",0x01,0xD5,3,1,8,131152},
{"CMP L,~0",0x04,0xBDCE,3,1,16,131144},
{"CMP NN,~0",0x04,0xBFCE,3,1,16,131144},
{"CMP SP,BA",0x04,0x5CCF,2,0},
{"CMP SP,HL",0x04,0x5DCF,2,0},
{"CMP SP,~0",0x04,0x6CCF,4,1,16,131152},
{"CMP X,~0",0x01,0xD6,3,1,8,131152},
{"CMP Y,~0",0x01,0xD7,3,1,8,131152},
{"CMP [HL],A",0x04,0x34CE,2,0},
{"CMP [HL],[X]",0x04,0x36CE,2,0},
{"CMP [HL],[Y]",0x04,0x37CE,2,0},
{"CMP [HL],~0",0x04,0x35CE,3,1,16,131144},
{"CMP [NN+~0],~1",0x01,0xDB,3,2,8,131144,16,262216},
{"CMPB A,A",0x01,0x30,1,0},
{"CMPB A,B",0x01,0x31,1,0},
{"CMPB A,[HL]",0x01,0x33,1,0},
{"CMPB A,[NN+~0]",0x01,0x34,2,1,8,262216},
{"CMPB A,[X+L]",0x04,0x32CE,2,0},
{"CMPB A,[X+~0]",0x04,0x30CE,3,1,16,262216},
{"CMPB A,[X]",0x01,0x36,1,0},
{"CMPB A,[Y+L]",0x04,0x33CE,2,0},
{"CMPB A,[Y+~0]",0x04,0x31CE,3,1,16,262216},
{"CMPB A,[Y]",0x01,0x37,1,0},
{"CMPB A,[~0]",0x01,0x35,3,1,8,262224},
{"CMPB A,~0",0x01,0x32,2,1,8,131144},
{"CMPB B,~0",0x04,0xBCCE,3,1,16,131144},
{"CMPB H,~0",0x04,0xBECE,3,1,16,131144},
{"CMPB L,~0",0x04,0xBDCE,3,1,16,131144},
{"CMPB NN,~0",0x04,0xBFCE,3,1,16,131144},
{"CMPB [HL],A",0x04,0x34CE,2,0},
{"CMPB [HL],[X]",0x04,0x36CE,2,0},
{"CMPB [HL],[Y]",0x04,0x37CE,2,0},
{"CMPB [HL],~0",0x04,0x35CE,3,1,16,131144},
{"CMPB [NN+~0],~1",0x01,0xDB,3,2,8,131144,16,262216},
{"CMPNW BA,~0",0x04,0x60CF,4,1,16,131152},
{"CMPNW HL,~0",0x04,0x61CF,4,1,16,131152},
{"CMPNW X,~0",0x04,0x62CF,4,1,16,131152},
{"CMPNW Y,~0",0x04,0x63CF,4,1,16,131152},
{"CMPW BA,BA",0x04,0x18CF,2,0},
{"CMPW BA,HL",0x04,0x19CF,2,0},
{"CMPW BA,X",0x04,0x1ACF,2,0},
{"CMPW BA,Y",0x04,0x1BCF,2,0},
{"CMPW BA,~0",0x01,0xD4,3,1,8,131152},
{"CMPW HL,BA",0x04,0x38CF,2,0},
{"CMPW HL,HL",0x04,0x39CF,2,0},
{"CMPW HL,X",0x04,0x3ACF,2,0},
{"CMPW HL,Y",0x04,0x3BCF,2,0},
{"CMPW HL,~0",0x01,0xD5,3,1,8,131152},
{"CMPW SP,BA",0x04,0x5CCF,2,0},
{"CMPW SP,HL",0x04,0x5DCF,2,0},
{"CMPW SP,~0",0x04,0x6CCF,4,1,16,131152},
{"CMPW X,~0",0x01,0xD6,3,1,8,131152},
{"CMPW Y,~0",0x01,0xD7,3,1,8,131152},
{"DEC A",0x01,0x88,1,0},
{"DEC B",0x01,0x89,1,0},
{"DEC BA",0x01,0x98,1,0},
{"DEC H",0x01,0x8B,1,0},
{"DEC HL",0x01,0x99,1,0},
{"DEC L",0x01,0x8A,1,0},
{"DEC NN",0x01,0x8C,1,0},
{"DEC SP",0x01,0x8F,1,0},
{"DEC X",0x01,0x9A,1,0},
{"DEC Y",0x01,0x9B,1,0},
{"DEC [HL]",0x01,0x8E,1,0},
{"DEC [NN+~0]",0x01,0x8D,2,1,8,262216},
{"DECB A",0x01,0x88,1,0},
{"DECB B",0x01,0x89,1,0},
{"DECB H",0x01,0x8B,1,0},
{"DECB L",0x01,0x8A,1,0},
{"DECB NN",0x01,0x8C,1,0},
{"DECB [HL]",0x01,0x8E,1,0},
{"DECB [NN+~0]",0x01,0x8D,2,1,8,262216},
{"DECW BA",0x01,0x98,1,0},
{"DECW HL",0x01,0x99,1,0},
{"DECW SP",0x01,0x8F,1,0},
{"DECW X",0x01,0x9A,1,0},
{"DECW Y",0x01,0x9B,1,0},
{"DIV HL,A",0x04,0xD9CE,2,0},
{"EX BA,A",0x04,0xA8CE,2,0},
{"EXTS BA,A",0x04,0xA8CE,2,0},
{"HALT",0x04,0xAECE,2,0},
{"INC A",0x01,0x80,1,0},
{"INC B",0x01,0x81,1,0},
{"INC BA",0x01,0x90,1,0},
{"INC H",0x01,0x83,1,0},
{"INC HL",0x01,0x91,1,0},
{"INC L",0x01,0x82,1,0},
{"INC NN",0x01,0x84,1,0},
{"INC SP",0x01,0x87,1,0},
{"INC X",0x01,0x92,1,0},
{"INC Y",0x01,0x93,1,0},
{"INC [HL]",0x01,0x86,1,0},
{"INC [NN+~0]",0x01,0x85,2,1,8,262216},
{"INCB A",0x01,0x80,1,0},
{"INCB B",0x01,0x81,1,0},
{"INCB H",0x01,0x83,1,0},
{"INCB L",0x01,0x82,1,0},
{"INCB NN",0x01,0x84,1,0},
{"INCB [HL]",0x01,0x86,1,0},
{"INCB [NN+~0]",0x01,0x85,2,1,8,262216},
{"INCW BA",0x01,0x90,1,0},
{"INCW HL",0x01,0x91,1,0},
{"INCW SP",0x01,0x87,1,0},
{"INCW X",0x01,0x92,1,0},
{"INCW Y",0x01,0x93,1,0},
{"INT ~0",0x01,0xFC,2,1,9,524359},
{"JC ~0",0x03,0xEC,3,1,8,400},
{"JCB ~0",0x03,0xE4,2,1,8,392},
{"JCW ~0",0x03,0xEC,3,1,8,400},
{"JDBNZ ~0",0x03,0xF5,2,1,8,392},
{"JG ~0",0x06,0xE2CE,3,1,16,392},
{"JGE ~0",0x06,0xE3CE,3,1,16,392},
{"JINT ~0",0x01,0xFD,2,1,9,524359},
{"JL ~0",0x06,0xE0CE,3,1,16,392},
{"JLE ~0",0x06,0xE1CE,3,1,16,392},
{"JMP HL",0x01,0xF4,1,0},
{"JMP ~0",0x03,0xF3,3,1,8,400},
{"JMPB ~0",0x03,0xF1,2,1,8,392},
{"JMPW ~0",0x03,0xF3,3,1,8,400},
{"JNC ~0",0x03,0xED,3,1,8,400},
{"JNCB ~0",0x03,0xE5,2,1,8,392},
{"JNCW ~0",0x03,0xED,3,1,8,400},
{"JNO ~0",0x06,0xE5CE,3,1,16,392},
{"JNS ~0",0x06,0xE6CE,3,1,16,392},
{"JNZ ~0",0x03,0xEF,3,1,8,400},
{"JNZB ~0",0x03,0xE7,2,1,8,392},
{"JNZW ~0",0x03,0xEF,3,1,8,400},
{"JO ~0",0x06,0xE4CE,3,1,16,392},
{"JS ~0",0x06,0xE7CE,3,1,16,392},
{"JZ ~0",0x03,0xEE,3,1,8,400},
{"JZB ~0",0x03,0xE6,2,1,8,392},
{"JZW ~0",0x03,0xEE,3,1,8,400},
{"MOV A,A",0x01,0x40,1,0},
{"MOV A,B",0x01,0x41,1,0},
{"MOV A,F",0x04,0xC1CE,2,0},
{"MOV A,H",0x01,0x43,1,0},
{"MOV A,I",0x04,0xC9CE,2,0},
{"MOV A,L",0x01,0x42,1,0},
{"MOV A,NN",0x04,0xC0CE,2,0},
{"MOV A,V",0x04,0xC8CE,2,0},
{"MOV A,XI",0x04,0xCACE,2,0},
{"MOV A,YI",0x04,0xCBCE,2,0},
{"MOV A,[HL]",0x01,0x45,1,0},
{"MOV A,[NN+~0]",0x01,0x44,2,1,8,262216},
{"MOV A,[X+L]",0x04,0x42CE,2,0},
{"MOV A,[X+~0]",0x04,0x40CE,3,1,16,262216},
{"MOV A,[X]",0x01,0x46,1,0},
{"MOV A,[Y+L]",0x04,0x43CE,2,0},
{"MOV A,[Y+~0]",0x04,0x41CE,3,1,16,262216},
{"MOV A,[Y]",0x01,0x47,1,0},
{"MOV A,[~0]",0x04,0xD0CE,4,1,16,262224},
{"MOV A,~0",0x01,0xB0,2,1,8,131144},
{"MOV B,A",0x01,0x48,1,0},
{"MOV B,B",0x01,0x49,1,0},
{"MOV B,H",0x01,0x4B,1,0},
{"MOV B,L",0x01,0x4A,1,0},
{"MOV B,[HL]",0x01,0x4D,1,0},
{"MOV B,[NN+~0]",0x01,0x4C,2,1,8,262216},
{"MOV B,[X+L]",0x04,0x4ACE,2,0},
{"MOV B,[X+~0]",0x04,0x48CE,3,1,16,262216},
{"MOV B,[X]",0x01,0x4E,1,0},
{"MOV B,[Y+L]",0x04,0x4BCE,2,0},
{"MOV B,[Y+~0]",0x04,0x49CE,3,1,16,262216},
{"MOV B,[Y]",0x01,0x4F,1,0},
{"MOV B,[~0]",0x04,0xD1CE,4,1,16,262224},
{"MOV B,~0",0x01,0xB1,2,1,8,131144},
{"MOV BA,BA",0x04,0xE0CF,2,0},
{"MOV BA,HL",0x04,0xE1CF,2,0},
{"MOV BA,PC",0x04,0xF9CF,2,0},
{"MOV BA,SP",0x04,0xF8CF,2,0},
{"MOV BA,X",0x04,0xE2CF,2,0},
{"MOV BA,Y",0x04,0xE3CF,2,0},
{"MOV BA,[HL]",0x04,0xC0CF,2,0},
{"MOV BA,[SP+~0]",0x04,0x70CF,3,1,16,262216},
{"MOV BA,[X]",0x04,0xD0CF,2,0},
{"MOV BA,[Y]",0x04,0xD8CF,2,0},
{"MOV BA,[~0]",0x01,0xB8,3,1,8,262224},
{"MOV BA,~0",0x01,0xC4,3,1,8,131152},
{"MOV F,A",0x04,0xC3CE,2,0},
{"MOV F,~0",0x01,0x9F,2,1,8,131144},
{"MOV H,A",0x01,0x58,1,0},
{"MOV H,B",0x01,0x59,1,0},
{"MOV H,H",0x01,0x5B,1,0},
{"MOV H,L",0x01,0x5A,1,0},
{"MOV H,[HL]",0x01,0x5D,1,0},
{"MOV H,[NN+~0]",0x01,0x5C,2,1,8,262216},
{"MOV H,[X+L]",0x04,0x5ACE,2,0},
{"MOV H,[X+~0]",0x04,0x58CE,3,1,16,262216},
{"MOV H,[X]",0x01,0x5E,1,0},
{"MOV H,[Y+L]",0x04,0x5BCE,2,0},
{"MOV H,[Y+~0]",0x04,0x59CE,3,1,16,262216},
{"MOV H,[Y]",0x01,0x5F,1,0},
{"MOV H,[~0]",0x04,0xD3CE,4,1,16,262224},
{"MOV H,~0",0x01,0xB3,2,1,8,131144},
{"MOV HL,BA",0x04,0xE4CF,2,0},
{"MOV HL,HL",0x04,0xE5CF,2,0},
{"MOV HL,PC",0x04,0xF5CF,2,0},
{"MOV HL,SP",0x04,0xF4CF,2,0},
{"MOV HL,X",0x04,0xE6CF,2,0},
{"MOV HL,Y",0x04,0xE7CF,2,0},
{"MOV HL,[HL]",0x04,0xC1CF,2,0},
{"MOV HL,[SP+~0]",0x04,0x71CF,3,1,16,262216},
{"MOV HL,[X]",0x04,0xD1CF,2,0},
{"MOV HL,[Y]",0x04,0xD9CF,2,0},
{"MOV HL,[~0]",0x01,0xB9,3,1,8,262224},
{"MOV HL,~0",0x01,0xC5,3,1,8,131152},
{"MOV I,A",0x04,0xCDCE,2,0},
{"MOV I,~0",0x04,0xC5CE,3,1,16,131144},
{"MOV L,A",0x01,0x50,1,0},
{"MOV L,B",0x01,0x51,1,0},
{"MOV L,H",0x01,0x53,1,0},
{"MOV L,L",0x01,0x52,1,0},
{"MOV L,[HL]",0x01,0x55,1,0},
{"MOV L,[NN+~0]",0x01,0x54,2,1,8,262216},
{"MOV L,[X+L]",0x04,0x52CE,2,0},
{"MOV L,[X+~0]",0x04,0x50CE,3,1,16,262216},
{"MOV L,[X]",0x01,0x56,1,0},
{"MOV L,[Y+L]",0x04,0x53CE,2,0},
{"MOV L,[Y+~0]",0x04,0x51CE,3,1,16,262216},
{"MOV L,[Y]",0x01,0x57,1,0},
{"MOV L,[~0]",0x04,0xD2CE,4,1,16,262224},
{"MOV L,~0",0x01,0xB2,2,1,8,131144},
{"MOV NN,A",0x04,0xC2CE,2,0},
{"MOV NN,~0",0x01,0xB4,2,1,8,131144},
{"MOV SP,BA",0x04,0xF0CF,2,0},
{"MOV SP,HL",0x04,0xF1CF,2,0},
{"MOV SP,X",0x04,0xF2CF,2,0},
{"MOV SP,Y",0x04,0xF3CF,2,0},
{"MOV SP,[~0]",0x04,0x78CF,4,1,16,262224},
{"MOV SP,~0",0x04,0x6ECF,4,1,16,131152},
{"MOV U,A",0x04,0xCCCE,2,0},
{"MOV U,~0",0x04,0xC4CE,3,1,16,131144},
{"MOV X,BA",0x04,0xE8CF,2,0},
{"MOV X,HL",0x04,0xE9CF,2,0},
{"MOV X,SP",0x04,0xFACF,2,0},
{"MOV X,X",0x04,0xEACF,2,0},
{"MOV X,Y",0x04,0xEBCF,2,0},
{"MOV X,[HL]",0x04,0xC2CF,2,0},
{"MOV X,[SP+~0]",0x04,0x72CF,3,1,16,262216},
{"MOV X,[X]",0x04,0xD2CF,2,0},
{"MOV X,[Y]",0x04,0xDACF,2,0},
{"MOV X,[~0]",0x01,0xBA,3,1,8,262224},
{"MOV X,~0",0x01,0xC6,3,1,8,131152},
{"MOV Y,BA",0x04,0xECCF,2,0},
{"MOV Y,HL",0x04,0xEDCF,2,0},
{"MOV Y,X",0x04,0xEECF,2,0},
{"MOV Y,Y",0x04,0xEFCF,2,0},
{"MOV Y,[HL]",0x04,0xC3CF,2,0},
{"MOV Y,[SP+~0]",0x04,0x73CF,3,1,16,262216},
{"MOV Y,[X]",0x04,0xD3CF,2,0},
{"MOV Y,[Y]",0x04,0xDBCF,2,0},
{"MOV Y,[~0]",0x01,0xBB,3,1,8,262224},
{"MOV Y,~0",0x01,0xC7,3,1,8,131152},
{"MOV XI,A",0x04,0xCECE,2,0},
{"MOV XI,~0",0x04,0xC6CE,3,1,16,131144},
{"MOV Y,SP",0x04,0xFECF,2,0},
{"MOV YI,A",0x04,0xCFCE,2,0},
{"MOV YI,~0",0x04,0xC7CE,3,1,16,131144},
{"MOV [HL],A",0x01,0x68,1,0},
{"MOV [HL],B",0x01,0x69,1,0},
{"MOV [HL],BA",0x04,0xC4CF,2,0},
{"MOV [HL],H",0x01,0x6B,1,0},
{"MOV [HL],HL",0x04,0xC5CF,2,0},
{"MOV [HL],L",0x01,0x6A,1,0},
{"MOV [HL],X",0x04,0xC6CF,2,0},
{"MOV [HL],Y",0x04,0xC7CF,2,0},
{"MOV [HL],[HL]",0x01,0x6D,1,0},
{"MOV [HL],[NN+~0]",0x01,0x6C,2,1,8,262216},
{"MOV [HL],[X+L]",0x04,0x62CE,2,0},
{"MOV [HL],[X+~0]",0x04,0x60CE,3,1,16,262216},
{"MOV [HL],[X]",0x01,0x6E,1,0},
{"MOV [HL],[Y+L]",0x04,0x63CE,2,0},
{"MOV [HL],[Y+~0]",0x04,0x61CE,3,1,16,262216},
{"MOV [HL],[Y]",0x01,0x6F,1,0},
{"MOV [HL],~0",0x01,0xB5,2,1,8,131144},
{"MOV [NN+~0],A",0x01,0x78,2,1,8,262216},
{"MOV [NN+~0],B",0x01,0x79,2,1,8,262216},
{"MOV [NN+~0],H",0x01,0x7B,2,1,8,262216},
{"MOV [NN+~0],L",0x01,0x7A,2,1,8,262216},
{"MOV [NN+~0],[HL]",0x01,0x7D,2,1,8,262216},
{"MOV [NN+~0],[X]",0x01,0x7E,2,1,8,262216},
{"MOV [NN+~0],[Y]",0x01,0x7F,2,1,8,262216},
{"MOV [NN+~0],~1",0x01,0xDD,3,2,8,131144,16,262216},
{"MOV [SP+~0],BA",0x04,0x74CF,3,1,16,262216},
{"MOV [SP+~0],HL",0x04,0x75CF,3,1,16,262216},
{"MOV [SP+~0],X",0x04,0x76CF,3,1,16,262216},
{"MOV [SP+~0],Y",0x04,0x77CF,3,1,16,262216},
{"MOV [X+L],A",0x04,0x46CE,2,0},
{"MOV [X+L],B",0x04,0x4ECE,2,0},
{"MOV [X+L],H",0x04,0x5ECE,2,0},
{"MOV [X+L],L",0x04,0x56CE,2,0},
{"MOV [X+~0],A",0x04,0x44CE,3,1,16,262216},
{"MOV [X+~0],B",0x04,0x4CCE,3,1,16,262216},
{"MOV [X+~0],H",0x04,0x5CCE,3,1,16,262216},
{"MOV [X+~0],L",0x04,0x54CE,3,1,16,262216},
{"MOV [X],A",0x01,0x60,1,0},
{"MOV [X],B",0x01,0x61,1,0},
{"MOV [X],BA",0x04,0xD4CF,2,0},
{"MOV [X],H",0x01,0x63,1,0},
{"MOV [X],HL",0x04,0xD5CF,2,0},
{"MOV [X],L",0x01,0x62,1,0},
{"MOV [X],X",0x04,0xD6CF,2,0},
{"MOV [X],Y",0x04,0xD7CF,2,0},
{"MOV [X],[HL]",0x01,0x65,1,0},
{"MOV [X],[NN+~0]",0x01,0x64,2,1,8,262216},
{"MOV [X],[X+L]",0x04,0x6ACE,2,0},
{"MOV [X],[X+~0]",0x04,0x68CE,3,1,16,262216},
{"MOV [X],[X]",0x01,0x66,1,0},
{"MOV [X],[Y+L]",0x04,0x6BCE,2,0},
{"MOV [X],[Y+~0]",0x04,0x69CE,3,1,16,262216},
{"MOV [X],[Y]",0x01,0x67,1,0},
{"MOV [X],~0",0x01,0xB6,2,1,8,131144},
{"MOV [Y+L],A",0x04,0x47CE,2,0},
{"MOV [Y+L],B",0x04,0x4FCE,2,0},
{"MOV [Y+L],H",0x04,0x5FCE,2,0},
{"MOV [Y+L],L",0x04,0x57CE,2,0},
{"MOV [Y+~0],A",0x04,0x45CE,3,1,16,262216},
{"MOV [Y+~0],B",0x04,0x4DCE,3,1,16,262216},
{"MOV [Y+~0],H",0x04,0x5DCE,3,1,16,262216},
{"MOV [Y+~0],L",0x04,0x55CE,3,1,16,262216},
{"MOV [Y],A",0x01,0x70,1,0},
{"MOV [Y],B",0x01,0x71,1,0},
{"MOV [Y],BA",0x04,0xDCCF,2,0},
{"MOV [Y],H",0x01,0x73,1,0},
{"MOV [Y],HL",0x04,0xDDCF,2,0},
{"MOV [Y],L",0x01,0x72,1,0},
{"MOV [Y],X",0x04,0xDECF,2,0},
{"MOV [Y],Y",0x04,0xDFCF,2,0},
{"MOV [Y],[HL]",0x01,0x75,1,0},
{"MOV [Y],[NN+~0]",0x01,0x74,2,1,8,262216},
{"MOV [Y],[X+L]",0x04,0x7ACE,2,0},
{"MOV [Y],[X+~0]",0x04,0x78CE,3,1,16,262216},
{"MOV [Y],[X]",0x01,0x76,1,0},
{"MOV [Y],[Y+L]",0x04,0x7BCE,2,0},
{"MOV [Y],[Y+~0]",0x04,0x79CE,3,1,16,262216},
{"MOV [Y],[Y]",0x01,0x77,1,0},
{"MOV [Y],~0",0x01,0xB7,2,1,8,131144},
{"MOV [~0],A",0x04,0xD4CE,4,1,16,262224},
{"MOV [~0],B",0x04,0xD5CE,4,1,16,262224},
{"MOV [~0],BA",0x01,0xBC,3,1,8,262224},
{"MOV [~0],H",0x04,0xD7CE,4,1,16,262224},
{"MOV [~0],HL",0x01,0xBD,3,1,8,262224},
{"MOV [~0],L",0x04,0xD6CE,4,1,16,262224},
{"MOV [~0],SP",0x04,0x7CCF,4,1,16,262224},
{"MOV [~0],X",0x01,0xBE,3,1,8,262224},
{"MOV [~0],Y",0x01,0xBF,3,1,8,262224},
{"MOVB A,A",0x01,0x40,1,0},
{"MOVB A,B",0x01,0x41,1,0},
{"MOVB A,FLAGS",0x04,0xC1CE,2,0},
{"MOVB A,H",0x01,0x43,1,0},
{"MOVB A,L",0x01,0x42,1,0},
{"MOVB A,NN",0x04,0xC0CE,2,0},
{"MOVB A,V",0x04,0xC8CE,2,0},
{"MOVB A,[HL]",0x01,0x45,1,0},
{"MOVB A,[NN+~0]",0x01,0x44,2,1,8,262216},
{"MOVB A,[X+L]",0x04,0x42CE,2,0},
{"MOVB A,[X+~0]",0x04,0x40CE,3,1,16,262216},
{"MOVB A,[X]",0x01,0x46,1,0},
{"MOVB A,[Y+L]",0x04,0x43CE,2,0},
{"MOVB A,[Y+~0]",0x04,0x41CE,3,1,16,262216},
{"MOVB A,[Y]",0x01,0x47,1,0},
{"MOVB A,[~0]",0x04,0xD0CE,4,1,16,262224},
{"MOVB A,~0",0x01,0xB0,2,1,8,131144},
{"MOVB B,A",0x01,0x48,1,0},
{"MOVB B,B",0x01,0x49,1,0},
{"MOVB B,H",0x01,0x4B,1,0},
{"MOVB B,L",0x01,0x4A,1,0},
{"MOVB B,[HL]",0x01,0x4D,1,0},
{"MOVB B,[NN+~0]",0x01,0x4C,2,1,8,262216},
{"MOVB B,[X+L]",0x04,0x4ACE,2,0},
{"MOVB B,[X+~0]",0x04,0x48CE,3,1,16,262216},
{"MOVB B,[X]",0x01,0x4E,1,0},
{"MOVB B,[Y+L]",0x04,0x4BCE,2,0},
{"MOVB B,[Y+~0]",0x04,0x49CE,3,1,16,262216},
{"MOVB B,[Y]",0x01,0x4F,1,0},
{"MOVB B,[~0]",0x04,0xD1CE,4,1,16,262224},
{"MOVB B,~0",0x01,0xB1,2,1,8,131144},
{"MOVB FLAGS,A",0x04,0xC3CE,2,0},
{"MOVB FLAGS,~0",0x01,0x9F,2,1,8,131144},
{"MOVB H,A",0x01,0x58,1,0},
{"MOVB H,B",0x01,0x59,1,0},
{"MOVB H,H",0x01,0x5B,1,0},
{"MOVB H,L",0x01,0x5A,1,0},
{"MOVB H,[HL]",0x01,0x5D,1,0},
{"MOVB H,[NN+~0]",0x01,0x5C,2,1,8,262216},
{"MOVB H,[X+L]",0x04,0x5ACE,2,0},
{"MOVB H,[X+~0]",0x04,0x58CE,3,1,16,262216},
{"MOVB H,[X]",0x01,0x5E,1,0},
{"MOVB H,[Y+L]",0x04,0x5BCE,2,0},
{"MOVB H,[Y+~0]",0x04,0x59CE,3,1,16,262216},
{"MOVB H,[Y]",0x01,0x5F,1,0},
{"MOVB H,[~0]",0x04,0xD3CE,4,1,16,262224},
{"MOVB H,~0",0x01,0xB3,2,1,8,131144},
{"MOVB L,A",0x01,0x50,1,0},
{"MOVB L,B",0x01,0x51,1,0},
{"MOVB L,H",0x01,0x53,1,0},
{"MOVB L,L",0x01,0x52,1,0},
{"MOVB L,[HL]",0x01,0x55,1,0},
{"MOVB L,[NN+~0]",0x01,0x54,2,1,8,262216},
{"MOVB L,[X+L]",0x04,0x52CE,2,0},
{"MOVB L,[X+~0]",0x04,0x50CE,3,1,16,262216},
{"MOVB L,[X]",0x01,0x56,1,0},
{"MOVB L,[Y+L]",0x04,0x53CE,2,0},
{"MOVB L,[Y+~0]",0x04,0x51CE,3,1,16,262216},
{"MOVB L,[Y]",0x01,0x57,1,0},
{"MOVB L,[~0]",0x04,0xD2CE,4,1,16,262224},
{"MOVB L,~0",0x01,0xB2,2,1,8,131144},
{"MOVB NN,A",0x04,0xC2CE,2,0},
{"MOVB U,A",0x04,0xCCCE,2,0},
{"MOVB U,~0",0x04,0xC4CE,3,1,16,131144},
{"MOVB [HL],A",0x01,0x68,1,0},
{"MOVB [HL],B",0x01,0x69,1,0},
{"MOVB [HL],H",0x01,0x6B,1,0},
{"MOVB [HL],L",0x01,0x6A,1,0},
{"MOVB [HL],[HL]",0x01,0x6D,1,0},
{"MOVB [HL],[NN+~0]",0x01,0x6C,2,1,8,262216},
{"MOVB [HL],[X+L]",0x04,0x62CE,2,0},
{"MOVB [HL],[X+~0]",0x04,0x60CE,3,1,16,262216},
{"MOVB [HL],[X]",0x01,0x6E,1,0},
{"MOVB [HL],[Y+L]",0x04,0x63CE,2,0},
{"MOVB [HL],[Y+~0]",0x04,0x61CE,3,1,16,262216},
{"MOVB [HL],[Y]",0x01,0x6F,1,0},
{"MOVB [HL],~0",0x01,0xB5,2,1,8,131144},
{"MOVB [NN+~0],A",0x01,0x78,2,1,8,262216},
{"MOVB [NN+~0],B",0x01,0x79,2,1,8,262216},
{"MOVB [NN+~0],H",0x01,0x7B,2,1,8,262216},
{"MOVB [NN+~0],L",0x01,0x7A,2,1,8,262216},
{"MOVB [NN+~0],[HL]",0x01,0x7D,2,1,8,262216},
{"MOVB [NN+~0],[X]",0x01,0x7E,2,1,8,262216},
{"MOVB [NN+~0],[Y]",0x01,0x7F,2,1,8,262216},
{"MOVB [NN+~0],~1",0x01,0xDD,3,2,8,131144,16,262216},
{"MOVB [X+L],A",0x04,0x46CE,2,0},
{"MOVB [X+L],B",0x04,0x4ECE,2,0},
{"MOVB [X+L],H",0x04,0x5ECE,2,0},
{"MOVB [X+L],L",0x04,0x56CE,2,0},
{"MOVB [X+~0],A",0x04,0x44CE,3,1,16,262216},
{"MOVB [X+~0],B",0x04,0x4CCE,3,1,16,262216},
{"MOVB [X+~0],H",0x04,0x5CCE,3,1,16,262216},
{"MOVB [X+~0],L",0x04,0x54CE,3,1,16,262216},
{"MOVB [X],A",0x01,0x60,1,0},
{"MOVB [X],B",0x01,0x61,1,0},
{"MOVB [X],H",0x01,0x63,1,0},
{"MOVB [X],L",0x01,0x62,1,0},
{"MOVB [X],[HL]",0x01,0x65,1,0},
{"MOVB [X],[NN+~0]",0x01,0x64,2,1,8,262216},
{"MOVB [X],[X+L]",0x04,0x6ACE,2,0},
{"MOVB [X],[X+~0]",0x04,0x68CE,3,1,16,262216},
{"MOVB [X],[X]",0x01,0x66,1,0},
{"MOVB [X],[Y+L]",0x04,0x6BCE,2,0},
{"MOVB [X],[Y+~0]",0x04,0x69CE,3,1,16,262216},
{"MOVB [X],[Y]",0x01,0x67,1,0},
{"MOVB [X],~0",0x01,0xB6,2,1,8,131144},
{"MOVB [Y+L],A",0x04,0x47CE,2,0},
{"MOVB [Y+L],B",0x04,0x4FCE,2,0},
{"MOVB [Y+L],H",0x04,0x5FCE,2,0},
{"MOVB [Y+L],L",0x04,0x57CE,2,0},
{"MOVB [Y+~0],A",0x04,0x45CE,3,1,16,262216},
{"MOVB [Y+~0],B",0x04,0x4DCE,3,1,16,262216},
{"MOVB [Y+~0],H",0x04,0x5DCE,3,1,16,262216},
{"MOVB [Y+~0],L",0x04,0x55CE,3,1,16,262216},
{"MOVB [Y],A",0x01,0x70,1,0},
{"MOVB [Y],B",0x01,0x71,1,0},
{"MOVB [Y],H",0x01,0x73,1,0},
{"MOVB [Y],L",0x01,0x72,1,0},
{"MOVB [Y],[HL]",0x01,0x75,1,0},
{"MOVB [Y],[NN+~0]",0x01,0x74,2,1,8,262216},
{"MOVB [Y],[X+L]",0x04,0x7ACE,2,0},
{"MOVB [Y],[X+~0]",0x04,0x78CE,3,1,16,262216},
{"MOVB [Y],[X]",0x01,0x76,1,0},
{"MOVB [Y],[Y+L]",0x04,0x7BCE,2,0},
{"MOVB [Y],[Y+~0]",0x04,0x79CE,3,1,16,262216},
{"MOVB [Y],[Y]",0x01,0x77,1,0},
{"MOVB [Y],~0",0x01,0xB7,2,1,8,131144},
{"MOVB [~0],A",0x04,0xD4CE,4,1,16,262224},
{"MOVB [~0],B",0x04,0xD5CE,4,1,16,262224},
{"MOVB [~0],H",0x04,0xD7CE,4,1,16,262224},
{"MOVB [~0],L",0x04,0xD6CE,4,1,16,262224},
{"MOVW BA,BA",0x04,0xE0CF,2,0},
{"MOVW BA,HL",0x04,0xE1CF,2,0},
{"MOVW BA,PC",0x04,0xF9CF,2,0},
{"MOVW BA,SP",0x04,0xF8CF,2,0},
{"MOVW BA,X",0x04,0xE2CF,2,0},
{"MOVW BA,Y",0x04,0xE3CF,2,0},
{"MOVW BA,[HL]",0x04,0xC0CF,2,0},
{"MOVW BA,[SP+~0]",0x04,0x70CF,3,1,16,262216},
{"MOVW BA,[X]",0x04,0xD0CF,2,0},
{"MOVW BA,[Y]",0x04,0xD8CF,2,0},
{"MOVW BA,[~0]",0x01,0xB8,3,1,8,262224},
{"MOVW BA,~0",0x01,0xC4,3,1,8,131152},
{"MOVW HL,BA",0x04,0xE4CF,2,0},
{"MOVW HL,HL",0x04,0xE5CF,2,0},
{"MOVW HL,PC",0x04,0xF5CF,2,0},
{"MOVW HL,SP",0x04,0xF4CF,2,0},
{"MOVW HL,X",0x04,0xE6CF,2,0},
{"MOVW HL,Y",0x04,0xE7CF,2,0},
{"MOVW HL,[HL]",0x04,0xC1CF,2,0},
{"MOVW HL,[SP+~0]",0x04,0x71CF,3,1,16,262216},
{"MOVW HL,[X]",0x04,0xD1CF,2,0},
{"MOVW HL,[Y]",0x04,0xD9CF,2,0},
{"MOVW HL,[~0]",0x01,0xB9,3,1,8,262224},
{"MOVW HL,~0",0x01,0xC5,3,1,8,131152},
{"MOVW NN,~0",0x01,0xB4,2,1,8,131664},
{"MOVW SP,BA",0x04,0xF0CF,2,0},
{"MOVW SP,HL",0x04,0xF1CF,2,0},
{"MOVW SP,X",0x04,0xF2CF,2,0},
{"MOVW SP,Y",0x04,0xF3CF,2,0},
{"MOVW SP,[~0]",0x04,0x78CF,4,1,16,262224},
{"MOVW SP,~0",0x04,0x6ECF,4,1,16,131152},
{"MOVW X,BA",0x04,0xE8CF,2,0},
{"MOVW X,HL",0x04,0xE9CF,2,0},
{"MOVW X,X",0x04,0xEACF,2,0},
{"MOVW X,Y",0x04,0xEBCF,2,0},
{"MOVW X,[HL]",0x04,0xC2CF,2,0},
{"MOVW X,[SP+~0]",0x04,0x72CF,3,1,16,262216},
{"MOVW X,[X]",0x04,0xD2CF,2,0},
{"MOVW X,[Y]",0x04,0xDACF,2,0},
{"MOVW X,[~0]",0x01,0xBA,3,1,8,262224},
{"MOVW X,~0",0x01,0xC6,3,1,8,131152},
{"MOVW X,SP",0x04,0xFACF,2,0},
{"MOVW Y,BA",0x04,0xECCF,2,0},
{"MOVW Y,HL",0x04,0xEDCF,2,0},
{"MOVW Y,SP",0x04,0xFECF,2,0},
{"MOVW Y,X",0x04,0xEECF,2,0},
{"MOVW Y,Y",0x04,0xEFCF,2,0},
{"MOVW Y,[HL]",0x04,0xC3CF,2,0},
{"MOVW Y,[SP+~0]",0x04,0x73CF,3,1,16,262216},
{"MOVW Y,[X]",0x04,0xD3CF,2,0},
{"MOVW Y,[Y]",0x04,0xDBCF,2,0},
{"MOVW Y,[~0]",0x01,0xBB,3,1,8,262224},
{"MOVW Y,~0",0x01,0xC7,3,1,8,131152},
{"MOVW [HL],BA",0x04,0xC4CF,2,0},
{"MOVW [HL],HL",0x04,0xC5CF,2,0},
{"MOVW [HL],X",0x04,0xC6CF,2,0},
{"MOVW [HL],Y",0x04,0xC7CF,2,0},
{"MOVW [SP+~0],BA",0x04,0x74CF,3,1,16,262216},
{"MOVW [SP+~0],HL",0x04,0x75CF,3,1,16,262216},
{"MOVW [SP+~0],X",0x04,0x76CF,3,1,16,262216},
{"MOVW [SP+~0],Y",0x04,0x77CF,3,1,16,262216},
{"MOVW [X],BA",0x04,0xD4CF,2,0},
{"MOVW [X],HL",0x04,0xD5CF,2,0},
{"MOVW [X],X",0x04,0xD6CF,2,0},
{"MOVW [X],Y",0x04,0xD7CF,2,0},
{"MOVW [Y],BA",0x04,0xDCCF,2,0},
{"MOVW [Y],HL",0x04,0xDDCF,2,0},
{"MOVW [Y],X",0x04,0xDECF,2,0},
{"MOVW [Y],Y",0x04,0xDFCF,2,0},
{"MOVW [~0],BA",0x01,0xBC,3,1,8,262224},
{"MOVW [~0],HL",0x01,0xBD,3,1,8,262224},
{"MOVW [~0],SP",0x04,0x7CCF,4,1,16,262224},
{"MOVW [~0],X",0x01,0xBE,3,1,8,262224},
{"MOVW [~0],Y",0x01,0xBF,3,1,8,262224},
{"MOVX A,HL",0x04,0xC9CE,2,0},
{"MOVX A,X",0x04,0xCACE,2,0},
{"MOVX A,Y",0x04,0xCBCE,2,0},
{"MOVX HL,A",0x04,0xCDCE,2,0},
{"MOVX HL,~0",0x04,0xC5CE,3,1,16,131144},
{"MOVX X,A",0x04,0xCECE,2,0},
{"MOVX X,~0",0x04,0xC6CE,3,1,16,131144},
{"MOVX Y,A",0x04,0xCFCE,2,0},
{"MOVX Y,~0",0x04,0xC7CE,3,1,16,131144},
{"MUL L,A",0x04,0xD8CE,2,0},
{"NEG A",0x04,0xA4CE,2,0},
{"NEG B",0x04,0xA5CE,2,0},
{"NEG [HL]",0x04,0xA7CE,2,0},
{"NEG [NN+~0]",0x04,0xA6CE,3,1,16,262216},
{"NEGB A",0x04,0xA4CE,2,0},
{"NEGB B",0x04,0xA5CE,2,0},
{"NEGB [HL]",0x04,0xA7CE,2,0},
{"NEGB [NN+~0]",0x04,0xA6CE,3,1,16,262216},
{"NOP",0x01,0xFF,1,0},
{"NOT A",0x04,0xA0CE,2,0},
{"NOT B",0x04,0xA1CE,2,0},
{"NOT [HL]",0x04,0xA3CE,2,0},
{"NOT [NN+~0]",0x04,0xA2CE,3,1,16,262216},
{"NOTB A",0x04,0xA0CE,2,0},
{"NOTB B",0x04,0xA1CE,2,0},
{"NOTB [HL]",0x04,0xA3CE,2,0},
{"NOTB [NN+~0]",0x04,0xA2CE,3,1,16,262216},
{"OR A,A",0x01,0x28,1,0},
{"OR A,B",0x01,0x29,1,0},
{"OR A,[HL]",0x01,0x2B,1,0},
{"OR A,[NN+~0]",0x01,0x2C,2,1,8,262216},
{"OR A,[X+L]",0x04,0x2ACE,2,0},
{"OR A,[X+~0]",0x04,0x28CE,3,1,16,262216},
{"OR A,[X]",0x01,0x2E,1,0},
{"OR A,[Y+L]",0x04,0x2BCE,2,0},
{"OR A,[Y+~0]",0x04,0x29CE,3,1,16,262216},
{"OR A,[Y]",0x01,0x2F,1,0},
{"OR A,[~0]",0x01,0x2D,3,1,8,262224},
{"OR A,~0",0x01,0x2A,2,1,8,131144},
{"OR B,~0",0x04,0xB4CE,3,1,16,131144},
{"OR F,~0",0x01,0x9D,2,1,8,131144},
{"OR H,~0",0x04,0xB6CE,3,1,16,131144},
{"OR L,~0",0x04,0xB5CE,3,1,16,131144},
{"OR [HL],A",0x04,0x2CCE,2,0},
{"OR [HL],[X]",0x04,0x2ECE,2,0},
{"OR [HL],[Y]",0x04,0x2FCE,2,0},
{"OR [HL],~0",0x04,0x2DCE,3,1,16,131144},
{"OR [NN+~0],~1",0x01,0xD9,3,2,8,131144,16,262216},
{"ORB A,A",0x01,0x28,1,0},
{"ORB A,B",0x01,0x29,1,0},
{"ORB A,[HL]",0x01,0x2B,1,0},
{"ORB A,[NN+~0]",0x01,0x2C,2,1,8,262216},
{"ORB A,[X+L]",0x04,0x2ACE,2,0},
{"ORB A,[X+~0]",0x04,0x28CE,3,1,16,262216},
{"ORB A,[X]",0x01,0x2E,1,0},
{"ORB A,[Y+L]",0x04,0x2BCE,2,0},
{"ORB A,[Y+~0]",0x04,0x29CE,3,1,16,262216},
{"ORB A,[Y]",0x01,0x2F,1,0},
{"ORB A,[~0]",0x01,0x2D,3,1,8,262224},
{"ORB A,~0",0x01,0x2A,2,1,8,131144},
{"ORB B,~0",0x04,0xB4CE,3,1,16,131144},
{"ORB FLAGS,~0",0x01,0x9D,2,1,8,131144},
{"ORB H,~0",0x04,0xB6CE,3,1,16,131144},
{"ORB L,~0",0x04,0xB5CE,3,1,16,131144},
{"ORB [HL],A",0x04,0x2CCE,2,0},
{"ORB [HL],[X]",0x04,0x2ECE,2,0},
{"ORB [HL],[Y]",0x04,0x2FCE,2,0},
{"ORB [HL],~0",0x04,0x2DCE,3,1,16,131144},
{"ORB [NN+~0],~1",0x01,0xD9,3,2,8,131144,16,262216},
{"PACK",0x01,0xDE,1,0},
{"POP A",0x04,0xB4CF,2,0},
{"POP B",0x04,0xB5CF,2,0},
{"POP BA",0x01,0xA8,1,0},
{"POP F",0x01,0xAF,1,0},
{"POP H",0x04,0xB7CF,2,0},
{"POP HL",0x01,0xA9,1,0},
{"POP I",0x01,0xAD,1,0},
{"POP L",0x04,0xB6CF,2,0},
{"POP NN",0x01,0xAC,1,0},
{"POP X",0x01,0xAA,1,0},
{"POP Y",0x01,0xAB,1,0},
{"POPA",0x04,0xBCCF,2,0},
{"POPAX",0x04,0xBDCF,2,0},
{"POPB A",0x04,0xB4CF,2,0},
{"POPB B",0x04,0xB5CF,2,0},
{"POPB FLAGS",0x01,0xAF,1,0},
{"POPB H",0x04,0xB7CF,2,0},
{"POPB L",0x04,0xB6CF,2,0},
{"POPB NN",0x01,0xAC,1,0},
{"POPW BA",0x01,0xA8,1,0},
{"POPW HL",0x01,0xA9,1,0},
{"POPW X",0x01,0xAA,1,0},
{"POPW Y",0x01,0xAB,1,0},
{"POPX HL",0x01,0xAD,1,0},
{"POPX",0x01,0xAE,1,0},
{"POPXXX",0x01,0xAE,1,0},
{"PUSH A",0x04,0xB0CF,2,0},
{"PUSH B",0x04,0xB1CF,2,0},
{"PUSH BA",0x01,0xA0,1,0},
{"PUSH F",0x01,0xA7,1,0},
{"PUSH H",0x04,0xB3CF,2,0},
{"PUSH HL",0x01,0xA1,1,0},
{"PUSH I",0x01,0xA5,1,0},
{"PUSH L",0x04,0xB2CF,2,0},
{"PUSH NN",0x01,0xA4,1,0},
{"PUSH X",0x01,0xA2,1,0},
{"PUSH Y",0x01,0xA3,1,0},
{"PUSHA",0x04,0xB8CF,2,0},
{"PUSHAX",0x04,0xB9CF,2,0},
{"PUSHB A",0x04,0xB0CF,2,0},
{"PUSHB B",0x04,0xB1CF,2,0},
{"PUSHB FLAGS",0x01,0xA7,1,0},
{"PUSHB H",0x04,0xB3CF,2,0},
{"PUSHB L",0x04,0xB2CF,2,0},
{"PUSHB NN",0x01,0xA4,1,0},
{"PUSHW BA",0x01,0xA0,1,0},
{"PUSHW HL",0x01,0xA1,1,0},
{"PUSHW X",0x01,0xA2,1,0},
{"PUSHW Y",0x01,0xA3,1,0},
{"PUSHX HL",0x01,0xA5,1,0},
{"PUSHX",0x01,0xA6,1,0},
{"PUSHXXX",0x01,0xA6,1,0},
{"RET",0x01,0xF8,1,0},
{"RETI",0x01,0xF9,1,0},
{"RETSKIP",0x01,0xFA,1,0},
{"ROL A",0x04,0x94CE,2,0},
{"ROL B",0x04,0x95CE,2,0},
{"ROL [HL]",0x04,0x97CE,2,0},
{"ROL [NN+~0]",0x04,0x96CE,3,1,16,262216},
{"ROLB A",0x04,0x94CE,2,0},
{"ROLB B",0x04,0x95CE,2,0},
{"ROLB [HL]",0x04,0x97CE,2,0},
{"ROLB [NN+~0]",0x04,0x96CE,3,1,16,262216},
{"ROLC A",0x04,0x90CE,2,0},
{"ROLC B",0x04,0x91CE,2,0},
{"ROLC [HL]",0x04,0x93CE,2,0},
{"ROLC [NN+~0]",0x04,0x92CE,3,1,16,262216},
{"ROLCB A",0x04,0x90CE,2,0},
{"ROLCB B",0x04,0x91CE,2,0},
{"ROLCB [HL]",0x04,0x93CE,2,0},
{"ROLCB [NN+~0]",0x04,0x92CE,3,1,16,262216},
{"ROR A",0x04,0x9CCE,2,0},
{"ROR B",0x04,0x9DCE,2,0},
{"ROR [HL]",0x04,0x9FCE,2,0},
{"ROR [NN+~0]",0x04,0x9ECE,3,1,16,262216},
{"RORB A",0x04,0x9CCE,2,0},
{"RORB B",0x04,0x9DCE,2,0},
{"RORB [HL]",0x04,0x9FCE,2,0},
{"RORB [NN+~0]",0x04,0x9ECE,3,1,16,262216},
{"RORC A",0x04,0x98CE,2,0},
{"RORC B",0x04,0x99CE,2,0},
{"RORC [HL]",0x04,0x9BCE,2,0},
{"RORC [NN+~0]",0x04,0x9ACE,3,1,16,262216},
{"RORCB A",0x04,0x98CE,2,0},
{"RORCB B",0x04,0x99CE,2,0},
{"RORCB [HL]",0x04,0x9BCE,2,0},
{"RORCB [NN+~0]",0x04,0x9ACE,3,1,16,262216},
{"SAL A",0x04,0x80CE,2,0},
{"SAL B",0x04,0x81CE,2,0},
{"SAL [HL]",0x04,0x83CE,2,0},
{"SAL [NN+~0]",0x04,0x82CE,3,1,16,262216},
{"SALB A",0x04,0x80CE,2,0},
{"SALB B",0x04,0x81CE,2,0},
{"SALB [HL]",0x04,0x83CE,2,0},
{"SALB [NN+~0]",0x04,0x82CE,3,1,16,262216},
{"SAR A",0x04,0x88CE,2,0},
{"SAR B",0x04,0x89CE,2,0},
{"SAR [HL]",0x04,0x8BCE,2,0},
{"SAR [NN+~0]",0x04,0x8ACE,3,1,16,262216},
{"SARB A",0x04,0x88CE,2,0},
{"SARB B",0x04,0x89CE,2,0},
{"SARB [HL]",0x04,0x8BCE,2,0},
{"SARB [NN+~0]",0x04,0x8ACE,3,1,16,262216},
{"SBC A,A",0x01,0x18,1,0},
{"SBC A,B",0x01,0x19,1,0},
{"SBC A,[HL]",0x01,0x1B,1,0},
{"SBC A,[NN+~0]",0x01,0x1C,2,1,8,262216},
{"SBC A,[X+L]",0x04,0x1ACE,2,0},
{"SBC A,[X+~0]",0x04,0x18CE,3,1,16,262216},
{"SBC A,[X]",0x01,0x1E,1,0},
{"SBC A,[Y+L]",0x04,0x1BCE,2,0},
{"SBC A,[Y+~0]",0x04,0x19CE,3,1,16,262216},
{"SBC A,[Y]",0x01,0x1F,1,0},
{"SBC A,[~0]",0x01,0x1D,3,1,8,262224},
{"SBC A,~0",0x01,0x1A,2,1,8,131144},
{"SBC BA,BA",0x04,0xCCF,2,0},
{"SBC BA,HL",0x04,0xDCF,2,0},
{"SBC BA,X",0x04,0xECF,2,0},
{"SBC BA,Y",0x04,0xFCF,2,0},
{"SBC BA,~0",0x04,0x62CF,4,1,16,131152},
{"SBC HL,BA",0x04,0x2CCF,2,0},
{"SBC HL,HL",0x04,0x2DCF,2,0},
{"SBC HL,X",0x04,0x2ECF,2,0},
{"SBC HL,Y",0x04,0x2FCF,2,0},
{"SBC HL,~0",0x04,0x63CF,4,1,16,131152},
{"SBC [HL],A",0x04,0x1CCE,2,0},
{"SBC [HL],[X]",0x04,0x1ECE,2,0},
{"SBC [HL],[Y]",0x04,0x1FCE,2,0},
{"SBC [HL],~0",0x04,0x1DCE,3,1,16,131144},
{"SHL A",0x04,0x84CE,2,0},
{"SHL B",0x04,0x85CE,2,0},
{"SHL [HL]",0x04,0x87CE,2,0},
{"SHL [NN+~0]",0x04,0x86CE,3,1,16,262216},
{"SHLB A",0x04,0x84CE,2,0},
{"SHLB B",0x04,0x85CE,2,0},
{"SHLB [HL]",0x04,0x87CE,2,0},
{"SHLB [NN+~0]",0x04,0x86CE,3,1,16,262216},
{"SHR A",0x04,0x8CCE,2,0},
{"SHR B",0x04,0x8DCE,2,0},
{"SHR [HL]",0x04,0x8FCE,2,0},
{"SHR [NN+~0]",0x04,0x8ECE,3,1,16,262216},
{"SHRB A",0x04,0x8CCE,2,0},
{"SHRB B",0x04,0x8DCE,2,0},
{"SHRB [HL]",0x04,0x8FCE,2,0},
{"SHRB [NN+~0]",0x04,0x8ECE,3,1,16,262216},
{"STOP",0x04,0xAFCE,2,0},
{"SUB A,A",0x01,0x10,1,0},
{"SUB A,B",0x01,0x11,1,0},
{"SUB A,[HL]",0x01,0x13,1,0},
{"SUB A,[NN+~0]",0x01,0x14,2,1,8,262216},
{"SUB A,[X+L]",0x04,0x12CE,2,0},
{"SUB A,[X+~0]",0x04,0x10CE,3,1,16,262216},
{"SUB A,[X]",0x01,0x16,1,0},
{"SUB A,[Y+L]",0x04,0x13CE,2,0},
{"SUB A,[Y+~0]",0x04,0x11CE,3,1,16,262216},
{"SUB A,[Y]",0x01,0x17,1,0},
{"SUB A,[~0]",0x01,0x15,3,1,8,262224},
{"SUB A,~0",0x01,0x12,2,1,8,131144},
{"SUB BA,BA",0x04,0x8CF,2,0},
{"SUB BA,HL",0x04,0x9CF,2,0},
{"SUB BA,X",0x04,0xACF,2,0},
{"SUB BA,Y",0x04,0xBCF,2,0},
{"SUB BA,~0",0x01,0xD0,3,1,8,131152},
{"SUB HL,BA",0x04,0x28CF,2,0},
{"SUB HL,HL",0x04,0x29CF,2,0},
{"SUB HL,X",0x04,0x2ACF,2,0},
{"SUB HL,Y",0x04,0x2BCF,2,0},
{"SUB HL,~0",0x01,0xD1,3,1,8,131152},
{"SUB SP,BA",0x04,0x4CCF,2,0},
{"SUB SP,HL",0x04,0x4DCF,2,0},
{"SUB SP,~0",0x04,0x6ACF,4,1,16,131152},
{"SUB X,BA",0x04,0x48CF,2,0},
{"SUB X,HL",0x04,0x49CF,2,0},
{"SUB X,~0",0x01,0xD2,3,1,8,131152},
{"SUB Y,~0",0x01,0xD3,3,1,8,131152},
{"SUB Y,BA",0x04,0x4ACF,2,0},
{"SUB Y,HL",0x04,0x4BCF,2,0},
{"SUB [HL],A",0x04,0x14CE,2,0},
{"SUB [HL],[X]",0x04,0x16CE,2,0},
{"SUB [HL],[Y]",0x04,0x17CE,2,0},
{"SUB [HL],~0",0x04,0x15CE,3,1,16,131144},
{"SUBB A,A",0x01,0x10,1,0},
{"SUBB A,B",0x01,0x11,1,0},
{"SUBB A,[HL]",0x01,0x13,1,0},
{"SUBB A,[NN+~0]",0x01,0x14,2,1,8,262216},
{"SUBB A,[X+L]",0x04,0x12CE,2,0},
{"SUBB A,[X+~0]",0x04,0x10CE,3,1,16,262216},
{"SUBB A,[X]",0x01,0x16,1,0},
{"SUBB A,[Y+L]",0x04,0x13CE,2,0},
{"SUBB A,[Y+~0]",0x04,0x11CE,3,1,16,262216},
{"SUBB A,[Y]",0x01,0x17,1,0},
{"SUBB A,[~0]",0x01,0x15,3,1,8,262224},
{"SUBB A,~0",0x01,0x12,2,1,8,131144},
{"SUBB [HL],A",0x04,0x14CE,2,0},
{"SUBB [HL],[X]",0x04,0x16CE,2,0},
{"SUBB [HL],[Y]",0x04,0x17CE,2,0},
{"SUBB [HL],~0",0x04,0x15CE,3,1,16,131144},
{"SUBCB A,A",0x01,0x18,1,0},
{"SUBCB A,B",0x01,0x19,1,0},
{"SUBCB A,[HL]",0x01,0x1B,1,0},
{"SUBCB A,[NN+~0]",0x01,0x1C,2,1,8,262216},
{"SUBCB A,[X+L]",0x04,0x1ACE,2,0},
{"SUBCB A,[X+~0]",0x04,0x18CE,3,1,16,262216},
{"SUBCB A,[X]",0x01,0x1E,1,0},
{"SUBCB A,[Y+L]",0x04,0x1BCE,2,0},
{"SUBCB A,[Y+~0]",0x04,0x19CE,3,1,16,262216},
{"SUBCB A,[Y]",0x01,0x1F,1,0},
{"SUBCB A,[~0]",0x01,0x1D,3,1,8,262224},
{"SUBCB A,~0",0x01,0x1A,2,1,8,131144},
{"SUBCB [HL],A",0x04,0x1CCE,2,0},
{"SUBCB [HL],[X]",0x04,0x1ECE,2,0},
{"SUBCB [HL],[Y]",0x04,0x1FCE,2,0},
{"SUBCB [HL],~0",0x04,0x1DCE,3,1,16,131144},
{"SUBCW BA,BA",0x04,0xCCF,2,0},
{"SUBCW BA,HL",0x04,0xDCF,2,0},
{"SUBCW BA,X",0x04,0xECF,2,0},
{"SUBCW BA,Y",0x04,0xFCF,2,0},
{"SUBCW HL,BA",0x04,0x2CCF,2,0},
{"SUBCW HL,HL",0x04,0x2DCF,2,0},
{"SUBCW HL,X",0x04,0x2ECF,2,0},
{"SUBCW HL,Y",0x04,0x2FCF,2,0},
{"SUBW BA,BA",0x04,0x8CF,2,0},
{"SUBW BA,HL",0x04,0x9CF,2,0},
{"SUBW BA,X",0x04,0xACF,2,0},
{"SUBW BA,Y",0x04,0xBCF,2,0},
{"SUBW BA,~0",0x01,0xD0,3,1,8,131152},
{"SUBW HL,BA",0x04,0x28CF,2,0},
{"SUBW HL,HL",0x04,0x29CF,2,0},
{"SUBW HL,X",0x04,0x2ACF,2,0},
{"SUBW HL,Y",0x04,0x2BCF,2,0},
{"SUBW HL,~0",0x01,0xD1,3,1,8,131152},
{"SUBW SP,BA",0x04,0x4CCF,2,0},
{"SUBW SP,HL",0x04,0x4DCF,2,0},
{"SUBW SP,~0",0x04,0x6ACF,4,1,16,131152},
{"SUBW X,~0",0x01,0xD2,3,1,8,131152},
{"SUBW X,BA",0x04,0x48CF,2,0},
{"SUBW X,HL",0x04,0x49CF,2,0},
{"SUBW Y,BA",0x04,0x4ACF,2,0},
{"SUBW Y,HL",0x04,0x4BCF,2,0},
{"SUBW Y,~0",0x01,0xD3,3,1,8,131152},
{"SWAP A",0x01,0xF6,1,0},
{"SWAP [HL]",0x01,0xF7,1,0},
{"TESTB A,B",0x01,0x94,1,0},
{"TESTB A,~0",0x01,0x96,2,1,8,131144},
{"TESTB B,~0",0x01,0x97,2,1,8,131144},
{"TESTB [HL],~0",0x01,0x95,2,1,8,131144},
{"TESTB [NN+~0],~1",0x01,0xDC,3,2,8,131144,16,262216},
{"TST A,B",0x01,0x94,1,0},
{"TST A,~0",0x01,0x96,2,1,8,131144},
{"TST B,~0",0x01,0x97,2,1,8,131144},
{"TST [HL],~0",0x01,0x95,2,1,8,131144},
{"TST [NN+~0],~1",0x01,0xDC,3,2,8,131144,16,262216},
{"UNPACK",0x01,0xDF,1,0},
{"XCHG A,B",0x01,0xCC,1,0},
{"XCHG A,[HL]",0x01,0xCD,1,0},
{"XCHG BA,HL",0x01,0xC8,1,0},
{"XCHG BA,SP",0x01,0xCB,1,0},
{"XCHG BA,X",0x01,0xC9,1,0},
{"XCHG BA,Y",0x01,0xCA,1,0},
{"XCHGB A,B",0x01,0xCC,1,0},
{"XCHGB A,[HL]",0x01,0xCD,1,0},
{"XCHGW BA,HL",0x01,0xC8,1,0},
{"XCHGW BA,SP",0x01,0xCB,1,0},
{"XCHGW BA,X",0x01,0xC9,1,0},
{"XCHGW BA,Y",0x01,0xCA,1,0},
{"XOR A,A",0x01,0x38,1,0},
{"XOR A,B",0x01,0x39,1,0},
{"XOR A,[HL]",0x01,0x3B,1,0},
{"XOR A,[NN+~0]",0x01,0x3C,2,1,8,262216},
{"XOR A,[X+L]",0x04,0x3ACE,2,0},
{"XOR A,[X+~0]",0x04,0x38CE,3,1,16,262216},
{"XOR A,[X]",0x01,0x3E,1,0},
{"XOR A,[Y+L]",0x04,0x3BCE,2,0},
{"XOR A,[Y+~0]",0x04,0x39CE,3,1,16,262216},
{"XOR A,[Y]",0x01,0x3F,1,0},
{"XOR A,[~0]",0x01,0x3D,3,1,8,262224},
{"XOR A,~0",0x01,0x3A,2,1,8,131144},
{"XOR B,~0",0x04,0xB8CE,3,1,16,131144},
{"XOR F,~0",0x01,0x9E,2,1,8,131144},
{"XOR H,~0",0x04,0xBACE,3,1,16,131144},
{"XOR L,~0",0x04,0xB9CE,3,1,16,131144},
{"XOR [HL],A",0x04,0x3CCE,2,0},
{"XOR [HL],[X]",0x04,0x3ECE,2,0},
{"XOR [HL],[Y]",0x04,0x3FCE,2,0},
{"XOR [HL],~0",0x04,0x3DCE,3,1,16,131144},
{"XOR [NN+~0],~1",0x01,0xDA,3,2,8,131144,16,262216},
{"XORB A,A",0x01,0x38,1,0},
{"XORB A,B",0x01,0x39,1,0},
{"XORB A,[HL]",0x01,0x3B,1,0},
{"XORB A,[NN+~0]",0x01,0x3C,2,1,8,262216},
{"XORB A,[X+L]",0x04,0x3ACE,2,0},
{"XORB A,[X+~0]",0x04,0x38CE,3,1,16,262216},
{"XORB A,[X]",0x01,0x3E,1,0},
{"XORB A,[Y+L]",0x04,0x3BCE,2,0},
{"XORB A,[Y+~0]",0x04,0x39CE,3,1,16,262216},
{"XORB A,[Y]",0x01,0x3F,1,0},
{"XORB A,[~0]",0x01,0x3D,3,1,8,262224},
{"XORB A,~0",0x01,0x3A,2,1,8,131144},
{"XORB B,~0",0x04,0xB8CE,3,1,16,131144},
{"XORB FLAGS,~0",0x01,0x9E,2,1,8,131144},
{"XORB H,~0",0x04,0xBACE,3,1,16,131144},
{"XORB L,~0",0x04,0xB9CE,3,1,16,131144},
{"XORB [HL],A",0x04,0x3CCE,2,0},
{"XORB [HL],[X]",0x04,0x3ECE,2,0},
{"XORB [HL],[Y]",0x04,0x3FCE,2,0},
{"XORB [HL],~0",0x04,0x3DCE,3,1,16,131144},
{"XORB [NN+~0],~1",0x01,0xDA,3,2,8,131144,16,262216},
};
