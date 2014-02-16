#include <stdio.h>

int main(void)
{
    int c;
    char newline = 1;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (newline == 0)
                putchar('\n');
            newline = 1;
        } else {
            newline = 0;
            putchar(c);
        }
    }
}
