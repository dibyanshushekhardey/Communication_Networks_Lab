#include <stdio.h>

int sum(int, int);
int sum(int a, int b){
    a = 5;
    return a + b;
}

int main(){
    int i = 1, j = 6;
    printf("The sum of 1 and 6 is %d\n", sum(i, j));    
    return 0;
}