#include <stdio.h>
#include <string.h>
int main()
{
    char str[80] = "hoangvu, 16/08/2003, xuyen moc";
    char* token = strtok(str, ",");
    int index = 0;

    while( token != NULL ) {
        printf("%d - %s\n", index, token );
        if(index == 1)
        {   
            int i = 0;
            char* token_1 = strtok(token, "/");
            while( token_1 != NULL ) {
                printf("\t%d - %s\n", i, token_1 );
                i++;
                token_1 = strtok(NULL, "/");
            }
        }
        index++;
        token = strtok(NULL, ",");
   }
   
   return(0);
}