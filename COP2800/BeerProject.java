/*******************************************************************
  *  Written by Hexuan Sun
  *  Date: January 18, 2026
  *  Purpose: To calculate annual beer consumption, calories, and weight gain
  *           based on user input for daily beer consumption and price.
  ********************************************************************/
package COP2800;
import java.util.Scanner;
public class BeerProject {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        double beerConsump, beerPrice, beerPerYear, caloriesPerYear, weightGainPerYear, moneySpentPerYear;
        System.out.print("On average, how many beers will you consume each day? ");
        beerConsump = scan.nextDouble();
        System.out.print("On average, how much will you pay for each cam of beer? ");
        beerPrice = scan.nextDouble();
        beerPerYear = beerConsump * 365;
        caloriesPerYear = beerConsump * 150 * 365;
        weightGainPerYear = beerConsump * 15;
        moneySpentPerYear = beerConsump * beerPrice * 365;
        System.out.printf("\nThat is approximately %.2f beers in one year.", beerPerYear);
        System.out.printf("\nIn one year, you will consume approximately %.2f calories from beer alone", caloriesPerYear);
        System.out.printf("\nWithout diet or exercise to consume these calories, you can expect to gain %.2f pounds from drinking that much beer this year", weightGainPerYear);
        System.out.printf("\nYou will spend approximately $%.2f on beer in one year.", moneySpentPerYear);
        scan.close();
    } //end of main method
} // end of BeerProject class

