/* ex2.3: a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.*/
#include <stdio.h>
#include <ctype.h>

int htoi(char s[]) {
    int i = 0, n = 0;

    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i += 2;

    for (; s[i] != '\0'; i++) {
        if (isdigit(s[i]))
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else
            break;
    }
    return n;
}

int main(void) {
    char hex[] = "FF";
    printf("Hex %s = %d\n", hex, htoi(hex));
    return 0;
}

