#include "Config.h"
#include <fstream>

using namespace std;

bool loadConfig(const string& path, GameConfig& config) {
    ifstream input(path);
    if (!input) {
        return false;
    }
    input >> config.columns >> config.rows >> config.mines;
    return true;
}
