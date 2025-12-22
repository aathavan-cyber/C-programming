/*Ex3.2:(part 2)Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.*/
#include <stdio.h>

void unescape(char s[], const char t[])
{
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[++i]) {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = t[i];
                break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char t[100];
    char s[100];
    printf("Enter a string with escape sequences (\\n, \\t):\n");
    fgets(t, sizeof(t), stdin);
    unescape(s, t);
    printf("After unescaping:\n");
    printf("%s", s);
    return 0;
}

