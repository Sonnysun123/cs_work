/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: April, 1, 2026
 *  Purpose: This class tests the AlarmClock class by creating default,
 * valid, and invalid objects and displaying the results of changing
 * their settings. The AlarmClock class implements AlarmSound, LightSource, and Time
 * interface.
 ******************************************************************* */
public class TestClass {
    public static void main(String[] args) {
        AlarmClock defaultClock = new AlarmClock();
        AlarmClock customClock = new AlarmClock(7, 30, "Birds.mp3", 60, "blue", 80);
        AlarmClock invalidClock = new AlarmClock(25, 75, "Buzz.mp3", 120, "red", 150);

        System.out.println("Default clock:");
        System.out.println(defaultClock);

        System.out.println("Custom clock:");
        System.out.println(customClock);

        System.out.println("Invalid clock:");
        System.out.println(invalidClock);

        System.out.println("Changing custom clock settings:");
        customClock.increaseVolume();
        customClock.decreaseBrightness();
        System.out.println("new custom clock:");
        System.out.println(customClock);

        System.out.println("Fixing invalid clock:");
        invalidClock.setTime(6, 45);
        invalidClock.setVolume(50);
        invalidClock.setBrightness(70);
        System.out.println("fixed invalid clock:");
        System.out.println(invalidClock);
    } //end of main method
} //end of TestClass class
