public class Person {
    private String name;
    private int heightInches;
    private int weightPounds;
    private int age;
    public Person() {
        setName("John Smith");
        setHeightInches(60);
        setWeightPounds(180);
        setAge(30);
    } //end of default constructor
    public Person(String name, int heightInches, int weightPounds, int age) { //overloaded method
        setName(name);
        setHeightInches(heightInches);
        setWeightPounds(weightPounds);
        setAge(age);
    } //end of parameterized constructor

    /*===================Setters======================== */
    public void setName(String name) {this.name = name;}
    public void setHeightInches(int heightInches) {this.heightInches = heightInches;}
    public void setWeightPounds(int weight) {this.weightPounds = weight;}
    public void setAge(int age) {this.age = age;}
    /*======================Getters======================= */
    public String getName() {return this.name;}
    public int getHeightInches() {return this.heightInches;}
    public int getWeightPounds() {return this.weightPounds;}
    public int getAge() {return this.age;}

    @Override
    public boolean equals(Object o) { //overrided method
        if (!(o instanceof Person)) 
            return false;
        Person other = (Person) o;
        return (this.name.equals(other.name) &&
               this.heightInches == other.heightInches &&
               this.weightPounds == other.weightPounds &&
               this.age == other.age);
    } //end of Person equals method

    @Override
    public String toString() { //overrided method
        return String.format("Name: %s, age: %d, Height in inches: %d, Weight in pounds: %d", getName(), getAge(), getHeightInches(), getWeightPounds());
    } //end of Person toString method

} //end of Person class