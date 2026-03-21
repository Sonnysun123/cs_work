// "New" means new compared to previous level
#include <stdio.h>
#include <stdlib.h>

typedef struct Home_struct {
   int numRooms;
   int numOccupants;
} Home;

void Home_SetData(Home* itemPtr, int rooms, int occupants) {
   if (itemPtr == NULL) return;
   
   itemPtr->numRooms = rooms;
   itemPtr->numOccupants = occupants;
}

// New: Home_AddOccupants()
void Home_AddOccupants(Home* itemPtr, int occupants) {
   if (itemPtr == NULL) return;

   itemPtr->numOccupants += occupants;
}

void Home_PrintHome(Home* itemPtr) {
   if (itemPtr == NULL) return;
   
   printf("%d rooms, %d occupants\n", itemPtr->numRooms, itemPtr->numOccupants); 
}

int main(void) {
   Home* myHome = NULL;

   myHome = (Home*)malloc(sizeof(Home));

   Home_SetData(myHome, 5, 2);
   Home_PrintHome(myHome);

   Home_AddOccupants(myHome, 4);
   Home_PrintHome(myHome);

   free(myHome);

   return 0;
}