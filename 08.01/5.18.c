/* Exercise 5-18
 * dcl with error recovery:
 * skips bad input lines and continues processing
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int error = 0;

/* prototypes */
int gettoken(void);
void skipline(void);
void dirdcl(void);
void dcl(void);

/* --------------------------- main --------------------------- */
int main(void)
{
    for (;;)
    {
        if (gettoken() == EOF)
            break;

        error = 0;

        datatype[0] = '\0';
        out[0] = '\0';
        name[0] = '\0';

        strcpy(datatype, token);

        dcl();

        if (error)
        {
            skipline();
            puts("invalid declaration skipped");
        }
        else if (tokentype != '\n')
        {
            puts("syntax error in declaration");
            skipline();
        }
        else
        {
            printf("name: %s | desc: %s | type: %s\n",
                   name, out, datatype);
        }
    }
    return 0;
}

/* --------------------------- dcl --------------------------- */
void dcl(void)
{
    int ns = 0;

    while (gettoken() == '*')
        ns++;

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* --------------------------- dirdcl --------------------------- */
void dirdcl(void)
{
    int type;

    if (tokentype == '(')
    {
        dcl();
        if (tokentype != ')')
        {
            puts("error: missing ')'");
            error = 1;
        }
    }
    else if (tokentype == NAME)
    {
        strcpy(name, token);
    }
    else
    {
        puts("error: invalid declarator");
        error = 1;
        return;
    }

    while (!error &&
           ((type = gettoken()) == PARENS || type == BRACKETS))
    {
        if (type == PARENS)
        {
            strcat(out, " function returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/* --------------------------- gettoken --------------------------- */
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == '(')
    {
        if ((c = getchar()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }

        ungetc(c, stdin);
        return tokentype = '(';
    }
    else if (c == '[')
    {
        *p++ = c;
        while ((*p++ = getchar()) != ']')
            ;

        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        *p++ = c;
        while (isalnum(c = getchar()))
            *p++ = c;

        *p = '\0';
        ungetc(c, stdin);
        return tokentype = NAME;
    }
    else
    {
        token[0] = c;
        token[1] = '\0';
        return tokentype = c;
    }
}

/* --------------------------- skipline --------------------------- */
void skipline(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
