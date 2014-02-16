#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

void reverse(char[]);

int main(void) {
    int s;
    char line[MAXLINE];
    while ((s = getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char s[]) {
    int len = 0;
    char temp;

    while (s[len++] != '\n')
        ;
    len -= 1;

    for (int i=0; i <= len/2; i++) {
        temp = s[i];
        s[i] = s[len-i];
        s[len-i] = temp;
    }
}
