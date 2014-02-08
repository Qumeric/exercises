#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool inComment, inQuotes, type;
    inComment = inQuotes = false;
    type = true;
    int c, oldC;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }

        if (!inQuotes) {
            if (c == '*') {
                if (oldC == '/') {
                    inComment = true;
                    putchar('\b');
                }
            }
            else if (c == '/') 
            {
                if (oldC == '*') {
                    inComment = false;
                    type = false;
                }
            }
        }
        if (!(inComment>inQuotes) && type)
            putchar(c);

        oldC = c;
        type = true;
    }
    return 0;
}
