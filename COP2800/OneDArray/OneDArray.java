/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: Febuary 10, 2026
 *  Purpose: To create a one-dimensional array of random integers,
 *  sort the array, and display the minimum, maximum, average values, and frequency.
 ******************************************************************* */
package OneDArray;

import java.util.*;

public class OneDArray {

    final static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int arraySize = 0;
        System.out.println("Enter the size of array: ");
        arraySize = scan.nextInt();
        int[] myArray = new int[arraySize];
        loadArray(myArray, arraySize);
        Arrays.sort(myArray);
        displaySortedArray(myArray, arraySize);
        displayCriticalValues(myArray, arraySize);
        displayFrequency(myArray, arraySize);
    }// end of main method

    static void loadArray(int[] myArray, int arraySize) {
        for (int i = 0; i < arraySize; i++) {
            int randomNum = (int) (Math.random() * 101);
            myArray[i] = randomNum;
        } // end of for loop
    } // end of loadArray method

    static void displaySortedArray(int[] myArray, int arraySize) {
        for (int i = 0; i < arraySize; i++) {
            System.out.println("Array at index " + i + ": " + myArray[i]);
        } // end of for loop
        System.out.println();
    } // end of displayArray method

    static void displayCriticalValues(int[] myArray, int arraySize) {
        int sum = 0;
        for (int i = 0; i < arraySize; i++) {
            sum += myArray[i];
        } // end of for loop
        double average = (double) sum / arraySize;
        System.out.println("Minimum value: " + myArray[0]);
        System.out.println("Maximum value: " + myArray[arraySize - 1]);
        System.out.println("Average value: " + average);
        System.out.println();

    } // end of displayCriticalValues method

    static void displayFrequency(int[] myArray, int arraySize) {
        int uniqueSize = 1;
        for (int i = 1; i < arraySize; i++) {// determine the size of unique array
            if (myArray[i] != myArray[i - 1]) {
                uniqueSize++;
            } // end of if
        } // end of for loop
        int[] uniqueArray = new int[uniqueSize];
        int[] frequencyArray = new int[uniqueSize];
        int uniqueIndex = 1;
        uniqueArray[0] = myArray[0];
        frequencyArray[0] = 1;
        for (int i = 1; i < arraySize; i++) {//load the unique array and frequency array
            if (myArray[i] != myArray[i - 1]) {
                uniqueArray[uniqueIndex] = myArray[i];
                frequencyArray[uniqueIndex] = 1;
                uniqueIndex++;
            } else {
                frequencyArray[uniqueIndex - 1]++;
            } // end of if
        } // end of for loop

        System.out.printf("%-10s %-10s\n", "Value", "Frequency");
        System.out.println("------------------------------");
        for (int i = 0; i < uniqueArray.length; i++) {// display the unique values and their frequencies
            System.out.printf("%-10d %-10d\n", uniqueArray[i], frequencyArray[i]);
        } // end of for loop
    } // end of displayFrequency method

}// end of OneDArray class
