#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

int nextTabstop(int ts, int n) {
    if (ts == 1)
        return n;
    else
        return ts-1;
}

void entab(char line[], int n)
{
    int i = 0; // position in line
    int j = 0; // position in eline
    int tabstop = n;
    int spaces = 0;
    char eline[MAXLINE] = "";

    while(line[i] != EOF && line[i] != '\n') {
        if (line[i] == ' ' || line[i] == '\t') {
            while(1) {
                if (line[i] == ' ') {
                    spaces++;
                    if (spaces >= tabstop) {
                        eline[j++] = '\t';
                        tabstop = n;
                        spaces = 0;
                    }
                }
                else if (line[i] == '\t') {
                    tabstop = n;
                    spaces = 0;
                    eline[j++] = '\t';
                } else {
                    break;
                }
                i++;
            }
        } else {
            for (int c=0; c < spaces; c++)
                eline[j++] = ' ';
            spaces = 0;
            eline[j++] = line[i++];
            tabstop = nextTabstop(tabstop, n);
        }
    }

    eline[j] = '\0';

    printf("%s", eline);
}

// This exercise probably needs rewriting
int main(void)
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0) {
        entab(line, 8);
        putchar('\n');
    }
    return 0;
}
