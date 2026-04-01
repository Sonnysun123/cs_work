public class Office extends Building {
    public int officeNum;
    public String officePurpose;

    public Office() {
        super();
        setOfficeNum(0);
        setOfficePurpose("No purpose");
    } //end of no argument constructor

    public Office(int stories, int officeNum, String purpose) {
        super(stories);
        setOfficeNum(officeNum);
        setOfficePurpose(purpose);
    } //end of full arugment constructor

    /*=========================Setters=========================== */
    public void setOfficeNum(int officeNum) {
        if (officeNum < 0) 
            throw new IllegalArgumentException("Office number must be 0 or greater");
        this.officeNum = officeNum;
    }
    public void setOfficePurpose(String purpose) {
        this.officePurpose = purpose;
    }
    /*=======================Getters======================== */
    public int getOfficeNum() {return this.officeNum;}
    public String getOfficePurpose() {return this.officePurpose;}
    /*=========================equals======================== */
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Office))
            return false;
        return super.equals(o) &&
                this.getOfficeNum() == ((Office)o).getOfficeNum() &&
                this.getOfficePurpose().equals(((Office)o).getOfficePurpose());
    } //end of equals method

    /*===========================toString============================== */
    @Override
    public String toString() {
        String message = "Type: Office, ";
        message += "Stories: " + super.toString() + ", ";
        message += "Office number: " + getOfficeNum() + ", ";
        message += "Office purpose: " + getOfficePurpose();
        return message;
    } //end of toString
}