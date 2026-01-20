#include <stdio.h>

int main(){
    // int sum = 0;
    // int i = 1;
    // do 
    // {
    //     /* code */
    //     sum += i;
    //     i++;
    // }while(i <= 10);
    int sum = 0;
    for (int i = 0; i <= 10; i++)
    {
        /* code */
        sum += i;
    }
    
    printf("The sum of first 10 natural numbers is %d\n", sum);


    return 0;
}