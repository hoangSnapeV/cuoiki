#include <stdio.h>
#include <string.h>
#include <ctype.h>


//fputs = fprintf :))

int is_blank_line(const char line[])
{
    int n = strlen(line);
    if(n == 0) return 1;

    int is_blank = 1;

    for (int i = 0; i < n; i++)
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        {
            return 0;
        }
    }
    return 1;
}

void normalize(char line[])
{
    int x = line[0];

    if(!isalpha(x)) {
        return;
    }

    if(islower(x)) {
        line[0] = toupper(x);
    }
    //

}

void read_and_normalize(const char src[], const char dest[])
{
    FILE* f1 = fopen(src, "r");
    FILE* f2 = fopen(dest, "w");

    char line[1000];

    while (!feof(f1))
    {
        char* status = fgets(line, 1000, f1);

        if(status != NULL && !is_blank_line(line)) {
            normalize(line);
            fputs(line, f2);
        }
    }
    

    fclose(f1);
    fclose(f2);
}

int main()
{   
    read_and_normalize("input.txt", "normalized.txt");
    
    return 0;
}