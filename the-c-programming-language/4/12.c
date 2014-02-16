#include <stdio.h>
#define MAXLINE 1000

int itoa(int n, char line[]);

int main(void)
{
    char line[MAXLINE] = "";
    itoa(783, line);
    printf("%s\n", line);
}

int itoa(int n, char line[])
{
    int i = 0;

    if (n < 0) {
        line[i++] = '-';
        n = -n;
    }

    if (n / 10 != 0)
        i = itoa(n/10, line);

    line[i++] = n%10+'0';
    line[i+1] = '\0';

    return i;
}
