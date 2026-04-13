#pragma once
#include <random>

using namespace std;

class Random {
    mt19937 _generator;

public:
    Random() {
        random_device device;
        unsigned int seed = device();
        _generator.seed(seed);
    }

    int nextInt(int minValue, int maxValue) {
        uniform_int_distribution<int> distribution(minValue, maxValue);
        return distribution(_generator);
    }
};