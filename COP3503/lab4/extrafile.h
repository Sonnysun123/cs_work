#pragma once
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Lego {

  string _setNumber;
  string _theme;
  string _name;
  unsigned int _minifigs;
  unsigned int _pieces;
  double _price;

public:
  void Deserialize(istringstream &is);
  string GetSetNumber() const;
  string GetTheme() const;
  string GetName() const;
  unsigned int GetMinifigs() const;
  unsigned int GetPieces() const;
  double GetPrice() const;
  void Print() const;
};

void MostExpensive(const vector<Lego> &legos);
void LargestPieceCount(const vector<Lego> &legos);
void SearchForSetName(const vector<Lego> &legos);
void SearchForTheme(const vector<Lego> &legos);
void PartCountInformation(const vector<Lego> &legos);
void PriceInformation(const vector<Lego> &legos);
void MinifigureInformation(const vector<Lego> &legos);
void IfYouBoughtOneOfEverything(const vector<Lego> &legos);