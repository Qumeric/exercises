#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

void fold(char line[], int max, int tabstop) {
    int position = 0;

    for (int i = 0; line[i] != '\n'; i++) {
        if (position >= max) {
            putchar('-');
            putchar('\n');
            position = 0;
        }

        if (line[i] == '\t' || line[i] == ' ') {
            for (int j=position+1; ; j++) {
                if (line[j] == '\t' || line[j] == ' ' || line[j] == '\n') {
                    if (j >= max) {
                        putchar('\n');
                        position = 0;
                        i++;
                    }
                    break;
                }
            }
        }

        putchar(line[i]);
        
        if (line[i] == '\t')
            position += tabstop - position%tabstop;
        else
            position++;
    }

    return;
}

int main(void)
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0) {
        fold(line, 80, 8);
        putchar('\n');
    }
    return 0;
}
