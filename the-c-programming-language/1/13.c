#define MAXLENGTH 16 
#include <stdio.h>

/* Words can contain all characters except blanks.
 * 473 is a word and (.)(.) is a word too. */

int main(void)
{
    int c;
    short length = 0;
    int lengths[MAXLENGTH];

    for (int i = 0; i < MAXLENGTH; i++)
        lengths[i] = 0;

    while ((c=getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (length) {
                lengths[length-1]++;
                length = 0;
            }
        } else {
            length++;
        }
    }

    for (int i = 0; i < MAXLENGTH; i++) {
        printf("%d", i+1);
        for (int j = 0; j < lengths[i]; j++)
            putchar('*');
        putchar('\n');
    }
}
