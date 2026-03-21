
public class Dog extends Animals {

    private String name;
    private String breed;
    private String DOB;

    public Dog(int weight, int height, String name, String breed, String DOB) {
        super(weight, height);
        setName(name);
        setBreed(breed);
        setDOB(DOB);
    } //end of Dog constructor

    /*================Setters============================*/
    public void setName(String name) {
        this.name = name;
    }

    public void setBreed(String breed) {
        this.breed = breed;
    }

    public void setDOB(String DOB) {
        this.DOB = DOB;
    }

    /*===================Getters================== */
    public String getName() {
        return this.name;
    }

    public String getBreed() {
        return this.breed;
    }

    public String getDOB() {
        return this.DOB;
    }

    @Override
    public String toString() {
        return String.format("[Type: Dog, Name: %s, Breed: %s, DOB: %s, %s]", getName(), getBreed(), getDOB(), super.toString());
    } //end of Dog toString method
} //end of Dog class
