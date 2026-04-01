public interface Time {

    int MAX_HOURS = 23;
    int MIN_HOURS = 0;
    int MAX_MINUTES = 59;
    int MIN_MINUTES = 0;
    
    void setTime(int h, int m);
    String getFormattedTime();
} //end of Time interface
