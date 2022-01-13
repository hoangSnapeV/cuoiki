#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Employee
{
    int id;
    char name[100];
    bool gender;
    int salary;
    float rating;

};

void print_employee(struct Employee e)
{
    
    printf("%d %s %s %d %.1f \n", e.id, e.name, e.gender ? "Male": "Female", e.salary, e.rating); // co the dung if
}

struct Employee create_employee() 
{
    struct Employee e;

    printf("enter id:");
    scanf("%d", &e.id);
    getchar();
    
    printf("enter name: ");
    fgets(e.name, 100, stdin);
    e.name[strlen(e.name) - 1] = '\0';

    printf("enter gender (0 for femal, others for male): ");
    int gender;
    scanf("%d", &gender);

    if(gender == 1)
    {
        e.gender = true;
    } else e.gender = false;

    printf("enter salary: ");
    scanf("%d", &e.salary);

    printf("enter rating: ");
    scanf("%f", &e.rating);

    return e;

}

//intro 3 _ kieu con tro cua struct 

void updat_employee(struct Employee* e)
{
    e->id = e->id * 2;
    e->rating = e->rating * 2;

    print_employee(*e); 
}
//---------
int main()
{
    // struct Employee a ={12, "Hoang Vu", true, 999, 7.5}; // int x =3;
    // struct Employee b = a;

    //b.id = 13;
    //b.name = "Van Manh"; cach ghi sai
    // strcpy(b.name, "Hai Yen");
    // b.gender = false;
    // b.salary = 1200;
    // b.rating = 6.6;
    
    // //printf("id of a: %d\n", a.id);
    // print_employee(a);
    // updat_employee(&a);
    // print_employee(a);
    // char a[] = "He";
    // char b[] = {'h', 'e', '\0'};
    // printf("%d %d", strlen(a), strlen(b));
    return 0;
}