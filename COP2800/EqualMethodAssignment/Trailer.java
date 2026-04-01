public class Trailer extends Building {
    public int yearMade;
    public boolean trailerType;

    public Trailer() {
        super();
        setYearMade(2000);
        setTrailerType(false);
    } //end of no argument Trailer constructor

    public Trailer(int stories, int yearMade, boolean trailerType) {
        super(stories);
        setYearMade(yearMade);
        setTrailerType(trailerType);
    } //end of full argument Trailer constructor

    /*======================Setters======================== */
    public void setYearMade(int year) {
        if (year < 1800 || year > 2026)
            throw new IllegalArgumentException("Year must be greater than or equal to 1800 and less than 2027");
        this.yearMade = year;
    }
    public void setTrailerType(boolean trailerType) {this.trailerType = trailerType;}
    /*=========================Getters============================ */
    public int getYearMade() {return this.yearMade;}
    public boolean getTrailerType() {return this.trailerType;}
    /*=========================equals========================== */
    public boolean equals(Object o) {
        if (!(o instanceof Trailer))
            return false;
        return super.equals(o) &&
               this.getYearMade() == ((Trailer)o).getYearMade() &&
               this.getTrailerType() == ((Trailer)o).getTrailerType();
    } //end of equals method
    /*===========================toString=========================== */
    @Override
    public String toString() {
        String type = (getTrailerType()) ? "Doublewide" : "SingleWide"; //Doublewide if true, singlewide if false
        String message = "Type: Trailer, ";
        message += super.toString() + ", ";
        message += "Year made: " + getYearMade() + ", ";
        message += "Trailer type: " + type;
        return message;
    } //end of toString method
}