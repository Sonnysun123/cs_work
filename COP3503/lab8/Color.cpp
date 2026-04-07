#include "Color.h"

void Color::SetValue(int value) {_value = value;}
void Color::SetName(const char* name) {_name = name;}

unsigned char Color::GetR() const {return _R;}
unsigned char Color::GetG() const {return _G;}
unsigned char Color::GetB() const {return _B;}
string Color::GetHexValue() const {
    //Merge RGB and convert to hex value

    return _hexValue;
}

string Color::GetName() const {return _name;}

void Color::SetR() {
    _R = static_cast<unsigned char>(_value >> 16);
}
void Color::SetG() {
    int temp = _value >> 8;
    _G = static_cast<unsigned char>(temp & static_cast<int>(pow(2.0, 8.0) - 1));
}
void Color::SetB() {
    _B = static_cast<unsigned char>(_value & static_cast<int>(pow(2.0, 8.0) - 1));
}
void Color::SetHexValue() {
    string hexR = DecimalToHex(GetR());
    string hexG = DecimalToHex(GetG());
    string hexB = DecimalToHex(GetB());
    _hexValue = "0x" + hexR + hexG + hexB;
}

string Color::DecimalToHex(unsigned char n) {
    if (n == 0) return "00";
    string result = "";
    string hexChars = "0123456789ABCDEF";
    while (n > 0) {
        int remainder = n % 16;
        result += hexChars[remainder];
        n /= 16;
    }
    reverse(result.begin(), result.end());
    if (result.length() == 1) 
        result = "0" + result;
    return result;
}

void Color::Deserialize(istringstream &iss) {
    iss >> _name;
    iss >> _value;
    SetR();
    SetG();
    SetB();
    SetHexValue();
}
