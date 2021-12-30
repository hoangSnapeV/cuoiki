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
    int classname;
    char country[100];

} dssv;



int demSodong(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    int count = 0;
    char line[1000];
    while (!feof(file))
    {   
        count++;
        fgets(line, 1000, file);

    }

    fclose(file);
    return count;
}

dssv* read_file(const char file_path[], int n)
{
    FILE* file = fopen(file_path, "r");

    dssv* student_list = calloc(n, sizeof(dssv));

    char line[200];
    fgets(line, 200, file);
    //

    for (int i = 0; i <= n - 2; i++)
    {
        fgets(line, 200, file);

        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }
        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        } 

        //printf("%d - %s\n", i, line);

        char* token = strtok(line, ",");
        int index = 0;

        while(token != NULL) {
            
            if(index == 0)
            {
                student_list[i].studentID = atoi(token);
            } else if(index == 1)
                {
                    strcpy(student_list[i].firstName, token);
                }
            if (index == 2)
            {
                strcpy(student_list[i].lastName, token);
            }
            if (index == 3)
            {
                strcpy(student_list[i].gender, token);
            }
            if (index == 4)
            {
                strcpy(student_list[i].dateOfBirth, token);   
            
            }
            if (index == 5)
            {
                student_list[i].classname = atoi(token);
            }
            if (index == 6)
            {
                strcpy(student_list[i].country, token);
            }
        
            token = strtok(NULL, ",");
            index++;
        }

    } 
    fclose(file);

    return student_list;
}

//y1
void print_sts_list(dssv* my_sts, int n, int x, const char path[])
{   
    FILE* file = fopen(path, "w");

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        if(my_sts[i].classname == x)
        {
            fprintf(file,"%d %s %s %s %s %d %s\n",my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        }

    }

    fclose(file);
    
}

//y2
void count_male(dssv* my_sts, int n, const char path[])
{
    FILE* file = fopen(path, "w");
    int count = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        if(strcmp(my_sts[i].gender, "Male") == 0)
        {
            count++;
        }
    }
    fprintf(file, "%d\n", count);

    fclose(file);
}

void count_Female(dssv* my_sts, int n, const char path[])
{
    FILE* file = fopen(path, "w");
    int count = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        if(strcmp(my_sts[i].gender, "Female") == 0)
        {
            count++;
        }
    }
    fprintf(file, "%d\n", count);

    fclose(file);
}

//y4
void sort_tang(dssv* my_sts, int n, const char path[])
{
    FILE* file = fopen(path, "w");
    dssv temp;

    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n -2; j++)
        {
            int cmp = strcmp(my_sts[i].firstName, my_sts[j].firstName);
            if(cmp == 0)
            {
                if(strcmp(my_sts[i].dateOfBirth, my_sts[j].dateOfBirth) > 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                }
            } else if (cmp > 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                }
            
        }

    }

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        fprintf(file,"%d %s %s %s %s %d %s\n",my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        

    }

    fclose(file);
}

void sort_giam(dssv* my_sts, int n, const char path[])
{
    FILE* file = fopen(path, "w");
    dssv temp;

    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n -2; j++)
        {
            int cmp = strcmp(my_sts[i].firstName, my_sts[j].firstName);
            if(cmp == 0)
            {
                if(strcmp(my_sts[i].dateOfBirth, my_sts[j].dateOfBirth) < 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                }
            } else if (cmp < 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                }
            
        }

    }

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        fprintf(file,"%d %s %s %s %s %d %s\n",my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        

    }

    fclose(file);
}

int main()
{   
    int x;
    int n = demSodong("dssv.csv");
    dssv* list_student = read_file("dssv.csv", n);

    printf("%d", n);
    print_sts_list(list_student, n, 5203001, "result.csv");
    
    //count_male(list_student, n,  "result.csv");

    //count_Female(list_student, n,  "result.csv");

    //sort_tang(list_student, n,  "result.csv");
    //sort_giam(list_student, n,  "result.csv");
    return 0;
}