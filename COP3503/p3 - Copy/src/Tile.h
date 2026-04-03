#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile {
public:
    Tile();

    bool hasMine = false;
    bool revealed = false;
    bool flagged = false;
    int adjacentMines = 0;
    int row = 0;
    int col = 0;
    std::vector<Tile*> neighbors;

    void resetState();
};

#endif
