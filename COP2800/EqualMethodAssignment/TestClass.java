/** *****************************************************************
 *  Written by Hexuan Sun
 *  Date: April 1, 2026
 *  Purpose: To models different kinds of buildings using inheritance. 
 *  Creates Building, House, Office, and Trailer objects, stores them in lists,
 * and compares them using equals and toString methods 
 ******************************************************************* */
import java.util.ArrayList;
public class TestClass {

    public static void loadBuildings(ArrayList<Building> buildings, ArrayList<String> buildingnames) {
        Building building1 = new Building(5);
        Building building2 = new Building(4);
        Building building5 = new Building(4);
        Building building3 = new Building();
        Building building4 = new Building();
        buildings.add(building1);
        buildings.add(building2);
        buildings.add(building3);
        buildings.add(building4);
        buildings.add(building5);
        for (int i = 1; i <= 5; i++) {
            buildingnames.add("building" + i);
        }
    } //end of loadBuildings method
    public static void loadHouses(ArrayList<Building> buildings, ArrayList<String> buildingnames) {
        House house1 = new House(2, 60, 60, 3);
        House house2 = new House(1, 30, 30, 1);
        House house3 = new House(1, 30, 30, 1);
        House house4 = new House();
        House house5 = new House();
        buildings.add(house1);
        buildings.add(house2);
        buildings.add(house3);
        buildings.add(house4);
        buildings.add(house5);
        for (int i = 1; i <= 5; i++) {
            buildingnames.add("house" + i);
        }
    } //end of loadHouses method
    public static void loadOffices(ArrayList<Building> buildings, ArrayList<String> buildingnames) {
        Office office1 = new Office(3, 1234, "Law firm");
        Office office2 = new Office(2, 4321, "Dental");
        Office office3 = new Office(2, 4321, "Dental");
        Office office4 = new Office();
        Office office5 = new Office();
        buildings.add(office1);
        buildings.add(office2);
        buildings.add(office3);
        buildings.add(office4);
        buildings.add(office5);
        for (int i = 1; i <= 5; i++) {
            buildingnames.add("office" + i);
        }
    } //end of loadOffices method
    public static void loadTrailer(ArrayList<Building> buildings, ArrayList<String> buildingnames) {
        Trailer trailer1 = new Trailer(1, 1999, false);
        Trailer trailer2 = new Trailer(2, 2020, true);
        Trailer trailer3 = new Trailer(2, 2020, true);
        Trailer trailer4 = new Trailer();
        Trailer trailer5 = new Trailer();
        buildings.add(trailer1);
        buildings.add(trailer2);
        buildings.add(trailer3);
        buildings.add(trailer4);
        buildings.add(trailer5);
        for (int i = 1; i <= 5; i++) {
            buildingnames.add("trailer" + i);
        }
    } //end of loadTrailer method
    public static void compareListElements(ArrayList<Building> buildings, ArrayList<String> buildingnames) {
        for (int i = 0; i < buildings.size() - 1; i++) {
            Building currentBuilding = buildings.get(i);
            Building nextBuilding = buildings.get(i + 1);
            String currentName = buildingnames.get(i);
            String nextName = buildingnames.get(i + 1);

            System.out.println("----------------------------------------");
            System.out.println(currentName + ": " + currentBuilding);
            System.out.println(nextName + ": " + nextBuilding);

            String message = currentName + " and " + nextName;
            if (currentBuilding.equals(nextBuilding)) {
                message += " are equal.";
            }
            else
                message += " are not equal.";
            System.out.println("Result: " + message);
            System.out.println();
        }
        System.out.println("----------------------------------------");

    } //end of compareListElements class
    public static void main(String[] args) {
        ArrayList<Building> buildings = new ArrayList<>();
        ArrayList<String> buildingnames = new ArrayList<>();
        loadBuildings(buildings, buildingnames);
        loadHouses(buildings, buildingnames);
        loadOffices(buildings, buildingnames);
        loadTrailer(buildings, buildingnames);
        compareListElements(buildings, buildingnames);
    } //end of main class
} //end of TestClass
