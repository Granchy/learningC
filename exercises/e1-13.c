#include <stdio.h>

#define IN 1  // inside a world
#define OUT 0 // outside a word

int main()
{
    int c, maxLen, count, state;
    count = maxLen = 0;
    state = OUT;

    



// Find max word len
        while ((c = getchar()) != '\n') {
        if (c == ' ') {
            if (count > maxLen) maxLen = count;
        } else {
            count++;
        }
    }

    int wordLengths[maxLen];
    count = 0;

    for(int i = 0; i < maxLen; i ++) wordLengths[i] = 0;

    while((c = getchar()) != '\n') {
        if(c == ' ') {
            wordLengths[count-1] = count;
            count = 0;
        } else {
            count++;
        }
    }

    



    return 0;
}