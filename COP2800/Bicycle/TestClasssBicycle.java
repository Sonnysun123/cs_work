
/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: Febuary 23, 2026
 *  Purpose: Creates a Bicycle class with attributes color, brand, gear ratio, and wheel height. Also creates a test class to create 5 bicycles and print their details.
 ******************************************************************* */
import java.util.*;

public class TestClasssBicycle {

    final static Scanner scanner = new Scanner(System.in);

    public static void populateBicycles(Bicycle[] bicycles) {
        for (int i = 0; i < bicycles.length; i++) { //get details for each bicycle
            System.out.println("Enter details for bicycle " + (i + 1) + ":");
            System.out.print("Color: ");
            String color = scanner.nextLine();
            System.out.print("Brand: ");
            String brand = scanner.nextLine();
            System.out.print("Gear Ratio: ");
            int gearRatio = scanner.nextInt();
            scanner.nextLine(); // consume the newline
            System.out.print("Wheel Height: ");
            int wheelHeight = scanner.nextInt();
            scanner.nextLine(); // consume the newline
            bicycles[i] = new Bicycle(color, brand, gearRatio, wheelHeight);
        }//end of for loop
    }//end of populateBicycles method

    public static void printBicycles(Bicycle[] bicycles) {
        for (int i = 0; i < bicycles.length; i++) {
            System.out.println("Bicycle " + (i + 1) + ": " + bicycles[i]);
        } //end of for loop
    } //end of printBicycles method

    public static void main(String[] args) {
        //create a list of 5 bicycles
        Bicycle[] bicycles = new Bicycle[5];
        System.out.println("Create 5 bicycles:");
        populateBicycles(bicycles); //populate the list of 5 bicycles with user input
        //print all bicycles
        printBicycles(bicycles);
    } //end of main
} //end of TestClassBycycle class
