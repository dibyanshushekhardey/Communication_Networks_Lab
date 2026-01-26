#include <stdio.h>
#include <string.h>
int main(){
    char st1[45] = "deep";
    char target[30] = "joke";
    int a = strcmp(st1, target);
    printf("%d", a);
    return 0;
}