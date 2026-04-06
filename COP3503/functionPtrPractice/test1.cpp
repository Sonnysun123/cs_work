#include <iostream>
#include <functional>
#include "functions.h"
using namespace std;

void Print1() {
    cout << "1" << endl;
}

struct Print2 {
    int _x;
    Print2(int x): _x(x){}
    void operator()() {
        cout << _x << endl;
    }
};
int main() {
    Functions<void()> functions;
    //Function pointer
    void (*first)() = Print1;
    functions.AddAction(first);
    //Functor
    functions.AddAction(Print2(5));
    //lambda
    auto PrintX = [](){cout << "3" << endl;};
    functions.AddAction(PrintX);

    return 0;
}