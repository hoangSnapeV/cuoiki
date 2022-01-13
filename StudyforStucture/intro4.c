#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    char name[64];
    int age;

    float rating;
    char email[32];

}Employee;

// void print_employee(Employee e)
// {
    
//     printf("%d %s %s %d %.1f \n", e.id, e.name, e.gender ? "Male": "Female", e.salary, e.rating); // co the dung if
// }

// Employee create_employee() 
// {
//     Employee e;

//     printf("enter id:");
//     scanf("%d", &e.id);
//     getchar();


//     printf("enter name: ");
//     fgets(e.name, 100, stdin);
//     e.name[strlen(e.name) - 1] = '\0';

//     printf("enter gender (0 for femal, others for male): ");
//     int gender;
//     scanf("%d", &gender);

//     if(gender == 1)
//     {
//         e.gender = true;
//     } else e.gender = false;

//     printf("enter salary: ");
//     scanf("%d", &e.salary);

//     printf("enter rating: ");
//     scanf("%f", &e.rating);

//     return e;

// }

//intro 3 _ kieu con tro cua struct 

// void updat_employee(Employee* e)
// {
//     e->id = e->id * 2;
//     e->rating = e->rating * 2;

//     print_employee(*e); 
// }
// //---------
int main()
{
    //Employee e = create_employee();
    // printf("%d\n", sizeof(Employee));
    // //print_employee(e);
    // printf("%d", 'A');
    int a[] = {1,2,3};
    int b[] = a;
    return 0;
}