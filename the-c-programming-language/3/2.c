#include <stdio.h>
#include "../1/getline.c"
#define MAXLINE 1000

void escape(char s[], char t[])
{
   int i, j;
   
   for (i = j = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
   }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] == '\\' && s[i+1] == 't') {
            t[j++] = '\t';
            i++;
        }
        else if (s[i] == '\\' && s[i+1] == 'n') {
            t[j++] = '\n';
            i++;
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

int main(void)
{
    char line[MAXLINE], escaped[MAXLINE];

    while(getline(line, MAXLINE) > 0) {
        escape(line, escaped);
        printf("Escaped:  \n%s\n", escaped);
        unescape(escaped, line);
        printf("Unescaped:\n%s\n", line);
    }

    return 0;
}
