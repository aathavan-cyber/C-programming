/* Exercise 5-20
 * Declaration parser with support for
 * qualifiers, function arguments, arrays and pointers
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, QUALIFIER };

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
void dirdcl(void);
void dcl(void);
void paramlist(void);


int main(void)
{
    while (1)
    {
        if (gettoken() == EOF)
            break;

        datatype[0] = '\0';
        name[0] = '\0';
        out[0] = '\0';

        strcpy(datatype, token);

        /* collect qualifiers after base datatype */
        for (;;)
        {
            if (gettoken() != QUALIFIER)
                break;

            strcat(datatype, " ");
            strcat(datatype, token);
        }

        dcl();

        if (tokentype != '\n')
        {
            puts("declaration error detected");
        }
        else
        {
            printf("identifier '%s' => %s %s\n",
                   name, out, datatype);
        }
    }

    return 0;
}

/* -------------------- dcl -------------------- */
void dcl(void)
{
    int ns = 0;

    while (tokentype == '*')
    {
        ns++;
        gettoken();
    }

    dirdcl();

    while (ns-- > 0)
    {
        strcat(out, " pointer to");
    }
}

/* -------------------- dirdcl -------------------- */
void dirdcl(void)
{
    int type;

    if (tokentype == '(')
    {
        gettoken();
        dcl();

        if (tokentype != ')')
            puts("warning: ')' expected");
    }
    else if (tokentype == NAME)
    {
        strcpy(name, token);
    }
    else
    {
        puts("invalid direct declaration");
        return;
    }

    while ((type = gettoken()) == PARENS ||
           type == BRACKETS ||
           type == '(')
    {
        if (type == PARENS)
        {
            strcat(out, " function returning");
        }
        else if (type == '(')
        {
            strcat(out, " function taking");
            paramlist()
