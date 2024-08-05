#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]) {
    int lenS = strlen(s);
    int lenT =strlen(t);

    for(int i = lenS-1; i >=0 ; i--) {
        if(s[i] == t[lenT- 1]) {
            putchar(s[i]);
            for(int j = lenT - 1; j >= 0; j--) {
                if(s[i] != t[j]) {
                    break;
                } else {
                    if (j ==0) return i;
                    else i--;
                }
            }
        }
    }
    return -1;
}

int main() {

    printf("%d", strrindex("hello there there", "there"));

    return 0;
}


