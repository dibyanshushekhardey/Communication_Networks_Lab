#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* code */
    srand(time(NULL));
    int N = rand()%(10+1);
    
    printf("Total Packets generated is %d\n", N);
    return 0;
}