#include <stdio.h>

const int ITEM_NUM = 100;
const double TAX = 0.05;

void PopulatesNewArray(double* itemsBefore, double* ItemsAfter) {
    for (int i = 0; i < ITEM_NUM; i++) { //loop 100 times
        ItemsAfter[i] = itemsBefore[i] * (1 + TAX); //sets value for the new array
    }
} //end of PopulatesNewArray function

void PopulatesOldArray(double* itemsBefore) { //populates itemsBefore array
    for (int i = 0; i < ITEM_NUM; i++) { //loop 100 times
        printf("Price for item %d: ", i + 1);
        double price; scanf("%lf", &price); //takes user input for item price
        itemsBefore[i] = price; //sets price in the ith index
    }
    
} //end of PopulatesOldArray function

void PrintNewArray(double* itemsAfter) {
    for (int i = 0; i < ITEM_NUM; i++) { //loop 100 times
        printf("Price for item %d after tax is: %0.2lf\n", i+1, itemsAfter[i]);//prints item value after tax rounded 2 decimal places
    } 
} //end of PrintNewArray function

void PrintTotalPrice(double* itemsBefore, double* itemsAfter) {
    double totalBefore = 0.0;
    double totalAfter = 0.0;
    for (int i = 0; i < ITEM_NUM; i++) { //loop 100 times
        totalBefore += itemsBefore[i];
        totalAfter += itemsAfter[i];
    } //end of for loop
    printf("Total price before tax: %0.2lf", totalBefore); //prints total price before tax rounded to 2 decimal places
    printf("\nTotal price after tax: %0.2f", totalAfter); //prints total price after tax rounded to 2 decimal places
} //end of PrintTotalPrice function

int main() {
    double itemsBefore[ITEM_NUM]; //initializes array that stores price for 100 items before tax 
    double itemsAfter[ITEM_NUM]; //initializes array that stores price for 100 items after tax
    PopulatesOldArray(itemsBefore); //populates array that stores prices before tax
    PopulatesNewArray(itemsBefore, itemsAfter); //populates array that stores prices after tax
    PrintNewArray(itemsAfter); //prints all values for the array that stores prices after tax
    PrintTotalPrice(itemsBefore, itemsAfter); //print total price before tax and after tax
} //end of main function