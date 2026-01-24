#include <stdio.h>

int main(){
    int marks[] = {12, 34, 56, 78};

    int* ptr = &marks[0];
    //int* ptr = &marks; // same as the previous one

    for (int i = 0; i < 4; i++){
        //printf("The marks ar index %d is %d\n", i, marks[i]);

    }

    for (int i = 0; i < 4; i++)
    {
        /* code */
        //printf("The marks ar index %d is %d\n", i, marks[i]);
        printf("The marks ar index %d is %d\n", i, *ptr);
        ptr++;

    }
    
    return 0;
}