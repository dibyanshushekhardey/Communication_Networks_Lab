#include <stdio.h>
typedef struct employee{
    int salary;
    float score;
}Employee;
int main(){
    Employee e1;
    Employee* ptr1 = &e1;

    ptr1 -> salary = 56;
    ptr1 -> score = 45.3;
    printf("the value of salary is %d and the value of score is %f \n", ptr1 -> salary, ptr1 -> score);

    return 0;
}