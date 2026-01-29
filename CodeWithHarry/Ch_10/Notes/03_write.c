#include <stdio.h>

int main(){
    FILE* fptr;
    // write mode will empty a file(ie erase an existing data)
    fptr = fopen("dibyanshu_1.txt", "a");
    int num = 432;
    
    fprintf(fptr, "%d", num);

    
    fclose(fptr);
    return 0;
}