#include <stdio.h>

int fibonacchi(int);

int fibonacchi(int n){
    if (n == 1 || n == 2){
        return n-1;
    }
    else{
        return fibonacchi(n-1) + fibonacchi(n-2);
    }
    
}
int main(){
    int n = 10;
    printf("The value of fibonacchi series at %d is %d\n", n, fibonacchi(n));
    return 0;
}