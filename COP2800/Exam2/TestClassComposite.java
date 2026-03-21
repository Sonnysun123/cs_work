
/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: March 03, 2026
 *  Purpose: Create an arrayList of Student, populates the list with user input for name, DOB, GPA, and credits, and outputs information in a nicely formatted manner
 ******************************************************************* */
import java.util.*;

public class TestClassComposite {

    final static Scanner scan = new Scanner(System.in);

    public static void populateArray(ArrayList<Student> studentList, int studentNum) {
        for (int i = 0; i < studentNum; i++) {
            System.out.println("Information for student " + (i + 1) + ".....");
            //Set new name object
            Name name = askAndSetName();
            //Set new Date object
            Date DOB = askAndSetDOB();
            //set GPA
            double GPA = askAndSetGPA();
            //set credit
            int credit = askAndSetCredit();
            //create new Student object
            Student student = new Student(DOB, name, GPA, credit);
            //Set arrayList element
            studentList.add(student);
        } //end of for loop
    } //end of populateArray method

    public static Name askAndSetName() {
        //ask user for name
        System.out.println("Enter student's first name: ");
        String firstName = scan.nextLine();
        System.out.println("Enter student's middle initial(press enter if there's none): ");
        String middleInit = scan.nextLine();
        System.out.println("Enter student's last name: ");
        String lastName = scan.nextLine();
        return new Name(firstName, middleInit, lastName);
    } //end of askAndSetName method

    public static Date askAndSetDOB() {
        System.out.println("Enter student's DOB(MM/DD/YYYY): ");
        //split string by slash
        String input = scan.nextLine();
        String[] parts = input.split("/");
        int month = Integer.parseInt(parts[0]);
        int day = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);
        return new Date(month, day, year);
    } //end of askAndSetDOB method

    public static double askAndSetGPA() {
        System.out.println("Enter student's GPA: ");
        double GPA = scan.nextDouble();
        scan.nextLine();
        return GPA;
    } //end of askAndSetGPA method

    public static int askAndSetCredit() {
        System.out.println("Enter student's credit: ");
        int credit = scan.nextInt();
        scan.nextLine();
        return credit;
    } //end of askAndSetCredit method

    public static void printArray(ArrayList<Student> studentList) {
        for (int i = 0; i < studentList.size(); i++) {
            System.out.println("Student " + (i + 1) + ": " + studentList.get(i).toString());
        } //end of for loop
    } //end of printArray method

    public static void main(String[] args) {
        System.out.print("How many Students do you want to set: ");
        int studentNum = scan.nextInt();
        scan.nextLine();
        ArrayList<Student> studentList = new ArrayList<>();
        populateArray(studentList, studentNum);
        printArray(studentList);
    } //end of main method
} //end of TestClassComposite class
