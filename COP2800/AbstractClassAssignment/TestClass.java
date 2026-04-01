/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: March 30, 2026
 *  Purpose: Write an abstract Instrument class and two concrete classes that extend it. Then, create a TestClass to test the functionality of the Instrument class and its subclasses.
 ******************************************************************* */
import java.util.ArrayList;

public class TestClass {
    
    public static void loadList(ArrayList<Instrument> instrumentList) {
        Piano piano = new Piano();
        Violin violin = new Violin();
        instrumentList.add(piano);
        instrumentList.add(violin);
    } //end of loadList class

    public static void printList(ArrayList<Instrument> instrumentList) {
        for (int i = 0; i < instrumentList.size(); i++) {
            System.out.println(instrumentList.get(i).toString());
        }
    } //end of printList class

    public static void main(String[] args) {
        ArrayList<Instrument> instrumentList = new ArrayList<>();
        loadList(instrumentList);
        printList(instrumentList);
    } //end of main method
} //end of TestClass class