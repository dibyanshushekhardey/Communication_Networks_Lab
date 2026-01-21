#include <stdio.h>

int main(){
    int i = 72;
    int *j = &i; // j is a pointer pointing to i (j is an interhe pointer)
    int k = 67;
    printf("The address of i is %p\n", &i);
    printf("The address of i is %p\n", j);
    printf("The address of k is %p\n", &k);
    printf("The value at address j is %d\n", *(&i));
    return 0;
}