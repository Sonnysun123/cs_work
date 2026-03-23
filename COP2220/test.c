
#include <stdio.h>
#include <string.h>

void FindNumber(int number, int lowVal, int highVal) {
   int midVal;

   midVal = (highVal + lowVal) / 2;
   printf("%d %d", number, midVal);

   if (number == midVal) {    // Base case
      printf(" a\n");
   }
   else {
      if (number < midVal) {  // First recursive case
         printf(" b\n");
         FindNumber(number, lowVal, midVal);
      }
      else {                  // Second recursive case
         printf(" c\n");
         FindNumber(number, midVal + 1, highVal);
      }
   }
}

int main(void) {
   int number;

   scanf("%d", &number);
   FindNumber(number, 0, 10);
   
   return 0;
}