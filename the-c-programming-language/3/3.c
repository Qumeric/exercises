#include <stdio.h>
#include "../1/getline.c"
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main(void)
{
    char toExpand[MAXLINE];
    char expanded[MAXLINE];

    while(getline(toExpand, MAXLINE) > 0) {
        expand(toExpand, expanded);
        printf("Expanded: %s\n", expanded);
    }
    
    return 0;
}

/* Simple version (FIXME)
 * prints all ASCII characters from sequences like a-bC-D0-1e-f2-3G-H
 * also may work with something like H-k0-t and even with -!?, tho shouldn't
 */
void expand(char s1[], char s2[])
{
    int c = 0;

    for (int i = 0; s1[i] != '\0' && s1[i] != '\n'; i+=3) {
        for (int j = s1[i]; j <= s1[i+2]; j++)
            s2[c++] = j;
    }
    s2[c] = '\0'
}
