
public class Bird extends Animals {

    private boolean fly;
    private int wingspan;

    public Bird(int weight, int height, boolean fly, int wingspan) {
        super(weight, height);
        setFly(fly);
        setWingspan(wingspan);
    } //end of Bird constructor

    /*=====================Setters===================== */
    public void setFly(boolean fly) {
        this.fly = fly;
    }

    public void setWingspan(int wingspan) {
        this.wingspan = wingspan;
    }

    /*=====================Getters============================ */
    public boolean getFly() {
        return this.fly;
    }

    public int getWingspan() {
        return this.wingspan;
    }

    @Override
    public String toString() {
        return String.format("[Type: Bird, Able to fly: %b, Wingspan: %d, %s]", getFly(), getWingspan(), super.toString());
    } //end of Bird toString method

} //end of Bird Class
