public class forLoopPatterns {
    public static void main(String[] args) {
        System.out.println("For Loop #1");
        for (int i = 0;i < 11;i++) {
            System.out.println(i);
        }
        System.out.println("For Loop #2");
        for (int i =12;i<=30;i+=3){
            System.out.println(i);
        }
        System.out.println("For Loop #3");
        for (int i =1; i<=128;i*=2){
            System.out.println(i);
        }
        System.out.println("For Loop #4");
        for (int i =20;i>=0;i-=4){
            System.out.println(i);
        }
    }
}
