#include <stdio.h>

float average(int a, int b, int c);

float average(int a, int b, int c){
    return (a+b+c)/3.0;
}
int main(){
    int a = 3, b = 4, c = 5;
    printf("The average of a , b, c is %f\n", average(a, b, c));    
    return 0;
}