public class Building {
    public int numStories;

    public Building() {
        setNumStories(1);
    } //end of no argument Building constructor
    public Building(int stories) {
        setNumStories(stories);
    } //end of parameterized Building constructor
    /*======================Setters====================== */
    public void setNumStories(int stories) {
        if (stories < 1)
            throw new IllegalArgumentException("Stories must be 1 or higher");
        this.numStories = stories;
    }
   /*========================Getters============================ */ 
    public int getNumStories() {return this.numStories;}
    
    /*======================Equals===================== */
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Building))
            return false;
        return ((Building)o).getNumStories() == this.getNumStories();
    } //end of equals method
    /*========================toString=========================== */
    @Override
    public String toString() {
        String message = "";
        if (getClass() == Building.class) //if runtime class of an object is strictly equal to Building
            message += "Type: Building, ";
        message += "Number of storie(s): " + getNumStories();
        return message;
    } //end of toString method
} //end of Building class 
