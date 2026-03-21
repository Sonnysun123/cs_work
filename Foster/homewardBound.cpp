#include <iostream>
#include <map>
#include <string>

using namespace std;

void solve();
void SplitAndMapCity(string line, map<string, string> &cities);
void ReverseMap(const map<string, string> original,
                map<string, string> &transformed);
string FindStartCity(const map<string, string> departToDestCities);
void PrintResult(const map<string, string> destToDepartCities,
                 string startCity);

int main() {
  unsigned int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}

void solve() {
  unsigned int cityNum;
  cin >> cityNum;
  map<string, string> departToDestCities;
  map<string, string> destToDepartCities;

  while (cityNum--) {
    string line;
    getline(cin >> ws, line);
    SplitAndMapCity(line, departToDestCities);
  } // split every city and map them to a dictionary
  ReverseMap(departToDestCities, destToDepartCities);
  string startCity = FindStartCity(departToDestCities);
  PrintResult(destToDepartCities, startCity);
}

void SplitAndMapCity(string line, map<string, string> &cities) {
  unsigned int spaceIndex = 0;
  string departCity = "";
  string destCity = "";
  for (unsigned int i = 0; i < line.length(); i++) {
    if (line[i] == ' ')
      spaceIndex = i;
  }
  departCity = line.substr(0, spaceIndex);
  destCity = line.substr(spaceIndex + 1);
  cities[departCity] = destCity;
}

void ReverseMap(const map<string, string> original,
                map<string, string> &transformed) {
  for (auto city : original) {
    transformed[city.second] = city.first;
  }
}

string FindStartCity(const map<string, string> departToDestCities) {
  for (auto city : departToDestCities) {
    if (departToDestCities.find(city.second) == departToDestCities.end()) {
      return city.second;
    }
  }
  return "error";
}

void PrintResult(const map<string, string> destToDepartCities,
                 string startCity) {
  string currentCity = startCity;
  cout << currentCity << endl;
  while (destToDepartCities.find(currentCity) != destToDepartCities.end()) {
    cout << destToDepartCities.at(currentCity) << endl;
    currentCity = destToDepartCities.at(currentCity);
  }
}