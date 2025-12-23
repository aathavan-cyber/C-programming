/*Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/
#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        while (exp-- > 0)
            val = (exp_sign == 1) ? val * 10 : val / 10;
    }
    return val;
}

int main(void)
{
    char s1[] = "123.45e-6";
    char s2[] = "-1.5E2";
    char s3[] = "10e3";
    printf("%g\n", atof(s1));
    printf("%g\n", atof(s2));
    printf("%g\n", atof(s3));
    return 0;
}

