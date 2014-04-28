#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../1/getline.c"
#define MAXLINE 100

double atof(char[]);

int main(void)
{
    double atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);

    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", atof(line));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign, esign, exp;

    for (i = 0; isspace(s[i]); i++)
        ; // skip white space
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    exp = 0;

    if (tolower(s[i++]) == 'e') {
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    for (; exp > 0; exp--) {
        if (esign == 1)
            val *= 10.0;
        else
            val /= 10.0;
    }
    
    return sign * val / power;
}
