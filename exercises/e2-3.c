#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum HEXDIGITS {
    A = 10, B, C, D, E ,F
};

int htoi(const char s[]);
int upper(char c);

int main() {
    printf("%d\n", htoi("1AA"));    // Should print 426
    printf("%d\n", htoi("0x1AA"));  // Should print 426
    printf("%d\n", htoi("0X1AA"));  // Should print 426

    return 0;
}

int htoi(const char s[]) {
    int len = strlen(s);
    if (len == 0) return 0;  // Handle empty string

    int start = 0;
    int result = 0;
    if (len > 1 && s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) start = 2;

    for (int i = start; i < len; i++) {
        if (isdigit(s[i])) {
            result = result * 16 + (s[i] - '0');
        } else {
            switch (upper(s[i])) {
                case 'A': result = result * 16 + A;
                break;
                case 'B': result = result * 16 + B; 
                break;
                case 'C': result = result * 16 + C; 
                break;
                case 'D': result = result * 16 + D; 
                break;
                case 'E': result = result * 16 + E; 
                break;
                case 'F': result = result * 16 + F; 
                break;
                default: 
                    // Invalid character for hexadecimal
                    return -1; 
            }
        }
    }

    return result;
}

int upper(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    else return c;
}