#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLINES 5000
#define MAXLEN 1000

#define BUFFSIZE 50000

char buff[BUFFSIZE];


char *lineptr[MAXLINES];
int mygetline(char *, int);
char *alloc(int);


int main(int argc, char const *argv[])
{
    int n, len, nlines = 0;
    char s[MAXLEN], *p, *lineptr[MAXLINES];

    if(argc > 1) n = abs(atoi(argv[1]));
    
    n = n ? n : 10;
    
    while((len = mygetline(s,MAXLEN)) > 0) {
        if(nlines >= MAXLINES || (p = alloc(len+1)) == NULL) {
            printf("OOM");
            return 0;
        }
        else {
            s[len] = '\0';
            strcpy(p,s);
            lineptr[nlines++] = p;
        }
    }
        
    int start = nlines - n <= 0 ? 0 : nlines - n;
    for(int i = start; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    return 0;
}

int mygetline(char *s, int maxline) {
    char c;
    int count = 0;
    while((c = getchar()) != '\n' && count < maxline-1) {
        *s = c;
        s++;
        count++;
    }
    *s = c;
    return count;
}

char *alloc(int need) {
    static int index = 0;
    if(index + need >= BUFFSIZE) return NULL;
    char *ptr = buff + index;
    index += need;
    return ptr;

}
