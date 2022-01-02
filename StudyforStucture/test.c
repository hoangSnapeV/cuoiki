#include <stdio.h>
#include <string.h>d

int main () {
   int x = 8;
   int y = 7;
   x = x + 1;

   x = x + --y; // == 16 -> y = 6 + x 


   printf("x = %d\t y = %d", x, y);
   
   return(0);
}