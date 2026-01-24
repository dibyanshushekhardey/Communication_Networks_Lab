#include <stdio.h>

int count(int a[], int n){
    int noOfPos = 0;
    for(int i = 0; i < n; i++){
        if (a[i] > 0){
            noOfPos++;
        }
    }
    return noOfPos;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, -6, 7, -8, 9, 10};
    printf("The number of positive integers is %d", count(a, 10));
    return 0;
}