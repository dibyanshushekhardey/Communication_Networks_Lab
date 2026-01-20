#include <stdio.h>

// function prototype
int sum(int, int);

// function definition
int sum(int x, int y){
    //printf("The sum is %d\n", x + y);
    return x + y;
}
int main(){
    int a = 1;
    int b = 2;

    int c = sum(a, b);
    printf("%d\n", c);
    
    int a1 = 12;
    int b1 = 13;
    int c1 = sum(a1, b1);
    printf("%d\n", c1);
    
    return 0;

}