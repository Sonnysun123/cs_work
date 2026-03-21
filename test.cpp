//write a simple program that prints "Hello, World!" to the console
#include <iostream>
#include <string>
using namespace std;
int main() {
    int a = 5;
    int& b = a;
    int& c = b;
    cout << a << " " << b << " " << c << endl;
    a = 10;
    cout << a << " " << b << " " << c << endl;
}
