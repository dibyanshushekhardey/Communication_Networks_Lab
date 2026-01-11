#include <stdio.h>

int main(){
    int age = 7;
    if (age>5){
        printf("We are inside if\n");
        printf("Your age is greater than 5\n");
    }
    if(age % 5 == 0){
        printf("We are inside another if\n");
        printf("Your age is divisible by 50\n");
    }
    return 0;
}