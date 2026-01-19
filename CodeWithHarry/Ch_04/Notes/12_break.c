#include <stdio.h>

int main(){
    for (int i = 0; i < 15; i++)
    {
        /* code */
        if(i == 5){
            //break; // exit the loop now!
            continue; // skip this iteration now
        }
        printf("i is %d\n", i);
    }
    printf("for loop is done\n");    
    return 0;
}