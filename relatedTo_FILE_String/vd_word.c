#include <stdio.h>

int main()
{   // fputc - ghi ki tu len tep tin dung "w"; ghi de len tep tin txt. do
    
    //FILE* f = fopen("vd.txt", "w");
    /*
    fputc('H', f);
    fputc('o', f);
    fputc('a', f);
    fputc('n', f);
    fputc('g', f); 
    */ //ghi len tep tin vd txt
    //--------------
    // fgetc(f) doc ki tu 
    FILE* f = fopen("C:/Users/Admin/OneDrive/Desktop/cuoiki/test/vd.txt", "r");

    while (!feof(f))
    {
        char x = fgetc(f);
        if (x != -1)
        {
            printf("%c", x);
        }
        

    }
    

    

    fclose(f);
    return 0;
}