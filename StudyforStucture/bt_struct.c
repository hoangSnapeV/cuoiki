#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int studentID;
    char firstName[100];
    char lastName[100];
    char gender[100];
    char dateOfBirth[100];
    char classname[100];
    char country[100];

} dssv;

void print_employee(dssv e)
{
    
    printf("%d %s %s %s %s %s %s", e.studentID, e.firstName, e.lastName, e.gender, e.dateOfBirth, e.classname, e.country);
}

dssv create_employee(int n) 
{   

    dssv student;
    for (int i = 1; i <= n; i++)
    {
        printf("enter id:");
        scanf("%d", &student.studentID);
        getchar();
        
        printf("enter first name: ");
        fgets(student.firstName, 100, stdin);
        student.firstName[strlen(student.firstName) - 1] = '\0';

        printf("enter last name: ");
        fgets(student.lastName, 100, stdin);
        student.lastName[strlen(student.lastName) - 1] = '\0';

        printf("enter gender (0 for femal, others for male): ");
        int gender;
        scanf("%d", &gender); 

        getchar();
        if(gender == 1)
        {
            strcpy(student.gender, "Male");
        } else strcpy(student.gender, "Female");

        printf("enter date of birth: ");
        fgets(student.dateOfBirth, 100, stdin);
        student.dateOfBirth[strlen(student.dateOfBirth) - 1] = '\0';

        printf("enter classname: ");
        fgets(student.classname, 100, stdin);
        student.classname[strlen(student.classname) - 1] = '\0';

        printf("enter country: ");
        fgets(student.country, 100, stdin);
        student.country[strlen(student.country) - 1] = '\0';

        print_employee(student);
        printf("\n\n");
    }
    
    
    //return student;

}

int main()
{
    int n;
    printf("nhap so luong student , n =");
    scanf("%d", &n);

    create_employee(n);

    return 0;
}