#include <stdio.h>

void strrcat(char *s, char *t)
{
    while(*s != '\0') {
        s++;
    }

    putchar(*(s+= 1));
    

    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

int main()
{
    char p[] = "hello";
    char q[] = " world";
    strrcat(p, q);
    // printf(p);

    return 0;
}