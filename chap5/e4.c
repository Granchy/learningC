#include <string.h>
#include<stdio.h>


short strend(char* s, char* t) {
    int lens = strlen(s), lent = strlen(t);
    s += lens - lent;
    while(*t) {
        // putchar(*s);
        // putchar(*t);
        if(*s != *t) return 0;
        else {
            s++;
            t++;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    printf("%d", strend("peepoo","poo"));
    return 0;
}
