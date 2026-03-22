#include "image.h"
#include "pixel.h"
#include "function.h"

void Multiply(Image& topImage, Image& bottomImage, Image& outputImage) {
    outputImage.header = topImage.header;
    outputImage.pixelCount = topImage.pixelCount;

    for (int i = 0; i < topImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;

        unsigned char topBlue = topImage.data[i].blue;
        unsigned char topGreen = topImage.data[i].green;
        unsigned char topRed = topImage.data[i].red;

        unsigned char bottomBlue = bottomImage.data[i].blue;
        unsigned char bottomGreen = bottomImage.data[i].green;
        unsigned char bottomRed = bottomImage.data[i].red;
        
        resultBlue = (unsigned char)(((topBlue / 255.0f) * (bottomBlue / 255.0f) * 255.0f) + 0.5f);
        resultGreen = (unsigned char)(((topGreen / 255.0f) * (bottomGreen / 255.0f) * 255.0f) + 0.5f);
        resultRed = (unsigned char)(((topRed / 255.0f) * (bottomRed / 255.0f) * 255.0f) + 0.5f);

        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
}

void Subtract(Image& topImage, Image& bottomImage, Image& outputImage) {
    outputImage.header = topImage.header;
    outputImage.pixelCount = topImage.pixelCount;

    for (int i = 0; i < topImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;

        unsigned char topBlue = topImage.data[i].blue;
        unsigned char topGreen = topImage.data[i].green;
        unsigned char topRed = topImage.data[i].red;

        unsigned char bottomBlue = bottomImage.data[i].blue;
        unsigned char bottomGreen = bottomImage.data[i].green;
        unsigned char bottomRed = bottomImage.data[i].red;
        
        short tempBlue = bottomBlue - topBlue;
        short tempGreen = bottomGreen - topGreen;
        short tempRed = bottomRed - topRed;

        if (tempBlue < 0)
            tempBlue = 0;
        if (tempGreen < 0)
            tempGreen = 0;
        if (tempRed < 0)
            tempRed = 0;

        resultBlue = (unsigned char) tempBlue;
        resultGreen = (unsigned char) tempGreen;
        resultRed = (unsigned char) tempRed;

        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
}

void Screen(Image& topImage, Image& bottomImage, Image& outputImage) {
    outputImage.header = topImage.header;
    outputImage.pixelCount = topImage.pixelCount;
    for (int i = 0; i < topImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;

        unsigned char topBlue = topImage.data[i].blue;
        unsigned char topGreen = topImage.data[i].green;
        unsigned char topRed = topImage.data[i].red;

        unsigned char bottomBlue = bottomImage.data[i].blue;
        unsigned char bottomGreen = bottomImage.data[i].green;
        unsigned char bottomRed = bottomImage.data[i].red;
        
        float invTopBlue = 1.0f - (topBlue / 255.0f);
        float invBottomBlue = 1.0f - (bottomBlue / 255.0f);
        float tempBlue = 1.0f - (invTopBlue * invBottomBlue);
        float invTopGreen = 1.0f - (topGreen / 255.0f);
        float invBottomGreen = 1.0f - (bottomGreen / 255.0f);
        float tempGreen = 1.0f - (invTopGreen * invBottomGreen);
        float invTopRed = 1.0f - (topRed / 255.0f);
        float invBottomRed = 1.0f - (bottomRed / 255.0f);
        float tempRed = 1.0f - (invTopRed * invBottomRed);

        resultBlue = (unsigned char) (tempBlue * 255.0f + 0.5f);
        resultGreen = (unsigned char) (tempGreen * 255.0f + 0.5f);
        resultRed = (unsigned char) (tempRed * 255.0f + 0.5f);

        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
}

void Overlay(Image& topImage, Image& bottomImage, Image& outputImage) {
    outputImage.header = topImage.header;
    outputImage.pixelCount = topImage.pixelCount;

    for (int i = 0; i < topImage.pixelCount; i++) {
        unsigned char resultBlue, resultGreen, resultRed;

        unsigned char topBlue = topImage.data[i].blue;
        unsigned char topGreen = topImage.data[i].green;
        unsigned char topRed = topImage.data[i].red;

        unsigned char bottomBlue = bottomImage.data[i].blue;
        unsigned char bottomGreen = bottomImage.data[i].green;
        unsigned char bottomRed = bottomImage.data[i].red;
        /*===============Blue===================*/
        float tempBottomBlue = bottomBlue / 255.0f;
        float tempTopBlue = topBlue / 255.0f;
        float tempResultBlue;

        if (tempBottomBlue <= 0.5f)
            tempResultBlue = 2.0f * tempBottomBlue * tempTopBlue;
        else
            tempResultBlue = 1.0f - 2.0f * (1.0f - tempBottomBlue) * (1.0f - tempTopBlue);

        resultBlue = (unsigned char) (tempResultBlue * 255.0f + 0.5f);
        /*===================Green========================*/
        float tempBottomGreen = bottomGreen / 255.0f;
        float tempTopGreen = topGreen / 255.0f;
        float tempResultGreen;

        if (tempBottomGreen <= 0.5f)
            tempResultGreen = 2.0f * tempBottomGreen * tempTopGreen;
        else
            tempResultGreen = 1.0f - 2.0f * (1.0f - tempBottomGreen) * (1.0f - tempTopGreen);
        
        resultGreen = (unsigned char) (tempResultGreen * 255.0f + 0.5f);
        /*+=======================Red==========================*/
        float tempBottomRed = bottomRed / 255.0f;
        float tempTopRed = topRed / 255.0f;
        float tempResultRed;

        if (tempBottomRed <= 0.5f)
            tempResultRed = 2.0f * tempBottomRed * tempTopRed;
        else
            tempResultRed = 1.0f - 2.0f * (1.0f - tempBottomRed) * (1.0f - tempTopRed);
        
        resultRed = (unsigned char) (tempResultRed * 255.0f + 0.5f);

        Pixel pixel(resultBlue, resultGreen, resultRed);
        outputImage.data.push_back(pixel);
    }
}