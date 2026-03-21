#pragma once
#include "Showroom.h"
#include <string>
#include <vector>
using namespace std;

class Dealership {
    public:
        //Constructor
        Dealership(string name = "Generic Dealership" , unsigned int capacity = 0);
        //Behaviors
        void AddShowroom(Showroom s);
        float GetAveragePrice();
        void ShowInventory();
    private:
        vector<Showroom> showrooms;
        string name;
        unsigned int capacity;
};