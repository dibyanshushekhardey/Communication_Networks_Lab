#include <stdio.h>
int* sum(int, int);
float* avg(int, int);
int* sum(int a, int b){
    int c = a + b;
    int* ptr = &c;
    printf("The sum is %d\n", c);
    return ptr;
}

float* avg(int a, int b){
    float c = (a+b)/2.0;
    printf("The avg is %0.2f\n", (a+b)/2.0);
    return &avg;
}

int main(){
    int x = 4;
    int y = 6;
    int* ptr1;
    float* ptr2;
    ptr1 = sum(x, y);
    ptr2 = avg(x, y);
    printf("The address of sum is %u and of average id %u\n", ptr1, ptr2);
    return 0;
}