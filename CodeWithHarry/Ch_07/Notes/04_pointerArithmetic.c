#include <stdio.h>

int main(){
    // character pointer
    char a = 'a';
    char* ptr = &a;
    printf("the address of a is %u\n", &a);
    printf("the address of ptr is %u\n", ptr);
    ptr++;
    printf("the value of ptr is %u\n", ptr);
    return 0;

    //integer pointer
    // int a = 5;
    // int* ptr = &a;
    // printf("the address of a is %u\n", &a);
    // printf("the address of ptr is %u\n", ptr);
    // ptr++;
    // printf("the value of ptr is %u\n", ptr);
    // return 0;
}