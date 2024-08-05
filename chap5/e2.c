#include <ctype.h>
#include <stdio.h>

#define MAXLEN 1000
#define BUFFSIZE 100

int getch(void);
void ungetch(int);
int getfloat(float *);

int bufp = 0;
int buf[BUFFSIZE];

int main(void)
{

    float number = 0.0;
    getfloat(&number);

    printf("number: %f\n", number);

    return 0;
}

int getch(void)
{
    return bufp ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters in the buffer\n");
    else
        buf[bufp++] = c;
}

int getfloat(float *pf)
{
    int c, sign, power;
    float fpart;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pf = 0; isdigit(c); c = getch())
        *pf = 10 * *pf + (c - '0');

    if (c == '.')
        c = getch();

    for (fpart = 0, power = 1; isdigit(c); c = getch())
    {
        fpart = fpart * 10 + (c - '0');
        power *= 10;
    }

    *pf += sign * fpart / power;

    if (c != EOF)
        ungetch(c);

    return c;
}