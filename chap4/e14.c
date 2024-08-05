#include <stdio.h>

#define swap(t,x,y) {   \
    t temp = x;         \
    x = y;              \
    y = temp;              \
}

int main() {
    int x = 3;
    int y = 4;
    swap(int, x, y)
    printf(" x = %d, y = %d", x, y);

    return 0;

}

/*
macros are can be thought of as literals of code. You write a macro and when you call it with its arguments
all the arguments are replaced with the literal text that you write, thats why you can pass types and 
what not. Its pretty cool stuff.

this is whats known as macro substitution and it occurs during preprocessing, before the file is compiled
all the calls to the macros or to the symbolic constants are replaced by their values. its essentially just 
define some word with some text which we want to replace with some word
*/