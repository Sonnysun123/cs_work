abstract class Instrument {

    private String name;

    public void setName(String name) {this.name = name;}
    public String getName() {return this.name;}
    /*========================Abstract functions====================== */
    public abstract String makeSound();
    public abstract String famousPiece();
    public abstract String famousComposer();

    public String Play() {
        return "Now playing the " + getName();
    }

    @Override
    public String toString() {
        String message = Play() + ". ";
        message += makeSound() + " ";
        message += famousPiece() + ". ";
        message += famousComposer() + "\n";
        return message;
    }
} //end of instrument class