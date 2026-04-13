#pragma once
#include <string>
#include <vector>

using namespace std;

struct Tile {
    bool hasMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
    vector<int> neighbors;
};

class Board {
    int _columns;
    int _rows;
    int _mineCount;
    vector<Tile> _tiles;

    // converts a column and row into one index for the tile vector.
    int index(int col, int row) const;
    // Checks whether a board position is inside the valid board area
    bool isInside(int col, int row) const;
    // Clears all tile data before a new board is set up
    void clearBoard();
    // stores the neighboring tile indexes for every tile on the board
    void buildNeighborLists();
    // rresets tile state and counts adjacent mines for each safe tile
    void finalizeBoardState();
    // Counts how many tiles are currently flagged
    int flagCount() const;

public:
    // creates a board with the requested size and number of mines
    Board(int columns, int rows, int mineCount);
    // Builds a new random board by placing mines in random tile positions.
    void resetRandom();
    // Loads a board layout from a file and rebuilds the tile numbers
    bool loadFromFile(const string& path);
    // reveals one tile and spreads to nearby empty tiles when needed
    bool reveal(int col, int row);
    // places or removes a flag on a tile if that tile is still hidden
    void toggleFlag(int col, int row);
    // checks if every non-mine tile has been revealed
    bool hasWon() const;
    // Flags every mine tile after the player wins
    void autoFlagAllMines();
    // Returns how many mines are left after subtracting placed flags.
    int minesRemaining() const;

    // Returns the number of columns on the board
    int columns() const;
    // Returns the number of rows on the board
    int rows() const;
    // Returns the current mine count for this board
    int mineCount() const;
    // Returns the tile at the requested board positio
    const Tile& tileAt(int col, int row) const;


    
};
