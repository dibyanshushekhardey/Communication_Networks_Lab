#include <stdio.h>
#include <string.h>

struct employee
{
    /* data */
    int code;
    float salary;
    char name[10];
};

void show(struct employee e);

void show (struct employee e){
    printf("Code is %d\nSalary is %f\nName is %s", e.code, e.salary, e.name);
}
int main(){
    struct employee e1;
    e1.code = 4511;
    strcpy(e1.name, "dibyanshu");
    e1.salary = 67000;
    show(e1);
    return 0;
}