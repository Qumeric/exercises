# include <stdio.h>

int strindex(char[], char[]);

int main(void)
{
    printf("%d\n", strindex("Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo",
                          "buffalo")); // answer - 56
}

int strindex(char s[], char t[])
{
    int pos = -1;
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i; s[j] != '\0'; j++) {
            if (s[j] != t[j-i])
                break;
            else if (t[j-i+1] == '\0')
                pos = i;
        }
    }
    return pos;
}

