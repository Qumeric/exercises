#include <stdio.h>

int main(void)
{
    int c;
    int lengths[128];

    for (int i=0; i<128;i++)
        lengths[i] = 0;

    while((c = getchar()) != EOF)
        lengths[c]++;

    for (int i=33; i<128; i++) {
        putchar(i);
        for (int j=0; j<lengths[i];j++)
            putchar('*');
        putchar('\n');
    }
}
