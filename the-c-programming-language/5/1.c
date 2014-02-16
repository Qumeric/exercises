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

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
   
    while (isspace(c = getchar()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getchar();
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}
