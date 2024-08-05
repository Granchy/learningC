#include <string.h>

#define MAXLEN 1000
#define BUFFSIZE 50000

int getline(char *, int);



int readlines(char *p, char *lineptr[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *buffend = p + BUFFSIZE;


    nlines = 0;
    while((len = getline(line,MAXLEN)) > 0) {
              if(nlines >= maxlines) {
            int count = 0;
            while(count != nlines) {
                if(*p == '\0') count++;
                p++;
            }
            if(p + len >= buffend) return -1;
            else {
                line[len-1] = '\0';
                strcpy(p,line);
                lineptr[nlines++] = p;
            }
        }
    }
    return nlines;
}