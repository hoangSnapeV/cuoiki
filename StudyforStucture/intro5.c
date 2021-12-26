#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    int id;
    char name[100];
    bool gender;
    int salary;
    float rating;

}Employee;

void print_employee(Employee e)
{
    
    printf("%d %s %s %d %.1f \n", e.id, e.name, e.gender ? "Male": "Female", e.salary, e.rating); // co the dung if
}

void read_file(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    int n;
    fscanf(file, "%d", &n);
    fgetc(file); // sau fscanf vaf truoc fgets

    //printf("%d", n);

    //getchar(); doc tu ban phim chu khong tu file

    char line[200];

    for (int i = 0; i <= n; i++)
    {
        fgets(line, 200, file);

        // if(line[strlen(line) - 1] == '\n'){
        //     line[strlen(line) - 1] == '\0';
        // }

        printf("%s", line);
    }
    
    

    fclose(file);
}

int main()
{
    read_file("input.txt");

    return 0; 
}