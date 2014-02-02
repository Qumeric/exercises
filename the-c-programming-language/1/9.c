#include <stdio.h>

int main(void)
{
    int c;
    int in = 0;

    while((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            in = 0;
        } else {
            if (in == 0) {
                putchar(c);
                in = 1;
            }
        }
    }
}
