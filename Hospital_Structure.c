#include <stdio.h>
#include <string.h>

struct HospitalHospital_Structure
{
    char patientName[30];
    char disease[30];
    int age;
    float bill;
};

int main()
{
    struct Hospital h1;

    strcpy(h1.patientName, "Anita");
    strcpy(h1.disease, "Fever");
    h1.age = 22;
    h1.bill = 3500.75;

    printf("Patient Name : %s\n", h1.patientName);
    printf("Disease      : %s\n", h1.disease);
    printf("Age          : %d\n", h1.age);
    printf("Bill Amount  : %.2f\n", h1.bill);

    return 0;
}