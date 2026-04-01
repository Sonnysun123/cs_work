/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: March, 20, 2026
 *  Purpose: This program provides a GUI via JOptionPane to 
 * manage a collection of individuals. It allows users to categorize 
 * entries as general Persons, Actors, or Prisoners, store them in an  
 * arrayList, and perform data analysis such as identifying the 
 * longest-serving prisoner and generating summaries.
 ******************************************************************* */
import java.util.ArrayList;
import javax.swing.JOptionPane;
public class Main {

    public static String menu() {
        String menuString = "MAIN MENU\n";
        menuString += "1. Add a person\n";
        menuString += "2. Add an actor\n";
        menuString += "3. Add a prisoner\n";
        menuString += "4. Display all records to the screen\n";
        menuString += "5. Summary\n";
        menuString += "    Show the total number of People\n";
        menuString += "    Show the total number of Actors\n";
        menuString += "    Show the total number of Prisoners\n";
        menuString += "    Show the record of the Prisoner that has served the longest time in prison\n";
        menuString += "6. Quit\n";   
        return menuString;
    }
   //Exception handling for all user input
    public static int askChoice() {
        int choice = 0;
        boolean goodChoice = false;
        
        while (!goodChoice) { //validate choice
            String input = JOptionPane.showInputDialog(menu());
            if (input == null) //if the user hits cancel or x
                return -1;
            try {
                choice = Integer.parseInt(input); // Converts String to int
                
                if (choice >= 1 && choice <= 6) { //if choice is between 1 and 6
                    goodChoice = true;
                } else {
                    JOptionPane.showMessageDialog(null, "Please enter a number between 1 and 6.");
                }
            } catch (NumberFormatException e) { // If user enters non integer
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a valid number.");
            }
        }
        return choice;
    } //end of askChoice method
    public static Name askName() {
        Name name = null;
        boolean goodName = false;
        while (!goodName) {
            String firstName = JOptionPane.showInputDialog("Enter first name (all letters)");
            String middleInitial = JOptionPane.showInputDialog("Enter middle initial (single letter)");
            String lastName = JOptionPane.showInputDialog("Enter last name (all letters)");
            name = new Name(firstName, middleInitial, lastName);
            if (name.getValidName() == true) {
                goodName = true;
            }
            else {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a valid name.");
            }
        }
        return name;
    } //end of askName method
    public static double askHeight() {
        double height = 0.0;
        boolean goodChoice = false;
        while (!goodChoice) { //validate choice
            String input = JOptionPane.showInputDialog("Enter height in inches(between 12 and 144): "); 
            try {
                height = Double.parseDouble(input); //Check if user entered valid number
                if (height < 12 || height > 144)
                    JOptionPane.showMessageDialog(null, "Invalid input! Please enter number between 12 and 144");
                else
                    goodChoice = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a valid number.");
            }
        }
        return height;
    } //end of askHeight method
    public static double askWeight() {
    double weight = 0.0;
        boolean goodChoice = false;
        while (!goodChoice) { //validate choice
            String input = JOptionPane.showInputDialog("Enter weight in pounds(between 25 and 1000): "); 
            try {
                weight = Double.parseDouble(input); //Check if user entered valid number
                if (weight < 25 || weight > 1000)
                    JOptionPane.showMessageDialog(null, "Invalid input! Please enter number between 25 and 1000");
                else
                    goodChoice = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a valid number.");
            }
        }
        return weight;
    } //end of askWeight method
    public static String askMainGenre() {
        String genre = null;
        boolean goodGenre = false;
        while(!goodGenre) {
            genre = JOptionPane.showInputDialog("Enter main genre of the actor(Comedy, Horror, or Drama):");
            if (genre.equalsIgnoreCase("Comedy")|| //accounts mixed lower and upper case
                genre.equalsIgnoreCase("Horror") ||
                genre.equalsIgnoreCase("Drama")) {
                    goodGenre = true;
            }
            else {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter Comedy, Horror, or Drama.");
            }
        }
        return genre;
    } //end of askMainGenre method
    public static int askTotalMoviesMade() {
        int movies = 0;
        boolean goodMovie = false;
        while (!goodMovie) {
            String input = JOptionPane.showInputDialog("Enter number of movies made(between 0 and 100): ");
            try {
                movies = Integer.parseInt(input);
                if (movies >=0 && movies <= 100)
                    goodMovie = true;
                else
                    JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 0 and 100.");
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 0 and 100.");
            }
        }
        return movies;
    } //end of askTotalMoviesMade method
    public static String askCrime() {
        String crime = null;
        boolean goodCrime = false;
        while(!goodCrime) {
            crime = JOptionPane.showInputDialog("Enter prisoner's crime (Murder, Rape, Theft, Assult, or White Collar): ");
            if (crime.equalsIgnoreCase("Murder")|| //accounts mixed lower and upper case
                crime.equalsIgnoreCase("Rape") ||
                crime.equalsIgnoreCase("Theft") ||
                crime.equalsIgnoreCase("Assult") ||
                crime.equalsIgnoreCase("White Collar")) {
                    goodCrime = true;
            }
            else {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter Murder, Rape, Theft, Assult, or White Collar.");
            }
        }
        return crime;   
    } //end of askCrime method
    public static int askYearSentenced() {
        int yearSentenced = 0;
        boolean goodYear = false;
        while (!goodYear) {
            String input = JOptionPane.showInputDialog("Enter number of year sentenced(between 1 and 1000): ");
            try {
                yearSentenced = Integer.parseInt(input);
                if (yearSentenced >=1 && yearSentenced <= 1000)
                    goodYear = true;
                else
                    JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 1 and 1000.");
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 1 and 1000.");
            }
        }
        return yearSentenced;
    }  //end of askYearsSentenced method
    public static int askYearRemained(int yearSentenced) {
        int yearRemained = 0;
        boolean goodYear = false;
        while (!goodYear) {
            String input = JOptionPane.showInputDialog("Enter number of years remaining(between 1 and 1000): ");
            try {
                yearRemained = Integer.parseInt(input);
                if (yearRemained > yearSentenced) //if year remaining is greater than year sentenced
                    JOptionPane.showMessageDialog(null, "Invalid input! Year remaining greater than year sentenced.");
                else if (yearRemained >=1 && yearRemained <= 1000)
                    goodYear = true;
                else
                    JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 1 and 1000.");
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Invalid input! Please enter a number between 1 and 1000.");
            }
        }
        return yearRemained;
    } //end of askYearRemained method
    /*==============================Choices============================== */
    public static void switchChoices(int choice, ArrayList<Person> personList) { //Switch options
          switch (choice) {
            case 1:
                choice1(personList);
                break;
            case 2:
                choice2(personList);
                break;
            case 3:
                choice3(personList);
                break;
            case 4:
                choice4(personList);
                break;
            case 5:
                choice5(personList);
                break;
            case 6:
                choice6();
                break;
        }
    } //end of switchChoices method
    public static void choice1(ArrayList<Person> personList) { //Adds Person
        Name name = askName();
        double height = askHeight();
        double weight = askWeight();
        Person person = new Person(name, height, weight);
        personList.add(person);
    } //end of choice1 method
    public static void choice2(ArrayList<Person> personList) { //Adds Actor
        Name name = askName();
        double height = askHeight();
        double weight = askWeight();
        String mainGenre = askMainGenre();
        int totalMoviesMade = askTotalMoviesMade();
        Actor actor = new Actor(name, height, weight, mainGenre, totalMoviesMade);
        personList.add(actor);
    } //end of choice2 method
    public static void choice3(ArrayList<Person> personList) { //Adds Prisoner
        Name name = askName();
        double height = askHeight();
        double weight = askWeight();
        String crime = askCrime();
        int yearSentenced = askYearSentenced();
        int yearRemained = askYearRemained(yearSentenced);
        Prisoner prisoner = new Prisoner(name, height, weight, crime, yearSentenced, yearRemained);
        personList.add(prisoner);
    } //end of choice3 method
    public static void choice4(ArrayList<Person> personList) { //Display all record
        String info = "";
        for (int i = 0; i < personList.size(); i++) {
            info += personList.get(i).toString() + "\n";
        } //Adds information of each Object
        JOptionPane.showMessageDialog(null, info);
    } //end of choice4 method
    public static void choice5(ArrayList<Person> personlList) { //Display summary
        int personCount = 0, actorCount = 0, prisonerCount = 0;
        for (int i = 0; i < personlList.size(); i++) {
            if (personlList.get(i) instanceof Actor)
                actorCount++;
            
            else if (personlList.get(i) instanceof Prisoner)
                prisonerCount++;

            personCount++; //person count increases by one regardeless object type
        }
        String longestPrisonerInfo = "";
        int longestServed = 0;
        for (int i = 0; i < personlList.size(); i++) {
            if (personlList.get(i) instanceof Prisoner) { //if object is Prisoner
                Prisoner prisoner = (Prisoner) personlList.get(i);
                int yearServed = prisoner.getYearsSentenced() - prisoner.getYearsRemaining();
                if (yearServed >= longestServed)
                    longestPrisonerInfo = prisoner.toString(); //stores longest served prisoner information
            }
        }
        String output = "Total number of people: " + personCount;
        output += "\nTotal number of Actors: " + actorCount;
        output += "\nTotal number of Prisoners: " + prisonerCount;
        output += "\nLongest served prisoner..." + longestPrisonerInfo;
        JOptionPane.showMessageDialog(null, output);
    } //end of choice5 method
    public static void choice6() { //Quit the program
        JOptionPane.showMessageDialog(null, "Goodbye!");
    } //end of choice6 method
    public static void main(String[] args) {
        ArrayList<Person> personList = new ArrayList<>();
        int choice = 0;
        while (choice != 6) {
            choice = askChoice();
            if (choice == -1) //if user hits cancel or x
                choice = 6;
            switchChoices(choice, personList);
        }
    } //end of main method
} //end of Main class