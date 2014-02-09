#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("Signed char:    from %d to %d  \n", CHAR_MIN, CHAR_MAX );
    printf("Unsigned char:  from %u to %d  \n", 0,        UCHAR_MAX);
    printf("Signed short:   from %d to %d  \n", SHRT_MIN, SHRT_MAX );
    printf("Unsigned short  from %u to %d  \n", 0,        USHRT_MAX);
    printf("Signed int:     from %d to %d  \n", INT_MIN,  INT_MAX  );
    printf("Unsigned int    from %u to %u  \n", 0,        UINT_MAX );
    printf("Signed long     from %ld to %ld\n", LONG_MIN, LONG_MAX );
    printf("Unsigned long   from %lu to %lu\n", 0,        ULONG_MAX);

}
