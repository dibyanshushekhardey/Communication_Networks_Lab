#include <stdio.h>

int main(){
    char ch = 'a';
    printf("The character is %c\n", ch);
    printf("The character is %d\n", ch);
    if (ch >= 97 && ch <= 122){
        printf("this character is lower case\n");
    }
    else{
        printf("this character is upper case\n");
    }
    return 0;
}