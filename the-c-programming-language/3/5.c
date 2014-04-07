#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itob(int n, char s[], unsigned char b);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];

    itob(127127, line, 16); // 1f097
    printf("itob: %s\n", line);
    
    return 0;
}

void itob(int n, char s[], unsigned char b)
{
    int sign, i;
    char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    if ((sign = n) < 0)
        n = -n;

    i = 0;

    do {
        s[i++] = symbols[n % b];
    } while ((n /= b) > 0);
    
    if (sign < 0)
        s[i++] = '-';
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
