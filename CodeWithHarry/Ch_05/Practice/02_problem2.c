#include <stdio.h>

float c2f(float);

float c2f(float c){
    return ((9*c)/5) + 32.0;
}
int main(){
    float c = 45;

    printf("Celsius to fahrenheit  for %0.2f is %.2f\n", c, c2f(c));
    return 0;
}