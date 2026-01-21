#include <stdio.h>

int main(){
    int i = 2;
    int* ptr = &i;
    printf("the addresws of i is %u", &i);
    printf("The value of i is %d\n", *ptr);
    return 0;
}