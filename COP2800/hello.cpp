#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    int sum = 0;
    int i = 1;
    //refactor the loop to use a for loop
    while (i <= n) {
        sum += i;
        ++i;
    }
    cout << "Sum from 1 to " << n << " is " << sum << endl;

    return 0;

}