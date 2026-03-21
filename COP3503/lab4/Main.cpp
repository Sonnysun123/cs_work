#include "extrafile.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void ReadFile(ifstream &inputfile, vector<Lego> &legos);

int main() {

  cout << std::fixed << setprecision(2);
  /*
      cout << "Which file(s) to open?\n";
      cout << "1. lego1.csv" << endl;
      cout << "2. lego2.csv" << endl;
      cout << "3. lego3.csv" << endl;
      cout << "4. All 3 files" << endl;
  */
  int option;
  cin >> option;

  /*======= Load data from file(s) =======*/
  ifstream inputFile;
  vector<Lego> legos;

  switch (option) {
  case 1:
    inputFile.open("lego1.csv");
    ReadFile(inputFile, legos);
    break;
  case 2:
    inputFile.open("lego2.csv");
    ReadFile(inputFile, legos);
    break;
  case 3:
    inputFile.open("lego3.csv");
    ReadFile(inputFile, legos);
    break;
  case 4:
    inputFile.open("lego1.csv");
    ReadFile(inputFile, legos);
    inputFile.close();
    inputFile.open("lego2.csv");
    ReadFile(inputFile, legos);
    inputFile.close();
    inputFile.open("lego3.csv");
    ReadFile(inputFile, legos);
    break;
  }

  /*
      cout << "1. Most Expensive set" << "\n";
      cout << "2. Largest piece count" << "\n";
      cout << "3. Search for set name containing..." << "\n";
      cout << "4. Search themes..." << "\n";
      cout << "5. Part count information" << "\n";
      cout << "6. Price information" << "\n";
      cout << "7. Minifigure information" << "\n";
      cout << "8. If you bought one of everything..." << "\n";
      cout << "0. Exit" << "\n";
      cout << endl;
  */
  int choice;
  cin >> choice;
  cin.get(); // Clear newline character for any later input

  /*======= Print out how many sets were loaded =======*/
  cout << "Total number of sets: " << legos.size() << endl << endl;

  /*======= Based on the choice, execute the appropriate task and show the
   * results =======*/

  switch (choice) {
  case 1:
    MostExpensive(legos);
    break;

  case 2:
    LargestPieceCount(legos);
    break;

  case 3:
    SearchForSetName(legos);
    break;

  case 4:
    SearchForTheme(legos);
    break;

  case 5:
    PartCountInformation(legos);
    break;

  case 6:
    PriceInformation(legos);
    break;

  case 7:
    MinifigureInformation(legos);
    break;

  case 8:
    IfYouBoughtOneOfEverything(legos);
    break;

  case 0:
    cout << "Exiting program." << endl;
    break;
  }

  return 0;
}

void ReadFile(ifstream &inputFile, vector<Lego> &legos) {
  if (inputFile.is_open()) {
    string lineFromFile;
    getline(inputFile, lineFromFile); // Skip the header line

    while (getline(inputFile, lineFromFile)) {
      istringstream iss(lineFromFile);
      Lego lego;
      lego.Deserialize(iss);
      legos.push_back(lego);
    }

  } else {
    cout << "Error opening file." << endl;
  }
}