import java.util.Random;

/************************************************************
  *  Written by Hexuan Sun
  *  Date: January 18, 2026
  *  Purpose: Determine the least number of coins needed for a given amount of change randomly
  *          generated between 1 and 99 cents.
  ********************************************************************/
public class LeastExchange {
    public static void main(String[] args) {
        Random rand = new Random();

        for (int i = 0; i < 5; i++){ // Repeat 5 times
            // Generate random amount between 1 and 99 cents
            int randomCents = rand.nextInt(99) + 1; 
            // Check how many half dollars are needed
            int halfDollars = randomCents / 50;
            int halfDollarsRemainder = randomCents % 50;
            // Check how many quarters are needed
            int quarters = halfDollarsRemainder / 25;
            int quartersRemainder = randomCents % 25;
            // Check how many dimes are needed
            int dimes = quartersRemainder / 10;
            int dimesRemainder = quartersRemainder % 10;
            // Check how many nickels are needed
            int nickels = dimesRemainder / 5;
            int nickelsRemainder = dimesRemainder % 5;
            // Check how many pennies are needed
            int pennies = nickelsRemainder;
            // Output the results
            System.out.println("Total change = " + randomCents);
            //check if half dollar greater than 0 before printing
            if (halfDollars > 0) {
            // check if singular or plural
                if (halfDollars == 1) {
                    System.out.println("Half Dollar ........ " + halfDollars);
                } // end of if
                else {
                    System.out.println("Half Dollars ........ " + halfDollars);
                } // end of else
            } // end of if
            //check if quarter greater than 0 before printing
            if (quarters > 0) {
                // check if singular or plural
                if (quarters == 1) {
                    System.out.println("Quarter ........ " + quarters);
                } // end of if
                else {
                    System.out.println("Quarters ........ " + quarters);
                } // end of else
            } // end of if
            //check if dime greater than 0 before printing
            if (dimes > 0) {
                // check if singular or plural
                if (dimes == 1) {
                    System.out.println("Dime ........ " + dimes);
                } // end of if
                else {
                    System.out.println("Dimes ........ " + dimes);
                } // end of else
            } // end of if
            //check if nickel greater than 0 before printing
            if (nickels > 0) {
                // check if singular or plural
                if (nickels == 1) {
                    System.out.println("Nickel ........ " + nickels);
                } // end of if
                else {
                    System.out.println("Nickels ........ " + nickels);
                } // end of else
            } // end of if
            //check if penny greater than 0 before printing
            if (pennies > 0) {
                // check if singular or plural
                if (pennies == 1) {
                    System.out.println("Penny ........ " + pennies);
                } // end of if
                else {
                    System.out.println("Pennies ........ " + pennies);
                } // end of else
            } // end of if
            System.out.println(); // Print a blank line between iterations
        } //end of for loop
    }  //end of main method
} //end of LeastExchange class


