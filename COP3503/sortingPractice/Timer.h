#pragma once
#include <chrono>
#include <iostream>

struct Timer {
    using Clock = std::chrono::steady_clock; //alias
    using timePoint = Clock::time_point;
    using Duration = std::chrono::duration<double>;

    timePoint _start;
    Timer() {
        _start = Clock::now();
    }
    double elapsedSeconds() const {
        Duration elapsed = Clock::now() - _start;
        return elapsed.count();
    }
    void reset() {
        _start = Clock::now();
    }
    void printTime() const {
        std::cout << "Unknown elapsed time: " << this->elapsedSeconds() << std::endl;
    }
    void printTime(const char* message) const {
        std::cout << message << this->elapsedSeconds() << std::endl;
    }
};