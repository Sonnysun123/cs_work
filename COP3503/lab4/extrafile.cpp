#include "extrafile.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
/*===========================Class Function
 * Definitions=============================*/
void Lego::Deserialize(istringstream &is) {

  string token;

  getline(is, this->_setNumber, ',');

  getline(is, this->_theme, ',');

  getline(is, this->_name, ',');

  getline(is, token, ',');
  this->_minifigs = stoi(token);

  getline(is, token, ',');
  this->_pieces = stoi(token);

  getline(is, token, ',');
  this->_price = stod(token);
}
string Lego::GetSetNumber() const { return this->_setNumber; }
string Lego::GetTheme() const { return this->_theme; }
string Lego::GetName() const { return this->_name; }
unsigned int Lego::GetMinifigs() const { return this->_minifigs; }
unsigned int Lego::GetPieces() const { return this->_pieces; }
double Lego::GetPrice() const { return this->_price; }

void Lego::Print() const {
  cout << "Name: " << _name << endl;
  cout << "Number: " << _setNumber << endl;
  cout << "Theme: " << _theme << endl;
  cout << "Price: $" << _price << endl;
  cout << "Minifigures: " << _minifigs << endl;
  cout << "Piece count: " << _pieces << endl;
}

/*========================Other Function Definitions=====================*/
void MostExpensive(const vector<Lego> &legos) {
  double maxPrice = 0.0;
  int indexOfMostExpensive = 0;

  for (unsigned int i = 0; i < legos.size(); i++) {
    if (legos[i].GetPrice() > maxPrice) {
      maxPrice = legos[i].GetPrice();
      indexOfMostExpensive = i;
    }
  }

  cout << "The most expensive set is:" << endl;
  legos[indexOfMostExpensive].Print();
}

void LargestPieceCount(const vector<Lego> &legos) {
  unsigned int maxPiece = 0;
  int maxPieceIndex = 0;

  for (unsigned int i = 0; i < legos.size(); i++) {
    if (legos[i].GetPieces() > maxPiece) {
      maxPiece = legos[i].GetPieces();
      maxPieceIndex = i;
    }
  }

  cout << "The set with the highest parts count:" << endl;
  legos[maxPieceIndex].Print();
}

void SearchForSetName(const vector<Lego> &legos) {
  string userInput;
  getline(cin, userInput);
  vector<int> index;
  for (unsigned int i = 0; i < legos.size(); i++) {
    if (legos[i].GetName().find(userInput) != string::npos) {
      index.push_back(i);
    }
  }
  if (index.size() == 0)
    cout << "No sets found matching that search term" << endl;
  else {
    cout << "Sets matching \"" << userInput << "\":" << endl;
    for (int i : index)
      cout << legos[i].GetSetNumber() << " " << legos[i].GetName() << " $"
           << legos[i].GetPrice() << endl;
  }
}

void SearchForTheme(const vector<Lego> &legos) {
  string userInput;
  getline(cin, userInput);
  vector<int> index;
  for (unsigned int i = 0; i < legos.size(); i++) {
    if (legos[i].GetTheme().find(userInput) != string::npos) {
      index.push_back(i);
    }
  }

  if (index.size() == 0)
    cout << "No sets found matching that search term" << endl;
  else {
    cout << "Sets matching \"" << userInput << "\":" << endl;
    for (int i : index)
      cout << legos[i].GetSetNumber() << " " << legos[i].GetName() << " $"
           << legos[i].GetPrice() << endl;
  }
}

void PartCountInformation(const vector<Lego> &legos) {
  int totalPartCount = 0;
  int avgPartCount = 0;

  for (auto lego : legos) {
    totalPartCount += lego.GetPieces();
  }

  avgPartCount = totalPartCount / legos.size();
  cout << "Average part count for " << legos.size()
       << " sets: " << avgPartCount;
}

void PriceInformation(const vector<Lego> &legos) {
  double totalPrice = legos[0].GetPrice();
  double avgPrice = 0.0;
  double minPrice = legos[0].GetPrice();
  double maxPrice = legos[0].GetPrice();
  int minPriceIndex, maxPriceIndex = 0;

  for (unsigned int i = 1; i < legos.size(); i++) {
    totalPrice += legos[i].GetPrice();

    if (legos[i].GetPrice() > maxPrice) {
      maxPrice = legos[i].GetPrice();
      maxPriceIndex = i;
    } else if (legos[i].GetPrice() < minPrice) {
      minPrice = legos[i].GetPrice();
      minPriceIndex = i;
    }
  }

  avgPrice = totalPrice / legos.size();

  cout << "Average price for " << legos.size() << " sets: $" << avgPrice << endl
       << endl;
  cout << "Least expensive set:" << endl;
  legos[minPriceIndex].Print();
  cout << endl;
  cout << "Most expensive set:" << endl;
  legos[maxPriceIndex].Print();
  cout << endl;
}

void MinifigureInformation(const vector<Lego> &legos) {
  unsigned int totalMinifig = 0;
  unsigned int maxMinifig = 0;
  int maxMinifigIndex = 0;
  int avgMinifig = 0;

  for (unsigned int i = 0; i < legos.size(); i++) {
    totalMinifig += legos[i].GetMinifigs();
    if (legos[i].GetMinifigs() > maxMinifig) {
      maxMinifig = legos[i].GetMinifigs();
      maxMinifigIndex = i;
    }
  }
  avgMinifig = totalMinifig / legos.size();

  cout << "Average number of minifigures: " << avgMinifig << endl;
  cout << "Set with the most minifigures:" << endl;
  legos[maxMinifigIndex].Print();
}

void IfYouBoughtOneOfEverything(const vector<Lego> &legos) {

  unsigned int totalPieces = 0, totalMinifigs = 0;
  double totalPrice = 0.0;
  for (auto lego : legos) {
    totalPrice += lego.GetPrice();
    totalPieces += lego.GetPieces();
    totalMinifigs += lego.GetMinifigs();
  }
  cout << "If you bought one of everything..." << endl;
  cout << "It would cost: $" << totalPrice << endl;
  cout << "You would have " << totalPieces << " pieces in your collection"
       << endl;
  cout << "You would have an army of " << totalMinifigs << " minifigures!"
       << endl;
}