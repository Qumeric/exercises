#include <stdio.h>

int main(void) {
    int i = 0, lim = 100, c;

    char s[lim];

    while (i < lim -1) {
        c=getchar();

        if (c == '\n')
            break;
        else if (c == EOF)
            break;
            
        s[i++] = c;
    }
}
