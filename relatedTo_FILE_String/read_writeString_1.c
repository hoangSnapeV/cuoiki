#include <stdio.h>
#include <string.h>

int main()
{
    FILE* f = fopen("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/output_read.txt", "w");

    if(f == NULL) 
    {
        printf("khong mo duoc file");
        return 0;
    }

    char name[] = "Hoang Dinh Quy Vu\n";

    fprintf(f, "%s", "welcome to c programming\n");
    fprintf(f, "%s", name);

    char input[100];
    printf("Please enter something: ");
    fgets(input, 100, stdin); //standard input

    int n = strlen(input); // hello\n , n = 5
    

    fprintf(f, "%s", input);


    

    fclose(f);
    return 0;
}