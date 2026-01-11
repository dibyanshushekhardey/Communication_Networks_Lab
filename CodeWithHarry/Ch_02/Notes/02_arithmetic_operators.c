#include <stdio.h>

int main(){
    int a = 4;
    int b = 3;
    int c = b + a;
    printf("The value of a is %d and value of b is %d and the sum is %c", a, b, c);
    // moduus operator is used to get the remainder
    printf("The remainder when a is divided by b is: %d", a%b);

    // this does not work for exponentiation in c
    // int d = a^b;
    return 0;
}