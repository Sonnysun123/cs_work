#include "Config.h"

#include <fstream>

bool loadConfig(const std::string& path, GameConfig& config) {
    std::ifstream input(path);
    if (!input) {
        return false;
    }

    return static_cast<bool>(input >> config.columns >> config.rows >> config.mines);
}
