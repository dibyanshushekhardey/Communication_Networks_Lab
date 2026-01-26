#include <stdio.h>
#include <string.h>

int main(){

    char str[] = "Dibyanshu";
    for (int i = 0; i < strlen(str); i++)
    {
        /* code */
        str[i] = str[i] + 1;

    }
    printf("%s", str);
    
    return 0;
}