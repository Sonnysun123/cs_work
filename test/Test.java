import java.util.*;
import java.io.*;

public class Test {

    public static void main(String[] args) throws IOException {
        String name = "Fred Flintstone";
        printIt(name);
        System.out.println("BACK IN MAIN");
    } // end Main

    public static void printIt(String name) throws IOException {
        File file = new File("FartsSmell.txt");
        try {
            // This line actually creates the file on the disk
            PrintWriter out = new PrintWriter(file); 

            // First loop: Writes 9 lines of greeting
            for (int i = 0; i < 9; i++) {
                out.println((i + 1) + ". Today is Thursday. " 
                    + "Hello " + name + ".");
            }

            // Adds some blank lines
            out.println(" ");
            out.println(" ");
            out.println(" ");
            out.println(" ");

            // Nested loops: Creates a triangle pattern of asterisks (*)
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j <= i; j++) {
                    out.print("*");
                } // end inner loop
                out.println(""); // Move to the next line in the file
            } // end outer loop

            out.close(); // Important: This saves and closes the file
            
        } catch (IOException ex) {
            System.out.println("This did not work dude");
        }
    } // end method printIt

} // end TestClass