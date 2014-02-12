#include <stdio.h>
#include <string.h>
#include "../1/getline.c"
#define MAXLINE 1000

void itoa(int n, char s[], unsigned short m);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];

    itoa(127127, line, 10);
    printf("itoa: %s\n", line);
    
    return 0;
}

void itoa(int n, char s[], unsigned short m)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < m)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
