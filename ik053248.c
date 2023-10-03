#define FILE void
#include "defines.h"

/* got the defines from https://stackoverflow.com/questions/18244726/why-doesnt-c-have-binary-literals */

struct instruction g_instructions_table[] = {
  { "ABX", 0xb0, 0, 0, 0 },

  { "ADCA #x", 0x18, 1, 0, 0 },
  { "ADCA,X", 0x1a, 9, 0, 0x26 },
  { "ADCA,Y", 0x1a, 9, 0, 0x36 },
  { "ADCA,U", 0x1a, 9, 0, 0x56 },
  { "ADCA,S", 0x1a, 9, 0, 0x66 },
  { "ADCA A,X", 0x1a, 9, 0, 0xa0 },
  { "ADCA A,Y", 0x1a, 9, 0, 0xb0 },
  { "ADCA A,U", 0x1a, 9, 0, 0xd0 },
  { "ADCA A,S", 0x1a, 9, 0, 0xe0 },
  { "ADCA B,X", 0x1a, 9, 0, 0xa1 },
  { "ADCA B,Y", 0x1a, 9, 0, 0xb1 },
  { "ADCA B,U", 0x1a, 9, 0, 0xd1 },
  { "ADCA B,S", 0x1a, 9, 0, 0xe1 },
  { "ADCA D,X", 0x1a, 9, 0, 0xa7 },
  { "ADCA D,Y", 0x1a, 9, 0, 0xb7 },
  { "ADCA D,U", 0x1a, 9, 0, 0xd7 },
  { "ADCA D,S", 0x1a, 9, 0, 0xe8 },
  { "ADCA,X+", 0x1a, 9, 0, 0x20 },
  { "ADCA,Y+", 0x1a, 9, 0, 0x30 },
  { "ADCA,U+", 0x1a, 9, 0, 0x50 },
  { "ADCA,S+", 0x1a, 9, 0, 0x60 },
  { "ADCA,X++", 0x1a, 9, 0, 0x21 },
  { "ADCA,Y++", 0x1a, 9, 0, 0x31 },
  { "ADCA,U++", 0x1a, 9, 0, 0x51 },
  { "ADCA,S++", 0x1a, 9, 0, 0x61 },
  { "ADCA,-X", 0x1a, 9, 0, 0x22 },
  { "ADCA,-Y", 0x1a, 9, 0, 0x32 },
  { "ADCA,-U", 0x1a, 9, 0, 0x52 },
  { "ADCA,-S", 0x1a, 9, 0, 0x62 },
  { "ADCA,--X", 0x1a, 9, 0, 0x23 },
  { "ADCA,--Y", 0x1a, 9, 0, 0x33 },
  { "ADCA,--U", 0x1a, 9, 0, 0x53 },
  { "ADCA,--S", 0x1a, 9, 0, 0x63 },
  { "ADCA (,X)", 0x1a, 9, 0, 0x2e },
  { "ADCA (,Y)", 0x1a, 9, 0, 0x3e },
  { "ADCA (,U)", 0x1a, 9, 0, 0x5e },
  { "ADCA (,S)", 0x1a, 9, 0, 0x6e },
  { "ADCA (A,X)", 0x1a, 9, 0, 0xa8 },
  { "ADCA (A,Y)", 0x1a, 9, 0, 0xb8 },
  { "ADCA (A,U)", 0x1a, 9, 0, 0xd8 },
  { "ADCA (A,S)", 0x1a, 9, 0, 0xe8 },
  { "ADCA (B,X)", 0x1a, 9, 0, 0xa9 },
  { "ADCA (B,Y)", 0x1a, 9, 0, 0xb9 },
  { "ADCA (B,U)", 0x1a, 9, 0, 0xd9 },
  { "ADCA (B,S)", 0x1a, 9, 0, 0xe9 },
  { "ADCA (D,X)", 0x1a, 9, 0, 0xaf },
  { "ADCA (D,Y)", 0x1a, 9, 0, 0xbf },
  { "ADCA (D,U)", 0x1a, 9, 0, 0xdf },
  { "ADCA (D,S)", 0x1a, 9, 0, 0xef },
  { "ADCA (,X++)", 0x1a, 9, 0, 0x29 },
  { "ADCA (,Y++)", 0x1a, 9, 0, 0x39 },
  { "ADCA (,U++)", 0x1a, 9, 0, 0x59 },
  { "ADCA (,S++)", 0x1a, 9, 0, 0x69 },
  { "ADCA (,--X)", 0x1a, 9, 0, 0x2b },
  { "ADCA (,--Y)", 0x1a, 9, 0, 0x3b },
  { "ADCA (,--U)", 0x1a, 9, 0, 0x5b },
  { "ADCA (,--S)", 0x1a, 9, 0, 0x6b },
  { "ADCA (x,X)", 0x1a, 7, 1, 0x2c }, /* 8-bit offset */
  { "ADCA (x,Y)", 0x1a, 7, 1, 0x3c }, /* 8-bit offset */
  { "ADCA (x,U)", 0x1a, 7, 1, 0x5c }, /* 8-bit offset */
  { "ADCA (x,S)", 0x1a, 7, 1, 0x6c }, /* 8-bit offset */
  { "ADCA (?,X)", 0x1a, 8, 0, 0x2d }, /* 16-bit offset */
  { "ADCA (?,Y)", 0x1a, 8, 0, 0x3d }, /* 16-bit offset */
  { "ADCA (?,U)", 0x1a, 8, 0, 0x5d }, /* 16-bit offset */
  { "ADCA (?,S)", 0x1a, 8, 0, 0x6d }, /* 16-bit offset */
  { "ADCA (x,PCR)", 0x1a, 7, 1, 0x7c }, /* 8-bit offset */
  { "ADCA (?,PCR)", 0x1a, 8, 0, 0x7d }, /* 16-bit offset */
  { "ADCA (?)", 0x1a, 8, 0, 0x0f }, /* 16-bit offset */
  { "ADCA s,X", 0x1a, 6, 1, 0x26 }, /* 5-bit offset */
  { "ADCA s,Y", 0x1a, 6, 1, 0x36 }, /* 5-bit offset */
  { "ADCA s,U", 0x1a, 6, 1, 0x56 }, /* 5-bit offset */
  { "ADCA s,S", 0x1a, 6, 1, 0x66 }, /* 5-bit offset */
  { "ADCA x,X", 0x1a, 7, 1, 0x24 }, /* 8-bit offset */
  { "ADCA x,Y", 0x1a, 7, 1, 0x34 }, /* 8-bit offset */
  { "ADCA x,U", 0x1a, 7, 1, 0x54 }, /* 8-bit offset */
  { "ADCA x,S", 0x1a, 7, 1, 0x64 }, /* 8-bit offset */
  { "ADCA ?,X", 0x1a, 8, 0, 0x25 }, /* 16-bit offset */
  { "ADCA ?,Y", 0x1a, 8, 0, 0x35 }, /* 16-bit offset */
  { "ADCA ?,U", 0x1a, 8, 0, 0x55 }, /* 16-bit offset */
  { "ADCA ?,S", 0x1a, 8, 0, 0x65 }, /* 16-bit offset */
  { "ADCA x,PCR", 0x1a, 7, 1, 0x74 }, /* 8-bit offset */
  { "ADCA ?,PCR", 0x1a, 8, 0, 0x75 }, /* 16-bit offset */
  { "ADCA x", 0x1a, 4, 1, 0xc4 },
  { "ADCA ?", 0x1a, 2, 0, 0xcc },

  { "ADCB #x", 0x19, 1, 0, 0 },
  { "ADCB,X", 0x1b, 9, 0, 0x26 },
  { "ADCB,Y", 0x1b, 9, 0, 0x36 },
  { "ADCB,U", 0x1b, 9, 0, 0x56 },
  { "ADCB,S", 0x1b, 9, 0, 0x66 }, /* 0xE4 */
  { "ADCB A,X", 0x1b, 9, 0, 0xa0 },
  { "ADCB A,Y", 0x1b, 9, 0, 0xb0 },
  { "ADCB A,U", 0x1b, 9, 0, 0xd0 },
  { "ADCB A,S", 0x1b, 9, 0, 0xe0 }, /* 0xE6 */
  { "ADCB B,X", 0x1b, 9, 0, 0xa1 },
  { "ADCB B,Y", 0x1b, 9, 0, 0xb1 },
  { "ADCB B,U", 0x1b, 9, 0, 0xd1 },
  { "ADCB B,S", 0x1b, 9, 0, 0xe1 }, /* 0xE5 */
  { "ADCB D,X", 0x1b, 9, 0, 0xa7 },
  { "ADCB D,Y", 0x1b, 9, 0, 0xb7 },
  { "ADCB D,U", 0x1b, 9, 0, 0xd7 },
  { "ADCB D,S", 0x1b, 9, 0, 0xe8 },
  { "ADCB,X+", 0x1b, 9, 0, 0x20 },
  { "ADCB,Y+", 0x1b, 9, 0, 0x30 },
  { "ADCB,U+", 0x1b, 9, 0, 0x50 },
  { "ADCB,S+", 0x1b, 9, 0, 0x60 }, /* 0xE0 */
  { "ADCB,X++", 0x1b, 9, 0, 0x21 },
  { "ADCB,Y++", 0x1b, 9, 0, 0x31 },
  { "ADCB,U++", 0x1b, 9, 0, 0x51 },
  { "ADCB,S++", 0x1b, 9, 0, 0x61 }, /* 0xE1 */
  { "ADCB,-X", 0x1b, 9, 0, 0x22 },
  { "ADCB,-Y", 0x1b, 9, 0, 0x32 },
  { "ADCB,-U", 0x1b, 9, 0, 0x52 },
  { "ADCB,-S", 0x1b, 9, 0, 0x62 }, /* 0xE2 */
  { "ADCB,--X", 0x1b, 9, 0, 0x23 },
  { "ADCB,--Y", 0x1b, 9, 0, 0x33 },
  { "ADCB,--U", 0x1b, 9, 0, 0x53 },
  { "ADCB,--S", 0x1b, 9, 0, 0x63 }, /* 0xE3 */
  { "ADCB (,X)", 0x1b, 9, 0, 0x2e },
  { "ADCB (,Y)", 0x1b, 9, 0, 0x3e },
  { "ADCB (,U)", 0x1b, 9, 0, 0x5e },
  { "ADCB (,S)", 0x1b, 9, 0, 0x6e }, /* 0xF4 */
  { "ADCB (A,X)", 0x1b, 9, 0, 0xa8 },
  { "ADCB (A,Y)", 0x1b, 9, 0, 0xb8 },
  { "ADCB (A,U)", 0x1b, 9, 0, 0xd8 },
  { "ADCB (A,S)", 0x1b, 9, 0, 0xe8 }, /* 0xF6 */
  { "ADCB (B,X)", 0x1b, 9, 0, 0xa9 },
  { "ADCB (B,Y)", 0x1b, 9, 0, 0xb9 },
  { "ADCB (B,U)", 0x1b, 9, 0, 0xd9 },
  { "ADCB (B,S)", 0x1b, 9, 0, 0xe9 }, /* 0xF5 */
  { "ADCB (D,X)", 0x1b, 9, 0, 0xaf },
  { "ADCB (D,Y)", 0x1b, 9, 0, 0xbf },
  { "ADCB (D,U)", 0x1b, 9, 0, 0xdf },
  { "ADCB (D,S)", 0x1b, 9, 0, 0xef }, /* 0xFB */
  { "ADCB (,X++)", 0x1b, 9, 0, 0x29 },
  { "ADCB (,Y++)", 0x1b, 9, 0, 0x39 },
  { "ADCB (,U++)", 0x1b, 9, 0, 0x59 },
  { "ADCB (,S++)", 0x1b, 9, 0, 0x69 }, /* 0xF1 */
  { "ADCB (,--X)", 0x1b, 9, 0, 0x2b },
  { "ADCB (,--Y)", 0x1b, 9, 0, 0x3b },
  { "ADCB (,--U)", 0x1b, 9, 0, 0x5b },
  { "ADCB (,--S)", 0x1b, 9, 0, 0x6b }, /* 0xF3 */
  { "ADCB (x,X)", 0x1b, 7, 1, 0x2c }, /* 8-bit offset */
  { "ADCB (x,Y)", 0x1b, 7, 1, 0x3c }, /* 8-bit offset */
  { "ADCB (x,U)", 0x1b, 7, 1, 0x5c }, /* 8-bit offset */
  { "ADCB (x,S)", 0x1b, 7, 1, 0x6c }, /* 8-bit offset */ /* 0xF8 */
  { "ADCB (?,X)", 0x1b, 8, 0, 0x2d }, /* 16-bit offset */
  { "ADCB (?,Y)", 0x1b, 8, 0, 0x3d }, /* 16-bit offset */
  { "ADCB (?,U)", 0x1b, 8, 0, 0x5d }, /* 16-bit offset */
  { "ADCB (?,S)", 0x1b, 8, 0, 0x6d }, /* 16-bit offset */ /* 0xF9 */
  { "ADCB (x,PCR)", 0x1b, 7, 1, 0x7c }, /* 8-bit offset */ /* 0x9C */
  { "ADCB (?,PCR)", 0x1b, 8, 0, 0x7d }, /* 16-bit offset */ /* 0x9D */
  { "ADCB (?)", 0x1b, 8, 0, 0x0f }, /* 16-bit offset */ /* 0x9F */
  { "ADCB s,X", 0x1b, 6, 1, 0x26 }, /* 5-bit offset */
  { "ADCB s,Y", 0x1b, 6, 1, 0x36 }, /* 5-bit offset */
  { "ADCB s,U", 0x1b, 6, 1, 0x56 }, /* 5-bit offset */
  { "ADCB s,S", 0x1b, 6, 1, 0x66 }, /* 5-bit offset */ /* 0x60 */
  { "ADCB x,X", 0x1b, 7, 1, 0x24 }, /* 8-bit offset */
  { "ADCB x,Y", 0x1b, 7, 1, 0x34 }, /* 8-bit offset */
  { "ADCB x,U", 0x1b, 7, 1, 0x54 }, /* 8-bit offset */
  { "ADCB x,S", 0x1b, 7, 1, 0x64 }, /* 8-bit offset */ /* 0xE8 */
  { "ADCB ?,X", 0x1b, 8, 0, 0x25 }, /* 16-bit offset */
  { "ADCB ?,Y", 0x1b, 8, 0, 0x35 }, /* 16-bit offset */
  { "ADCB ?,U", 0x1b, 8, 0, 0x55 }, /* 16-bit offset */
  { "ADCB ?,S", 0x1b, 8, 0, 0x65 }, /* 16-bit offset */ /* 0x1b */
  { "ADCB x,PCR", 0x1b, 7, 1, 0x74 }, /* 8-bit offset */ /* 0x8C */
  { "ADCB ?,PCR", 0x1b, 8, 0, 0x75 }, /* 16-bit offset */ /* 0x8D */
  { "ADCB x", 0x1b, 2, 1, 0x07 },
  { "ADCB ?", 0x1b, 2, 0, 0x07 },

  { "ADDA #x", 0x14, 1, 0, 0 },
  { "ADDA,X", 0x16, 9, 0, 0x26 },
  { "ADDA,Y", 0x16, 9, 0, 0x36 },
  { "ADDA,U", 0x16, 9, 0, 0x56 },
  { "ADDA,S", 0x16, 9, 0, 0x66 },
  { "ADDA A,X", 0x16, 9, 0, 0xa0 },
  { "ADDA A,Y", 0x16, 9, 0, 0xb0 },
  { "ADDA A,U", 0x16, 9, 0, 0xd0 },
  { "ADDA A,S", 0x16, 9, 0, 0xe0 },
  { "ADDA B,X", 0x16, 9, 0, 0xa1 },
  { "ADDA B,Y", 0x16, 9, 0, 0xb1 },
  { "ADDA B,U", 0x16, 9, 0, 0xd1 },
  { "ADDA B,S", 0x16, 9, 0, 0xe1 },
  { "ADDA D,X", 0x16, 9, 0, 0xa7 },
  { "ADDA D,Y", 0x16, 9, 0, 0xb7 },
  { "ADDA D,U", 0x16, 9, 0, 0xd7 },
  { "ADDA D,S", 0x16, 9, 0, 0xe8 },
  { "ADDA,X+", 0x16, 9, 0, 0x20 },
  { "ADDA,Y+", 0x16, 9, 0, 0x30 },
  { "ADDA,U+", 0x16, 9, 0, 0x50 },
  { "ADDA,S+", 0x16, 9, 0, 0x60 },
  { "ADDA,X++", 0x16, 9, 0, 0x21 },
  { "ADDA,Y++", 0x16, 9, 0, 0x31 },
  { "ADDA,U++", 0x16, 9, 0, 0x51 },
  { "ADDA,S++", 0x16, 9, 0, 0x61 },
  { "ADDA,-X", 0x16, 9, 0, 0x22 },
  { "ADDA,-Y", 0x16, 9, 0, 0x32 },
  { "ADDA,-U", 0x16, 9, 0, 0x52 },
  { "ADDA,-S", 0x16, 9, 0, 0x62 },
  { "ADDA,--X", 0x16, 9, 0, 0x23 },
  { "ADDA,--Y", 0x16, 9, 0, 0x33 },
  { "ADDA,--U", 0x16, 9, 0, 0x53 },
  { "ADDA,--S", 0x16, 9, 0, 0x63 },
  { "ADDA (,X)", 0x16, 9, 0, 0x2e },
  { "ADDA (,Y)", 0x16, 9, 0, 0x3e },
  { "ADDA (,U)", 0x16, 9, 0, 0x5e },
  { "ADDA (,S)", 0x16, 9, 0, 0x6e },
  { "ADDA (A,X)", 0x16, 9, 0, 0xa8 },
  { "ADDA (A,Y)", 0x16, 9, 0, 0xb8 },
  { "ADDA (A,U)", 0x16, 9, 0, 0xd8 },
  { "ADDA (A,S)", 0x16, 9, 0, 0xe8 },
  { "ADDA (B,X)", 0x16, 9, 0, 0xa9 },
  { "ADDA (B,Y)", 0x16, 9, 0, 0xb9 },
  { "ADDA (B,U)", 0x16, 9, 0, 0xd9 },
  { "ADDA (B,S)", 0x16, 9, 0, 0xe9 },
  { "ADDA (D,X)", 0x16, 9, 0, 0xaf },
  { "ADDA (D,Y)", 0x16, 9, 0, 0xbf },
  { "ADDA (D,U)", 0x16, 9, 0, 0xdf },
  { "ADDA (D,S)", 0x16, 9, 0, 0xef },
  { "ADDA (,X++)", 0x16, 9, 0, 0x29 },
  { "ADDA (,Y++)", 0x16, 9, 0, 0x39 },
  { "ADDA (,U++)", 0x16, 9, 0, 0x59 },
  { "ADDA (,S++)", 0x16, 9, 0, 0x69 },
  { "ADDA (,--X)", 0x16, 9, 0, 0x2b },
  { "ADDA (,--Y)", 0x16, 9, 0, 0x3b },
  { "ADDA (,--U)", 0x16, 9, 0, 0x5b },
  { "ADDA (,--S)", 0x16, 9, 0, 0x6b },
  { "ADDA (x,X)", 0x16, 7, 1, 0x2c }, /* 8-bit offset */
  { "ADDA (x,Y)", 0x16, 7, 1, 0x3c }, /* 8-bit offset */
  { "ADDA (x,U)", 0x16, 7, 1, 0x5c }, /* 8-bit offset */
  { "ADDA (x,S)", 0x16, 7, 1, 0x6c }, /* 8-bit offset */
  { "ADDA (?,X)", 0x16, 8, 0, 0x2d }, /* 16-bit offset */
  { "ADDA (?,Y)", 0x16, 8, 0, 0x3d }, /* 16-bit offset */
  { "ADDA (?,U)", 0x16, 8, 0, 0x5d }, /* 16-bit offset */
  { "ADDA (?,S)", 0x16, 8, 0, 0x6d }, /* 16-bit offset */
  { "ADDA (x,PCR)", 0x16, 7, 1, 0x7c }, /* 8-bit offset */
  { "ADDA (?,PCR)", 0x16, 8, 0, 0x7d }, /* 16-bit offset */
  { "ADDA (?)", 0x16, 8, 0, 0x0f }, /* 16-bit offset */
  { "ADDA s,X", 0x16, 6, 1, 0x26 }, /* 5-bit offset */
  { "ADDA s,Y", 0x16, 6, 1, 0x36 }, /* 5-bit offset */
  { "ADDA s,U", 0x16, 6, 1, 0x56 }, /* 5-bit offset */
  { "ADDA s,S", 0x16, 6, 1, 0x66 }, /* 5-bit offset */
  { "ADDA x,X", 0x16, 7, 1, 0x24 }, /* 8-bit offset */
  { "ADDA x,Y", 0x16, 7, 1, 0x34 }, /* 8-bit offset */
  { "ADDA x,U", 0x16, 7, 1, 0x54 }, /* 8-bit offset */
  { "ADDA x,S", 0x16, 7, 1, 0x64 }, /* 8-bit offset */
  { "ADDA ?,X", 0x16, 8, 0, 0x25 }, /* 16-bit offset */
  { "ADDA ?,Y", 0x16, 8, 0, 0x35 }, /* 16-bit offset */
  { "ADDA ?,U", 0x16, 8, 0, 0x55 }, /* 16-bit offset */
  { "ADDA ?,S", 0x16, 8, 0, 0x65 }, /* 16-bit offset */
  { "ADDA x,PCR", 0x16, 7, 1, 0x74 }, /* 8-bit offset */
  { "ADDA ?,PCR", 0x16, 8, 0, 0x75 }, /* 16-bit offset */
  { "ADDA x", 0x16, 2, 1, 0x07 },
  { "ADDA ?", 0x16, 2, 0, 0x07 },

  { "ADDB #x", 0x15, 1, 0, 0 },
  { "ADDB,X", 0x17, 9, 0, 0x26 },
  { "ADDB,Y", 0x17, 9, 0, 0x36 },
  { "ADDB,U", 0x17, 9, 0, 0x56 },
  { "ADDB,S", 0x17, 9, 0, 0x66 },
  { "ADDB A,X", 0x17, 9, 0, 0xa0 },
  { "ADDB A,Y", 0x17, 9, 0, 0xb0 },
  { "ADDB A,U", 0x17, 9, 0, 0xd0 },
  { "ADDB A,S", 0x17, 9, 0, 0xe0 },
  { "ADDB B,X", 0x17, 9, 0, 0xa1 },
  { "ADDB B,Y", 0x17, 9, 0, 0xb1 },
  { "ADDB B,U", 0x17, 9, 0, 0xd1 },
  { "ADDB B,S", 0x17, 9, 0, 0xe1 },
  { "ADDB D,X", 0x17, 9, 0, 0xa7 },
  { "ADDB D,Y", 0x17, 9, 0, 0xb7 },
  { "ADDB D,U", 0x17, 9, 0, 0xd7 },
  { "ADDB D,S", 0x17, 9, 0, 0xe8 },
  { "ADDB,X+", 0x17, 9, 0, 0x20 },
  { "ADDB,Y+", 0x17, 9, 0, 0x30 },
  { "ADDB,U+", 0x17, 9, 0, 0x50 },
  { "ADDB,S+", 0x17, 9, 0, 0x60 },
  { "ADDB,X++", 0x17, 9, 0, 0x21 },
  { "ADDB,Y++", 0x17, 9, 0, 0x31 },
  { "ADDB,U++", 0x17, 9, 0, 0x51 },
  { "ADDB,S++", 0x17, 9, 0, 0x61 },
  { "ADDB,-X", 0x17, 9, 0, 0x22 },
  { "ADDB,-Y", 0x17, 9, 0, 0x32 },
  { "ADDB,-U", 0x17, 9, 0, 0x52 },
  { "ADDB,-S", 0x17, 9, 0, 0x62 },
  { "ADDB,--X", 0x17, 9, 0, 0x23 },
  { "ADDB,--Y", 0x17, 9, 0, 0x33 },
  { "ADDB,--U", 0x17, 9, 0, 0x53 },
  { "ADDB,--S", 0x17, 9, 0, 0x63 },
  { "ADDB (,X)", 0x17, 9, 0, 0x2e },
  { "ADDB (,Y)", 0x17, 9, 0, 0x3e },
  { "ADDB (,U)", 0x17, 9, 0, 0x5e },
  { "ADDB (,S)", 0x17, 9, 0, 0x6e },
  { "ADDB (A,X)", 0x17, 9, 0, 0xa8 },
  { "ADDB (A,Y)", 0x17, 9, 0, 0xb8 },
  { "ADDB (A,U)", 0x17, 9, 0, 0xd8 },
  { "ADDB (A,S)", 0x17, 9, 0, 0xe8 },
  { "ADDB (B,X)", 0x17, 9, 0, 0xa9 },
  { "ADDB (B,Y)", 0x17, 9, 0, 0xb9 },
  { "ADDB (B,U)", 0x17, 9, 0, 0xd9 },
  { "ADDB (B,S)", 0x17, 9, 0, 0xe9 },
  { "ADDB (D,X)", 0x17, 9, 0, 0xaf },
  { "ADDB (D,Y)", 0x17, 9, 0, 0xbf },
  { "ADDB (D,U)", 0x17, 9, 0, 0xdf },
  { "ADDB (D,S)", 0x17, 9, 0, 0xef },
  { "ADDB (,X++)", 0x17, 9, 0, 0x29 },
  { "ADDB (,Y++)", 0x17, 9, 0, 0x39 },
  { "ADDB (,U++)", 0x17, 9, 0, 0x59 },
  { "ADDB (,S++)", 0x17, 9, 0, 0x69 },
  { "ADDB (,--X)", 0x17, 9, 0, 0x2b },
  { "ADDB (,--Y)", 0x17, 9, 0, 0x3b },
  { "ADDB (,--U)", 0x17, 9, 0, 0x5b },
  { "ADDB (,--S)", 0x17, 9, 0, 0x6b },
  { "ADDB (x,X)", 0x17, 7, 1, 0x2c }, /* 8-bit offset */
  { "ADDB (x,Y)", 0x17, 7, 1, 0x3c }, /* 8-bit offset */
  { "ADDB (x,U)", 0x17, 7, 1, 0x5c }, /* 8-bit offset */
  { "ADDB (x,S)", 0x17, 7, 1, 0x6c }, /* 8-bit offset */
  { "ADDB (?,X)", 0x17, 8, 0, 0x2d }, /* 16-bit offset */
  { "ADDB (?,Y)", 0x17, 8, 0, 0x3d }, /* 16-bit offset */
  { "ADDB (?,U)", 0x17, 8, 0, 0x5d }, /* 16-bit offset */
  { "ADDB (?,S)", 0x17, 8, 0, 0x6d }, /* 16-bit offset */
  { "ADDB (x,PCR)", 0x17, 7, 1, 0x7c }, /* 8-bit offset */
  { "ADDB (?,PCR)", 0x17, 8, 0, 0x7d }, /* 16-bit offset */
  { "ADDB (?)", 0x17, 8, 0, 0x0f }, /* 16-bit offset */
  { "ADDB s,X", 0x17, 6, 1, 0x26 }, /* 5-bit offset */
  { "ADDB s,Y", 0x17, 6, 1, 0x36 }, /* 5-bit offset */
  { "ADDB s,U", 0x17, 6, 1, 0x56 }, /* 5-bit offset */
  { "ADDB s,S", 0x17, 6, 1, 0x66 }, /* 5-bit offset */
  { "ADDB x,X", 0x17, 7, 1, 0x24 }, /* 8-bit offset */
  { "ADDB x,Y", 0x17, 7, 1, 0x34 }, /* 8-bit offset */
  { "ADDB x,U", 0x17, 7, 1, 0x54 }, /* 8-bit offset */
  { "ADDB x,S", 0x17, 7, 1, 0x64 }, /* 8-bit offset */
  { "ADDB ?,X", 0x17, 8, 0, 0x25 }, /* 16-bit offset */
  { "ADDB ?,Y", 0x17, 8, 0, 0x35 }, /* 16-bit offset */
  { "ADDB ?,U", 0x17, 8, 0, 0x55 }, /* 16-bit offset */
  { "ADDB ?,S", 0x17, 8, 0, 0x65 }, /* 16-bit offset */
  { "ADDB x,PCR", 0x17, 7, 1, 0x74 }, /* 8-bit offset */
  { "ADDB ?,PCR", 0x17, 8, 0, 0x75 }, /* 16-bit offset */
  { "ADDB x", 0x17, 2, 1, 0x07 },
  { "ADDB ?", 0x17, 2, 0, 0x07 },

  { "ADDD #x", 0x54, 1, 0, 0 },
  { "ADDD,X", 0x55, 9, 0, 0x26 },
  { "ADDD,Y", 0x55, 9, 0, 0x36 },
  { "ADDD,U", 0x55, 9, 0, 0x56 },
  { "ADDD,S", 0x55, 9, 0, 0x66 },
  { "ADDD A,X", 0x55, 9, 0, 0xa0 },
  { "ADDD A,Y", 0x55, 9, 0, 0xb0 },
  { "ADDD A,U", 0x55, 9, 0, 0xd0 },
  { "ADDD A,S", 0x55, 9, 0, 0xe0 },
  { "ADDD B,X", 0x55, 9, 0, 0xa1 },
  { "ADDD B,Y", 0x55, 9, 0, 0xb1 },
  { "ADDD B,U", 0x55, 9, 0, 0xd1 },
  { "ADDD B,S", 0x55, 9, 0, 0xe1 },
  { "ADDD D,X", 0x55, 9, 0, 0xa7 },
  { "ADDD D,Y", 0x55, 9, 0, 0xb7 },
  { "ADDD D,U", 0x55, 9, 0, 0xd7 },
  { "ADDD D,S", 0x55, 9, 0, 0xe8 },
  { "ADDD,X+", 0x55, 9, 0, 0x20 },
  { "ADDD,Y+", 0x55, 9, 0, 0x30 },
  { "ADDD,U+", 0x55, 9, 0, 0x50 },
  { "ADDD,S+", 0x55, 9, 0, 0x60 },
  { "ADDD,X++", 0x55, 9, 0, 0x21 },
  { "ADDD,Y++", 0x55, 9, 0, 0x31 },
  { "ADDD,U++", 0x55, 9, 0, 0x51 },
  { "ADDD,S++", 0x55, 9, 0, 0x61 },
  { "ADDD,-X", 0x55, 9, 0, 0x22 },
  { "ADDD,-Y", 0x55, 9, 0, 0x32 },
  { "ADDD,-U", 0x55, 9, 0, 0x52 },
  { "ADDD,-S", 0x55, 9, 0, 0x62 },
  { "ADDD,--X", 0x55, 9, 0, 0x23 },
  { "ADDD,--Y", 0x55, 9, 0, 0x33 },
  { "ADDD,--U", 0x55, 9, 0, 0x53 },
  { "ADDD,--S", 0x55, 9, 0, 0x63 },
  { "ADDD (,X)", 0x55, 9, 0, 0x2e },
  { "ADDD (,Y)", 0x55, 9, 0, 0x3e },
  { "ADDD (,U)", 0x55, 9, 0, 0x5e },
  { "ADDD (,S)", 0x55, 9, 0, 0x6e },
  { "ADDD (A,X)", 0x55, 9, 0, 0xa8 },
  { "ADDD (A,Y)", 0x55, 9, 0, 0xb8 },
  { "ADDD (A,U)", 0x55, 9, 0, 0xd8 },
  { "ADDD (A,S)", 0x55, 9, 0, 0xe8 },
  { "ADDD (B,X)", 0x55, 9, 0, 0xa9 },
  { "ADDD (B,Y)", 0x55, 9, 0, 0xb9 },
  { "ADDD (B,U)", 0x55, 9, 0, 0xd9 },
  { "ADDD (B,S)", 0x55, 9, 0, 0xe9 },
  { "ADDD (D,X)", 0x55, 9, 0, 0xaf },
  { "ADDD (D,Y)", 0x55, 9, 0, 0xbf },
  { "ADDD (D,U)", 0x55, 9, 0, 0xdf },
  { "ADDD (D,S)", 0x55, 9, 0, 0xef },
  { "ADDD (,X++)", 0x55, 9, 0, 0x29 },
  { "ADDD (,Y++)", 0x55, 9, 0, 0x39 },
  { "ADDD (,U++)", 0x55, 9, 0, 0x59 },
  { "ADDD (,S++)", 0x55, 9, 0, 0x69 },
  { "ADDD (,--X)", 0x55, 9, 0, 0x2b },
  { "ADDD (,--Y)", 0x55, 9, 0, 0x3b },
  { "ADDD (,--U)", 0x55, 9, 0, 0x5b },
  { "ADDD (,--S)", 0x55, 9, 0, 0x6b },
  { "ADDD (x,X)", 0x55, 7, 1, 0x2c }, /* 8-bit offset */
  { "ADDD (x,Y)", 0x55, 7, 1, 0x3c }, /* 8-bit offset */
  { "ADDD (x,U)", 0x55, 7, 1, 0x5c }, /* 8-bit offset */
  { "ADDD (x,S)", 0x55, 7, 1, 0x6c }, /* 8-bit offset */
  { "ADDD (?,X)", 0x55, 8, 0, 0x2d }, /* 16-bit offset */
  { "ADDD (?,Y)", 0x55, 8, 0, 0x3d }, /* 16-bit offset */
  { "ADDD (?,U)", 0x55, 8, 0, 0x5d }, /* 16-bit offset */
  { "ADDD (?,S)", 0x55, 8, 0, 0x6d }, /* 16-bit offset */
  { "ADDD (x,PCR)", 0x55, 7, 1, 0x7c }, /* 8-bit offset */
  { "ADDD (?,PCR)", 0x55, 8, 0, 0x7d }, /* 16-bit offset */
  { "ADDD (?)", 0x55, 8, 0, 0x0f }, /* 16-bit offset */
  { "ADDD s,X", 0x55, 6, 1, 0x26 }, /* 5-bit offset */
  { "ADDD s,Y", 0x55, 6, 1, 0x36 }, /* 5-bit offset */
  { "ADDD s,U", 0x55, 6, 1, 0x56 }, /* 5-bit offset */
  { "ADDD s,S", 0x55, 6, 1, 0x66 }, /* 5-bit offset */
  { "ADDD x,X", 0x55, 7, 1, 0x24 }, /* 8-bit offset */
  { "ADDD x,Y", 0x55, 7, 1, 0x34 }, /* 8-bit offset */
  { "ADDD x,U", 0x55, 7, 1, 0x54 }, /* 8-bit offset */
  { "ADDD x,S", 0x55, 7, 1, 0x64 }, /* 8-bit offset */
  { "ADDD ?,X", 0x55, 8, 0, 0x25 }, /* 16-bit offset */
  { "ADDD ?,Y", 0x55, 8, 0, 0x35 }, /* 16-bit offset */
  { "ADDD ?,U", 0x55, 8, 0, 0x55 }, /* 16-bit offset */
  { "ADDD ?,S", 0x55, 8, 0, 0x65 }, /* 16-bit offset */
  { "ADDD x,PCR", 0x55, 7, 1, 0x74 }, /* 8-bit offset */
  { "ADDD ?,PCR", 0x55, 8, 0, 0x75 }, /* 16-bit offset */
  { "ADDD x", 0x55, 2, 1, 0x07 },
  { "ADDD ?", 0x55, 2, 0, 0x07 },

  { "ANDA #x", 0x24, 1, 0, 0 },
  { "ANDA,X", 0x26, 9, 0, 0x26 },
  { "ANDA,Y", 0x26, 9, 0, 0x36 },
  { "ANDA,U", 0x26, 9, 0, 0x56 },
  { "ANDA,S", 0x26, 9, 0, 0x66 },
  { "ANDA A,X", 0x26, 9, 0, 0xa0 },
  { "ANDA A,Y", 0x26, 9, 0, 0xb0 },
  { "ANDA A,U", 0x26, 9, 0, 0xd0 },
  { "ANDA A,S", 0x26, 9, 0, 0xe0 },
  { "ANDA B,X", 0x26, 9, 0, 0xa1 },
  { "ANDA B,Y", 0x26, 9, 0, 0xb1 },
  { "ANDA B,U", 0x26, 9, 0, 0xd1 },
  { "ANDA B,S", 0x26, 9, 0, 0xe1 },
  { "ANDA D,X", 0x26, 9, 0, 0xa7 },
  { "ANDA D,Y", 0x26, 9, 0, 0xb7 },
  { "ANDA D,U", 0x26, 9, 0, 0xd7 },
  { "ANDA D,S", 0x26, 9, 0, 0xe8 },
  { "ANDA,X+", 0x26, 9, 0, 0x20 },
  { "ANDA,Y+", 0x26, 9, 0, 0x30 },
  { "ANDA,U+", 0x26, 9, 0, 0x50 },
  { "ANDA,S+", 0x26, 9, 0, 0x60 },
  { "ANDA,X++", 0x26, 9, 0, 0x21 },
  { "ANDA,Y++", 0x26, 9, 0, 0x31 },
  { "ANDA,U++", 0x26, 9, 0, 0x51 },
  { "ANDA,S++", 0x26, 9, 0, 0x61 },
  { "ANDA,-X", 0x26, 9, 0, 0x22 },
  { "ANDA,-Y", 0x26, 9, 0, 0x32 },
  { "ANDA,-U", 0x26, 9, 0, 0x52 },
  { "ANDA,-S", 0x26, 9, 0, 0x62 },
  { "ANDA,--X", 0x26, 9, 0, 0x23 },
  { "ANDA,--Y", 0x26, 9, 0, 0x33 },
  { "ANDA,--U", 0x26, 9, 0, 0x53 },
  { "ANDA,--S", 0x26, 9, 0, 0x63 },
  { "ANDA (,X)", 0x26, 9, 0, 0x2e },
  { "ANDA (,Y)", 0x26, 9, 0, 0x3e },
  { "ANDA (,U)", 0x26, 9, 0, 0x5e },
  { "ANDA (,S)", 0x26, 9, 0, 0x6e },
  { "ANDA (A,X)", 0x26, 9, 0, 0xa8 },
  { "ANDA (A,Y)", 0x26, 9, 0, 0xb8 },
  { "ANDA (A,U)", 0x26, 9, 0, 0xd8 },
  { "ANDA (A,S)", 0x26, 9, 0, 0xe8 },
  { "ANDA (B,X)", 0x26, 9, 0, 0xa9 },
  { "ANDA (B,Y)", 0x26, 9, 0, 0xb9 },
  { "ANDA (B,U)", 0x26, 9, 0, 0xd9 },
  { "ANDA (B,S)", 0x26, 9, 0, 0xe9 },
  { "ANDA (D,X)", 0x26, 9, 0, 0xaf },
  { "ANDA (D,Y)", 0x26, 9, 0, 0xbf },
  { "ANDA (D,U)", 0x26, 9, 0, 0xdf },
  { "ANDA (D,S)", 0x26, 9, 0, 0xef },
  { "ANDA (,X++)", 0x26, 9, 0, 0x29 },
  { "ANDA (,Y++)", 0x26, 9, 0, 0x39 },
  { "ANDA (,U++)", 0x26, 9, 0, 0x59 },
  { "ANDA (,S++)", 0x26, 9, 0, 0x69 },
  { "ANDA (,--X)", 0x26, 9, 0, 0x2b },
  { "ANDA (,--Y)", 0x26, 9, 0, 0x3b },
  { "ANDA (,--U)", 0x26, 9, 0, 0x5b },
  { "ANDA (,--S)", 0x26, 9, 0, 0x6b },
  { "ANDA (x,X)", 0x26, 7, 1, 0x2c }, /* 8-bit offset */
  { "ANDA (x,Y)", 0x26, 7, 1, 0x3c }, /* 8-bit offset */
  { "ANDA (x,U)", 0x26, 7, 1, 0x5c }, /* 8-bit offset */
  { "ANDA (x,S)", 0x26, 7, 1, 0x6c }, /* 8-bit offset */
  { "ANDA (?,X)", 0x26, 8, 0, 0x2d }, /* 16-bit offset */
  { "ANDA (?,Y)", 0x26, 8, 0, 0x3d }, /* 16-bit offset */
  { "ANDA (?,U)", 0x26, 8, 0, 0x5d }, /* 16-bit offset */
  { "ANDA (?,S)", 0x26, 8, 0, 0x6d }, /* 16-bit offset */
  { "ANDA (x,PCR)", 0x26, 7, 1, 0x7c }, /* 8-bit offset */
  { "ANDA (?,PCR)", 0x26, 8, 0, 0x7d }, /* 16-bit offset */
  { "ANDA (?)", 0x26, 8, 0, 0x0f }, /* 16-bit offset */
  { "ANDA s,X", 0x26, 6, 1, 0x26 }, /* 5-bit offset */
  { "ANDA s,Y", 0x26, 6, 1, 0x36 }, /* 5-bit offset */
  { "ANDA s,U", 0x26, 6, 1, 0x56 }, /* 5-bit offset */
  { "ANDA s,S", 0x26, 6, 1, 0x66 }, /* 5-bit offset */
  { "ANDA x,X", 0x26, 7, 1, 0x24 }, /* 8-bit offset */
  { "ANDA x,Y", 0x26, 7, 1, 0x34 }, /* 8-bit offset */
  { "ANDA x,U", 0x26, 7, 1, 0x54 }, /* 8-bit offset */
  { "ANDA x,S", 0x26, 7, 1, 0x64 }, /* 8-bit offset */
  { "ANDA ?,X", 0x26, 8, 0, 0x25 }, /* 16-bit offset */
  { "ANDA ?,Y", 0x26, 8, 0, 0x35 }, /* 16-bit offset */
  { "ANDA ?,U", 0x26, 8, 0, 0x55 }, /* 16-bit offset */
  { "ANDA ?,S", 0x26, 8, 0, 0x65 }, /* 16-bit offset */
  { "ANDA x,PCR", 0x26, 7, 1, 0x74 }, /* 8-bit offset */
  { "ANDA ?,PCR", 0x26, 8, 0, 0x75 }, /* 16-bit offset */
  { "ANDA x", 0x26, 2, 1, 0x07 },
  { "ANDA ?", 0x26, 2, 0, 0x07 },

  { "ANDB #x", 0x25, 1, 0, 0 },
  { "ANDB,X", 0x27, 9, 0, 0x26 },
  { "ANDB,Y", 0x27, 9, 0, 0x36 },
  { "ANDB,U", 0x27, 9, 0, 0x56 },
  { "ANDB,S", 0x27, 9, 0, 0x66 },
  { "ANDB A,X", 0x27, 9, 0, 0xa0 },
  { "ANDB A,Y", 0x27, 9, 0, 0xb0 },
  { "ANDB A,U", 0x27, 9, 0, 0xd0 },
  { "ANDB A,S", 0x27, 9, 0, 0xe0 },
  { "ANDB B,X", 0x27, 9, 0, 0xa1 },
  { "ANDB B,Y", 0x27, 9, 0, 0xb1 },
  { "ANDB B,U", 0x27, 9, 0, 0xd1 },
  { "ANDB B,S", 0x27, 9, 0, 0xe1 },
  { "ANDB D,X", 0x27, 9, 0, 0xa7 },
  { "ANDB D,Y", 0x27, 9, 0, 0xb7 },
  { "ANDB D,U", 0x27, 9, 0, 0xd7 },
  { "ANDB D,S", 0x27, 9, 0, 0xe8 },
  { "ANDB,X+", 0x27, 9, 0, 0x20 },
  { "ANDB,Y+", 0x27, 9, 0, 0x30 },
  { "ANDB,U+", 0x27, 9, 0, 0x50 },
  { "ANDB,S+", 0x27, 9, 0, 0x60 },
  { "ANDB,X++", 0x27, 9, 0, 0x21 },
  { "ANDB,Y++", 0x27, 9, 0, 0x31 },
  { "ANDB,U++", 0x27, 9, 0, 0x51 },
  { "ANDB,S++", 0x27, 9, 0, 0x61 },
  { "ANDB,-X", 0x27, 9, 0, 0x22 },
  { "ANDB,-Y", 0x27, 9, 0, 0x32 },
  { "ANDB,-U", 0x27, 9, 0, 0x52 },
  { "ANDB,-S", 0x27, 9, 0, 0x62 },
  { "ANDB,--X", 0x27, 9, 0, 0x23 },
  { "ANDB,--Y", 0x27, 9, 0, 0x33 },
  { "ANDB,--U", 0x27, 9, 0, 0x53 },
  { "ANDB,--S", 0x27, 9, 0, 0x63 },
  { "ANDB (,X)", 0x27, 9, 0, 0x2e },
  { "ANDB (,Y)", 0x27, 9, 0, 0x3e },
  { "ANDB (,U)", 0x27, 9, 0, 0x5e },
  { "ANDB (,S)", 0x27, 9, 0, 0x6e },
  { "ANDB (A,X)", 0x27, 9, 0, 0xa8 },
  { "ANDB (A,Y)", 0x27, 9, 0, 0xb8 },
  { "ANDB (A,U)", 0x27, 9, 0, 0xd8 },
  { "ANDB (A,S)", 0x27, 9, 0, 0xe8 },
  { "ANDB (B,X)", 0x27, 9, 0, 0xa9 },
  { "ANDB (B,Y)", 0x27, 9, 0, 0xb9 },
  { "ANDB (B,U)", 0x27, 9, 0, 0xd9 },
  { "ANDB (B,S)", 0x27, 9, 0, 0xe9 },
  { "ANDB (D,X)", 0x27, 9, 0, 0xaf },
  { "ANDB (D,Y)", 0x27, 9, 0, 0xbf },
  { "ANDB (D,U)", 0x27, 9, 0, 0xdf },
  { "ANDB (D,S)", 0x27, 9, 0, 0xef },
  { "ANDB (,X++)", 0x27, 9, 0, 0x29 },
  { "ANDB (,Y++)", 0x27, 9, 0, 0x39 },
  { "ANDB (,U++)", 0x27, 9, 0, 0x59 },
  { "ANDB (,S++)", 0x27, 9, 0, 0x69 },
  { "ANDB (,--X)", 0x27, 9, 0, 0x2b },
  { "ANDB (,--Y)", 0x27, 9, 0, 0x3b },
  { "ANDB (,--U)", 0x27, 9, 0, 0x5b },
  { "ANDB (,--S)", 0x27, 9, 0, 0x6b },
  { "ANDB (x,X)", 0x27, 7, 1, 0x2c }, /* 8-bit offset */
  { "ANDB (x,Y)", 0x27, 7, 1, 0x3c }, /* 8-bit offset */
  { "ANDB (x,U)", 0x27, 7, 1, 0x5c }, /* 8-bit offset */
  { "ANDB (x,S)", 0x27, 7, 1, 0x6c }, /* 8-bit offset */
  { "ANDB (?,X)", 0x27, 8, 0, 0x2d }, /* 16-bit offset */
  { "ANDB (?,Y)", 0x27, 8, 0, 0x3d }, /* 16-bit offset */
  { "ANDB (?,U)", 0x27, 8, 0, 0x5d }, /* 16-bit offset */
  { "ANDB (?,S)", 0x27, 8, 0, 0x6d }, /* 16-bit offset */
  { "ANDB (x,PCR)", 0x27, 7, 1, 0x7c }, /* 8-bit offset */
  { "ANDB (?,PCR)", 0x27, 8, 0, 0x7d }, /* 16-bit offset */
  { "ANDB (?)", 0x27, 8, 0, 0x0f }, /* 16-bit offset */
  { "ANDB s,X", 0x27, 6, 1, 0x26 }, /* 5-bit offset */
  { "ANDB s,Y", 0x27, 6, 1, 0x36 }, /* 5-bit offset */
  { "ANDB s,U", 0x27, 6, 1, 0x56 }, /* 5-bit offset */
  { "ANDB s,S", 0x27, 6, 1, 0x66 }, /* 5-bit offset */
  { "ANDB x,X", 0x27, 7, 1, 0x24 }, /* 8-bit offset */
  { "ANDB x,Y", 0x27, 7, 1, 0x34 }, /* 8-bit offset */
  { "ANDB x,U", 0x27, 7, 1, 0x54 }, /* 8-bit offset */
  { "ANDB x,S", 0x27, 7, 1, 0x64 }, /* 8-bit offset */
  { "ANDB ?,X", 0x27, 8, 0, 0x25 }, /* 16-bit offset */
  { "ANDB ?,Y", 0x27, 8, 0, 0x35 }, /* 16-bit offset */
  { "ANDB ?,U", 0x27, 8, 0, 0x55 }, /* 16-bit offset */
  { "ANDB ?,S", 0x27, 8, 0, 0x65 }, /* 16-bit offset */
  { "ANDB x,PCR", 0x27, 7, 1, 0x74 }, /* 8-bit offset */
  { "ANDB ?,PCR", 0x27, 8, 0, 0x75 }, /* 16-bit offset */
  { "ANDB x", 0x27, 2, 1, 0x07 },
  { "ANDB ?", 0x27, 2, 0, 0x07 },

  { "ANDCC #x", 0x3C, 1, 0, 0 },

  { "ASLA", 0x9c, 0, 0, 0 },
  { "ASLB", 0x9d, 0, 0, 0 },
  { "ASL,X", 0x9e, 9, 0, 0x26 },
  { "ASL,Y", 0x9e, 9, 0, 0x36 },
  { "ASL,U", 0x9e, 9, 0, 0x56 },
  { "ASL,S", 0x9e, 9, 0, 0x66 },
  { "ASL A,X", 0x9e, 9, 0, 0xa0 },
  { "ASL A,Y", 0x9e, 9, 0, 0xb0 },
  { "ASL A,U", 0x9e, 9, 0, 0xd0 },
  { "ASL A,S", 0x9e, 9, 0, 0xe0 },
  { "ASL B,X", 0x9e, 9, 0, 0xa1 },
  { "ASL B,Y", 0x9e, 9, 0, 0xb1 },
  { "ASL B,U", 0x9e, 9, 0, 0xd1 },
  { "ASL B,S", 0x9e, 9, 0, 0xe1 },
  { "ASL D,X", 0x9e, 9, 0, 0xa7 },
  { "ASL D,Y", 0x9e, 9, 0, 0xb7 },
  { "ASL D,U", 0x9e, 9, 0, 0xd7 },
  { "ASL D,S", 0x9e, 9, 0, 0xe8 },
  { "ASL,X+", 0x9e, 9, 0, 0x20 },
  { "ASL,Y+", 0x9e, 9, 0, 0x30 },
  { "ASL,U+", 0x9e, 9, 0, 0x50 },
  { "ASL,S+", 0x9e, 9, 0, 0x60 },
  { "ASL,X++", 0x9e, 9, 0, 0x21 },
  { "ASL,Y++", 0x9e, 9, 0, 0x31 },
  { "ASL,U++", 0x9e, 9, 0, 0x51 },
  { "ASL,S++", 0x9e, 9, 0, 0x61 },
  { "ASL,-X", 0x9e, 9, 0, 0x22 },
  { "ASL,-Y", 0x9e, 9, 0, 0x32 },
  { "ASL,-U", 0x9e, 9, 0, 0x52 },
  { "ASL,-S", 0x9e, 9, 0, 0x62 },
  { "ASL,--X", 0x9e, 9, 0, 0x23 },
  { "ASL,--Y", 0x9e, 9, 0, 0x33 },
  { "ASL,--U", 0x9e, 9, 0, 0x53 },
  { "ASL,--S", 0x9e, 9, 0, 0x63 },
  { "ASL (,X)", 0x9e, 9, 0, 0x2e },
  { "ASL (,Y)", 0x9e, 9, 0, 0x3e },
  { "ASL (,U)", 0x9e, 9, 0, 0x5e },
  { "ASL (,S)", 0x9e, 9, 0, 0x6e },
  { "ASL (A,X)", 0x9e, 9, 0, 0xa8 },
  { "ASL (A,Y)", 0x9e, 9, 0, 0xb8 },
  { "ASL (A,U)", 0x9e, 9, 0, 0xd8 },
  { "ASL (A,S)", 0x9e, 9, 0, 0xe8 },
  { "ASL (B,X)", 0x9e, 9, 0, 0xa9 },
  { "ASL (B,Y)", 0x9e, 9, 0, 0xb9 },
  { "ASL (B,U)", 0x9e, 9, 0, 0xd9 },
  { "ASL (B,S)", 0x9e, 9, 0, 0xe9 },
  { "ASL (D,X)", 0x9e, 9, 0, 0xaf },
  { "ASL (D,Y)", 0x9e, 9, 0, 0xbf },
  { "ASL (D,U)", 0x9e, 9, 0, 0xdf },
  { "ASL (D,S)", 0x9e, 9, 0, 0xef },
  { "ASL (,X++)", 0x9e, 9, 0, 0x29 },
  { "ASL (,Y++)", 0x9e, 9, 0, 0x39 },
  { "ASL (,U++)", 0x9e, 9, 0, 0x59 },
  { "ASL (,S++)", 0x9e, 9, 0, 0x69 },
  { "ASL (,--X)", 0x9e, 9, 0, 0x2b },
  { "ASL (,--Y)", 0x9e, 9, 0, 0x3b },
  { "ASL (,--U)", 0x9e, 9, 0, 0x5b },
  { "ASL (,--S)", 0x9e, 9, 0, 0x6b },
  { "ASL (x,X)", 0x9e, 7, 1, 0x2c }, /* 8-bit offset */
  { "ASL (x,Y)", 0x9e, 7, 1, 0x3c }, /* 8-bit offset */
  { "ASL (x,U)", 0x9e, 7, 1, 0x5c }, /* 8-bit offset */
  { "ASL (x,S)", 0x9e, 7, 1, 0x6c }, /* 8-bit offset */
  { "ASL (?,X)", 0x9e, 8, 0, 0x2d }, /* 16-bit offset */
  { "ASL (?,Y)", 0x9e, 8, 0, 0x3d }, /* 16-bit offset */
  { "ASL (?,U)", 0x9e, 8, 0, 0x5d }, /* 16-bit offset */
  { "ASL (?,S)", 0x9e, 8, 0, 0x6d }, /* 16-bit offset */
  { "ASL (x,PCR)", 0x9e, 7, 1, 0x7c }, /* 8-bit offset */
  { "ASL (?,PCR)", 0x9e, 8, 0, 0x7d }, /* 16-bit offset */
  { "ASL (?)", 0x9e, 8, 0, 0x0f }, /* 16-bit offset */
  { "ASL s,X", 0x9e, 6, 1, 0x26 }, /* 5-bit offset */
  { "ASL s,Y", 0x9e, 6, 1, 0x36 }, /* 5-bit offset */
  { "ASL s,U", 0x9e, 6, 1, 0x56 }, /* 5-bit offset */
  { "ASL s,S", 0x9e, 6, 1, 0x66 }, /* 5-bit offset */
  { "ASL x,X", 0x9e, 7, 1, 0x24 }, /* 8-bit offset */
  { "ASL x,Y", 0x9e, 7, 1, 0x34 }, /* 8-bit offset */
  { "ASL x,U", 0x9e, 7, 1, 0x54 }, /* 8-bit offset */
  { "ASL x,S", 0x9e, 7, 1, 0x64 }, /* 8-bit offset */
  { "ASL ?,X", 0x9e, 8, 0, 0x25 }, /* 16-bit offset */
  { "ASL ?,Y", 0x9e, 8, 0, 0x35 }, /* 16-bit offset */
  { "ASL ?,U", 0x9e, 8, 0, 0x55 }, /* 16-bit offset */
  { "ASL ?,S", 0x9e, 8, 0, 0x65 }, /* 16-bit offset */
  { "ASL x,PCR", 0x9e, 7, 1, 0x74 }, /* 8-bit offset */
  { "ASL ?,PCR", 0x9e, 8, 0, 0x75 }, /* 16-bit offset */
  { "ASL x", 0x9e, 2, 1, 0x07 },
  { "ASL ?", 0x9e, 2, 0, 0x07 },

  { "ASRA", 0x99, 0, 0, 0 },
  { "ASRB", 0x9a, 0, 0, 0 },
  { "ASR,X", 0x9b, 9, 0, 0x26 },
  { "ASR,Y", 0x9b, 9, 0, 0x36 },
  { "ASR,U", 0x9b, 9, 0, 0x56 },
  { "ASR,S", 0x9b, 9, 0, 0x66 },
  { "ASR A,X", 0x9b, 9, 0, 0xa0 },
  { "ASR A,Y", 0x9b, 9, 0, 0xb0 },
  { "ASR A,U", 0x9b, 9, 0, 0xd0 },
  { "ASR A,S", 0x9b, 9, 0, 0xe0 },
  { "ASR B,X", 0x9b, 9, 0, 0xa1 },
  { "ASR B,Y", 0x9b, 9, 0, 0xb1 },
  { "ASR B,U", 0x9b, 9, 0, 0xd1 },
  { "ASR B,S", 0x9b, 9, 0, 0xe1 },
  { "ASR D,X", 0x9b, 9, 0, 0xa7 },
  { "ASR D,Y", 0x9b, 9, 0, 0xb7 },
  { "ASR D,U", 0x9b, 9, 0, 0xd7 },
  { "ASR D,S", 0x9b, 9, 0, 0xe8 },
  { "ASR,X+", 0x9b, 9, 0, 0x20 },
  { "ASR,Y+", 0x9b, 9, 0, 0x30 },
  { "ASR,U+", 0x9b, 9, 0, 0x50 },
  { "ASR,S+", 0x9b, 9, 0, 0x60 },
  { "ASR,X++", 0x9b, 9, 0, 0x21 },
  { "ASR,Y++", 0x9b, 9, 0, 0x31 },
  { "ASR,U++", 0x9b, 9, 0, 0x51 },
  { "ASR,S++", 0x9b, 9, 0, 0x61 },
  { "ASR,-X", 0x9b, 9, 0, 0x22 },
  { "ASR,-Y", 0x9b, 9, 0, 0x32 },
  { "ASR,-U", 0x9b, 9, 0, 0x52 },
  { "ASR,-S", 0x9b, 9, 0, 0x62 },
  { "ASR,--X", 0x9b, 9, 0, 0x23 },
  { "ASR,--Y", 0x9b, 9, 0, 0x33 },
  { "ASR,--U", 0x9b, 9, 0, 0x53 },
  { "ASR,--S", 0x9b, 9, 0, 0x63 },
  { "ASR (,X)", 0x9b, 9, 0, 0x2e },
  { "ASR (,Y)", 0x9b, 9, 0, 0x3e },
  { "ASR (,U)", 0x9b, 9, 0, 0x5e },
  { "ASR (,S)", 0x9b, 9, 0, 0x6e },
  { "ASR (A,X)", 0x9b, 9, 0, 0xa8 },
  { "ASR (A,Y)", 0x9b, 9, 0, 0xb8 },
  { "ASR (A,U)", 0x9b, 9, 0, 0xd8 },
  { "ASR (A,S)", 0x9b, 9, 0, 0xe8 },
  { "ASR (B,X)", 0x9b, 9, 0, 0xa9 },
  { "ASR (B,Y)", 0x9b, 9, 0, 0xb9 },
  { "ASR (B,U)", 0x9b, 9, 0, 0xd9 },
  { "ASR (B,S)", 0x9b, 9, 0, 0xe9 },
  { "ASR (D,X)", 0x9b, 9, 0, 0xaf },
  { "ASR (D,Y)", 0x9b, 9, 0, 0xbf },
  { "ASR (D,U)", 0x9b, 9, 0, 0xdf },
  { "ASR (D,S)", 0x9b, 9, 0, 0xef },
  { "ASR (,X++)", 0x9b, 9, 0, 0x29 },
  { "ASR (,Y++)", 0x9b, 9, 0, 0x39 },
  { "ASR (,U++)", 0x9b, 9, 0, 0x59 },
  { "ASR (,S++)", 0x9b, 9, 0, 0x69 },
  { "ASR (,--X)", 0x9b, 9, 0, 0x2b },
  { "ASR (,--Y)", 0x9b, 9, 0, 0x3b },
  { "ASR (,--U)", 0x9b, 9, 0, 0x5b },
  { "ASR (,--S)", 0x9b, 9, 0, 0x6b },
  { "ASR (x,X)", 0x9b, 7, 1, 0x2c }, /* 8-bit offset */
  { "ASR (x,Y)", 0x9b, 7, 1, 0x3c }, /* 8-bit offset */
  { "ASR (x,U)", 0x9b, 7, 1, 0x5c }, /* 8-bit offset */
  { "ASR (x,S)", 0x9b, 7, 1, 0x6c }, /* 8-bit offset */
  { "ASR (?,X)", 0x9b, 8, 0, 0x2d }, /* 16-bit offset */
  { "ASR (?,Y)", 0x9b, 8, 0, 0x3d }, /* 16-bit offset */
  { "ASR (?,U)", 0x9b, 8, 0, 0x5d }, /* 16-bit offset */
  { "ASR (?,S)", 0x9b, 8, 0, 0x6d }, /* 16-bit offset */
  { "ASR (x,PCR)", 0x9b, 7, 1, 0x7c }, /* 8-bit offset */
  { "ASR (?,PCR)", 0x9b, 8, 0, 0x7d }, /* 16-bit offset */
  { "ASR (?)", 0x9b, 8, 0, 0x0f }, /* 16-bit offset */
  { "ASR s,X", 0x9b, 6, 1, 0x26 }, /* 5-bit offset */
  { "ASR s,Y", 0x9b, 6, 1, 0x36 }, /* 5-bit offset */
  { "ASR s,U", 0x9b, 6, 1, 0x56 }, /* 5-bit offset */
  { "ASR s,S", 0x9b, 6, 1, 0x66 }, /* 5-bit offset */
  { "ASR x,X", 0x9b, 7, 1, 0x24 }, /* 8-bit offset */
  { "ASR x,Y", 0x9b, 7, 1, 0x34 }, /* 8-bit offset */
  { "ASR x,U", 0x9b, 7, 1, 0x54 }, /* 8-bit offset */
  { "ASR x,S", 0x9b, 7, 1, 0x64 }, /* 8-bit offset */
  { "ASR ?,X", 0x9b, 8, 0, 0x25 }, /* 16-bit offset */
  { "ASR ?,Y", 0x9b, 8, 0, 0x35 }, /* 16-bit offset */
  { "ASR ?,U", 0x9b, 8, 0, 0x55 }, /* 16-bit offset */
  { "ASR ?,S", 0x9b, 8, 0, 0x65 }, /* 16-bit offset */
  { "ASR x,PCR", 0x9b, 7, 1, 0x74 }, /* 8-bit offset */
  { "ASR ?,PCR", 0x9b, 8, 0, 0x75 }, /* 16-bit offset */
  { "ASR x", 0x9b, 2, 1, 0x07 },
  { "ASR ?", 0x9b, 2, 0, 0x07 },

  { "BITA #x", 0x28, 1, 0, 0 },
  { "BITA,X", 0x2a, 9, 0, 0x26 },
  { "BITA,Y", 0x2a, 9, 0, 0x36 },
  { "BITA,U", 0x2a, 9, 0, 0x56 },
  { "BITA,S", 0x2a, 9, 0, 0x66 },
  { "BITA A,X", 0x2a, 9, 0, 0xa0 },
  { "BITA A,Y", 0x2a, 9, 0, 0xb0 },
  { "BITA A,U", 0x2a, 9, 0, 0xd0 },
  { "BITA A,S", 0x2a, 9, 0, 0xe0 },
  { "BITA B,X", 0x2a, 9, 0, 0xa1 },
  { "BITA B,Y", 0x2a, 9, 0, 0xb1 },
  { "BITA B,U", 0x2a, 9, 0, 0xd1 },
  { "BITA B,S", 0x2a, 9, 0, 0xe1 },
  { "BITA D,X", 0x2a, 9, 0, 0xa7 },
  { "BITA D,Y", 0x2a, 9, 0, 0xb7 },
  { "BITA D,U", 0x2a, 9, 0, 0xd7 },
  { "BITA D,S", 0x2a, 9, 0, 0xe8 },
  { "BITA,X+", 0x2a, 9, 0, 0x20 },
  { "BITA,Y+", 0x2a, 9, 0, 0x30 },
  { "BITA,U+", 0x2a, 9, 0, 0x50 },
  { "BITA,S+", 0x2a, 9, 0, 0x60 },
  { "BITA,X++", 0x2a, 9, 0, 0x21 },
  { "BITA,Y++", 0x2a, 9, 0, 0x31 },
  { "BITA,U++", 0x2a, 9, 0, 0x51 },
  { "BITA,S++", 0x2a, 9, 0, 0x61 },
  { "BITA,-X", 0x2a, 9, 0, 0x22 },
  { "BITA,-Y", 0x2a, 9, 0, 0x32 },
  { "BITA,-U", 0x2a, 9, 0, 0x52 },
  { "BITA,-S", 0x2a, 9, 0, 0x62 },
  { "BITA,--X", 0x2a, 9, 0, 0x23 },
  { "BITA,--Y", 0x2a, 9, 0, 0x33 },
  { "BITA,--U", 0x2a, 9, 0, 0x53 },
  { "BITA,--S", 0x2a, 9, 0, 0x63 },
  { "BITA (,X)", 0x2a, 9, 0, 0x2e },
  { "BITA (,Y)", 0x2a, 9, 0, 0x3e },
  { "BITA (,U)", 0x2a, 9, 0, 0x5e },
  { "BITA (,S)", 0x2a, 9, 0, 0x6e },
  { "BITA (A,X)", 0x2a, 9, 0, 0xa8 },
  { "BITA (A,Y)", 0x2a, 9, 0, 0xb8 },
  { "BITA (A,U)", 0x2a, 9, 0, 0xd8 },
  { "BITA (A,S)", 0x2a, 9, 0, 0xe8 },
  { "BITA (B,X)", 0x2a, 9, 0, 0xa9 },
  { "BITA (B,Y)", 0x2a, 9, 0, 0xb9 },
  { "BITA (B,U)", 0x2a, 9, 0, 0xd9 },
  { "BITA (B,S)", 0x2a, 9, 0, 0xe9 },
  { "BITA (D,X)", 0x2a, 9, 0, 0xaf },
  { "BITA (D,Y)", 0x2a, 9, 0, 0xbf },
  { "BITA (D,U)", 0x2a, 9, 0, 0xdf },
  { "BITA (D,S)", 0x2a, 9, 0, 0xef },
  { "BITA (,X++)", 0x2a, 9, 0, 0x29 },
  { "BITA (,Y++)", 0x2a, 9, 0, 0x39 },
  { "BITA (,U++)", 0x2a, 9, 0, 0x59 },
  { "BITA (,S++)", 0x2a, 9, 0, 0x69 },
  { "BITA (,--X)", 0x2a, 9, 0, 0x2b },
  { "BITA (,--Y)", 0x2a, 9, 0, 0x3b },
  { "BITA (,--U)", 0x2a, 9, 0, 0x5b },
  { "BITA (,--S)", 0x2a, 9, 0, 0x6b },
  { "BITA (x,X)", 0x2a, 7, 1, 0x2c }, /* 8-bit offset */
  { "BITA (x,Y)", 0x2a, 7, 1, 0x3c }, /* 8-bit offset */
  { "BITA (x,U)", 0x2a, 7, 1, 0x5c }, /* 8-bit offset */
  { "BITA (x,S)", 0x2a, 7, 1, 0x6c }, /* 8-bit offset */
  { "BITA (?,X)", 0x2a, 8, 0, 0x2d }, /* 16-bit offset */
  { "BITA (?,Y)", 0x2a, 8, 0, 0x3d }, /* 16-bit offset */
  { "BITA (?,U)", 0x2a, 8, 0, 0x5d }, /* 16-bit offset */
  { "BITA (?,S)", 0x2a, 8, 0, 0x6d }, /* 16-bit offset */
  { "BITA (x,PCR)", 0x2a, 7, 1, 0x7c }, /* 8-bit offset */
  { "BITA (?,PCR)", 0x2a, 8, 0, 0x7d }, /* 16-bit offset */
  { "BITA (?)", 0x2a, 8, 0, 0x0f }, /* 16-bit offset */
  { "BITA s,X", 0x2a, 6, 1, 0x26 }, /* 5-bit offset */
  { "BITA s,Y", 0x2a, 6, 1, 0x36 }, /* 5-bit offset */
  { "BITA s,U", 0x2a, 6, 1, 0x56 }, /* 5-bit offset */
  { "BITA s,S", 0x2a, 6, 1, 0x66 }, /* 5-bit offset */
  { "BITA x,X", 0x2a, 7, 1, 0x24 }, /* 8-bit offset */
  { "BITA x,Y", 0x2a, 7, 1, 0x34 }, /* 8-bit offset */
  { "BITA x,U", 0x2a, 7, 1, 0x54 }, /* 8-bit offset */
  { "BITA x,S", 0x2a, 7, 1, 0x64 }, /* 8-bit offset */
  { "BITA ?,X", 0x2a, 8, 0, 0x25 }, /* 16-bit offset */
  { "BITA ?,Y", 0x2a, 8, 0, 0x35 }, /* 16-bit offset */
  { "BITA ?,U", 0x2a, 8, 0, 0x55 }, /* 16-bit offset */
  { "BITA ?,S", 0x2a, 8, 0, 0x65 }, /* 16-bit offset */
  { "BITA x,PCR", 0x2a, 7, 1, 0x74 }, /* 8-bit offset */
  { "BITA ?,PCR", 0x2a, 8, 0, 0x75 }, /* 16-bit offset */
  { "BITA x", 0x2a, 2, 1, 0x07 },
  { "BITA ?", 0x2a, 2, 0, 0x07 },

  { "BITB #x", 0x29, 1, 0, 0 },
  { "BITB,X", 0x2b, 9, 0, 0x26 },
  { "BITB,Y", 0x2b, 9, 0, 0x36 },
  { "BITB,U", 0x2b, 9, 0, 0x56 },
  { "BITB,S", 0x2b, 9, 0, 0x66 },
  { "BITB A,X", 0x2b, 9, 0, 0xa0 },
  { "BITB A,Y", 0x2b, 9, 0, 0xb0 },
  { "BITB A,U", 0x2b, 9, 0, 0xd0 },
  { "BITB A,S", 0x2b, 9, 0, 0xe0 },
  { "BITB B,X", 0x2b, 9, 0, 0xa1 },
  { "BITB B,Y", 0x2b, 9, 0, 0xb1 },
  { "BITB B,U", 0x2b, 9, 0, 0xd1 },
  { "BITB B,S", 0x2b, 9, 0, 0xe1 },
  { "BITB D,X", 0x2b, 9, 0, 0xa7 },
  { "BITB D,Y", 0x2b, 9, 0, 0xb7 },
  { "BITB D,U", 0x2b, 9, 0, 0xd7 },
  { "BITB D,S", 0x2b, 9, 0, 0xe8 },
  { "BITB,X+", 0x2b, 9, 0, 0x20 },
  { "BITB,Y+", 0x2b, 9, 0, 0x30 },
  { "BITB,U+", 0x2b, 9, 0, 0x50 },
  { "BITB,S+", 0x2b, 9, 0, 0x60 },
  { "BITB,X++", 0x2b, 9, 0, 0x21 },
  { "BITB,Y++", 0x2b, 9, 0, 0x31 },
  { "BITB,U++", 0x2b, 9, 0, 0x51 },
  { "BITB,S++", 0x2b, 9, 0, 0x61 },
  { "BITB,-X", 0x2b, 9, 0, 0x22 },
  { "BITB,-Y", 0x2b, 9, 0, 0x32 },
  { "BITB,-U", 0x2b, 9, 0, 0x52 },
  { "BITB,-S", 0x2b, 9, 0, 0x62 },
  { "BITB,--X", 0x2b, 9, 0, 0x23 },
  { "BITB,--Y", 0x2b, 9, 0, 0x33 },
  { "BITB,--U", 0x2b, 9, 0, 0x53 },
  { "BITB,--S", 0x2b, 9, 0, 0x63 },
  { "BITB (,X)", 0x2b, 9, 0, 0x2e },
  { "BITB (,Y)", 0x2b, 9, 0, 0x3e },
  { "BITB (,U)", 0x2b, 9, 0, 0x5e },
  { "BITB (,S)", 0x2b, 9, 0, 0x6e },
  { "BITB (A,X)", 0x2b, 9, 0, 0xa8 },
  { "BITB (A,Y)", 0x2b, 9, 0, 0xb8 },
  { "BITB (A,U)", 0x2b, 9, 0, 0xd8 },
  { "BITB (A,S)", 0x2b, 9, 0, 0xe8 },
  { "BITB (B,X)", 0x2b, 9, 0, 0xa9 },
  { "BITB (B,Y)", 0x2b, 9, 0, 0xb9 },
  { "BITB (B,U)", 0x2b, 9, 0, 0xd9 },
  { "BITB (B,S)", 0x2b, 9, 0, 0xe9 },
  { "BITB (D,X)", 0x2b, 9, 0, 0xaf },
  { "BITB (D,Y)", 0x2b, 9, 0, 0xbf },
  { "BITB (D,U)", 0x2b, 9, 0, 0xdf },
  { "BITB (D,S)", 0x2b, 9, 0, 0xef },
  { "BITB (,X++)", 0x2b, 9, 0, 0x29 },
  { "BITB (,Y++)", 0x2b, 9, 0, 0x39 },
  { "BITB (,U++)", 0x2b, 9, 0, 0x59 },
  { "BITB (,S++)", 0x2b, 9, 0, 0x69 },
  { "BITB (,--X)", 0x2b, 9, 0, 0x2b },
  { "BITB (,--Y)", 0x2b, 9, 0, 0x3b },
  { "BITB (,--U)", 0x2b, 9, 0, 0x5b },
  { "BITB (,--S)", 0x2b, 9, 0, 0x6b },
  { "BITB (x,X)", 0x2b, 7, 1, 0x2c }, /* 8-bit offset */
  { "BITB (x,Y)", 0x2b, 7, 1, 0x3c }, /* 8-bit offset */
  { "BITB (x,U)", 0x2b, 7, 1, 0x5c }, /* 8-bit offset */
  { "BITB (x,S)", 0x2b, 7, 1, 0x6c }, /* 8-bit offset */
  { "BITB (?,X)", 0x2b, 8, 0, 0x2d }, /* 16-bit offset */
  { "BITB (?,Y)", 0x2b, 8, 0, 0x3d }, /* 16-bit offset */
  { "BITB (?,U)", 0x2b, 8, 0, 0x5d }, /* 16-bit offset */
  { "BITB (?,S)", 0x2b, 8, 0, 0x6d }, /* 16-bit offset */
  { "BITB (x,PCR)", 0x2b, 7, 1, 0x7c }, /* 8-bit offset */
  { "BITB (?,PCR)", 0x2b, 8, 0, 0x7d }, /* 16-bit offset */
  { "BITB (?)", 0x2b, 8, 0, 0x0f }, /* 16-bit offset */
  { "BITB s,X", 0x2b, 6, 1, 0x26 }, /* 5-bit offset */
  { "BITB s,Y", 0x2b, 6, 1, 0x36 }, /* 5-bit offset */
  { "BITB s,U", 0x2b, 6, 1, 0x56 }, /* 5-bit offset */
  { "BITB s,S", 0x2b, 6, 1, 0x66 }, /* 5-bit offset */
  { "BITB x,X", 0x2b, 7, 1, 0x24 }, /* 8-bit offset */
  { "BITB x,Y", 0x2b, 7, 1, 0x34 }, /* 8-bit offset */
  { "BITB x,U", 0x2b, 7, 1, 0x54 }, /* 8-bit offset */
  { "BITB x,S", 0x2b, 7, 1, 0x64 }, /* 8-bit offset */
  { "BITB ?,X", 0x2b, 8, 0, 0x25 }, /* 16-bit offset */
  { "BITB ?,Y", 0x2b, 8, 0, 0x35 }, /* 16-bit offset */
  { "BITB ?,U", 0x2b, 8, 0, 0x55 }, /* 16-bit offset */
  { "BITB ?,S", 0x2b, 8, 0, 0x65 }, /* 16-bit offset */
  { "BITB x,PCR", 0x2b, 7, 1, 0x74 }, /* 8-bit offset */
  { "BITB ?,PCR", 0x2b, 8, 0, 0x75 }, /* 16-bit offset */
  { "BITB x", 0x2b, 2, 1, 0x07 },
  { "BITB ?", 0x2b, 2, 0, 0x07 },

  { "BCC x", 0x62, 5, 0, 0 },
  { "BCS x", 0x72, 5, 0, 0 },
  { "BEQ x", 0x73, 5, 0, 0 },
  { "BGE x", 0x66, 5, 0, 0 },
  { "BGT x", 0x67, 5, 0, 0 },
  { "BHI x", 0x61, 5, 0, 0 },
  { "BHS x", 0x62, 5, 0, 0 },
  { "BLE x", 0x77, 5, 0, 0 },
  { "BLO x", 0x72, 5, 0, 0 },
  { "BLS x", 0x72, 5, 0, 0 },
  { "BLT x", 0x76, 5, 0, 0 },
  { "BMI x", 0x75, 5, 0, 0 },
  { "BNE x", 0x63, 5, 0, 0 },
  { "BPL x", 0x65, 5, 0, 0 },
  { "BRA x", 0x60, 5, 0, 0 },
  { "BRN x", 0x70, 5, 0, 0 },
  { "BSR x", 0xaa, 5, 0, 0 },
  { "BVC x", 0x64, 5, 0, 0 },
  { "BVS x", 0x74, 5, 0, 0 },

  { "CLRA", 0x80, 0, 0, 0 },
  { "CLRB", 0x81, 0, 0, 0 },
  { "CLR,X", 0x82, 9, 0, 0x26 },
  { "CLR,Y", 0x82, 9, 0, 0x36 },
  { "CLR,U", 0x82, 9, 0, 0x56 },
  { "CLR,S", 0x82, 9, 0, 0x66 },
  { "CLR A,X", 0x82, 9, 0, 0xa0 },
  { "CLR A,Y", 0x82, 9, 0, 0xb0 },
  { "CLR A,U", 0x82, 9, 0, 0xd0 },
  { "CLR A,S", 0x82, 9, 0, 0xe0 },
  { "CLR B,X", 0x82, 9, 0, 0xa1 },
  { "CLR B,Y", 0x82, 9, 0, 0xb1 },
  { "CLR B,U", 0x82, 9, 0, 0xd1 },
  { "CLR B,S", 0x82, 9, 0, 0xe1 },
  { "CLR D,X", 0x82, 9, 0, 0xa7 },
  { "CLR D,Y", 0x82, 9, 0, 0xb7 },
  { "CLR D,U", 0x82, 9, 0, 0xd7 },
  { "CLR D,S", 0x82, 9, 0, 0xe8 },
  { "CLR,X+", 0x82, 9, 0, 0x20 },
  { "CLR,Y+", 0x82, 9, 0, 0x30 },
  { "CLR,U+", 0x82, 9, 0, 0x50 },
  { "CLR,S+", 0x82, 9, 0, 0x60 },
  { "CLR,X++", 0x82, 9, 0, 0x21 },
  { "CLR,Y++", 0x82, 9, 0, 0x31 },
  { "CLR,U++", 0x82, 9, 0, 0x51 },
  { "CLR,S++", 0x82, 9, 0, 0x61 },
  { "CLR,-X", 0x82, 9, 0, 0x22 },
  { "CLR,-Y", 0x82, 9, 0, 0x32 },
  { "CLR,-U", 0x82, 9, 0, 0x52 },
  { "CLR,-S", 0x82, 9, 0, 0x62 },
  { "CLR,--X", 0x82, 9, 0, 0x23 },
  { "CLR,--Y", 0x82, 9, 0, 0x33 },
  { "CLR,--U", 0x82, 9, 0, 0x53 },
  { "CLR,--S", 0x82, 9, 0, 0x63 },
  { "CLR (,X)", 0x82, 9, 0, 0x2e },
  { "CLR (,Y)", 0x82, 9, 0, 0x3e },
  { "CLR (,U)", 0x82, 9, 0, 0x5e },
  { "CLR (,S)", 0x82, 9, 0, 0x6e },
  { "CLR (A,X)", 0x82, 9, 0, 0xa8 },
  { "CLR (A,Y)", 0x82, 9, 0, 0xb8 },
  { "CLR (A,U)", 0x82, 9, 0, 0xd8 },
  { "CLR (A,S)", 0x82, 9, 0, 0xe8 },
  { "CLR (B,X)", 0x82, 9, 0, 0xa9 },
  { "CLR (B,Y)", 0x82, 9, 0, 0xb9 },
  { "CLR (B,U)", 0x82, 9, 0, 0xd9 },
  { "CLR (B,S)", 0x82, 9, 0, 0xe9 },
  { "CLR (D,X)", 0x82, 9, 0, 0xaf },
  { "CLR (D,Y)", 0x82, 9, 0, 0xbf },
  { "CLR (D,U)", 0x82, 9, 0, 0xdf },
  { "CLR (D,S)", 0x82, 9, 0, 0xef },
  { "CLR (,X++)", 0x82, 9, 0, 0x29 },
  { "CLR (,Y++)", 0x82, 9, 0, 0x39 },
  { "CLR (,U++)", 0x82, 9, 0, 0x59 },
  { "CLR (,S++)", 0x82, 9, 0, 0x69 },
  { "CLR (,--X)", 0x82, 9, 0, 0x2b },
  { "CLR (,--Y)", 0x82, 9, 0, 0x3b },
  { "CLR (,--U)", 0x82, 9, 0, 0x5b },
  { "CLR (,--S)", 0x82, 9, 0, 0x6b },
  { "CLR (x,X)", 0x82, 7, 1, 0x2c }, /* 8-bit offset */
  { "CLR (x,Y)", 0x82, 7, 1, 0x3c }, /* 8-bit offset */
  { "CLR (x,U)", 0x82, 7, 1, 0x5c }, /* 8-bit offset */
  { "CLR (x,S)", 0x82, 7, 1, 0x6c }, /* 8-bit offset */
  { "CLR (?,X)", 0x82, 8, 0, 0x2d }, /* 16-bit offset */
  { "CLR (?,Y)", 0x82, 8, 0, 0x3d }, /* 16-bit offset */
  { "CLR (?,U)", 0x82, 8, 0, 0x5d }, /* 16-bit offset */
  { "CLR (?,S)", 0x82, 8, 0, 0x6d }, /* 16-bit offset */
  { "CLR (x,PCR)", 0x82, 7, 1, 0x7c }, /* 8-bit offset */
  { "CLR (?,PCR)", 0x82, 8, 0, 0x7d }, /* 16-bit offset */
  { "CLR (?)", 0x82, 8, 0, 0x0f }, /* 16-bit offset */
  { "CLR s,X", 0x82, 6, 1, 0x26 }, /* 5-bit offset */
  { "CLR s,Y", 0x82, 6, 1, 0x36 }, /* 5-bit offset */
  { "CLR s,U", 0x82, 6, 1, 0x56 }, /* 5-bit offset */
  { "CLR s,S", 0x82, 6, 1, 0x66 }, /* 5-bit offset */
  { "CLR x,X", 0x82, 7, 1, 0x24 }, /* 8-bit offset */
  { "CLR x,Y", 0x82, 7, 1, 0x34 }, /* 8-bit offset */
  { "CLR x,U", 0x82, 7, 1, 0x54 }, /* 8-bit offset */
  { "CLR x,S", 0x82, 7, 1, 0x64 }, /* 8-bit offset */
  { "CLR ?,X", 0x82, 8, 0, 0x25 }, /* 16-bit offset */
  { "CLR ?,Y", 0x82, 8, 0, 0x35 }, /* 16-bit offset */
  { "CLR ?,U", 0x82, 8, 0, 0x55 }, /* 16-bit offset */
  { "CLR ?,S", 0x82, 8, 0, 0x65 }, /* 16-bit offset */
  { "CLR x,PCR", 0x82, 7, 1, 0x74 }, /* 8-bit offset */
  { "CLR ?,PCR", 0x82, 8, 0, 0x75 }, /* 16-bit offset */
  { "CLR x", 0x82, 2, 1, 0x07 },
  { "CLR ?", 0x82, 2, 0, 0x07 },

  { "CMPA #x", 0x34, 1, 0, 0 },
  { "CMPA,X", 0x36, 9, 0, 0x26 },
  { "CMPA,Y", 0x36, 9, 0, 0x36 },
  { "CMPA,U", 0x36, 9, 0, 0x56 },
  { "CMPA,S", 0x36, 9, 0, 0x66 },
  { "CMPA A,X", 0x36, 9, 0, 0xa0 },
  { "CMPA A,Y", 0x36, 9, 0, 0xb0 },
  { "CMPA A,U", 0x36, 9, 0, 0xd0 },
  { "CMPA A,S", 0x36, 9, 0, 0xe0 },
  { "CMPA B,X", 0x36, 9, 0, 0xa1 },
  { "CMPA B,Y", 0x36, 9, 0, 0xb1 },
  { "CMPA B,U", 0x36, 9, 0, 0xd1 },
  { "CMPA B,S", 0x36, 9, 0, 0xe1 },
  { "CMPA D,X", 0x36, 9, 0, 0xa7 },
  { "CMPA D,Y", 0x36, 9, 0, 0xb7 },
  { "CMPA D,U", 0x36, 9, 0, 0xd7 },
  { "CMPA D,S", 0x36, 9, 0, 0xe8 },
  { "CMPA,X+", 0x36, 9, 0, 0x20 },
  { "CMPA,Y+", 0x36, 9, 0, 0x30 },
  { "CMPA,U+", 0x36, 9, 0, 0x50 },
  { "CMPA,S+", 0x36, 9, 0, 0x60 },
  { "CMPA,X++", 0x36, 9, 0, 0x21 },
  { "CMPA,Y++", 0x36, 9, 0, 0x31 },
  { "CMPA,U++", 0x36, 9, 0, 0x51 },
  { "CMPA,S++", 0x36, 9, 0, 0x61 },
  { "CMPA,-X", 0x36, 9, 0, 0x22 },
  { "CMPA,-Y", 0x36, 9, 0, 0x32 },
  { "CMPA,-U", 0x36, 9, 0, 0x52 },
  { "CMPA,-S", 0x36, 9, 0, 0x62 },
  { "CMPA,--X", 0x36, 9, 0, 0x23 },
  { "CMPA,--Y", 0x36, 9, 0, 0x33 },
  { "CMPA,--U", 0x36, 9, 0, 0x53 },
  { "CMPA,--S", 0x36, 9, 0, 0x63 },
  { "CMPA (,X)", 0x36, 9, 0, 0x2e },
  { "CMPA (,Y)", 0x36, 9, 0, 0x3e },
  { "CMPA (,U)", 0x36, 9, 0, 0x5e },
  { "CMPA (,S)", 0x36, 9, 0, 0x6e },
  { "CMPA (A,X)", 0x36, 9, 0, 0xa8 },
  { "CMPA (A,Y)", 0x36, 9, 0, 0xb8 },
  { "CMPA (A,U)", 0x36, 9, 0, 0xd8 },
  { "CMPA (A,S)", 0x36, 9, 0, 0xe8 },
  { "CMPA (B,X)", 0x36, 9, 0, 0xa9 },
  { "CMPA (B,Y)", 0x36, 9, 0, 0xb9 },
  { "CMPA (B,U)", 0x36, 9, 0, 0xd9 },
  { "CMPA (B,S)", 0x36, 9, 0, 0xe9 },
  { "CMPA (D,X)", 0x36, 9, 0, 0xaf },
  { "CMPA (D,Y)", 0x36, 9, 0, 0xbf },
  { "CMPA (D,U)", 0x36, 9, 0, 0xdf },
  { "CMPA (D,S)", 0x36, 9, 0, 0xef },
  { "CMPA (,X++)", 0x36, 9, 0, 0x29 },
  { "CMPA (,Y++)", 0x36, 9, 0, 0x39 },
  { "CMPA (,U++)", 0x36, 9, 0, 0x59 },
  { "CMPA (,S++)", 0x36, 9, 0, 0x69 },
  { "CMPA (,--X)", 0x36, 9, 0, 0x2b },
  { "CMPA (,--Y)", 0x36, 9, 0, 0x3b },
  { "CMPA (,--U)", 0x36, 9, 0, 0x5b },
  { "CMPA (,--S)", 0x36, 9, 0, 0x6b },
  { "CMPA (x,X)", 0x36, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPA (x,Y)", 0x36, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPA (x,U)", 0x36, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPA (x,S)", 0x36, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPA (?,X)", 0x36, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPA (?,Y)", 0x36, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPA (?,U)", 0x36, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPA (?,S)", 0x36, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPA (x,PCR)", 0x36, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPA (?,PCR)", 0x36, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPA (?)", 0x36, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPA s,X", 0x36, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPA s,Y", 0x36, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPA s,U", 0x36, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPA s,S", 0x36, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPA x,X", 0x36, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPA x,Y", 0x36, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPA x,U", 0x36, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPA x,S", 0x36, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPA ?,X", 0x36, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPA ?,Y", 0x36, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPA ?,U", 0x36, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPA ?,S", 0x36, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPA x,PCR", 0x36, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPA ?,PCR", 0x36, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPA x", 0x36, 2, 1, 0x07 },
  { "CMPA ?", 0x36, 2, 0, 0x07 },

  { "CMPB #x", 0x35, 1, 0, 0 },
  { "CMPB,X", 0x37, 9, 0, 0x26 },
  { "CMPB,Y", 0x37, 9, 0, 0x36 },
  { "CMPB,U", 0x37, 9, 0, 0x56 },
  { "CMPB,S", 0x37, 9, 0, 0x66 },
  { "CMPB A,X", 0x37, 9, 0, 0xa0 },
  { "CMPB A,Y", 0x37, 9, 0, 0xb0 },
  { "CMPB A,U", 0x37, 9, 0, 0xd0 },
  { "CMPB A,S", 0x37, 9, 0, 0xe0 },
  { "CMPB B,X", 0x37, 9, 0, 0xa1 },
  { "CMPB B,Y", 0x37, 9, 0, 0xb1 },
  { "CMPB B,U", 0x37, 9, 0, 0xd1 },
  { "CMPB B,S", 0x37, 9, 0, 0xe1 },
  { "CMPB D,X", 0x37, 9, 0, 0xa7 },
  { "CMPB D,Y", 0x37, 9, 0, 0xb7 },
  { "CMPB D,U", 0x37, 9, 0, 0xd7 },
  { "CMPB D,S", 0x37, 9, 0, 0xe8 },
  { "CMPB,X+", 0x37, 9, 0, 0x20 },
  { "CMPB,Y+", 0x37, 9, 0, 0x30 },
  { "CMPB,U+", 0x37, 9, 0, 0x50 },
  { "CMPB,S+", 0x37, 9, 0, 0x60 },
  { "CMPB,X++", 0x37, 9, 0, 0x21 },
  { "CMPB,Y++", 0x37, 9, 0, 0x31 },
  { "CMPB,U++", 0x37, 9, 0, 0x51 },
  { "CMPB,S++", 0x37, 9, 0, 0x61 },
  { "CMPB,-X", 0x37, 9, 0, 0x22 },
  { "CMPB,-Y", 0x37, 9, 0, 0x32 },
  { "CMPB,-U", 0x37, 9, 0, 0x52 },
  { "CMPB,-S", 0x37, 9, 0, 0x62 },
  { "CMPB,--X", 0x37, 9, 0, 0x23 },
  { "CMPB,--Y", 0x37, 9, 0, 0x33 },
  { "CMPB,--U", 0x37, 9, 0, 0x53 },
  { "CMPB,--S", 0x37, 9, 0, 0x63 },
  { "CMPB (,X)", 0x37, 9, 0, 0x2e },
  { "CMPB (,Y)", 0x37, 9, 0, 0x3e },
  { "CMPB (,U)", 0x37, 9, 0, 0x5e },
  { "CMPB (,S)", 0x37, 9, 0, 0x6e },
  { "CMPB (A,X)", 0x37, 9, 0, 0xa8 },
  { "CMPB (A,Y)", 0x37, 9, 0, 0xb8 },
  { "CMPB (A,U)", 0x37, 9, 0, 0xd8 },
  { "CMPB (A,S)", 0x37, 9, 0, 0xe8 },
  { "CMPB (B,X)", 0x37, 9, 0, 0xa9 },
  { "CMPB (B,Y)", 0x37, 9, 0, 0xb9 },
  { "CMPB (B,U)", 0x37, 9, 0, 0xd9 },
  { "CMPB (B,S)", 0x37, 9, 0, 0xe9 },
  { "CMPB (D,X)", 0x37, 9, 0, 0xaf },
  { "CMPB (D,Y)", 0x37, 9, 0, 0xbf },
  { "CMPB (D,U)", 0x37, 9, 0, 0xdf },
  { "CMPB (D,S)", 0x37, 9, 0, 0xef },
  { "CMPB (,X++)", 0x37, 9, 0, 0x29 },
  { "CMPB (,Y++)", 0x37, 9, 0, 0x39 },
  { "CMPB (,U++)", 0x37, 9, 0, 0x59 },
  { "CMPB (,S++)", 0x37, 9, 0, 0x69 },
  { "CMPB (,--X)", 0x37, 9, 0, 0x2b },
  { "CMPB (,--Y)", 0x37, 9, 0, 0x3b },
  { "CMPB (,--U)", 0x37, 9, 0, 0x5b },
  { "CMPB (,--S)", 0x37, 9, 0, 0x6b },
  { "CMPB (x,X)", 0x37, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPB (x,Y)", 0x37, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPB (x,U)", 0x37, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPB (x,S)", 0x37, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPB (?,X)", 0x37, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPB (?,Y)", 0x37, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPB (?,U)", 0x37, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPB (?,S)", 0x37, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPB (x,PCR)", 0x37, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPB (?,PCR)", 0x37, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPB (?)", 0x37, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPB s,X", 0x37, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPB s,Y", 0x37, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPB s,U", 0x37, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPB s,S", 0x37, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPB x,X", 0x37, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPB x,Y", 0x37, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPB x,U", 0x37, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPB x,S", 0x37, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPB ?,X", 0x37, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPB ?,Y", 0x37, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPB ?,U", 0x37, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPB ?,S", 0x37, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPB x,PCR", 0x37, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPB ?,PCR", 0x37, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPB x", 0x37, 2, 1, 0x07 },
  { "CMPB ?", 0x37, 2, 0, 0x07 },

  { "CMPX #x", 0x4c, 4, 0, 0 },
  { "CMPX,X", 0x4d, 9, 0, 0x26 },
  { "CMPX,Y", 0x4d, 9, 0, 0x36 },
  { "CMPX,U", 0x4d, 9, 0, 0x56 },
  { "CMPX,S", 0x4d, 9, 0, 0x66 },
  { "CMPX A,X", 0x4d, 9, 0, 0xa0 },
  { "CMPX A,Y", 0x4d, 9, 0, 0xb0 },
  { "CMPX A,U", 0x4d, 9, 0, 0xd0 },
  { "CMPX A,S", 0x4d, 9, 0, 0xe0 },
  { "CMPX B,X", 0x4d, 9, 0, 0xa1 },
  { "CMPX B,Y", 0x4d, 9, 0, 0xb1 },
  { "CMPX B,U", 0x4d, 9, 0, 0xd1 },
  { "CMPX B,S", 0x4d, 9, 0, 0xe1 },
  { "CMPX D,X", 0x4d, 9, 0, 0xa7 },
  { "CMPX D,Y", 0x4d, 9, 0, 0xb7 },
  { "CMPX D,U", 0x4d, 9, 0, 0xd7 },
  { "CMPX D,S", 0x4d, 9, 0, 0xe8 },
  { "CMPX,X+", 0x4d, 9, 0, 0x20 },
  { "CMPX,Y+", 0x4d, 9, 0, 0x30 },
  { "CMPX,U+", 0x4d, 9, 0, 0x50 },
  { "CMPX,S+", 0x4d, 9, 0, 0x60 },
  { "CMPX,X++", 0x4d, 9, 0, 0x21 },
  { "CMPX,Y++", 0x4d, 9, 0, 0x31 },
  { "CMPX,U++", 0x4d, 9, 0, 0x51 },
  { "CMPX,S++", 0x4d, 9, 0, 0x61 },
  { "CMPX,-X", 0x4d, 9, 0, 0x22 },
  { "CMPX,-Y", 0x4d, 9, 0, 0x32 },
  { "CMPX,-U", 0x4d, 9, 0, 0x52 },
  { "CMPX,-S", 0x4d, 9, 0, 0x62 },
  { "CMPX,--X", 0x4d, 9, 0, 0x23 },
  { "CMPX,--Y", 0x4d, 9, 0, 0x33 },
  { "CMPX,--U", 0x4d, 9, 0, 0x53 },
  { "CMPX,--S", 0x4d, 9, 0, 0x63 },
  { "CMPX (,X)", 0x4d, 9, 0, 0x2e },
  { "CMPX (,Y)", 0x4d, 9, 0, 0x3e },
  { "CMPX (,U)", 0x4d, 9, 0, 0x5e },
  { "CMPX (,S)", 0x4d, 9, 0, 0x6e },
  { "CMPX (A,X)", 0x4d, 9, 0, 0xa8 },
  { "CMPX (A,Y)", 0x4d, 9, 0, 0xb8 },
  { "CMPX (A,U)", 0x4d, 9, 0, 0xd8 },
  { "CMPX (A,S)", 0x4d, 9, 0, 0xe8 },
  { "CMPX (B,X)", 0x4d, 9, 0, 0xa9 },
  { "CMPX (B,Y)", 0x4d, 9, 0, 0xb9 },
  { "CMPX (B,U)", 0x4d, 9, 0, 0xd9 },
  { "CMPX (B,S)", 0x4d, 9, 0, 0xe9 },
  { "CMPX (D,X)", 0x4d, 9, 0, 0xaf },
  { "CMPX (D,Y)", 0x4d, 9, 0, 0xbf },
  { "CMPX (D,U)", 0x4d, 9, 0, 0xdf },
  { "CMPX (D,S)", 0x4d, 9, 0, 0xef },
  { "CMPX (,X++)", 0x4d, 9, 0, 0x29 },
  { "CMPX (,Y++)", 0x4d, 9, 0, 0x39 },
  { "CMPX (,U++)", 0x4d, 9, 0, 0x59 },
  { "CMPX (,S++)", 0x4d, 9, 0, 0x69 },
  { "CMPX (,--X)", 0x4d, 9, 0, 0x2b },
  { "CMPX (,--Y)", 0x4d, 9, 0, 0x3b },
  { "CMPX (,--U)", 0x4d, 9, 0, 0x5b },
  { "CMPX (,--S)", 0x4d, 9, 0, 0x6b },
  { "CMPX (x,X)", 0x4d, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPX (x,Y)", 0x4d, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPX (x,U)", 0x4d, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPX (x,S)", 0x4d, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPX (?,X)", 0x4d, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPX (?,Y)", 0x4d, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPX (?,U)", 0x4d, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPX (?,S)", 0x4d, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPX (x,PCR)", 0x4d, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPX (?,PCR)", 0x4d, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPX (?)", 0x4d, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPX s,X", 0x4d, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPX s,Y", 0x4d, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPX s,U", 0x4d, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPX s,S", 0x4d, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPX x,X", 0x4d, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPX x,Y", 0x4d, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPX x,U", 0x4d, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPX x,S", 0x4d, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPX ?,X", 0x4d, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPX ?,Y", 0x4d, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPX ?,U", 0x4d, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPX ?,S", 0x4d, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPX x,PCR", 0x4d, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPX ?,PCR", 0x4d, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPX x", 0x4d, 2, 1, 0x07 },
  { "CMPX ?", 0x4d, 2, 0, 0x07 },

  { "CMPD #x", 0x4a, 4, 0, 0 },
  { "CMPD,X", 0x4b, 9, 0, 0x26 },
  { "CMPD,Y", 0x4b, 9, 0, 0x36 },
  { "CMPD,U", 0x4b, 9, 0, 0x56 },
  { "CMPD,S", 0x4b, 9, 0, 0x66 },
  { "CMPD A,X", 0x4b, 9, 0, 0xa0 },
  { "CMPD A,Y", 0x4b, 9, 0, 0xb0 },
  { "CMPD A,U", 0x4b, 9, 0, 0xd0 },
  { "CMPD A,S", 0x4b, 9, 0, 0xe0 },
  { "CMPD B,X", 0x4b, 9, 0, 0xa1 },
  { "CMPD B,Y", 0x4b, 9, 0, 0xb1 },
  { "CMPD B,U", 0x4b, 9, 0, 0xd1 },
  { "CMPD B,S", 0x4b, 9, 0, 0xe1 },
  { "CMPD D,X", 0x4b, 9, 0, 0xa7 },
  { "CMPD D,Y", 0x4b, 9, 0, 0xb7 },
  { "CMPD D,U", 0x4b, 9, 0, 0xd7 },
  { "CMPD D,S", 0x4b, 9, 0, 0xe8 },
  { "CMPD,X+", 0x4b, 9, 0, 0x20 },
  { "CMPD,Y+", 0x4b, 9, 0, 0x30 },
  { "CMPD,U+", 0x4b, 9, 0, 0x50 },
  { "CMPD,S+", 0x4b, 9, 0, 0x60 },
  { "CMPD,X++", 0x4b, 9, 0, 0x21 },
  { "CMPD,Y++", 0x4b, 9, 0, 0x31 },
  { "CMPD,U++", 0x4b, 9, 0, 0x51 },
  { "CMPD,S++", 0x4b, 9, 0, 0x61 },
  { "CMPD,-X", 0x4b, 9, 0, 0x22 },
  { "CMPD,-Y", 0x4b, 9, 0, 0x32 },
  { "CMPD,-U", 0x4b, 9, 0, 0x52 },
  { "CMPD,-S", 0x4b, 9, 0, 0x62 },
  { "CMPD,--X", 0x4b, 9, 0, 0x23 },
  { "CMPD,--Y", 0x4b, 9, 0, 0x33 },
  { "CMPD,--U", 0x4b, 9, 0, 0x53 },
  { "CMPD,--S", 0x4b, 9, 0, 0x63 },
  { "CMPD (,X)", 0x4b, 9, 0, 0x2e },
  { "CMPD (,Y)", 0x4b, 9, 0, 0x3e },
  { "CMPD (,U)", 0x4b, 9, 0, 0x5e },
  { "CMPD (,S)", 0x4b, 9, 0, 0x6e },
  { "CMPD (A,X)", 0x4b, 9, 0, 0xa8 },
  { "CMPD (A,Y)", 0x4b, 9, 0, 0xb8 },
  { "CMPD (A,U)", 0x4b, 9, 0, 0xd8 },
  { "CMPD (A,S)", 0x4b, 9, 0, 0xe8 },
  { "CMPD (B,X)", 0x4b, 9, 0, 0xa9 },
  { "CMPD (B,Y)", 0x4b, 9, 0, 0xb9 },
  { "CMPD (B,U)", 0x4b, 9, 0, 0xd9 },
  { "CMPD (B,S)", 0x4b, 9, 0, 0xe9 },
  { "CMPD (D,X)", 0x4b, 9, 0, 0xaf },
  { "CMPD (D,Y)", 0x4b, 9, 0, 0xbf },
  { "CMPD (D,U)", 0x4b, 9, 0, 0xdf },
  { "CMPD (D,S)", 0x4b, 9, 0, 0xef },
  { "CMPD (,X++)", 0x4b, 9, 0, 0x29 },
  { "CMPD (,Y++)", 0x4b, 9, 0, 0x39 },
  { "CMPD (,U++)", 0x4b, 9, 0, 0x59 },
  { "CMPD (,S++)", 0x4b, 9, 0, 0x69 },
  { "CMPD (,--X)", 0x4b, 9, 0, 0x2b },
  { "CMPD (,--Y)", 0x4b, 9, 0, 0x3b },
  { "CMPD (,--U)", 0x4b, 9, 0, 0x5b },
  { "CMPD (,--S)", 0x4b, 9, 0, 0x6b },
  { "CMPD (x,X)", 0x4b, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPD (x,Y)", 0x4b, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPD (x,U)", 0x4b, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPD (x,S)", 0x4b, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPD (?,X)", 0x4b, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPD (?,Y)", 0x4b, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPD (?,U)", 0x4b, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPD (?,S)", 0x4b, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPD (x,PCR)", 0x4b, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPD (?,PCR)", 0x4b, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPD (?)", 0x4b, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPD s,X", 0x4b, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPD s,Y", 0x4b, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPD s,U", 0x4b, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPD s,S", 0x4b, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPD x,X", 0x4b, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPD x,Y", 0x4b, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPD x,U", 0x4b, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPD x,S", 0x4b, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPD ?,X", 0x4b, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPD ?,Y", 0x4b, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPD ?,U", 0x4b, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPD ?,S", 0x4b, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPD x,PCR", 0x4b, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPD ?,PCR", 0x4b, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPD x", 0x4b, 2, 1, 0x07 },
  { "CMPD ?", 0x4b, 2, 0, 0x07 },

  { "CMPS #x", 0x52, 4, 0, 0 },
  { "CMPS,X", 0x53, 9, 0, 0x26 },
  { "CMPS,Y", 0x53, 9, 0, 0x36 },
  { "CMPS,U", 0x53, 9, 0, 0x56 },
  { "CMPS,S", 0x53, 9, 0, 0x66 },
  { "CMPS A,X", 0x53, 9, 0, 0xa0 },
  { "CMPS A,Y", 0x53, 9, 0, 0xb0 },
  { "CMPS A,U", 0x53, 9, 0, 0xd0 },
  { "CMPS A,S", 0x53, 9, 0, 0xe0 },
  { "CMPS B,X", 0x53, 9, 0, 0xa1 },
  { "CMPS B,Y", 0x53, 9, 0, 0xb1 },
  { "CMPS B,U", 0x53, 9, 0, 0xd1 },
  { "CMPS B,S", 0x53, 9, 0, 0xe1 },
  { "CMPS D,X", 0x53, 9, 0, 0xa7 },
  { "CMPS D,Y", 0x53, 9, 0, 0xb7 },
  { "CMPS D,U", 0x53, 9, 0, 0xd7 },
  { "CMPS D,S", 0x53, 9, 0, 0xe8 },
  { "CMPS,X+", 0x53, 9, 0, 0x20 },
  { "CMPS,Y+", 0x53, 9, 0, 0x30 },
  { "CMPS,U+", 0x53, 9, 0, 0x50 },
  { "CMPS,S+", 0x53, 9, 0, 0x60 },
  { "CMPS,X++", 0x53, 9, 0, 0x21 },
  { "CMPS,Y++", 0x53, 9, 0, 0x31 },
  { "CMPS,U++", 0x53, 9, 0, 0x51 },
  { "CMPS,S++", 0x53, 9, 0, 0x61 },
  { "CMPS,-X", 0x53, 9, 0, 0x22 },
  { "CMPS,-Y", 0x53, 9, 0, 0x32 },
  { "CMPS,-U", 0x53, 9, 0, 0x52 },
  { "CMPS,-S", 0x53, 9, 0, 0x62 },
  { "CMPS,--X", 0x53, 9, 0, 0x23 },
  { "CMPS,--Y", 0x53, 9, 0, 0x33 },
  { "CMPS,--U", 0x53, 9, 0, 0x53 },
  { "CMPS,--S", 0x53, 9, 0, 0x63 },
  { "CMPS (,X)", 0x53, 9, 0, 0x2e },
  { "CMPS (,Y)", 0x53, 9, 0, 0x3e },
  { "CMPS (,U)", 0x53, 9, 0, 0x5e },
  { "CMPS (,S)", 0x53, 9, 0, 0x6e },
  { "CMPS (A,X)", 0x53, 9, 0, 0xa8 },
  { "CMPS (A,Y)", 0x53, 9, 0, 0xb8 },
  { "CMPS (A,U)", 0x53, 9, 0, 0xd8 },
  { "CMPS (A,S)", 0x53, 9, 0, 0xe8 },
  { "CMPS (B,X)", 0x53, 9, 0, 0xa9 },
  { "CMPS (B,Y)", 0x53, 9, 0, 0xb9 },
  { "CMPS (B,U)", 0x53, 9, 0, 0xd9 },
  { "CMPS (B,S)", 0x53, 9, 0, 0xe9 },
  { "CMPS (D,X)", 0x53, 9, 0, 0xaf },
  { "CMPS (D,Y)", 0x53, 9, 0, 0xbf },
  { "CMPS (D,U)", 0x53, 9, 0, 0xdf },
  { "CMPS (D,S)", 0x53, 9, 0, 0xef },
  { "CMPS (,X++)", 0x53, 9, 0, 0x29 },
  { "CMPS (,Y++)", 0x53, 9, 0, 0x39 },
  { "CMPS (,U++)", 0x53, 9, 0, 0x59 },
  { "CMPS (,S++)", 0x53, 9, 0, 0x69 },
  { "CMPS (,--X)", 0x53, 9, 0, 0x2b },
  { "CMPS (,--Y)", 0x53, 9, 0, 0x3b },
  { "CMPS (,--U)", 0x53, 9, 0, 0x5b },
  { "CMPS (,--S)", 0x53, 9, 0, 0x6b },
  { "CMPS (x,X)", 0x53, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPS (x,Y)", 0x53, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPS (x,U)", 0x53, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPS (x,S)", 0x53, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPS (?,X)", 0x53, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPS (?,Y)", 0x53, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPS (?,U)", 0x53, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPS (?,S)", 0x53, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPS (x,PCR)", 0x53, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPS (?,PCR)", 0x53, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPS (?)", 0x53, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPS s,X", 0x53, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPS s,Y", 0x53, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPS s,U", 0x53, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPS s,S", 0x53, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPS x,X", 0x53, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPS x,Y", 0x53, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPS x,U", 0x53, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPS x,S", 0x53, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPS ?,X", 0x53, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPS ?,Y", 0x53, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPS ?,U", 0x53, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPS ?,S", 0x53, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPS x,PCR", 0x53, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPS ?,PCR", 0x53, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPS x", 0x53, 2, 1, 0x07 },
  { "CMPS ?", 0x53, 2, 0, 0x07 },

  { "CMPU #x", 0x50, 4, 0, 0 },
  { "CMPU,X", 0x51, 9, 0, 0x26 },
  { "CMPU,Y", 0x51, 9, 0, 0x36 },
  { "CMPU,U", 0x51, 9, 0, 0x56 },
  { "CMPU,S", 0x51, 9, 0, 0x66 },
  { "CMPU A,X", 0x51, 9, 0, 0xa0 },
  { "CMPU A,Y", 0x51, 9, 0, 0xb0 },
  { "CMPU A,U", 0x51, 9, 0, 0xd0 },
  { "CMPU A,S", 0x51, 9, 0, 0xe0 },
  { "CMPU B,X", 0x51, 9, 0, 0xa1 },
  { "CMPU B,Y", 0x51, 9, 0, 0xb1 },
  { "CMPU B,U", 0x51, 9, 0, 0xd1 },
  { "CMPU B,S", 0x51, 9, 0, 0xe1 },
  { "CMPU D,X", 0x51, 9, 0, 0xa7 },
  { "CMPU D,Y", 0x51, 9, 0, 0xb7 },
  { "CMPU D,U", 0x51, 9, 0, 0xd7 },
  { "CMPU D,S", 0x51, 9, 0, 0xe8 },
  { "CMPU,X+", 0x51, 9, 0, 0x20 },
  { "CMPU,Y+", 0x51, 9, 0, 0x30 },
  { "CMPU,U+", 0x51, 9, 0, 0x50 },
  { "CMPU,S+", 0x51, 9, 0, 0x60 },
  { "CMPU,X++", 0x51, 9, 0, 0x21 },
  { "CMPU,Y++", 0x51, 9, 0, 0x31 },
  { "CMPU,U++", 0x51, 9, 0, 0x51 },
  { "CMPU,S++", 0x51, 9, 0, 0x61 },
  { "CMPU,-X", 0x51, 9, 0, 0x22 },
  { "CMPU,-Y", 0x51, 9, 0, 0x32 },
  { "CMPU,-U", 0x51, 9, 0, 0x52 },
  { "CMPU,-S", 0x51, 9, 0, 0x62 },
  { "CMPU,--X", 0x51, 9, 0, 0x23 },
  { "CMPU,--Y", 0x51, 9, 0, 0x33 },
  { "CMPU,--U", 0x51, 9, 0, 0x53 },
  { "CMPU,--S", 0x51, 9, 0, 0x63 },
  { "CMPU (,X)", 0x51, 9, 0, 0x2e },
  { "CMPU (,Y)", 0x51, 9, 0, 0x3e },
  { "CMPU (,U)", 0x51, 9, 0, 0x5e },
  { "CMPU (,S)", 0x51, 9, 0, 0x6e },
  { "CMPU (A,X)", 0x51, 9, 0, 0xa8 },
  { "CMPU (A,Y)", 0x51, 9, 0, 0xb8 },
  { "CMPU (A,U)", 0x51, 9, 0, 0xd8 },
  { "CMPU (A,S)", 0x51, 9, 0, 0xe8 },
  { "CMPU (B,X)", 0x51, 9, 0, 0xa9 },
  { "CMPU (B,Y)", 0x51, 9, 0, 0xb9 },
  { "CMPU (B,U)", 0x51, 9, 0, 0xd9 },
  { "CMPU (B,S)", 0x51, 9, 0, 0xe9 },
  { "CMPU (D,X)", 0x51, 9, 0, 0xaf },
  { "CMPU (D,Y)", 0x51, 9, 0, 0xbf },
  { "CMPU (D,U)", 0x51, 9, 0, 0xdf },
  { "CMPU (D,S)", 0x51, 9, 0, 0xef },
  { "CMPU (,X++)", 0x51, 9, 0, 0x29 },
  { "CMPU (,Y++)", 0x51, 9, 0, 0x39 },
  { "CMPU (,U++)", 0x51, 9, 0, 0x59 },
  { "CMPU (,S++)", 0x51, 9, 0, 0x69 },
  { "CMPU (,--X)", 0x51, 9, 0, 0x2b },
  { "CMPU (,--Y)", 0x51, 9, 0, 0x3b },
  { "CMPU (,--U)", 0x51, 9, 0, 0x5b },
  { "CMPU (,--S)", 0x51, 9, 0, 0x6b },
  { "CMPU (x,X)", 0x51, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPU (x,Y)", 0x51, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPU (x,U)", 0x51, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPU (x,S)", 0x51, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPU (?,X)", 0x51, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPU (?,Y)", 0x51, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPU (?,U)", 0x51, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPU (?,S)", 0x51, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPU (x,PCR)", 0x51, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPU (?,PCR)", 0x51, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPU (?)", 0x51, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPU s,X", 0x51, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPU s,Y", 0x51, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPU s,U", 0x51, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPU s,S", 0x51, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPU x,X", 0x51, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPU x,Y", 0x51, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPU x,U", 0x51, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPU x,S", 0x51, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPU ?,X", 0x51, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPU ?,Y", 0x51, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPU ?,U", 0x51, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPU ?,S", 0x51, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPU x,PCR", 0x51, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPU ?,PCR", 0x51, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPU x", 0x51, 2, 1, 0x07 },
  { "CMPU ?", 0x51, 2, 0, 0x07 },

  { "CMPY #x", 0x4e, 4, 0, 0 },
  { "CMPY,X", 0x4f, 9, 0, 0x26 },
  { "CMPY,Y", 0x4f, 9, 0, 0x36 },
  { "CMPY,U", 0x4f, 9, 0, 0x56 },
  { "CMPY,S", 0x4f, 9, 0, 0x66 },
  { "CMPY A,X", 0x4f, 9, 0, 0xa0 },
  { "CMPY A,Y", 0x4f, 9, 0, 0xb0 },
  { "CMPY A,U", 0x4f, 9, 0, 0xd0 },
  { "CMPY A,S", 0x4f, 9, 0, 0xe0 },
  { "CMPY B,X", 0x4f, 9, 0, 0xa1 },
  { "CMPY B,Y", 0x4f, 9, 0, 0xb1 },
  { "CMPY B,U", 0x4f, 9, 0, 0xd1 },
  { "CMPY B,S", 0x4f, 9, 0, 0xe1 },
  { "CMPY D,X", 0x4f, 9, 0, 0xa7 },
  { "CMPY D,Y", 0x4f, 9, 0, 0xb7 },
  { "CMPY D,U", 0x4f, 9, 0, 0xd7 },
  { "CMPY D,S", 0x4f, 9, 0, 0xe8 },
  { "CMPY,X+", 0x4f, 9, 0, 0x20 },
  { "CMPY,Y+", 0x4f, 9, 0, 0x30 },
  { "CMPY,U+", 0x4f, 9, 0, 0x50 },
  { "CMPY,S+", 0x4f, 9, 0, 0x60 },
  { "CMPY,X++", 0x4f, 9, 0, 0x21 },
  { "CMPY,Y++", 0x4f, 9, 0, 0x31 },
  { "CMPY,U++", 0x4f, 9, 0, 0x51 },
  { "CMPY,S++", 0x4f, 9, 0, 0x61 },
  { "CMPY,-X", 0x4f, 9, 0, 0x22 },
  { "CMPY,-Y", 0x4f, 9, 0, 0x32 },
  { "CMPY,-U", 0x4f, 9, 0, 0x52 },
  { "CMPY,-S", 0x4f, 9, 0, 0x62 },
  { "CMPY,--X", 0x4f, 9, 0, 0x23 },
  { "CMPY,--Y", 0x4f, 9, 0, 0x33 },
  { "CMPY,--U", 0x4f, 9, 0, 0x53 },
  { "CMPY,--S", 0x4f, 9, 0, 0x63 },
  { "CMPY (,X)", 0x4f, 9, 0, 0x2e },
  { "CMPY (,Y)", 0x4f, 9, 0, 0x3e },
  { "CMPY (,U)", 0x4f, 9, 0, 0x5e },
  { "CMPY (,S)", 0x4f, 9, 0, 0x6e },
  { "CMPY (A,X)", 0x4f, 9, 0, 0xa8 },
  { "CMPY (A,Y)", 0x4f, 9, 0, 0xb8 },
  { "CMPY (A,U)", 0x4f, 9, 0, 0xd8 },
  { "CMPY (A,S)", 0x4f, 9, 0, 0xe8 },
  { "CMPY (B,X)", 0x4f, 9, 0, 0xa9 },
  { "CMPY (B,Y)", 0x4f, 9, 0, 0xb9 },
  { "CMPY (B,U)", 0x4f, 9, 0, 0xd9 },
  { "CMPY (B,S)", 0x4f, 9, 0, 0xe9 },
  { "CMPY (D,X)", 0x4f, 9, 0, 0xaf },
  { "CMPY (D,Y)", 0x4f, 9, 0, 0xbf },
  { "CMPY (D,U)", 0x4f, 9, 0, 0xdf },
  { "CMPY (D,S)", 0x4f, 9, 0, 0xef },
  { "CMPY (,X++)", 0x4f, 9, 0, 0x29 },
  { "CMPY (,Y++)", 0x4f, 9, 0, 0x39 },
  { "CMPY (,U++)", 0x4f, 9, 0, 0x59 },
  { "CMPY (,S++)", 0x4f, 9, 0, 0x69 },
  { "CMPY (,--X)", 0x4f, 9, 0, 0x2b },
  { "CMPY (,--Y)", 0x4f, 9, 0, 0x3b },
  { "CMPY (,--U)", 0x4f, 9, 0, 0x5b },
  { "CMPY (,--S)", 0x4f, 9, 0, 0x6b },
  { "CMPY (x,X)", 0x4f, 7, 1, 0x2c }, /* 8-bit offset */
  { "CMPY (x,Y)", 0x4f, 7, 1, 0x3c }, /* 8-bit offset */
  { "CMPY (x,U)", 0x4f, 7, 1, 0x5c }, /* 8-bit offset */
  { "CMPY (x,S)", 0x4f, 7, 1, 0x6c }, /* 8-bit offset */
  { "CMPY (?,X)", 0x4f, 8, 0, 0x2d }, /* 16-bit offset */
  { "CMPY (?,Y)", 0x4f, 8, 0, 0x3d }, /* 16-bit offset */
  { "CMPY (?,U)", 0x4f, 8, 0, 0x5d }, /* 16-bit offset */
  { "CMPY (?,S)", 0x4f, 8, 0, 0x6d }, /* 16-bit offset */
  { "CMPY (x,PCR)", 0x4f, 7, 1, 0x7c }, /* 8-bit offset */
  { "CMPY (?,PCR)", 0x4f, 8, 0, 0x7d }, /* 16-bit offset */
  { "CMPY (?)", 0x4f, 8, 0, 0x0f }, /* 16-bit offset */
  { "CMPY s,X", 0x4f, 6, 1, 0x26 }, /* 5-bit offset */
  { "CMPY s,Y", 0x4f, 6, 1, 0x36 }, /* 5-bit offset */
  { "CMPY s,U", 0x4f, 6, 1, 0x56 }, /* 5-bit offset */
  { "CMPY s,S", 0x4f, 6, 1, 0x66 }, /* 5-bit offset */
  { "CMPY x,X", 0x4f, 7, 1, 0x24 }, /* 8-bit offset */
  { "CMPY x,Y", 0x4f, 7, 1, 0x34 }, /* 8-bit offset */
  { "CMPY x,U", 0x4f, 7, 1, 0x54 }, /* 8-bit offset */
  { "CMPY x,S", 0x4f, 7, 1, 0x64 }, /* 8-bit offset */
  { "CMPY ?,X", 0x4f, 8, 0, 0x25 }, /* 16-bit offset */
  { "CMPY ?,Y", 0x4f, 8, 0, 0x35 }, /* 16-bit offset */
  { "CMPY ?,U", 0x4f, 8, 0, 0x55 }, /* 16-bit offset */
  { "CMPY ?,S", 0x4f, 8, 0, 0x65 }, /* 16-bit offset */
  { "CMPY x,PCR", 0x4f, 7, 1, 0x74 }, /* 8-bit offset */
  { "CMPY ?,PCR", 0x4f, 8, 0, 0x75 }, /* 16-bit offset */
  { "CMPY x", 0x4f, 2, 1, 0x07 },
  { "CMPY ?", 0x4f, 2, 0, 0x07 },

  { "COMA", 0x83, 0, 0, 0 },
  { "COMB", 0x84, 0, 0, 0 },
  { "COM,X", 0x85, 9, 0, 0x26 },
  { "COM,Y", 0x85, 9, 0, 0x36 },
  { "COM,U", 0x85, 9, 0, 0x56 },
  { "COM,S", 0x85, 9, 0, 0x66 },
  { "COM A,X", 0x85, 9, 0, 0xa0 },
  { "COM A,Y", 0x85, 9, 0, 0xb0 },
  { "COM A,U", 0x85, 9, 0, 0xd0 },
  { "COM A,S", 0x85, 9, 0, 0xe0 },
  { "COM B,X", 0x85, 9, 0, 0xa1 },
  { "COM B,Y", 0x85, 9, 0, 0xb1 },
  { "COM B,U", 0x85, 9, 0, 0xd1 },
  { "COM B,S", 0x85, 9, 0, 0xe1 },
  { "COM D,X", 0x85, 9, 0, 0xa7 },
  { "COM D,Y", 0x85, 9, 0, 0xb7 },
  { "COM D,U", 0x85, 9, 0, 0xd7 },
  { "COM D,S", 0x85, 9, 0, 0xe8 },
  { "COM,X+", 0x85, 9, 0, 0x20 },
  { "COM,Y+", 0x85, 9, 0, 0x30 },
  { "COM,U+", 0x85, 9, 0, 0x50 },
  { "COM,S+", 0x85, 9, 0, 0x60 },
  { "COM,X++", 0x85, 9, 0, 0x21 },
  { "COM,Y++", 0x85, 9, 0, 0x31 },
  { "COM,U++", 0x85, 9, 0, 0x51 },
  { "COM,S++", 0x85, 9, 0, 0x61 },
  { "COM,-X", 0x85, 9, 0, 0x22 },
  { "COM,-Y", 0x85, 9, 0, 0x32 },
  { "COM,-U", 0x85, 9, 0, 0x52 },
  { "COM,-S", 0x85, 9, 0, 0x62 },
  { "COM,--X", 0x85, 9, 0, 0x23 },
  { "COM,--Y", 0x85, 9, 0, 0x33 },
  { "COM,--U", 0x85, 9, 0, 0x53 },
  { "COM,--S", 0x85, 9, 0, 0x63 },
  { "COM (,X)", 0x85, 9, 0, 0x2e },
  { "COM (,Y)", 0x85, 9, 0, 0x3e },
  { "COM (,U)", 0x85, 9, 0, 0x5e },
  { "COM (,S)", 0x85, 9, 0, 0x6e },
  { "COM (A,X)", 0x85, 9, 0, 0xa8 },
  { "COM (A,Y)", 0x85, 9, 0, 0xb8 },
  { "COM (A,U)", 0x85, 9, 0, 0xd8 },
  { "COM (A,S)", 0x85, 9, 0, 0xe8 },
  { "COM (B,X)", 0x85, 9, 0, 0xa9 },
  { "COM (B,Y)", 0x85, 9, 0, 0xb9 },
  { "COM (B,U)", 0x85, 9, 0, 0xd9 },
  { "COM (B,S)", 0x85, 9, 0, 0xe9 },
  { "COM (D,X)", 0x85, 9, 0, 0xaf },
  { "COM (D,Y)", 0x85, 9, 0, 0xbf },
  { "COM (D,U)", 0x85, 9, 0, 0xdf },
  { "COM (D,S)", 0x85, 9, 0, 0xef },
  { "COM (,X++)", 0x85, 9, 0, 0x29 },
  { "COM (,Y++)", 0x85, 9, 0, 0x39 },
  { "COM (,U++)", 0x85, 9, 0, 0x59 },
  { "COM (,S++)", 0x85, 9, 0, 0x69 },
  { "COM (,--X)", 0x85, 9, 0, 0x2b },
  { "COM (,--Y)", 0x85, 9, 0, 0x3b },
  { "COM (,--U)", 0x85, 9, 0, 0x5b },
  { "COM (,--S)", 0x85, 9, 0, 0x6b },
  { "COM (x,X)", 0x85, 7, 1, 0x2c }, /* 8-bit offset */
  { "COM (x,Y)", 0x85, 7, 1, 0x3c }, /* 8-bit offset */
  { "COM (x,U)", 0x85, 7, 1, 0x5c }, /* 8-bit offset */
  { "COM (x,S)", 0x85, 7, 1, 0x6c }, /* 8-bit offset */
  { "COM (?,X)", 0x85, 8, 0, 0x2d }, /* 16-bit offset */
  { "COM (?,Y)", 0x85, 8, 0, 0x3d }, /* 16-bit offset */
  { "COM (?,U)", 0x85, 8, 0, 0x5d }, /* 16-bit offset */
  { "COM (?,S)", 0x85, 8, 0, 0x6d }, /* 16-bit offset */
  { "COM (x,PCR)", 0x85, 7, 1, 0x7c }, /* 8-bit offset */
  { "COM (?,PCR)", 0x85, 8, 0, 0x7d }, /* 16-bit offset */
  { "COM (?)", 0x85, 8, 0, 0x0f }, /* 16-bit offset */
  { "COM s,X", 0x85, 6, 1, 0x26 }, /* 5-bit offset */
  { "COM s,Y", 0x85, 6, 1, 0x36 }, /* 5-bit offset */
  { "COM s,U", 0x85, 6, 1, 0x56 }, /* 5-bit offset */
  { "COM s,S", 0x85, 6, 1, 0x66 }, /* 5-bit offset */
  { "COM x,X", 0x85, 7, 1, 0x24 }, /* 8-bit offset */
  { "COM x,Y", 0x85, 7, 1, 0x34 }, /* 8-bit offset */
  { "COM x,U", 0x85, 7, 1, 0x54 }, /* 8-bit offset */
  { "COM x,S", 0x85, 7, 1, 0x64 }, /* 8-bit offset */
  { "COM ?,X", 0x85, 8, 0, 0x25 }, /* 16-bit offset */
  { "COM ?,Y", 0x85, 8, 0, 0x35 }, /* 16-bit offset */
  { "COM ?,U", 0x85, 8, 0, 0x55 }, /* 16-bit offset */
  { "COM ?,S", 0x85, 8, 0, 0x65 }, /* 16-bit offset */
  { "COM x,PCR", 0x85, 7, 1, 0x74 }, /* 8-bit offset */
  { "COM ?,PCR", 0x85, 8, 0, 0x75 }, /* 16-bit offset */
  { "COM x", 0x85, 2, 1, 0x07 },
  { "COM ?", 0x85, 2, 0, 0x07 },

/*{ "CWAI #x", 0x3C, 1, 0, 0 }, */

  { "DAA", 0xb1, 0, 0, 0 },

  { "DECA", 0x8c, 0, 0, 0 },
  { "DECB", 0x8d, 0, 0, 0 },
  { "DEC,X", 0x8e, 9, 0, 0x26 },
  { "DEC,Y", 0x8e, 9, 0, 0x36 },
  { "DEC,U", 0x8e, 9, 0, 0x56 },
  { "DEC,S", 0x8e, 9, 0, 0x66 },
  { "DEC A,X", 0x8e, 9, 0, 0xa0 },
  { "DEC A,Y", 0x8e, 9, 0, 0xb0 },
  { "DEC A,U", 0x8e, 9, 0, 0xd0 },
  { "DEC A,S", 0x8e, 9, 0, 0xe0 },
  { "DEC B,X", 0x8e, 9, 0, 0xa1 },
  { "DEC B,Y", 0x8e, 9, 0, 0xb1 },
  { "DEC B,U", 0x8e, 9, 0, 0xd1 },
  { "DEC B,S", 0x8e, 9, 0, 0xe1 },
  { "DEC D,X", 0x8e, 9, 0, 0xa7 },
  { "DEC D,Y", 0x8e, 9, 0, 0xb7 },
  { "DEC D,U", 0x8e, 9, 0, 0xd7 },
  { "DEC D,S", 0x8e, 9, 0, 0xe8 },
  { "DEC,X+", 0x8e, 9, 0, 0x20 },
  { "DEC,Y+", 0x8e, 9, 0, 0x30 },
  { "DEC,U+", 0x8e, 9, 0, 0x50 },
  { "DEC,S+", 0x8e, 9, 0, 0x60 },
  { "DEC,X++", 0x8e, 9, 0, 0x21 },
  { "DEC,Y++", 0x8e, 9, 0, 0x31 },
  { "DEC,U++", 0x8e, 9, 0, 0x51 },
  { "DEC,S++", 0x8e, 9, 0, 0x61 },
  { "DEC,-X", 0x8e, 9, 0, 0x22 },
  { "DEC,-Y", 0x8e, 9, 0, 0x32 },
  { "DEC,-U", 0x8e, 9, 0, 0x52 },
  { "DEC,-S", 0x8e, 9, 0, 0x62 },
  { "DEC,--X", 0x8e, 9, 0, 0x23 },
  { "DEC,--Y", 0x8e, 9, 0, 0x33 },
  { "DEC,--U", 0x8e, 9, 0, 0x53 },
  { "DEC,--S", 0x8e, 9, 0, 0x63 },
  { "DEC (,X)", 0x8e, 9, 0, 0x2e },
  { "DEC (,Y)", 0x8e, 9, 0, 0x3e },
  { "DEC (,U)", 0x8e, 9, 0, 0x5e },
  { "DEC (,S)", 0x8e, 9, 0, 0x6e },
  { "DEC (A,X)", 0x8e, 9, 0, 0xa8 },
  { "DEC (A,Y)", 0x8e, 9, 0, 0xb8 },
  { "DEC (A,U)", 0x8e, 9, 0, 0xd8 },
  { "DEC (A,S)", 0x8e, 9, 0, 0xe8 },
  { "DEC (B,X)", 0x8e, 9, 0, 0xa9 },
  { "DEC (B,Y)", 0x8e, 9, 0, 0xb9 },
  { "DEC (B,U)", 0x8e, 9, 0, 0xd9 },
  { "DEC (B,S)", 0x8e, 9, 0, 0xe9 },
  { "DEC (D,X)", 0x8e, 9, 0, 0xaf },
  { "DEC (D,Y)", 0x8e, 9, 0, 0xbf },
  { "DEC (D,U)", 0x8e, 9, 0, 0xdf },
  { "DEC (D,S)", 0x8e, 9, 0, 0xef },
  { "DEC (,X++)", 0x8e, 9, 0, 0x29 },
  { "DEC (,Y++)", 0x8e, 9, 0, 0x39 },
  { "DEC (,U++)", 0x8e, 9, 0, 0x59 },
  { "DEC (,S++)", 0x8e, 9, 0, 0x69 },
  { "DEC (,--X)", 0x8e, 9, 0, 0x2b },
  { "DEC (,--Y)", 0x8e, 9, 0, 0x3b },
  { "DEC (,--U)", 0x8e, 9, 0, 0x5b },
  { "DEC (,--S)", 0x8e, 9, 0, 0x6b },
  { "DEC (x,X)", 0x8e, 7, 1, 0x2c }, /* 8-bit offset */
  { "DEC (x,Y)", 0x8e, 7, 1, 0x3c }, /* 8-bit offset */
  { "DEC (x,U)", 0x8e, 7, 1, 0x5c }, /* 8-bit offset */
  { "DEC (x,S)", 0x8e, 7, 1, 0x6c }, /* 8-bit offset */
  { "DEC (?,X)", 0x8e, 8, 0, 0x2d }, /* 16-bit offset */
  { "DEC (?,Y)", 0x8e, 8, 0, 0x3d }, /* 16-bit offset */
  { "DEC (?,U)", 0x8e, 8, 0, 0x5d }, /* 16-bit offset */
  { "DEC (?,S)", 0x8e, 8, 0, 0x6d }, /* 16-bit offset */
  { "DEC (x,PCR)", 0x8e, 7, 1, 0x7c }, /* 8-bit offset */
  { "DEC (?,PCR)", 0x8e, 8, 0, 0x7d }, /* 16-bit offset */
  { "DEC (?)", 0x8e, 8, 0, 0x0f }, /* 16-bit offset */
  { "DEC s,X", 0x8e, 6, 1, 0x26 }, /* 5-bit offset */
  { "DEC s,Y", 0x8e, 6, 1, 0x36 }, /* 5-bit offset */
  { "DEC s,U", 0x8e, 6, 1, 0x56 }, /* 5-bit offset */
  { "DEC s,S", 0x8e, 6, 1, 0x66 }, /* 5-bit offset */
  { "DEC x,X", 0x8e, 7, 1, 0x24 }, /* 8-bit offset */
  { "DEC x,Y", 0x8e, 7, 1, 0x34 }, /* 8-bit offset */
  { "DEC x,U", 0x8e, 7, 1, 0x54 }, /* 8-bit offset */
  { "DEC x,S", 0x8e, 7, 1, 0x64 }, /* 8-bit offset */
  { "DEC ?,X", 0x8e, 8, 0, 0x25 }, /* 16-bit offset */
  { "DEC ?,Y", 0x8e, 8, 0, 0x35 }, /* 16-bit offset */
  { "DEC ?,U", 0x8e, 8, 0, 0x55 }, /* 16-bit offset */
  { "DEC ?,S", 0x8e, 8, 0, 0x65 }, /* 16-bit offset */
  { "DEC x,PCR", 0x8e, 7, 1, 0x74 }, /* 8-bit offset */
  { "DEC ?,PCR", 0x8e, 8, 0, 0x75 }, /* 16-bit offset */
  { "DEC x", 0x8e, 2, 1, 0x07 },
  { "DEC ?", 0x8e, 2, 0, 0x07 },

  { "EORA #x", 0x2c, 1, 0, 0 },
  { "EORA,X", 0x2e, 9, 0, 0x26 },
  { "EORA,Y", 0x2e, 9, 0, 0x36 },
  { "EORA,U", 0x2e, 9, 0, 0x56 },
  { "EORA,S", 0x2e, 9, 0, 0x66 },
  { "EORA A,X", 0x2e, 9, 0, 0xa0 },
  { "EORA A,Y", 0x2e, 9, 0, 0xb0 },
  { "EORA A,U", 0x2e, 9, 0, 0xd0 },
  { "EORA A,S", 0x2e, 9, 0, 0xe0 },
  { "EORA B,X", 0x2e, 9, 0, 0xa1 },
  { "EORA B,Y", 0x2e, 9, 0, 0xb1 },
  { "EORA B,U", 0x2e, 9, 0, 0xd1 },
  { "EORA B,S", 0x2e, 9, 0, 0xe1 },
  { "EORA D,X", 0x2e, 9, 0, 0xa7 },
  { "EORA D,Y", 0x2e, 9, 0, 0xb7 },
  { "EORA D,U", 0x2e, 9, 0, 0xd7 },
  { "EORA D,S", 0x2e, 9, 0, 0xe8 },
  { "EORA,X+", 0x2e, 9, 0, 0x20 },
  { "EORA,Y+", 0x2e, 9, 0, 0x30 },
  { "EORA,U+", 0x2e, 9, 0, 0x50 },
  { "EORA,S+", 0x2e, 9, 0, 0x60 },
  { "EORA,X++", 0x2e, 9, 0, 0x21 },
  { "EORA,Y++", 0x2e, 9, 0, 0x31 },
  { "EORA,U++", 0x2e, 9, 0, 0x51 },
  { "EORA,S++", 0x2e, 9, 0, 0x61 },
  { "EORA,-X", 0x2e, 9, 0, 0x22 },
  { "EORA,-Y", 0x2e, 9, 0, 0x32 },
  { "EORA,-U", 0x2e, 9, 0, 0x52 },
  { "EORA,-S", 0x2e, 9, 0, 0x62 },
  { "EORA,--X", 0x2e, 9, 0, 0x23 },
  { "EORA,--Y", 0x2e, 9, 0, 0x33 },
  { "EORA,--U", 0x2e, 9, 0, 0x53 },
  { "EORA,--S", 0x2e, 9, 0, 0x63 },
  { "EORA (,X)", 0x2e, 9, 0, 0x2e },
  { "EORA (,Y)", 0x2e, 9, 0, 0x3e },
  { "EORA (,U)", 0x2e, 9, 0, 0x5e },
  { "EORA (,S)", 0x2e, 9, 0, 0x6e },
  { "EORA (A,X)", 0x2e, 9, 0, 0xa8 },
  { "EORA (A,Y)", 0x2e, 9, 0, 0xb8 },
  { "EORA (A,U)", 0x2e, 9, 0, 0xd8 },
  { "EORA (A,S)", 0x2e, 9, 0, 0xe8 },
  { "EORA (B,X)", 0x2e, 9, 0, 0xa9 },
  { "EORA (B,Y)", 0x2e, 9, 0, 0xb9 },
  { "EORA (B,U)", 0x2e, 9, 0, 0xd9 },
  { "EORA (B,S)", 0x2e, 9, 0, 0xe9 },
  { "EORA (D,X)", 0x2e, 9, 0, 0xaf },
  { "EORA (D,Y)", 0x2e, 9, 0, 0xbf },
  { "EORA (D,U)", 0x2e, 9, 0, 0xdf },
  { "EORA (D,S)", 0x2e, 9, 0, 0xef },
  { "EORA (,X++)", 0x2e, 9, 0, 0x29 },
  { "EORA (,Y++)", 0x2e, 9, 0, 0x39 },
  { "EORA (,U++)", 0x2e, 9, 0, 0x59 },
  { "EORA (,S++)", 0x2e, 9, 0, 0x69 },
  { "EORA (,--X)", 0x2e, 9, 0, 0x2b },
  { "EORA (,--Y)", 0x2e, 9, 0, 0x3b },
  { "EORA (,--U)", 0x2e, 9, 0, 0x5b },
  { "EORA (,--S)", 0x2e, 9, 0, 0x6b },
  { "EORA (x,X)", 0x2e, 7, 1, 0x2c }, /* 8-bit offset */
  { "EORA (x,Y)", 0x2e, 7, 1, 0x3c }, /* 8-bit offset */
  { "EORA (x,U)", 0x2e, 7, 1, 0x5c }, /* 8-bit offset */
  { "EORA (x,S)", 0x2e, 7, 1, 0x6c }, /* 8-bit offset */
  { "EORA (?,X)", 0x2e, 8, 0, 0x2d }, /* 16-bit offset */
  { "EORA (?,Y)", 0x2e, 8, 0, 0x3d }, /* 16-bit offset */
  { "EORA (?,U)", 0x2e, 8, 0, 0x5d }, /* 16-bit offset */
  { "EORA (?,S)", 0x2e, 8, 0, 0x6d }, /* 16-bit offset */
  { "EORA (x,PCR)", 0x2e, 7, 1, 0x7c }, /* 8-bit offset */
  { "EORA (?,PCR)", 0x2e, 8, 0, 0x7d }, /* 16-bit offset */
  { "EORA (?)", 0x2e, 8, 0, 0x0f }, /* 16-bit offset */
  { "EORA s,X", 0x2e, 6, 1, 0x26 }, /* 5-bit offset */
  { "EORA s,Y", 0x2e, 6, 1, 0x36 }, /* 5-bit offset */
  { "EORA s,U", 0x2e, 6, 1, 0x56 }, /* 5-bit offset */
  { "EORA s,S", 0x2e, 6, 1, 0x66 }, /* 5-bit offset */
  { "EORA x,X", 0x2e, 7, 1, 0x24 }, /* 8-bit offset */
  { "EORA x,Y", 0x2e, 7, 1, 0x34 }, /* 8-bit offset */
  { "EORA x,U", 0x2e, 7, 1, 0x54 }, /* 8-bit offset */
  { "EORA x,S", 0x2e, 7, 1, 0x64 }, /* 8-bit offset */
  { "EORA ?,X", 0x2e, 8, 0, 0x25 }, /* 16-bit offset */
  { "EORA ?,Y", 0x2e, 8, 0, 0x35 }, /* 16-bit offset */
  { "EORA ?,U", 0x2e, 8, 0, 0x55 }, /* 16-bit offset */
  { "EORA ?,S", 0x2e, 8, 0, 0x65 }, /* 16-bit offset */
  { "EORA x,PCR", 0x2e, 7, 1, 0x74 }, /* 8-bit offset */
  { "EORA ?,PCR", 0x2e, 8, 0, 0x75 }, /* 16-bit offset */
  { "EORA x", 0x2e, 2, 1, 0x07 },
  { "EORA ?", 0x2e, 2, 0, 0x07 },

  { "EORB #x", 0x2d, 1, 0, 0 },
  { "EORB,X", 0x2f, 9, 0, 0x26 },
  { "EORB,Y", 0x2f, 9, 0, 0x36 },
  { "EORB,U", 0x2f, 9, 0, 0x56 },
  { "EORB,S", 0x2f, 9, 0, 0x66 },
  { "EORB A,X", 0x2f, 9, 0, 0xa0 },
  { "EORB A,Y", 0x2f, 9, 0, 0xb0 },
  { "EORB A,U", 0x2f, 9, 0, 0xd0 },
  { "EORB A,S", 0x2f, 9, 0, 0xe0 },
  { "EORB B,X", 0x2f, 9, 0, 0xa1 },
  { "EORB B,Y", 0x2f, 9, 0, 0xb1 },
  { "EORB B,U", 0x2f, 9, 0, 0xd1 },
  { "EORB B,S", 0x2f, 9, 0, 0xe1 },
  { "EORB D,X", 0x2f, 9, 0, 0xa7 },
  { "EORB D,Y", 0x2f, 9, 0, 0xb7 },
  { "EORB D,U", 0x2f, 9, 0, 0xd7 },
  { "EORB D,S", 0x2f, 9, 0, 0xe8 },
  { "EORB,X+", 0x2f, 9, 0, 0x20 },
  { "EORB,Y+", 0x2f, 9, 0, 0x30 },
  { "EORB,U+", 0x2f, 9, 0, 0x50 },
  { "EORB,S+", 0x2f, 9, 0, 0x60 },
  { "EORB,X++", 0x2f, 9, 0, 0x21 },
  { "EORB,Y++", 0x2f, 9, 0, 0x31 },
  { "EORB,U++", 0x2f, 9, 0, 0x51 },
  { "EORB,S++", 0x2f, 9, 0, 0x61 },
  { "EORB,-X", 0x2f, 9, 0, 0x22 },
  { "EORB,-Y", 0x2f, 9, 0, 0x32 },
  { "EORB,-U", 0x2f, 9, 0, 0x52 },
  { "EORB,-S", 0x2f, 9, 0, 0x62 },
  { "EORB,--X", 0x2f, 9, 0, 0x23 },
  { "EORB,--Y", 0x2f, 9, 0, 0x33 },
  { "EORB,--U", 0x2f, 9, 0, 0x53 },
  { "EORB,--S", 0x2f, 9, 0, 0x63 },
  { "EORB (,X)", 0x2f, 9, 0, 0x2e },
  { "EORB (,Y)", 0x2f, 9, 0, 0x3e },
  { "EORB (,U)", 0x2f, 9, 0, 0x5e },
  { "EORB (,S)", 0x2f, 9, 0, 0x6e },
  { "EORB (A,X)", 0x2f, 9, 0, 0xa8 },
  { "EORB (A,Y)", 0x2f, 9, 0, 0xb8 },
  { "EORB (A,U)", 0x2f, 9, 0, 0xd8 },
  { "EORB (A,S)", 0x2f, 9, 0, 0xe8 },
  { "EORB (B,X)", 0x2f, 9, 0, 0xa9 },
  { "EORB (B,Y)", 0x2f, 9, 0, 0xb9 },
  { "EORB (B,U)", 0x2f, 9, 0, 0xd9 },
  { "EORB (B,S)", 0x2f, 9, 0, 0xe9 },
  { "EORB (D,X)", 0x2f, 9, 0, 0xaf },
  { "EORB (D,Y)", 0x2f, 9, 0, 0xbf },
  { "EORB (D,U)", 0x2f, 9, 0, 0xdf },
  { "EORB (D,S)", 0x2f, 9, 0, 0xef },
  { "EORB (,X++)", 0x2f, 9, 0, 0x29 },
  { "EORB (,Y++)", 0x2f, 9, 0, 0x39 },
  { "EORB (,U++)", 0x2f, 9, 0, 0x59 },
  { "EORB (,S++)", 0x2f, 9, 0, 0x69 },
  { "EORB (,--X)", 0x2f, 9, 0, 0x2b },
  { "EORB (,--Y)", 0x2f, 9, 0, 0x3b },
  { "EORB (,--U)", 0x2f, 9, 0, 0x5b },
  { "EORB (,--S)", 0x2f, 9, 0, 0x6b },
  { "EORB (x,X)", 0x2f, 7, 1, 0x2c }, /* 8-bit offset */
  { "EORB (x,Y)", 0x2f, 7, 1, 0x3c }, /* 8-bit offset */
  { "EORB (x,U)", 0x2f, 7, 1, 0x5c }, /* 8-bit offset */
  { "EORB (x,S)", 0x2f, 7, 1, 0x6c }, /* 8-bit offset */
  { "EORB (?,X)", 0x2f, 8, 0, 0x2d }, /* 16-bit offset */
  { "EORB (?,Y)", 0x2f, 8, 0, 0x3d }, /* 16-bit offset */
  { "EORB (?,U)", 0x2f, 8, 0, 0x5d }, /* 16-bit offset */
  { "EORB (?,S)", 0x2f, 8, 0, 0x6d }, /* 16-bit offset */
  { "EORB (x,PCR)", 0x2f, 7, 1, 0x7c }, /* 8-bit offset */
  { "EORB (?,PCR)", 0x2f, 8, 0, 0x7d }, /* 16-bit offset */
  { "EORB (?)", 0x2f, 8, 0, 0x0f }, /* 16-bit offset */
  { "EORB s,X", 0x2f, 6, 1, 0x26 }, /* 5-bit offset */
  { "EORB s,Y", 0x2f, 6, 1, 0x36 }, /* 5-bit offset */
  { "EORB s,U", 0x2f, 6, 1, 0x56 }, /* 5-bit offset */
  { "EORB s,S", 0x2f, 6, 1, 0x66 }, /* 5-bit offset */
  { "EORB x,X", 0x2f, 7, 1, 0x24 }, /* 8-bit offset */
  { "EORB x,Y", 0x2f, 7, 1, 0x34 }, /* 8-bit offset */
  { "EORB x,U", 0x2f, 7, 1, 0x54 }, /* 8-bit offset */
  { "EORB x,S", 0x2f, 7, 1, 0x64 }, /* 8-bit offset */
  { "EORB ?,X", 0x2f, 8, 0, 0x25 }, /* 16-bit offset */
  { "EORB ?,Y", 0x2f, 8, 0, 0x35 }, /* 16-bit offset */
  { "EORB ?,U", 0x2f, 8, 0, 0x55 }, /* 16-bit offset */
  { "EORB ?,S", 0x2f, 8, 0, 0x65 }, /* 16-bit offset */
  { "EORB x,PCR", 0x2f, 7, 1, 0x74 }, /* 8-bit offset */
  { "EORB ?,PCR", 0x2f, 8, 0, 0x75 }, /* 16-bit offset */
  { "EORB x", 0x2f, 2, 1, 0x07 },
  { "EORB ?", 0x2f, 2, 0, 0x07 },

  { "EXG r", 0x3e, 10, 0, 0 },

  { "INCA", 0x89, 0, 0, 0 },
  { "INCB", 0x8a, 0, 0, 0 },
  { "INC,X", 0x8b, 9, 0, 0x26 },
  { "INC,Y", 0x8b, 9, 0, 0x36 },
  { "INC,U", 0x8b, 9, 0, 0x56 },
  { "INC,S", 0x8b, 9, 0, 0x66 },
  { "INC A,X", 0x8b, 9, 0, 0xa0 },
  { "INC A,Y", 0x8b, 9, 0, 0xb0 },
  { "INC A,U", 0x8b, 9, 0, 0xd0 },
  { "INC A,S", 0x8b, 9, 0, 0xe0 },
  { "INC B,X", 0x8b, 9, 0, 0xa1 },
  { "INC B,Y", 0x8b, 9, 0, 0xb1 },
  { "INC B,U", 0x8b, 9, 0, 0xd1 },
  { "INC B,S", 0x8b, 9, 0, 0xe1 },
  { "INC D,X", 0x8b, 9, 0, 0xa7 },
  { "INC D,Y", 0x8b, 9, 0, 0xb7 },
  { "INC D,U", 0x8b, 9, 0, 0xd7 },
  { "INC D,S", 0x8b, 9, 0, 0xe8 },
  { "INC,X+", 0x8b, 9, 0, 0x20 },
  { "INC,Y+", 0x8b, 9, 0, 0x30 },
  { "INC,U+", 0x8b, 9, 0, 0x50 },
  { "INC,S+", 0x8b, 9, 0, 0x60 },
  { "INC,X++", 0x8b, 9, 0, 0x21 },
  { "INC,Y++", 0x8b, 9, 0, 0x31 },
  { "INC,U++", 0x8b, 9, 0, 0x51 },
  { "INC,S++", 0x8b, 9, 0, 0x61 },
  { "INC,-X", 0x8b, 9, 0, 0x22 },
  { "INC,-Y", 0x8b, 9, 0, 0x32 },
  { "INC,-U", 0x8b, 9, 0, 0x52 },
  { "INC,-S", 0x8b, 9, 0, 0x62 },
  { "INC,--X", 0x8b, 9, 0, 0x23 },
  { "INC,--Y", 0x8b, 9, 0, 0x33 },
  { "INC,--U", 0x8b, 9, 0, 0x53 },
  { "INC,--S", 0x8b, 9, 0, 0x63 },
  { "INC (,X)", 0x8b, 9, 0, 0x2e },
  { "INC (,Y)", 0x8b, 9, 0, 0x3e },
  { "INC (,U)", 0x8b, 9, 0, 0x5e },
  { "INC (,S)", 0x8b, 9, 0, 0x6e },
  { "INC (A,X)", 0x8b, 9, 0, 0xa8 },
  { "INC (A,Y)", 0x8b, 9, 0, 0xb8 },
  { "INC (A,U)", 0x8b, 9, 0, 0xd8 },
  { "INC (A,S)", 0x8b, 9, 0, 0xe8 },
  { "INC (B,X)", 0x8b, 9, 0, 0xa9 },
  { "INC (B,Y)", 0x8b, 9, 0, 0xb9 },
  { "INC (B,U)", 0x8b, 9, 0, 0xd9 },
  { "INC (B,S)", 0x8b, 9, 0, 0xe9 },
  { "INC (D,X)", 0x8b, 9, 0, 0xaf },
  { "INC (D,Y)", 0x8b, 9, 0, 0xbf },
  { "INC (D,U)", 0x8b, 9, 0, 0xdf },
  { "INC (D,S)", 0x8b, 9, 0, 0xef },
  { "INC (,X++)", 0x8b, 9, 0, 0x29 },
  { "INC (,Y++)", 0x8b, 9, 0, 0x39 },
  { "INC (,U++)", 0x8b, 9, 0, 0x59 },
  { "INC (,S++)", 0x8b, 9, 0, 0x69 },
  { "INC (,--X)", 0x8b, 9, 0, 0x2b },
  { "INC (,--Y)", 0x8b, 9, 0, 0x3b },
  { "INC (,--U)", 0x8b, 9, 0, 0x5b },
  { "INC (,--S)", 0x8b, 9, 0, 0x6b },
  { "INC (x,X)", 0x8b, 7, 1, 0x2c }, /* 8-bit offset */
  { "INC (x,Y)", 0x8b, 7, 1, 0x3c }, /* 8-bit offset */
  { "INC (x,U)", 0x8b, 7, 1, 0x5c }, /* 8-bit offset */
  { "INC (x,S)", 0x8b, 7, 1, 0x6c }, /* 8-bit offset */
  { "INC (?,X)", 0x8b, 8, 0, 0x2d }, /* 16-bit offset */
  { "INC (?,Y)", 0x8b, 8, 0, 0x3d }, /* 16-bit offset */
  { "INC (?,U)", 0x8b, 8, 0, 0x5d }, /* 16-bit offset */
  { "INC (?,S)", 0x8b, 8, 0, 0x6d }, /* 16-bit offset */
  { "INC (x,PCR)", 0x8b, 7, 1, 0x7c }, /* 8-bit offset */
  { "INC (?,PCR)", 0x8b, 8, 0, 0x7d }, /* 16-bit offset */
  { "INC (?)", 0x8b, 8, 0, 0x0f }, /* 16-bit offset */
  { "INC s,X", 0x8b, 6, 1, 0x26 }, /* 5-bit offset */
  { "INC s,Y", 0x8b, 6, 1, 0x36 }, /* 5-bit offset */
  { "INC s,U", 0x8b, 6, 1, 0x56 }, /* 5-bit offset */
  { "INC s,S", 0x8b, 6, 1, 0x66 }, /* 5-bit offset */
  { "INC x,X", 0x8b, 7, 1, 0x24 }, /* 8-bit offset */
  { "INC x,Y", 0x8b, 7, 1, 0x34 }, /* 8-bit offset */
  { "INC x,U", 0x8b, 7, 1, 0x54 }, /* 8-bit offset */
  { "INC x,S", 0x8b, 7, 1, 0x64 }, /* 8-bit offset */
  { "INC ?,X", 0x8b, 8, 0, 0x25 }, /* 16-bit offset */
  { "INC ?,Y", 0x8b, 8, 0, 0x35 }, /* 16-bit offset */
  { "INC ?,U", 0x8b, 8, 0, 0x55 }, /* 16-bit offset */
  { "INC ?,S", 0x8b, 8, 0, 0x65 }, /* 16-bit offset */
  { "INC x,PCR", 0x8b, 7, 1, 0x74 }, /* 8-bit offset */
  { "INC ?,PCR", 0x8b, 8, 0, 0x75 }, /* 16-bit offset */
  { "INC x", 0x8b, 2, 1, 0x07 },
  { "INC ?", 0x8b, 2, 0, 0x07 },

  { "JMP,X", 0xa8, 9, 0, 0x26 },
  { "JMP,Y", 0xa8, 9, 0, 0x36 },
  { "JMP,U", 0xa8, 9, 0, 0x56 },
  { "JMP,S", 0xa8, 9, 0, 0x66 },
  { "JMP A,X", 0xa8, 9, 0, 0xa0 },
  { "JMP A,Y", 0xa8, 9, 0, 0xb0 },
  { "JMP A,U", 0xa8, 9, 0, 0xd0 },
  { "JMP A,S", 0xa8, 9, 0, 0xe0 },
  { "JMP B,X", 0xa8, 9, 0, 0xa1 },
  { "JMP B,Y", 0xa8, 9, 0, 0xb1 },
  { "JMP B,U", 0xa8, 9, 0, 0xd1 },
  { "JMP B,S", 0xa8, 9, 0, 0xe1 },
  { "JMP D,X", 0xa8, 9, 0, 0xa7 },
  { "JMP D,Y", 0xa8, 9, 0, 0xb7 },
  { "JMP D,U", 0xa8, 9, 0, 0xd7 },
  { "JMP D,S", 0xa8, 9, 0, 0xe8 },
  { "JMP,X+", 0xa8, 9, 0, 0x20 },
  { "JMP,Y+", 0xa8, 9, 0, 0x30 },
  { "JMP,U+", 0xa8, 9, 0, 0x50 },
  { "JMP,S+", 0xa8, 9, 0, 0x60 },
  { "JMP,X++", 0xa8, 9, 0, 0x21 },
  { "JMP,Y++", 0xa8, 9, 0, 0x31 },
  { "JMP,U++", 0xa8, 9, 0, 0x51 },
  { "JMP,S++", 0xa8, 9, 0, 0x61 },
  { "JMP,-X", 0xa8, 9, 0, 0x22 },
  { "JMP,-Y", 0xa8, 9, 0, 0x32 },
  { "JMP,-U", 0xa8, 9, 0, 0x52 },
  { "JMP,-S", 0xa8, 9, 0, 0x62 },
  { "JMP,--X", 0xa8, 9, 0, 0x23 },
  { "JMP,--Y", 0xa8, 9, 0, 0x33 },
  { "JMP,--U", 0xa8, 9, 0, 0x53 },
  { "JMP,--S", 0xa8, 9, 0, 0x63 },
  { "JMP (,X)", 0xa8, 9, 0, 0x2e },
  { "JMP (,Y)", 0xa8, 9, 0, 0x3e },
  { "JMP (,U)", 0xa8, 9, 0, 0x5e },
  { "JMP (,S)", 0xa8, 9, 0, 0x6e },
  { "JMP (A,X)", 0xa8, 9, 0, 0xa8 },
  { "JMP (A,Y)", 0xa8, 9, 0, 0xb8 },
  { "JMP (A,U)", 0xa8, 9, 0, 0xd8 },
  { "JMP (A,S)", 0xa8, 9, 0, 0xe8 },
  { "JMP (B,X)", 0xa8, 9, 0, 0xa9 },
  { "JMP (B,Y)", 0xa8, 9, 0, 0xb9 },
  { "JMP (B,U)", 0xa8, 9, 0, 0xd9 },
  { "JMP (B,S)", 0xa8, 9, 0, 0xe9 },
  { "JMP (D,X)", 0xa8, 9, 0, 0xaf },
  { "JMP (D,Y)", 0xa8, 9, 0, 0xbf },
  { "JMP (D,U)", 0xa8, 9, 0, 0xdf },
  { "JMP (D,S)", 0xa8, 9, 0, 0xef },
  { "JMP (,X++)", 0xa8, 9, 0, 0x29 },
  { "JMP (,Y++)", 0xa8, 9, 0, 0x39 },
  { "JMP (,U++)", 0xa8, 9, 0, 0x59 },
  { "JMP (,S++)", 0xa8, 9, 0, 0x69 },
  { "JMP (,--X)", 0xa8, 9, 0, 0x2b },
  { "JMP (,--Y)", 0xa8, 9, 0, 0x3b },
  { "JMP (,--U)", 0xa8, 9, 0, 0x5b },
  { "JMP (,--S)", 0xa8, 9, 0, 0x6b },
  { "JMP (x,X)", 0xa8, 7, 1, 0x2c }, /* 8-bit offset */
  { "JMP (x,Y)", 0xa8, 7, 1, 0x3c }, /* 8-bit offset */
  { "JMP (x,U)", 0xa8, 7, 1, 0x5c }, /* 8-bit offset */
  { "JMP (x,S)", 0xa8, 7, 1, 0x6c }, /* 8-bit offset */
  { "JMP (?,X)", 0xa8, 8, 0, 0x2d }, /* 16-bit offset */
  { "JMP (?,Y)", 0xa8, 8, 0, 0x3d }, /* 16-bit offset */
  { "JMP (?,U)", 0xa8, 8, 0, 0x5d }, /* 16-bit offset */
  { "JMP (?,S)", 0xa8, 8, 0, 0x6d }, /* 16-bit offset */
  { "JMP (x,PCR)", 0xa8, 7, 1, 0x7c }, /* 8-bit offset */
  { "JMP (?,PCR)", 0xa8, 8, 0, 0x7d }, /* 16-bit offset */
  { "JMP (?)", 0xa8, 8, 0, 0x0f }, /* 16-bit offset */
  { "JMP s,X", 0xa8, 6, 1, 0x26 }, /* 5-bit offset */
  { "JMP s,Y", 0xa8, 6, 1, 0x36 }, /* 5-bit offset */
  { "JMP s,U", 0xa8, 6, 1, 0x56 }, /* 5-bit offset */
  { "JMP s,S", 0xa8, 6, 1, 0x66 }, /* 5-bit offset */
  { "JMP x,X", 0xa8, 7, 1, 0x24 }, /* 8-bit offset */ /* 0x88 */
  { "JMP x,Y", 0xa8, 7, 1, 0x34 }, /* 8-bit offset */
  { "JMP x,U", 0xa8, 7, 1, 0x54 }, /* 8-bit offset */
  { "JMP x,S", 0xa8, 7, 1, 0x64 }, /* 8-bit offset */
  { "JMP ?,X", 0xa8, 8, 0, 0x25 }, /* 16-bit offset */ /* 0x89 */
  { "JMP ?,Y", 0xa8, 8, 0, 0x35 }, /* 16-bit offset */
  { "JMP ?,U", 0xa8, 8, 0, 0x55 }, /* 16-bit offset */
  { "JMP ?,S", 0xa8, 8, 0, 0x65 }, /* 16-bit offset */
  { "JMP x,PCR", 0xa8, 7, 1, 0x74 }, /* 8-bit offset */
  { "JMP ?,PCR", 0xa8, 8, 0, 0x75 }, /* 16-bit offset */
  { "JMP x", 0xa8, 2, 1, 0x07 },
  { "JMP ?", 0xa8, 2, 0, 0x07 },

  { "JSR,X", 0xa9, 9, 0, 0x26 },
  { "JSR,Y", 0xa9, 9, 0, 0x36 },
  { "JSR,U", 0xa9, 9, 0, 0x56 },
  { "JSR,S", 0xa9, 9, 0, 0x66 },
  { "JSR A,X", 0xa9, 9, 0, 0xa0 },
  { "JSR A,Y", 0xa9, 9, 0, 0xb0 },
  { "JSR A,U", 0xa9, 9, 0, 0xd0 },
  { "JSR A,S", 0xa9, 9, 0, 0xe0 },
  { "JSR B,X", 0xa9, 9, 0, 0xa1 },
  { "JSR B,Y", 0xa9, 9, 0, 0xb1 },
  { "JSR B,U", 0xa9, 9, 0, 0xd1 },
  { "JSR B,S", 0xa9, 9, 0, 0xe1 },
  { "JSR D,X", 0xa9, 9, 0, 0xa7 },
  { "JSR D,Y", 0xa9, 9, 0, 0xb7 },
  { "JSR D,U", 0xa9, 9, 0, 0xd7 },
  { "JSR D,S", 0xa9, 9, 0, 0xe8 },
  { "JSR,X+", 0xa9, 9, 0, 0x20 },
  { "JSR,Y+", 0xa9, 9, 0, 0x30 },
  { "JSR,U+", 0xa9, 9, 0, 0x50 },
  { "JSR,S+", 0xa9, 9, 0, 0x60 },
  { "JSR,X++", 0xa9, 9, 0, 0x21 },
  { "JSR,Y++", 0xa9, 9, 0, 0x31 },
  { "JSR,U++", 0xa9, 9, 0, 0x51 },
  { "JSR,S++", 0xa9, 9, 0, 0x61 },
  { "JSR,-X", 0xa9, 9, 0, 0x22 },
  { "JSR,-Y", 0xa9, 9, 0, 0x32 },
  { "JSR,-U", 0xa9, 9, 0, 0x52 },
  { "JSR,-S", 0xa9, 9, 0, 0x62 },
  { "JSR,--X", 0xa9, 9, 0, 0x23 },
  { "JSR,--Y", 0xa9, 9, 0, 0x33 },
  { "JSR,--U", 0xa9, 9, 0, 0x53 },
  { "JSR,--S", 0xa9, 9, 0, 0x63 },
  { "JSR (,X)", 0xa9, 9, 0, 0x2e },
  { "JSR (,Y)", 0xa9, 9, 0, 0x3e },
  { "JSR (,U)", 0xa9, 9, 0, 0x5e },
  { "JSR (,S)", 0xa9, 9, 0, 0x6e },
  { "JSR (A,X)", 0xa9, 9, 0, 0xa8 },
  { "JSR (A,Y)", 0xa9, 9, 0, 0xb8 },
  { "JSR (A,U)", 0xa9, 9, 0, 0xd8 },
  { "JSR (A,S)", 0xa9, 9, 0, 0xe8 },
  { "JSR (B,X)", 0xa9, 9, 0, 0xa9 },
  { "JSR (B,Y)", 0xa9, 9, 0, 0xb9 },
  { "JSR (B,U)", 0xa9, 9, 0, 0xd9 },
  { "JSR (B,S)", 0xa9, 9, 0, 0xe9 },
  { "JSR (D,X)", 0xa9, 9, 0, 0xaf },
  { "JSR (D,Y)", 0xa9, 9, 0, 0xbf },
  { "JSR (D,U)", 0xa9, 9, 0, 0xdf },
  { "JSR (D,S)", 0xa9, 9, 0, 0xef },
  { "JSR (,X++)", 0xa9, 9, 0, 0x29 },
  { "JSR (,Y++)", 0xa9, 9, 0, 0x39 },
  { "JSR (,U++)", 0xa9, 9, 0, 0x59 },
  { "JSR (,S++)", 0xa9, 9, 0, 0x69 },
  { "JSR (,--X)", 0xa9, 9, 0, 0x2b },
  { "JSR (,--Y)", 0xa9, 9, 0, 0x3b },
  { "JSR (,--U)", 0xa9, 9, 0, 0x5b },
  { "JSR (,--S)", 0xa9, 9, 0, 0x6b },
  { "JSR (x,X)", 0xa9, 7, 1, 0x2c }, /* 8-bit offset */
  { "JSR (x,Y)", 0xa9, 7, 1, 0x3c }, /* 8-bit offset */
  { "JSR (x,U)", 0xa9, 7, 1, 0x5c }, /* 8-bit offset */
  { "JSR (x,S)", 0xa9, 7, 1, 0x6c }, /* 8-bit offset */
  { "JSR (?,X)", 0xa9, 8, 0, 0x2d }, /* 16-bit offset */
  { "JSR (?,Y)", 0xa9, 8, 0, 0x3d }, /* 16-bit offset */
  { "JSR (?,U)", 0xa9, 8, 0, 0x5d }, /* 16-bit offset */
  { "JSR (?,S)", 0xa9, 8, 0, 0x6d }, /* 16-bit offset */
  { "JSR (x,PCR)", 0xa9, 7, 1, 0x7c }, /* 8-bit offset */
  { "JSR (?,PCR)", 0xa9, 8, 0, 0x7d }, /* 16-bit offset */
  { "JSR (?)", 0xa9, 8, 0, 0x0f }, /* 16-bit offset */
  { "JSR s,X", 0xa9, 6, 1, 0x26 }, /* 5-bit offset */
  { "JSR s,Y", 0xa9, 6, 1, 0x36 }, /* 5-bit offset */
  { "JSR s,U", 0xa9, 6, 1, 0x56 }, /* 5-bit offset */
  { "JSR s,S", 0xa9, 6, 1, 0x66 }, /* 5-bit offset */
  { "JSR x,X", 0xa9, 7, 1, 0x24 }, /* 8-bit offset */
  { "JSR x,Y", 0xa9, 7, 1, 0x34 }, /* 8-bit offset */
  { "JSR x,U", 0xa9, 7, 1, 0x54 }, /* 8-bit offset */
  { "JSR x,S", 0xa9, 7, 1, 0x64 }, /* 8-bit offset */
  { "JSR ?,X", 0xa9, 8, 0, 0x25 }, /* 16-bit offset */
  { "JSR ?,Y", 0xa9, 8, 0, 0x35 }, /* 16-bit offset */
  { "JSR ?,U", 0xa9, 8, 0, 0x55 }, /* 16-bit offset */
  { "JSR ?,S", 0xa9, 8, 0, 0x65 }, /* 16-bit offset */
  { "JSR x,PCR", 0xa9, 7, 1, 0x74 }, /* 8-bit offset */
  { "JSR ?,PCR", 0xa9, 8, 0, 0x75 }, /* 16-bit offset */
  { "JSR x", 0xa9, 2, 1, 0x07 },
  { "JSR ?", 0xa9, 2, 0, 0x07 },

  { "LBCC ?", 0x6a, 12, 0, 0 },
  { "LBCS ?", 0x7a, 12, 0, 0 },
  { "LBEQ ?", 0x73, 12, 0, 0 },
  { "LBGE ?", 0x6e, 12, 0, 0 },
  { "LBGT ?", 0x6f, 12, 0, 0 },
  { "LBHI ?", 0x69, 12, 0, 0 },
  { "LBHS ?", 0x6a, 12, 0, 0 },
  { "LBLE ?", 0x7f, 12, 0, 0 },
  { "LBLO ?", 0x7a, 12, 0, 0 },
  { "LBLS ?", 0x79, 12, 0, 0 },
  { "LBLT ?", 0x7e, 12, 0, 0 },
  { "LBMI ?", 0x7d, 12, 0, 0 },
  { "LBNE ?", 0x6b, 12, 0, 0 },
  { "LBPL ?", 0x6d, 12, 0, 0 },
  { "LBRA ?", 0x68, 12, 0, 0 },
  { "LBRN ?", 0x78, 12, 0, 0 },
  { "LBSR ?", 0xab, 12, 0, 0 },
  { "LBVC ?", 0x6c, 12, 0, 0 },
  { "LBVS ?", 0x7c, 12, 0, 0 },
  
  { "LDA #x", 0x10, 1, 0, 0 },
  { "LDA,X", 0x12, 9, 0, 0x26 },
  { "LDA,Y", 0x12, 9, 0, 0x36 },
  { "LDA,U", 0x12, 9, 0, 0x56 },
  { "LDA,S", 0x12, 9, 0, 0x66 },
  { "LDA A,X", 0x12, 9, 0, 0xa0 },
  { "LDA A,Y", 0x12, 9, 0, 0xb0 },
  { "LDA A,U", 0x12, 9, 0, 0xd0 },
  { "LDA A,S", 0x12, 9, 0, 0xe0 },
  { "LDA B,X", 0x12, 9, 0, 0xa1 },
  { "LDA B,Y", 0x12, 9, 0, 0xb1 },
  { "LDA B,U", 0x12, 9, 0, 0xd1 },
  { "LDA B,S", 0x12, 9, 0, 0xe1 },
  { "LDA D,X", 0x12, 9, 0, 0xa7 },
  { "LDA D,Y", 0x12, 9, 0, 0xb7 },
  { "LDA D,U", 0x12, 9, 0, 0xd7 },
  { "LDA D,S", 0x12, 9, 0, 0xe8 },
  { "LDA,X+", 0x12, 9, 0, 0x20 },
  { "LDA,Y+", 0x12, 9, 0, 0x30 },
  { "LDA,U+", 0x12, 9, 0, 0x50 },
  { "LDA,S+", 0x12, 9, 0, 0x60 },
  { "LDA,X++", 0x12, 9, 0, 0x21 },
  { "LDA,Y++", 0x12, 9, 0, 0x31 },
  { "LDA,U++", 0x12, 9, 0, 0x51 },
  { "LDA,S++", 0x12, 9, 0, 0x61 },
  { "LDA,-X", 0x12, 9, 0, 0x22 },
  { "LDA,-Y", 0x12, 9, 0, 0x32 },
  { "LDA,-U", 0x12, 9, 0, 0x52 },
  { "LDA,-S", 0x12, 9, 0, 0x62 },
  { "LDA,--X", 0x12, 9, 0, 0x23 },
  { "LDA,--Y", 0x12, 9, 0, 0x33 },
  { "LDA,--U", 0x12, 9, 0, 0x53 },
  { "LDA,--S", 0x12, 9, 0, 0x63 },
  { "LDA (,X)", 0x12, 9, 0, 0x2e },
  { "LDA (,Y)", 0x12, 9, 0, 0x3e },
  { "LDA (,U)", 0x12, 9, 0, 0x5e },
  { "LDA (,S)", 0x12, 9, 0, 0x6e },
  { "LDA (A,X)", 0x12, 9, 0, 0xa8 },
  { "LDA (A,Y)", 0x12, 9, 0, 0xb8 },
  { "LDA (A,U)", 0x12, 9, 0, 0xd8 },
  { "LDA (A,S)", 0x12, 9, 0, 0xe8 },
  { "LDA (B,X)", 0x12, 9, 0, 0xa9 },
  { "LDA (B,Y)", 0x12, 9, 0, 0xb9 },
  { "LDA (B,U)", 0x12, 9, 0, 0xd9 },
  { "LDA (B,S)", 0x12, 9, 0, 0xe9 },
  { "LDA (D,X)", 0x12, 9, 0, 0xaf },
  { "LDA (D,Y)", 0x12, 9, 0, 0xbf },
  { "LDA (D,U)", 0x12, 9, 0, 0xdf },
  { "LDA (D,S)", 0x12, 9, 0, 0xef },
  { "LDA (,X++)", 0x12, 9, 0, 0x29 },
  { "LDA (,Y++)", 0x12, 9, 0, 0x39 },
  { "LDA (,U++)", 0x12, 9, 0, 0x59 },
  { "LDA (,S++)", 0x12, 9, 0, 0x69 },
  { "LDA (,--X)", 0x12, 9, 0, 0x2b },
  { "LDA (,--Y)", 0x12, 9, 0, 0x3b },
  { "LDA (,--U)", 0x12, 9, 0, 0x5b },
  { "LDA (,--S)", 0x12, 9, 0, 0x6b },
  { "LDA (x,X)", 0x12, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDA (x,Y)", 0x12, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDA (x,U)", 0x12, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDA (x,S)", 0x12, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDA (?,X)", 0x12, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDA (?,Y)", 0x12, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDA (?,U)", 0x12, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDA (?,S)", 0x12, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDA (x,PCR)", 0x12, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDA (?,PCR)", 0x12, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDA (?)", 0x12, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDA s,X", 0x12, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDA s,Y", 0x12, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDA s,U", 0x12, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDA s,S", 0x12, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDA x,X", 0x12, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDA x,Y", 0x12, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDA x,U", 0x12, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDA x,S", 0x12, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDA ?,X", 0x12, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDA ?,Y", 0x12, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDA ?,U", 0x12, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDA ?,S", 0x12, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDA x,PCR", 0x12, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDA ?,PCR", 0x12, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDA x", 0x12, 2, 1, 0x07 },
  { "LDA ?", 0x12, 2, 0, 0x07 },

  { "LDB #x", 0x11, 1, 0, 0 },
  { "LDB,X", 0x13, 9, 0, 0x26 },
  { "LDB,Y", 0x13, 9, 0, 0x36 },
  { "LDB,U", 0x13, 9, 0, 0x56 },
  { "LDB,S", 0x13, 9, 0, 0x66 },
  { "LDB A,X", 0x13, 9, 0, 0xa0 },
  { "LDB A,Y", 0x13, 9, 0, 0xb0 },
  { "LDB A,U", 0x13, 9, 0, 0xd0 },
  { "LDB A,S", 0x13, 9, 0, 0xe0 },
  { "LDB B,X", 0x13, 9, 0, 0xa1 },
  { "LDB B,Y", 0x13, 9, 0, 0xb1 },
  { "LDB B,U", 0x13, 9, 0, 0xd1 },
  { "LDB B,S", 0x13, 9, 0, 0xe1 },
  { "LDB D,X", 0x13, 9, 0, 0xa7 },
  { "LDB D,Y", 0x13, 9, 0, 0xb7 },
  { "LDB D,U", 0x13, 9, 0, 0xd7 },
  { "LDB D,S", 0x13, 9, 0, 0xe8 },
  { "LDB,X+", 0x13, 9, 0, 0x20 },
  { "LDB,Y+", 0x13, 9, 0, 0x30 },
  { "LDB,U+", 0x13, 9, 0, 0x50 },
  { "LDB,S+", 0x13, 9, 0, 0x60 },
  { "LDB,X++", 0x13, 9, 0, 0x21 },
  { "LDB,Y++", 0x13, 9, 0, 0x31 },
  { "LDB,U++", 0x13, 9, 0, 0x51 },
  { "LDB,S++", 0x13, 9, 0, 0x61 },
  { "LDB,-X", 0x13, 9, 0, 0x22 },
  { "LDB,-Y", 0x13, 9, 0, 0x32 },
  { "LDB,-U", 0x13, 9, 0, 0x52 },
  { "LDB,-S", 0x13, 9, 0, 0x62 },
  { "LDB,--X", 0x13, 9, 0, 0x23 },
  { "LDB,--Y", 0x13, 9, 0, 0x33 },
  { "LDB,--U", 0x13, 9, 0, 0x53 },
  { "LDB,--S", 0x13, 9, 0, 0x63 },
  { "LDB (,X)", 0x13, 9, 0, 0x2e },
  { "LDB (,Y)", 0x13, 9, 0, 0x3e },
  { "LDB (,U)", 0x13, 9, 0, 0x5e },
  { "LDB (,S)", 0x13, 9, 0, 0x6e },
  { "LDB (A,X)", 0x13, 9, 0, 0xa8 },
  { "LDB (A,Y)", 0x13, 9, 0, 0xb8 },
  { "LDB (A,U)", 0x13, 9, 0, 0xd8 },
  { "LDB (A,S)", 0x13, 9, 0, 0xe8 },
  { "LDB (B,X)", 0x13, 9, 0, 0xa9 },
  { "LDB (B,Y)", 0x13, 9, 0, 0xb9 },
  { "LDB (B,U)", 0x13, 9, 0, 0xd9 },
  { "LDB (B,S)", 0x13, 9, 0, 0xe9 },
  { "LDB (D,X)", 0x13, 9, 0, 0xaf },
  { "LDB (D,Y)", 0x13, 9, 0, 0xbf },
  { "LDB (D,U)", 0x13, 9, 0, 0xdf },
  { "LDB (D,S)", 0x13, 9, 0, 0xef },
  { "LDB (,X++)", 0x13, 9, 0, 0x29 },
  { "LDB (,Y++)", 0x13, 9, 0, 0x39 },
  { "LDB (,U++)", 0x13, 9, 0, 0x59 },
  { "LDB (,S++)", 0x13, 9, 0, 0x69 },
  { "LDB (,--X)", 0x13, 9, 0, 0x2b },
  { "LDB (,--Y)", 0x13, 9, 0, 0x3b },
  { "LDB (,--U)", 0x13, 9, 0, 0x5b },
  { "LDB (,--S)", 0x13, 9, 0, 0x6b },
  { "LDB (x,X)", 0x13, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDB (x,Y)", 0x13, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDB (x,U)", 0x13, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDB (x,S)", 0x13, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDB (?,X)", 0x13, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDB (?,Y)", 0x13, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDB (?,U)", 0x13, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDB (?,S)", 0x13, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDB (x,PCR)", 0x13, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDB (?,PCR)", 0x13, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDB (?)", 0x13, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDB s,X", 0x13, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDB s,Y", 0x13, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDB s,U", 0x13, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDB s,S", 0x13, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDB x,X", 0x13, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDB x,Y", 0x13, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDB x,U", 0x13, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDB x,S", 0x13, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDB ?,X", 0x13, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDB ?,Y", 0x13, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDB ?,U", 0x13, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDB ?,S", 0x13, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDB x,PCR", 0x13, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDB ?,PCR", 0x13, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDB x", 0x13, 2, 1, 0x07 },
  { "LDB ?", 0x13, 2, 0, 0x07 },

  { "LDD #x", 0x40, 1, 0, 0 },
  { "LDD,X", 0x41, 9, 0, 0x26 },
  { "LDD,Y", 0x41, 9, 0, 0x36 },
  { "LDD,U", 0x41, 9, 0, 0x56 },
  { "LDD,S", 0x41, 9, 0, 0x66 },
  { "LDD A,X", 0x41, 9, 0, 0xa0 },
  { "LDD A,Y", 0x41, 9, 0, 0xb0 },
  { "LDD A,U", 0x41, 9, 0, 0xd0 },
  { "LDD A,S", 0x41, 9, 0, 0xe0 },
  { "LDD B,X", 0x41, 9, 0, 0xa1 },
  { "LDD B,Y", 0x41, 9, 0, 0xb1 },
  { "LDD B,U", 0x41, 9, 0, 0xd1 },
  { "LDD B,S", 0x41, 9, 0, 0xe1 },
  { "LDD D,X", 0x41, 9, 0, 0xa7 },
  { "LDD D,Y", 0x41, 9, 0, 0xb7 },
  { "LDD D,U", 0x41, 9, 0, 0xd7 },
  { "LDD D,S", 0x41, 9, 0, 0xe8 },
  { "LDD,X+", 0x41, 9, 0, 0x20 },
  { "LDD,Y+", 0x41, 9, 0, 0x30 },
  { "LDD,U+", 0x41, 9, 0, 0x50 },
  { "LDD,S+", 0x41, 9, 0, 0x60 },
  { "LDD,X++", 0x41, 9, 0, 0x21 },
  { "LDD,Y++", 0x41, 9, 0, 0x31 },
  { "LDD,U++", 0x41, 9, 0, 0x51 },
  { "LDD,S++", 0x41, 9, 0, 0x61 },
  { "LDD,-X", 0x41, 9, 0, 0x22 },
  { "LDD,-Y", 0x41, 9, 0, 0x32 },
  { "LDD,-U", 0x41, 9, 0, 0x52 },
  { "LDD,-S", 0x41, 9, 0, 0x62 },
  { "LDD,--X", 0x41, 9, 0, 0x23 },
  { "LDD,--Y", 0x41, 9, 0, 0x33 },
  { "LDD,--U", 0x41, 9, 0, 0x53 },
  { "LDD,--S", 0x41, 9, 0, 0x63 },
  { "LDD (,X)", 0x41, 9, 0, 0x2e },
  { "LDD (,Y)", 0x41, 9, 0, 0x3e },
  { "LDD (,U)", 0x41, 9, 0, 0x5e },
  { "LDD (,S)", 0x41, 9, 0, 0x6e },
  { "LDD (A,X)", 0x41, 9, 0, 0xa8 },
  { "LDD (A,Y)", 0x41, 9, 0, 0xb8 },
  { "LDD (A,U)", 0x41, 9, 0, 0xd8 },
  { "LDD (A,S)", 0x41, 9, 0, 0xe8 },
  { "LDD (B,X)", 0x41, 9, 0, 0xa9 },
  { "LDD (B,Y)", 0x41, 9, 0, 0xb9 },
  { "LDD (B,U)", 0x41, 9, 0, 0xd9 },
  { "LDD (B,S)", 0x41, 9, 0, 0xe9 },
  { "LDD (D,X)", 0x41, 9, 0, 0xaf },
  { "LDD (D,Y)", 0x41, 9, 0, 0xbf },
  { "LDD (D,U)", 0x41, 9, 0, 0xdf },
  { "LDD (D,S)", 0x41, 9, 0, 0xef },
  { "LDD (,X++)", 0x41, 9, 0, 0x29 },
  { "LDD (,Y++)", 0x41, 9, 0, 0x39 },
  { "LDD (,U++)", 0x41, 9, 0, 0x59 },
  { "LDD (,S++)", 0x41, 9, 0, 0x69 },
  { "LDD (,--X)", 0x41, 9, 0, 0x2b },
  { "LDD (,--Y)", 0x41, 9, 0, 0x3b },
  { "LDD (,--U)", 0x41, 9, 0, 0x5b },
  { "LDD (,--S)", 0x41, 9, 0, 0x6b },
  { "LDD (x,X)", 0x41, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDD (x,Y)", 0x41, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDD (x,U)", 0x41, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDD (x,S)", 0x41, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDD (?,X)", 0x41, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDD (?,Y)", 0x41, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDD (?,U)", 0x41, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDD (?,S)", 0x41, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDD (x,PCR)", 0x41, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDD (?,PCR)", 0x41, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDD (?)", 0x41, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDD s,X", 0x41, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDD s,Y", 0x41, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDD s,U", 0x41, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDD s,S", 0x41, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDD x,X", 0x41, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDD x,Y", 0x41, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDD x,U", 0x41, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDD x,S", 0x41, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDD ?,X", 0x41, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDD ?,Y", 0x41, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDD ?,U", 0x41, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDD ?,S", 0x41, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDD x,PCR", 0x41, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDD ?,PCR", 0x41, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDD x", 0x41, 2, 1, 0x07 },
  { "LDD ?", 0x41, 2, 0, 0x07 },

  { "LDS #x", 0x48, 13, 0, 0 },
  { "LDS,X", 0x49, 9, 0, 0x26 },
  { "LDS,Y", 0x49, 9, 0, 0x36 },
  { "LDS,U", 0x49, 9, 0, 0x56 },
  { "LDS,S", 0x49, 9, 0, 0x66 },
  { "LDS A,X", 0x49, 9, 0, 0xa0 },
  { "LDS A,Y", 0x49, 9, 0, 0xb0 },
  { "LDS A,U", 0x49, 9, 0, 0xd0 },
  { "LDS A,S", 0x49, 9, 0, 0xe0 },
  { "LDS B,X", 0x49, 9, 0, 0xa1 },
  { "LDS B,Y", 0x49, 9, 0, 0xb1 },
  { "LDS B,U", 0x49, 9, 0, 0xd1 },
  { "LDS B,S", 0x49, 9, 0, 0xe1 },
  { "LDS D,X", 0x49, 9, 0, 0xa7 },
  { "LDS D,Y", 0x49, 9, 0, 0xb7 },
  { "LDS D,U", 0x49, 9, 0, 0xd7 },
  { "LDS D,S", 0x49, 9, 0, 0xe8 },
  { "LDS,X+", 0x49, 9, 0, 0x20 },
  { "LDS,Y+", 0x49, 9, 0, 0x30 },
  { "LDS,U+", 0x49, 9, 0, 0x50 },
  { "LDS,S+", 0x49, 9, 0, 0x60 },
  { "LDS,X++", 0x49, 9, 0, 0x21 },
  { "LDS,Y++", 0x49, 9, 0, 0x31 },
  { "LDS,U++", 0x49, 9, 0, 0x51 },
  { "LDS,S++", 0x49, 9, 0, 0x61 },
  { "LDS,-X", 0x49, 9, 0, 0x22 },
  { "LDS,-Y", 0x49, 9, 0, 0x32 },
  { "LDS,-U", 0x49, 9, 0, 0x52 },
  { "LDS,-S", 0x49, 9, 0, 0x62 },
  { "LDS,--X", 0x49, 9, 0, 0x23 },
  { "LDS,--Y", 0x49, 9, 0, 0x33 },
  { "LDS,--U", 0x49, 9, 0, 0x53 },
  { "LDS,--S", 0x49, 9, 0, 0x63 },
  { "LDS (,X)", 0x49, 9, 0, 0x2e },
  { "LDS (,Y)", 0x49, 9, 0, 0x3e },
  { "LDS (,U)", 0x49, 9, 0, 0x5e },
  { "LDS (,S)", 0x49, 9, 0, 0x6e },
  { "LDS (A,X)", 0x49, 9, 0, 0xa8 },
  { "LDS (A,Y)", 0x49, 9, 0, 0xb8 },
  { "LDS (A,U)", 0x49, 9, 0, 0xd8 },
  { "LDS (A,S)", 0x49, 9, 0, 0xe8 },
  { "LDS (B,X)", 0x49, 9, 0, 0xa9 },
  { "LDS (B,Y)", 0x49, 9, 0, 0xb9 },
  { "LDS (B,U)", 0x49, 9, 0, 0xd9 },
  { "LDS (B,S)", 0x49, 9, 0, 0xe9 },
  { "LDS (D,X)", 0x49, 9, 0, 0xaf },
  { "LDS (D,Y)", 0x49, 9, 0, 0xbf },
  { "LDS (D,U)", 0x49, 9, 0, 0xdf },
  { "LDS (D,S)", 0x49, 9, 0, 0xef },
  { "LDS (,X++)", 0x49, 9, 0, 0x29 },
  { "LDS (,Y++)", 0x49, 9, 0, 0x39 },
  { "LDS (,U++)", 0x49, 9, 0, 0x59 },
  { "LDS (,S++)", 0x49, 9, 0, 0x69 },
  { "LDS (,--X)", 0x49, 9, 0, 0x2b },
  { "LDS (,--Y)", 0x49, 9, 0, 0x3b },
  { "LDS (,--U)", 0x49, 9, 0, 0x5b },
  { "LDS (,--S)", 0x49, 9, 0, 0x6b },
  { "LDS (x,X)", 0x49, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDS (x,Y)", 0x49, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDS (x,U)", 0x49, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDS (x,S)", 0x49, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDS (?,X)", 0x49, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDS (?,Y)", 0x49, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDS (?,U)", 0x49, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDS (?,S)", 0x49, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDS (x,PCR)", 0x49, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDS (?,PCR)", 0x49, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDS (?)", 0x49, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDS s,X", 0x49, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDS s,Y", 0x49, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDS s,U", 0x49, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDS s,S", 0x49, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDS x,X", 0x49, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDS x,Y", 0x49, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDS x,U", 0x49, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDS x,S", 0x49, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDS ?,X", 0x49, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDS ?,Y", 0x49, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDS ?,U", 0x49, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDS ?,S", 0x49, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDS x,PCR", 0x49, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDS ?,PCR", 0x49, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDS x", 0x49, 2, 1, 0x07 },
  { "LDS ?", 0x49, 2, 0, 0x07 },

  { "LDU #x", 0x46, 13, 0, 0 },
  { "LDU,X", 0x47, 9, 0, 0x26 },
  { "LDU,Y", 0x47, 9, 0, 0x36 },
  { "LDU,U", 0x47, 9, 0, 0x56 },
  { "LDU,S", 0x47, 9, 0, 0x66 },
  { "LDU A,X", 0x47, 9, 0, 0xa0 },
  { "LDU A,Y", 0x47, 9, 0, 0xb0 },
  { "LDU A,U", 0x47, 9, 0, 0xd0 },
  { "LDU A,S", 0x47, 9, 0, 0xe0 },
  { "LDU B,X", 0x47, 9, 0, 0xa1 },
  { "LDU B,Y", 0x47, 9, 0, 0xb1 },
  { "LDU B,U", 0x47, 9, 0, 0xd1 },
  { "LDU B,S", 0x47, 9, 0, 0xe1 },
  { "LDU D,X", 0x47, 9, 0, 0xa7 },
  { "LDU D,Y", 0x47, 9, 0, 0xb7 },
  { "LDU D,U", 0x47, 9, 0, 0xd7 },
  { "LDU D,S", 0x47, 9, 0, 0xe8 },
  { "LDU,X+", 0x47, 9, 0, 0x20 },
  { "LDU,Y+", 0x47, 9, 0, 0x30 },
  { "LDU,U+", 0x47, 9, 0, 0x50 },
  { "LDU,S+", 0x47, 9, 0, 0x60 },
  { "LDU,X++", 0x47, 9, 0, 0x21 },
  { "LDU,Y++", 0x47, 9, 0, 0x31 },
  { "LDU,U++", 0x47, 9, 0, 0x51 },
  { "LDU,S++", 0x47, 9, 0, 0x61 },
  { "LDU,-X", 0x47, 9, 0, 0x22 },
  { "LDU,-Y", 0x47, 9, 0, 0x32 },
  { "LDU,-U", 0x47, 9, 0, 0x52 },
  { "LDU,-S", 0x47, 9, 0, 0x62 },
  { "LDU,--X", 0x47, 9, 0, 0x23 },
  { "LDU,--Y", 0x47, 9, 0, 0x33 },
  { "LDU,--U", 0x47, 9, 0, 0x53 },
  { "LDU,--S", 0x47, 9, 0, 0x63 },
  { "LDU (,X)", 0x47, 9, 0, 0x2e },
  { "LDU (,Y)", 0x47, 9, 0, 0x3e },
  { "LDU (,U)", 0x47, 9, 0, 0x5e },
  { "LDU (,S)", 0x47, 9, 0, 0x6e },
  { "LDU (A,X)", 0x47, 9, 0, 0xa8 },
  { "LDU (A,Y)", 0x47, 9, 0, 0xb8 },
  { "LDU (A,U)", 0x47, 9, 0, 0xd8 },
  { "LDU (A,S)", 0x47, 9, 0, 0xe8 },
  { "LDU (B,X)", 0x47, 9, 0, 0xa9 },
  { "LDU (B,Y)", 0x47, 9, 0, 0xb9 },
  { "LDU (B,U)", 0x47, 9, 0, 0xd9 },
  { "LDU (B,S)", 0x47, 9, 0, 0xe9 },
  { "LDU (D,X)", 0x47, 9, 0, 0xaf },
  { "LDU (D,Y)", 0x47, 9, 0, 0xbf },
  { "LDU (D,U)", 0x47, 9, 0, 0xdf },
  { "LDU (D,S)", 0x47, 9, 0, 0xef },
  { "LDU (,X++)", 0x47, 9, 0, 0x29 },
  { "LDU (,Y++)", 0x47, 9, 0, 0x39 },
  { "LDU (,U++)", 0x47, 9, 0, 0x59 },
  { "LDU (,S++)", 0x47, 9, 0, 0x69 },
  { "LDU (,--X)", 0x47, 9, 0, 0x2b },
  { "LDU (,--Y)", 0x47, 9, 0, 0x3b },
  { "LDU (,--U)", 0x47, 9, 0, 0x5b },
  { "LDU (,--S)", 0x47, 9, 0, 0x6b },
  { "LDU (x,X)", 0x47, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDU (x,Y)", 0x47, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDU (x,U)", 0x47, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDU (x,S)", 0x47, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDU (?,X)", 0x47, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDU (?,Y)", 0x47, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDU (?,U)", 0x47, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDU (?,S)", 0x47, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDU (x,PCR)", 0x47, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDU (?,PCR)", 0x47, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDU (?)", 0x47, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDU s,X", 0x47, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDU s,Y", 0x47, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDU s,U", 0x47, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDU s,S", 0x47, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDU x,X", 0x47, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDU x,Y", 0x47, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDU x,U", 0x47, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDU x,S", 0x47, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDU ?,X", 0x47, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDU ?,Y", 0x47, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDU ?,U", 0x47, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDU ?,S", 0x47, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDU x,PCR", 0x47, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDU ?,PCR", 0x47, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDU x", 0x47, 2, 1, 0x07 },
  { "LDU ?", 0x47, 2, 0, 0x07 },

  { "LDX #x", 0x42, 13, 0, 0 },
  { "LDX,X", 0x43, 9, 0, 0x26 },
  { "LDX,Y", 0x43, 9, 0, 0x36 },
  { "LDX,U", 0x43, 9, 0, 0x56 },
  { "LDX,S", 0x43, 9, 0, 0x66 },
  { "LDX A,X", 0x43, 9, 0, 0xa0 },
  { "LDX A,Y", 0x43, 9, 0, 0xb0 },
  { "LDX A,U", 0x43, 9, 0, 0xd0 },
  { "LDX A,S", 0x43, 9, 0, 0xe0 },
  { "LDX B,X", 0x43, 9, 0, 0xa1 },
  { "LDX B,Y", 0x43, 9, 0, 0xb1 },
  { "LDX B,U", 0x43, 9, 0, 0xd1 },
  { "LDX B,S", 0x43, 9, 0, 0xe1 },
  { "LDX D,X", 0x43, 9, 0, 0xa7 },
  { "LDX D,Y", 0x43, 9, 0, 0xb7 },
  { "LDX D,U", 0x43, 9, 0, 0xd7 },
  { "LDX D,S", 0x43, 9, 0, 0xe8 },
  { "LDX,X+", 0x43, 9, 0, 0x20 },
  { "LDX,Y+", 0x43, 9, 0, 0x30 },
  { "LDX,U+", 0x43, 9, 0, 0x50 },
  { "LDX,S+", 0x43, 9, 0, 0x60 },
  { "LDX,X++", 0x43, 9, 0, 0x21 },
  { "LDX,Y++", 0x43, 9, 0, 0x31 },
  { "LDX,U++", 0x43, 9, 0, 0x51 },
  { "LDX,S++", 0x43, 9, 0, 0x61 },
  { "LDX,-X", 0x43, 9, 0, 0x22 },
  { "LDX,-Y", 0x43, 9, 0, 0x32 },
  { "LDX,-U", 0x43, 9, 0, 0x52 },
  { "LDX,-S", 0x43, 9, 0, 0x62 },
  { "LDX,--X", 0x43, 9, 0, 0x23 },
  { "LDX,--Y", 0x43, 9, 0, 0x33 },
  { "LDX,--U", 0x43, 9, 0, 0x53 },
  { "LDX,--S", 0x43, 9, 0, 0x63 },
  { "LDX (,X)", 0x43, 9, 0, 0x2e },
  { "LDX (,Y)", 0x43, 9, 0, 0x3e },
  { "LDX (,U)", 0x43, 9, 0, 0x5e },
  { "LDX (,S)", 0x43, 9, 0, 0x6e },
  { "LDX (A,X)", 0x43, 9, 0, 0xa8 },
  { "LDX (A,Y)", 0x43, 9, 0, 0xb8 },
  { "LDX (A,U)", 0x43, 9, 0, 0xd8 },
  { "LDX (A,S)", 0x43, 9, 0, 0xe8 },
  { "LDX (B,X)", 0x43, 9, 0, 0xa9 },
  { "LDX (B,Y)", 0x43, 9, 0, 0xb9 },
  { "LDX (B,U)", 0x43, 9, 0, 0xd9 },
  { "LDX (B,S)", 0x43, 9, 0, 0xe9 },
  { "LDX (D,X)", 0x43, 9, 0, 0xaf },
  { "LDX (D,Y)", 0x43, 9, 0, 0xbf },
  { "LDX (D,U)", 0x43, 9, 0, 0xdf },
  { "LDX (D,S)", 0x43, 9, 0, 0xef },
  { "LDX (,X++)", 0x43, 9, 0, 0x29 },
  { "LDX (,Y++)", 0x43, 9, 0, 0x39 },
  { "LDX (,U++)", 0x43, 9, 0, 0x59 },
  { "LDX (,S++)", 0x43, 9, 0, 0x69 },
  { "LDX (,--X)", 0x43, 9, 0, 0x2b },
  { "LDX (,--Y)", 0x43, 9, 0, 0x3b },
  { "LDX (,--U)", 0x43, 9, 0, 0x5b },
  { "LDX (,--S)", 0x43, 9, 0, 0x6b },
  { "LDX (x,X)", 0x43, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDX (x,Y)", 0x43, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDX (x,U)", 0x43, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDX (x,S)", 0x43, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDX (?,X)", 0x43, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDX (?,Y)", 0x43, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDX (?,U)", 0x43, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDX (?,S)", 0x43, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDX (x,PCR)", 0x43, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDX (?,PCR)", 0x43, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDX (?)", 0x43, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDX s,X", 0x43, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDX s,Y", 0x43, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDX s,U", 0x43, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDX s,S", 0x43, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDX x,X", 0x43, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDX x,Y", 0x43, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDX x,U", 0x43, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDX x,S", 0x43, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDX ?,X", 0x43, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDX ?,Y", 0x43, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDX ?,U", 0x43, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDX ?,S", 0x43, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDX x,PCR", 0x43, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDX ?,PCR", 0x43, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDX x", 0x43, 2, 1, 0x07 },
  { "LDX ?", 0x43, 2, 0, 0x07 },

  { "LDY #x", 0x44, 13, 0, 0 },
  { "LDY,X", 0x45, 9, 0, 0x26 },
  { "LDY,Y", 0x45, 9, 0, 0x36 },
  { "LDY,U", 0x45, 9, 0, 0x56 },
  { "LDY,S", 0x45, 9, 0, 0x66 },
  { "LDY A,X", 0x45, 9, 0, 0xa0 },
  { "LDY A,Y", 0x45, 9, 0, 0xb0 },
  { "LDY A,U", 0x45, 9, 0, 0xd0 },
  { "LDY A,S", 0x45, 9, 0, 0xe0 },
  { "LDY B,X", 0x45, 9, 0, 0xa1 },
  { "LDY B,Y", 0x45, 9, 0, 0xb1 },
  { "LDY B,U", 0x45, 9, 0, 0xd1 },
  { "LDY B,S", 0x45, 9, 0, 0xe1 },
  { "LDY D,X", 0x45, 9, 0, 0xa7 },
  { "LDY D,Y", 0x45, 9, 0, 0xb7 },
  { "LDY D,U", 0x45, 9, 0, 0xd7 },
  { "LDY D,S", 0x45, 9, 0, 0xe8 },
  { "LDY,X+", 0x45, 9, 0, 0x20 },
  { "LDY,Y+", 0x45, 9, 0, 0x30 },
  { "LDY,U+", 0x45, 9, 0, 0x50 },
  { "LDY,S+", 0x45, 9, 0, 0x60 },
  { "LDY,X++", 0x45, 9, 0, 0x21 },
  { "LDY,Y++", 0x45, 9, 0, 0x31 },
  { "LDY,U++", 0x45, 9, 0, 0x51 },
  { "LDY,S++", 0x45, 9, 0, 0x61 },
  { "LDY,-X", 0x45, 9, 0, 0x22 },
  { "LDY,-Y", 0x45, 9, 0, 0x32 },
  { "LDY,-U", 0x45, 9, 0, 0x52 },
  { "LDY,-S", 0x45, 9, 0, 0x62 },
  { "LDY,--X", 0x45, 9, 0, 0x23 },
  { "LDY,--Y", 0x45, 9, 0, 0x33 },
  { "LDY,--U", 0x45, 9, 0, 0x53 },
  { "LDY,--S", 0x45, 9, 0, 0x63 },
  { "LDY (,X)", 0x45, 9, 0, 0x2e },
  { "LDY (,Y)", 0x45, 9, 0, 0x3e },
  { "LDY (,U)", 0x45, 9, 0, 0x5e },
  { "LDY (,S)", 0x45, 9, 0, 0x6e },
  { "LDY (A,X)", 0x45, 9, 0, 0xa8 },
  { "LDY (A,Y)", 0x45, 9, 0, 0xb8 },
  { "LDY (A,U)", 0x45, 9, 0, 0xd8 },
  { "LDY (A,S)", 0x45, 9, 0, 0xe8 },
  { "LDY (B,X)", 0x45, 9, 0, 0xa9 },
  { "LDY (B,Y)", 0x45, 9, 0, 0xb9 },
  { "LDY (B,U)", 0x45, 9, 0, 0xd9 },
  { "LDY (B,S)", 0x45, 9, 0, 0xe9 },
  { "LDY (D,X)", 0x45, 9, 0, 0xaf },
  { "LDY (D,Y)", 0x45, 9, 0, 0xbf },
  { "LDY (D,U)", 0x45, 9, 0, 0xdf },
  { "LDY (D,S)", 0x45, 9, 0, 0xef },
  { "LDY (,X++)", 0x45, 9, 0, 0x29 },
  { "LDY (,Y++)", 0x45, 9, 0, 0x39 },
  { "LDY (,U++)", 0x45, 9, 0, 0x59 },
  { "LDY (,S++)", 0x45, 9, 0, 0x69 },
  { "LDY (,--X)", 0x45, 9, 0, 0x2b },
  { "LDY (,--Y)", 0x45, 9, 0, 0x3b },
  { "LDY (,--U)", 0x45, 9, 0, 0x5b },
  { "LDY (,--S)", 0x45, 9, 0, 0x6b },
  { "LDY (x,X)", 0x45, 7, 1, 0x2c }, /* 8-bit offset */
  { "LDY (x,Y)", 0x45, 7, 1, 0x3c }, /* 8-bit offset */
  { "LDY (x,U)", 0x45, 7, 1, 0x5c }, /* 8-bit offset */
  { "LDY (x,S)", 0x45, 7, 1, 0x6c }, /* 8-bit offset */
  { "LDY (?,X)", 0x45, 8, 0, 0x2d }, /* 16-bit offset */
  { "LDY (?,Y)", 0x45, 8, 0, 0x3d }, /* 16-bit offset */
  { "LDY (?,U)", 0x45, 8, 0, 0x5d }, /* 16-bit offset */
  { "LDY (?,S)", 0x45, 8, 0, 0x6d }, /* 16-bit offset */
  { "LDY (x,PCR)", 0x45, 7, 1, 0x7c }, /* 8-bit offset */
  { "LDY (?,PCR)", 0x45, 8, 0, 0x7d }, /* 16-bit offset */
  { "LDY (?)", 0x45, 8, 0, 0x0f }, /* 16-bit offset */
  { "LDY s,X", 0x45, 6, 1, 0x26 }, /* 5-bit offset */
  { "LDY s,Y", 0x45, 6, 1, 0x36 }, /* 5-bit offset */
  { "LDY s,U", 0x45, 6, 1, 0x56 }, /* 5-bit offset */
  { "LDY s,S", 0x45, 6, 1, 0x66 }, /* 5-bit offset */
  { "LDY x,X", 0x45, 7, 1, 0x24 }, /* 8-bit offset */
  { "LDY x,Y", 0x45, 7, 1, 0x34 }, /* 8-bit offset */
  { "LDY x,U", 0x45, 7, 1, 0x54 }, /* 8-bit offset */
  { "LDY x,S", 0x45, 7, 1, 0x64 }, /* 8-bit offset */
  { "LDY ?,X", 0x45, 8, 0, 0x25 }, /* 16-bit offset */
  { "LDY ?,Y", 0x45, 8, 0, 0x35 }, /* 16-bit offset */
  { "LDY ?,U", 0x45, 8, 0, 0x55 }, /* 16-bit offset */
  { "LDY ?,S", 0x45, 8, 0, 0x65 }, /* 16-bit offset */
  { "LDY x,PCR", 0x45, 7, 1, 0x74 }, /* 8-bit offset */
  { "LDY ?,PCR", 0x45, 8, 0, 0x75 }, /* 16-bit offset */
  { "LDY x", 0x45, 2, 1, 0x07 },
  { "LDY ?", 0x45, 2, 0, 0x07 },

  { "LEAS,X", 0x0b, 9, 0, 0x26 },
  { "LEAS,Y", 0x0b, 9, 0, 0x36 },
  { "LEAS,U", 0x0b, 9, 0, 0x56 },
  { "LEAS,S", 0x0b, 9, 0, 0x66 },
  { "LEAS A,X", 0x0b, 9, 0, 0xa0 },
  { "LEAS A,Y", 0x0b, 9, 0, 0xb0 },
  { "LEAS A,U", 0x0b, 9, 0, 0xd0 },
  { "LEAS A,S", 0x0b, 9, 0, 0xe0 },
  { "LEAS B,X", 0x0b, 9, 0, 0xa1 },
  { "LEAS B,Y", 0x0b, 9, 0, 0xb1 },
  { "LEAS B,U", 0x0b, 9, 0, 0xd1 },
  { "LEAS B,S", 0x0b, 9, 0, 0xe1 },
  { "LEAS D,X", 0x0b, 9, 0, 0xa7 },
  { "LEAS D,Y", 0x0b, 9, 0, 0xb7 },
  { "LEAS D,U", 0x0b, 9, 0, 0xd7 },
  { "LEAS D,S", 0x0b, 9, 0, 0xe8 },
  { "LEAS,X+", 0x0b, 9, 0, 0x20 },
  { "LEAS,Y+", 0x0b, 9, 0, 0x30 },
  { "LEAS,U+", 0x0b, 9, 0, 0x50 },
  { "LEAS,S+", 0x0b, 9, 0, 0x60 },
  { "LEAS,X++", 0x0b, 9, 0, 0x21 },
  { "LEAS,Y++", 0x0b, 9, 0, 0x31 },
  { "LEAS,U++", 0x0b, 9, 0, 0x51 },
  { "LEAS,S++", 0x0b, 9, 0, 0x61 },
  { "LEAS,-X", 0x0b, 9, 0, 0x22 },
  { "LEAS,-Y", 0x0b, 9, 0, 0x32 },
  { "LEAS,-U", 0x0b, 9, 0, 0x52 },
  { "LEAS,-S", 0x0b, 9, 0, 0x62 },
  { "LEAS,--X", 0x0b, 9, 0, 0x23 },
  { "LEAS,--Y", 0x0b, 9, 0, 0x33 },
  { "LEAS,--U", 0x0b, 9, 0, 0x53 },
  { "LEAS,--S", 0x0b, 9, 0, 0x63 },
  { "LEAS (,X)", 0x0b, 9, 0, 0x2e },
  { "LEAS (,Y)", 0x0b, 9, 0, 0x3e },
  { "LEAS (,U)", 0x0b, 9, 0, 0x5e },
  { "LEAS (,S)", 0x0b, 9, 0, 0x6e },
  { "LEAS (A,X)", 0x0b, 9, 0, 0xa8 },
  { "LEAS (A,Y)", 0x0b, 9, 0, 0xb8 },
  { "LEAS (A,U)", 0x0b, 9, 0, 0xd8 },
  { "LEAS (A,S)", 0x0b, 9, 0, 0xe8 },
  { "LEAS (B,X)", 0x0b, 9, 0, 0xa9 },
  { "LEAS (B,Y)", 0x0b, 9, 0, 0xb9 },
  { "LEAS (B,U)", 0x0b, 9, 0, 0xd9 },
  { "LEAS (B,S)", 0x0b, 9, 0, 0xe9 },
  { "LEAS (D,X)", 0x0b, 9, 0, 0xaf },
  { "LEAS (D,Y)", 0x0b, 9, 0, 0xbf },
  { "LEAS (D,U)", 0x0b, 9, 0, 0xdf },
  { "LEAS (D,S)", 0x0b, 9, 0, 0xef },
  { "LEAS (,X++)", 0x0b, 9, 0, 0x29 },
  { "LEAS (,Y++)", 0x0b, 9, 0, 0x39 },
  { "LEAS (,U++)", 0x0b, 9, 0, 0x59 },
  { "LEAS (,S++)", 0x0b, 9, 0, 0x69 },
  { "LEAS (,--X)", 0x0b, 9, 0, 0x2b },
  { "LEAS (,--Y)", 0x0b, 9, 0, 0x3b },
  { "LEAS (,--U)", 0x0b, 9, 0, 0x5b },
  { "LEAS (,--S)", 0x0b, 9, 0, 0x6b },
  { "LEAS (x,X)", 0x0b, 7, 1, 0x2c }, /* 8-bit offset */
  { "LEAS (x,Y)", 0x0b, 7, 1, 0x3c }, /* 8-bit offset */
  { "LEAS (x,U)", 0x0b, 7, 1, 0x5c }, /* 8-bit offset */
  { "LEAS (x,S)", 0x0b, 7, 1, 0x6c }, /* 8-bit offset */
  { "LEAS (?,X)", 0x0b, 8, 0, 0x2d }, /* 16-bit offset */
  { "LEAS (?,Y)", 0x0b, 8, 0, 0x3d }, /* 16-bit offset */
  { "LEAS (?,U)", 0x0b, 8, 0, 0x5d }, /* 16-bit offset */
  { "LEAS (?,S)", 0x0b, 8, 0, 0x6d }, /* 16-bit offset */
  { "LEAS (x,PCR)", 0x0b, 7, 1, 0x7c }, /* 8-bit offset */
  { "LEAS (?,PCR)", 0x0b, 8, 0, 0x7d }, /* 16-bit offset */
  { "LEAS (?)", 0x0b, 8, 0, 0x0f }, /* 16-bit offset */
  { "LEAS s,X", 0x0b, 6, 1, 0x26 }, /* 5-bit offset */
  { "LEAS s,Y", 0x0b, 6, 1, 0x36 }, /* 5-bit offset */
  { "LEAS s,U", 0x0b, 6, 1, 0x56 }, /* 5-bit offset */
  { "LEAS s,S", 0x0b, 6, 1, 0x66 }, /* 5-bit offset */
  { "LEAS x,X", 0x0b, 7, 1, 0x24 }, /* 8-bit offset */
  { "LEAS x,Y", 0x0b, 7, 1, 0x34 }, /* 8-bit offset */
  { "LEAS x,U", 0x0b, 7, 1, 0x54 }, /* 8-bit offset */
  { "LEAS x,S", 0x0b, 7, 1, 0x64 }, /* 8-bit offset */
  { "LEAS ?,X", 0x0b, 8, 0, 0x25 }, /* 16-bit offset */
  { "LEAS ?,Y", 0x0b, 8, 0, 0x35 }, /* 16-bit offset */
  { "LEAS ?,U", 0x0b, 8, 0, 0x55 }, /* 16-bit offset */
  { "LEAS ?,S", 0x0b, 8, 0, 0x65 }, /* 16-bit offset */
  { "LEAS x,PCR", 0x0b, 7, 1, 0x74 }, /* 8-bit offset */
  { "LEAS ?,PCR", 0x0b, 8, 0, 0x75 }, /* 16-bit offset */

  { "LEAU,X", 0x0a, 9, 0, 0x26 },
  { "LEAU,Y", 0x0a, 9, 0, 0x36 },
  { "LEAU,U", 0x0a, 9, 0, 0x56 },
  { "LEAU,S", 0x0a, 9, 0, 0x66 },
  { "LEAU A,X", 0x0a, 9, 0, 0xa0 },
  { "LEAU A,Y", 0x0a, 9, 0, 0xb0 },
  { "LEAU A,U", 0x0a, 9, 0, 0xd0 },
  { "LEAU A,S", 0x0a, 9, 0, 0xe0 },
  { "LEAU B,X", 0x0a, 9, 0, 0xa1 },
  { "LEAU B,Y", 0x0a, 9, 0, 0xb1 },
  { "LEAU B,U", 0x0a, 9, 0, 0xd1 },
  { "LEAU B,S", 0x0a, 9, 0, 0xe1 },
  { "LEAU D,X", 0x0a, 9, 0, 0xa7 },
  { "LEAU D,Y", 0x0a, 9, 0, 0xb7 },
  { "LEAU D,U", 0x0a, 9, 0, 0xd7 },
  { "LEAU D,S", 0x0a, 9, 0, 0xe8 },
  { "LEAU,X+", 0x0a, 9, 0, 0x20 },
  { "LEAU,Y+", 0x0a, 9, 0, 0x30 },
  { "LEAU,U+", 0x0a, 9, 0, 0x50 },
  { "LEAU,S+", 0x0a, 9, 0, 0x60 },
  { "LEAU,X++", 0x0a, 9, 0, 0x21 },
  { "LEAU,Y++", 0x0a, 9, 0, 0x31 },
  { "LEAU,U++", 0x0a, 9, 0, 0x51 },
  { "LEAU,S++", 0x0a, 9, 0, 0x61 },
  { "LEAU,-X", 0x0a, 9, 0, 0x22 },
  { "LEAU,-Y", 0x0a, 9, 0, 0x32 },
  { "LEAU,-U", 0x0a, 9, 0, 0x52 },
  { "LEAU,-S", 0x0a, 9, 0, 0x62 },
  { "LEAU,--X", 0x0a, 9, 0, 0x23 },
  { "LEAU,--Y", 0x0a, 9, 0, 0x33 },
  { "LEAU,--U", 0x0a, 9, 0, 0x53 },
  { "LEAU,--S", 0x0a, 9, 0, 0x63 },
  { "LEAU (,X)", 0x0a, 9, 0, 0x2e },
  { "LEAU (,Y)", 0x0a, 9, 0, 0x3e },
  { "LEAU (,U)", 0x0a, 9, 0, 0x5e },
  { "LEAU (,S)", 0x0a, 9, 0, 0x6e },
  { "LEAU (A,X)", 0x0a, 9, 0, 0xa8 },
  { "LEAU (A,Y)", 0x0a, 9, 0, 0xb8 },
  { "LEAU (A,U)", 0x0a, 9, 0, 0xd8 },
  { "LEAU (A,S)", 0x0a, 9, 0, 0xe8 },
  { "LEAU (B,X)", 0x0a, 9, 0, 0xa9 },
  { "LEAU (B,Y)", 0x0a, 9, 0, 0xb9 },
  { "LEAU (B,U)", 0x0a, 9, 0, 0xd9 },
  { "LEAU (B,S)", 0x0a, 9, 0, 0xe9 },
  { "LEAU (D,X)", 0x0a, 9, 0, 0xaf },
  { "LEAU (D,Y)", 0x0a, 9, 0, 0xbf },
  { "LEAU (D,U)", 0x0a, 9, 0, 0xdf },
  { "LEAU (D,S)", 0x0a, 9, 0, 0xef },
  { "LEAU (,X++)", 0x0a, 9, 0, 0x29 },
  { "LEAU (,Y++)", 0x0a, 9, 0, 0x39 },
  { "LEAU (,U++)", 0x0a, 9, 0, 0x59 },
  { "LEAU (,S++)", 0x0a, 9, 0, 0x69 },
  { "LEAU (,--X)", 0x0a, 9, 0, 0x2b },
  { "LEAU (,--Y)", 0x0a, 9, 0, 0x3b },
  { "LEAU (,--U)", 0x0a, 9, 0, 0x5b },
  { "LEAU (,--S)", 0x0a, 9, 0, 0x6b },
  { "LEAU (x,X)", 0x0a, 7, 1, 0x2c }, /* 8-bit offset */
  { "LEAU (x,Y)", 0x0a, 7, 1, 0x3c }, /* 8-bit offset */
  { "LEAU (x,U)", 0x0a, 7, 1, 0x5c }, /* 8-bit offset */
  { "LEAU (x,S)", 0x0a, 7, 1, 0x6c }, /* 8-bit offset */
  { "LEAU (?,X)", 0x0a, 8, 0, 0x2d }, /* 16-bit offset */
  { "LEAU (?,Y)", 0x0a, 8, 0, 0x3d }, /* 16-bit offset */
  { "LEAU (?,U)", 0x0a, 8, 0, 0x5d }, /* 16-bit offset */
  { "LEAU (?,S)", 0x0a, 8, 0, 0x6d }, /* 16-bit offset */
  { "LEAU (x,PCR)", 0x0a, 7, 1, 0x7c }, /* 8-bit offset */
  { "LEAU (?,PCR)", 0x0a, 8, 0, 0x7d }, /* 16-bit offset */
  { "LEAU (?)", 0x0a, 8, 0, 0x0f }, /* 16-bit offset */
  { "LEAU s,X", 0x0a, 6, 1, 0x26 }, /* 5-bit offset */
  { "LEAU s,Y", 0x0a, 6, 1, 0x36 }, /* 5-bit offset */
  { "LEAU s,U", 0x0a, 6, 1, 0x56 }, /* 5-bit offset */
  { "LEAU s,S", 0x0a, 6, 1, 0x66 }, /* 5-bit offset */
  { "LEAU x,X", 0x0a, 7, 1, 0x24 }, /* 8-bit offset */
  { "LEAU x,Y", 0x0a, 7, 1, 0x34 }, /* 8-bit offset */
  { "LEAU x,U", 0x0a, 7, 1, 0x54 }, /* 8-bit offset */
  { "LEAU x,S", 0x0a, 7, 1, 0x64 }, /* 8-bit offset */
  { "LEAU ?,X", 0x0a, 8, 0, 0x25 }, /* 16-bit offset */
  { "LEAU ?,Y", 0x0a, 8, 0, 0x35 }, /* 16-bit offset */
  { "LEAU ?,U", 0x0a, 8, 0, 0x55 }, /* 16-bit offset */
  { "LEAU ?,S", 0x0a, 8, 0, 0x65 }, /* 16-bit offset */
  { "LEAU x,PCR", 0x0a, 7, 1, 0x74 }, /* 8-bit offset */
  { "LEAU ?,PCR", 0x0a, 8, 0, 0x75 }, /* 16-bit offset */

  { "LEAX,X", 0x08, 9, 0, 0x26 },
  { "LEAX,Y", 0x08, 9, 0, 0x36 },
  { "LEAX,U", 0x08, 9, 0, 0x56 },
  { "LEAX,S", 0x08, 9, 0, 0x66 },
  { "LEAX A,X", 0x08, 9, 0, 0xa0 },
  { "LEAX A,Y", 0x08, 9, 0, 0xb0 },
  { "LEAX A,U", 0x08, 9, 0, 0xd0 },
  { "LEAX A,S", 0x08, 9, 0, 0xe0 },
  { "LEAX B,X", 0x08, 9, 0, 0xa1 },
  { "LEAX B,Y", 0x08, 9, 0, 0xb1 },
  { "LEAX B,U", 0x08, 9, 0, 0xd1 },
  { "LEAX B,S", 0x08, 9, 0, 0xe1 },
  { "LEAX D,X", 0x08, 9, 0, 0xa7 },
  { "LEAX D,Y", 0x08, 9, 0, 0xb7 },
  { "LEAX D,U", 0x08, 9, 0, 0xd7 },
  { "LEAX D,S", 0x08, 9, 0, 0xe8 },
  { "LEAX,X+", 0x08, 9, 0, 0x20 },
  { "LEAX,Y+", 0x08, 9, 0, 0x30 },
  { "LEAX,U+", 0x08, 9, 0, 0x50 },
  { "LEAX,S+", 0x08, 9, 0, 0x60 },
  { "LEAX,X++", 0x08, 9, 0, 0x21 },
  { "LEAX,Y++", 0x08, 9, 0, 0x31 },
  { "LEAX,U++", 0x08, 9, 0, 0x51 },
  { "LEAX,S++", 0x08, 9, 0, 0x61 },
  { "LEAX,-X", 0x08, 9, 0, 0x22 },
  { "LEAX,-Y", 0x08, 9, 0, 0x32 },
  { "LEAX,-U", 0x08, 9, 0, 0x52 },
  { "LEAX,-S", 0x08, 9, 0, 0x62 },
  { "LEAX,--X", 0x08, 9, 0, 0x23 },
  { "LEAX,--Y", 0x08, 9, 0, 0x33 },
  { "LEAX,--U", 0x08, 9, 0, 0x53 },
  { "LEAX,--S", 0x08, 9, 0, 0x63 },
  { "LEAX (,X)", 0x08, 9, 0, 0x2e },
  { "LEAX (,Y)", 0x08, 9, 0, 0x3e },
  { "LEAX (,U)", 0x08, 9, 0, 0x5e },
  { "LEAX (,S)", 0x08, 9, 0, 0x6e },
  { "LEAX (A,X)", 0x08, 9, 0, 0xa8 },
  { "LEAX (A,Y)", 0x08, 9, 0, 0xb8 },
  { "LEAX (A,U)", 0x08, 9, 0, 0xd8 },
  { "LEAX (A,S)", 0x08, 9, 0, 0xe8 },
  { "LEAX (B,X)", 0x08, 9, 0, 0xa9 },
  { "LEAX (B,Y)", 0x08, 9, 0, 0xb9 },
  { "LEAX (B,U)", 0x08, 9, 0, 0xd9 },
  { "LEAX (B,S)", 0x08, 9, 0, 0xe9 },
  { "LEAX (D,X)", 0x08, 9, 0, 0xaf },
  { "LEAX (D,Y)", 0x08, 9, 0, 0xbf },
  { "LEAX (D,U)", 0x08, 9, 0, 0xdf },
  { "LEAX (D,S)", 0x08, 9, 0, 0xef },
  { "LEAX (,X++)", 0x08, 9, 0, 0x29 },
  { "LEAX (,Y++)", 0x08, 9, 0, 0x39 },
  { "LEAX (,U++)", 0x08, 9, 0, 0x59 },
  { "LEAX (,S++)", 0x08, 9, 0, 0x69 },
  { "LEAX (,--X)", 0x08, 9, 0, 0x2b },
  { "LEAX (,--Y)", 0x08, 9, 0, 0x3b },
  { "LEAX (,--U)", 0x08, 9, 0, 0x5b },
  { "LEAX (,--S)", 0x08, 9, 0, 0x6b },
  { "LEAX (x,X)", 0x08, 7, 1, 0x2c }, /* 8-bit offset */
  { "LEAX (x,Y)", 0x08, 7, 1, 0x3c }, /* 8-bit offset */
  { "LEAX (x,U)", 0x08, 7, 1, 0x5c }, /* 8-bit offset */
  { "LEAX (x,S)", 0x08, 7, 1, 0x6c }, /* 8-bit offset */
  { "LEAX (?,X)", 0x08, 8, 0, 0x2d }, /* 16-bit offset */
  { "LEAX (?,Y)", 0x08, 8, 0, 0x3d }, /* 16-bit offset */
  { "LEAX (?,U)", 0x08, 8, 0, 0x5d }, /* 16-bit offset */
  { "LEAX (?,S)", 0x08, 8, 0, 0x6d }, /* 16-bit offset */
  { "LEAX (x,PCR)", 0x08, 7, 1, 0x7c }, /* 8-bit offset */
  { "LEAX (?,PCR)", 0x08, 8, 0, 0x7d }, /* 16-bit offset */
  { "LEAX (?)", 0x08, 8, 0, 0x0f }, /* 16-bit offset */
  { "LEAX s,X", 0x08, 6, 1, 0x26 }, /* 5-bit offset */
  { "LEAX s,Y", 0x08, 6, 1, 0x36 }, /* 5-bit offset */
  { "LEAX s,U", 0x08, 6, 1, 0x56 }, /* 5-bit offset */
  { "LEAX s,S", 0x08, 6, 1, 0x66 }, /* 5-bit offset */
  { "LEAX x,X", 0x08, 7, 1, 0x24 }, /* 8-bit offset */
  { "LEAX x,Y", 0x08, 7, 1, 0x34 }, /* 8-bit offset */
  { "LEAX x,U", 0x08, 7, 1, 0x54 }, /* 8-bit offset */
  { "LEAX x,S", 0x08, 7, 1, 0x64 }, /* 8-bit offset */
  { "LEAX ?,X", 0x08, 8, 0, 0x25 }, /* 16-bit offset */
  { "LEAX ?,Y", 0x08, 8, 0, 0x35 }, /* 16-bit offset */
  { "LEAX ?,U", 0x08, 8, 0, 0x55 }, /* 16-bit offset */
  { "LEAX ?,S", 0x08, 8, 0, 0x65 }, /* 16-bit offset */
  { "LEAX x,PCR", 0x08, 7, 1, 0x74 }, /* 8-bit offset */
  { "LEAX ?,PCR", 0x08, 8, 0, 0x75 }, /* 16-bit offset */

  { "LEAY,X", 0x09, 9, 0, 0x26 },
  { "LEAY,Y", 0x09, 9, 0, 0x36 },
  { "LEAY,U", 0x09, 9, 0, 0x56 },
  { "LEAY,S", 0x09, 9, 0, 0x66 },
  { "LEAY A,X", 0x09, 9, 0, 0xa0 },
  { "LEAY A,Y", 0x09, 9, 0, 0xb0 },
  { "LEAY A,U", 0x09, 9, 0, 0xd0 },
  { "LEAY A,S", 0x09, 9, 0, 0xe0 },
  { "LEAY B,X", 0x09, 9, 0, 0xa1 },
  { "LEAY B,Y", 0x09, 9, 0, 0xb1 },
  { "LEAY B,U", 0x09, 9, 0, 0xd1 },
  { "LEAY B,S", 0x09, 9, 0, 0xe1 },
  { "LEAY D,X", 0x09, 9, 0, 0xa7 },
  { "LEAY D,Y", 0x09, 9, 0, 0xb7 },
  { "LEAY D,U", 0x09, 9, 0, 0xd7 },
  { "LEAY D,S", 0x09, 9, 0, 0xe8 },
  { "LEAY,X+", 0x09, 9, 0, 0x20 },
  { "LEAY,Y+", 0x09, 9, 0, 0x30 },
  { "LEAY,U+", 0x09, 9, 0, 0x50 },
  { "LEAY,S+", 0x09, 9, 0, 0x60 },
  { "LEAY,X++", 0x09, 9, 0, 0x21 },
  { "LEAY,Y++", 0x09, 9, 0, 0x31 },
  { "LEAY,U++", 0x09, 9, 0, 0x51 },
  { "LEAY,S++", 0x09, 9, 0, 0x61 },
  { "LEAY,-X", 0x09, 9, 0, 0x22 },
  { "LEAY,-Y", 0x09, 9, 0, 0x32 },
  { "LEAY,-U", 0x09, 9, 0, 0x52 },
  { "LEAY,-S", 0x09, 9, 0, 0x62 },
  { "LEAY,--X", 0x09, 9, 0, 0x23 },
  { "LEAY,--Y", 0x09, 9, 0, 0x33 },
  { "LEAY,--U", 0x09, 9, 0, 0x53 },
  { "LEAY,--S", 0x09, 9, 0, 0x63 },
  { "LEAY (,X)", 0x09, 9, 0, 0x2e },
  { "LEAY (,Y)", 0x09, 9, 0, 0x3e },
  { "LEAY (,U)", 0x09, 9, 0, 0x5e },
  { "LEAY (,S)", 0x09, 9, 0, 0x6e },
  { "LEAY (A,X)", 0x09, 9, 0, 0xa8 },
  { "LEAY (A,Y)", 0x09, 9, 0, 0xb8 },
  { "LEAY (A,U)", 0x09, 9, 0, 0xd8 },
  { "LEAY (A,S)", 0x09, 9, 0, 0xe8 },
  { "LEAY (B,X)", 0x09, 9, 0, 0xa9 },
  { "LEAY (B,Y)", 0x09, 9, 0, 0xb9 },
  { "LEAY (B,U)", 0x09, 9, 0, 0xd9 },
  { "LEAY (B,S)", 0x09, 9, 0, 0xe9 },
  { "LEAY (D,X)", 0x09, 9, 0, 0xaf },
  { "LEAY (D,Y)", 0x09, 9, 0, 0xbf },
  { "LEAY (D,U)", 0x09, 9, 0, 0xdf },
  { "LEAY (D,S)", 0x09, 9, 0, 0xef },
  { "LEAY (,X++)", 0x09, 9, 0, 0x29 },
  { "LEAY (,Y++)", 0x09, 9, 0, 0x39 },
  { "LEAY (,U++)", 0x09, 9, 0, 0x59 },
  { "LEAY (,S++)", 0x09, 9, 0, 0x69 },
  { "LEAY (,--X)", 0x09, 9, 0, 0x2b },
  { "LEAY (,--Y)", 0x09, 9, 0, 0x3b },
  { "LEAY (,--U)", 0x09, 9, 0, 0x5b },
  { "LEAY (,--S)", 0x09, 9, 0, 0x6b },
  { "LEAY (x,X)", 0x09, 7, 1, 0x2c }, /* 8-bit offset */
  { "LEAY (x,Y)", 0x09, 7, 1, 0x3c }, /* 8-bit offset */
  { "LEAY (x,U)", 0x09, 7, 1, 0x5c }, /* 8-bit offset */
  { "LEAY (x,S)", 0x09, 7, 1, 0x6c }, /* 8-bit offset */
  { "LEAY (?,X)", 0x09, 8, 0, 0x2d }, /* 16-bit offset */
  { "LEAY (?,Y)", 0x09, 8, 0, 0x3d }, /* 16-bit offset */
  { "LEAY (?,U)", 0x09, 8, 0, 0x5d }, /* 16-bit offset */
  { "LEAY (?,S)", 0x09, 8, 0, 0x6d }, /* 16-bit offset */
  { "LEAY (x,PCR)", 0x09, 7, 1, 0x7c }, /* 8-bit offset */
  { "LEAY (?,PCR)", 0x09, 8, 0, 0x7d }, /* 16-bit offset */
  { "LEAY (?)", 0x09, 8, 0, 0x0f }, /* 16-bit offset */
  { "LEAY s,X", 0x09, 6, 1, 0x26 }, /* 5-bit offset */
  { "LEAY s,Y", 0x09, 6, 1, 0x36 }, /* 5-bit offset */
  { "LEAY s,U", 0x09, 6, 1, 0x56 }, /* 5-bit offset */
  { "LEAY s,S", 0x09, 6, 1, 0x66 }, /* 5-bit offset */
  { "LEAY x,X", 0x09, 7, 1, 0x24 }, /* 8-bit offset */
  { "LEAY x,Y", 0x09, 7, 1, 0x34 }, /* 8-bit offset */
  { "LEAY x,U", 0x09, 7, 1, 0x54 }, /* 8-bit offset */
  { "LEAY x,S", 0x09, 7, 1, 0x64 }, /* 8-bit offset */
  { "LEAY ?,X", 0x09, 8, 0, 0x25 }, /* 16-bit offset */
  { "LEAY ?,Y", 0x09, 8, 0, 0x35 }, /* 16-bit offset */
  { "LEAY ?,U", 0x09, 8, 0, 0x55 }, /* 16-bit offset */
  { "LEAY ?,S", 0x09, 8, 0, 0x65 }, /* 16-bit offset */
  { "LEAY x,PCR", 0x09, 7, 1, 0x74 }, /* 8-bit offset */
  { "LEAY ?,PCR", 0x09, 8, 0, 0x75 }, /* 16-bit offset */

  { "LSLA", 0x9c, 0, 0, 0 },
  { "LSLB", 0x9d, 0, 0, 0 },
  { "LSL,X", 0x9e, 9, 0, 0x26 },
  { "LSL,Y", 0x9e, 9, 0, 0x36 },
  { "LSL,U", 0x9e, 9, 0, 0x56 },
  { "LSL,S", 0x9e, 9, 0, 0x66 },
  { "LSL A,X", 0x9e, 9, 0, 0xa0 },
  { "LSL A,Y", 0x9e, 9, 0, 0xb0 },
  { "LSL A,U", 0x9e, 9, 0, 0xd0 },
  { "LSL A,S", 0x9e, 9, 0, 0xe0 },
  { "LSL B,X", 0x9e, 9, 0, 0xa1 },
  { "LSL B,Y", 0x9e, 9, 0, 0xb1 },
  { "LSL B,U", 0x9e, 9, 0, 0xd1 },
  { "LSL B,S", 0x9e, 9, 0, 0xe1 },
  { "LSL D,X", 0x9e, 9, 0, 0xa7 },
  { "LSL D,Y", 0x9e, 9, 0, 0xb7 },
  { "LSL D,U", 0x9e, 9, 0, 0xd7 },
  { "LSL D,S", 0x9e, 9, 0, 0xe8 },
  { "LSL,X+", 0x9e, 9, 0, 0x20 },
  { "LSL,Y+", 0x9e, 9, 0, 0x30 },
  { "LSL,U+", 0x9e, 9, 0, 0x50 },
  { "LSL,S+", 0x9e, 9, 0, 0x60 },
  { "LSL,X++", 0x9e, 9, 0, 0x21 },
  { "LSL,Y++", 0x9e, 9, 0, 0x31 },
  { "LSL,U++", 0x9e, 9, 0, 0x51 },
  { "LSL,S++", 0x9e, 9, 0, 0x61 },
  { "LSL,-X", 0x9e, 9, 0, 0x22 },
  { "LSL,-Y", 0x9e, 9, 0, 0x32 },
  { "LSL,-U", 0x9e, 9, 0, 0x52 },
  { "LSL,-S", 0x9e, 9, 0, 0x62 },
  { "LSL,--X", 0x9e, 9, 0, 0x23 },
  { "LSL,--Y", 0x9e, 9, 0, 0x33 },
  { "LSL,--U", 0x9e, 9, 0, 0x53 },
  { "LSL,--S", 0x9e, 9, 0, 0x63 },
  { "LSL (,X)", 0x9e, 9, 0, 0x2e },
  { "LSL (,Y)", 0x9e, 9, 0, 0x3e },
  { "LSL (,U)", 0x9e, 9, 0, 0x5e },
  { "LSL (,S)", 0x9e, 9, 0, 0x6e },
  { "LSL (A,X)", 0x9e, 9, 0, 0xa8 },
  { "LSL (A,Y)", 0x9e, 9, 0, 0xb8 },
  { "LSL (A,U)", 0x9e, 9, 0, 0xd8 },
  { "LSL (A,S)", 0x9e, 9, 0, 0xe8 },
  { "LSL (B,X)", 0x9e, 9, 0, 0xa9 },
  { "LSL (B,Y)", 0x9e, 9, 0, 0xb9 },
  { "LSL (B,U)", 0x9e, 9, 0, 0xd9 },
  { "LSL (B,S)", 0x9e, 9, 0, 0xe9 },
  { "LSL (D,X)", 0x9e, 9, 0, 0xaf },
  { "LSL (D,Y)", 0x9e, 9, 0, 0xbf },
  { "LSL (D,U)", 0x9e, 9, 0, 0xdf },
  { "LSL (D,S)", 0x9e, 9, 0, 0xef },
  { "LSL (,X++)", 0x9e, 9, 0, 0x29 },
  { "LSL (,Y++)", 0x9e, 9, 0, 0x39 },
  { "LSL (,U++)", 0x9e, 9, 0, 0x59 },
  { "LSL (,S++)", 0x9e, 9, 0, 0x69 },
  { "LSL (,--X)", 0x9e, 9, 0, 0x2b },
  { "LSL (,--Y)", 0x9e, 9, 0, 0x3b },
  { "LSL (,--U)", 0x9e, 9, 0, 0x5b },
  { "LSL (,--S)", 0x9e, 9, 0, 0x6b },
  { "LSL (x,X)", 0x9e, 7, 1, 0x2c }, /* 8-bit offset */
  { "LSL (x,Y)", 0x9e, 7, 1, 0x3c }, /* 8-bit offset */
  { "LSL (x,U)", 0x9e, 7, 1, 0x5c }, /* 8-bit offset */
  { "LSL (x,S)", 0x9e, 7, 1, 0x6c }, /* 8-bit offset */
  { "LSL (?,X)", 0x9e, 8, 0, 0x2d }, /* 16-bit offset */
  { "LSL (?,Y)", 0x9e, 8, 0, 0x3d }, /* 16-bit offset */
  { "LSL (?,U)", 0x9e, 8, 0, 0x5d }, /* 16-bit offset */
  { "LSL (?,S)", 0x9e, 8, 0, 0x6d }, /* 16-bit offset */
  { "LSL (x,PCR)", 0x9e, 7, 1, 0x7c }, /* 8-bit offset */
  { "LSL (?,PCR)", 0x9e, 8, 0, 0x7d }, /* 16-bit offset */
  { "LSL (?)", 0x9e, 8, 0, 0x0f }, /* 16-bit offset */
  { "LSL s,X", 0x9e, 6, 1, 0x26 }, /* 5-bit offset */
  { "LSL s,Y", 0x9e, 6, 1, 0x36 }, /* 5-bit offset */
  { "LSL s,U", 0x9e, 6, 1, 0x56 }, /* 5-bit offset */
  { "LSL s,S", 0x9e, 6, 1, 0x66 }, /* 5-bit offset */
  { "LSL x,X", 0x9e, 7, 1, 0x24 }, /* 8-bit offset */
  { "LSL x,Y", 0x9e, 7, 1, 0x34 }, /* 8-bit offset */
  { "LSL x,U", 0x9e, 7, 1, 0x54 }, /* 8-bit offset */
  { "LSL x,S", 0x9e, 7, 1, 0x64 }, /* 8-bit offset */
  { "LSL ?,X", 0x9e, 8, 0, 0x25 }, /* 16-bit offset */
  { "LSL ?,Y", 0x9e, 8, 0, 0x35 }, /* 16-bit offset */
  { "LSL ?,U", 0x9e, 8, 0, 0x55 }, /* 16-bit offset */
  { "LSL ?,S", 0x9e, 8, 0, 0x65 }, /* 16-bit offset */
  { "LSL x,PCR", 0x9e, 7, 1, 0x74 }, /* 8-bit offset */
  { "LSL ?,PCR", 0x9e, 8, 0, 0x75 }, /* 16-bit offset */
  { "LSL x", 0x9e, 2, 1, 0x07 },
  { "LSL ?", 0x9e, 2, 0, 0x07 },

  { "LSRA", 0x93, 0, 0, 0 },
  { "LSRB", 0x94, 0, 0, 0 },
  { "LSR,X", 0x95, 9, 0, 0x26 },
  { "LSR,Y", 0x95, 9, 0, 0x36 },
  { "LSR,U", 0x95, 9, 0, 0x56 },
  { "LSR,S", 0x95, 9, 0, 0x66 },
  { "LSR A,X", 0x95, 9, 0, 0xa0 },
  { "LSR A,Y", 0x95, 9, 0, 0xb0 },
  { "LSR A,U", 0x95, 9, 0, 0xd0 },
  { "LSR A,S", 0x95, 9, 0, 0xe0 },
  { "LSR B,X", 0x95, 9, 0, 0xa1 },
  { "LSR B,Y", 0x95, 9, 0, 0xb1 },
  { "LSR B,U", 0x95, 9, 0, 0xd1 },
  { "LSR B,S", 0x95, 9, 0, 0xe1 },
  { "LSR D,X", 0x95, 9, 0, 0xa7 },
  { "LSR D,Y", 0x95, 9, 0, 0xb7 },
  { "LSR D,U", 0x95, 9, 0, 0xd7 },
  { "LSR D,S", 0x95, 9, 0, 0xe8 },
  { "LSR,X+", 0x95, 9, 0, 0x20 },
  { "LSR,Y+", 0x95, 9, 0, 0x30 },
  { "LSR,U+", 0x95, 9, 0, 0x50 },
  { "LSR,S+", 0x95, 9, 0, 0x60 },
  { "LSR,X++", 0x95, 9, 0, 0x21 },
  { "LSR,Y++", 0x95, 9, 0, 0x31 },
  { "LSR,U++", 0x95, 9, 0, 0x51 },
  { "LSR,S++", 0x95, 9, 0, 0x61 },
  { "LSR,-X", 0x95, 9, 0, 0x22 },
  { "LSR,-Y", 0x95, 9, 0, 0x32 },
  { "LSR,-U", 0x95, 9, 0, 0x52 },
  { "LSR,-S", 0x95, 9, 0, 0x62 },
  { "LSR,--X", 0x95, 9, 0, 0x23 },
  { "LSR,--Y", 0x95, 9, 0, 0x33 },
  { "LSR,--U", 0x95, 9, 0, 0x53 },
  { "LSR,--S", 0x95, 9, 0, 0x63 },
  { "LSR (,X)", 0x95, 9, 0, 0x2e },
  { "LSR (,Y)", 0x95, 9, 0, 0x3e },
  { "LSR (,U)", 0x95, 9, 0, 0x5e },
  { "LSR (,S)", 0x95, 9, 0, 0x6e },
  { "LSR (A,X)", 0x95, 9, 0, 0xa8 },
  { "LSR (A,Y)", 0x95, 9, 0, 0xb8 },
  { "LSR (A,U)", 0x95, 9, 0, 0xd8 },
  { "LSR (A,S)", 0x95, 9, 0, 0xe8 },
  { "LSR (B,X)", 0x95, 9, 0, 0xa9 },
  { "LSR (B,Y)", 0x95, 9, 0, 0xb9 },
  { "LSR (B,U)", 0x95, 9, 0, 0xd9 },
  { "LSR (B,S)", 0x95, 9, 0, 0xe9 },
  { "LSR (D,X)", 0x95, 9, 0, 0xaf },
  { "LSR (D,Y)", 0x95, 9, 0, 0xbf },
  { "LSR (D,U)", 0x95, 9, 0, 0xdf },
  { "LSR (D,S)", 0x95, 9, 0, 0xef },
  { "LSR (,X++)", 0x95, 9, 0, 0x29 },
  { "LSR (,Y++)", 0x95, 9, 0, 0x39 },
  { "LSR (,U++)", 0x95, 9, 0, 0x59 },
  { "LSR (,S++)", 0x95, 9, 0, 0x69 },
  { "LSR (,--X)", 0x95, 9, 0, 0x2b },
  { "LSR (,--Y)", 0x95, 9, 0, 0x3b },
  { "LSR (,--U)", 0x95, 9, 0, 0x5b },
  { "LSR (,--S)", 0x95, 9, 0, 0x6b },
  { "LSR (x,X)", 0x95, 7, 1, 0x2c }, /* 8-bit offset */
  { "LSR (x,Y)", 0x95, 7, 1, 0x3c }, /* 8-bit offset */
  { "LSR (x,U)", 0x95, 7, 1, 0x5c }, /* 8-bit offset */
  { "LSR (x,S)", 0x95, 7, 1, 0x6c }, /* 8-bit offset */
  { "LSR (?,X)", 0x95, 8, 0, 0x2d }, /* 16-bit offset */
  { "LSR (?,Y)", 0x95, 8, 0, 0x3d }, /* 16-bit offset */
  { "LSR (?,U)", 0x95, 8, 0, 0x5d }, /* 16-bit offset */
  { "LSR (?,S)", 0x95, 8, 0, 0x6d }, /* 16-bit offset */
  { "LSR (x,PCR)", 0x95, 7, 1, 0x7c }, /* 8-bit offset */
  { "LSR (?,PCR)", 0x95, 8, 0, 0x7d }, /* 16-bit offset */
  { "LSR (?)", 0x95, 8, 0, 0x0f }, /* 16-bit offset */
  { "LSR s,X", 0x95, 6, 1, 0x26 }, /* 5-bit offset */
  { "LSR s,Y", 0x95, 6, 1, 0x36 }, /* 5-bit offset */
  { "LSR s,U", 0x95, 6, 1, 0x56 }, /* 5-bit offset */
  { "LSR s,S", 0x95, 6, 1, 0x66 }, /* 5-bit offset */
  { "LSR x,X", 0x95, 7, 1, 0x24 }, /* 8-bit offset */
  { "LSR x,Y", 0x95, 7, 1, 0x34 }, /* 8-bit offset */
  { "LSR x,U", 0x95, 7, 1, 0x54 }, /* 8-bit offset */
  { "LSR x,S", 0x95, 7, 1, 0x64 }, /* 8-bit offset */
  { "LSR ?,X", 0x95, 8, 0, 0x25 }, /* 16-bit offset */
  { "LSR ?,Y", 0x95, 8, 0, 0x35 }, /* 16-bit offset */
  { "LSR ?,U", 0x95, 8, 0, 0x55 }, /* 16-bit offset */
  { "LSR ?,S", 0x95, 8, 0, 0x65 }, /* 16-bit offset */
  { "LSR x,PCR", 0x95, 7, 1, 0x74 }, /* 8-bit offset */
  { "LSR ?,PCR", 0x95, 8, 0, 0x75 }, /* 16-bit offset */
  { "LSR x", 0x95, 2, 1, 0x07 },
  { "LSR ?", 0x95, 2, 0, 0x07 },

  { "MUL", 0xb3, 0, 0, 0 },

  { "NEGA", 0x86, 0, 0, 0 },
  { "NEGB", 0x87, 0, 0, 0 },
  { "NEG,X", 0x88, 9, 0, 0x26 },
  { "NEG,Y", 0x88, 9, 0, 0x36 },
  { "NEG,U", 0x88, 9, 0, 0x56 },
  { "NEG,S", 0x88, 9, 0, 0x66 },
  { "NEG A,X", 0x88, 9, 0, 0xa0 },
  { "NEG A,Y", 0x88, 9, 0, 0xb0 },
  { "NEG A,U", 0x88, 9, 0, 0xd0 },
  { "NEG A,S", 0x88, 9, 0, 0xe0 },
  { "NEG B,X", 0x88, 9, 0, 0xa1 },
  { "NEG B,Y", 0x88, 9, 0, 0xb1 },
  { "NEG B,U", 0x88, 9, 0, 0xd1 },
  { "NEG B,S", 0x88, 9, 0, 0xe1 },
  { "NEG D,X", 0x88, 9, 0, 0xa7 },
  { "NEG D,Y", 0x88, 9, 0, 0xb7 },
  { "NEG D,U", 0x88, 9, 0, 0xd7 },
  { "NEG D,S", 0x88, 9, 0, 0xe8 },
  { "NEG,X+", 0x88, 9, 0, 0x20 },
  { "NEG,Y+", 0x88, 9, 0, 0x30 },
  { "NEG,U+", 0x88, 9, 0, 0x50 },
  { "NEG,S+", 0x88, 9, 0, 0x60 },
  { "NEG,X++", 0x88, 9, 0, 0x21 },
  { "NEG,Y++", 0x88, 9, 0, 0x31 },
  { "NEG,U++", 0x88, 9, 0, 0x51 },
  { "NEG,S++", 0x88, 9, 0, 0x61 },
  { "NEG,-X", 0x88, 9, 0, 0x22 },
  { "NEG,-Y", 0x88, 9, 0, 0x32 },
  { "NEG,-U", 0x88, 9, 0, 0x52 },
  { "NEG,-S", 0x88, 9, 0, 0x62 },
  { "NEG,--X", 0x88, 9, 0, 0x23 },
  { "NEG,--Y", 0x88, 9, 0, 0x33 },
  { "NEG,--U", 0x88, 9, 0, 0x53 },
  { "NEG,--S", 0x88, 9, 0, 0x63 },
  { "NEG (,X)", 0x88, 9, 0, 0x2e },
  { "NEG (,Y)", 0x88, 9, 0, 0x3e },
  { "NEG (,U)", 0x88, 9, 0, 0x5e },
  { "NEG (,S)", 0x88, 9, 0, 0x6e },
  { "NEG (A,X)", 0x88, 9, 0, 0xa8 },
  { "NEG (A,Y)", 0x88, 9, 0, 0xb8 },
  { "NEG (A,U)", 0x88, 9, 0, 0xd8 },
  { "NEG (A,S)", 0x88, 9, 0, 0xe8 },
  { "NEG (B,X)", 0x88, 9, 0, 0xa9 },
  { "NEG (B,Y)", 0x88, 9, 0, 0xb9 },
  { "NEG (B,U)", 0x88, 9, 0, 0xd9 },
  { "NEG (B,S)", 0x88, 9, 0, 0xe9 },
  { "NEG (D,X)", 0x88, 9, 0, 0xaf },
  { "NEG (D,Y)", 0x88, 9, 0, 0xbf },
  { "NEG (D,U)", 0x88, 9, 0, 0xdf },
  { "NEG (D,S)", 0x88, 9, 0, 0xef },
  { "NEG (,X++)", 0x88, 9, 0, 0x29 },
  { "NEG (,Y++)", 0x88, 9, 0, 0x39 },
  { "NEG (,U++)", 0x88, 9, 0, 0x59 },
  { "NEG (,S++)", 0x88, 9, 0, 0x69 },
  { "NEG (,--X)", 0x88, 9, 0, 0x2b },
  { "NEG (,--Y)", 0x88, 9, 0, 0x3b },
  { "NEG (,--U)", 0x88, 9, 0, 0x5b },
  { "NEG (,--S)", 0x88, 9, 0, 0x6b },
  { "NEG (x,X)", 0x88, 7, 1, 0x2c }, /* 8-bit offset */
  { "NEG (x,Y)", 0x88, 7, 1, 0x3c }, /* 8-bit offset */
  { "NEG (x,U)", 0x88, 7, 1, 0x5c }, /* 8-bit offset */
  { "NEG (x,S)", 0x88, 7, 1, 0x6c }, /* 8-bit offset */
  { "NEG (?,X)", 0x88, 8, 0, 0x2d }, /* 16-bit offset */
  { "NEG (?,Y)", 0x88, 8, 0, 0x3d }, /* 16-bit offset */
  { "NEG (?,U)", 0x88, 8, 0, 0x5d }, /* 16-bit offset */
  { "NEG (?,S)", 0x88, 8, 0, 0x6d }, /* 16-bit offset */
  { "NEG (x,PCR)", 0x88, 7, 1, 0x7c }, /* 8-bit offset */
  { "NEG (?,PCR)", 0x88, 8, 0, 0x7d }, /* 16-bit offset */
  { "NEG (?)", 0x88, 8, 0, 0x0f }, /* 16-bit offset */
  { "NEG s,X", 0x88, 6, 1, 0x26 }, /* 5-bit offset */
  { "NEG s,Y", 0x88, 6, 1, 0x36 }, /* 5-bit offset */
  { "NEG s,U", 0x88, 6, 1, 0x56 }, /* 5-bit offset */
  { "NEG s,S", 0x88, 6, 1, 0x66 }, /* 5-bit offset */
  { "NEG x,X", 0x88, 7, 1, 0x24 }, /* 8-bit offset */
  { "NEG x,Y", 0x88, 7, 1, 0x34 }, /* 8-bit offset */
  { "NEG x,U", 0x88, 7, 1, 0x54 }, /* 8-bit offset */
  { "NEG x,S", 0x88, 7, 1, 0x64 }, /* 8-bit offset */
  { "NEG ?,X", 0x88, 8, 0, 0x25 }, /* 16-bit offset */
  { "NEG ?,Y", 0x88, 8, 0, 0x35 }, /* 16-bit offset */
  { "NEG ?,U", 0x88, 8, 0, 0x55 }, /* 16-bit offset */
  { "NEG ?,S", 0x88, 8, 0, 0x65 }, /* 16-bit offset */
  { "NEG x,PCR", 0x88, 7, 1, 0x74 }, /* 8-bit offset */
  { "NEG ?,PCR", 0x88, 8, 0, 0x75 }, /* 16-bit offset */
  { "NEG x", 0x88, 2, 1, 0x07 },
  { "NEG ?", 0x88, 2, 0, 0x07 },

  { "NOP", 0xae, 0, 0, 0 },

  { "ORA #x", 0x30, 1, 0, 0 },
  { "ORA,X", 0x32, 9, 0, 0x26 },
  { "ORA,Y", 0x32, 9, 0, 0x36 },
  { "ORA,U", 0x32, 9, 0, 0x56 },
  { "ORA,S", 0x32, 9, 0, 0x66 },
  { "ORA A,X", 0x32, 9, 0, 0xa0 },
  { "ORA A,Y", 0x32, 9, 0, 0xb0 },
  { "ORA A,U", 0x32, 9, 0, 0xd0 },
  { "ORA A,S", 0x32, 9, 0, 0xe0 },
  { "ORA B,X", 0x32, 9, 0, 0xa1 },
  { "ORA B,Y", 0x32, 9, 0, 0xb1 },
  { "ORA B,U", 0x32, 9, 0, 0xd1 },
  { "ORA B,S", 0x32, 9, 0, 0xe1 },
  { "ORA D,X", 0x32, 9, 0, 0xa7 },
  { "ORA D,Y", 0x32, 9, 0, 0xb7 },
  { "ORA D,U", 0x32, 9, 0, 0xd7 },
  { "ORA D,S", 0x32, 9, 0, 0xe8 },
  { "ORA,X+", 0x32, 9, 0, 0x20 },
  { "ORA,Y+", 0x32, 9, 0, 0x30 },
  { "ORA,U+", 0x32, 9, 0, 0x50 },
  { "ORA,S+", 0x32, 9, 0, 0x60 },
  { "ORA,X++", 0x32, 9, 0, 0x21 },
  { "ORA,Y++", 0x32, 9, 0, 0x31 },
  { "ORA,U++", 0x32, 9, 0, 0x51 },
  { "ORA,S++", 0x32, 9, 0, 0x61 },
  { "ORA,-X", 0x32, 9, 0, 0x22 },
  { "ORA,-Y", 0x32, 9, 0, 0x32 },
  { "ORA,-U", 0x32, 9, 0, 0x52 },
  { "ORA,-S", 0x32, 9, 0, 0x62 },
  { "ORA,--X", 0x32, 9, 0, 0x23 },
  { "ORA,--Y", 0x32, 9, 0, 0x33 },
  { "ORA,--U", 0x32, 9, 0, 0x53 },
  { "ORA,--S", 0x32, 9, 0, 0x63 },
  { "ORA (,X)", 0x32, 9, 0, 0x2e },
  { "ORA (,Y)", 0x32, 9, 0, 0x3e },
  { "ORA (,U)", 0x32, 9, 0, 0x5e },
  { "ORA (,S)", 0x32, 9, 0, 0x6e },
  { "ORA (A,X)", 0x32, 9, 0, 0xa8 },
  { "ORA (A,Y)", 0x32, 9, 0, 0xb8 },
  { "ORA (A,U)", 0x32, 9, 0, 0xd8 },
  { "ORA (A,S)", 0x32, 9, 0, 0xe8 },
  { "ORA (B,X)", 0x32, 9, 0, 0xa9 },
  { "ORA (B,Y)", 0x32, 9, 0, 0xb9 },
  { "ORA (B,U)", 0x32, 9, 0, 0xd9 },
  { "ORA (B,S)", 0x32, 9, 0, 0xe9 },
  { "ORA (D,X)", 0x32, 9, 0, 0xaf },
  { "ORA (D,Y)", 0x32, 9, 0, 0xbf },
  { "ORA (D,U)", 0x32, 9, 0, 0xdf },
  { "ORA (D,S)", 0x32, 9, 0, 0xef },
  { "ORA (,X++)", 0x32, 9, 0, 0x29 },
  { "ORA (,Y++)", 0x32, 9, 0, 0x39 },
  { "ORA (,U++)", 0x32, 9, 0, 0x59 },
  { "ORA (,S++)", 0x32, 9, 0, 0x69 },
  { "ORA (,--X)", 0x32, 9, 0, 0x2b },
  { "ORA (,--Y)", 0x32, 9, 0, 0x3b },
  { "ORA (,--U)", 0x32, 9, 0, 0x5b },
  { "ORA (,--S)", 0x32, 9, 0, 0x6b },
  { "ORA (x,X)", 0x32, 7, 1, 0x2c }, /* 8-bit offset */
  { "ORA (x,Y)", 0x32, 7, 1, 0x3c }, /* 8-bit offset */
  { "ORA (x,U)", 0x32, 7, 1, 0x5c }, /* 8-bit offset */
  { "ORA (x,S)", 0x32, 7, 1, 0x6c }, /* 8-bit offset */
  { "ORA (?,X)", 0x32, 8, 0, 0x2d }, /* 16-bit offset */
  { "ORA (?,Y)", 0x32, 8, 0, 0x3d }, /* 16-bit offset */
  { "ORA (?,U)", 0x32, 8, 0, 0x5d }, /* 16-bit offset */
  { "ORA (?,S)", 0x32, 8, 0, 0x6d }, /* 16-bit offset */
  { "ORA (x,PCR)", 0x32, 7, 1, 0x7c }, /* 8-bit offset */
  { "ORA (?,PCR)", 0x32, 8, 0, 0x7d }, /* 16-bit offset */
  { "ORA (?)", 0x32, 8, 0, 0x0f }, /* 16-bit offset */
  { "ORA s,X", 0x32, 6, 1, 0x26 }, /* 5-bit offset */
  { "ORA s,Y", 0x32, 6, 1, 0x36 }, /* 5-bit offset */
  { "ORA s,U", 0x32, 6, 1, 0x56 }, /* 5-bit offset */
  { "ORA s,S", 0x32, 6, 1, 0x66 }, /* 5-bit offset */
  { "ORA x,X", 0x32, 7, 1, 0x24 }, /* 8-bit offset */
  { "ORA x,Y", 0x32, 7, 1, 0x34 }, /* 8-bit offset */
  { "ORA x,U", 0x32, 7, 1, 0x54 }, /* 8-bit offset */
  { "ORA x,S", 0x32, 7, 1, 0x64 }, /* 8-bit offset */
  { "ORA ?,X", 0x32, 8, 0, 0x25 }, /* 16-bit offset */
  { "ORA ?,Y", 0x32, 8, 0, 0x35 }, /* 16-bit offset */
  { "ORA ?,U", 0x32, 8, 0, 0x55 }, /* 16-bit offset */
  { "ORA ?,S", 0x32, 8, 0, 0x65 }, /* 16-bit offset */
  { "ORA x,PCR", 0x32, 7, 1, 0x74 }, /* 8-bit offset */
  { "ORA ?,PCR", 0x32, 8, 0, 0x75 }, /* 16-bit offset */
  { "ORA x", 0x32, 2, 1, 0x07 },
  { "ORA ?", 0x32, 2, 0, 0x07 },

  { "ORB #x", 0x31, 1, 0, 0 },
  { "ORB,X", 0x33, 9, 0, 0x26 },
  { "ORB,Y", 0x33, 9, 0, 0x36 },
  { "ORB,U", 0x33, 9, 0, 0x56 },
  { "ORB,S", 0x33, 9, 0, 0x66 },
  { "ORB A,X", 0x33, 9, 0, 0xa0 },
  { "ORB A,Y", 0x33, 9, 0, 0xb0 },
  { "ORB A,U", 0x33, 9, 0, 0xd0 },
  { "ORB A,S", 0x33, 9, 0, 0xe0 },
  { "ORB B,X", 0x33, 9, 0, 0xa1 },
  { "ORB B,Y", 0x33, 9, 0, 0xb1 },
  { "ORB B,U", 0x33, 9, 0, 0xd1 },
  { "ORB B,S", 0x33, 9, 0, 0xe1 },
  { "ORB D,X", 0x33, 9, 0, 0xa7 },
  { "ORB D,Y", 0x33, 9, 0, 0xb7 },
  { "ORB D,U", 0x33, 9, 0, 0xd7 },
  { "ORB D,S", 0x33, 9, 0, 0xe8 },
  { "ORB,X+", 0x33, 9, 0, 0x20 },
  { "ORB,Y+", 0x33, 9, 0, 0x30 },
  { "ORB,U+", 0x33, 9, 0, 0x50 },
  { "ORB,S+", 0x33, 9, 0, 0x60 },
  { "ORB,X++", 0x33, 9, 0, 0x21 },
  { "ORB,Y++", 0x33, 9, 0, 0x31 },
  { "ORB,U++", 0x33, 9, 0, 0x51 },
  { "ORB,S++", 0x33, 9, 0, 0x61 },
  { "ORB,-X", 0x33, 9, 0, 0x22 },
  { "ORB,-Y", 0x33, 9, 0, 0x32 },
  { "ORB,-U", 0x33, 9, 0, 0x52 },
  { "ORB,-S", 0x33, 9, 0, 0x62 },
  { "ORB,--X", 0x33, 9, 0, 0x23 },
  { "ORB,--Y", 0x33, 9, 0, 0x33 },
  { "ORB,--U", 0x33, 9, 0, 0x53 },
  { "ORB,--S", 0x33, 9, 0, 0x63 },
  { "ORB (,X)", 0x33, 9, 0, 0x2e },
  { "ORB (,Y)", 0x33, 9, 0, 0x3e },
  { "ORB (,U)", 0x33, 9, 0, 0x5e },
  { "ORB (,S)", 0x33, 9, 0, 0x6e },
  { "ORB (A,X)", 0x33, 9, 0, 0xa8 },
  { "ORB (A,Y)", 0x33, 9, 0, 0xb8 },
  { "ORB (A,U)", 0x33, 9, 0, 0xd8 },
  { "ORB (A,S)", 0x33, 9, 0, 0xe8 },
  { "ORB (B,X)", 0x33, 9, 0, 0xa9 },
  { "ORB (B,Y)", 0x33, 9, 0, 0xb9 },
  { "ORB (B,U)", 0x33, 9, 0, 0xd9 },
  { "ORB (B,S)", 0x33, 9, 0, 0xe9 },
  { "ORB (D,X)", 0x33, 9, 0, 0xaf },
  { "ORB (D,Y)", 0x33, 9, 0, 0xbf },
  { "ORB (D,U)", 0x33, 9, 0, 0xdf },
  { "ORB (D,S)", 0x33, 9, 0, 0xef },
  { "ORB (,X++)", 0x33, 9, 0, 0x29 },
  { "ORB (,Y++)", 0x33, 9, 0, 0x39 },
  { "ORB (,U++)", 0x33, 9, 0, 0x59 },
  { "ORB (,S++)", 0x33, 9, 0, 0x69 },
  { "ORB (,--X)", 0x33, 9, 0, 0x2b },
  { "ORB (,--Y)", 0x33, 9, 0, 0x3b },
  { "ORB (,--U)", 0x33, 9, 0, 0x5b },
  { "ORB (,--S)", 0x33, 9, 0, 0x6b },
  { "ORB (x,X)", 0x33, 7, 1, 0x2c }, /* 8-bit offset */
  { "ORB (x,Y)", 0x33, 7, 1, 0x3c }, /* 8-bit offset */
  { "ORB (x,U)", 0x33, 7, 1, 0x5c }, /* 8-bit offset */
  { "ORB (x,S)", 0x33, 7, 1, 0x6c }, /* 8-bit offset */
  { "ORB (?,X)", 0x33, 8, 0, 0x2d }, /* 16-bit offset */
  { "ORB (?,Y)", 0x33, 8, 0, 0x3d }, /* 16-bit offset */
  { "ORB (?,U)", 0x33, 8, 0, 0x5d }, /* 16-bit offset */
  { "ORB (?,S)", 0x33, 8, 0, 0x6d }, /* 16-bit offset */
  { "ORB (x,PCR)", 0x33, 7, 1, 0x7c }, /* 8-bit offset */
  { "ORB (?,PCR)", 0x33, 8, 0, 0x7d }, /* 16-bit offset */
  { "ORB (?)", 0x33, 8, 0, 0x0f }, /* 16-bit offset */
  { "ORB s,X", 0x33, 6, 1, 0x26 }, /* 5-bit offset */
  { "ORB s,Y", 0x33, 6, 1, 0x36 }, /* 5-bit offset */
  { "ORB s,U", 0x33, 6, 1, 0x56 }, /* 5-bit offset */
  { "ORB s,S", 0x33, 6, 1, 0x66 }, /* 5-bit offset */
  { "ORB x,X", 0x33, 7, 1, 0x24 }, /* 8-bit offset */
  { "ORB x,Y", 0x33, 7, 1, 0x34 }, /* 8-bit offset */
  { "ORB x,U", 0x33, 7, 1, 0x54 }, /* 8-bit offset */
  { "ORB x,S", 0x33, 7, 1, 0x64 }, /* 8-bit offset */
  { "ORB ?,X", 0x33, 8, 0, 0x25 }, /* 16-bit offset */
  { "ORB ?,Y", 0x33, 8, 0, 0x35 }, /* 16-bit offset */
  { "ORB ?,U", 0x33, 8, 0, 0x55 }, /* 16-bit offset */
  { "ORB ?,S", 0x33, 8, 0, 0x65 }, /* 16-bit offset */
  { "ORB x,PCR", 0x33, 7, 1, 0x74 }, /* 8-bit offset */
  { "ORB ?,PCR", 0x33, 8, 0, 0x75 }, /* 16-bit offset */
  { "ORB x", 0x33, 2, 1, 0x07 },
  { "ORB ?", 0x33, 2, 0, 0x07 },

  { "ORCC #x", 0x3d, 1, 0, 0 },

  { "PSHS r", 0x0c, 11, 0, 1 },
  { "PSHU r", 0x0d, 11, 0, 0 },
  { "PULS r", 0x0e, 11, 0, 1 },
  { "PULU r", 0x0f, 11, 0, 0 },

  { "ROLA", 0xa0, 0, 0, 0 },
  { "ROLB", 0xa1, 0, 0, 0 },
  { "ROL,X", 0xa2, 9, 0, 0x26 },
  { "ROL,Y", 0xa2, 9, 0, 0x36 },
  { "ROL,U", 0xa2, 9, 0, 0x56 },
  { "ROL,S", 0xa2, 9, 0, 0x66 },
  { "ROL A,X", 0xa2, 9, 0, 0xa0 },
  { "ROL A,Y", 0xa2, 9, 0, 0xb0 },
  { "ROL A,U", 0xa2, 9, 0, 0xd0 },
  { "ROL A,S", 0xa2, 9, 0, 0xe0 },
  { "ROL B,X", 0xa2, 9, 0, 0xa1 },
  { "ROL B,Y", 0xa2, 9, 0, 0xb1 },
  { "ROL B,U", 0xa2, 9, 0, 0xd1 },
  { "ROL B,S", 0xa2, 9, 0, 0xe1 },
  { "ROL D,X", 0xa2, 9, 0, 0xa7 },
  { "ROL D,Y", 0xa2, 9, 0, 0xb7 },
  { "ROL D,U", 0xa2, 9, 0, 0xd7 },
  { "ROL D,S", 0xa2, 9, 0, 0xe8 },
  { "ROL,X+", 0xa2, 9, 0, 0x20 },
  { "ROL,Y+", 0xa2, 9, 0, 0x30 },
  { "ROL,U+", 0xa2, 9, 0, 0x50 },
  { "ROL,S+", 0xa2, 9, 0, 0x60 },
  { "ROL,X++", 0xa2, 9, 0, 0x21 },
  { "ROL,Y++", 0xa2, 9, 0, 0x31 },
  { "ROL,U++", 0xa2, 9, 0, 0x51 },
  { "ROL,S++", 0xa2, 9, 0, 0x61 },
  { "ROL,-X", 0xa2, 9, 0, 0x22 },
  { "ROL,-Y", 0xa2, 9, 0, 0x32 },
  { "ROL,-U", 0xa2, 9, 0, 0x52 },
  { "ROL,-S", 0xa2, 9, 0, 0x62 },
  { "ROL,--X", 0xa2, 9, 0, 0x23 },
  { "ROL,--Y", 0xa2, 9, 0, 0x33 },
  { "ROL,--U", 0xa2, 9, 0, 0x53 },
  { "ROL,--S", 0xa2, 9, 0, 0x63 },
  { "ROL (,X)", 0xa2, 9, 0, 0x2e },
  { "ROL (,Y)", 0xa2, 9, 0, 0x3e },
  { "ROL (,U)", 0xa2, 9, 0, 0x5e },
  { "ROL (,S)", 0xa2, 9, 0, 0x6e },
  { "ROL (A,X)", 0xa2, 9, 0, 0xa8 },
  { "ROL (A,Y)", 0xa2, 9, 0, 0xb8 },
  { "ROL (A,U)", 0xa2, 9, 0, 0xd8 },
  { "ROL (A,S)", 0xa2, 9, 0, 0xe8 },
  { "ROL (B,X)", 0xa2, 9, 0, 0xa9 },
  { "ROL (B,Y)", 0xa2, 9, 0, 0xb9 },
  { "ROL (B,U)", 0xa2, 9, 0, 0xd9 },
  { "ROL (B,S)", 0xa2, 9, 0, 0xe9 },
  { "ROL (D,X)", 0xa2, 9, 0, 0xaf },
  { "ROL (D,Y)", 0xa2, 9, 0, 0xbf },
  { "ROL (D,U)", 0xa2, 9, 0, 0xdf },
  { "ROL (D,S)", 0xa2, 9, 0, 0xef },
  { "ROL (,X++)", 0xa2, 9, 0, 0x29 },
  { "ROL (,Y++)", 0xa2, 9, 0, 0x39 },
  { "ROL (,U++)", 0xa2, 9, 0, 0x59 },
  { "ROL (,S++)", 0xa2, 9, 0, 0x69 },
  { "ROL (,--X)", 0xa2, 9, 0, 0x2b },
  { "ROL (,--Y)", 0xa2, 9, 0, 0x3b },
  { "ROL (,--U)", 0xa2, 9, 0, 0x5b },
  { "ROL (,--S)", 0xa2, 9, 0, 0x6b },
  { "ROL (x,X)", 0xa2, 7, 1, 0x2c }, /* 8-bit offset */
  { "ROL (x,Y)", 0xa2, 7, 1, 0x3c }, /* 8-bit offset */
  { "ROL (x,U)", 0xa2, 7, 1, 0x5c }, /* 8-bit offset */
  { "ROL (x,S)", 0xa2, 7, 1, 0x6c }, /* 8-bit offset */
  { "ROL (?,X)", 0xa2, 8, 0, 0x2d }, /* 16-bit offset */
  { "ROL (?,Y)", 0xa2, 8, 0, 0x3d }, /* 16-bit offset */
  { "ROL (?,U)", 0xa2, 8, 0, 0x5d }, /* 16-bit offset */
  { "ROL (?,S)", 0xa2, 8, 0, 0x6d }, /* 16-bit offset */
  { "ROL (x,PCR)", 0xa2, 7, 1, 0x7c }, /* 8-bit offset */
  { "ROL (?,PCR)", 0xa2, 8, 0, 0x7d }, /* 16-bit offset */
  { "ROL (?)", 0xa2, 8, 0, 0x0f }, /* 16-bit offset */
  { "ROL s,X", 0xa2, 6, 1, 0x26 }, /* 5-bit offset */
  { "ROL s,Y", 0xa2, 6, 1, 0x36 }, /* 5-bit offset */
  { "ROL s,U", 0xa2, 6, 1, 0x56 }, /* 5-bit offset */
  { "ROL s,S", 0xa2, 6, 1, 0x66 }, /* 5-bit offset */
  { "ROL x,X", 0xa2, 7, 1, 0x24 }, /* 8-bit offset */
  { "ROL x,Y", 0xa2, 7, 1, 0x34 }, /* 8-bit offset */
  { "ROL x,U", 0xa2, 7, 1, 0x54 }, /* 8-bit offset */
  { "ROL x,S", 0xa2, 7, 1, 0x64 }, /* 8-bit offset */
  { "ROL ?,X", 0xa2, 8, 0, 0x25 }, /* 16-bit offset */
  { "ROL ?,Y", 0xa2, 8, 0, 0x35 }, /* 16-bit offset */
  { "ROL ?,U", 0xa2, 8, 0, 0x55 }, /* 16-bit offset */
  { "ROL ?,S", 0xa2, 8, 0, 0x65 }, /* 16-bit offset */
  { "ROL x,PCR", 0xa2, 7, 1, 0x74 }, /* 8-bit offset */
  { "ROL ?,PCR", 0xa2, 8, 0, 0x75 }, /* 16-bit offset */
  { "ROL x", 0xa2, 2, 1, 0x07 },
  { "ROL ?", 0xa2, 2, 0, 0x07 },

  { "RORA", 0x96, 0, 0, 0 },
  { "RORB", 0x97, 0, 0, 0 },
  { "ROR,X", 0x98, 9, 0, 0x26 },
  { "ROR,Y", 0x98, 9, 0, 0x36 },
  { "ROR,U", 0x98, 9, 0, 0x56 },
  { "ROR,S", 0x98, 9, 0, 0x66 },
  { "ROR A,X", 0x98, 9, 0, 0xa0 },
  { "ROR A,Y", 0x98, 9, 0, 0xb0 },
  { "ROR A,U", 0x98, 9, 0, 0xd0 },
  { "ROR A,S", 0x98, 9, 0, 0xe0 },
  { "ROR B,X", 0x98, 9, 0, 0xa1 },
  { "ROR B,Y", 0x98, 9, 0, 0xb1 },
  { "ROR B,U", 0x98, 9, 0, 0xd1 },
  { "ROR B,S", 0x98, 9, 0, 0xe1 },
  { "ROR D,X", 0x98, 9, 0, 0xa7 },
  { "ROR D,Y", 0x98, 9, 0, 0xb7 },
  { "ROR D,U", 0x98, 9, 0, 0xd7 },
  { "ROR D,S", 0x98, 9, 0, 0xe8 },
  { "ROR,X+", 0x98, 9, 0, 0x20 },
  { "ROR,Y+", 0x98, 9, 0, 0x30 },
  { "ROR,U+", 0x98, 9, 0, 0x50 },
  { "ROR,S+", 0x98, 9, 0, 0x60 },
  { "ROR,X++", 0x98, 9, 0, 0x21 },
  { "ROR,Y++", 0x98, 9, 0, 0x31 },
  { "ROR,U++", 0x98, 9, 0, 0x51 },
  { "ROR,S++", 0x98, 9, 0, 0x61 },
  { "ROR,-X", 0x98, 9, 0, 0x22 },
  { "ROR,-Y", 0x98, 9, 0, 0x32 },
  { "ROR,-U", 0x98, 9, 0, 0x52 },
  { "ROR,-S", 0x98, 9, 0, 0x62 },
  { "ROR,--X", 0x98, 9, 0, 0x23 },
  { "ROR,--Y", 0x98, 9, 0, 0x33 },
  { "ROR,--U", 0x98, 9, 0, 0x53 },
  { "ROR,--S", 0x98, 9, 0, 0x63 },
  { "ROR (,X)", 0x98, 9, 0, 0x2e },
  { "ROR (,Y)", 0x98, 9, 0, 0x3e },
  { "ROR (,U)", 0x98, 9, 0, 0x5e },
  { "ROR (,S)", 0x98, 9, 0, 0x6e },
  { "ROR (A,X)", 0x98, 9, 0, 0xa8 },
  { "ROR (A,Y)", 0x98, 9, 0, 0xb8 },
  { "ROR (A,U)", 0x98, 9, 0, 0xd8 },
  { "ROR (A,S)", 0x98, 9, 0, 0xe8 },
  { "ROR (B,X)", 0x98, 9, 0, 0xa9 },
  { "ROR (B,Y)", 0x98, 9, 0, 0xb9 },
  { "ROR (B,U)", 0x98, 9, 0, 0xd9 },
  { "ROR (B,S)", 0x98, 9, 0, 0xe9 },
  { "ROR (D,X)", 0x98, 9, 0, 0xaf },
  { "ROR (D,Y)", 0x98, 9, 0, 0xbf },
  { "ROR (D,U)", 0x98, 9, 0, 0xdf },
  { "ROR (D,S)", 0x98, 9, 0, 0xef },
  { "ROR (,X++)", 0x98, 9, 0, 0x29 },
  { "ROR (,Y++)", 0x98, 9, 0, 0x39 },
  { "ROR (,U++)", 0x98, 9, 0, 0x59 },
  { "ROR (,S++)", 0x98, 9, 0, 0x69 },
  { "ROR (,--X)", 0x98, 9, 0, 0x2b },
  { "ROR (,--Y)", 0x98, 9, 0, 0x3b },
  { "ROR (,--U)", 0x98, 9, 0, 0x5b },
  { "ROR (,--S)", 0x98, 9, 0, 0x6b },
  { "ROR (x,X)", 0x98, 7, 1, 0x2c }, /* 8-bit offset */
  { "ROR (x,Y)", 0x98, 7, 1, 0x3c }, /* 8-bit offset */
  { "ROR (x,U)", 0x98, 7, 1, 0x5c }, /* 8-bit offset */
  { "ROR (x,S)", 0x98, 7, 1, 0x6c }, /* 8-bit offset */
  { "ROR (?,X)", 0x98, 8, 0, 0x2d }, /* 16-bit offset */
  { "ROR (?,Y)", 0x98, 8, 0, 0x3d }, /* 16-bit offset */
  { "ROR (?,U)", 0x98, 8, 0, 0x5d }, /* 16-bit offset */
  { "ROR (?,S)", 0x98, 8, 0, 0x6d }, /* 16-bit offset */
  { "ROR (x,PCR)", 0x98, 7, 1, 0x7c }, /* 8-bit offset */
  { "ROR (?,PCR)", 0x98, 8, 0, 0x7d }, /* 16-bit offset */
  { "ROR (?)", 0x98, 8, 0, 0x0f }, /* 16-bit offset */
  { "ROR s,X", 0x98, 6, 1, 0x26 }, /* 5-bit offset */
  { "ROR s,Y", 0x98, 6, 1, 0x36 }, /* 5-bit offset */
  { "ROR s,U", 0x98, 6, 1, 0x56 }, /* 5-bit offset */
  { "ROR s,S", 0x98, 6, 1, 0x66 }, /* 5-bit offset */
  { "ROR x,X", 0x98, 7, 1, 0x24 }, /* 8-bit offset */
  { "ROR x,Y", 0x98, 7, 1, 0x34 }, /* 8-bit offset */
  { "ROR x,U", 0x98, 7, 1, 0x54 }, /* 8-bit offset */
  { "ROR x,S", 0x98, 7, 1, 0x64 }, /* 8-bit offset */
  { "ROR ?,X", 0x98, 8, 0, 0x25 }, /* 16-bit offset */
  { "ROR ?,Y", 0x98, 8, 0, 0x35 }, /* 16-bit offset */
  { "ROR ?,U", 0x98, 8, 0, 0x55 }, /* 16-bit offset */
  { "ROR ?,S", 0x98, 8, 0, 0x65 }, /* 16-bit offset */
  { "ROR x,PCR", 0x98, 7, 1, 0x74 }, /* 8-bit offset */
  { "ROR ?,PCR", 0x98, 8, 0, 0x75 }, /* 16-bit offset */
  { "ROR x", 0x98, 2, 1, 0x07 },
  { "ROR ?", 0x98, 2, 0, 0x07 },

  { "RTI", 0x9f, 0, 0, 0 },
  { "RTS", 0x8f, 0, 0, 0 },

  { "SBCA #x", 0x20, 1, 0, 0 },
  { "SBCA,X", 0x22, 9, 0, 0x26 },
  { "SBCA,Y", 0x22, 9, 0, 0x36 },
  { "SBCA,U", 0x22, 9, 0, 0x56 },
  { "SBCA,S", 0x22, 9, 0, 0x66 },
  { "SBCA A,X", 0x22, 9, 0, 0xa0 },
  { "SBCA A,Y", 0x22, 9, 0, 0xb0 },
  { "SBCA A,U", 0x22, 9, 0, 0xd0 },
  { "SBCA A,S", 0x22, 9, 0, 0xe0 },
  { "SBCA B,X", 0x22, 9, 0, 0xa1 },
  { "SBCA B,Y", 0x22, 9, 0, 0xb1 },
  { "SBCA B,U", 0x22, 9, 0, 0xd1 },
  { "SBCA B,S", 0x22, 9, 0, 0xe1 },
  { "SBCA D,X", 0x22, 9, 0, 0xa7 },
  { "SBCA D,Y", 0x22, 9, 0, 0xb7 },
  { "SBCA D,U", 0x22, 9, 0, 0xd7 },
  { "SBCA D,S", 0x22, 9, 0, 0xe8 },
  { "SBCA,X+", 0x22, 9, 0, 0x20 },
  { "SBCA,Y+", 0x22, 9, 0, 0x30 },
  { "SBCA,U+", 0x22, 9, 0, 0x50 },
  { "SBCA,S+", 0x22, 9, 0, 0x60 },
  { "SBCA,X++", 0x22, 9, 0, 0x21 },
  { "SBCA,Y++", 0x22, 9, 0, 0x31 },
  { "SBCA,U++", 0x22, 9, 0, 0x51 },
  { "SBCA,S++", 0x22, 9, 0, 0x61 },
  { "SBCA,-X", 0x22, 9, 0, 0x22 },
  { "SBCA,-Y", 0x22, 9, 0, 0x32 },
  { "SBCA,-U", 0x22, 9, 0, 0x52 },
  { "SBCA,-S", 0x22, 9, 0, 0x62 },
  { "SBCA,--X", 0x22, 9, 0, 0x23 },
  { "SBCA,--Y", 0x22, 9, 0, 0x33 },
  { "SBCA,--U", 0x22, 9, 0, 0x53 },
  { "SBCA,--S", 0x22, 9, 0, 0x63 },
  { "SBCA (,X)", 0x22, 9, 0, 0x2e },
  { "SBCA (,Y)", 0x22, 9, 0, 0x3e },
  { "SBCA (,U)", 0x22, 9, 0, 0x5e },
  { "SBCA (,S)", 0x22, 9, 0, 0x6e },
  { "SBCA (A,X)", 0x22, 9, 0, 0xa8 },
  { "SBCA (A,Y)", 0x22, 9, 0, 0xb8 },
  { "SBCA (A,U)", 0x22, 9, 0, 0xd8 },
  { "SBCA (A,S)", 0x22, 9, 0, 0xe8 },
  { "SBCA (B,X)", 0x22, 9, 0, 0xa9 },
  { "SBCA (B,Y)", 0x22, 9, 0, 0xb9 },
  { "SBCA (B,U)", 0x22, 9, 0, 0xd9 },
  { "SBCA (B,S)", 0x22, 9, 0, 0xe9 },
  { "SBCA (D,X)", 0x22, 9, 0, 0xaf },
  { "SBCA (D,Y)", 0x22, 9, 0, 0xbf },
  { "SBCA (D,U)", 0x22, 9, 0, 0xdf },
  { "SBCA (D,S)", 0x22, 9, 0, 0xef },
  { "SBCA (,X++)", 0x22, 9, 0, 0x29 },
  { "SBCA (,Y++)", 0x22, 9, 0, 0x39 },
  { "SBCA (,U++)", 0x22, 9, 0, 0x59 },
  { "SBCA (,S++)", 0x22, 9, 0, 0x69 },
  { "SBCA (,--X)", 0x22, 9, 0, 0x2b },
  { "SBCA (,--Y)", 0x22, 9, 0, 0x3b },
  { "SBCA (,--U)", 0x22, 9, 0, 0x5b },
  { "SBCA (,--S)", 0x22, 9, 0, 0x6b },
  { "SBCA (x,X)", 0x22, 7, 1, 0x2c }, /* 8-bit offset */
  { "SBCA (x,Y)", 0x22, 7, 1, 0x3c }, /* 8-bit offset */
  { "SBCA (x,U)", 0x22, 7, 1, 0x5c }, /* 8-bit offset */
  { "SBCA (x,S)", 0x22, 7, 1, 0x6c }, /* 8-bit offset */
  { "SBCA (?,X)", 0x22, 8, 0, 0x2d }, /* 16-bit offset */
  { "SBCA (?,Y)", 0x22, 8, 0, 0x3d }, /* 16-bit offset */
  { "SBCA (?,U)", 0x22, 8, 0, 0x5d }, /* 16-bit offset */
  { "SBCA (?,S)", 0x22, 8, 0, 0x6d }, /* 16-bit offset */
  { "SBCA (x,PCR)", 0x22, 7, 1, 0x7c }, /* 8-bit offset */
  { "SBCA (?,PCR)", 0x22, 8, 0, 0x7d }, /* 16-bit offset */
  { "SBCA (?)", 0x22, 8, 0, 0x0f }, /* 16-bit offset */
  { "SBCA s,X", 0x22, 6, 1, 0x26 }, /* 5-bit offset */
  { "SBCA s,Y", 0x22, 6, 1, 0x36 }, /* 5-bit offset */
  { "SBCA s,U", 0x22, 6, 1, 0x56 }, /* 5-bit offset */
  { "SBCA s,S", 0x22, 6, 1, 0x66 }, /* 5-bit offset */
  { "SBCA x,X", 0x22, 7, 1, 0x24 }, /* 8-bit offset */
  { "SBCA x,Y", 0x22, 7, 1, 0x34 }, /* 8-bit offset */
  { "SBCA x,U", 0x22, 7, 1, 0x54 }, /* 8-bit offset */
  { "SBCA x,S", 0x22, 7, 1, 0x64 }, /* 8-bit offset */
  { "SBCA ?,X", 0x22, 8, 0, 0x25 }, /* 16-bit offset */
  { "SBCA ?,Y", 0x22, 8, 0, 0x35 }, /* 16-bit offset */
  { "SBCA ?,U", 0x22, 8, 0, 0x55 }, /* 16-bit offset */
  { "SBCA ?,S", 0x22, 8, 0, 0x65 }, /* 16-bit offset */
  { "SBCA x,PCR", 0x22, 7, 1, 0x74 }, /* 8-bit offset */
  { "SBCA ?,PCR", 0x22, 8, 0, 0x75 }, /* 16-bit offset */
  { "SBCA x", 0x22, 2, 1, 0x07 },
  { "SBCA ?", 0x22, 2, 0, 0x07 },

  { "SBCB #x", 0x21, 1, 0, 0 },
  { "SBCB,X", 0x23, 9, 0, 0x26 },
  { "SBCB,Y", 0x23, 9, 0, 0x36 },
  { "SBCB,U", 0x23, 9, 0, 0x56 },
  { "SBCB,S", 0x23, 9, 0, 0x66 },
  { "SBCB A,X", 0x23, 9, 0, 0xa0 },
  { "SBCB A,Y", 0x23, 9, 0, 0xb0 },
  { "SBCB A,U", 0x23, 9, 0, 0xd0 },
  { "SBCB A,S", 0x23, 9, 0, 0xe0 },
  { "SBCB B,X", 0x23, 9, 0, 0xa1 },
  { "SBCB B,Y", 0x23, 9, 0, 0xb1 },
  { "SBCB B,U", 0x23, 9, 0, 0xd1 },
  { "SBCB B,S", 0x23, 9, 0, 0xe1 },
  { "SBCB D,X", 0x23, 9, 0, 0xa7 },
  { "SBCB D,Y", 0x23, 9, 0, 0xb7 },
  { "SBCB D,U", 0x23, 9, 0, 0xd7 },
  { "SBCB D,S", 0x23, 9, 0, 0xe8 },
  { "SBCB,X+", 0x23, 9, 0, 0x20 },
  { "SBCB,Y+", 0x23, 9, 0, 0x30 },
  { "SBCB,U+", 0x23, 9, 0, 0x50 },
  { "SBCB,S+", 0x23, 9, 0, 0x60 },
  { "SBCB,X++", 0x23, 9, 0, 0x21 },
  { "SBCB,Y++", 0x23, 9, 0, 0x31 },
  { "SBCB,U++", 0x23, 9, 0, 0x51 },
  { "SBCB,S++", 0x23, 9, 0, 0x61 },
  { "SBCB,-X", 0x23, 9, 0, 0x22 },
  { "SBCB,-Y", 0x23, 9, 0, 0x32 },
  { "SBCB,-U", 0x23, 9, 0, 0x52 },
  { "SBCB,-S", 0x23, 9, 0, 0x62 },
  { "SBCB,--X", 0x23, 9, 0, 0x23 },
  { "SBCB,--Y", 0x23, 9, 0, 0x33 },
  { "SBCB,--U", 0x23, 9, 0, 0x53 },
  { "SBCB,--S", 0x23, 9, 0, 0x63 },
  { "SBCB (,X)", 0x23, 9, 0, 0x2e },
  { "SBCB (,Y)", 0x23, 9, 0, 0x3e },
  { "SBCB (,U)", 0x23, 9, 0, 0x5e },
  { "SBCB (,S)", 0x23, 9, 0, 0x6e },
  { "SBCB (A,X)", 0x23, 9, 0, 0xa8 },
  { "SBCB (A,Y)", 0x23, 9, 0, 0xb8 },
  { "SBCB (A,U)", 0x23, 9, 0, 0xd8 },
  { "SBCB (A,S)", 0x23, 9, 0, 0xe8 },
  { "SBCB (B,X)", 0x23, 9, 0, 0xa9 },
  { "SBCB (B,Y)", 0x23, 9, 0, 0xb9 },
  { "SBCB (B,U)", 0x23, 9, 0, 0xd9 },
  { "SBCB (B,S)", 0x23, 9, 0, 0xe9 },
  { "SBCB (D,X)", 0x23, 9, 0, 0xaf },
  { "SBCB (D,Y)", 0x23, 9, 0, 0xbf },
  { "SBCB (D,U)", 0x23, 9, 0, 0xdf },
  { "SBCB (D,S)", 0x23, 9, 0, 0xef },
  { "SBCB (,X++)", 0x23, 9, 0, 0x29 },
  { "SBCB (,Y++)", 0x23, 9, 0, 0x39 },
  { "SBCB (,U++)", 0x23, 9, 0, 0x59 },
  { "SBCB (,S++)", 0x23, 9, 0, 0x69 },
  { "SBCB (,--X)", 0x23, 9, 0, 0x2b },
  { "SBCB (,--Y)", 0x23, 9, 0, 0x3b },
  { "SBCB (,--U)", 0x23, 9, 0, 0x5b },
  { "SBCB (,--S)", 0x23, 9, 0, 0x6b },
  { "SBCB (x,X)", 0x23, 7, 1, 0x2c }, /* 8-bit offset */
  { "SBCB (x,Y)", 0x23, 7, 1, 0x3c }, /* 8-bit offset */
  { "SBCB (x,U)", 0x23, 7, 1, 0x5c }, /* 8-bit offset */
  { "SBCB (x,S)", 0x23, 7, 1, 0x6c }, /* 8-bit offset */
  { "SBCB (?,X)", 0x23, 8, 0, 0x2d }, /* 16-bit offset */
  { "SBCB (?,Y)", 0x23, 8, 0, 0x3d }, /* 16-bit offset */
  { "SBCB (?,U)", 0x23, 8, 0, 0x5d }, /* 16-bit offset */
  { "SBCB (?,S)", 0x23, 8, 0, 0x6d }, /* 16-bit offset */
  { "SBCB (x,PCR)", 0x23, 7, 1, 0x7c }, /* 8-bit offset */
  { "SBCB (?,PCR)", 0x23, 8, 0, 0x7d }, /* 16-bit offset */
  { "SBCB (?)", 0x23, 8, 0, 0x0f }, /* 16-bit offset */
  { "SBCB s,X", 0x23, 6, 1, 0x26 }, /* 5-bit offset */
  { "SBCB s,Y", 0x23, 6, 1, 0x36 }, /* 5-bit offset */
  { "SBCB s,U", 0x23, 6, 1, 0x56 }, /* 5-bit offset */
  { "SBCB s,S", 0x23, 6, 1, 0x66 }, /* 5-bit offset */
  { "SBCB x,X", 0x23, 7, 1, 0x24 }, /* 8-bit offset */
  { "SBCB x,Y", 0x23, 7, 1, 0x34 }, /* 8-bit offset */
  { "SBCB x,U", 0x23, 7, 1, 0x54 }, /* 8-bit offset */
  { "SBCB x,S", 0x23, 7, 1, 0x64 }, /* 8-bit offset */
  { "SBCB ?,X", 0x23, 8, 0, 0x25 }, /* 16-bit offset */
  { "SBCB ?,Y", 0x23, 8, 0, 0x35 }, /* 16-bit offset */
  { "SBCB ?,U", 0x23, 8, 0, 0x55 }, /* 16-bit offset */
  { "SBCB ?,S", 0x23, 8, 0, 0x65 }, /* 16-bit offset */
  { "SBCB x,PCR", 0x23, 7, 1, 0x74 }, /* 8-bit offset */
  { "SBCB ?,PCR", 0x23, 8, 0, 0x75 }, /* 16-bit offset */
  { "SBCB x", 0x23, 2, 1, 0x07 },
  { "SBCB ?", 0x23, 2, 0, 0x07 },

  { "SEX", 0xb2, 0, 0, 0 },
  
  { "STA,X", 0x3a, 9, 0, 0x26 },
  { "STA,Y", 0x3a, 9, 0, 0x36 },
  { "STA,U", 0x3a, 9, 0, 0x56 },
  { "STA,S", 0x3a, 9, 0, 0x66 },
  { "STA A,X", 0x3a, 9, 0, 0xa0 },
  { "STA A,Y", 0x3a, 9, 0, 0xb0 },
  { "STA A,U", 0x3a, 9, 0, 0xd0 },
  { "STA A,S", 0x3a, 9, 0, 0xe0 },
  { "STA B,X", 0x3a, 9, 0, 0xa1 },
  { "STA B,Y", 0x3a, 9, 0, 0xb1 },
  { "STA B,U", 0x3a, 9, 0, 0xd1 },
  { "STA B,S", 0x3a, 9, 0, 0xe1 },
  { "STA D,X", 0x3a, 9, 0, 0xa7 },
  { "STA D,Y", 0x3a, 9, 0, 0xb7 },
  { "STA D,U", 0x3a, 9, 0, 0xd7 },
  { "STA D,S", 0x3a, 9, 0, 0xe8 },
  { "STA,X+", 0x3a, 9, 0, 0x20 },
  { "STA,Y+", 0x3a, 9, 0, 0x30 },
  { "STA,U+", 0x3a, 9, 0, 0x50 },
  { "STA,S+", 0x3a, 9, 0, 0x60 },
  { "STA,X++", 0x3a, 9, 0, 0x21 },
  { "STA,Y++", 0x3a, 9, 0, 0x31 },
  { "STA,U++", 0x3a, 9, 0, 0x51 },
  { "STA,S++", 0x3a, 9, 0, 0x61 },
  { "STA,-X", 0x3a, 9, 0, 0x22 },
  { "STA,-Y", 0x3a, 9, 0, 0x32 },
  { "STA,-U", 0x3a, 9, 0, 0x52 },
  { "STA,-S", 0x3a, 9, 0, 0x62 },
  { "STA,--X", 0x3a, 9, 0, 0x23 },
  { "STA,--Y", 0x3a, 9, 0, 0x33 },
  { "STA,--U", 0x3a, 9, 0, 0x53 },
  { "STA,--S", 0x3a, 9, 0, 0x63 },
  { "STA (,X)", 0x3a, 9, 0, 0x2e },
  { "STA (,Y)", 0x3a, 9, 0, 0x3e },
  { "STA (,U)", 0x3a, 9, 0, 0x5e },
  { "STA (,S)", 0x3a, 9, 0, 0x6e },
  { "STA (A,X)", 0x3a, 9, 0, 0xa8 },
  { "STA (A,Y)", 0x3a, 9, 0, 0xb8 },
  { "STA (A,U)", 0x3a, 9, 0, 0xd8 },
  { "STA (A,S)", 0x3a, 9, 0, 0xe8 },
  { "STA (B,X)", 0x3a, 9, 0, 0xa9 },
  { "STA (B,Y)", 0x3a, 9, 0, 0xb9 },
  { "STA (B,U)", 0x3a, 9, 0, 0xd9 },
  { "STA (B,S)", 0x3a, 9, 0, 0xe9 },
  { "STA (D,X)", 0x3a, 9, 0, 0xaf },
  { "STA (D,Y)", 0x3a, 9, 0, 0xbf },
  { "STA (D,U)", 0x3a, 9, 0, 0xdf },
  { "STA (D,S)", 0x3a, 9, 0, 0xef },
  { "STA (,X++)", 0x3a, 9, 0, 0x29 },
  { "STA (,Y++)", 0x3a, 9, 0, 0x39 },
  { "STA (,U++)", 0x3a, 9, 0, 0x59 },
  { "STA (,S++)", 0x3a, 9, 0, 0x69 },
  { "STA (,--X)", 0x3a, 9, 0, 0x2b },
  { "STA (,--Y)", 0x3a, 9, 0, 0x3b },
  { "STA (,--U)", 0x3a, 9, 0, 0x5b },
  { "STA (,--S)", 0x3a, 9, 0, 0x6b },
  { "STA (x,X)", 0x3a, 7, 1, 0x2c }, /* 8-bit offset */
  { "STA (x,Y)", 0x3a, 7, 1, 0x3c }, /* 8-bit offset */
  { "STA (x,U)", 0x3a, 7, 1, 0x5c }, /* 8-bit offset */
  { "STA (x,S)", 0x3a, 7, 1, 0x6c }, /* 8-bit offset */
  { "STA (?,X)", 0x3a, 8, 0, 0x2d }, /* 16-bit offset */
  { "STA (?,Y)", 0x3a, 8, 0, 0x3d }, /* 16-bit offset */
  { "STA (?,U)", 0x3a, 8, 0, 0x5d }, /* 16-bit offset */
  { "STA (?,S)", 0x3a, 8, 0, 0x6d }, /* 16-bit offset */
  { "STA (x,PCR)", 0x3a, 7, 1, 0x7c }, /* 8-bit offset */
  { "STA (?,PCR)", 0x3a, 8, 0, 0x7d }, /* 16-bit offset */
  { "STA (?)", 0x3a, 8, 0, 0x0f }, /* 16-bit offset */
  { "STA s,X", 0x3a, 6, 1, 0x26 }, /* 5-bit offset */
  { "STA s,Y", 0x3a, 6, 1, 0x36 }, /* 5-bit offset */
  { "STA s,U", 0x3a, 6, 1, 0x56 }, /* 5-bit offset */
  { "STA s,S", 0x3a, 6, 1, 0x66 }, /* 5-bit offset */
  { "STA x,X", 0x3a, 7, 1, 0x24 }, /* 8-bit offset */
  { "STA x,Y", 0x3a, 7, 1, 0x34 }, /* 8-bit offset */
  { "STA x,U", 0x3a, 7, 1, 0x54 }, /* 8-bit offset */
  { "STA x,S", 0x3a, 7, 1, 0x64 }, /* 8-bit offset */
  { "STA ?,X", 0x3a, 8, 0, 0x25 }, /* 16-bit offset */
  { "STA ?,Y", 0x3a, 8, 0, 0x35 }, /* 16-bit offset */
  { "STA ?,U", 0x3a, 8, 0, 0x55 }, /* 16-bit offset */
  { "STA ?,S", 0x3a, 8, 0, 0x65 }, /* 16-bit offset */
  { "STA x,PCR", 0x3a, 7, 1, 0x74 }, /* 8-bit offset */
  { "STA ?,PCR", 0x3a, 8, 0, 0x75 }, /* 16-bit offset */
  { "STA x", 0x3a, 2, 1, 0x07 },
  { "STA ?", 0x3a, 2, 0, 0x07 },

  { "STB,X", 0x3b, 9, 0, 0x26 },
  { "STB,Y", 0x3b, 9, 0, 0x36 },
  { "STB,U", 0x3b, 9, 0, 0x56 },
  { "STB,S", 0x3b, 9, 0, 0x66 },
  { "STB A,X", 0x3b, 9, 0, 0xa0 },
  { "STB A,Y", 0x3b, 9, 0, 0xb0 },
  { "STB A,U", 0x3b, 9, 0, 0xd0 },
  { "STB A,S", 0x3b, 9, 0, 0xe0 },
  { "STB B,X", 0x3b, 9, 0, 0xa1 },
  { "STB B,Y", 0x3b, 9, 0, 0xb1 },
  { "STB B,U", 0x3b, 9, 0, 0xd1 },
  { "STB B,S", 0x3b, 9, 0, 0xe1 },
  { "STB D,X", 0x3b, 9, 0, 0xa7 },
  { "STB D,Y", 0x3b, 9, 0, 0xb7 },
  { "STB D,U", 0x3b, 9, 0, 0xd7 },
  { "STB D,S", 0x3b, 9, 0, 0xe8 },
  { "STB,X+", 0x3b, 9, 0, 0x20 },
  { "STB,Y+", 0x3b, 9, 0, 0x30 },
  { "STB,U+", 0x3b, 9, 0, 0x50 },
  { "STB,S+", 0x3b, 9, 0, 0x60 },
  { "STB,X++", 0x3b, 9, 0, 0x21 },
  { "STB,Y++", 0x3b, 9, 0, 0x31 },
  { "STB,U++", 0x3b, 9, 0, 0x51 },
  { "STB,S++", 0x3b, 9, 0, 0x61 },
  { "STB,-X", 0x3b, 9, 0, 0x22 },
  { "STB,-Y", 0x3b, 9, 0, 0x32 },
  { "STB,-U", 0x3b, 9, 0, 0x52 },
  { "STB,-S", 0x3b, 9, 0, 0x62 },
  { "STB,--X", 0x3b, 9, 0, 0x23 },
  { "STB,--Y", 0x3b, 9, 0, 0x33 },
  { "STB,--U", 0x3b, 9, 0, 0x53 },
  { "STB,--S", 0x3b, 9, 0, 0x63 },
  { "STB (,X)", 0x3b, 9, 0, 0x2e },
  { "STB (,Y)", 0x3b, 9, 0, 0x3e },
  { "STB (,U)", 0x3b, 9, 0, 0x5e },
  { "STB (,S)", 0x3b, 9, 0, 0x6e },
  { "STB (A,X)", 0x3b, 9, 0, 0xa8 },
  { "STB (A,Y)", 0x3b, 9, 0, 0xb8 },
  { "STB (A,U)", 0x3b, 9, 0, 0xd8 },
  { "STB (A,S)", 0x3b, 9, 0, 0xe8 },
  { "STB (B,X)", 0x3b, 9, 0, 0xa9 },
  { "STB (B,Y)", 0x3b, 9, 0, 0xb9 },
  { "STB (B,U)", 0x3b, 9, 0, 0xd9 },
  { "STB (B,S)", 0x3b, 9, 0, 0xe9 },
  { "STB (D,X)", 0x3b, 9, 0, 0xaf },
  { "STB (D,Y)", 0x3b, 9, 0, 0xbf },
  { "STB (D,U)", 0x3b, 9, 0, 0xdf },
  { "STB (D,S)", 0x3b, 9, 0, 0xef },
  { "STB (,X++)", 0x3b, 9, 0, 0x29 },
  { "STB (,Y++)", 0x3b, 9, 0, 0x39 },
  { "STB (,U++)", 0x3b, 9, 0, 0x59 },
  { "STB (,S++)", 0x3b, 9, 0, 0x69 },
  { "STB (,--X)", 0x3b, 9, 0, 0x2b },
  { "STB (,--Y)", 0x3b, 9, 0, 0x3b },
  { "STB (,--U)", 0x3b, 9, 0, 0x5b },
  { "STB (,--S)", 0x3b, 9, 0, 0x6b },
  { "STB (x,X)", 0x3b, 7, 1, 0x2c }, /* 8-bit offset */
  { "STB (x,Y)", 0x3b, 7, 1, 0x3c }, /* 8-bit offset */
  { "STB (x,U)", 0x3b, 7, 1, 0x5c }, /* 8-bit offset */
  { "STB (x,S)", 0x3b, 7, 1, 0x6c }, /* 8-bit offset */
  { "STB (?,X)", 0x3b, 8, 0, 0x2d }, /* 16-bit offset */
  { "STB (?,Y)", 0x3b, 8, 0, 0x3d }, /* 16-bit offset */
  { "STB (?,U)", 0x3b, 8, 0, 0x5d }, /* 16-bit offset */
  { "STB (?,S)", 0x3b, 8, 0, 0x6d }, /* 16-bit offset */
  { "STB (x,PCR)", 0x3b, 7, 1, 0x7c }, /* 8-bit offset */
  { "STB (?,PCR)", 0x3b, 8, 0, 0x7d }, /* 16-bit offset */
  { "STB (?)", 0x3b, 8, 0, 0x0f }, /* 16-bit offset */
  { "STB s,X", 0x3b, 6, 1, 0x26 }, /* 5-bit offset */
  { "STB s,Y", 0x3b, 6, 1, 0x36 }, /* 5-bit offset */
  { "STB s,U", 0x3b, 6, 1, 0x56 }, /* 5-bit offset */
  { "STB s,S", 0x3b, 6, 1, 0x66 }, /* 5-bit offset */
  { "STB x,X", 0x3b, 7, 1, 0x24 }, /* 8-bit offset */
  { "STB x,Y", 0x3b, 7, 1, 0x34 }, /* 8-bit offset */
  { "STB x,U", 0x3b, 7, 1, 0x54 }, /* 8-bit offset */
  { "STB x,S", 0x3b, 7, 1, 0x64 }, /* 8-bit offset */
  { "STB ?,X", 0x3b, 8, 0, 0x25 }, /* 16-bit offset */
  { "STB ?,Y", 0x3b, 8, 0, 0x35 }, /* 16-bit offset */
  { "STB ?,U", 0x3b, 8, 0, 0x55 }, /* 16-bit offset */
  { "STB ?,S", 0x3b, 8, 0, 0x65 }, /* 16-bit offset */
  { "STB x,PCR", 0x3b, 7, 1, 0x74 }, /* 8-bit offset */
  { "STB ?,PCR", 0x3b, 8, 0, 0x75 }, /* 16-bit offset */
  { "STB x", 0x3b, 2, 1, 0x07 },
  { "STB ?", 0x3b, 2, 0, 0x07 },

  { "STD,X", 0x58, 9, 0, 0x26 },
  { "STD,Y", 0x58, 9, 0, 0x36 },
  { "STD,U", 0x58, 9, 0, 0x56 },
  { "STD,S", 0x58, 9, 0, 0x66 },
  { "STD A,X", 0x58, 9, 0, 0xa0 },
  { "STD A,Y", 0x58, 9, 0, 0xb0 },
  { "STD A,U", 0x58, 9, 0, 0xd0 },
  { "STD A,S", 0x58, 9, 0, 0xe0 },
  { "STD B,X", 0x58, 9, 0, 0xa1 },
  { "STD B,Y", 0x58, 9, 0, 0xb1 },
  { "STD B,U", 0x58, 9, 0, 0xd1 },
  { "STD B,S", 0x58, 9, 0, 0xe1 },
  { "STD D,X", 0x58, 9, 0, 0xa7 },
  { "STD D,Y", 0x58, 9, 0, 0xb7 },
  { "STD D,U", 0x58, 9, 0, 0xd7 },
  { "STD D,S", 0x58, 9, 0, 0xe8 },
  { "STD,X+", 0x58, 9, 0, 0x20 },
  { "STD,Y+", 0x58, 9, 0, 0x30 },
  { "STD,U+", 0x58, 9, 0, 0x50 },
  { "STD,S+", 0x58, 9, 0, 0x60 },
  { "STD,X++", 0x58, 9, 0, 0x21 },
  { "STD,Y++", 0x58, 9, 0, 0x31 },
  { "STD,U++", 0x58, 9, 0, 0x51 },
  { "STD,S++", 0x58, 9, 0, 0x61 },
  { "STD,-X", 0x58, 9, 0, 0x22 },
  { "STD,-Y", 0x58, 9, 0, 0x32 },
  { "STD,-U", 0x58, 9, 0, 0x52 },
  { "STD,-S", 0x58, 9, 0, 0x62 },
  { "STD,--X", 0x58, 9, 0, 0x23 },
  { "STD,--Y", 0x58, 9, 0, 0x33 },
  { "STD,--U", 0x58, 9, 0, 0x53 },
  { "STD,--S", 0x58, 9, 0, 0x63 },
  { "STD (,X)", 0x58, 9, 0, 0x2e },
  { "STD (,Y)", 0x58, 9, 0, 0x3e },
  { "STD (,U)", 0x58, 9, 0, 0x5e },
  { "STD (,S)", 0x58, 9, 0, 0x6e },
  { "STD (A,X)", 0x58, 9, 0, 0xa8 },
  { "STD (A,Y)", 0x58, 9, 0, 0xb8 },
  { "STD (A,U)", 0x58, 9, 0, 0xd8 },
  { "STD (A,S)", 0x58, 9, 0, 0xe8 },
  { "STD (B,X)", 0x58, 9, 0, 0xa9 },
  { "STD (B,Y)", 0x58, 9, 0, 0xb9 },
  { "STD (B,U)", 0x58, 9, 0, 0xd9 },
  { "STD (B,S)", 0x58, 9, 0, 0xe9 },
  { "STD (D,X)", 0x58, 9, 0, 0xaf },
  { "STD (D,Y)", 0x58, 9, 0, 0xbf },
  { "STD (D,U)", 0x58, 9, 0, 0xdf },
  { "STD (D,S)", 0x58, 9, 0, 0xef },
  { "STD (,X++)", 0x58, 9, 0, 0x29 },
  { "STD (,Y++)", 0x58, 9, 0, 0x39 },
  { "STD (,U++)", 0x58, 9, 0, 0x59 },
  { "STD (,S++)", 0x58, 9, 0, 0x69 },
  { "STD (,--X)", 0x58, 9, 0, 0x2b },
  { "STD (,--Y)", 0x58, 9, 0, 0x3b },
  { "STD (,--U)", 0x58, 9, 0, 0x5b },
  { "STD (,--S)", 0x58, 9, 0, 0x6b },
  { "STD (x,X)", 0x58, 7, 1, 0x2c }, /* 8-bit offset */
  { "STD (x,Y)", 0x58, 7, 1, 0x3c }, /* 8-bit offset */
  { "STD (x,U)", 0x58, 7, 1, 0x5c }, /* 8-bit offset */
  { "STD (x,S)", 0x58, 7, 1, 0x6c }, /* 8-bit offset */
  { "STD (?,X)", 0x58, 8, 0, 0x2d }, /* 16-bit offset */
  { "STD (?,Y)", 0x58, 8, 0, 0x3d }, /* 16-bit offset */
  { "STD (?,U)", 0x58, 8, 0, 0x5d }, /* 16-bit offset */
  { "STD (?,S)", 0x58, 8, 0, 0x6d }, /* 16-bit offset */
  { "STD (x,PCR)", 0x58, 7, 1, 0x7c }, /* 8-bit offset */
  { "STD (?,PCR)", 0x58, 8, 0, 0x7d }, /* 16-bit offset */
  { "STD (?)", 0x58, 8, 0, 0x0f }, /* 16-bit offset */
  { "STD s,X", 0x58, 6, 1, 0x26 }, /* 5-bit offset */
  { "STD s,Y", 0x58, 6, 1, 0x36 }, /* 5-bit offset */
  { "STD s,U", 0x58, 6, 1, 0x56 }, /* 5-bit offset */
  { "STD s,S", 0x58, 6, 1, 0x66 }, /* 5-bit offset */
  { "STD x,X", 0x58, 7, 1, 0x24 }, /* 8-bit offset */
  { "STD x,Y", 0x58, 7, 1, 0x34 }, /* 8-bit offset */
  { "STD x,U", 0x58, 7, 1, 0x54 }, /* 8-bit offset */
  { "STD x,S", 0x58, 7, 1, 0x64 }, /* 8-bit offset */
  { "STD ?,X", 0x58, 8, 0, 0x25 }, /* 16-bit offset */
  { "STD ?,Y", 0x58, 8, 0, 0x35 }, /* 16-bit offset */
  { "STD ?,U", 0x58, 8, 0, 0x55 }, /* 16-bit offset */
  { "STD ?,S", 0x58, 8, 0, 0x65 }, /* 16-bit offset */
  { "STD x,PCR", 0x58, 7, 1, 0x74 }, /* 8-bit offset */
  { "STD ?,PCR", 0x58, 8, 0, 0x75 }, /* 16-bit offset */
  { "STD x", 0x58, 2, 1, 0x07 },
  { "STD ?", 0x58, 2, 0, 0x07 },

  { "STS,X", 0x5c, 9, 0, 0x26 },
  { "STS,Y", 0x5c, 9, 0, 0x36 },
  { "STS,U", 0x5c, 9, 0, 0x56 },
  { "STS,S", 0x5c, 9, 0, 0x66 },
  { "STS A,X", 0x5c, 9, 0, 0xa0 },
  { "STS A,Y", 0x5c, 9, 0, 0xb0 },
  { "STS A,U", 0x5c, 9, 0, 0xd0 },
  { "STS A,S", 0x5c, 9, 0, 0xe0 },
  { "STS B,X", 0x5c, 9, 0, 0xa1 },
  { "STS B,Y", 0x5c, 9, 0, 0xb1 },
  { "STS B,U", 0x5c, 9, 0, 0xd1 },
  { "STS B,S", 0x5c, 9, 0, 0xe1 },
  { "STS D,X", 0x5c, 9, 0, 0xa7 },
  { "STS D,Y", 0x5c, 9, 0, 0xb7 },
  { "STS D,U", 0x5c, 9, 0, 0xd7 },
  { "STS D,S", 0x5c, 9, 0, 0xe8 },
  { "STS,X+", 0x5c, 9, 0, 0x20 },
  { "STS,Y+", 0x5c, 9, 0, 0x30 },
  { "STS,U+", 0x5c, 9, 0, 0x50 },
  { "STS,S+", 0x5c, 9, 0, 0x60 },
  { "STS,X++", 0x5c, 9, 0, 0x21 },
  { "STS,Y++", 0x5c, 9, 0, 0x31 },
  { "STS,U++", 0x5c, 9, 0, 0x51 },
  { "STS,S++", 0x5c, 9, 0, 0x61 },
  { "STS,-X", 0x5c, 9, 0, 0x22 },
  { "STS,-Y", 0x5c, 9, 0, 0x32 },
  { "STS,-U", 0x5c, 9, 0, 0x52 },
  { "STS,-S", 0x5c, 9, 0, 0x62 },
  { "STS,--X", 0x5c, 9, 0, 0x23 },
  { "STS,--Y", 0x5c, 9, 0, 0x33 },
  { "STS,--U", 0x5c, 9, 0, 0x53 },
  { "STS,--S", 0x5c, 9, 0, 0x63 },
  { "STS (,X)", 0x5c, 9, 0, 0x2e },
  { "STS (,Y)", 0x5c, 9, 0, 0x3e },
  { "STS (,U)", 0x5c, 9, 0, 0x5e },
  { "STS (,S)", 0x5c, 9, 0, 0x6e },
  { "STS (A,X)", 0x5c, 9, 0, 0xa8 },
  { "STS (A,Y)", 0x5c, 9, 0, 0xb8 },
  { "STS (A,U)", 0x5c, 9, 0, 0xd8 },
  { "STS (A,S)", 0x5c, 9, 0, 0xe8 },
  { "STS (B,X)", 0x5c, 9, 0, 0xa9 },
  { "STS (B,Y)", 0x5c, 9, 0, 0xb9 },
  { "STS (B,U)", 0x5c, 9, 0, 0xd9 },
  { "STS (B,S)", 0x5c, 9, 0, 0xe9 },
  { "STS (D,X)", 0x5c, 9, 0, 0xaf },
  { "STS (D,Y)", 0x5c, 9, 0, 0xbf },
  { "STS (D,U)", 0x5c, 9, 0, 0xdf },
  { "STS (D,S)", 0x5c, 9, 0, 0xef },
  { "STS (,X++)", 0x5c, 9, 0, 0x29 },
  { "STS (,Y++)", 0x5c, 9, 0, 0x39 },
  { "STS (,U++)", 0x5c, 9, 0, 0x59 },
  { "STS (,S++)", 0x5c, 9, 0, 0x69 },
  { "STS (,--X)", 0x5c, 9, 0, 0x2b },
  { "STS (,--Y)", 0x5c, 9, 0, 0x3b },
  { "STS (,--U)", 0x5c, 9, 0, 0x5b },
  { "STS (,--S)", 0x5c, 9, 0, 0x6b },
  { "STS (x,X)", 0x5c, 7, 1, 0x2c }, /* 8-bit offset */
  { "STS (x,Y)", 0x5c, 7, 1, 0x3c }, /* 8-bit offset */
  { "STS (x,U)", 0x5c, 7, 1, 0x5c }, /* 8-bit offset */
  { "STS (x,S)", 0x5c, 7, 1, 0x6c }, /* 8-bit offset */
  { "STS (?,X)", 0x5c, 8, 0, 0x2d }, /* 16-bit offset */
  { "STS (?,Y)", 0x5c, 8, 0, 0x3d }, /* 16-bit offset */
  { "STS (?,U)", 0x5c, 8, 0, 0x5d }, /* 16-bit offset */
  { "STS (?,S)", 0x5c, 8, 0, 0x6d }, /* 16-bit offset */
  { "STS (x,PCR)", 0x5c, 7, 1, 0x7c }, /* 8-bit offset */
  { "STS (?,PCR)", 0x5c, 8, 0, 0x7d }, /* 16-bit offset */
  { "STS (?)", 0x5c, 8, 0, 0x0f }, /* 16-bit offset */
  { "STS s,X", 0x5c, 6, 1, 0x26 }, /* 5-bit offset */
  { "STS s,Y", 0x5c, 6, 1, 0x36 }, /* 5-bit offset */
  { "STS s,U", 0x5c, 6, 1, 0x56 }, /* 5-bit offset */
  { "STS s,S", 0x5c, 6, 1, 0x66 }, /* 5-bit offset */
  { "STS x,X", 0x5c, 7, 1, 0x24 }, /* 8-bit offset */
  { "STS x,Y", 0x5c, 7, 1, 0x34 }, /* 8-bit offset */
  { "STS x,U", 0x5c, 7, 1, 0x54 }, /* 8-bit offset */
  { "STS x,S", 0x5c, 7, 1, 0x64 }, /* 8-bit offset */
  { "STS ?,X", 0x5c, 8, 0, 0x25 }, /* 16-bit offset */
  { "STS ?,Y", 0x5c, 8, 0, 0x35 }, /* 16-bit offset */
  { "STS ?,U", 0x5c, 8, 0, 0x55 }, /* 16-bit offset */
  { "STS ?,S", 0x5c, 8, 0, 0x65 }, /* 16-bit offset */
  { "STS x,PCR", 0x5c, 7, 1, 0x74 }, /* 8-bit offset */
  { "STS ?,PCR", 0x5c, 8, 0, 0x75 }, /* 16-bit offset */
  { "STS x", 0x5c, 2, 1, 0x07 },
  { "STS ?", 0x5c, 2, 0, 0x07 },

  { "STU,X", 0x5b, 9, 0, 0x26 },
  { "STU,Y", 0x5b, 9, 0, 0x36 },
  { "STU,U", 0x5b, 9, 0, 0x56 },
  { "STU,S", 0x5b, 9, 0, 0x66 },
  { "STU A,X", 0x5b, 9, 0, 0xa0 },
  { "STU A,Y", 0x5b, 9, 0, 0xb0 },
  { "STU A,U", 0x5b, 9, 0, 0xd0 },
  { "STU A,S", 0x5b, 9, 0, 0xe0 },
  { "STU B,X", 0x5b, 9, 0, 0xa1 },
  { "STU B,Y", 0x5b, 9, 0, 0xb1 },
  { "STU B,U", 0x5b, 9, 0, 0xd1 },
  { "STU B,S", 0x5b, 9, 0, 0xe1 },
  { "STU D,X", 0x5b, 9, 0, 0xa7 },
  { "STU D,Y", 0x5b, 9, 0, 0xb7 },
  { "STU D,U", 0x5b, 9, 0, 0xd7 },
  { "STU D,S", 0x5b, 9, 0, 0xe8 },
  { "STU,X+", 0x5b, 9, 0, 0x20 },
  { "STU,Y+", 0x5b, 9, 0, 0x30 },
  { "STU,U+", 0x5b, 9, 0, 0x50 },
  { "STU,S+", 0x5b, 9, 0, 0x60 },
  { "STU,X++", 0x5b, 9, 0, 0x21 },
  { "STU,Y++", 0x5b, 9, 0, 0x31 },
  { "STU,U++", 0x5b, 9, 0, 0x51 },
  { "STU,S++", 0x5b, 9, 0, 0x61 },
  { "STU,-X", 0x5b, 9, 0, 0x22 },
  { "STU,-Y", 0x5b, 9, 0, 0x32 },
  { "STU,-U", 0x5b, 9, 0, 0x52 },
  { "STU,-S", 0x5b, 9, 0, 0x62 },
  { "STU,--X", 0x5b, 9, 0, 0x23 },
  { "STU,--Y", 0x5b, 9, 0, 0x33 },
  { "STU,--U", 0x5b, 9, 0, 0x53 },
  { "STU,--S", 0x5b, 9, 0, 0x63 },
  { "STU (,X)", 0x5b, 9, 0, 0x2e },
  { "STU (,Y)", 0x5b, 9, 0, 0x3e },
  { "STU (,U)", 0x5b, 9, 0, 0x5e },
  { "STU (,S)", 0x5b, 9, 0, 0x6e },
  { "STU (A,X)", 0x5b, 9, 0, 0xa8 },
  { "STU (A,Y)", 0x5b, 9, 0, 0xb8 },
  { "STU (A,U)", 0x5b, 9, 0, 0xd8 },
  { "STU (A,S)", 0x5b, 9, 0, 0xe8 },
  { "STU (B,X)", 0x5b, 9, 0, 0xa9 },
  { "STU (B,Y)", 0x5b, 9, 0, 0xb9 },
  { "STU (B,U)", 0x5b, 9, 0, 0xd9 },
  { "STU (B,S)", 0x5b, 9, 0, 0xe9 },
  { "STU (D,X)", 0x5b, 9, 0, 0xaf },
  { "STU (D,Y)", 0x5b, 9, 0, 0xbf },
  { "STU (D,U)", 0x5b, 9, 0, 0xdf },
  { "STU (D,S)", 0x5b, 9, 0, 0xef },
  { "STU (,X++)", 0x5b, 9, 0, 0x29 },
  { "STU (,Y++)", 0x5b, 9, 0, 0x39 },
  { "STU (,U++)", 0x5b, 9, 0, 0x59 },
  { "STU (,S++)", 0x5b, 9, 0, 0x69 },
  { "STU (,--X)", 0x5b, 9, 0, 0x2b },
  { "STU (,--Y)", 0x5b, 9, 0, 0x3b },
  { "STU (,--U)", 0x5b, 9, 0, 0x5b },
  { "STU (,--S)", 0x5b, 9, 0, 0x6b },
  { "STU (x,X)", 0x5b, 7, 1, 0x2c }, /* 8-bit offset */
  { "STU (x,Y)", 0x5b, 7, 1, 0x3c }, /* 8-bit offset */
  { "STU (x,U)", 0x5b, 7, 1, 0x5c }, /* 8-bit offset */
  { "STU (x,S)", 0x5b, 7, 1, 0x6c }, /* 8-bit offset */
  { "STU (?,X)", 0x5b, 8, 0, 0x2d }, /* 16-bit offset */
  { "STU (?,Y)", 0x5b, 8, 0, 0x3d }, /* 16-bit offset */
  { "STU (?,U)", 0x5b, 8, 0, 0x5d }, /* 16-bit offset */
  { "STU (?,S)", 0x5b, 8, 0, 0x6d }, /* 16-bit offset */
  { "STU (x,PCR)", 0x5b, 7, 1, 0x7c }, /* 8-bit offset */
  { "STU (?,PCR)", 0x5b, 8, 0, 0x7d }, /* 16-bit offset */
  { "STU (?)", 0x5b, 8, 0, 0x0f }, /* 16-bit offset */
  { "STU s,X", 0x5b, 6, 1, 0x26 }, /* 5-bit offset */
  { "STU s,Y", 0x5b, 6, 1, 0x36 }, /* 5-bit offset */
  { "STU s,U", 0x5b, 6, 1, 0x56 }, /* 5-bit offset */
  { "STU s,S", 0x5b, 6, 1, 0x66 }, /* 5-bit offset */
  { "STU x,X", 0x5b, 7, 1, 0x24 }, /* 8-bit offset */
  { "STU x,Y", 0x5b, 7, 1, 0x34 }, /* 8-bit offset */
  { "STU x,U", 0x5b, 7, 1, 0x54 }, /* 8-bit offset */
  { "STU x,S", 0x5b, 7, 1, 0x64 }, /* 8-bit offset */
  { "STU ?,X", 0x5b, 8, 0, 0x25 }, /* 16-bit offset */
  { "STU ?,Y", 0x5b, 8, 0, 0x35 }, /* 16-bit offset */
  { "STU ?,U", 0x5b, 8, 0, 0x55 }, /* 16-bit offset */
  { "STU ?,S", 0x5b, 8, 0, 0x65 }, /* 16-bit offset */
  { "STU x,PCR", 0x5b, 7, 1, 0x74 }, /* 8-bit offset */
  { "STU ?,PCR", 0x5b, 8, 0, 0x75 }, /* 16-bit offset */
  { "STU x", 0x5b, 2, 1, 0x07 },
  { "STU ?", 0x5b, 2, 0, 0x07 },

  { "STX,X", 0x59, 9, 0, 0x26 },
  { "STX,Y", 0x59, 9, 0, 0x36 },
  { "STX,U", 0x59, 9, 0, 0x56 },
  { "STX,S", 0x59, 9, 0, 0x66 },
  { "STX A,X", 0x59, 9, 0, 0xa0 },
  { "STX A,Y", 0x59, 9, 0, 0xb0 },
  { "STX A,U", 0x59, 9, 0, 0xd0 },
  { "STX A,S", 0x59, 9, 0, 0xe0 },
  { "STX B,X", 0x59, 9, 0, 0xa1 },
  { "STX B,Y", 0x59, 9, 0, 0xb1 },
  { "STX B,U", 0x59, 9, 0, 0xd1 },
  { "STX B,S", 0x59, 9, 0, 0xe1 },
  { "STX D,X", 0x59, 9, 0, 0xa7 },
  { "STX D,Y", 0x59, 9, 0, 0xb7 },
  { "STX D,U", 0x59, 9, 0, 0xd7 },
  { "STX D,S", 0x59, 9, 0, 0xe8 },
  { "STX,X+", 0x59, 9, 0, 0x20 },
  { "STX,Y+", 0x59, 9, 0, 0x30 },
  { "STX,U+", 0x59, 9, 0, 0x50 },
  { "STX,S+", 0x59, 9, 0, 0x60 },
  { "STX,X++", 0x59, 9, 0, 0x21 },
  { "STX,Y++", 0x59, 9, 0, 0x31 },
  { "STX,U++", 0x59, 9, 0, 0x51 },
  { "STX,S++", 0x59, 9, 0, 0x61 },
  { "STX,-X", 0x59, 9, 0, 0x22 },
  { "STX,-Y", 0x59, 9, 0, 0x32 },
  { "STX,-U", 0x59, 9, 0, 0x52 },
  { "STX,-S", 0x59, 9, 0, 0x62 },
  { "STX,--X", 0x59, 9, 0, 0x23 },
  { "STX,--Y", 0x59, 9, 0, 0x33 },
  { "STX,--U", 0x59, 9, 0, 0x53 },
  { "STX,--S", 0x59, 9, 0, 0x63 },
  { "STX (,X)", 0x59, 9, 0, 0x2e },
  { "STX (,Y)", 0x59, 9, 0, 0x3e },
  { "STX (,U)", 0x59, 9, 0, 0x5e },
  { "STX (,S)", 0x59, 9, 0, 0x6e },
  { "STX (A,X)", 0x59, 9, 0, 0xa8 },
  { "STX (A,Y)", 0x59, 9, 0, 0xb8 },
  { "STX (A,U)", 0x59, 9, 0, 0xd8 },
  { "STX (A,S)", 0x59, 9, 0, 0xe8 },
  { "STX (B,X)", 0x59, 9, 0, 0xa9 },
  { "STX (B,Y)", 0x59, 9, 0, 0xb9 },
  { "STX (B,U)", 0x59, 9, 0, 0xd9 },
  { "STX (B,S)", 0x59, 9, 0, 0xe9 },
  { "STX (D,X)", 0x59, 9, 0, 0xaf },
  { "STX (D,Y)", 0x59, 9, 0, 0xbf },
  { "STX (D,U)", 0x59, 9, 0, 0xdf },
  { "STX (D,S)", 0x59, 9, 0, 0xef },
  { "STX (,X++)", 0x59, 9, 0, 0x29 },
  { "STX (,Y++)", 0x59, 9, 0, 0x39 },
  { "STX (,U++)", 0x59, 9, 0, 0x59 },
  { "STX (,S++)", 0x59, 9, 0, 0x69 },
  { "STX (,--X)", 0x59, 9, 0, 0x2b },
  { "STX (,--Y)", 0x59, 9, 0, 0x3b },
  { "STX (,--U)", 0x59, 9, 0, 0x5b },
  { "STX (,--S)", 0x59, 9, 0, 0x6b },
  { "STX (x,X)", 0x59, 7, 1, 0x2c }, /* 8-bit offset */
  { "STX (x,Y)", 0x59, 7, 1, 0x3c }, /* 8-bit offset */
  { "STX (x,U)", 0x59, 7, 1, 0x5c }, /* 8-bit offset */
  { "STX (x,S)", 0x59, 7, 1, 0x6c }, /* 8-bit offset */
  { "STX (?,X)", 0x59, 8, 0, 0x2d }, /* 16-bit offset */
  { "STX (?,Y)", 0x59, 8, 0, 0x3d }, /* 16-bit offset */
  { "STX (?,U)", 0x59, 8, 0, 0x5d }, /* 16-bit offset */
  { "STX (?,S)", 0x59, 8, 0, 0x6d }, /* 16-bit offset */
  { "STX (x,PCR)", 0x59, 7, 1, 0x7c }, /* 8-bit offset */
  { "STX (?,PCR)", 0x59, 8, 0, 0x7d }, /* 16-bit offset */
  { "STX (?)", 0x59, 8, 0, 0x0f }, /* 16-bit offset */
  { "STX s,X", 0x59, 6, 1, 0x26 }, /* 5-bit offset */
  { "STX s,Y", 0x59, 6, 1, 0x36 }, /* 5-bit offset */
  { "STX s,U", 0x59, 6, 1, 0x56 }, /* 5-bit offset */
  { "STX s,S", 0x59, 6, 1, 0x66 }, /* 5-bit offset */
  { "STX x,X", 0x59, 7, 1, 0x24 }, /* 8-bit offset */
  { "STX x,Y", 0x59, 7, 1, 0x34 }, /* 8-bit offset */
  { "STX x,U", 0x59, 7, 1, 0x54 }, /* 8-bit offset */
  { "STX x,S", 0x59, 7, 1, 0x64 }, /* 8-bit offset */
  { "STX ?,X", 0x59, 8, 0, 0x25 }, /* 16-bit offset */
  { "STX ?,Y", 0x59, 8, 0, 0x35 }, /* 16-bit offset */
  { "STX ?,U", 0x59, 8, 0, 0x55 }, /* 16-bit offset */
  { "STX ?,S", 0x59, 8, 0, 0x65 }, /* 16-bit offset */
  { "STX x,PCR", 0x59, 7, 1, 0x74 }, /* 8-bit offset */
  { "STX ?,PCR", 0x59, 8, 0, 0x75 }, /* 16-bit offset */
  { "STX x", 0x59, 2, 1, 0x07 },
  { "STX ?", 0x59, 2, 0, 0x07 },

  { "STY,X", 0x5a, 9, 0, 0x26 },
  { "STY,Y", 0x5a, 9, 0, 0x36 },
  { "STY,U", 0x5a, 9, 0, 0x56 },
  { "STY,S", 0x5a, 9, 0, 0x66 },
  { "STY A,X", 0x5a, 9, 0, 0xa0 },
  { "STY A,Y", 0x5a, 9, 0, 0xb0 },
  { "STY A,U", 0x5a, 9, 0, 0xd0 },
  { "STY A,S", 0x5a, 9, 0, 0xe0 },
  { "STY B,X", 0x5a, 9, 0, 0xa1 },
  { "STY B,Y", 0x5a, 9, 0, 0xb1 },
  { "STY B,U", 0x5a, 9, 0, 0xd1 },
  { "STY B,S", 0x5a, 9, 0, 0xe1 },
  { "STY D,X", 0x5a, 9, 0, 0xa7 },
  { "STY D,Y", 0x5a, 9, 0, 0xb7 },
  { "STY D,U", 0x5a, 9, 0, 0xd7 },
  { "STY D,S", 0x5a, 9, 0, 0xe8 },
  { "STY,X+", 0x5a, 9, 0, 0x20 },
  { "STY,Y+", 0x5a, 9, 0, 0x30 },
  { "STY,U+", 0x5a, 9, 0, 0x50 },
  { "STY,S+", 0x5a, 9, 0, 0x60 },
  { "STY,X++", 0x5a, 9, 0, 0x21 },
  { "STY,Y++", 0x5a, 9, 0, 0x31 },
  { "STY,U++", 0x5a, 9, 0, 0x51 },
  { "STY,S++", 0x5a, 9, 0, 0x61 },
  { "STY,-X", 0x5a, 9, 0, 0x22 },
  { "STY,-Y", 0x5a, 9, 0, 0x32 },
  { "STY,-U", 0x5a, 9, 0, 0x52 },
  { "STY,-S", 0x5a, 9, 0, 0x62 },
  { "STY,--X", 0x5a, 9, 0, 0x23 },
  { "STY,--Y", 0x5a, 9, 0, 0x33 },
  { "STY,--U", 0x5a, 9, 0, 0x53 },
  { "STY,--S", 0x5a, 9, 0, 0x63 },
  { "STY (,X)", 0x5a, 9, 0, 0x2e },
  { "STY (,Y)", 0x5a, 9, 0, 0x3e },
  { "STY (,U)", 0x5a, 9, 0, 0x5e },
  { "STY (,S)", 0x5a, 9, 0, 0x6e },
  { "STY (A,X)", 0x5a, 9, 0, 0xa8 },
  { "STY (A,Y)", 0x5a, 9, 0, 0xb8 },
  { "STY (A,U)", 0x5a, 9, 0, 0xd8 },
  { "STY (A,S)", 0x5a, 9, 0, 0xe8 },
  { "STY (B,X)", 0x5a, 9, 0, 0xa9 },
  { "STY (B,Y)", 0x5a, 9, 0, 0xb9 },
  { "STY (B,U)", 0x5a, 9, 0, 0xd9 },
  { "STY (B,S)", 0x5a, 9, 0, 0xe9 },
  { "STY (D,X)", 0x5a, 9, 0, 0xaf },
  { "STY (D,Y)", 0x5a, 9, 0, 0xbf },
  { "STY (D,U)", 0x5a, 9, 0, 0xdf },
  { "STY (D,S)", 0x5a, 9, 0, 0xef },
  { "STY (,X++)", 0x5a, 9, 0, 0x29 },
  { "STY (,Y++)", 0x5a, 9, 0, 0x39 },
  { "STY (,U++)", 0x5a, 9, 0, 0x59 },
  { "STY (,S++)", 0x5a, 9, 0, 0x69 },
  { "STY (,--X)", 0x5a, 9, 0, 0x2b },
  { "STY (,--Y)", 0x5a, 9, 0, 0x3b },
  { "STY (,--U)", 0x5a, 9, 0, 0x5b },
  { "STY (,--S)", 0x5a, 9, 0, 0x6b },
  { "STY (x,X)", 0x5a, 7, 1, 0x2c }, /* 8-bit offset */
  { "STY (x,Y)", 0x5a, 7, 1, 0x3c }, /* 8-bit offset */
  { "STY (x,U)", 0x5a, 7, 1, 0x5c }, /* 8-bit offset */
  { "STY (x,S)", 0x5a, 7, 1, 0x6c }, /* 8-bit offset */
  { "STY (?,X)", 0x5a, 8, 0, 0x2d }, /* 16-bit offset */
  { "STY (?,Y)", 0x5a, 8, 0, 0x3d }, /* 16-bit offset */
  { "STY (?,U)", 0x5a, 8, 0, 0x5d }, /* 16-bit offset */
  { "STY (?,S)", 0x5a, 8, 0, 0x6d }, /* 16-bit offset */
  { "STY (x,PCR)", 0x5a, 7, 1, 0x7c }, /* 8-bit offset */
  { "STY (?,PCR)", 0x5a, 8, 0, 0x7d }, /* 16-bit offset */
  { "STY (?)", 0x5a, 8, 0, 0x0f }, /* 16-bit offset */
  { "STY s,X", 0x5a, 6, 1, 0x26 }, /* 5-bit offset */
  { "STY s,Y", 0x5a, 6, 1, 0x36 }, /* 5-bit offset */
  { "STY s,U", 0x5a, 6, 1, 0x56 }, /* 5-bit offset */
  { "STY s,S", 0x5a, 6, 1, 0x66 }, /* 5-bit offset */
  { "STY x,X", 0x5a, 7, 1, 0x24 }, /* 8-bit offset */
  { "STY x,Y", 0x5a, 7, 1, 0x34 }, /* 8-bit offset */
  { "STY x,U", 0x5a, 7, 1, 0x54 }, /* 8-bit offset */
  { "STY x,S", 0x5a, 7, 1, 0x64 }, /* 8-bit offset */
  { "STY ?,X", 0x5a, 8, 0, 0x25 }, /* 16-bit offset */
  { "STY ?,Y", 0x5a, 8, 0, 0x35 }, /* 16-bit offset */
  { "STY ?,U", 0x5a, 8, 0, 0x55 }, /* 16-bit offset */
  { "STY ?,S", 0x5a, 8, 0, 0x65 }, /* 16-bit offset */
  { "STY x,PCR", 0x5a, 7, 1, 0x74 }, /* 8-bit offset */
  { "STY ?,PCR", 0x5a, 8, 0, 0x75 }, /* 16-bit offset */
  { "STY x", 0x5a, 2, 1, 0x07 },
  { "STY ?", 0x5a, 2, 0, 0x07 },

  { "SUBA #x", 0x1c, 1, 0, 0 },
  { "SUBA,X", 0x1e, 9, 0, 0x26 },
  { "SUBA,Y", 0x1e, 9, 0, 0x36 },
  { "SUBA,U", 0x1e, 9, 0, 0x56 },
  { "SUBA,S", 0x1e, 9, 0, 0x66 },
  { "SUBA A,X", 0x1e, 9, 0, 0xa0 },
  { "SUBA A,Y", 0x1e, 9, 0, 0xb0 },
  { "SUBA A,U", 0x1e, 9, 0, 0xd0 },
  { "SUBA A,S", 0x1e, 9, 0, 0xe0 },
  { "SUBA B,X", 0x1e, 9, 0, 0xa1 },
  { "SUBA B,Y", 0x1e, 9, 0, 0xb1 },
  { "SUBA B,U", 0x1e, 9, 0, 0xd1 },
  { "SUBA B,S", 0x1e, 9, 0, 0xe1 },
  { "SUBA D,X", 0x1e, 9, 0, 0xa7 },
  { "SUBA D,Y", 0x1e, 9, 0, 0xb7 },
  { "SUBA D,U", 0x1e, 9, 0, 0xd7 },
  { "SUBA D,S", 0x1e, 9, 0, 0xe8 },
  { "SUBA,X+", 0x1e, 9, 0, 0x20 },
  { "SUBA,Y+", 0x1e, 9, 0, 0x30 },
  { "SUBA,U+", 0x1e, 9, 0, 0x50 },
  { "SUBA,S+", 0x1e, 9, 0, 0x60 },
  { "SUBA,X++", 0x1e, 9, 0, 0x21 },
  { "SUBA,Y++", 0x1e, 9, 0, 0x31 },
  { "SUBA,U++", 0x1e, 9, 0, 0x51 },
  { "SUBA,S++", 0x1e, 9, 0, 0x61 },
  { "SUBA,-X", 0x1e, 9, 0, 0x22 },
  { "SUBA,-Y", 0x1e, 9, 0, 0x32 },
  { "SUBA,-U", 0x1e, 9, 0, 0x52 },
  { "SUBA,-S", 0x1e, 9, 0, 0x62 },
  { "SUBA,--X", 0x1e, 9, 0, 0x23 },
  { "SUBA,--Y", 0x1e, 9, 0, 0x33 },
  { "SUBA,--U", 0x1e, 9, 0, 0x53 },
  { "SUBA,--S", 0x1e, 9, 0, 0x63 },
  { "SUBA (,X)", 0x1e, 9, 0, 0x2e },
  { "SUBA (,Y)", 0x1e, 9, 0, 0x3e },
  { "SUBA (,U)", 0x1e, 9, 0, 0x5e },
  { "SUBA (,S)", 0x1e, 9, 0, 0x6e },
  { "SUBA (A,X)", 0x1e, 9, 0, 0xa8 },
  { "SUBA (A,Y)", 0x1e, 9, 0, 0xb8 },
  { "SUBA (A,U)", 0x1e, 9, 0, 0xd8 },
  { "SUBA (A,S)", 0x1e, 9, 0, 0xe8 },
  { "SUBA (B,X)", 0x1e, 9, 0, 0xa9 },
  { "SUBA (B,Y)", 0x1e, 9, 0, 0xb9 },
  { "SUBA (B,U)", 0x1e, 9, 0, 0xd9 },
  { "SUBA (B,S)", 0x1e, 9, 0, 0xe9 },
  { "SUBA (D,X)", 0x1e, 9, 0, 0xaf },
  { "SUBA (D,Y)", 0x1e, 9, 0, 0xbf },
  { "SUBA (D,U)", 0x1e, 9, 0, 0xdf },
  { "SUBA (D,S)", 0x1e, 9, 0, 0xef },
  { "SUBA (,X++)", 0x1e, 9, 0, 0x29 },
  { "SUBA (,Y++)", 0x1e, 9, 0, 0x39 },
  { "SUBA (,U++)", 0x1e, 9, 0, 0x59 },
  { "SUBA (,S++)", 0x1e, 9, 0, 0x69 },
  { "SUBA (,--X)", 0x1e, 9, 0, 0x2b },
  { "SUBA (,--Y)", 0x1e, 9, 0, 0x3b },
  { "SUBA (,--U)", 0x1e, 9, 0, 0x5b },
  { "SUBA (,--S)", 0x1e, 9, 0, 0x6b },
  { "SUBA (x,X)", 0x1e, 7, 1, 0x2c }, /* 8-bit offset */
  { "SUBA (x,Y)", 0x1e, 7, 1, 0x3c }, /* 8-bit offset */
  { "SUBA (x,U)", 0x1e, 7, 1, 0x5c }, /* 8-bit offset */
  { "SUBA (x,S)", 0x1e, 7, 1, 0x6c }, /* 8-bit offset */
  { "SUBA (?,X)", 0x1e, 8, 0, 0x2d }, /* 16-bit offset */
  { "SUBA (?,Y)", 0x1e, 8, 0, 0x3d }, /* 16-bit offset */
  { "SUBA (?,U)", 0x1e, 8, 0, 0x5d }, /* 16-bit offset */
  { "SUBA (?,S)", 0x1e, 8, 0, 0x6d }, /* 16-bit offset */
  { "SUBA (x,PCR)", 0x1e, 7, 1, 0x7c }, /* 8-bit offset */
  { "SUBA (?,PCR)", 0x1e, 8, 0, 0x7d }, /* 16-bit offset */
  { "SUBA (?)", 0x1e, 8, 0, 0x0f }, /* 16-bit offset */
  { "SUBA s,X", 0x1e, 6, 1, 0x26 }, /* 5-bit offset */
  { "SUBA s,Y", 0x1e, 6, 1, 0x36 }, /* 5-bit offset */
  { "SUBA s,U", 0x1e, 6, 1, 0x56 }, /* 5-bit offset */
  { "SUBA s,S", 0x1e, 6, 1, 0x66 }, /* 5-bit offset */
  { "SUBA x,X", 0x1e, 7, 1, 0x24 }, /* 8-bit offset */
  { "SUBA x,Y", 0x1e, 7, 1, 0x34 }, /* 8-bit offset */
  { "SUBA x,U", 0x1e, 7, 1, 0x54 }, /* 8-bit offset */
  { "SUBA x,S", 0x1e, 7, 1, 0x64 }, /* 8-bit offset */
  { "SUBA ?,X", 0x1e, 8, 0, 0x25 }, /* 16-bit offset */
  { "SUBA ?,Y", 0x1e, 8, 0, 0x35 }, /* 16-bit offset */
  { "SUBA ?,U", 0x1e, 8, 0, 0x55 }, /* 16-bit offset */
  { "SUBA ?,S", 0x1e, 8, 0, 0x65 }, /* 16-bit offset */
  { "SUBA x,PCR", 0x1e, 7, 1, 0x74 }, /* 8-bit offset */
  { "SUBA ?,PCR", 0x1e, 8, 0, 0x75 }, /* 16-bit offset */
  { "SUBA x", 0x1e, 2, 1, 0x07 },
  { "SUBA ?", 0x1e, 2, 0, 0x07 },

  { "SUBB #x", 0x1d, 1, 0, 0 },
  { "SUBB,X", 0x1f, 9, 0, 0x26 },
  { "SUBB,Y", 0x1f, 9, 0, 0x36 },
  { "SUBB,U", 0x1f, 9, 0, 0x56 },
  { "SUBB,S", 0x1f, 9, 0, 0x66 },
  { "SUBB A,X", 0x1f, 9, 0, 0xa0 },
  { "SUBB A,Y", 0x1f, 9, 0, 0xb0 },
  { "SUBB A,U", 0x1f, 9, 0, 0xd0 },
  { "SUBB A,S", 0x1f, 9, 0, 0xe0 },
  { "SUBB B,X", 0x1f, 9, 0, 0xa1 },
  { "SUBB B,Y", 0x1f, 9, 0, 0xb1 },
  { "SUBB B,U", 0x1f, 9, 0, 0xd1 },
  { "SUBB B,S", 0x1f, 9, 0, 0xe1 },
  { "SUBB D,X", 0x1f, 9, 0, 0xa7 },
  { "SUBB D,Y", 0x1f, 9, 0, 0xb7 },
  { "SUBB D,U", 0x1f, 9, 0, 0xd7 },
  { "SUBB D,S", 0x1f, 9, 0, 0xe8 },
  { "SUBB,X+", 0x1f, 9, 0, 0x20 },
  { "SUBB,Y+", 0x1f, 9, 0, 0x30 },
  { "SUBB,U+", 0x1f, 9, 0, 0x50 },
  { "SUBB,S+", 0x1f, 9, 0, 0x60 },
  { "SUBB,X++", 0x1f, 9, 0, 0x21 },
  { "SUBB,Y++", 0x1f, 9, 0, 0x31 },
  { "SUBB,U++", 0x1f, 9, 0, 0x51 },
  { "SUBB,S++", 0x1f, 9, 0, 0x61 },
  { "SUBB,-X", 0x1f, 9, 0, 0x22 },
  { "SUBB,-Y", 0x1f, 9, 0, 0x32 },
  { "SUBB,-U", 0x1f, 9, 0, 0x52 },
  { "SUBB,-S", 0x1f, 9, 0, 0x62 },
  { "SUBB,--X", 0x1f, 9, 0, 0x23 },
  { "SUBB,--Y", 0x1f, 9, 0, 0x33 },
  { "SUBB,--U", 0x1f, 9, 0, 0x53 },
  { "SUBB,--S", 0x1f, 9, 0, 0x63 },
  { "SUBB (,X)", 0x1f, 9, 0, 0x2e },
  { "SUBB (,Y)", 0x1f, 9, 0, 0x3e },
  { "SUBB (,U)", 0x1f, 9, 0, 0x5e },
  { "SUBB (,S)", 0x1f, 9, 0, 0x6e },
  { "SUBB (A,X)", 0x1f, 9, 0, 0xa8 },
  { "SUBB (A,Y)", 0x1f, 9, 0, 0xb8 },
  { "SUBB (A,U)", 0x1f, 9, 0, 0xd8 },
  { "SUBB (A,S)", 0x1f, 9, 0, 0xe8 },
  { "SUBB (B,X)", 0x1f, 9, 0, 0xa9 },
  { "SUBB (B,Y)", 0x1f, 9, 0, 0xb9 },
  { "SUBB (B,U)", 0x1f, 9, 0, 0xd9 },
  { "SUBB (B,S)", 0x1f, 9, 0, 0xe9 },
  { "SUBB (D,X)", 0x1f, 9, 0, 0xaf },
  { "SUBB (D,Y)", 0x1f, 9, 0, 0xbf },
  { "SUBB (D,U)", 0x1f, 9, 0, 0xdf },
  { "SUBB (D,S)", 0x1f, 9, 0, 0xef },
  { "SUBB (,X++)", 0x1f, 9, 0, 0x29 },
  { "SUBB (,Y++)", 0x1f, 9, 0, 0x39 },
  { "SUBB (,U++)", 0x1f, 9, 0, 0x59 },
  { "SUBB (,S++)", 0x1f, 9, 0, 0x69 },
  { "SUBB (,--X)", 0x1f, 9, 0, 0x2b },
  { "SUBB (,--Y)", 0x1f, 9, 0, 0x3b },
  { "SUBB (,--U)", 0x1f, 9, 0, 0x5b },
  { "SUBB (,--S)", 0x1f, 9, 0, 0x6b },
  { "SUBB (x,X)", 0x1f, 7, 1, 0x2c }, /* 8-bit offset */
  { "SUBB (x,Y)", 0x1f, 7, 1, 0x3c }, /* 8-bit offset */
  { "SUBB (x,U)", 0x1f, 7, 1, 0x5c }, /* 8-bit offset */
  { "SUBB (x,S)", 0x1f, 7, 1, 0x6c }, /* 8-bit offset */
  { "SUBB (?,X)", 0x1f, 8, 0, 0x2d }, /* 16-bit offset */
  { "SUBB (?,Y)", 0x1f, 8, 0, 0x3d }, /* 16-bit offset */
  { "SUBB (?,U)", 0x1f, 8, 0, 0x5d }, /* 16-bit offset */
  { "SUBB (?,S)", 0x1f, 8, 0, 0x6d }, /* 16-bit offset */
  { "SUBB (x,PCR)", 0x1f, 7, 1, 0x7c }, /* 8-bit offset */
  { "SUBB (?,PCR)", 0x1f, 8, 0, 0x7d }, /* 16-bit offset */
  { "SUBB (?)", 0x1f, 8, 0, 0x0f }, /* 16-bit offset */
  { "SUBB s,X", 0x1f, 6, 1, 0x26 }, /* 5-bit offset */
  { "SUBB s,Y", 0x1f, 6, 1, 0x36 }, /* 5-bit offset */
  { "SUBB s,U", 0x1f, 6, 1, 0x56 }, /* 5-bit offset */
  { "SUBB s,S", 0x1f, 6, 1, 0x66 }, /* 5-bit offset */
  { "SUBB x,X", 0x1f, 7, 1, 0x24 }, /* 8-bit offset */
  { "SUBB x,Y", 0x1f, 7, 1, 0x34 }, /* 8-bit offset */
  { "SUBB x,U", 0x1f, 7, 1, 0x54 }, /* 8-bit offset */
  { "SUBB x,S", 0x1f, 7, 1, 0x64 }, /* 8-bit offset */
  { "SUBB ?,X", 0x1f, 8, 0, 0x25 }, /* 16-bit offset */
  { "SUBB ?,Y", 0x1f, 8, 0, 0x35 }, /* 16-bit offset */
  { "SUBB ?,U", 0x1f, 8, 0, 0x55 }, /* 16-bit offset */
  { "SUBB ?,S", 0x1f, 8, 0, 0x65 }, /* 16-bit offset */
  { "SUBB x,PCR", 0x1f, 7, 1, 0x74 }, /* 8-bit offset */
  { "SUBB ?,PCR", 0x1f, 8, 0, 0x75 }, /* 16-bit offset */
  { "SUBB x", 0x1f, 2, 1, 0x07 },
  { "SUBB ?", 0x1f, 2, 0, 0x07 },

  { "SUBD #x", 0x56, 1, 0, 0 },
  { "SUBD,X", 0x57, 9, 0, 0x26 },
  { "SUBD,Y", 0x57, 9, 0, 0x36 },
  { "SUBD,U", 0x57, 9, 0, 0x56 },
  { "SUBD,S", 0x57, 9, 0, 0x66 },
  { "SUBD A,X", 0x57, 9, 0, 0xa0 },
  { "SUBD A,Y", 0x57, 9, 0, 0xb0 },
  { "SUBD A,U", 0x57, 9, 0, 0xd0 },
  { "SUBD A,S", 0x57, 9, 0, 0xe0 },
  { "SUBD B,X", 0x57, 9, 0, 0xa1 },
  { "SUBD B,Y", 0x57, 9, 0, 0xb1 },
  { "SUBD B,U", 0x57, 9, 0, 0xd1 },
  { "SUBD B,S", 0x57, 9, 0, 0xe1 },
  { "SUBD D,X", 0x57, 9, 0, 0xa7 },
  { "SUBD D,Y", 0x57, 9, 0, 0xb7 },
  { "SUBD D,U", 0x57, 9, 0, 0xd7 },
  { "SUBD D,S", 0x57, 9, 0, 0xe8 },
  { "SUBD,X+", 0x57, 9, 0, 0x20 },
  { "SUBD,Y+", 0x57, 9, 0, 0x30 },
  { "SUBD,U+", 0x57, 9, 0, 0x50 },
  { "SUBD,S+", 0x57, 9, 0, 0x60 },
  { "SUBD,X++", 0x57, 9, 0, 0x21 },
  { "SUBD,Y++", 0x57, 9, 0, 0x31 },
  { "SUBD,U++", 0x57, 9, 0, 0x51 },
  { "SUBD,S++", 0x57, 9, 0, 0x61 },
  { "SUBD,-X", 0x57, 9, 0, 0x22 },
  { "SUBD,-Y", 0x57, 9, 0, 0x32 },
  { "SUBD,-U", 0x57, 9, 0, 0x52 },
  { "SUBD,-S", 0x57, 9, 0, 0x62 },
  { "SUBD,--X", 0x57, 9, 0, 0x23 },
  { "SUBD,--Y", 0x57, 9, 0, 0x33 },
  { "SUBD,--U", 0x57, 9, 0, 0x53 },
  { "SUBD,--S", 0x57, 9, 0, 0x63 },
  { "SUBD (,X)", 0x57, 9, 0, 0x2e },
  { "SUBD (,Y)", 0x57, 9, 0, 0x3e },
  { "SUBD (,U)", 0x57, 9, 0, 0x5e },
  { "SUBD (,S)", 0x57, 9, 0, 0x6e },
  { "SUBD (A,X)", 0x57, 9, 0, 0xa8 },
  { "SUBD (A,Y)", 0x57, 9, 0, 0xb8 },
  { "SUBD (A,U)", 0x57, 9, 0, 0xd8 },
  { "SUBD (A,S)", 0x57, 9, 0, 0xe8 },
  { "SUBD (B,X)", 0x57, 9, 0, 0xa9 },
  { "SUBD (B,Y)", 0x57, 9, 0, 0xb9 },
  { "SUBD (B,U)", 0x57, 9, 0, 0xd9 },
  { "SUBD (B,S)", 0x57, 9, 0, 0xe9 },
  { "SUBD (D,X)", 0x57, 9, 0, 0xaf },
  { "SUBD (D,Y)", 0x57, 9, 0, 0xbf },
  { "SUBD (D,U)", 0x57, 9, 0, 0xdf },
  { "SUBD (D,S)", 0x57, 9, 0, 0xef },
  { "SUBD (,X++)", 0x57, 9, 0, 0x29 },
  { "SUBD (,Y++)", 0x57, 9, 0, 0x39 },
  { "SUBD (,U++)", 0x57, 9, 0, 0x59 },
  { "SUBD (,S++)", 0x57, 9, 0, 0x69 },
  { "SUBD (,--X)", 0x57, 9, 0, 0x2b },
  { "SUBD (,--Y)", 0x57, 9, 0, 0x3b },
  { "SUBD (,--U)", 0x57, 9, 0, 0x5b },
  { "SUBD (,--S)", 0x57, 9, 0, 0x6b },
  { "SUBD (x,X)", 0x57, 7, 1, 0x2c }, /* 8-bit offset */
  { "SUBD (x,Y)", 0x57, 7, 1, 0x3c }, /* 8-bit offset */
  { "SUBD (x,U)", 0x57, 7, 1, 0x5c }, /* 8-bit offset */
  { "SUBD (x,S)", 0x57, 7, 1, 0x6c }, /* 8-bit offset */
  { "SUBD (?,X)", 0x57, 8, 0, 0x2d }, /* 16-bit offset */
  { "SUBD (?,Y)", 0x57, 8, 0, 0x3d }, /* 16-bit offset */
  { "SUBD (?,U)", 0x57, 8, 0, 0x5d }, /* 16-bit offset */
  { "SUBD (?,S)", 0x57, 8, 0, 0x6d }, /* 16-bit offset */
  { "SUBD (x,PCR)", 0x57, 7, 1, 0x7c }, /* 8-bit offset */
  { "SUBD (?,PCR)", 0x57, 8, 0, 0x7d }, /* 16-bit offset */
  { "SUBD (?)", 0x57, 8, 0, 0x0f }, /* 16-bit offset */
  { "SUBD s,X", 0x57, 6, 1, 0x26 }, /* 5-bit offset */
  { "SUBD s,Y", 0x57, 6, 1, 0x36 }, /* 5-bit offset */
  { "SUBD s,U", 0x57, 6, 1, 0x56 }, /* 5-bit offset */
  { "SUBD s,S", 0x57, 6, 1, 0x66 }, /* 5-bit offset */
  { "SUBD x,X", 0x57, 7, 1, 0x24 }, /* 8-bit offset */
  { "SUBD x,Y", 0x57, 7, 1, 0x34 }, /* 8-bit offset */
  { "SUBD x,U", 0x57, 7, 1, 0x54 }, /* 8-bit offset */
  { "SUBD x,S", 0x57, 7, 1, 0x64 }, /* 8-bit offset */
  { "SUBD ?,X", 0x57, 8, 0, 0x25 }, /* 16-bit offset */
  { "SUBD ?,Y", 0x57, 8, 0, 0x35 }, /* 16-bit offset */
  { "SUBD ?,U", 0x57, 8, 0, 0x55 }, /* 16-bit offset */
  { "SUBD ?,S", 0x57, 8, 0, 0x65 }, /* 16-bit offset */
  { "SUBD x,PCR", 0x57, 7, 1, 0x74 }, /* 8-bit offset */
  { "SUBD ?,PCR", 0x57, 8, 0, 0x75 }, /* 16-bit offset */
  { "SUBD x", 0x57, 2, 1, 0x07 },
  { "SUBD ?", 0x57, 2, 0, 0x07 },

/*{ "SWI1", 0x3F, 0, 0, 0 },*/
/*{ "SWI2", 0x103F, 0, 0, 0 },*/
/*{ "SWI3", 0x113F, 0, 0, 0 },*/
/*{ "SWI", 0x3F, 0, 0, 0 },*/

/*{ "SYNC", 0x13, 0, 0, 0 },*/

  { "TFR r", 0x3f, 10, 0, 0 },

  { "TSTA", 0x90, 0, 0, 0 },
  { "TSTB", 0x91, 0, 0, 0 },
  { "TST,X", 0x92, 9, 0, 0x26 },
  { "TST,Y", 0x92, 9, 0, 0x36 },
  { "TST,U", 0x92, 9, 0, 0x56 },
  { "TST,S", 0x92, 9, 0, 0x66 },
  { "TST A,X", 0x92, 9, 0, 0xa0 },
  { "TST A,Y", 0x92, 9, 0, 0xb0 },
  { "TST A,U", 0x92, 9, 0, 0xd0 },
  { "TST A,S", 0x92, 9, 0, 0xe0 },
  { "TST B,X", 0x92, 9, 0, 0xa1 },
  { "TST B,Y", 0x92, 9, 0, 0xb1 },
  { "TST B,U", 0x92, 9, 0, 0xd1 },
  { "TST B,S", 0x92, 9, 0, 0xe1 },
  { "TST D,X", 0x92, 9, 0, 0xa7 },
  { "TST D,Y", 0x92, 9, 0, 0xb7 },
  { "TST D,U", 0x92, 9, 0, 0xd7 },
  { "TST D,S", 0x92, 9, 0, 0xe8 },
  { "TST,X+", 0x92, 9, 0, 0x20 },
  { "TST,Y+", 0x92, 9, 0, 0x30 },
  { "TST,U+", 0x92, 9, 0, 0x50 },
  { "TST,S+", 0x92, 9, 0, 0x60 },
  { "TST,X++", 0x92, 9, 0, 0x21 },
  { "TST,Y++", 0x92, 9, 0, 0x31 },
  { "TST,U++", 0x92, 9, 0, 0x51 },
  { "TST,S++", 0x92, 9, 0, 0x61 },
  { "TST,-X", 0x92, 9, 0, 0x22 },
  { "TST,-Y", 0x92, 9, 0, 0x32 },
  { "TST,-U", 0x92, 9, 0, 0x52 },
  { "TST,-S", 0x92, 9, 0, 0x62 },
  { "TST,--X", 0x92, 9, 0, 0x23 },
  { "TST,--Y", 0x92, 9, 0, 0x33 },
  { "TST,--U", 0x92, 9, 0, 0x53 },
  { "TST,--S", 0x92, 9, 0, 0x63 },
  { "TST (,X)", 0x92, 9, 0, 0x2e },
  { "TST (,Y)", 0x92, 9, 0, 0x3e },
  { "TST (,U)", 0x92, 9, 0, 0x5e },
  { "TST (,S)", 0x92, 9, 0, 0x6e },
  { "TST (A,X)", 0x92, 9, 0, 0xa8 },
  { "TST (A,Y)", 0x92, 9, 0, 0xb8 },
  { "TST (A,U)", 0x92, 9, 0, 0xd8 },
  { "TST (A,S)", 0x92, 9, 0, 0xe8 },
  { "TST (B,X)", 0x92, 9, 0, 0xa9 },
  { "TST (B,Y)", 0x92, 9, 0, 0xb9 },
  { "TST (B,U)", 0x92, 9, 0, 0xd9 },
  { "TST (B,S)", 0x92, 9, 0, 0xe9 },
  { "TST (D,X)", 0x92, 9, 0, 0xaf },
  { "TST (D,Y)", 0x92, 9, 0, 0xbf },
  { "TST (D,U)", 0x92, 9, 0, 0xdf },
  { "TST (D,S)", 0x92, 9, 0, 0xef },
  { "TST (,X++)", 0x92, 9, 0, 0x29 },
  { "TST (,Y++)", 0x92, 9, 0, 0x39 },
  { "TST (,U++)", 0x92, 9, 0, 0x59 },
  { "TST (,S++)", 0x92, 9, 0, 0x69 },
  { "TST (,--X)", 0x92, 9, 0, 0x2b },
  { "TST (,--Y)", 0x92, 9, 0, 0x3b },
  { "TST (,--U)", 0x92, 9, 0, 0x5b },
  { "TST (,--S)", 0x92, 9, 0, 0x6b },
  { "TST (x,X)", 0x92, 7, 1, 0x2c }, /* 8-bit offset */
  { "TST (x,Y)", 0x92, 7, 1, 0x3c }, /* 8-bit offset */
  { "TST (x,U)", 0x92, 7, 1, 0x5c }, /* 8-bit offset */
  { "TST (x,S)", 0x92, 7, 1, 0x6c }, /* 8-bit offset */
  { "TST (?,X)", 0x92, 8, 0, 0x2d }, /* 16-bit offset */
  { "TST (?,Y)", 0x92, 8, 0, 0x3d }, /* 16-bit offset */
  { "TST (?,U)", 0x92, 8, 0, 0x5d }, /* 16-bit offset */
  { "TST (?,S)", 0x92, 8, 0, 0x6d }, /* 16-bit offset */
  { "TST (x,PCR)", 0x92, 7, 1, 0x7c }, /* 8-bit offset */
  { "TST (?,PCR)", 0x92, 8, 0, 0x7d }, /* 16-bit offset */
  { "TST (?)", 0x92, 8, 0, 0x0f }, /* 16-bit offset */
  { "TST s,X", 0x92, 6, 1, 0x26 }, /* 5-bit offset */
  { "TST s,Y", 0x92, 6, 1, 0x36 }, /* 5-bit offset */
  { "TST s,U", 0x92, 6, 1, 0x56 }, /* 5-bit offset */
  { "TST s,S", 0x92, 6, 1, 0x66 }, /* 5-bit offset */
  { "TST x,X", 0x92, 7, 1, 0x24 }, /* 8-bit offset */
  { "TST x,Y", 0x92, 7, 1, 0x34 }, /* 8-bit offset */
  { "TST x,U", 0x92, 7, 1, 0x54 }, /* 8-bit offset */
  { "TST x,S", 0x92, 7, 1, 0x64 }, /* 8-bit offset */
  { "TST ?,X", 0x92, 8, 0, 0x25 }, /* 16-bit offset */
  { "TST ?,Y", 0x92, 8, 0, 0x35 }, /* 16-bit offset */
  { "TST ?,U", 0x92, 8, 0, 0x55 }, /* 16-bit offset */
  { "TST ?,S", 0x92, 8, 0, 0x65 }, /* 16-bit offset */
  { "TST x,PCR", 0x92, 7, 1, 0x74 }, /* 8-bit offset */
  { "TST ?,PCR", 0x92, 8, 0, 0x75 }, /* 16-bit offset */
  { "TST x", 0x92, 2, 1, 0x07 },
  { "TST ?", 0x92, 2, 0, 0x07 },
  
  { "E", 0x100, 0xFF, 0, 0 }
};
