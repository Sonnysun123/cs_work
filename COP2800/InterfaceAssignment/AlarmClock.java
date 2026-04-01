public class AlarmClock implements Time, AlarmSound, LightSource{
    private int hours;
    private int minutes;
    private String sound;
    private int volume;
    private String color;
    private int brightness;
    private boolean validClock;

    public AlarmClock() {
        this.setTime(MAX_HOURS, MAX_MINUTES);
        this.setSound(DEFAULT_SOUND);
        this.setVolume(MAX_VOLUME);
        this.setColor(DEFAULT_COLOR);
        this.setBrightness(MAX_BRIGHTNESS);
    } //end of no argument AlarmClock constructor
    public AlarmClock(int h, int m, String sound, int volume, String color, int brightness) {
        this.setTime(h, m);
        this.setSound(sound);
        this.setVolume(volume);
        this.setColor(color);
        this.setBrightness(brightness);
    } //end of parameterized AlarmClock constructor
    /*=========================Setters=========================== */
    @Override
    public void setTime(int h, int m) {
        if (h >= MIN_HOURS && h <= MAX_HOURS) 
            this.hours = h;
        else {
            this.hours = -1;
        }

        if (m >= MIN_MINUTES && m <= MAX_MINUTES)
            this.minutes = m;
        else {
            this.minutes = -1;
        }
        updateValidClock();
    } //end of setTime method
    
    public void setSound(String sound) {
        this.sound = sound;
    } //end of setSound method

    public void setVolume(int volume) {
        if (volume >= MIN_VOLUME && volume <= MAX_VOLUME)
            this.volume = volume;
        else {
            this.volume = -1;   
        }
        updateValidClock();
    } //end of setVolume method

    public void setColor(String color) {
        this.color = color;
    } //end of setColor method

    public void setBrightness(int brightness) {
        if (brightness >= MIN_BRIGHTNESS && brightness <= MAX_BRIGHTNESS)
            this.brightness = brightness;
        else {
            this.brightness = -1;
        }
        updateValidClock();
    } //end of setBrightness method

    private void updateValidClock() {
        this.validClock = this.hours != -1
            && this.minutes != -1
            && this.volume != -1
            && this.brightness != -1;
    } //end of updateValidClock method
    /*=============================Getters================================= */
    @Override
    
    public String getFormattedTime() {
        return String.format("%02d:%02d", this.hours, this.minutes);
    } //end of getFormattedTime method
    public int getHours() {return this.hours;} //end of getHours method
    public int getMinutes() {return this.minutes;} //end of getMinutes method
    public String getSound() {return this.sound;} //end of getSound method
    public int getVolume() {return this.volume;} //end of getVolume method
    public String getColor() {return this.color;} //end of getColor method
    public int getBrightness() {return this.brightness;} //end of getBrightness method
    public boolean getValidClock() {return this.validClock;} //end of getValidClock method
    
    /*=============================Behaviors======================= */
    @Override
    public void increaseBrightness() {
        if (!getValidClock()) {
            System.out.println("Can't increase brightness! Invalid Clock!");
            return;
        }
        if (this.brightness == MAX_BRIGHTNESS) {
            System.out.print("Can't increase brightness! Max brightness reached!");
            return;
        }
        this.brightness += 1;
        System.out.println("Brightness increase successful, current brightness is " + getBrightness() + "%\n");
       
    } //end of increaseBrightness method
    @Override
    public void decreaseBrightness() {
        if (!getValidClock()) {
            System.out.println("Can't decrease brightness! Invalid Clock!");
            return;
        }
        if (this.brightness == MIN_BRIGHTNESS) {
            System.out.print("Can't decrease brightness! Minimum brightness reached!");
            return;
        }
        this.brightness -= 1;
        System.out.println("Brightness decrease successful, current brightness is " + getBrightness() + "%\n");
    } //end of decreaseBrightness method
    @Override
    public void increaseVolume() {
        if (!getValidClock()) {
            System.out.println("Can't increase volume! Invalid Clock!");
            return;
        }
        if (this.volume == MAX_VOLUME) {
            System.out.print("Can't increase volume! Max volume reached!");
            return;
        }
        this.volume += 1;
        System.out.println("Volume increase successful, current volume is " + getVolume() + "%\n");
    } //end of increaseVolume method
    @Override
    public void decreaseVolume() {
        if (!getValidClock()) {
            System.out.println("Can't decrease volume! Invalid Clock!");
            return;
        }
        if (this.volume == MIN_VOLUME) {
            System.out.print("Can't decrease volume! Minimum volume reached!");
            return;
        }
        this.volume -= 1;
        System.out.println("Volume decrease successful, current volume is " + getVolume() + "%\n");
    } //end of decreaseVolume method
    @Override

    public String toString() {
        if (validClock == false)
            return "Invalid Clock!\n";

        String message = "[Alarm Time: " + getFormattedTime() + ", \n";
        message += "Alarm Sound: " + getSound() + ", \n"; 
        message += "Alarm Volume: " + getVolume() + "%, \n";
        message += "Alarm Light Color: " + getColor() +", \n";
        message += "Alarm Light Brightness: " + getBrightness() + "%]\n";
        return message;
    } //end of toString method
} //end of AlarmClock class
