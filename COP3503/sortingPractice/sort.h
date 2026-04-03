#pragma once
#include <algorithm>
#include <random>
#include <utility>
#include <vector>
#include <iostream>
#include "Timer.h"

int RandomNum();
void LoadVector(std::vector<int>& numbers);
void PrintVector(std::vector<int>& numbers);
void BubbleSort(std::vector<int>& numbers);
void SelectionSort(std::vector<int>& numbers);
void InsertionSort(std::vector<int>& numbers);


