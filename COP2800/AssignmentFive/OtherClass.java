import java.util.InputMismatchException;
import java.util.Scanner;
public class OtherClass {

    public static int age(Scanner scan) {
        int age = 0;
        boolean goodInt = false;

        while(!goodInt) { //loop until user enters a valid integer
            try {
                System.out.println("What is your age: "); //ask user's age
                age = scan.nextInt(); //read user's age
                goodInt = true;
            }
            catch(InputMismatchException e) {
                goodInt = false;
                System.out.println("Invalid input");
                scan.next(); //clear out the buffer
            } //end of exception
        } //end of while

        return age; //return user's age
    } //end of age method
    
} //end of OtherClass
