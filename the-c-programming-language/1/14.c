#include <stdio.h>
#define FIRST 32   // 32 is first printable ASCII character <space>
#define LEN 127-32 // 127 is last printable ASCII character <delete>

int main(void)
{
    int c;
    int lengths[LEN];

    for (int i=0; i<LEN;i++)
        lengths[i] = 0;

    while((c = getchar()) != EOF)
        lengths[c-FIRST]++;

    for (int i=0; i<LEN; i++) {
        printf("%c ", i+FIRST);
        for (int j=0; j<lengths[i];j++)
            putchar('*');
        putchar('\n');
    }
}
