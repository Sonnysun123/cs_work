#include "sort.h"

int RandomNum() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,100);
    return distr(gen);
}
void LoadVector(std::vector<int>& numbers) {
    for (int& i : numbers) 
        i = RandomNum();
}
void PrintVector(std::vector<int>& numbers) {
    for (int i : numbers)
        std::cout << i << " ";
    std::cout << std::endl;
}
void BubbleSort(std::vector<int>& numbers) {
    bool swapMade;
    size_t n = numbers.size();
    do { //keeps looping if swap made
        swapMade = false;
        for (size_t i = 0; i < n - 1; i++) {
            //compare adjacent elements, swap if necessary
            if (numbers[i] > numbers[i + 1]) {
                std::swap(numbers[i], numbers[i + 1]);
                swapMade = true;
            }
        }
        // After each pass, the largest element is already at the end. 
        // We can ignore the last element in the next pass.
        n--; 
    } while (swapMade && n > 1); //n > 1 prevents check when only 1 element is unsorted
}
void SelectionSort(std::vector<int>& numbers) {
    for (size_t sortedIndex = 0; sortedIndex < numbers.size() - 1; sortedIndex++) { //no need to check the last element
        size_t minIndex = sortedIndex; //assume first index is min
         //Finds the smallest number in the unsorted list and smaller than value at sortedIndex
        for (size_t j = sortedIndex + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minIndex])
                minIndex = j; //update min index
        }
        if (minIndex != sortedIndex) //if a value smaller than value at sortedIndex is found
            std::swap(numbers[sortedIndex], numbers[minIndex]);
    }
}
void InsertionSort(std::vector<int>& numbers) {
    //For each element
    //Bubble that element forward, until it can't swap anymore
    //Start with 2nd element
    for (size_t sortedIndex = 1; sortedIndex < numbers.size(); sortedIndex++) { 
        size_t currentIndex = sortedIndex;
        //Stops when current value greater than the one before it
        while (currentIndex > 0 && numbers[currentIndex] < numbers[currentIndex - 1]) {
            std::swap(numbers[currentIndex], numbers[currentIndex - 1]);
            currentIndex--;
        }
    }
}