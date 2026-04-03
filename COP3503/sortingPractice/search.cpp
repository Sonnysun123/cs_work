#include "search.h"
#include <cstddef>

size_t LinearSearch(std::vector<int>& numbers, int val) {
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == val) 
            return i;
    }
    return static_cast<size_t>(-1);
}

size_t BinarySearch(std::vector<int>& numbers, int val) {
    size_t leftIndex = 0;
    size_t rightIndex = numbers.size() - 1;

    while (leftIndex <= rightIndex) {
        size_t middleIndex = (leftIndex + rightIndex) / 2;

        if (numbers[middleIndex] == val)
            return middleIndex;

        if (numbers[middleIndex] < val)
            leftIndex = middleIndex + 1;
        else
            rightIndex = middleIndex - 1;
    }
    return static_cast<size_t>(-1);
}