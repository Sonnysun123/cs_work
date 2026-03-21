public class Prisoner extends Person {
    private String typeOfCrime;
    private int yearsSentenced;
    private int yearsRemaining;
    private boolean validPrisoner;

    public Prisoner() {
        super();
        makePrisoner();
    } //end of no argument constructor

    public Prisoner(Name name, double height, double weight, String crime, int yearSentenced, int yearRemaining) {
        super(name, height, weight);
        if (super.getValidPerson() == false) //check if name, height, weight are valid
            setValidPrisoner(false);
        else
            setValidPrisoner(true);
        setTypesOfCrime(crime);
        setYearsSentenced(yearSentenced);
        setYearsRemaining(yearRemaining);
    } //end of full argument constructor
    /*================= Setters ========================*/
    public void setTypesOfCrime(String crime) {
        if (crime.equalsIgnoreCase("Murder")|| //accounts mixed lower and upper case
            crime.equalsIgnoreCase("Rape") ||
            crime.equalsIgnoreCase("Theft") ||
            crime.equalsIgnoreCase("Assult") ||
            crime.equalsIgnoreCase("White Collar")) {
                this.typeOfCrime = crime;
            }
        else {
            typeOfCrime = "-1"; //invalid crime
            setValidPrisoner(false);
        }
    }
    public void setYearsSentenced(int year) {
        if (year >= 1 || year <= 1000)
            this.yearsSentenced = year;
        else {
            this.yearsSentenced = -1; //invalid years sentenced
            setValidPrisoner(false);
        }
    }
    public void setYearsRemaining(int year) {
        if (year >= 1 || year <= 1000)
            this.yearsRemaining = year;
        else {
            this.yearsRemaining = -1; //invalid years remaining
            setValidPrisoner(false);
        }
    }
    public void setValidPrisoner(boolean valid) {this.validPrisoner = valid;}
    /*======================Getters======================= */
    public String getTypeOfCrime() {
        if (this.typeOfCrime.equalsIgnoreCase("White Collar"))
            return "White Collar";
         //Capitalize first letter
        String firstLetter = this.typeOfCrime.substring(0, 1).toUpperCase();
        //decapitalize the rest
        String remainingLetters = this.typeOfCrime.substring(1).toLowerCase();
        //resulting String
        String crime = firstLetter + remainingLetters;
        return crime;
    }
    public int getYearsSentenced() {return this.yearsSentenced;}
    public int getYearsRemaining() {return this.yearsRemaining;}
    public boolean getValidPrisoner() {return this.validPrisoner;}

    public void makePrisoner() {
        setValidPrisoner(true);
        setTypesOfCrime("Murder");
        setYearsSentenced(100);
        setYearsRemaining(100);
    } //end of makePrisoner method

    @Override
    public String toString() {
        if (getValidPrisoner() == false)
            return "invalid prisoner";
        return String.format("%s, Type of Crime: %s, Years Sentenced: %d, Years Remaining: %d", super.toString(), getTypeOfCrime(), getYearsSentenced(), getYearsRemaining());
    } //end of toString method
} //end of Prisoner class