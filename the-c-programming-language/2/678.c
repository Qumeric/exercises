/* 
 * All this functions threat bits like this:
 * 000010001100
 * Length of the sequence is 8 (stars from highest non-zero bit). 
 * 11 is two bits starting from fourth bit.
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

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned char len = getBitLength(x);
    x = x & ~(~(~0 << n) << (len-p-n));
    y = (y & (unsigned) (pow(2, (n))-1)) << (len-p-n);
    return x|y;

}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    unsigned y = getbits(x, p, n);
    x = setbits(x, p, n, ~y);
    return x;
}

unsigned rightrot(unsigned x, unsigned n)
{
    unsigned char len = getBitLength(x);
    unsigned lastbits = x & ~(~0 << n);
    x >>= n;
    return x|(lastbits<<(len-n));
}

