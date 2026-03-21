public class Person {
    private Name name;
    private double height;
    private double weight;
    private boolean validPerson;

    public Person() {
        makePerson();
    } //end of no argument constructor

    public Person(Name name, double height, double weight) {
        setValidPerson(true);
        setName(name);
        setHeight(height);
        setWeight(weight);
    } //end of parameterized constructor

    /*==================Setters========================== */
    public void setName(Name name) {
        if (name.getValidName() == false) {
            this.name = null; //invalid name
            setValidPerson(false);
        }
        else
            this.name = name;
    }
    public void setHeight(double height) {
        if (height > 144 || height < 12) {
            this.height = -1; //invalid height
            setValidPerson(false);
        }
        else
            this.height = height;
        }
    public void setWeight(double weight) {
        if (weight > 1000 || weight < 25) {
            this.weight = -1; //invlaid weight
            setValidPerson(false);
        }
        else
            this.weight = weight;
    }
    public void setValidPerson(boolean validObject) {this.validPerson = validObject;}
    /*==========================Getters======================== */
    public Name getName() {return this.name;}
    public double getHeight() {return this.height;}
    public double getWeight() {return this.weight;}
    public boolean getValidPerson() {return this.validPerson;}
    /*==================Other methods==================== */
    public void makePerson() {
        setValidPerson(true);
        setName(new Name());
        setHeight(60);
        setWeight(180);
    } //end of makePerson method
    @Override
    public String toString() {
        return String.format("Name: %s, Height: %.2f, Weight: %.2f", getName().toString(), getHeight(), getWeight());
    } //end of toString

} //end of Person class