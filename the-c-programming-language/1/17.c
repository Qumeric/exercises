#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 80) {
            printf("%s", line);
        }
    return 0;
}
