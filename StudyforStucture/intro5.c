#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char name[100];
    bool gender;
    int salary;
    float rating;

} Employee;

void print_employee(Employee e)
{
    
    printf("%d %s %s %d %.1f \n", e.id, e.name, e.gender ? "Male": "Female", e.salary, e.rating); // co the dung if
}

void read_file(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    int n;
    fscanf(file, "%d", &n);    
    //printf("%d", n);
    // fgetc(file); // hoac có thể thây 2 dòng 28, 29 -> fgets(line, 200, file);
    // fgetc(file);
    
    Employee * employee_list = calloc(n, sizeof(Employee));

    char line[200];
    fgets(line, 200, file);

    for (int i = 1; i <= n; i++)
    {
        fgets(line, 200, file);

        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }
        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }   
        printf("%s\n", line);

        
        
    } //end for

    fclose(file);
}

int main()
{
    read_file("input_1.txt");
    //atoi vs atof 
    

    return 0;
}