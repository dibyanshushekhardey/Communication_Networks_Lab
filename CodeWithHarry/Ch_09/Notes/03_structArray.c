#include <stdio.h>


struct employee
{
    /* data */
    int code;
    float salary;
    char name[10];
};

int main(){
    struct employee facebook[100];
    facebook[0].code = 100;
    facebook[1].code = 77;
    struct employee dibyanshu = {56, 67000.00, "Dibyanshu"};
    printf("%d %f %s\n", dibyanshu.code, dibyanshu.salary, dibyanshu.name);
    
    return 0;
}