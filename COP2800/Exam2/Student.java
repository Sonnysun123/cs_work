
public class Student {

    //fields
    private Date DOB;
    private Name name;
    private double GPA;
    private int credit;

    //constructor
    public Student(Date DOB, Name name, double GPA, int credit) {
        setDOB(DOB);
        setName(name);
        setGPA(GPA);
        setCredit(credit);
    } //end of constructor
    //setters

    public void setDOB(Date DOB) {
        this.DOB = DOB;
    } //end of setDOB method

    public void setName(Name name) {
        this.name = name;
    } //end of setName method

    public void setGPA(double GPA) {
        this.GPA = GPA;
    } //end of setGPA method

    public void setCredit(int credit) {
        this.credit = credit;
    } //end of setCredit method
    //getters

    public Date getDOB() {
        return this.DOB;
    } //end of getDOB method

    public Name getName() {
        return this.name;
    } //end of getName method

    public double getGPA() {
        return this.GPA;
    } //end of getGPA method

    public int getCredit() {
        return this.credit;
    } //end of getCredit method
    //behaviors

    public String checkGPA(double GPA) {
        if (GPA > 5.0 || GPA < 0) {
            return "Invalid GPA!";
        }
        return String.format("%.2f", GPA);
    } //end of checkGPA method

    public String checkCredit(int credit) {
        if (credit > 200 || credit < 0) {
            return "Invalid credits!";
        }
        return Integer.toString(credit);
    } //end of checkCredit method
    //toString

    public String toString() {
        return "[Name: " + name.toString() + ", Date: "
                + DOB.toString() + ", GPA: " + checkGPA(getGPA())
                + ", Credits: " + checkCredit(getCredit()) + "]";
    } //end of toString
} //end of Student class
