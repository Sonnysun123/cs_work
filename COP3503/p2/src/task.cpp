#include "task.h"
#include <fstream>
#include "image.h"
#include "function.h"
#include "pixel.h"

void Task1(ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile) {
    Image topImage;
    Image bottomImage;
    Image outputImage;
    topImage.Deserialize(topLayer);
    bottomImage.Deserialize(bottomLayer);

    outputImage.header = topImage.header;
    outputImage.pixelCount = topImage.pixelCount;

    Multiply(topImage, bottomImage, outputImage);
    outputImage.Serialize(outputFile);
}
void Task2(ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile) {
    Image topImage;
    Image bottomImage;
    Image outputImage;
    topImage.Deserialize(topLayer);
    bottomImage.Deserialize(bottomLayer);
    Subtract(topImage, bottomImage, outputImage);
    outputImage.Serialize(outputFile);
}
void Task3(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile) {
    Image topImage;
    Image bottomImage;
    Image image3;
    Image tempImage;
    Image outputImage;

    topImage.Deserialize(inputFile1);
    bottomImage.Deserialize(inputFile2);
    image3.Deserialize(inputFile3);
    Multiply(topImage, bottomImage, tempImage);
    Screen(tempImage, image3, outputImage);
    outputImage.Serialize(outputFile);

}
void Task4(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile) {
    Image topImage;
    Image bottomImage;
    Image image3;
    Image tempImage;
    Image outputImage;

    topImage.Deserialize(inputFile1);
    bottomImage.Deserialize(inputFile2);
    image3.Deserialize(inputFile3);
    Multiply(topImage, bottomImage, tempImage);
    Subtract(image3, tempImage, outputImage);
    outputImage.Serialize(outputFile);
}
void Task5(ifstream& topLayer, ifstream& bottomLayer, ofstream& outputFile) {
    Image topImage;
    Image bottomImage;
    Image outputImage;
    topImage.Deserialize(topLayer);
    bottomImage.Deserialize(bottomLayer);
    Overlay(topImage, bottomImage, outputImage);
    outputImage.Serialize(outputFile);
}
void Task6(ifstream& inputFile1, ofstream& outputFile) {
    Image inputImage;
    Image outputImage;

    inputImage.Deserialize(inputFile1);
    outputImage.header = inputImage.header;
    outputImage.pixelCount = inputImage.pixelCount;

    for (int i = 0; i < inputImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;
        short tempGreen;
        resultBlue = inputImage.data[i].blue;
        resultRed = inputImage.data[i].red;
        tempGreen = inputImage.data[i].green + 200;
        if (tempGreen > 255)
            tempGreen = 255;
        resultGreen = tempGreen;
        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
    outputImage.Serialize(outputFile);
}

void Task7(ifstream& inputFile1, ofstream& outputFile) {
    Image inputImage;
    Image outputImage;

    inputImage.Deserialize(inputFile1);
    outputImage.header = inputImage.header;
    outputImage.pixelCount = inputImage.pixelCount;

    for (int i = 0; i < inputImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;
        short tempRed;
        resultBlue = 0;
        resultGreen = inputImage.data[i].green;
        tempRed = inputImage.data[i].red * 4;
        if (tempRed > 255)
            tempRed = 255;
        resultRed = tempRed;
        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
    outputImage.Serialize(outputFile);
}

void Task8(ifstream& inputFile1, ofstream& outputFile1, ofstream& outputFile2, ofstream& outputFile3) {
    Image inputImage;
    Image outputImage1;
    Image outputImage2;
    Image outputImage3;
    inputImage.Deserialize(inputFile1);

    outputImage1.header = inputImage.header;
    outputImage2.header = inputImage.header;
    outputImage3.header = inputImage.header;
    outputImage1.pixelCount = inputImage.pixelCount;
    outputImage2.pixelCount = inputImage.pixelCount;
    outputImage3.pixelCount = inputImage.pixelCount;

    for (int i = 0; i < inputImage.pixelCount; i++) {
        unsigned char red, green, blue;
        red = inputImage.data[i].red;
        green = inputImage.data[i].green;
        blue = inputImage.data[i].blue;
        //all red
        Pixel pixelRed(red, red, red);
        //all green
        Pixel pixelGreen(green, green, green);
        //all blue
        Pixel pixelBlue(blue, blue, blue);
        outputImage1.data.push_back(pixelRed);
        outputImage2.data.push_back(pixelGreen);
        outputImage3.data.push_back(pixelBlue);
    }
    outputImage1.Serialize(outputFile1);
    outputImage2.Serialize(outputFile2);
    outputImage3.Serialize(outputFile3);
}

void Task9(ifstream& inputFile1, ifstream& inputFile2, ifstream& inputFile3, ofstream& outputFile) {
    Image redImage, greenImage, blueImage, outputImage;
    redImage.Deserialize(inputFile1);
    greenImage.Deserialize(inputFile2);
    blueImage.Deserialize(inputFile3);
    outputImage.header = redImage.header;
    outputImage.pixelCount = redImage.pixelCount;
    for (int i = 0; i < outputImage.pixelCount; i++) {
        unsigned char red, green, blue;
        red = redImage.data[i].red;
        green = greenImage.data[i].green;
        blue = blueImage.data[i].blue;
        Pixel pixe(blue, green, red);
        outputImage.data.push_back(pixe);
    }
    outputImage.Serialize(outputFile);
}
void Task10(ifstream& inputFile1, ofstream& outputFile) {
    Image inputImage, outputImage;
    inputImage.Deserialize(inputFile1);
    outputImage.header = inputImage.header;
    outputImage.pixelCount = inputImage.pixelCount;
    vector<Pixel> reversePixel;
    for (int i = 0; i < outputImage.pixelCount; i++) {
        unsigned char red = inputImage.data[i].red;
        unsigned char green = inputImage.data[i].green;
        unsigned char blue = inputImage.data[i].blue;
        Pixel pixel(blue, green, red);
        reversePixel.push_back(pixel);
    }
    for (int i = outputImage.pixelCount - 1; i >= 0; i--) {
        outputImage.data.push_back(reversePixel[i]);
    }
    outputImage.Serialize(outputFile);
}
