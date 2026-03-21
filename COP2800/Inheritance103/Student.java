public class Student extends Person{
    private int gradeLevel;
    private double GPA;
    private String schoolName;
    public Student() { 
        super();
        setGradeLevel(10);
        setGPA(3);
        setSchoolName("Default School");
    } //end of default Student constructor
    public Student(String name, int height, int weight, int age, int gradeLevel, double GPA, String schoolName) { //overloaded method
        super(name, height, weight, age);
        setGradeLevel(gradeLevel);
        setGPA(GPA);
        setSchoolName(schoolName);
    } //end of parameterized Student constructor
    /*========================Setters=========================== */
    public void setGradeLevel(int gradeLevel) {this.gradeLevel = gradeLevel;}
    public void setGPA(double GPA) {this.GPA = GPA;}
    public void setSchoolName(String schoolName) {this.schoolName = schoolName;}
    /*===========================Getters========================== */
    public int getGradeLevel() {return this.gradeLevel;}
    public double getGPA() {return this.GPA;}
    public String getSchoolName() {return this.schoolName;}

    @Override
    public boolean equals(Object o) { //overrided method
        if (!(o instanceof Student))
            return false;
        if (!super.equals(o))
            return false;
        Student other = (Student) o;
        return this.gradeLevel == other.gradeLevel &&
               this.GPA == other.GPA &&
               this.schoolName.equals(other.schoolName);
    } //end of Student equals method
    @Override
    public String toString() { //overrided method
        return String.format("[Person type: Student, %s, Grade Level: %d, GPA: %.2f, School name: %s]", super.toString(), getGradeLevel(), getGPA(), getSchoolName());
    } //end of Student toString method
} //end of Student class