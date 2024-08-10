#include <ctype.h>
#include <stdio.h>

enum
{
    TRUE = 1,
    FALSE = 0
};

int string_const = FALSE;
int comment = FALSE;
int inline_comment = FALSE;
int multiline_comment = FALSE;
int preprocessor_control = FALSE;
char getword(char *word, int lim)
{
    char c, getch(void);
    void ungetch(int);

    char *w = word;
    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    switch (c)
    {
    case '#':
        *w++ = c;
        preprocessor_control = TRUE;
        break;
    case '/':
        *w++ = c;
        comment = TRUE;
        if((c = getch()) == '/') inline_comment = TRUE;
        else multiline_comment = TRUE;
        *w++ = c;
        break;
    case '_':
        break;
    default:
        if (!isalpha(c))
        {
            *w = '\0';
            return c;
        }
    }


    for (; --lim > 0; w++)
    {
        if(multiline_comment) {
            if(*w == '*') {
                char temp;
                if((temp = getchar()) == '/') {
                    --lim > 0 ? *(++w) = temp : ungetch(temp);
                    multiline_comment = FALSE;
                }
            }
        }
        if (!isalnum(*w) && !multiline_comment)
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
