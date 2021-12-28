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

Employee * read_file(const char file_path[], int* size)
{
    FILE* file = fopen(file_path, "r");

    int n;
    fscanf(file, "%d", &n);    
    //printf("%d", n);
    // fgetc(file); // hoac có thể thây 2 dòng 28, 29 -> fgets(line, 200, file);
    // fgetc(file);
    *size = n;

    Employee * employee_list = calloc(n, sizeof(Employee));

    char line[200];
    fgets(line, 200, file);

    for (int i = 0; i < n; i++)
    {
        fgets(line, 200, file);

        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }
        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        } 
            
        //printf("%s\n", line);

        
        char* token = strtok(line, ",");
        int index = 0;
        bool gender;

        while(token != NULL) {
            //printf("%s: %d\n", token, index);

            if (index == 0)
            {
                employee_list[i].id = atoi(token);
            }
            else if(index == 1)
            {
                //employee_list[i].name = token;
                strcpy(employee_list[i].name, token);
            }
            if(index == 2)
            {
                if (strcmp(token, "true") == 0)
                {
                    employee_list[i].gender = true;
                } else
                    {
                        employee_list[i].gender = false;
                    }
                
            }
            if(index == 3)
            {
                employee_list[i].salary = atoi(token);
            }
            else if(index == 4)
            {
                employee_list[i].rating = atof(token);
            }
            
            token = strtok(NULL, ",");
            index++;
        }
    } //end for

    fclose(file);
    return employee_list;
}

void print_employee_list(Employee* my_emp, int n)
{
    for (int i = 0; i < n; i++)
    {
        print_employee(my_emp[i]);
    }
    
}

int main()
{   
    int n;
    Employee* my_list = read_file("input_1.txt", &n);
    //atoi vs atof 
    print_employee_list(my_list, n);

    return 0;
}