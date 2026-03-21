#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

mt19937 random_mt;
struct StateInfo {
    string stateName;
    int perCapitaIncome;
    int population;
    int medianIncome;
    int numHousehold;

    void Deserialize(istringstream& iss) {
        string token;
        getline(iss, this->stateName, ',');
        getline(iss, token, ',');
        this->perCapitaIncome = stoi(token);
        getline(iss, token, ',');
        this->population = stoi(token);
        getline(iss, token, ',');
        this->medianIncome = stoi(token);
        getline(iss, token, ',');
        this->numHousehold = stoi(token);
    }
};
int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numRoll, int numSide);
void ReadFile(ifstream& inputfile, map<string, StateInfo>& stateStats);
void PrintAllStates(const map<string,  StateInfo>& stateStats);
void PrintIndividualState(const StateInfo state);
void CheckState(string state, const map<string, StateInfo>& stateStats);
int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		cout << "Number of times to roll the die: ";
      // user input
        int numRoll;
        cin >> numRoll;

		cout << "Number of sides on this die: ";
      // user input
        int diceSide;
        cin >> diceSide;
		// Roll Dice
        RollDice(numRoll, diceSide);
	}
	else if (option == 2)
	{
	   // Load the states
       map<string, StateInfo> stateStats;
	   ifstream inputFile("states.csv");
       ReadFile(inputFile, stateStats);
       cout << "1. Print all states" << endl;
       cout << "2. Search for a state" << endl;
       cin >> option;
       if (option == 1) {
            PrintAllStates(stateStats);
       }
       else if (option == 2) {
            string inputState;
            cin >> inputState;
            CheckState(inputState, stateStats);
       }


	   // Get input for option 1 (show all states) or 2 (do a search for a particular state)

	}

	return 0;
}

void RollDice(int numRoll, int numSide) {
    map<int, int> diceStats;
    //set all side to 0
    for (int i = 1; i < numSide + 1; i++) {
        diceStats[i] = 0;
    }
    //increase rollValue index by 1
    for (int i = 0; i < numRoll; i++) {
        int rollValue = Random(1, numSide);
        diceStats[rollValue] += 1;
    }
    //print out content
    for (auto a : diceStats)
        cout << a.first << ": " << a.second << endl;
}
void ReadFile(ifstream& inputfile, map<string, StateInfo>& stateStats) {
    if (inputfile.is_open()) {
        //get first line
        string lineFromFile;
        getline(inputfile, lineFromFile);

        while (getline(inputfile, lineFromFile)) {
            istringstream iss(lineFromFile);
            StateInfo info;
            info.Deserialize(iss);
            //load the state info
            stateStats[info.stateName] = info;
        }
    }
    else {
        cout << "error";
    }
}
void PrintAllStates(const map<string, StateInfo>& stateStats) {
    for (auto a : stateStats) {
        PrintIndividualState(a.second);
    }
}

void PrintIndividualState(const StateInfo state) {
    cout << state.stateName << endl;
    cout << "Population: " << state.population << endl;
    cout << "Per Capita Income: " << state.perCapitaIncome << endl;
    cout << "Median Household Income: " << state.medianIncome << endl;
    cout << "Number of Households: " << state.numHousehold << endl;
}

void CheckState(string state, const map<string, StateInfo>& stateStats) {
    auto it = stateStats.find(state);
    if (it != stateStats.end()) {
        PrintIndividualState(it->second);
    } else {
        cout << "No match found for " <<state << endl;
    }
}