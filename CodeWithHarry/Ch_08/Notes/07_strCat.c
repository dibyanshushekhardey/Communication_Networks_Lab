#include <stdio.h>
#include <string.h>
int main(){
    char st[] = "Dibyanshu";
    char s1[56] = "Shekhar";
    char s2[56] = "Dey";
    char target[30];
    strcpy(target, st);
    printf("%s %s", st, target);

    strcat(s1, s2);
    printf("%s", s1);
    return 0;
}