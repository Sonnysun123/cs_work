#include "Dealership.h"
#include "Showroom.h"
#include <iostream>
using namespace std;
Dealership::Dealership(string name , unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}
void Dealership::AddShowroom(Showroom s) {
    if (showrooms.size() < capacity) {
        showrooms.push_back(s);
    }
    else {
        cout << "Dealership is full, can't add another showroom!" << endl;
    }    
}
float Dealership::GetAveragePrice() {
    float totalValue = 0;
    int totalVehicles = 0;
    if (showrooms.size() == 0) {
        return 0.00;
    }
    else {
        for (size_t i = 0; i < showrooms.size(); i++) {
            for (size_t j = 0; j < showrooms[i].GetVehicles().size(); j++) {
                totalValue += showrooms[i].GetVehicles()[j].GetPrice();
                totalVehicles++;
            }
        }
        return totalValue / totalVehicles;
    }
}
void Dealership::ShowInventory() {
    if (showrooms.size() == 0) {
        cout << name << " is empty!" << endl;
    }
    for (size_t i = 0; i < showrooms.size(); i++) {
        showrooms[i].ShowInventory();
    }

    cout << "Average car price: $" << GetAveragePrice();
}
