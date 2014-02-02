#include <stdio.h>
#include "getline.c"
#include "copy.c"
#define MAXLINE 1000

int main(void)
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {
        printf("Max length: %d\n", max);
        printf("%s", longest);
    }
    return 0;
}
