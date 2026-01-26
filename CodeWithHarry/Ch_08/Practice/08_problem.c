#include <stdio.h>
#include <string.h>

int main(){
    char c = 'z';
    int count = 0;
    char str[] = "Ejczbotiv";
    for (int i = 0; i < strlen(str); i++)
    {
        /* code */
        if(str[i] == c){
            count++;
        }

    }
    printf("%d", count);
    
    return 0;
}