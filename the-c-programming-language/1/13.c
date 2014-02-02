#define MAXLENGTH 16 
#include <stdio.h>

int main(void)
{
    int c;
    int length = 0;
    int lengths[MAXLENGTH];
    
    for (int i = 0; i < MAXLENGTH; i++)
        lengths[i] = 0;

    while ((c=getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            lengths[0]++;
            lengths[length]++;
            length = 0;
        } else {
            length++;
        }
    }

    for (int i = 0; i < MAXLENGTH; i++) {
        printf("%d", i);
        for (int j = 0; j < lengths[i]; j++)
            putchar('*');
        putchar('\n');
    }
}

