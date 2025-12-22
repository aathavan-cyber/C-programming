/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s.*/
#include <stdio.h>

void escape(char s[], const char t[])
{
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char t[100];
    char s[200];
    printf("Enter a string:\n");
    fgets(t, sizeof(t), stdin);
    escape(s, t);
    printf("After escaping:\n%s\n", s);
    return 0;
}


