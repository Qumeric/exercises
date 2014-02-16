#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

void detab(char line[], int n);

int main(void)
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0) {
        detab(line, 8);
    }
    return 0;
}

void detab(char line[], int n)
{
    int i, j;
    i = j = 0;
    char dline[MAXLINE] = "";

    for (; line[i] != '\n' && line[i] != EOF; i++) {
        if (line[i] != '\t')
            dline[j++] = line[i];
        else
            for (int k = j%n; k < n; k++)
                dline[j++] = ' ';
    }

    if (line[i] == '\n')
        dline[j++] = '\n';
    dline[j] = '\0';

    printf("%s", dline);
}
