/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: Febuary 16, 2026
 *  Purpose: To create a jagged array with 50 rows, where each row has a random number of columns between 1 and 20. The first element of each row will indicate the number of columns in that row. The program will populate the jagged array with values based on the first element of each row, print the jagged array, and calculate and display the sum and average of all elements in the jagged array.
 ******************************************************************* */
public class JaggedArray {
    static void initJaggedArray(int[][] jaggedArray) {
        for (int i = 0; i < jaggedArray.length; i++) {
            int random = (int)(Math.random()*20 +1); //generate a random number between 1 and 20
            jaggedArray[i] = new int[random + 1]; //initialize each row with a random number of columns + 1
            jaggedArray[i][0] = random; //populate the first element of each row with the number of columns in that row
        }
    } // end of initJaggedArray method

    static void populateJaggedArray(int[][] jaggedArray) {
        for (int i = 0; i < jaggedArray.length; i++) { //iterate through each row of the jagged array
            for (int j = 0; j < jaggedArray[i].length; j++) { //iterate through each column of the current row
                jaggedArray[i][j] = jaggedArray[i][0] + j; //populate each element with the value of the first element in the row plus the column index
           }
        }
    } // end of populateJaggedArray method
    
    static void printJaggedArray(int[][] jaggedArray) {
        for (int i = 0; i < jaggedArray.length; i++) { //iterate through each row of the jagged array
            for (int j = 0; j < jaggedArray[i].length; j++) { //iterate through each column of the current row
                System.out.print(jaggedArray[i][j] + " "); //print each element followed by a space
            }
            System.out.println(); //print a new line after each row
        }
        
        int sum = sumJa`ggedArray(jaggedArray); //calculate the sum of all elements in the jagged array
        int size = sizeJaggedArray(jaggedArray); //calculate the total number of elements in the jagged array
        System.out.println("Sum: " + sum); //print the sum
        System.out.printf("Average: %.2f", (double)sum/size); //print the average rounded to 2 decimal places
    } // end of printJaggedArray method
    
    static int sumJaggedArray(int[][] jaggedArray) {
        int sum = 0; //sum of all elements in the jagged array
        for (int i = 0; i < jaggedArray.length; i++) { //iterate through each row of the jagged array
            for (int j = 0; j < jaggedArray[i].length; j++) { //iterate through each column of the current row
                sum += jaggedArray[i][j]; //add each element to sum 
            }
        }
        return sum; //return the sum
    } // end of sumJaggedArray method
    
    static int sizeJaggedArray(int[][] jaggedArray) {
        int size = 0; //total number of elements in the jagged array
        for (int i = 0; i < jaggedArray.length; i++) { //iterate through each row of the jagged array
            size += jaggedArray[i].length; //add the number of columns in each row to size
        }
        return size; //return the total number of elements
    } // end of sizeJaggedArray method
    public static void main(String[] args) {
        int[][] jaggedArray = new int[50][]; //initialize a jagged array with 50 rows
        initJaggedArray(jaggedArray);//initialize the columns of jagged array
        populateJaggedArray(jaggedArray); //populate the jagged array
        printJaggedArray(jaggedArray); //print the jagged array and sum and average
       
    } // end of main method

} // end of JaggedArray class