#include <stdio.h>

int main()
{
   char str[50];

   printf("Nhap mot chuoi: ");
   gets(str);

   printf("Ban vua nhap chuoi: %s", str);

   return(0);
}