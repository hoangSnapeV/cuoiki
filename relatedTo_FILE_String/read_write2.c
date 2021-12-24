#include <stdio.h>
#include <string.h>

int main()
{
    FILE* f = fopen("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/input.txt", "r");

    if(f == NULL) 
    {
        printf("khong mo duoc file de doc");
        return 0;
    }

    char word[100];
    //đoc hét
    /*
    while (feof(f) != 1)
    {
        fscanf(f, "%s", word);
        printf("%s\n", word);
    }*/

    /// đọc theo dòng
    int count = 0;
    char line[1000];
    while (!feof(f))
    {   
        count++;
        fgets(line, 1000, f);
        printf("%d - %s", count, line);
    }
    // fgets - doc theo 1 dong lun di kem 1 dau enter
    // fscanf - đọc theo từng từ 
    // fprintf -  in trong tep tin . 

    fclose(f);


    return 0;
}