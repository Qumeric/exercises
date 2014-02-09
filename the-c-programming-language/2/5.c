#include <stdio.h>
#include <stdbool.h>

int any(char s1[], char s2[]);
bool in(char c, char s[]);

int main(void)
{   
    char line[1000] = "abcdefgh"; 
    printf("%d\n", any(line, "eh"));
}

int any(char s1[], char s2[])
{
    int location = -1;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (in(s1[i], s2)) {
            location = i;
            break;
        }
    }
    return location;
}

bool in(char c, char s[]) {
    bool isIt = false;
    
    for (int i=0; s[i] != '\0'; i++)
        if (s[i] == c)
            isIt = true;

    return isIt;
}
