public class Actor extends Person{
    private String mainGenre;
    private int totalMoviesMade;
    private boolean validActor;
    public Actor() {
        super();
        makeActor();
    } //end of no argument constructor
    public Actor(Name name, double height, double weight, String mainGenre, int totalMoviesMade) {
        super(name, height, weight);
        if (super.getValidPerson() == false) //check if name, height, weight are valid
            setValidActor(false);
        else
            setValidActor(true);
        setMainGenre(mainGenre);
        setTotalMoviesMade(totalMoviesMade);
    } //end of full argument constructor
    /*===============setters====================== */
    public void setMainGenre(String mainGenre) {
        if (mainGenre.equalsIgnoreCase("Comedy")|| //accounts mixed lower and upper case
            mainGenre.equalsIgnoreCase("Horror") ||
            mainGenre.equalsIgnoreCase("Drama")) {
                this.mainGenre = mainGenre;
            }
        else
            this.mainGenre = "-1"; //invalid genere
            setValidActor(false);
    }
    public void setTotalMoviesMade(int totalMoviesMade) {
        if (totalMoviesMade >= 0 && totalMoviesMade <= 100)
            this.totalMoviesMade = totalMoviesMade;
        else {
            this.totalMoviesMade = -1; //invalid movies made
            setValidActor(false);
        }
    }
    public void setValidActor(boolean validActor) {this.validActor = validActor;}
    /*=====================Getters========================= */
    public String getMainGenre() {
         //Capitalize first letter
        String firstLetter = this.mainGenre.substring(0, 1).toUpperCase();
        //decapitalize the rest
        String remainingLetters = this.mainGenre.substring(1).toLowerCase();
        //resulting String
        String genre = firstLetter + remainingLetters;
        return genre;
    }
    public int getTotalMoviesMade() {return this.totalMoviesMade;}
    public boolean getValidActor() {return this.validActor;}

    public void makeActor() {
        setValidActor(true);
        setMainGenre("Comedy");
        setTotalMoviesMade(10);
    } //end of makeActor method

    @Override
    public String toString() {
        if (getValidActor() == false)
            return "invalid actor";
        return String.format("%s, Main Genre: %s, Total Movies Made: %d", super.toString(), getMainGenre(), getTotalMoviesMade());
    } //end of toString method
} //end of Actor class