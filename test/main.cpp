#include <bits/stdc++.h>

using namespace std;
int main() {
    map<int,int> test;
    test.emplace(1, 1);
    test.emplace(1, 2);
    
    cout << test[1];
}