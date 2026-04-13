#pragma once
#include <string>

struct GameConfig {
    int columns = 25;
    int rows = 16;
    int mines = 50;
};

// reads the board settings from the config file
bool loadConfig(const std::string& path, GameConfig& config);
