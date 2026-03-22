#pragma once
#include "header.h"
#include "pixel.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Image {

    Header header;
    vector<Pixel> data;
    int pixelCount;

    void Deserialize(ifstream& inputFile) {

        header.Deserialize(inputFile);
        pixelCount = header.height * header.width;
        for (int i = 0; i < pixelCount; i++) {
            Pixel pixel;
            pixel.Deserialize(inputFile);
            data.push_back(pixel);
        }
    }

    void Serialize(ofstream& outputFile) {
        header.Serialize(outputFile);

        for (int i = 0; i < pixelCount; i++) {
            data[i].Serialize(outputFile);
        }

    }

    void PrintImage(ofstream& outputFile) {

        header.PrintHeader(outputFile);
        outputFile << "Total number of pixels: " + to_string(pixelCount) << endl;
        for (int i = 0; i < pixelCount; i++) {
            outputFile << "Pixel" + to_string(i + 1) + ": " << endl;
            data[i].PrintPixel(outputFile);
        }
    }

};