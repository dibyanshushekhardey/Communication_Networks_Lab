#include <stdio.h>
#include <string.h>

int main(){
    char c = 'd';
    int contains = 0;
    char str[] = "Ejczbotiv";
    for (int i = 0; i < strlen(str); i++)
    {
        /* code */
        if(str[i] == c){
            contains = 1;
            break;
        }

    }
    if(contains){
        printf("Yes it contains");
    }
    else{
        printf("It does not contain\n");
    }
    
    return 0;
}