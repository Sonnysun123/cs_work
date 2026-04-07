#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
class Color
{
    int _value;
    string _name;
    unsigned char _R, _G, _B;
    string _hexValue;
public:
    
    void SetValue(int value); //integer value
    void SetName(const char* name); //name of the color

    //Mutators
    void SetR();
    void SetG();
    void SetB();
    void SetHexValue(); 
    //Accessors
    int GetValue() const {
        return _value;
    }
    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    string GetHexValue() const;
    string GetName() const;


    string DecimalToHex(unsigned char n);
    

    void Deserialize(istringstream &iss);
};