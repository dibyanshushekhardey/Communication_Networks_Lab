#include <stdio.h>

typedef struct c
{
    /* data */
    int real;
    int imaginary;
}Complex;

int main(){
    Complex c = {1, 2};
    printf("The value of Complex Number is %d + %di\n", c.real, c.imaginary);
    return 0;
}