#include <stdio.h>
#include <string.h>

typedef struct employee
{
    /* data */
    int code;
    float salary;
    char name[10];
}Emp;

void show (struct employee e){
    printf("Code is %d\nSalary is %f\nName is %s", e.code, e.salary, e.name);
}

int main(){
    //typedef struct employee Emp;
    Emp e1;
    Emp* ptr1 = &e1;
    e1.code = 89;
    strcpy(e1.name, "dibyanshu");
    e1.salary = 67000;
    show(e1);
    printf("%d %f %s\n", ptr1 -> code, ptr1 -> salary, ptr1 -> name);
    return 0;
}