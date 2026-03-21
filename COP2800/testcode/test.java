import java.util.*;
class Main{

    final static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int size = 0, eSize = 0;
        System.out.println("Enter the size of array: ");
        size = scan.nextInt();
        int[] myArray = new int[size];
        for (eSize = eSize; eSize < size; eSize++) {
            System.out.println("Enter the element: ");
            myArray[eSize] = scan.nextInt();
        }
    }
}