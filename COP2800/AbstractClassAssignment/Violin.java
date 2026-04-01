class Violin extends Instrument {
    public Violin() {
        setName("violin");
    } //end of Violin constructor
    @Override
    public String makeSound() {
        return "Violin String bowing!";
    }
    @Override
    public String famousPiece() {
        return "Famous violin piece: The Four Seasons: Summer";
    }
    @Override
    public String famousComposer() {
        return "Famous violin composer: Antonio Vivaldi";
    }

} //end of Violin class