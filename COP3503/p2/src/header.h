#pragma once
#include <fstream>
#include <iostream>
using namespace std;
struct Header {
    
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    void Deserialize(ifstream& inputFile) {

        inputFile.read(reinterpret_cast<char*>(&idLength), sizeof(idLength));
        inputFile.read(reinterpret_cast<char*>(&colorMapType), sizeof(colorMapType));
        inputFile.read(reinterpret_cast<char*>(&dataTypeCode), sizeof(dataTypeCode));
        inputFile.read(reinterpret_cast<char*>(&colorMapOrigin), sizeof(colorMapOrigin));
        inputFile.read(reinterpret_cast<char*>(&colorMapLength), sizeof(colorMapLength));
        inputFile.read(reinterpret_cast<char*>(&colorMapDepth), sizeof(colorMapDepth));
        inputFile.read(reinterpret_cast<char*>(&xOrigin), sizeof(xOrigin));
        inputFile.read(reinterpret_cast<char*>(&yOrigin), sizeof(yOrigin));
        inputFile.read(reinterpret_cast<char*>(&width), sizeof(width));
        inputFile.read(reinterpret_cast<char*>(&height), sizeof(height));
        inputFile.read(reinterpret_cast<char*>(&bitsPerPixel), sizeof(bitsPerPixel));
        inputFile.read(reinterpret_cast<char*>(&imageDescriptor), sizeof(imageDescriptor));
    
    }

    void Serialize(ofstream& outputFile) {

        outputFile.write(reinterpret_cast<char*>(&idLength), sizeof(idLength));
        outputFile.write(reinterpret_cast<char*>(&colorMapType), sizeof(colorMapType));
        outputFile.write(reinterpret_cast<char*>(&dataTypeCode), sizeof(dataTypeCode));
        outputFile.write(reinterpret_cast<char*>(&colorMapOrigin), sizeof(colorMapOrigin));
        outputFile.write(reinterpret_cast<char*>(&colorMapLength), sizeof(colorMapLength));
        outputFile.write(reinterpret_cast<char*>(&colorMapDepth), sizeof(colorMapDepth));
        outputFile.write(reinterpret_cast<char*>(&xOrigin), sizeof(xOrigin));
        outputFile.write(reinterpret_cast<char*>(&yOrigin), sizeof(yOrigin));
        outputFile.write(reinterpret_cast<char*>(&width), sizeof(width));
        outputFile.write(reinterpret_cast<char*>(&height), sizeof(height));
        outputFile.write(reinterpret_cast<char*>(&bitsPerPixel), sizeof(bitsPerPixel));
        outputFile.write(reinterpret_cast<char*>(&imageDescriptor), sizeof(imageDescriptor));
    }

    void PrintHeader(ofstream& outputFile) {

        string message = "idLength: " + to_string(static_cast<int>(idLength)) + "\n";
        message += "colorMapType: " + to_string(static_cast<int>(colorMapType)) + "\n";
        message += "dataTypeCode: " + to_string(static_cast<int>(dataTypeCode)) + "\n";
        message += "colorMapOrigin: " + to_string(static_cast<int>(colorMapOrigin)) + "\n";
        message += "colorMapLength: " + to_string(static_cast<int>(colorMapLength)) + "\n";
        message += "colorMapDepth: " + to_string(static_cast<int>(colorMapDepth)) + "\n";
        message += "xOrigin: " + to_string(static_cast<int>(xOrigin)) + "\n";
        message += "yOrigin: " + to_string(static_cast<int>(yOrigin)) + "\n";
        message += "width: " + to_string(static_cast<int>(width)) + "\n";
        message += "height: " + to_string(static_cast<int>(height)) + "\n";
        message += "bitsPerPixel: " + to_string(static_cast<int>(bitsPerPixel)) + "\n";
        message += "imageDescriptor: " + to_string(static_cast<int>(imageDescriptor)) + "\n";
        outputFile << message << endl;

    }
};
