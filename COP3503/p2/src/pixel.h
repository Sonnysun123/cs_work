#pragma once
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
/*==================To late when I realized I should make a vector...=====================*/
struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    Pixel() {
        red = 0;
        green = 0;
        blue = 0;
    }
    Pixel(unsigned char blue, unsigned char green, unsigned char red) {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    void Deserialize(ifstream& inputFile) {
        inputFile.read(reinterpret_cast<char*>(&blue), sizeof(blue));
        inputFile.read(reinterpret_cast<char*>(&green), sizeof(green));
        inputFile.read(reinterpret_cast<char*>(&red), sizeof(red));
    }

    void Serialize(ofstream& outputFile) {
        outputFile.write(reinterpret_cast<char*>(&blue), sizeof(blue));
        outputFile.write(reinterpret_cast<char*>(&green), sizeof(green));
        outputFile.write(reinterpret_cast<char*>(&red), sizeof(red));
    }

    void PrintPixel(ofstream& outputFile) {
        string message = "";
        message += "blue" + to_string(static_cast<int>(blue)) + "\n";
        message += "green" + to_string(static_cast<int>(green)) + "\n";
        message += "red" + to_string(static_cast<int>(red)) + "\n";
        outputFile << message << endl;
    }
};