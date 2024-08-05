#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    int a = 03;
    int p = 1;
      // Binary: 11
    // int b = 077;  // Binary: 0111111
    int unsigned result = setbits(240,5,3,170);// Result: 1000 (decimal 8)
    
    printf("Bitwise AND: %u\n", result);


    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned int mask = ~( ~(~0 << n) << p-1); // make sure you make the mask correctly
    return (x & mask) | (y & ~(~0 << n) << p-1) ;
}

unsigned invert(unsigned int x, unsigned int p, unsigned int n) {
    unsigned int mask = ~(~0 << n) << p -1;
    return x ^ mask;
}

