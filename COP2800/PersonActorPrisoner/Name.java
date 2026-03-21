public class Name {
    private String firstName;
    private String middleInitial;
    private String lastName;
    private boolean validName;

    public Name() {
        setFirstName("John");
        setMiddleInitial("A");
        setLastName("Smith");
        setValidName(true);
    } //end of no argument constructor

    public Name(String firstName, String middleInitial, String lastName) {
        setValidName(true); //set validName to true first, the remaining setters can override it if it's false
        setFirstName(firstName);
        setMiddleInitial(middleInitial);
        setLastName(lastName);
    } //end of parameterized Constructor
    
    /*=======================Setters============================== */
    public void setFirstName(String firstName) {
        if (firstName.length() == 0) {
            setValidName(false);
            this.firstName = "-1";
        }
        else {
            boolean allLetter = true;
            for (char c : firstName.toCharArray()) { //check if user entered all letters or not
                if (!Character.isLetter(c)) {
                    setValidName(false);
                    allLetter = false;
                    this.firstName = "-1";
                }
            }
            if (allLetter)
                this.firstName = firstName;
        }
    } //end of setFirstName method

    public void setMiddleInitial(String middleInitial) {
        if (middleInitial.length() != 1) {
             setValidName(false);
             this.middleInitial = "-1";
        }
        else if (!Character.isLetter(middleInitial.charAt(0))) //check if it's a letter
            setValidName(false);
        else {
            this.middleInitial = middleInitial;
        }
        
    } //end of setMiddleInitial method

    public void setLastName(String lastName) {
        if (lastName.length() == 0) {
            setValidName(false);
            this.lastName = "-1";
        }
        else {
            boolean allLetter = true;
            for (char c : lastName.toCharArray()) { //check if user entered all letters or not
                if (!Character.isLetter(c)) {
                    setValidName(false);
                    allLetter = false;
                    this.lastName = "-1";
                }
            }
            if (allLetter)
                this.lastName = lastName;
        }
    } //end of setLastName method

    public void setValidName(boolean validName) {
        this.validName = validName;
    }
    /*==========================getters==================================*/
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
    public boolean getValidName() {
        return validName;
    }

    @Override
    public String toString() {
        if (getValidName() == false)
            return "Invalid name";
        return getFirstName() + " " + getMiddleInitial() + ". " + getLastName();
    } // end of toString method
} //End of Name class
