/*Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) push((int)pop() % (int)op2);
            else printf("error: zero divisor\n");
            break;
        case 's':
            push(sin(pop()));
            break;
        case 'e':
            push(exp(pop()));
            break;
        case 'p':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full\n");
}

double pop(void)
{
    if (sp > 0) return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[])
{
    int i = 0, c;
    while ((c = getch()) == ' ' || c == '\t');
    if (!isdigit(c) && c != '.' && !islower(c)) return c;
    if (islower(c)) {
        s[0] = c;
        s[1] = '\0';
        return c;
    }
    s[i++] = c;
    while (isdigit(c = getch())) s[i++] = c;
    if (c == '.') {
        s[i++] = c;
        while (isdigit(c = getch())) s[i++] = c;
    }
    s[i] = '\0';
    ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE) buf[bufp++] = c;
    else printf("ungetch: too many characters\n");
}

