#include <stdio.h>

int htoi(char[]);
int hexToDec(char n);

int main(void)
{
    printf("%d\n", htoi("ff"));
}

int htoi(char s[])
{
    int result = 0;
    int i = 0;

    if (s[1] == 'x' || s[1] == 'X')
        i = 2;

    for (; s[i] != '\0'; i++) {
        result = result * 16 + hexToDec(s[i]);
    }
    
    return result;
}

int hexToDec(char n)
{
    if (n >= '0' && n <= '9')
        return n-'0';
    else
        return n-'a'+10;
}
