#include <stdio.h>
struct vector
{
    /* data */
    int i;
    int j;
};

int main(){
    struct vector v = {1,2};
    printf("The value of %di + %dj", v.i, v.j);
    return 0;
}