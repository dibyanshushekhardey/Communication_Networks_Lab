#include <stdio.h>
int main(){
    int i = 5;
    printf("The value of i is %d\n", i);
    i = i + 5;
    printf("The value of i is %d\n", i);
    printf("The value of i is %d\n", i++);
    printf("The value of i is %d\n", i);
    // i++ first prints and then increments i(Post increment operator)
    // ++i increments first and then prints i(Pre increment operator)
    
    i += 2; // same as i = i + 2
    printf("The value of i is %d\n", i);

    return 0;
}