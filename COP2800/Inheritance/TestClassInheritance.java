/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: March 19, 2026
 *  Purpose: Inherite Dog, Cat, Bird class from Animals class. Create Dog, Cat, Bird object and call their toString method.
 ******************************************************************* */
public class TestClassInheritance {

    public static void main(String[] args) {
        //Create Dog object and call toString
        Dog dog1 = new Dog(5, 5, "Pup", "Gold retriever", "01/01/2020");
        System.out.println(dog1.toString());
        //Create Cat object and call toString
        Cat cat1 = new Cat(4, 4, "Kitty", 8);
        System.out.println(cat1.toString());
        //Create Bird object and call toString
        Bird bird1 = new Bird(4, 4, false, 5);
        System.out.println(bird1.toString());
    } //end of main method
} //end of TestClassInheritance class
