#include <ctype.h>
#include <string.h>
#include <stdio.h>

double atof(char s[]) {
    double val, power, n, nPower;
    int i, valSign, nSign;
    for(i = 0; isspace(s[i]); i++);

    valSign = s[i] == '-' ? -1 : 1;

    if(s[i] == '+' || s[i] == '-') i++;

    for(val = 0; isdigit(s[i]); i++) 
        val = val * 10 + (s[i] - '0');
    
    if(s[i] == '.') i++;

    for(power = 1; isdigit(s[i]) ; i++) {
        val = val * 10 + (s[i] - '0');
        power *= 10;
    }

    if(toupper(s[i]) == 'E') i++;

    nSign = s[i] == '-' ? -1 : 1;

    if(s[i] == '+' || s[i] == '-') i++;


    for(; isdigit(s[i]); i++) 
        n = n * 10 + (s[i] - '0');

    nPower = 1;
    for(int k = 0; k < n; k++)
        nPower *= 10;
    return valSign * val / power * (nSign > 0 ? nPower : 1.0/nPower);
}

int main() {

    double atof(char []);

    printf("%f", atof("2.343e3"));


    return 0;
}