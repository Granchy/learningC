#include <stdio.h>

#define MAXLINE 10

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while((len = my_getline(line,MAXLINE)) > 0) 
        if(len > max) {
        max = len;
        copy(longest,line);
        }
    if (max > 0) printf("%d: %s", max, longest);

    return 0;
}

int my_getline(char s[], int lim) {
    int c, i = 0;
    for(; (c=getchar()) != EOF && c !='\n'; i++) {
        if(i < lim -1) s[i] = c;
    }
    if(c == '\n' && i < lim -1) {
        s[i] = c;
        i++;
        s[i] = '\0';

    } else if (i >= lim -1){
        s[lim-2] = '\n';
        s[lim-1] = '\0';
        i = i+1;
    }
    
    return i;

}

void copy(char to[], char from[]) {
    int i = 0;

    while((to[i] = from[i]) != '\0')  i++;
}

