public interface LightSource {

    String DEFAULT_COLOR = "white";
    int MAX_BRIGHTNESS = 100;
    int MIN_BRIGHTNESS = 1;
    
    void increaseBrightness();
    void decreaseBrightness();
} //end of LightSource interface
