#include <stdio.h>
#include <string.h>
struct employee
{
    /* data */
    int code;
    float salary;
    char name[10];
};

int main(){
    struct employee e1, e2;
    strcpy(e1.name, "Dibyanshu");
    e1.salary = 400.44;
    printf("%D %f %s", e1.code, e1.salary, e1.name);
    return 0;
}