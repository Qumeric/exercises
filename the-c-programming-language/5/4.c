#include <string.h>

// I hope it works
_Bool strend(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    _Bool equal = 1;

    if (len_t <= len_s) {
        s+=(len_s-len_t);

        do {
            if (!(*s++==*t++))
                equal = 0;
        } while(*s != '\0') 
    }
    return equal;
}
