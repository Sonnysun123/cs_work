#include "Vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(){
    make = "COP3503";
    model = "Rust Bucket";
    year = 1900;
    price = 0;
    mileage = 0;
};
Vehicle::Vehicle(string make , string model , int year , float price , int mileage){
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->mileage = mileage;
};
void Vehicle::Display(){
    cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;
}
string Vehicle::GetYearMakeModel(){
    return to_string(year) + " " + make + " " + model;
}
float Vehicle::GetPrice(){
    return price;
}
