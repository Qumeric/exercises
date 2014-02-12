#include <stdio.h>
#include "../1/getline.c"
#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main(void)
{
    char toExpand[MAXLINE] = "a-z0-9";
    char expanded[MAXLINE];

    while(getline(toExpand, MAXLINE) > 0) {
        expand(toExpand, expanded);
        printf("Expanded: %s\n", expanded);
    }
    
    return 0;
}

/* UNDONE */
void expand(char s1[], char s2[])
{
    int c = 0;

    for (int i = 0; s1[i] != '\0' && s1[i] != '\n'; i+=3) {
        for (int j = s1[i]; j <= s1[i+2]; j++)
            s2[c++] = j;
    }
}
