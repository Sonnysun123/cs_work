#pragma once
#include <string>

using namespace std;

struct GameConfig {
    int columns = 25;
    int rows = 16;
    int mines = 50;
};

// reads the board settings from the config file
bool loadConfig(const string& path, GameConfig& config);
