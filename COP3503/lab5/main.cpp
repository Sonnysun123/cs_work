#include "extrafile.h"
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

void ReadFile(ifstream& inputFile, vector<Ship>& ships);
void PrintShipInfo(Ship ship);
void PrintAllShip(const vector<Ship>& ships);
void PrintShipWithMostPowerfulWeapon(const vector<Ship>& ships);
void PrintMostPowerfulShip(const vector<Ship>& ships);
void PrintWeakestShip(const vector<Ship>& ships);
void PrintUnarmedShip(const vector<Ship>& ships);

int main() {
    vector<Ship> ships;
    int option; 
    cin >> option;
    switch (option) {
        case 1: {
            ifstream inputFile("friendlyships.shp", ios_base::binary);
            ReadFile(inputFile, ships);
            inputFile.close();
            break;
        }
        case 2: {
            ifstream inputFile2("enemyships.shp", ios_base::binary);
            ReadFile(inputFile2, ships);
            inputFile2.close();
            break;
        }
        case 3: {
            ifstream inputFile("friendlyships.shp", ios_base::binary);
            ReadFile(inputFile, ships);
            inputFile.close();
            ifstream inputFile2("enemyships.shp", ios_base::binary);
            ReadFile(inputFile2, ships);
            inputFile2.close();
            break;
        }
    }
    
    cin >> option;

    switch (option) {
        case 1: {
            PrintAllShip(ships);
            break;
        }
        case 2: {
            PrintShipWithMostPowerfulWeapon(ships);
            break;
        }
        case 3: {
            PrintMostPowerfulShip(ships);
            break;
        }
        case 4: {
            PrintWeakestShip(ships);
            break;
        }
        case 5: {
            PrintUnarmedShip(ships);
            break;
        }
   
    }
}

void ReadFile(ifstream& inputFile, vector<Ship>& ships) {
    if (inputFile.is_open()) {
        unsigned int shipCount;
        inputFile.read(reinterpret_cast<char*>(&shipCount), sizeof(shipCount));
        for (unsigned int i = 0; i < shipCount; i++) {
            Ship ship;
            ship.Deserialize(inputFile);
            ships.push_back(ship);
        }
    }
    else {
        cout << "Error opening file." << endl;
    }
}

void PrintShipInfo(Ship ship) {
        cout << "Name: " << ship.GetName() << endl;
        cout << "Class: " << ship.GetClass() << endl;
        cout << "Length: " << ship.GetLength() << endl;
        cout << "Shield capacity: " << ship.GetShieldCapacity() << endl;
        cout << "Maximum Warp: " << ship.GetMaxWrap() << endl;
        cout << "Armaments:" << endl;
        if (ship.GetWeaponCount() == 0) {
            cout << "Unarmed" << endl;
        }
        else{
            for (const Weapon& weapon : ship.GetWeapons()) {
                cout << weapon.GetName() << ", " << weapon.GetRating() << ", " << weapon.GetPowerConsump() << endl;
            }
            cout << "Total firepower: " << ship.GetTotalFirePower() << endl;

        }
    cout << endl;
}

void PrintAllShip(const vector<Ship>& ships) {
    for (const Ship& ship : ships) {
        PrintShipInfo(ship);
    }
}

void PrintShipWithMostPowerfulWeapon(const vector<Ship>& ships) {
    int maxRating = 0;
    Ship shipWithMostPowerfulWeapon;
    for (const Ship& ship : ships) {
        if (ship.MostPowerfulWeapon() > maxRating) {
            maxRating = ship.MostPowerfulWeapon();
            shipWithMostPowerfulWeapon = ship;
        }
    }
    PrintShipInfo(shipWithMostPowerfulWeapon);
}

void PrintMostPowerfulShip(const vector<Ship>& ships) {
    int maxFirePower = 0;
    Ship mostPowerfulShip;
    for (const Ship& ship : ships) {
        if (ship.GetTotalFirePower() > maxFirePower) {
            maxFirePower = ship.GetTotalFirePower();
            mostPowerfulShip = ship;
        }
    }
    cout << "Most powerful ship:" << endl;
    PrintShipInfo(mostPowerfulShip);
}

void PrintWeakestShip(const vector<Ship>& ships) {
    int minFirePower = 999999;
    Ship weakestShip;
    for (const Ship& ship : ships) {
        if (ship.GetWeaponCount() == 0) {
                continue;
            }
        if (ship.GetTotalFirePower() < minFirePower) {
            minFirePower = ship.GetTotalFirePower();
            weakestShip = ship;
        }
    }
    cout << "Weakest ship:" << endl;
    PrintShipInfo(weakestShip);
}

void PrintUnarmedShip(const vector<Ship>& ships) {
    cout << "Unarmed ships:" << endl;
    for (const Ship& ship : ships) {
        if (ship.GetWeaponCount() == 0) {
            PrintShipInfo(ship);
        }
    }
}