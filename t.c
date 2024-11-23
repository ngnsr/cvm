#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t program[] = {
    0x2013, //  0010 0000 0001 0010             LD  R0, 20
    0x1220, //  0001 0010 0010 0000             AND R1,R0,0
    0xE407, //  1110 0100 0000 1000             lea R2
    0x1480, //  0001 0100 1000 0000             AND R2,R1,R0
    0x6280, //  0110 0010 1000 0000             ldr load from baser
    0xE404, //  1110 0100 0000 0100             lea R2
    0x200e, //  0010 0000 0000 1100             LD  R0, 14
    0x1480, //  0001 0100 1000 0010             AND R2,R0,R2
    0x6080, //  0110 0010 1000 0000             ldr load from baser
    0x1240, //  0001 0010 0100 0000             AND R1,R1,R0
    0x0000, // a[0]
    0x0001, // a[1]
    0x0002, // a[2]
    0x0003, // a[3]
    0x0004, // a[4]
    0x0005, // a[5]
    0x0006, // a[6]
    0x0007, // a[7]
    0x0008, // a[8]
    0x0009, // a[9]
    0x001,  // i
    0x001,  // j
    0xF025, //  1111 0000 0010 0101             HALT ;halt
};

int main() {
  const char *outf = "array_sum.obj";
  FILE *f = fopen(outf, "wb");
  if (!f) {
    fprintf(stderr, "Cannot write to file %s\n", outf);
    return 1;
  }

  size_t writ =
      fwrite(program, sizeof(uint16_t), sizeof(program) / sizeof(uint16_t), f);
  printf("Written %lu entries to file %s\n", writ, outf);
  fclose(f);

  return 0;
}
