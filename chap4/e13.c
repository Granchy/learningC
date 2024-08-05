#include <string.h>
#include <stdio.h>



void reverse(char s[], int len) {
    static int n;
    if(strlen(s) == len) {
      n = 0;
      len -= 1;
    }
    if(!(n == len || n + 1 == len)) {
        n++;
        reverse(s, len-1);
        
    } 
        char temp = s[n];
        s[n] = s[len];
        s[len] = temp;
        n--;

    // "hello"


}    
int main() {
        char s[] = "hell";
        reverse(s, strlen(s));
        printf("%s", s);
        return 0;
    }