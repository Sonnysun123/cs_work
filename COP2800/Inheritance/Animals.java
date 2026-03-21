
public class Animals {

    private int weight;
    private int height;

    public Animals(int weight, int height) {
        setWeight(weight);
        setHeight(height);
    }//end of Animals constructor

    /*====================Setters======================== */
    public void setWeight(int weight) {
        this.weight = weight;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    /*=======================Getters=========================== */
    public int getWeight() {
        return this.weight;
    }

    public int getHeight() {
        return this.height;
    }

    @Override
    public String toString() {
        return String.format("Weight: %d, Height: %d", getWeight(), getHeight());
    } //end of Animals toString method
} //end of Animals class
