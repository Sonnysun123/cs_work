public interface AlarmSound {

    String DEFAULT_SOUND = "Ding.mp3";
    int MAX_VOLUME = 100;
    int MIN_VOLUME = 0;

    void increaseVolume();
    void decreaseVolume();

} //end of AlarmSound interface
