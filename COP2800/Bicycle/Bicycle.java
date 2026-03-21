
public class Bicycle {

    //fields
    private String color;
    private String brand;
    private int gearRatio;
    private int wheelHeight;

    //constructor
    public Bicycle(String color, String brand, int gearRatio, int wheelHeight) {
        setColor(color);
        setBrand(brand);
        setGearRatio(gearRatio);
        setWheelHeight(wheelHeight);
    } //end of constructor

    //toString method
    public String toString() {
        return "[color=" + getColor() + ", brand=" + getBrand() + ", gearRatio=" + getGearRatio() + ", wheelHeight=" + getWheelHeight() + "]";
    } //end of toString method

    //setters
    public void setColor(String color) {
        this.color = color;
    } //end of setColor method

    public void setBrand(String brand) {
        this.brand = brand;
    } //end of setBrand method

    public void setGearRatio(int gearRatio) {
        if (gearRatio < 1) {
            throw new IllegalArgumentException("Gear ratio cannot be less than 1");
        } //end of if statement
        this.gearRatio = gearRatio;
    } //end of setGearRatio method

    public void setWheelHeight(int wheelHeight) {
        if (wheelHeight < 0) {
            throw new IllegalArgumentException("Wheel height cannot be negative");
        } //end of if statement
        this.wheelHeight = wheelHeight;
    } //end of setWheelHeight method

    //getters
    public String getColor() {
        return this.color;
    } //end of getColor method

    public String getBrand() {
        return this.brand;
    } //end of getBrand method

    public int getGearRatio() {
        return this.gearRatio;
    } //end of getGearRatio method

    public int getWheelHeight() {
        return this.wheelHeight;
    } //end of getWheelHeight method

}//end of Bicycle class
