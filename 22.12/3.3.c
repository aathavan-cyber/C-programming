/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/
#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[])
{
    int i, j = 0;
    char c;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' &&
            i > 0 &&
            s1[i+1] != '\0' &&
            (
              (isdigit(s1[i-1]) && isdigit(s1[i+1])) ||
              (islower(s1[i-1]) && islower(s1[i+1])) ||
              (isupper(s1[i-1]) && isupper(s1[i+1]))
            ) &&
            s1[i-1] < s1[i+1]) {
            for (c = s1[i-1] + 1; c < s1[i+1]; c++)
                s2[j++] = c;
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main(void)
{
    char s1[100];
    char s2[200];
    printf("Enter shorthand string:\n");
    fgets(s1, sizeof(s1), stdin);
    expand(s1, s2);
    printf("Expanded string:\n%s\n", s2);
    return 0;
}

