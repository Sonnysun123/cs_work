import java.util.Scanner;

public class Main {

    public static String name(Scanner scan) {
        System.out.println("What is your full name: "); //ask user's name
        String fullName = scan.nextLine(); //read user's full name
        return fullName; //return user's full name
    } //end of name method

    public static void output(String fullName, int age) {
        if (age > 50){
            System.out.println("Hello " + fullName + " since you are " + age + " years old you are really old.");
        } //end of if   
        else if (age < 21) {
            System.out.println("Hello " + fullName + " since you are " + age + " years old you are really young.");
        } //end of else if
        else {
            System.out.println("Hello " + fullName + " since you are " + age + " years old you are doing just fine.");

        } //end of else
    } //end of output method

    public static void main(String[] args) {
        String repeat = "yes";
        while (repeat.equals("yes")) { //repeat if user enters "yes"
            Scanner scan = new Scanner(System.in); //create scanner object
            String name = name(scan); //call name method
            int age = OtherClass.age(scan); //call age method from OtherClass
            output(name, age); //call output method
            System.out.println("Enter \"yes\" if you want to repeat: "); //ask user if they want to repeat
            scan.nextLine(); //consume newline character
            repeat = scan.nextLine(); //read user's response
        } //end of while
    } //end of main method
} //end of Main class
