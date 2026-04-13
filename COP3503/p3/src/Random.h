#pragma once
#include <random>

class Random {
    std::mt19937 _generator;

public:
    Random() {
        std::random_device device;
        unsigned int seed = device();
        _generator.seed(seed);
    }

    int nextInt(int minValue, int maxValue) {
        std::uniform_int_distribution<int> distribution(minValue, maxValue);
        return distribution(_generator);
    }
};
