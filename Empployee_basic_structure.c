#include<stdio.h>
struct Employee{
    char name[50];
    int id;
    float salary;
};

int main(){
    struct Employee e1;
    //Assign values

    e1.id=112;
    e1.salary=75000.50;

    printf("Employee ID: %d\n", e1.id);
    printf("Salary     :%.2f\n", e1.salary);

    return 0;
}