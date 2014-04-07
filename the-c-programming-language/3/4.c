#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
     int i, j, temp;
     for(i = 0, j = strlen(s) - 1; i<j; i++, j--)
     {
           temp = s[i];
           s[i] = s[j];
           s[j] = temp;
     }
}

void itoa(int n, char s[])
{
     int i, sign;
     bool toosmall = (n == INT_MIN);

     if (toosmall)
        n += 1;
     
     if((sign = n) < 0)
       n = -n;
     
     i = 0;
     do{
        s[i++] = n % 10 + '0';
     }while((n /= 10) > 0);
     
     if (toosmall)
         s[0] += 1;

     if(sign < 0)
       s[i++] = '-';

     s[i] = '\0';
     reverse(s);
}

int main(void)
{
    char test[20];
    itoa(INT_MIN, test);
    printf("Real minimum: %d\n", INT_MIN);
    printf("Itoa result:  %s\n", test);
    
    return 0;
}
