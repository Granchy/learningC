#include <stdio.h>

int power(int, int); //parameter names are optional if function prototypes
double fahrenheitToCelsius(double);



int main() {
    printf("%d %d %d\n", power(2,2), power(3,3) , power(2,5));
    printf("%f %f %f", fahrenheitToCelsius(70), fahrenheitToCelsius(72), fahrenheitToCelsius(81));
    return 0;
}

int power(int m, int n) {
    int p =1;

    for(int i =0; i < n; i++) p *= m;
    return p;
}

double fahrenheitToCelsius(double f) { // parameters in C can be thought of as declared local variables
    double c = (5.0)/9*(f-32); // with the value that is being passed as argument
    f = f-100; // but this does not affect on the argument itself, the value is only being changed in the function call, not locally
    return c + f;
}





