#include <stdio.h>
#include <ctype.h>
#define SIZE 1000

int main(void)
{
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("%d\n", array[n]);

    return 0;
}

// I dunno how it should work
int getint(int *pn)
{
    int c, sign, notdigit;
   
    while (isspace(c = getchar()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (notdigit=(c == '-' || c == '+'))
        c = getchar();
    if (!isdigit(c)) {
        ungetc(c, stdin);
        if (notdigit)
            ungetc((sign == -1) ? '-' : '+', stdin);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}
