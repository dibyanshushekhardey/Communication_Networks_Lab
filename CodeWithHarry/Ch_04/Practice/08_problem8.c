#include <stdio.h>

int main(){
    // 8! = 1x2x3x4x5x6x7x8
    int product = 1;
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        product *= i;
    }
    printf("The factorial of %d is  %d\n", n, product);

    return 0;
}