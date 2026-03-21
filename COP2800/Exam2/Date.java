
public class Date {

    // fields
    private int month;
    private int day;
    private int year;

    // constructor
    public Date(int month, int day, int year) {
        setMonth(month);
        setDay(day);
        setYear(year);
    } // end of Constructor
      // setters

    public void setMonth(int month) {
        this.month = month;
    } // end of setMonth method

    public void setDay(int day) {
        this.day = day;
    } // end of setDay method

    public void setYear(int year) {
        this.year = year;
    } // end of setYear method
      // getters

    public int getMonth() {
        return this.month;
    } // end of getMonth method

    public int getDay() {
        return this.day;
    } // end of getDay method

    public int getYear() {
        return this.year;
    } // end of getYear method
      // behaviors

    public boolean checkValidDate(int month, int day, int year) {
        // check valid year
        if (year < 0) {
            return false;
        }
        // check valid month
        if (month > 12 || month < 1) {
            return false;
        }
        // check valid date
        if (day < 1) {
            return false;
        }
        switch (month) {
            case 1:
                if (day > 31) {
                    return false;
                }
                break;
            case 2:
                // check leap year
                if (year % 4 == 0 && day > 29) {
                    return false;
                } else if (day > 28) {
                    return false;
                }
                break;
            case 3:
                if (day > 31) {
                    return false;
                }
                break;
            case 4:
                if (day > 30) {
                    return false;
                }
                break;
            case 5:
                if (day > 31) {
                    return false;
                }
                break;
            case 6:
                if (day > 30) {
                    return false;
                }
                break;
            case 7:
                if (day > 31) {
                    return false;
                }
                break;
            case 8:
                if (day > 31) {
                    return false;
                }
                break;
            case 9:
                if (day > 30) {
                    return false;
                }
                break;
            case 10:
                if (day > 31) {
                    return false;
                }
                break;
            case 11:
                if (day > 30) {
                    return false;
                }
                break;
            case 12:
                if (day > 31) {
                    return false;
                }
                break;

        } // end of switch
        return true;
    } // end of checkValidDate method
      // toString

    public String toString() {
        // check if date is valid
        if (checkValidDate(getMonth(), getDay(), getYear()) == false) {
            return "Invalid Date!";
        } else {
            // format the date
            String day = String.format("%02d", getDay());
            // format the month
            String month = String.format("%02d", getMonth());
            // format the year
            String year = String.format("%04d", getYear());
            return (day + "/" + month + "/" + year);
        }
    }// end of toString method
} // end of Date class
