//C program to implement a structure to store and display details of students 
//such as name , roll number, age and cgpa

#include<stdio.h>
struct Student{
    int rollno;
    char grade;
    int cgpa;
    char name[50];//name as chararecter array
};
//to access the mem ber we use dot operator
int main(){
     struct Student s1;
    printf("Enter the student name:");
    scanf("%s", s1.name);
    printf("Enter the student roll number:");
    scanf("%d", &s1.rollno);
    printf("Enter the student grade:");
    scanf(" %c", &s1.grade);
    printf("Enter the student cgpa:");
    scanf("%d", &s1.cgpa);

    printf("---$$ Student Details: $$---\n");
    printf("Name: %s\n", s1.name);
    printf("Roll Number: %d\n", s1.rollno);
    printf("Grade: %c\n", s1.grade);
    printf("CGPA: %d\n", s1.cgpa);
    return 0;
}