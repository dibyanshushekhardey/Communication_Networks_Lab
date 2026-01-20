#include <stdio.h>

int sumNat(int);

int sumNat(int n){
    if (n == 1){
        return 1;
    }
    else{
        return sumNat(n-1) + n;
    }
    
}
int main(){
    printf("The sum of first 5 natural numbers is %d\n", sumNat(5));
    return 0;
}