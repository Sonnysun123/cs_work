package RecursiveMethod;
public class RecursiveMethod{
    public static void printMessage(int count){
        System.out.println(count + ". Java Programming really fun.");
        if(count < 10){
            count++;
            printMessage(count);
        }
    } //end of printMessage method
    public static void main(String[] args){
        int count = 1;
        printMessage(count);
    }//end of main method
}//end of class



