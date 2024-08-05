// this is exercise 10 from chapter 5.
#include <stdio.h>
#include <ctype.h>
#define MAXSTACK 1000

int stack[MAXSTACK];
int *stackp = stack;

int main(int argc, char *argv[])
{
    int result = 0;
    if (argc < 3)
    {
        printf("Usage: Add numbers and operators.");
    }
    else
    {
        while (--argc > 0)
        {
            char *c;
            c = *++argv;
            if (isdigit(*c))
            {
                *stackp = *c - '0';
                stackp++;
            }
            else
            {
                int op1 = *--stackp;
                int op2 = *--stackp;
                switch (*c)
                {
                case '*':
                    *stackp = op2 * op1;
                    break;
                case '+':
                    *stackp = op2 + op1;
                    break;
                }
                stackp++;
            }
        }
    }
    printf("%d", *--stackp);
    return 0;
}

// 14