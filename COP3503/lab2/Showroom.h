#pragma once
#include "Vehicle.h"
#include <cstddef>
#include <vector>
using namespace std;
class Showroom {
    public:
        //default constructor
        Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
        //Accessor
        vector<Vehicle> GetVehicles();
        //Behaviors
        void AddVehicle(Vehicle v);
        void ShowInventory();
        float GetInventoryValue();
    private:
        string name;
        vector<Vehicle> vehicles;
        unsigned int capacity;
};