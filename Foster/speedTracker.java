import java.util.Scanner;
public class speedTracker {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("What's the interval between measurements?");
        int interval = scan.nextInt();
        double sum =0;
        for (int i=0;i<=60;i+=interval){
            System.out.println("Give you speed at minute "+i+": ");
            double speed = scan.nextInt();
            sum = speed+sum;
        }
        double average = (sum/(60/interval));
        System.out.println("Your average speed is "+average+" mph");
        scan.close();
    }
}
