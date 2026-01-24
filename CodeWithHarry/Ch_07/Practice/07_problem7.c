#include <stdio.h>

int main(){
    int arr[3][10];
    int mul[] = {2, 7, 9};
    for (int  i = 0; i < 3; i++)
    {
        /* code */
        for (int j = 0; j < 10; j++)
        {
            /* code */
            arr[i][j] = mul[i] * (j+1);

        }
        
    }

    for (int  i = 0; i < 3; i++)
    {
        /* code */
        for (int j = 0; j < 10; j++)
        {
            /* code */
            printf("the value of arr[i][j] is %d\n", arr[i][j]);

        }
        printf("\n");
        
    }
    
    return 0;
}