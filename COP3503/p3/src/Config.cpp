#include "Config.h"
#include <fstream>

bool loadConfig(const std::string& path, GameConfig& config) {
    std::ifstream input(path);
    if (!input) {
        return false;
    }
    input >> config.columns >> config.rows >> config.mines;
    return true;
}
