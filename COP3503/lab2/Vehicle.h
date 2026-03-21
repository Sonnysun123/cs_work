#pragma once
#include <string>
using namespace std;

class Vehicle {
    public:
        //Default constructor, initializes variables to default values
        Vehicle();
        Vehicle(string make , string model , int year , float price , int mileage);
        // Print out the vehicle's details in a single line:
        // 1973 Ford Mustang $9500 113000
        void Display();
        // Create and return a string in the form of "YEAR MAKE MODEL"
        // Example: "1970 Ford Mustang"
        string GetYearMakeModel();
        // Return the price
        float GetPrice();
    private:
        string make;
        string model;
        unsigned int year;
        float price;
        unsigned int mileage;
};