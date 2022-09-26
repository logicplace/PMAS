;; Config
.option output_ext ".min"

;; 8-bit instructions
; Addition
.instruction "ADD A,A",0x11,0x00,1,0	; 114
.instruction "ADD A,B",0x11,0x01,1,0	; 116
.instruction "ADD A,~0",0x11,0x02,2,1,8,0x020048	; 118
.instruction "ADD A,[HL]",0x11,0x03,1,0	; 120
.instruction "ADD A,[BR:~0]",0x11,0x04,2,1,8,0x040048	; 122
.instruction "ADD A,[~0]",0x11,0x05,3,1,8,0x040050	; 125
.instruction "ADD A,[IX]",0x11,0x06,1,0	; 127
.instruction "ADD A,[IY]",0x11,0x07,1,0	; 129
.instruction "ADD A,[IX+~0]",0x14,0x00CE,3,1,16,0x040048	; 652
.instruction "ADD A,[IY+~0]",0x14,0x01CE,3,1,16,0x040048	; 655
.instruction "ADD A,[IX+L]",0x14,0x02CE,2,0	; 658
.instruction "ADD A,[IY+L]",0x14,0x03CE,2,0	; 661
.instruction "ADD [HL],A",0x14,0x04CE,2,0	; 664
.instruction "ADD [HL],~0",0x14,0x05CE,3,1,16,0x020048	; 667
.instruction "ADD [HL],[IX]",0x14,0x06CE,2,0	; 670
.instruction "ADD [HL],[IY]",0x14,0x07CE,2,0	; 674

.instruction "ADC A,A",0x11,0x08,1,0	; 131
.instruction "ADC A,B",0x11,0x09,1,0	; 133
.instruction "ADC A,~0",0x11,0x0A,2,1,8,0x020048	; 135
.instruction "ADC A,[HL]",0x11,0x0B,1,0	; 137
.instruction "ADC A,[BR:~0]",0x11,0x0C,2,1,8,0x040048	; 140
.instruction "ADC A,[~0]",0x11,0x0D,3,1,8,0x040050	; 143
.instruction "ADC A,[IX]",0x11,0x0E,1,0	; 146
.instruction "ADC A,[IY]",0x11,0x0F,1,0	; 149
.instruction "ADC A,[IX+~0]",0x14,0x08CE,3,1,16,0x040048	; 678
.instruction "ADC A,[IY+~0]",0x14,0x09CE,3,1,16,0x040048	; 681
.instruction "ADC A,[IX+L]",0x14,0x0ACE,2,0	; 684
.instruction "ADC A,[IY+L]",0x14,0x0BCE,2,0	; 687
.instruction "ADC [HL],A",0x14,0x0CCE,2,0	; 690
.instruction "ADC [HL],~0",0x14,0x0DCE,3,1,16,0x020048	; 693
.instruction "ADC [HL],[IX]",0x14,0x0ECE,2,0	; 696
.instruction "ADC [HL],[IY]",0x14,0x0FCE,2,0	; 700

; Subtraction
.instruction "SUB A,A",0x11,0x10,1,0	; 152
.instruction "SUB A,B",0x11,0x11,1,0	; 154
.instruction "SUB A,~0",0x11,0x12,2,1,8,0x020048	; 156
.instruction "SUB A,[HL]",0x11,0x13,1,0	; 158
.instruction "SUB A,[BR:~0]",0x11,0x14,2,1,8,0x040048	; 160
.instruction "SUB A,[~0]",0x11,0x15,3,1,8,0x040050	; 163
.instruction "SUB A,[IX]",0x11,0x16,1,0	; 165
.instruction "SUB A,[IY]",0x11,0x17,1,0	; 167
.instruction "SUB A,[IX+~0]",0x14,0x10CE,3,1,16,0x040048	; 704
.instruction "SUB A,[IY+~0]",0x14,0x11CE,3,1,16,0x040048	; 707
.instruction "SUB A,[IX+L]",0x14,0x12CE,2,0	; 710
.instruction "SUB A,[IY+L]",0x14,0x13CE,2,0	; 713
.instruction "SUB [HL],A",0x14,0x14CE,2,0	; 716
.instruction "SUB [HL],~0",0x14,0x15CE,3,1,16,0x020048	; 719
.instruction "SUB [HL],[IX]",0x14,0x16CE,2,0	; 722
.instruction "SUB [HL],[IY]",0x14,0x17CE,2,0	; 726

.instruction "SBC A,A",0x11,0x18,1,0	; 169
.instruction "SBC A,B",0x11,0x19,1,0	; 171
.instruction "SBC A,~0",0x11,0x1A,2,1,8,0x020048	; 173
.instruction "SBC A,[HL]",0x11,0x1B,1,0	; 175
.instruction "SBC A,[BR:~0]",0x11,0x1C,2,1,8,0x040048	; 178
.instruction "SBC A,[~0]",0x11,0x1D,3,1,8,0x040050	; 181
.instruction "SBC A,[IX]",0x11,0x1E,1,0	; 184
.instruction "SBC A,[IY]",0x11,0x1F,1,0	; 187
.instruction "SBC A,[IX+~0]",0x14,0x18CE,3,1,16,0x040048	; 730
.instruction "SBC A,[IY+~0]",0x14,0x19CE,3,1,16,0x040048	; 733
.instruction "SBC A,[IX+L]",0x14,0x1ACE,2,0	; 736
.instruction "SBC A,[IY+L]",0x14,0x1BCE,2,0	; 739
.instruction "SBC [HL],A",0x14,0x1CCE,2,0	; 742
.instruction "SBC [HL],~0",0x14,0x1DCE,3,1,16,0x020048	; 745
.instruction "SBC [HL],[IX]",0x14,0x1ECE,2,0	; 748
.instruction "SBC [HL],[IY]",0x14,0x1FCE,2,0	; 752

; Logical product
.instruction "AND A,A",0x11,0x20,1,0	; 190
.instruction "AND A,B",0x11,0x21,1,0	; 192
.instruction "AND A,~0",0x11,0x22,2,1,8,0x020048	; 194
.instruction "AND A,[HL]",0x11,0x23,1,0	; 196
.instruction "AND A,[BR:~0]",0x11,0x24,2,1,8,0x040048	; 198
.instruction "AND A,[~0]",0x11,0x25,3,1,8,0x040050	; 201
.instruction "AND A,[IX]",0x11,0x26,1,0	; 204
.instruction "AND A,[IY]",0x11,0x27,1,0	; 206
.instruction "AND A,[IX+~0]",0x14,0x20CE,3,1,16,0x040048	; 756
.instruction "AND A,[IY+~0]",0x14,0x21CE,3,1,16,0x040048	; 759
.instruction "AND A,[IX+L]",0x14,0x22CE,2,0	; 762
.instruction "AND A,[IY+L]",0x14,0x23CE,2,0	; 765
.instruction "AND B,~0",0x14,0xB0CE,3,1,16,0x020048	; 1029
.instruction "AND H,~0",0x14,0xB2CE,3,1,16,0x020048	; 1033
.instruction "AND [BR:~0],~1",0x11,0xD8,3,2,8,0x020048,16,0x040048	; 465
.instruction "AND [HL],A",0x14,0x24CE,2,0	; 768
.instruction "AND [HL],~0",0x14,0x25CE,3,1,16,0x020048	; 771
.instruction "AND [HL],[IX]",0x14,0x26CE,2,0	; 774
.instruction "AND [HL],[IY]",0x14,0x27CE,2,0	; 778
.instruction "AND L,~0",0x14,0xB1CE,3,1,16,0x020048	; 1031
.instruction "AND SC,~0",0x11,0x9C,2,1,8,0x020048	; 376

; Logical sum
.instruction "OR A,A",0x11,0x28,1,0	; 208
.instruction "OR A,B",0x11,0x29,1,0	; 210
.instruction "OR A,~0",0x11,0x2A,2,1,8,0x020048	; 212
.instruction "OR A,[HL]",0x11,0x2B,1,0	; 214
.instruction "OR A,[BR:~0]",0x11,0x2C,2,1,8,0x040048	; 216
.instruction "OR A,[~0]",0x11,0x2D,3,1,8,0x040050	; 219
.instruction "OR A,[IX]",0x11,0x2E,1,0	; 222
.instruction "OR A,[IY]",0x11,0x2F,1,0	; 224
.instruction "OR A,[IX+~0]",0x14,0x28CE,3,1,16,0x040048	; 782
.instruction "OR A,[IY+~0]",0x14,0x29CE,3,1,16,0x040048	; 785
.instruction "OR A,[IX+L]",0x14,0x2ACE,2,0	; 788
.instruction "OR A,[IY+L]",0x14,0x2BCE,2,0	; 791
.instruction "OR B,~0",0x14,0xB4CE,3,1,16,0x020048	; 1035
.instruction "OR H,~0",0x14,0xB6CE,3,1,16,0x020048	; 1039
.instruction "OR [BR:~0],~1",0x11,0xD9,3,2,8,0x020048,16,0x040048	; 469
.instruction "OR [HL],A",0x14,0x2CCE,2,0	; 794
.instruction "OR [HL],~0",0x14,0x2DCE,3,1,16,0x020048	; 797
.instruction "OR [HL],[IX]",0x14,0x2ECE,2,0	; 800
.instruction "OR [HL],[IY]",0x14,0x2FCE,2,0	; 804
.instruction "OR L,~0",0x14,0xB5CE,3,1,16,0x020048	; 1037
.instruction "OR SC,~0",0x11,0x9D,2,1,8,0x020048	; 378

; Exclusive OR
.instruction "XOR A,A",0x11,0x38,1,0	; 252
.instruction "XOR A,B",0x11,0x39,1,0	; 254
.instruction "XOR A,~0",0x11,0x3A,2,1,8,0x020048	; 256
.instruction "XOR A,[HL]",0x11,0x3B,1,0	; 258
.instruction "XOR A,[BR:~0]",0x11,0x3C,2,1,8,0x040048	; 260
.instruction "XOR A,[~0]",0x11,0x3D,3,1,8,0x040050	; 263
.instruction "XOR A,[IX]",0x11,0x3E,1,0	; 266
.instruction "XOR A,[IY]",0x11,0x3F,1,0	; 268
.instruction "XOR A,[IX+~0]",0x14,0x38CE,3,1,16,0x040048	; 838
.instruction "XOR A,[IY+~0]",0x14,0x39CE,3,1,16,0x040048	; 841
.instruction "XOR A,[IX+L]",0x14,0x3ACE,2,0	; 844
.instruction "XOR A,[IY+L]",0x14,0x3BCE,2,0	; 847
.instruction "XOR B,~0",0x14,0xB8CE,3,1,16,0x020048	; 1041
.instruction "XOR H,~0",0x14,0xBACE,3,1,16,0x020048	; 1045
.instruction "XOR [BR:~0],~1",0x11,0xDA,3,2,8,0x020048,16,0x040048	; 473
.instruction "XOR [HL],[IX]",0x14,0x3ECE,2,0	; 856
.instruction "XOR [HL],[IY]",0x14,0x3FCE,2,0	; 860
.instruction "XOR [HL],A",0x14,0x3CCE,2,0	; 850
.instruction "XOR [HL],~0",0x14,0x3DCE,3,1,16,0x020048	; 853
.instruction "XOR L,~0",0x14,0xB9CE,3,1,16,0x020048	; 1043
.instruction "XOR SC,~0",0x11,0x9E,2,1,8,0x020048	; 380

; Comparison
.instruction "CP A,A",0x11,0x30,1,0	; 226
.instruction "CP A,B",0x11,0x31,1,0	; 229
.instruction "CP A,~0",0x11,0x32,2,1,8,0x020048	; 232
.instruction "CP A,[HL]",0x11,0x33,1,0	; 235
.instruction "CP A,[BR:~0]",0x11,0x34,2,1,8,0x040048	; 238
.instruction "CP A,[~0]",0x11,0x35,3,1,8,0x040050	; 242
.instruction "CP A,[IX]",0x11,0x36,1,0	; 246
.instruction "CP A,[IX+~0]",0x14,0x30CE,3,1,16,0x040048	; 808
.instruction "CP A,[IX+L]",0x14,0x32CE,2,0	; 816
.instruction "CP A,[IY]",0x11,0x37,1,0	; 249
.instruction "CP A,[IY+~0]",0x14,0x31CE,3,1,16,0x040048	; 812
.instruction "CP A,[IY+L]",0x14,0x33CE,2,0	; 820
.instruction "CP B,~0",0x14,0xBCCE,3,1,16,0x020048	; 1047
.instruction "CP H,~0",0x14,0xBECE,3,1,16,0x020048	; 1055
.instruction "CP BR,~0",0x14,0xBFCE,3,1,16,0x020048	; 1059
.instruction "CP [BR:~0],~1",0x11,0xDB,3,2,8,0x020048,16,0x040048	; 477
.instruction "CP [HL],A",0x14,0x34CE,2,0	; 824
.instruction "CP [HL],~0",0x14,0x35CE,3,1,16,0x020048	; 827
.instruction "CP [HL],[IX]",0x14,0x36CE,2,0	; 830
.instruction "CP [HL],[IY]",0x14,0x37CE,2,0	; 834
.instruction "CP L,~0",0x14,0xBDCE,3,1,16,0x020048	; 1051

; Bit test
.instruction "BIT A,B",0x11,0x94,1,0	; 361
.instruction "BIT A,~0",0x11,0x96,2,1,8,0x020048	; 368
.instruction "BIT B,~0",0x11,0x97,2,1,8,0x020048	; 371
.instruction "BIT [HL],~0",0x11,0x95,2,1,8,0x020048	; 364
.instruction "BIT [BR:~0],~1",0x11,0xDC,3,2,8,0x020048,16,0x040048	; 482

; Increment by 1
.instruction "INC A",0x11,0x80,1,0	; 335
.instruction "INC B",0x11,0x81,1,0	; 335
.instruction "INC H",0x11,0x83,1,0	; 335
.instruction "INC [BR:~0]",0x11,0x85,2,1,8,0x040048	; 339
.instruction "INC [HL]",0x11,0x86,1,0	; 342
.instruction "INC L",0x11,0x82,1,0	; 335
.instruction "INC BR",0x11,0x84,1,0	; 337

; Decrement by 1
.instruction "DEC A",0x11,0x88,1,0	; 347
.instruction "DEC B",0x11,0x89,1,0	; 347
.instruction "DEC H",0x11,0x8B,1,0	; 347
.instruction "DEC [BR:~0]",0x11,0x8D,2,1,8,0x040048	; 351
.instruction "DEC [HL]",0x11,0x8E,1,0	; 354
.instruction "DEC L",0x11,0x8A,1,0	; 347
.instruction "DEC BR",0x11,0x8C,1,0	; 349

; Multiplication
.instruction "MLT",0x14,0xD8CE,2,0	; 1099

; Division
.instruction "DIV",0x14,0xD9CE,2,0	; 1101

; Complement of 1
.instruction "CPL A",0x14,0xA0CE,2,0	; 1002
.instruction "CPL B",0x14,0xA1CE,2,0	; 1004
.instruction "CPL [HL]",0x14,0xA3CE,2,0	; 1009
.instruction "CPL [BR:~0]",0x14,0xA2CE,3,1,16,0x040048	; 1006

; Complement of 2
.instruction "NEG A",0x14,0xA4CE,2,0	; 1012
.instruction "NEG B",0x14,0xA5CE,2,0	; 1014
.instruction "NEG [HL]",0x14,0xA7CE,2,0	; 1019
.instruction "NEG [BR:~0]",0x14,0xA6CE,3,1,16,0x040048	; 1016

; 8-bit transfer
.instruction "LD A,A",0x11,0x40,1,0	; 270
.instruction "LD A,B",0x11,0x41,1,0	; 270
.instruction "LD A,~0",0x11,0xB0,2,1,8,0x020048	; 418
.instruction "LD A,L",0x11,0x42,1,0	; 270
.instruction "LD A,H",0x11,0x43,1,0	; 270
.instruction "LD A,[BR:~0]",0x11,0x44,2,1,8,0x040048	; 272
.instruction "LD A,[HL]",0x11,0x45,1,0	; 275
.instruction "LD A,[IX]",0x11,0x46,1,0	; 277
.instruction "LD A,[IY]",0x11,0x47,1,0	; 279
.instruction "LD A,[IX+~0]",0x14,0x40CE,3,1,16,0x040048	; 864
.instruction "LD A,[IY+~0]",0x14,0x41CE,3,1,16,0x040048	; 866
.instruction "LD A,[IX+L]",0x14,0x42CE,2,0	; 868
.instruction "LD A,[IY+L]",0x14,0x43CE,2,0	; 870
.instruction "LD A,BR",0x14,0xC0CE,2,0	; 1063
.instruction "LD A,SC",0x14,0xC1CE,2,0	; 1065
.instruction "LD A,NB",0x14,0xC8CE,2,0	; 1079
.instruction "LD A,EP",0x14,0xC9CE,2,0	; 1081
.instruction "LD A,XP",0x14,0xCACE,2,0	; 1083
.instruction "LD A,YP",0x14,0xCBCE,2,0	; 1085
.instruction "LD A,[~0]",0x14,0xD0CE,4,1,16,0x040050	; 1095

.instruction "LD B,A",0x11,0x48,1,0	; 270
.instruction "LD B,B",0x11,0x49,1,0	; 270
.instruction "LD B,L",0x11,0x4A,1,0	; 270
.instruction "LD B,H",0x11,0x4B,1,0	; 270
.instruction "LD B,[BR:~0]",0x11,0x4C,2,1,8,0x040048	; 272
.instruction "LD B,[HL]",0x11,0x4D,1,0	; 275
.instruction "LD B,[IX]",0x11,0x4E,1,0	; 277
.instruction "LD B,[IY]",0x11,0x4F,1,0	; 279
.instruction "LD B,~0",0x11,0xB1,2,1,8,0x020048	; 418
.instruction "LD B,[IX+~0]",0x14,0x48CE,3,1,16,0x040048	; 864
.instruction "LD B,[IY+~0]",0x14,0x49CE,3,1,16,0x040048	; 866
.instruction "LD B,[IX+L]",0x14,0x4ACE,2,0	; 868
.instruction "LD B,[IY+L]",0x14,0x4BCE,2,0	; 870
.instruction "LD B,[~0]",0x14,0xD1CE,4,1,16,0x040050	; 1095

.instruction "LD L,A",0x11,0x50,1,0	; 270
.instruction "LD L,B",0x11,0x51,1,0	; 270
.instruction "LD L,L",0x11,0x52,1,0	; 270
.instruction "LD L,H",0x11,0x53,1,0	; 270
.instruction "LD L,[BR:~0]",0x11,0x54,2,1,8,0x040048	; 272
.instruction "LD L,[HL]",0x11,0x55,1,0	; 275
.instruction "LD L,[IX]",0x11,0x56,1,0	; 277
.instruction "LD L,[IY]",0x11,0x57,1,0	; 279
.instruction "LD L,~0",0x11,0xB2,2,1,8,0x020048	; 418
.instruction "LD L,[IX+~0]",0x14,0x50CE,3,1,16,0x040048	; 864
.instruction "LD L,[IY+~0]",0x14,0x51CE,3,1,16,0x040048	; 866
.instruction "LD L,[IX+L]",0x14,0x52CE,2,0	; 868
.instruction "LD L,[IY+L]",0x14,0x53CE,2,0	; 870
.instruction "LD L,[~0]",0x14,0xD2CE,4,1,16,0x040050	; 1095

.instruction "LD H,A",0x11,0x58,1,0	; 270
.instruction "LD H,B",0x11,0x59,1,0	; 270
.instruction "LD H,L",0x11,0x5A,1,0	; 270
.instruction "LD H,H",0x11,0x5B,1,0	; 270
.instruction "LD H,[BR:~0]",0x11,0x5C,2,1,8,0x040048	; 272
.instruction "LD H,[HL]",0x11,0x5D,1,0	; 275
.instruction "LD H,[IX]",0x11,0x5E,1,0	; 277
.instruction "LD H,[IY]",0x11,0x5F,1,0	; 279
.instruction "LD H,[~0]",0x14,0xD3CE,4,1,16,0x040050	; 1095
.instruction "LD H,[IX+~0]",0x14,0x58CE,3,1,16,0x040048	; 864
.instruction "LD H,[IY+~0]",0x14,0x59CE,3,1,16,0x040048	; 866
.instruction "LD H,[IX+L]",0x14,0x5ACE,2,0	; 868
.instruction "LD H,[IY+L]",0x14,0x5BCE,2,0	; 870
.instruction "LD H,~0",0x11,0xB3,2,1,8,0x020048	; 418

.instruction "LD BR,~0",0x11,0xB4,2,1,8,0x020048	; 420
.instruction "LD BR,A",0x14,0xC2CE,2,0	; 1067

.instruction "LD SC,~0",0x11,0x9F,2,1,8,0x020048	; 382
.instruction "LD SC,A",0x14,0xC3CE,2,0	; 1069

.instruction "LD NB,~0",0x14,0xC4CE,3,1,16,0x020048	; 1071
.instruction "LD NB,A",0x14,0xCCCE,2,0	; 1087
.instruction "LD EP,~0",0x14,0xC5CE,3,1,16,0x020048	; 1073
.instruction "LD EP,A",0x14,0xCDCE,2,0	; 1089
.instruction "LD XP,~0",0x14,0xC6CE,3,1,16,0x020048	; 1075
.instruction "LD XP,A",0x14,0xCECE,2,0	; 1091
.instruction "LD YP,~0",0x14,0xC7CE,3,1,16,0x020048	; 1077
.instruction "LD YP,A",0x14,0xCFCE,2,0	; 1093

.instruction "LD [BR:~0],A",0x11,0x78,2,1,8,0x040048	; 323
.instruction "LD [BR:~0],B",0x11,0x79,2,1,8,0x040048	; 323
.instruction "LD [BR:~0],L",0x11,0x7A,2,1,8,0x040048	; 323
.instruction "LD [BR:~0],H",0x11,0x7B,2,1,8,0x040048	; 323
.instruction "LD [BR:~0],[HL]",0x11,0x7D,2,1,8,0x040048	; 326
.instruction "LD [BR:~0],[IX]",0x11,0x7E,2,1,8,0x040048	; 329
.instruction "LD [BR:~0],[IY]",0x11,0x7F,2,1,8,0x040048	; 332
.instruction "LD [BR:~0],~1",0x11,0xDD,3,2,8,0x020048,16,0x040048	; 487

.instruction "LD [~0],A",0x14,0xD4CE,4,1,16,0x040050	; 1097
.instruction "LD [~0],B",0x14,0xD5CE,4,1,16,0x040050	; 1097
.instruction "LD [~0],L",0x14,0xD6CE,4,1,16,0x040050	; 1097
.instruction "LD [~0],H",0x14,0xD7CE,4,1,16,0x040050	; 1097

.instruction "LD [HL],A",0x11,0x68,1,0	; 295
.instruction "LD [HL],B",0x11,0x69,1,0	; 295
.instruction "LD [HL],L",0x11,0x6A,1,0	; 295
.instruction "LD [HL],H",0x11,0x6B,1,0	; 295
.instruction "LD [HL],[BR:~0]",0x11,0x6C,2,1,8,0x040048	; 297
.instruction "LD [HL],[HL]",0x11,0x6D,1,0	; 300
.instruction "LD [HL],[IX]",0x11,0x6E,1,0	; 303
.instruction "LD [HL],[IY]",0x11,0x6F,1,0	; 306
.instruction "LD [HL],~0",0x11,0xB5,2,1,8,0x020048	; 422
.instruction "LD [HL],[IX+~0]",0x14,0x60CE,3,1,16,0x040048	; 880
.instruction "LD [HL],[IY+~0]",0x14,0x61CE,3,1,16,0x040048	; 883
.instruction "LD [HL],[IX+L]",0x14,0x62CE,2,0	; 886
.instruction "LD [HL],[IY+L]",0x14,0x63CE,2,0	; 889

.instruction "LD [IX],A",0x11,0x60,1,0	; 281
.instruction "LD [IX],B",0x11,0x61,1,0	; 281
.instruction "LD [IX],L",0x11,0x62,1,0	; 281
.instruction "LD [IX],H",0x11,0x63,1,0	; 281
.instruction "LD [IX],[BR:~0]",0x11,0x64,2,1,8,0x040048	; 283
.instruction "LD [IX],[HL]",0x11,0x65,1,0	; 286
.instruction "LD [IX],[IX]",0x11,0x66,1,0	; 289
.instruction "LD [IX],[IY]",0x11,0x67,1,0	; 292
.instruction "LD [IX],~0",0x11,0xB6,2,1,8,0x020048	; 424
.instruction "LD [IX],[IX+~0]",0x14,0x68CE,3,1,16,0x040048	; 892
.instruction "LD [IX],[IY+~0]",0x14,0x69CE,3,1,16,0x040048	; 895
.instruction "LD [IX],[IX+L]",0x14,0x6ACE,2,0	; 898
.instruction "LD [IX],[IY+L]",0x14,0x6BCE,2,0	; 901

.instruction "LD [IY],A",0x11,0x70,1,0	; 309
.instruction "LD [IY],B",0x11,0x71,1,0	; 309
.instruction "LD [IY],L",0x11,0x72,1,0	; 309
.instruction "LD [IY],H",0x11,0x73,1,0	; 309
.instruction "LD [IY],[BR:~0]",0x11,0x74,2,1,8,0x040048	; 311
.instruction "LD [IY],[HL]",0x11,0x75,1,0	; 314
.instruction "LD [IY],[IX]",0x11,0x76,1,0	; 317
.instruction "LD [IY],[IY]",0x11,0x77,1,0	; 320
.instruction "LD [IY],~0",0x11,0xB7,2,1,8,0x020048	; 426
.instruction "LD [IY],[IX+~0]",0x14,0x78CE,3,1,16,0x040048	; 904
.instruction "LD [IY],[IY+~0]",0x14,0x79CE,3,1,16,0x040048	; 907
.instruction "LD [IY],[IX+L]",0x14,0x7ACE,2,0	; 910
.instruction "LD [IY],[IY+L]",0x14,0x7BCE,2,0	; 913

.instruction "LD [IX+~0],A",0x14,0x44CE,3,1,16,0x040048	; 872
.instruction "LD [IX+~0],B",0x14,0x4CCE,3,1,16,0x040048	; 872
.instruction "LD [IX+~0],L",0x14,0x54CE,3,1,16,0x040048	; 872
.instruction "LD [IX+~0],H",0x14,0x5CCE,3,1,16,0x040048	; 872

.instruction "LD [IY+~0],A",0x14,0x45CE,3,1,16,0x040048	; 874
.instruction "LD [IY+~0],B",0x14,0x4DCE,3,1,16,0x040048	; 874
.instruction "LD [IY+~0],L",0x14,0x55CE,3,1,16,0x040048	; 874
.instruction "LD [IY+~0],H",0x14,0x5DCE,3,1,16,0x040048	; 874

.instruction "LD [IX+L],A",0x14,0x46CE,2,0	; 876
.instruction "LD [IX+L],B",0x14,0x4ECE,2,0	; 876
.instruction "LD [IX+L],L",0x14,0x56CE,2,0	; 876
.instruction "LD [IX+L],H",0x14,0x5ECE,2,0	; 876

.instruction "LD [IY+L],A",0x14,0x47CE,2,0	; 878
.instruction "LD [IY+L],B",0x14,0x4FCE,2,0	; 878
.instruction "LD [IY+L],L",0x14,0x57CE,2,0	; 878
.instruction "LD [IY+L],H",0x14,0x5FCE,2,0	; 878

; Byte exchange
.instruction "EX A,B",0x11,0xCC,1,0	; 452
.instruction "EX A,[HL]",0x11,0xCD,1,0	; 456

; Nibble exchange
.instruction "SWAP A",0x11,0xF6,1,0	; 609
.instruction "SWAP [HL]",0x11,0xF7,1,0	; 611

; Rotate to left with carry
.instruction "RL A",0x14,0x90CE,2,0	; 958
.instruction "RL B",0x14,0x91CE,2,0	; 960
.instruction "RL [HL]",0x14,0x93CE,2,0	; 965
.instruction "RL [BR:~0]",0x14,0x92CE,3,1,16,0x040048	; 962

; Rotate to left without carry
.instruction "RLC A",0x14,0x94CE,2,0	; 968
.instruction "RLC B",0x14,0x95CE,2,0	; 970
.instruction "RLC [HL]",0x14,0x97CE,2,0	; 976
.instruction "RLC [BR:~0]",0x14,0x96CE,3,1,16,0x040048	; 972

; Rotate to right with carry
.instruction "RR A",0x14,0x98CE,2,0	; 980
.instruction "RR B",0x14,0x99CE,2,0	; 982
.instruction "RR [HL]",0x14,0x9BCE,2,0	; 988
.instruction "RR [BR:~0]",0x14,0x9ACE,3,1,16,0x040048	; 984

; Rotate to right without carry
.instruction "RRC A",0x14,0x9CCE,2,0	; 991
.instruction "RRC B",0x14,0x9DCE,2,0	; 993
.instruction "RRC [HL]",0x14,0x9FCE,2,0	; 999
.instruction "RRC [BR:~0]",0x14,0x9ECE,3,1,16,0x040048	; 995

; Arithmetic shift to left
.instruction "SLA A",0x14,0x80CE,2,0	; 916
.instruction "SLA B",0x14,0x81CE,2,0	; 918
.instruction "SLA [HL]",0x14,0x83CE,2,0	; 923
.instruction "SLA [BR:~0]",0x14,0x82CE,3,1,16,0x040048	; 920

; Logical shift to left
.instruction "SLL A",0x14,0x84CE,2,0	; 926
.instruction "SLL B",0x14,0x85CE,2,0	; 928
.instruction "SLL [HL]",0x14,0x87CE,2,0	; 933
.instruction "SLL [BR:~0]",0x14,0x86CE,3,1,16,0x040048	; 930

; Arithmetic shift to right
.instruction "SRA A",0x14,0x88CE,2,0	; 936
.instruction "SRA B",0x14,0x89CE,2,0	; 938
.instruction "SRA [HL]",0x14,0x8BCE,2,0	; 944
.instruction "SRA [BR:~0]",0x14,0x8ACE,3,1,16,0x040048	; 940

; Logical shift to right
.instruction "SRL A",0x14,0x8CCE,2,0	; 948
.instruction "SRL B",0x14,0x8DCE,2,0	; 950
.instruction "SRL [HL]",0x14,0x8FCE,2,0	; 955
.instruction "SRL [BR:~0]",0x14,0x8ECE,3,1,16,0x040048	; 952

; Pack / unpack / code extension
.instruction "PACK",0x11,0xDE,1,0	; 490
.instruction "UPCK",0x11,0xDF,1,0	; 492
.instruction "SEP",0x14,0xA8CE,2,0	; 1022

;; 16-bit instructions
; Addition
.instruction "ADD BA,~0",0x11,0xC0,3,1,8,0x020050	; 432
.instruction "ADD BA,BA",0x14,0x00CF,2,0	; 1196
.instruction "ADD BA,HL",0x14,0x01CF,2,0	; 1196
.instruction "ADD BA,IX",0x14,0x02CF,2,0	; 1196
.instruction "ADD BA,IY",0x14,0x03CF,2,0	; 1196
.instruction "ADD HL,~0",0x11,0xC1,3,1,8,0x020050	; 432
.instruction "ADD HL,BA",0x14,0x20CF,2,0	; 1207
.instruction "ADD HL,HL",0x14,0x21CF,2,0	; 1207
.instruction "ADD HL,IX",0x14,0x22CF,2,0	; 1207
.instruction "ADD HL,IY",0x14,0x23CF,2,0	; 1207
.instruction "ADD IX,~0",0x11,0xC2,3,1,8,0x020050	; 432
.instruction "ADD IX,BA",0x14,0x40CF,2,0	; 1218
.instruction "ADD IX,HL",0x14,0x41CF,2,0	; 1220
.instruction "ADD IY,~0",0x11,0xC3,3,1,8,0x020050	; 432
.instruction "ADD IY,BA",0x14,0x42CF,2,0	; 1222
.instruction "ADD IY,HL",0x14,0x43CF,2,0	; 1224
.instruction "ADD SP,BA",0x14,0x44CF,2,0	; 1226
.instruction "ADD SP,HL",0x14,0x45CF,2,0	; 1228
.instruction "ADD SP,~0",0x14,0x68CF,4,1,16,0x020050	; 1256

.instruction "ADC BA,BA",0x14,0x04CF,2,0	; 1198
.instruction "ADC BA,HL",0x14,0x05CF,2,0	; 1198
.instruction "ADC BA,IX",0x14,0x06CF,2,0	; 1198
.instruction "ADC BA,IY",0x14,0x07CF,2,0	; 1198
.instruction "ADC BA,~0",0x14,0x60CF,4,1,16,0x020050	; 1248
.instruction "ADC HL,BA",0x14,0x24CF,2,0	; 1209
.instruction "ADC HL,HL",0x14,0x25CF,2,0	; 1209
.instruction "ADC HL,IX",0x14,0x26CF,2,0	; 1209
.instruction "ADC HL,IY",0x14,0x27CF,2,0	; 1209
.instruction "ADC HL,~0",0x14,0x61CF,4,1,16,0x020050	; 1250

; Subtraction
.instruction "SUB BA,BA",0x14,0x08CF,2,0	; 1200
.instruction "SUB BA,HL",0x14,0x09CF,2,0	; 1200
.instruction "SUB BA,IX",0x14,0x0ACF,2,0	; 1200
.instruction "SUB BA,IY",0x14,0x0BCF,2,0	; 1200
.instruction "SUB BA,~0",0x11,0xD0,3,1,8,0x020050	; 460
.instruction "SUB HL,BA",0x14,0x28CF,2,0	; 1211
.instruction "SUB HL,HL",0x14,0x29CF,2,0	; 1211
.instruction "SUB HL,IX",0x14,0x2ACF,2,0	; 1211
.instruction "SUB HL,IY",0x14,0x2BCF,2,0	; 1211
.instruction "SUB HL,~0",0x11,0xD1,3,1,8,0x020050	; 460
.instruction "SUB IX,BA",0x14,0x48CF,2,0	; 1230
.instruction "SUB IX,HL",0x14,0x49CF,2,0	; 1232
.instruction "SUB IX,~0",0x11,0xD2,3,1,8,0x020050	; 460
.instruction "SUB IY,BA",0x14,0x4ACF,2,0	; 1234
.instruction "SUB IY,HL",0x14,0x4BCF,2,0	; 1236
.instruction "SUB IY,~0",0x11,0xD3,3,1,8,0x020050	; 460
.instruction "SUB SP,BA",0x14,0x4CCF,2,0	; 1238
.instruction "SUB SP,HL",0x14,0x4DCF,2,0	; 1240
.instruction "SUB SP,~0",0x14,0x6ACF,4,1,16,0x020050	; 1258

.instruction "SBC BA,BA",0x14,0x0CCF,2,0	; 1202
.instruction "SBC BA,HL",0x14,0x0DCF,2,0	; 1202
.instruction "SBC BA,IX",0x14,0x0ECF,2,0	; 1202
.instruction "SBC BA,IY",0x14,0x0FCF,2,0	; 1202
.instruction "SBC BA,~0",0x14,0x62CF,4,1,16,0x020050	; 1252
.instruction "SBC HL,BA",0x14,0x2CCF,2,0	; 1213
.instruction "SBC HL,HL",0x14,0x2DCF,2,0	; 1213
.instruction "SBC HL,IX",0x14,0x2ECF,2,0	; 1213
.instruction "SBC HL,IY",0x14,0x2FCF,2,0	; 1213
.instruction "SBC HL,~0",0x14,0x63CF,4,1,16,0x020050	; 1254

; Comparison
.instruction "CP BA,~0",0x11,0xD4,3,1,8,0x020050	; 462
.instruction "CP BA,BA",0x14,0x18CF,2,0	; 1204
.instruction "CP BA,HL",0x14,0x19CF,2,0	; 1204
.instruction "CP BA,IX",0x14,0x1ACF,2,0	; 1204
.instruction "CP BA,IY",0x14,0x1BCF,2,0	; 1204
.instruction "CP HL,~0",0x11,0xD5,3,1,8,0x020050	; 462
.instruction "CP HL,BA",0x14,0x38CF,2,0	; 1215
.instruction "CP HL,HL",0x14,0x39CF,2,0	; 1215
.instruction "CP HL,IX",0x14,0x3ACF,2,0	; 1215
.instruction "CP HL,IY",0x14,0x3BCF,2,0	; 1215
.instruction "CP IX,~0",0x11,0xD6,3,1,8,0x020050	; 462
.instruction "CP IY,~0",0x11,0xD7,3,1,8,0x020050	; 462
.instruction "CP SP,BA",0x14,0x5CCF,2,0	; 1242
.instruction "CP SP,HL",0x14,0x5DCF,2,0	; 1245
.instruction "CP SP,~0",0x14,0x6CCF,4,1,16,0x020050	; 1260

; Increment by 1
.instruction "INC SP",0x11,0x87,1,0	; 345
.instruction "INC BA",0x11,0x90,1,0	; 359
.instruction "INC HL",0x11,0x91,1,0	; 359
.instruction "INC IX",0x11,0x92,1,0	; 359
.instruction "INC IY",0x11,0x93,1,0	; 359

; Decrement by 1
.instruction "DEC BA",0x11,0x98,1,0	; 374
.instruction "DEC SP",0x11,0x8F,1,0	; 357
.instruction "DEC HL",0x11,0x99,1,0	; 374
.instruction "DEC IX",0x11,0x9A,1,0	; 374
.instruction "DEC IY",0x11,0x9B,1,0	; 374

; 16-bit transfer
.instruction "LD BA,[~0]",0x11,0xB8,3,1,8,0x040050	; 428
.instruction "LD BA,~0",0x11,0xC4,3,1,8,0x020050	; 434
.instruction "LD BA,[SP+~0]",0x14,0x70CF,3,1,16,0x040048	; 1265
.instruction "LD BA,[HL]",0x14,0xC0CF,2,0	; 1315
.instruction "LD BA,[IX]",0x14,0xD0CF,2,0	; 1319
.instruction "LD BA,[IY]",0x14,0xD8CF,2,0	; 1323
.instruction "LD BA,BA",0x14,0xE0CF,2,0	; 1327
.instruction "LD BA,HL",0x14,0xE1CF,2,0	; 1327
.instruction "LD BA,IX",0x14,0xE2CF,2,0	; 1327
.instruction "LD BA,IY",0x14,0xE3CF,2,0	; 1327
.instruction "LD BA,SP",0x14,0xF8CF,2,0	; 1335
.instruction "LD BA,PC",0x14,0xF9CF,2,0	; 1337

.instruction "LD HL,[~0]",0x11,0xB9,3,1,8,0x040050	; 428
.instruction "LD HL,~0",0x11,0xC5,3,1,8,0x020050	; 434
.instruction "LD HL,[SP+~0]",0x14,0x71CF,3,1,16,0x040048	; 1265
.instruction "LD HL,[HL]",0x14,0xC1CF,2,0	; 1315
.instruction "LD HL,[IX]",0x14,0xD1CF,2,0	; 1319
.instruction "LD HL,[IY]",0x14,0xD9CF,2,0	; 1323
.instruction "LD HL,BA",0x14,0xE4CF,2,0	; 1327
.instruction "LD HL,HL",0x14,0xE5CF,2,0	; 1327
.instruction "LD HL,IX",0x14,0xE6CF,2,0	; 1327
.instruction "LD HL,IY",0x14,0xE7CF,2,0	; 1327
.instruction "LD HL,SP",0x14,0xF4CF,2,0	; 1331
.instruction "LD HL,PC",0x14,0xF5CF,2,0	; 1333

.instruction "LD IX,[~0]",0x11,0xBA,3,1,8,0x040050	; 428
.instruction "LD IX,~0",0x11,0xC6,3,1,8,0x020050	; 434
.instruction "LD IX,[SP+~0]",0x14,0x72CF,3,1,16,0x040048	; 1265
.instruction "LD IX,[HL]",0x14,0xC2CF,2,0	; 1315
.instruction "LD IX,[IX]",0x14,0xD2CF,2,0	; 1319
.instruction "LD IX,[IY]",0x14,0xDACF,2,0	; 1323
.instruction "LD IX,BA",0x14,0xE8CF,2,0	; 1327
.instruction "LD IX,HL",0x14,0xE9CF,2,0	; 1327
.instruction "LD IX,IX",0x14,0xEACF,2,0	; 1327
.instruction "LD IX,IY",0x14,0xEBCF,2,0	; 1327
.instruction "LD IX,SP",0x14,0xFACF,2,0	; 1339

.instruction "LD IY,[~0]",0x11,0xBB,3,1,8,0x040050	; 428
.instruction "LD IY,~0",0x11,0xC7,3,1,8,0x020050	; 434
.instruction "LD IY,[SP+~0]",0x14,0x73CF,3,1,16,0x040048	; 1265
.instruction "LD IY,[HL]",0x14,0xC3CF,2,0	; 1315
.instruction "LD IY,[IX]",0x14,0xD3CF,2,0	; 1319
.instruction "LD IY,[IY]",0x14,0xDBCF,2,0	; 1323
.instruction "LD IY,BA",0x14,0xECCF,2,0	; 1327
.instruction "LD IY,HL",0x14,0xEDCF,2,0	; 1327
.instruction "LD IY,IX",0x14,0xEECF,2,0	; 1327
.instruction "LD IY,IY",0x14,0xEFCF,2,0	; 1327
.instruction "LD IY,SP",0x14,0xFECF,2,0	; 1341

.instruction "LD SP,~0",0x14,0x6ECF,4,1,16,0x020050	; 1263
.instruction "LD SP,[~0]",0x14,0x78CF,4,1,16,0x040050	; 1269
.instruction "LD SP,BA",0x14,0xF0CF,2,0	; 1329
.instruction "LD SP,HL",0x14,0xF1CF,2,0	; 1329
.instruction "LD SP,IX",0x14,0xF2CF,2,0	; 1329
.instruction "LD SP,IY",0x14,0xF3CF,2,0	; 1329

.instruction "LD [~0],BA",0x11,0xBC,3,1,8,0x040050	; 430
.instruction "LD [~0],HL",0x11,0xBD,3,1,8,0x040050	; 430
.instruction "LD [~0],IX",0x11,0xBE,3,1,8,0x040050	; 430
.instruction "LD [~0],IY",0x11,0xBF,3,1,8,0x040050	; 430
.instruction "LD [~0],SP",0x14,0x7CCF,4,1,16,0x040050	; 1272

.instruction "LD [HL],BA",0x14,0xC4CF,2,0	; 1317
.instruction "LD [HL],HL",0x14,0xC5CF,2,0	; 1317
.instruction "LD [HL],IX",0x14,0xC6CF,2,0	; 1317
.instruction "LD [HL],IY",0x14,0xC7CF,2,0	; 1317

.instruction "LD [IX],BA",0x14,0xD4CF,2,0	; 1321
.instruction "LD [IX],HL",0x14,0xD5CF,2,0	; 1321
.instruction "LD [IX],IX",0x14,0xD6CF,2,0	; 1321
.instruction "LD [IX],IY",0x14,0xD7CF,2,0	; 1321

.instruction "LD [IY],BA",0x14,0xDCCF,2,0	; 1325
.instruction "LD [IY],HL",0x14,0xDDCF,2,0	; 1325
.instruction "LD [IY],IX",0x14,0xDECF,2,0	; 1325
.instruction "LD [IY],IY",0x14,0xDFCF,2,0	; 1325

.instruction "LD [SP+~0],BA",0x14,0x74CF,3,1,16,0x040048	; 1267
.instruction "LD [SP+~0],HL",0x14,0x75CF,3,1,16,0x040048	; 1267
.instruction "LD [SP+~0],IX",0x14,0x76CF,3,1,16,0x040048	; 1267
.instruction "LD [SP+~0],IY",0x14,0x77CF,3,1,16,0x040048	; 1267

; Byte exchange
.instruction "EX BA,HL",0x11,0xC8,1,0	; 436
.instruction "EX BA,IX",0x11,0xC9,1,0	; 440
.instruction "EX BA,IY",0x11,0xCA,1,0	; 444
.instruction "EX BA,SP",0x11,0xCB,1,0	; 448

;; Stack control
.instruction "PUSH BA",0x11,0xA0,1,0	; 384
.instruction "PUSH HL",0x11,0xA1,1,0	; 384
.instruction "PUSH IX",0x11,0xA2,1,0	; 384
.instruction "PUSH IY",0x11,0xA3,1,0	; 384
.instruction "PUSH BR",0x11,0xA4,1,0	; 388
.instruction "PUSH EP",0x11,0xA5,1,0	; 391
.instruction "PUSH IP",0x11,0xA6,1,0	; 1678
.instruction "PUSH SC",0x11,0xA7,1,0	; 398
.instruction "PUSH A",0x14,0xB0CF,2,0	; 1275
.instruction "PUSH B",0x14,0xB1CF,2,0	; 1275
.instruction "PUSH L",0x14,0xB2CF,2,0	; 1275
.instruction "PUSH H",0x14,0xB3CF,2,0	; 1275
.instruction "PUSH ALL",0x14,0xB8CF,2,0	; 1281
.instruction "PUSH ALE",0x14,0xB9CF,2,0	; 1288

.instruction "POP BA",0x11,0xA8,1,0	; 401
.instruction "POP HL",0x11,0xA9,1,0	; 401
.instruction "POP IX",0x11,0xAA,1,0	; 401
.instruction "POP IY",0x11,0xAB,1,0	; 401
.instruction "POP BR",0x11,0xAC,1,0	; 405
.instruction "POP EP",0x11,0xAD,1,0	; 408
.instruction "POP IP",0x11,0xAE,1,0	; 1695
.instruction "POP SC",0x11,0xAF,1,0	; 415
.instruction "POP A",0x14,0xB4CF,2,0	; 1278
.instruction "POP B",0x14,0xB5CF,2,0	; 1278
.instruction "POP L",0x14,0xB6CF,2,0	; 1278
.instruction "POP H",0x14,0xB7CF,2,0	; 1278
.instruction "POP ALL",0x14,0xBCCF,2,0	; 1298
.instruction "POP ALE",0x14,0xBDCF,2,0	; 1305

;; Branching
.instruction "CAR ~0",0x13,0xF2,3,1,8,0x000190	; 1399
.instruction "CARS ~0",0x13,0xF0,2,1,8,0x000188	; 583
.instruction "CARL ~0",0x13,0xF2,3,1,8,0x000190	; 1399
.instruction "JR ~0",0x13,0xF3,3,1,8,0x000190	; 1405
.instruction "JRS ~0",0x13,0xF1,2,1,8,0x000188	; 589
.instruction "JRL ~0",0x13,0xF3,3,1,8,0x000190	; 1405

; Relative short jump
.instruction "JRS C,~0",0x13,0xE4,2,1,8,0x000188	; 523
.instruction "JRS NC,~0",0x13,0xE5,2,1,8,0x000188
.instruction "JRS Z,~0",0x13,0xE6,2,1,8,0x000188
.instruction "JRS NZ,~0",0x13,0xE7,2,1,8,0x000188

.instruction "JRS LT,~0",0x16,0xE0CE,3,1,16,0x000188	; 1104
.instruction "JRS LE,~0",0x16,0xE1CE,3,1,16,0x000188	; 1108
.instruction "JRS GT,~0",0x16,0xE2CE,3,1,16,0x000188	; 1112
.instruction "JRS GE,~0",0x16,0xE3CE,3,1,16,0x000188	; 1116
.instruction "JRS V,~0",0x16,0xE4CE,3,1,16,0x000188	; 1120
.instruction "JRS NV,~0",0x16,0xE5CE,3,1,16,0x000188	; 1124
.instruction "JRS P,~0",0x16,0xE6CE,3,1,16,0x000188	; 1128
.instruction "JRS M,~0",0x16,0xE7CE,3,1,16,0x000188	; 1132
.instruction "JRS F0,~0",0x16,0xE8CE,3,1,16,0x000188
.instruction "JRS F1,~0",0x16,0xE9CE,3,1,16,0x000188
.instruction "JRS F2,~0",0x16,0xEACE,3,1,16,0x000188
.instruction "JRS F3,~0",0x16,0xEBCE,3,1,16,0x000188
.instruction "JRS NF0,~0",0x16,0xECCE,3,1,16,0x000188
.instruction "JRS NF1,~0",0x16,0xEDCE,3,1,16,0x000188
.instruction "JRS NF2,~0",0x16,0xEECE,3,1,16,0x000188
.instruction "JRS NF3,~0",0x16,0xEFCE,3,1,16,0x000188

; Relative long jump
.instruction "JRL C,~0",0x13,0xEC,3,1,8,0x000190	; 1383
.instruction "JRL NC,~0",0x13,0xED,3,1,8,0x000190	; 1387
.instruction "JRL Z,~0",0x13,0xEE,3,1,8,0x000190	; 1391
.instruction "JRL NZ,~0",0x13,0xEF,3,1,8,0x000190	; 1395

; Indirect jump
.instruction "JP HL",0x11,0xF4,1,0	; 601
.instruction "JP [~0]",0x11,0xFD,2,1,9,0x080047	; 640

; Loop
.instruction "DJR NZ,~0",0x13,0xF5,2,1,8,0x000188	; 604

; Relative short call
.instruction "CARS C,~0",0x13,0xE0,2,1,8,0x000188	; 495
.instruction "CARS NC,~0",0x13,0xE1,2,1,8,0x000188	; 502
.instruction "CARS Z,~0",0x13,0xE2,2,1,8,0x000188	; 509
.instruction "CARS NZ,~0",0x13,0xE3,2,1,8,0x000188	; 516
.instruction "CARS LT,~0",0x16,0xF0CE,3,1,16,0x000188	; 1136
.instruction "CARS LE,~0",0x16,0xF1CE,3,1,16,0x000188	; 1143
.instruction "CARS GT,~0",0x16,0xF2CE,3,1,16,0x000188	; 1150
.instruction "CARS GE,~0",0x16,0xF3CE,3,1,16,0x000188	; 1157
.instruction "CARS V,~0",0x16,0xF4CE,3,1,16,0x000188	; 1164
.instruction "CARS NV,~0",0x16,0xF5CE,3,1,16,0x000188	; 1171
.instruction "CARS P,~0",0x16,0xF6CE,3,1,16,0x000188	; 1178
.instruction "CARS M,~0",0x16,0xF7CE,3,1,16,0x000188	; 1185
.instruction "CARS F0,~0",0x16,0xF8CE,3,1,16,0x000188
.instruction "CARS F1,~0",0x16,0xF9CE,3,1,16,0x000188
.instruction "CARS F2,~0",0x16,0xFACE,3,1,16,0x000188
.instruction "CARS F3,~0",0x16,0xFBCE,3,1,16,0x000188
.instruction "CARS NF0,~0",0x16,0xFCCE,3,1,16,0x000188
.instruction "CARS NF1,~0",0x16,0xFDCE,3,1,16,0x000188
.instruction "CARS NF2,~0",0x16,0xFECE,3,1,16,0x000188
.instruction "CARS NF3,~0",0x16,0xFFCE,3,1,16,0x000188

; Relative long call
.instruction "CARL C,~0",0x13,0xE8,3,1,8,0x000190	; 1355
.instruction "CARL NC,~0",0x13,0xE9,3,1,8,0x000190	; 1362
.instruction "CARL Z,~0",0x13,0xEA,3,1,8,0x000190	; 1369
.instruction "CARL NZ,~0",0x13,0xEB,3,1,8,0x000190	; 1376

; Indirect call
.instruction "CALL [~0]",0x11,0xFB,3,1,8,0x040050	; 628

; Return / exception processing return / return and skip 
.instruction "RET",0x11,0xF8,1,0	; 615
.instruction "RETE",0x11,0xF9,1,0	; 619
.instruction "RETS",0x11,0xFA,1,0	; 624

; Software interrupt
.instruction "INT [~0]",0x11,0xFC,2,1,9,0x080047	; 1785

;; System Control
.instruction "NOP",0x11,0xFF,1,0	; 646
.instruction "HALT",0x14,0xAECE,2,0	; 1025
.instruction "SLP",0x14,0xAFCE,2,0	; 1027
