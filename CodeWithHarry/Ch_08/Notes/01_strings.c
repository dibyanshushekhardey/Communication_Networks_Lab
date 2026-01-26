#include <stdio.h>

int main(){
    // char st[]= {'a', 'b', 'c', '\0'};
    char st[] = "abc";
    for(int i = 0; i < 3; i++){
        printf("Character is %c \n", st[i]);
    }
    printf("First character is %c \n", st[0]);
    return 0;
}