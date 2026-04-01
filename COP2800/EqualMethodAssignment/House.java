public class House extends Building {
    public int width; //unit feet
    public int height; //unit feet
    public int numBedrooms;

    public House() {
        super();
        setWidth(50);
        setHeight(50);
        setNumBedrooms(3);
    } //end of no arugment House constructor

    public House(int stories, int width, int height, int numBed) {
        super(stories);
        setWidth(width);
        setHeight(height);
        setNumBedrooms(numBed);
    } //end of full argument House contructor

    /*========================Setters=========================== */
    public void setWidth(int width) {
        if (width < 1)
            throw new IllegalArgumentException("Width must be 1 feet or higher");
        this.width = width;
    }
    public void setHeight(int height) {
        if (height < 1)
            throw new IllegalArgumentException("Height must be 1 feet or higher");
        this.height = height;
    }
    public void setNumBedrooms(int numBed) {
        if (numBed < 1)
            throw new IllegalArgumentException("Number of bedrooms must be 1 or higher");
        this.numBedrooms = numBed;
    }
    /*===========================Getters============================= */
    public int getWidth() {return this.width;}
    public int getHeight() {return this.height;}
    public int getNumBedrooms() {return this.numBedrooms;}
    /*============================equals============================== */
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof House))
            return false;
        return super.equals(o) &&
               this.getWidth() == ((House)o).getWidth() &&
               this.getHeight() == ((House)o).getHeight() &&
               this.getNumBedrooms() == ((House)o).getNumBedrooms();
    } //end of equals method
    /*===============================toString=========================== */
    @Override
    public String toString() {
        String message = "Type: House, ";
        message += super.toString() + ", ";
        message += "Width: " + getWidth() + " feet, ";
        message += "Height: " + getHeight() + " feet, ";
        message += "Number of bedrooms: " + getNumBedrooms();
        return message;
    } //end of toString method
}   
