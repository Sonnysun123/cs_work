#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    ofstream file("output.txt");
    file << "Hello, World!";
    return 0;
}