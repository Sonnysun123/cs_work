#pragma once

#include <string>
#include <vector>

struct Tile {
    bool hasMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
    std::vector<int> neighbors;
};

class Board {
public:
    Board(int columns, int rows, int mineCount);

    void resetRandom();
    bool loadFromFile(const std::string& path);
    bool reveal(int col, int row);
    void toggleFlag(int col, int row);

    bool hasWon() const;
    void autoFlagAllMines();
    int minesRemaining() const;

    int columns() const;
    int rows() const;
    int mineCount() const;
    const Tile& tileAt(int col, int row) const;

private:
    int columns_;
    int rows_;
    int mineCount_;
    std::vector<Tile> tiles_;

    int index(int col, int row) const;
    bool isInside(int col, int row) const;
    void clearBoard();
    void buildNeighborLists();
    void finalizeBoardState();
    int flagCount() const;
};
