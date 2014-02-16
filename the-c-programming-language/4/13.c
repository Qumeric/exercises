#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int reverse(char s[]);

int main(void)
{
    char line[MAXLINE] = "Metro";
    printf("%s\n", reverse(line));
}
