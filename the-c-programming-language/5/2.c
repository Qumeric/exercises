#include <stdio.h>
#include <ctype.h>
#define SIZE 1000

int main(void)
{
    float array[SIZE];
    int n, getfloat(float *);
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        printf("%g\n", array[n]);

    return 0;
}

int getfloat(float*pn)
{
    long long c, afterDot;
    short sign;
    afterDot = 1;
   
    while (isspace(c = getchar()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getchar();
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        c = getchar();
        for (; isdigit(c); c = getchar()) {
            *pn = 10 * *pn + (c - '0');
            afterDot *= 10;
        }
    }
    *pn /= afterDot*sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}
