/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: March 19, 2026
 *  Purpose: Inherite Student class from Person class. Create Person and Student objects and test their toString method and equals method.
 ******************************************************************* */
public class TestClass {
    public static void main(String[] args) {
        //Create 3 Person class object, test the toString and equals method
        Person p1 = new Person("Jack", 55, 180, 34);;
        Person p2 = new Person();
        Person p3 = p1;
        System.out.println(p1.toString());
        System.out.println(p2.toString());
        System.out.println(p3.toString());
        System.out.println("Person 1 equals Person 2: " + p1.equals(p2));
        System.out.println("Person 1 equals Person 3: " + p1.equals(p3));

        //Create 3 Student class object, test the toString and equals method
        Student s1 = new Student("Kay Wright", 50, 130, 12, 7, 2.5, "West Middleschool");
        Student s2 = new Student();
        Student s3 = s1;
        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.println(s3.toString());
        System.out.println("student 1 equals student 2: " + s1.equals(s2));
        System.out.println("student 1 equals student 3: " + s1.equals(s3));
    } //end of main method
} //end of TestClass class