
#include <stdio.h>

enum option {
   STOP = 'Q',
   CONTINUE = 'C',
   NEW = 'N',
   EDIT = 'E',

};


int main(void) {
   printf("%c", STOP);
}