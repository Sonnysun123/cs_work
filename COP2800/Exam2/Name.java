
public class Name {

    //fields
    private String firstName;
    private String middleInitial;
    private String lastName;

    //constructor
    public Name(String firstName, String middleInitial, String lastName) {
        setFirstName(firstName);
        setMiddleInitial(middleInitial);
        setLastName(lastName);
    } //end of Constructor
    //setters

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    } //end of setFirstName method

    public void setMiddleInitial(String middleInitial) {
        this.middleInitial = middleInitial;
    } //end of setMiddleInitial method

    public void setLastName(String lastName) {
        this.lastName = lastName;
    } //end of setLastName method
    //getters

    public String getFirstName() {
        //Capitalize first letter
        String firstLetter = this.firstName.substring(0, 1).toUpperCase();
        //decapitalize the rest
        String remainingLetters = this.firstName.substring(1).toLowerCase();
        //resulting String
        String firstNameCap = firstLetter + remainingLetters;
        return firstNameCap;
    } //end of getFirstName method

    public String getMiddleInitial() {
        //capitalize middle initial
        String middleCap = this.middleInitial.toUpperCase();
        return middleCap;
    } //end of getMiddleInitial method

    public String getLastName() {
        //Capitalize first letter
        String firstLetter = this.lastName.substring(0, 1).toUpperCase();
        //Decapitalize the rest
        String remainingLetters = this.lastName.substring(1).toLowerCase();
        //resulting String
        String lastNameCap = firstLetter + remainingLetters;
        return lastNameCap;
    } //end of getLastName method

    //toString
    public String toString() {
        //If there is no middle initial
        if (getMiddleInitial().equals("")) {
            return getFirstName() + " " + getLastName();
        } //If there is middle initial
        else {
            return getFirstName() + " " + getMiddleInitial() + ". " + getLastName();
        }
    } // end of toString method
} //End of Name class
