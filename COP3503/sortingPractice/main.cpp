#include "sort.h"
#include "search.h"
#include "time.h"
#include <vector>

Timer timer;

int main() {
    std::vector<int> numbers(100);
    LoadVector(numbers);
    SelectionSort(numbers);
    PrintVector(numbers);
    int target = 100;

    timer.reset();
    size_t a = LinearSearch(numbers, target);
    timer.printTime("Linear search: ");
    std::cout << "Location: " << a << std::endl;
    timer.reset();
    a = BinarySearch(numbers, target);
    timer.printTime("Binary search: ");
    std::cout << "Location: " << a << std::endl;


}