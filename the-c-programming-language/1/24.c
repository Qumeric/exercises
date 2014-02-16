#include <stdio.h>

int main(void)
{
    int c;
    int sq, dq, cb, sb, p;

    /* First  byte is responsible for all kinds of braces
     * Second byte is responsible for all kinds of quotes */
    short error = 0;

    sq = dq = cb = sb = p = 0;

    while((c = getchar()) != EOF) {
        switch(c) {
            case '\'':
                sq++;
                break;
            case '"':
                dq++;
                break;
            case '{':
                cb++;
                break;
            case '}':
                cb--;
                break;
            case '[':
                sb++;
                break;
            case ']':
                sb--;
                break;
            case '(':
                p++;
                break;
            case ')':
                p--;
                break;
        }
        if (cb < 0 || sb < 0 || p < 0)
            error |= 1;
    }
    if (sq % 2 == 1 || dq % 2 == 1)
        error |= 2;
    
    if (cb || sb || p)
        error |= 1;

    if (error == 0)
        printf("Possibly your program is correct\n");
    else {
        if (error & 1)
            printf("Something wrong with braces\n");
        if (error & 2)
            printf("Something wrong with quotes\n");
    }
    return 0;
}
