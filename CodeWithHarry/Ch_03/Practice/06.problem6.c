#include <stdio.h>

int main(){
    int a = 4, b = 6,  c = 7, d = 32;
    if (a > b && a > c && a > d)
    {
        /* code */
        printf("The greatest number is a\n");
    }
    else if (b > a && b > c && b > d)
    {
        /* code */
        printf("The greatest number is b\n");
    }
    else if (c > a && c > b && c > d)
    {
        /* code */
        printf("The greatest number is c\n");
    }
    else if (d > a && d > c && d > b)
    {
        /* code */
        printf("The greatest number is c\n");
    }
    
    return 0;
}