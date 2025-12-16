#include <stdio.h>

int main(void)
{
    int c;
    int blanks = 0, tabs = 0, newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }

    printf("blanks: %d\ntabs: %d\nnewline: %d\n",
           blanks, tabs, newlines);

    return 0;
}

