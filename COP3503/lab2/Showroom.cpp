#include "Showroom.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
Showroom::Showroom(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}
vector<Vehicle> Showroom::GetVehicles() {
    return vehicles;
}
void Showroom::AddVehicle(Vehicle v) {
    if (vehicles.size() < capacity) {
        vehicles.push_back(v);
    }
    else {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
}
void Showroom::ShowInventory() {
    
    if (vehicles.size() == 0) {
        cout << name << " is empty!" << endl;
    }
    else {
        cout << "Vehicles in " << name << endl;
        for (size_t i = 0; i < vehicles.size(); i++) {
        vehicles[i].Display();
        }
        cout << endl;
    }
}
float Showroom::GetInventoryValue() {
    float value = 0;
    for (size_t i = 0; i < vehicles.size(); i++) {
        value += vehicles[i].GetPrice();
    }
    return value;
}