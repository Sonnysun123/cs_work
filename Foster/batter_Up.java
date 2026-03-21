import java.util.*;
public class batter_Up {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        int testcase = scan.nextInt();
        scan.nextLine();
        for(int i = 0; i<testcase;i++){
            String info = scan.nextLine();
            String[]lol = info.split(":");
            String[]loll=lol[1].split(",");
            int count = 0;
            int points = 0;
            double SLG= 0;
            for(String a:loll){
                if(a.equals("BB")){

                }
                if(a.equals("K")){
                    count++;
                }
                if(a.equals("1B")){
                    points = points+1;
                    count++;
                }
                if(a.equals("2B")){
                    points = points+2;
                    count++;
                }
                if(a.equals("3B")){
                    points = points+3;
                    count++;
                }
                if(a.equals("HR")){
                    points = points+4;
                    count++;
                }
            }
           
           SLG = (double)points/count;
            String p=lol[0]+"="+String.format("%.3f",SLG);
            System.out.println(p);
        }
        scan.close();
        }
    }

