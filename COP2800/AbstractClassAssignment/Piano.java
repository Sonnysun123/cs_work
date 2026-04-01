class Piano extends Instrument {

    public Piano() {
        setName("piano");
    } //end of Piano constructor
    @Override
    public String makeSound() {
        return "Piano keyboard striking!";
    }
    @Override
    public String famousPiece() {
        return "Famous piano piece: Chopin Ballade No. 4 in F minor";
    }
    @Override
    public String famousComposer() {
        return "Famous piano composer: Frederic Chopin";
    }
    
} //end of Piano class