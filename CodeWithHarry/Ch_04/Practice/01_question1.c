#include <stdio.h>

int main(){
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i <= 10; i++)
    {
        /* code */
        printf("%d X %d = %d\n", n, i, n*i);
    }
    
    return 0;
}