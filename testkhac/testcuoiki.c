#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    char classname[100];
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

int demSoDong(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    if(file == NULL) return 0;

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

int count_dssm(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    if(file == NULL) return 0;

    int count = 0;
    char line[1000];
    fgets(line, 1000, file);
    while (!feof(file))
    {   
        
        fgets(line, 1000, file);
        count++;
    }
    fclose(file);
    return count;
}

//
dssv* read_file(const char file_path[], int n)
{
    FILE* file = fopen(file_path, "r");
    if(file == NULL) return 0;

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

void create_error(const char path[])
{
    FILE* file = fopen(path, "w");
    fprintf(file, "%s", "invalid command");

    fclose(file);
}

void create_emptyFile(const char path[])
{
    FILE* file = fopen(path, "w");
    
    fprintf(file, "%s", ' ');

    fclose(file);
}


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
            fprintf(file,"%d %s %s %s %s %s %s\n", my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
            index++;
        } 

    }

    if (index == 0)
    {
        create_emptyFile("result.csv");            
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
void sort_asc(dssv* my_sts, int n, const char path[], date* listdate)
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

        fprintf(file,"%d %s %s %s %s %s %s\n", my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);

    }

    fclose(file);
}

void sort_desc(dssv* my_sts, int n, const char path[], date* listdate)
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

        fprintf(file,"%d %s %s %s %s %s %s\n", my_sts[i].studentID, my_sts[i].firstName, my_sts[i].lastName, my_sts[i].gender, my_sts[i].dateOfBirth, my_sts[i].classname, my_sts[i].country);
        

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
diem* read_file_diem(const char file_path[], int n, int a)
{
    FILE* file = fopen(file_path, "r");

    if(file == NULL) return 0;

    diem * diemlist = calloc((n - 1) * a, sizeof(diem));

    char line[200];
    fgets(line, 200, file);

    for (int i = 0; i <= (n - 1) * a - 1; i++)
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
        x = n - 1;
    }
    for (int i = 0; i <= x - 1; i++)
    {   
        fprintf(file,"%d %s %s %s %s %s %s\n", list_student[i].studentID, list_student[i].firstName, list_student[i].lastName, list_student[i].gender, list_student[i].dateOfBirth, list_student[i].classname, list_student[i].country);
    }
    fclose(file);
}

//--
int check_chuoi(char name[])
{   
    int n = strlen(name);
    int count_space = 0;
    for (int i = 0; i < n; i++)
    {
        char x = name[i];
        if(x == ' ')
        {
            count_space++;
            if (count_space == 2)
            {
                return 0;
            }     
        } else if(x != ' ')
            {
                int check = isalnum(x);
                if(check == 0)
                {
                    return 0;
                }
            }
    }
    if (count_space == 0)
    {
        return 0;
    }
    
    
    return 1;
}

void chuanHoa_lenh(char name[])
{
    int n = strlen(name);
    for (int i = 0; i < n; i++)
    {
        name[i] = tolower(name[i]);
    }
}

int chuanHoa_Chu_1(char thamso[])
{
    int n = strlen(thamso);
    
    thamso[0] = toupper(thamso[0]);
    for (int i = 1; i < n; i++)
    {
        thamso[i] = tolower(thamso[i]);
    }
    

}

void chuanHoa_Chu_sort(char thamso[])
{
    int n = strlen(thamso);

    
    for (int i = 0; i < n; i++)
    {
        thamso[i] = tolower(thamso[i]);
    }

}

int chuanHoa_So(char thamso[])
{
    int n = strlen(thamso);
    for (int i = 0; i < n; i++)
    {
        int check = isdigit(thamso[i]);
        if (check == 0)
        {
            return 0;
        }
        
    }
    int a = atoi(thamso);

    return a;
}
//
int check_thamso_chu(char thamso[])
{
    int n = strlen(thamso);
    
    for (int i = 0; i < n; i++)
    {
        int check = isalpha(thamso[i]);
        if(check == 0) return 0;  
        
    }
    return 1;
}

void print_txt( const char file_log[], int n, int s, const char file_lenh[], char x[])
{
    
    FILE* file_1 = fopen(file_log, "w");
    FILE* file_2 = fopen(file_lenh, "w");

    fprintf(file_1, "%d %d %d", n - 1, s, (n - 1) * s);
    fprintf(file_2, "%s", x);

    fclose(file_1);
    fclose(file_2);
}

int check_read_file(const char file_path[])
{
    FILE* file = fopen(file_path, "r");

    if(file == NULL) return 0;

    fclose(file);
    return 1;
}

int main()
{   
    
    int n = demSoDong("dssv.csv");
    int s = count_dssm("dsmh.csv");
    int d = check_read_file("diem.csv");

    dssv* list_student;
    dssv* copy_list;
    date* list_date;
    diem* list_diem_sts;
    list_avg* list_grade_avg;
    
    printf("%d %d %d\n", n, s, d);

    if(n != 0)
    {
        list_student = read_file("dssv.csv", n);
        copy_list = read_file("dssv.csv", n);
        list_date = bring_date(copy_list, n);
    }
    

    if(d != 0)
    {
        list_diem_sts = read_file_diem("diem.csv", n, s);

        list_grade_avg = grade_average(list_diem_sts, n);
    }
    
    ///
   
    char caulenh[100];
    fgets(caulenh, 100, stdin);
    caulenh[strlen(caulenh) - 1] = '\0';
    
    print_txt("log.txt", n, s, "cau lenh.txt", caulenh);

    
    int result = check_chuoi(caulenh);
    call nhap_lenh;

    if (result)
    {       
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

        chuanHoa_lenh(nhap_lenh.lenh);

        int a1 = strcmp(nhap_lenh.lenh, "list") == 0;
        int a2 = strcmp(nhap_lenh.lenh, "count") == 0;
        int a3 = strcmp(nhap_lenh.lenh, "country") == 0;
        int a4 = strcmp(nhap_lenh.lenh, "top") == 0;
        int a5 = strcmp(nhap_lenh.lenh, "sort") == 0;

        if (a1 || a2 || a3 || a4 || a5)
        {            
            //print_sts_class
            if(strcmp(nhap_lenh.lenh, "list") == 0)
            {
                print_sts_list(list_student, n, nhap_lenh.chu, "result.csv");
            }

            int result_1 = check_thamso_chu(nhap_lenh.chu);
            //count
            if(strcmp(nhap_lenh.lenh, "count") == 0)
            {
                if(result_1)
                {
                    chuanHoa_Chu_1(nhap_lenh.chu); 
                    
                    if (strcmp(nhap_lenh.chu, "Male") == 0)
                    {
                        count_male(list_student, n,  "result.csv"); 
                    } else if(strcmp(nhap_lenh.chu, "Female") == 0)
                        {
                            count_Female(list_student, n,  "result.csv");
                        } else
                            {
                                create_error("error.txt");
                            }   
                    
                }
            }
            //country
            if(strcmp(nhap_lenh.lenh, "country") == 0)
            {
                if(result_1)
                {
                    chuanHoa_Chu_1(nhap_lenh.chu);

                    print_country(list_student, n, nhap_lenh.chu, "result.csv");
                }
            }
            // top n
            if (strcmp(nhap_lenh.lenh, "top") == 0)
            {
                int result2 = chuanHoa_So(nhap_lenh.chu);
                
                if (result2 > 0)
                {
                    print_top(list_grade_avg, n, "result.csv", list_student, result2);
                } else
                    {
                        create_error("error.txt");
                    }
            }

            //sort
            if (strcmp(nhap_lenh.lenh, "sort") == 0)
            {   
                chuanHoa_Chu_sort(nhap_lenh.chu);
                if (strcmp(nhap_lenh.chu, "asc") == 0)
                {
                    sort_asc(list_student, n,  "result.csv", list_date);
                } else if (strcmp(nhap_lenh.chu, "desc") == 0)
                    {
                        sort_desc(list_student, n,  "result.csv", list_date);
                    } else
                        {
                            create_error("error.txt");
                        }
            }
        } else
            {
                create_error("error.txt");
            } 


    } else 
        {
            create_error("error.txt");
        }

    return 0;
}