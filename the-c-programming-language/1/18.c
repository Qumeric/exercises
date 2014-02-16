#include <stdio.h>
#include "getline.c"
#define MAXLINE 1000

// Maybe this exercise need rewriting
int main(void)
{
    int len;
    int i, j;
    char line[MAXLINE];
    char blanks[MAXLINE];
    short inword;

    while ((len = getline(line, MAXLINE)) > 0) {
        i = j = 0;
        inword = 1;
        blanks[0] = '\0';

        for(; line[i] == ' ' || line[i] == '\t'; i++)
            ;   // skip blanks at the beginning of the line
        
        if (line[i] == '\n')
            line[i] = '\0';  // remove empty lines

        for(; line[i] != '\0'; i++) {
            /* add all blanks to the blanks array */
            if (line[i] == ' ' || line[i] == '\t') {
                blanks[j++] = line[i];
                blanks[j] = '\0';
                inword = 0;
            } else {
                /* if encounter a word then print blanks array 
                 * (won't print blanks at the end of the line)*/
                if (inword == 0 && line[i] != '\n') {
                    printf(blanks);
                    j = 0;
                    blanks[0] = '\0';
                    inword = 1;
                }
                putchar(line[i]);
            }
        }
    }
    return 0;
}
