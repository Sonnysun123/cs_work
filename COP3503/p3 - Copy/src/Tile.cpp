#include "Tile.h"

Tile::Tile() = default;

void Tile::resetState() {
    hasMine = false;
    revealed = false;
    flagged = false;
    adjacentMines = 0;
}
