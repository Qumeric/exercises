#include <stdio.h>

int main(void)
{
    int c, newlines, blanks, tabs;

    newlines = blanks = tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}
