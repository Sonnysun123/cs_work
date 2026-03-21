#include <iostream>
#include <string>

using namespace std;

void solve();

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}

void solve() {
  string line;
  getline(cin >> ws, line);
  cout << line << endl;
}