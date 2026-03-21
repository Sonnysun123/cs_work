/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: Febuary 23, 2026
 *  Purpose: Creates an arrayList, populates, sorts, displays the list based on user input
 ******************************************************************* */
import java.util.*;

public class LinkedList {

    final static Scanner scan = new Scanner(System.in); //initializes global scanner object

    public static void displayMenu() {
        System.out.println("MENU SYSTEM");
        System.out.println("[A]dd a name to the list");
        System.out.println("[D]isplay all names in the list in ascending order");
        System.out.println("[S]tatistics");
        System.out.println("[Q]uit");
    } //end of displayMenu method

    public static void addArray(ArrayList<String> array) { //adds word into array
        System.out.println("Enter the name you want to add into this array: ");
        String name = scan.next(); //stores user input
        array.add(name); //adds input into the array
    } //end of addArray method

    public static void displayArray(ArrayList<String> array) { //sort and print array
        System.out.println("Displaying Sorted Array....");
        array.sort(null); //sorts array
        for (int i = 0; i < array.size(); i++) { //prints array
            System.out.println(array.get(i));
        }
    } //end of displayArray method

    public static void displayStatistics(ArrayList<String> array) { //display statistics
        int numName = 0;
        int numVowels = 0;
        for (int i = 0; i < array.size(); i++) { //iterate over all names in the array
            numName++; //increase number of names by 1
            for (int j = 0; j < array.get(i).length(); j++) { //iterate over all letters in the array
                if (array.get(i).toLowerCase().charAt(j) == 'a' || array.get(i).toLowerCase().charAt(j) == 'e' || array.get(i).toLowerCase().charAt(j) == 'i' || array.get(i).toLowerCase().charAt(j) == 'o' || array.get(i).toLowerCase().charAt(j) == 'u') { //checks vowels
                    numVowels++; //increase number vowels by 1
                } // end of if statement
            } //end of inner for loop
        } //end of outer for loop

        String longestName = array.get(0);
        int longestNameSize = longestName.length();

        for (int i = 0; i < array.size() - 1; i++) { //iterate over all names in the array
            if (array.get(i + 1).length() >= longestNameSize) { //if the length of the next name is greater than current name length
                longestName = array.get(i + 1); //updates longest name
                longestNameSize = longestName.length(); //updates longest name length
            } //end of if statement
        } //end of for loop

        System.out.println("Total Names Entered: " + numName); //prints number of names
        System.out.println("Total Vowels Entered: " + numVowels); //prints number of vowels
        System.out.println("Name With The Most Letters: " + longestName + "(" + longestNameSize + " letters)"); //prints longest name and its size
    } //end of displayStatistics method

    public static void main(String[] args) {
        String input = "";
        ArrayList<String> array = new ArrayList<>(); //initiatlize list with type string
        while (!input.equals("Q")) { //while user didn't enter Q
            displayMenu(); //display menu
            input = scan.next(); //ask user's input
            switch (input) {
                //if user enters A
                case "A":
                    addArray(array); //adds array
                    break;
                //if user enters D
                case "D":
                    displayArray(array);
                    break;
                //if user enters S
                case "S":
                    displayStatistics(array); //display statistics
                    break;
                //if user enters Q
                case "Q":
                    break;
                //if user enters anything else
                default:
                    System.out.println("Please Try Again");
                    break;
            }
        }
    } //end of main method
} //end of LinkedList class
