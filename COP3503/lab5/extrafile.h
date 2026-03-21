#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Weapon {

    string _name;
    int _rating;
    float _powerConsump;
public:
    const string& GetName() const {return _name;};
    int GetRating() const {return _rating;};
    float GetPowerConsump() const {return _powerConsump;};

    void Deserialize(ifstream& inputFile) {
        // Read the name length and name
        unsigned int nameLength;
        inputFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* tempArray = new char[nameLength];
        inputFile.read(tempArray, nameLength);
        _name = tempArray;
        delete[] tempArray;
        //Read rating
        inputFile.read(reinterpret_cast<char*>(&_rating), sizeof(_rating));
        //Read power consumption
        inputFile.read(reinterpret_cast<char*>(&_powerConsump), sizeof(_powerConsump));
    }
};
class Ship {

    string _name;
    string _class;
    short _length;
    int _shieldCapacity;
    float _maxWrap;
    int _weaponCount;
    vector<Weapon> _weapons;
public:
    const string& GetName() const {return _name;};
    const string& GetClass() const {return _class;};
    short GetLength() const {return _length;};
    int GetShieldCapacity() const {return _shieldCapacity;};
    float GetMaxWrap() const {return _maxWrap;};
    int GetWeaponCount() const {return _weaponCount;};
    const vector<Weapon>& GetWeapons() const {return _weapons;};
    void Deserialize(ifstream& inputFile) {
        // Read the name length and name
        unsigned int nameLength;
        inputFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* tempArray = new char[nameLength];
        inputFile.read(tempArray, nameLength);
        _name = tempArray;
        delete[] tempArray;

        // Read the class length and class
        unsigned int classLength;
        inputFile.read(reinterpret_cast<char*>(&classLength), sizeof(classLength));
        char* tempClassArray = new char[classLength];
        inputFile.read(tempClassArray, classLength);
        _class = tempClassArray;
        delete[] tempClassArray;

        //Read ship length
        inputFile.read(reinterpret_cast<char*>(&_length), sizeof(_length));
        //Read shield capacity
        inputFile.read(reinterpret_cast<char*>(&_shieldCapacity), sizeof(_shieldCapacity));
        //Read max warp
        inputFile.read(reinterpret_cast<char*>(&_maxWrap), sizeof(_maxWrap));
        //Read weapon count
        inputFile.read(reinterpret_cast<char*>(&_weaponCount), sizeof(_weaponCount));

        //Read each weapon
        for (int i = 0; i < _weaponCount; i++) {
            Weapon weapon;
            weapon.Deserialize(inputFile);
            _weapons.push_back(weapon);
        }
    }

    int GetTotalFirePower() const {
        int totalFirePower = 0;
        for (auto weapon : _weapons) {
            totalFirePower += weapon.GetRating();
        }
        return totalFirePower;
    }

    int MostPowerfulWeapon() const {
        int maxRating = 0;
        Weapon mostPowerfulWeapon;
        for (const Weapon& weapon : _weapons) {
            if (weapon.GetRating() > maxRating) {
                maxRating = weapon.GetRating();
                mostPowerfulWeapon = weapon;
            }
        }
        return maxRating;
    }
};

