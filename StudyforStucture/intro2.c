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

    printf("enter id: ");
    scanf("%d", &e.id);
    getchar(); // loi trc khi nhap chuoi 
    // su dung khi sau scanf vaf trc fgets

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


int main()
{
    struct Employee e = create_employee();
    print_employee(e);

    return 0;
}