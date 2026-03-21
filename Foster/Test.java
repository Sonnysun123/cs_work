import java.util.Scanner;
public class Test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int number, highest, lowest, sum, count =0;
        number = highest = lowest = sum = count = 0;
        number = scan.nextInt();
        while (number != -999){
            if(number > highest){
                highest = number;
            }
            if (number < lowest){
                lowest = number;
            }
            sum += number;
            count++;
            number = scan.nextInt();
        }
        if(count > 0){
            double average = (double)sum / count;
            System.out.println("Highest Value: " + highest);
            System.out.println("Lowest Value: " + lowest);
            System.out.println("Average of Values: " + average);
        }
        scan.close(); 
    }
}