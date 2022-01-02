#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct 
{
    int studentID;
    char firstName[100];
    char lastName[100];
    char gender[100];
    char dateOfBirth[100];
    char classname[100];//
    char country[100];

} dssv;

typedef struct {
    int student_ID;
    int subjectID;
    float score;

} diem;

typedef struct {
    int student_ID_avg;
    float diem_tb;
} list_avg;

typedef struct {
    char lenh[100];
    char chu[100];
} call;

int demSodong(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    int count = 0;
    char line[1000];
    while (!feof(file))
    {   
        
        fgets(line, 1000, file);
        count++;
    }

    fclose(file);
    return count;
}

dssv* read_file(const char file_path[], int n)
{
    FILE* file = fopen(file_path, "r");

    dssv* student_list = calloc(n - 1, sizeof(dssv));

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
                //
            }
            if (index == 5)
            {
                strcpy(student_list[i].classname, token);   
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

///
date* bring_date(dssv* list_student, int n)
{
    date* date_sts = calloc(n - 1, sizeof(date));

    for(int i = 0; i <= n -2; i++)
    {   
        char * token = strtok(list_student[i].dateOfBirth, "/");
        int j = 0;
        while( token != NULL ) {
            //printf( " %s ", token );
            if (j == 0)
            {
                date_sts[i].day = atoi(token);
            }
            if (j == 1)
            {
                date_sts[i].month = atoi(token);
            }
            if (j == 2)
            {
                date_sts[i].year = atoi(token);
            }
            token = strtok(NULL, "/");
            j++;
        }
        
        //printf("%s\n", list_student[i].dateOfBirth);
    }
    return date_sts;
}
////

//y1
void print_sts_list(dssv* my_sts, int n, char x[], const char path[])
{   
    FILE* file = fopen(path, "w");
    int index = 0;
    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        if(strcmp(my_sts[i].classname, x) == 0)
        {   
            fprintf(file,"%d -  %d %s %s %s %s %s %s\n", index,my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
            index++;
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

//y4 sort asc là tang dân
void sort_tang(dssv* my_sts, int n, const char path[], date* listdate)
{
    FILE* file = fopen(path, "w");
    dssv temp;
    date temp_date;
    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n - 2; j++)
        {
            int cmp = strcmp(my_sts[i].firstName, my_sts[j].firstName);
            //printf("%d %d", listdate[i].year,  listdate[j].year);
            if(cmp == 0)
            {   
                if(listdate[i].year  < listdate[j].year)
                {   
                    //doi ben dan sach
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                    // doi ben dia chi
                    temp_date = listdate[i];
                    listdate[i] = listdate[j];
                    listdate[j] = temp_date;
                    
                } else if (listdate[i].year  == listdate[j].year)
                    {   
                        if(listdate[i].month  > listdate[j].month)
                        {
                            temp = my_sts[i];
                            my_sts[i] = my_sts[j];
                            my_sts[j] = temp; 

                            temp_date = listdate[i];
                            listdate[i] = listdate[j];
                            listdate[j] = temp_date;
                        } else if(listdate[i].month  == listdate[j].month)
                            {
                                if(listdate[i].day  > listdate[j].day)
                                {
                                    temp = my_sts[i];
                                    my_sts[i] = my_sts[j];
                                    my_sts[j] = temp; 

                                    temp_date = listdate[i];
                                    listdate[i] = listdate[j];
                                    listdate[j] = temp_date;
                                }
                            }
                            
                    }
            } else if (cmp > 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;

                    temp_date = listdate[i];
                    listdate[i] = listdate[j];
                    listdate[j] = temp_date;
                }
            
        }

    }

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        fprintf(file,"%d -  %d %s %s %s %s %s %s\n", i, my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        

    }

    fclose(file);
}
//giam sort desc
void sort_giam(dssv* my_sts, int n, const char path[], date* listdate)
{
    FILE* file = fopen(path, "w");
    dssv temp;
    date temp_date;
    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n - 2; j++)
        {
            int cmp = strcmp(my_sts[i].firstName, my_sts[j].firstName);
            //printf("%d %d", listdate[i].year,  listdate[j].year);
            if(cmp == 0)
            {   
                if(listdate[i].year  > listdate[j].year)
                {   
                    //doi ben dan sach
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;
                    // doi ben dia chi
                    temp_date = listdate[i];
                    listdate[i] = listdate[j];
                    listdate[j] = temp_date;
                    
                } else if (listdate[i].year  == listdate[j].year)
                    {   
                        if(listdate[i].month  < listdate[j].month)
                        {
                            temp = my_sts[i];
                            my_sts[i] = my_sts[j];
                            my_sts[j] = temp; 

                            temp_date = listdate[i];
                            listdate[i] = listdate[j];
                            listdate[j] = temp_date;
                        } else if(listdate[i].month  == listdate[j].month)
                            {
                                if(listdate[i].day  < listdate[j].day)
                                {
                                    temp = my_sts[i];
                                    my_sts[i] = my_sts[j];
                                    my_sts[j] = temp; 

                                    temp_date = listdate[i];
                                    listdate[i] = listdate[j];
                                    listdate[j] = temp_date;
                                }
                            }
                    }
            } else if (cmp < 0)
                {
                    temp = my_sts[i];
                    my_sts[i] = my_sts[j];
                    my_sts[j] = temp;

                    temp_date = listdate[i];
                    listdate[i] = listdate[j];
                    listdate[j] = temp_date;
                }
            
        }

    }

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        fprintf(file,"%d -  %d %s %s %s %s %s %s\n", i, my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        

    }

    fclose(file);
}


//y5 
void print_country(dssv* my_sts, int n, char x[], const char path[])
{   
    FILE* file = fopen(path, "w");

    for (int i = 0; i <= n - 2; i++)
    {   
        //print_student(my_sts[i], x);

        if(strcmp(my_sts[i].country, x) == 0)
        {
            fprintf(file,"%d %s %s %s %s %s %s\n",my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        }

    }

    fclose(file);
    
}
/// y3


diem* read_file_diem(const char file_path[], int n)
{
    FILE* file = fopen(file_path, "r");
    diem * diemlist = calloc((n - 1) * 6, sizeof(diem));

    char line[200];
    fgets(line, 200, file);

    for (int i = 0; i <= (n - 1) * 6 - 1; i++)
    {
        fgets(line, 200, file);

        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }
        if(line[strlen(line) - 1] == 10 || line[strlen(line) - 1] == 13) {
            line[strlen(line) - 1] = '\0';
        }
        //
        char* token = strtok(line, ",");
        int index = 0;

        while(token != NULL) {
            
            if(index == 0)
            {
                diemlist[i].student_ID = atoi(token);
            } else if(index == 1)
                {
                    diemlist[i].subjectID = atoi(token);
                }
            if (index == 2)
            {
                diemlist[i].score = atof(token);
            }
            token = strtok(NULL, ",");
            index++;
        }


    }
    fclose(file);
    return diemlist;
}

list_avg* grade_average(diem* list_diem_sts, int n)
{
    list_avg* list_tb = calloc(n - 1, sizeof(list_avg));
    int index = 0;
    float avg = 0;
    int mssv = list_diem_sts[0].student_ID;

    for (int i = 0; i <= (n - 1) * 6 - 1; i++)
    {
        
        if(mssv == list_diem_sts[i].student_ID)
        {   
            if(list_diem_sts[i].subjectID == 1)
            {
                avg = avg + list_diem_sts[i].score;
            } else if(list_diem_sts[i].subjectID == 2)
                {
                    avg = avg + list_diem_sts[i].score;
                }

            if(list_diem_sts[i].subjectID == 3)
            {
                avg = avg + list_diem_sts[i].score;
            } else if(list_diem_sts[i].subjectID == 4)
                {
                    avg = avg + list_diem_sts[i].score;
                } 
            
            if(list_diem_sts[i].subjectID == 5)
            {
                avg = avg + list_diem_sts[i].score;
            } else if(list_diem_sts[i].subjectID == 6)
                {
                    avg = avg + list_diem_sts[i].score;

                    list_tb[index].student_ID_avg = mssv;
                    list_tb[index].diem_tb = avg;
                    index++;
                    mssv = list_diem_sts[i + 1].student_ID;
                    //printf("%.2f\n", avg);
                    avg = 0;
                } 
        }
    }

    return list_tb;

}

void print_top(list_avg* list_grade_avg, int n, const char path[], dssv* list_student, int x)
{
    FILE* file = fopen(path, "w");
    dssv temp;
    list_avg temp_top;

    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n - 2; j++)
        {
            if(list_grade_avg[i].diem_tb < list_grade_avg[j].diem_tb)
            {   
                //doi avg
                temp_top = list_grade_avg[i];
                list_grade_avg[i] = list_grade_avg[j]; 
                list_grade_avg[j] = temp_top;
                //doi liststudent
                temp = list_student[i];
                list_student[i] = list_student[j];
                list_student[j] = temp;
            }

        }
    }
    if(x > (n - 1))
    {
        x = n - 2;
    }
    for (int i = 0; i <= x - 1; i++)
    {   
        fprintf(file,"%d - %d %s %s %s %s %s %s\n",i,list_student[i].studentID, list_student[i].firstName, list_student[i].lastName, list_student[i].gender, list_student[i].dateOfBirth, list_student[i].classname, list_student[i].country);
    }
    fclose(file);
}

void create_error(const char path[])
{
    FILE* file = fopen(path, "w");
    fprintf(file, "%s", "invalid command");

    fclose(file);
}


int main()
{   
    
    int n = demSodong("dssv.csv");
    printf("%d", n); // N = 202
    
    dssv* list_student = read_file("dssv.csv", n);
    dssv* copy_list = read_file("dssv.csv", n);

    date* list_date = bring_date(copy_list, n); 

    diem* list_diem_sts = read_file_diem("diem.csv", n);

    list_avg* list_grade_avg = grade_average(list_diem_sts, n); 
    
    ///
    /*
    char caulenh[100];
    printf("nhap lenh: ");
    fgets(caulenh, 100, stdin);
    caulenh[strlen(caulenh) - 1] = '\0';

    call nhap_lenh;
    char* token = strtok(caulenh, " ");
    int index = 0;
    while (token != NULL)
    {
        if (index == 0)
        {
            strcpy(nhap_lenh.lenh, token);
        } else if (index == 1)
            {
                strcpy(nhap_lenh.chu, token);
            }

        token = strtok(NULL, " ");
        index++;
    }
    
    create_error("error.txt");
    ////
    
    printf("%s %s", nhap_lenh.lenh, nhap_lenh.chu );
    //printf("%lu", strlen(caulenh));
    */


    //////----------

    //print_sts_list(list_student, n, "5203002", "result.csv");

    //count_male(list_student, n,  "result.csv");

    //count_Female(list_student, n,  "result.csv");

    //sort_tang(list_student, n,  "result.csv", list_date);
    //sort_giam(list_student, n,  "result.csv", list_date);

    //print_country(list_student, n, "Chile", "result.csv");

    //y3
    

    //print_top(list_grade_avg, n, "result.csv", list_student, 200);

    return 0;
}