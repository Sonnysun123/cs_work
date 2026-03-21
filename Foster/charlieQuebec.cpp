#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void solve();
void LoadDictionary(map<char, string> &convert);
void InnerSolve();

map<char, string> convert;

int main() {
  int tc;
  cin >> tc;
  LoadDictionary(convert);

  while (tc--) {
    solve();
  }
}

void LoadDictionary(map<char, string> &convert) {
  convert[' '] = " ";
  convert['A'] = "Alpha";
  convert['B'] = "Bravo";
  convert['C'] = "Charlie";
  convert['D'] = "Delta";
  convert['E'] = "Echo";
  convert['F'] = "Foxtrot";
  convert['G'] = "Golf";
  convert['H'] = "Hotel";
  convert['I'] = "India";
  convert['J'] = "Juliet";
  convert['K'] = "Kilo";
  convert['L'] = "Lima";
  convert['M'] = "Mike";
  convert['N'] = "November";
  convert['O'] = "Oscar";
  convert['P'] = "Papa";
  convert['Q'] = "Quebec";
  convert['R'] = "Romeo";
  convert['S'] = "Sierra";
  convert['T'] = "Tango";
  convert['U'] = "Uniform";
  convert['V'] = "Victor";
  convert['W'] = "Whiskey";
  convert['X'] = "Xray";
  convert['Y'] = "Yankee";
  convert['Z'] = "Zulu";
}

void solve() {
  int lineNum;
  cin >> lineNum;
  while (lineNum--) {
    InnerSolve();
  }
}

void InnerSolve() {
  string line = "";
  string result = "";
  getline(cin >> ws, line);
  for (char character : line) {
    char capitalChar = toupper(character);
    if (capitalChar == ' ') {
      result = result.substr(0, result.length() - 1);
      result += convert[capitalChar];
    } else
      result += convert[capitalChar] + '-';
  }
  result = result.substr(0, result.length() - 1);
  cout << result << endl;
}