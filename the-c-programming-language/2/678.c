/* 
 * All this functions threat bits like this:
 * 000010011100
 * Length of the sequence is 8 (begins from highest non-zero bit). 
 * First 1 is zeroth bit.
 * 111 is three bits starting from third bit.
 */ 

#include <stdio.h>
#include <math.h>

unsigned char getBitLength(unsigned);
unsigned getbits(unsigned, unsigned, unsigned);
unsigned setbits(unsigned, unsigned, unsigned, unsigned);
unsigned invert(unsigned, unsigned, unsigned);
unsigned rightrot(unsigned, unsigned);

int main(void)
{   
    printf("setbits:  %x\n", setbits(0xafcd, 4, 4, 0xb));
    printf("invert:   %x\n", invert(0xa4cd, 4, 4));
    printf("rightrot: %x\n", rightrot(0xbcda, 4));

    return 0;
}

unsigned getbits(unsigned x, unsigned p, unsigned n)
{
    unsigned char len = getBitLength(x);
    return (x >> (len-p-n)) & ~(~0 << n);
}

unsigned char getBitLength(unsigned n)
{
    for (unsigned i = 1; ; i++) {
        if (pow(2.0, i) > n)
            return i;
    }
}

// 2.6
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned char len = getBitLength(x);
    x = x & ~(~(~0 << n) << (len-p-n));
    y = (y & (unsigned) (pow(2, (n))-1)) << (len-p-n);
    return x|y;

}

// 2.7
unsigned invert(unsigned x, unsigned p, unsigned n)
{
    unsigned y = getbits(x, p, n);
    x = setbits(x, p, n, ~y);
    return x;
}

// 2.8
unsigned rightrot(unsigned x, unsigned n)
{
    unsigned char len = getBitLength(x);
    unsigned lastbits = x & ~(~0 << n);
    x >>= n;
    return x|(lastbits<<(len-n));
}

