#include <iostream>
using namespace std;
//Do more research on how primary, partial, full template words with more than 1 typename
// primary template
template<typename T>
class Example {
public:
    void Print() {
        cout << "primary template" << endl;
    }
};

// partial specialization for pointer types
template<typename T>
class Example<T*> {
public:
    void Print() {
        cout << "partial specialization for pointers" << endl;
    }
};

// full specialization for bool
template<>
class Example<bool> {
public:
    void Print() {
        cout << "full specialization for bool" << endl;
    }
};

int main() {
    Example<int> a;
    Example<int*> b;
    Example<bool> c;

    a.Print();
    b.Print();
    c.Print();
}
