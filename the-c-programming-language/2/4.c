#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]);
bool in(char c, char s[]);

int main(void)
{   
    char line[1000] = "abcdefgh"; 
    squeeze(line, "ae");
    printf("%s\n", line);
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!in(s1[i], s2))
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

bool in(char c, char s[]) {
    bool isIt = false;
    
    for (int i=0; s[i] != '\0'; i++)
        if (s[i] == c)
            isIt = true;

    return isIt;
}
