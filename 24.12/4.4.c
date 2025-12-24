/*Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.*/
#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double);
double pop(void);
void print_top(void);
void duplicate(void);
void swap(void);
void clear(void);

int main(void)
{
    push(10);
    push(20);
    print_top();
    duplicate();
    swap();
    clear();
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

void print_top(void)
{
    if (sp > 0) printf("%.8g\n", val[sp - 1]);
    else printf("stack empty\n");
}

void duplicate(void)
{
    if (sp > 0) push(val[sp - 1]);
    else printf("stack empty\n");
}

void swap(void)
{
    double t;
    if (sp >= 2) {
        t = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = t;
    } else printf("not enough elements\n");
}

void clear(void)
{
    sp = 0;
}

