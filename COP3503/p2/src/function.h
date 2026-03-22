#pragma once
#include "image.h"

void Multiply(Image& topImage, Image& bottomImage, Image& outputImage);
void Subtract(Image& topImage, Image& bottomImage, Image& outputImage);
void Screen(Image& topImage, Image& bottomImage, Image& outputImage);
void Overlay(Image& topImage, Image& bottomImage, Image& outputImage);