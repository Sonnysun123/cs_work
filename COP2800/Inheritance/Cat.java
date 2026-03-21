
public class Cat extends Animals {

    private String name;
    private int lives;

    public Cat(int weight, int height, String name, int lives) {
        super(weight, height);
        setName(name);
        setLives(lives);
    } //end of Cat constructor

    /*====================Setters=========================== */
    public void setName(String name) {
        this.name = name;
    }

    public void setLives(int lives) {
        this.lives = lives;
    }

    /*=====================Getters=========================== */
    public String getName() {
        return this.name;
    }

    public int getLives() {
        return this.lives;
    }

    @Override
    public String toString() {
        return String.format("[Type: Cat, Name: %s, Lives: %s, %s]", getName(), getLives(), super.toString());
    } //end of Cat toString method
} //end of Cat class
