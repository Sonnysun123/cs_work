// #include "Board.h"
// #include "Random.h"
// #include <fstream>
// #include <string>
// #include <vector>
// //BRUHHHHH SO MUCH WORK
// using namespace std;

// Random randomGenerator;

// int randomNumber(int minValue, int maxValue) {
//     return randomGenerator.nextInt(minValue, maxValue);
// }

// Board::Board(int columns, int rows, int mineCount) : _columns(columns), _rows(rows), _mineCount(mineCount), _tiles(columns * rows) {
//     buildNeighborLists();
//     resetRandom();
// }

// void Board::resetRandom() {
//     clearBoard();

//     int minesPlaced = 0;
//     int lastIndex = static_cast<int>(_tiles.size()) - 1;

//     while (minesPlaced < _mineCount) {
//         int randomIndex = randomNumber(0, lastIndex);

//         if (_tiles[randomIndex].hasMine) {
//             continue;
//         }

//         _tiles[randomIndex].hasMine = true;
//         minesPlaced = minesPlaced + 1;
//     }

//     finalizeBoardState();
// }

// bool Board::loadFromFile(const string& path) {
//     ifstream input(path);
//     if (!input) {
//         return false;
//     }
//     clearBoard();
//     string line;
//     int row = 0;
//     int loadedMineCount = 0;
//     while (getline(input, line) && row < _rows) {
//         for (int col = 0; col < _columns && col < static_cast<int>(line.size()); ++col) {
//             bool isMine = (line[col] == '1');
//             Tile& tile = _tiles[index(col, row)];
//             tile.hasMine = isMine;
//             if (isMine) {
//                 loadedMineCount++;
//             }
//         }
//         row++;
//     }

//     _mineCount = loadedMineCount;
//     finalizeBoardState();
//     return true;
// }

// bool Board::reveal(int col, int row) {
//     if (!isInside(col, row)) {
//         return false;
//     }

//     Tile& start = _tiles[index(col, row)];
//     if (start.isFlagged || start.isRevealed) {
//         return false;
//     }

//     start.isRevealed = true;
//     if (start.hasMine) {
//         return true;
//     }

//     if (start.adjacentMines != 0) {
//         return false;
//     }

//     vector<int> stack{index(col, row)};
//     while (!stack.empty()) {
//         const int currentIndex = stack.back();
//         stack.pop_back();
//         Tile& current = _tiles[currentIndex];

//         for (const int neighborIndex : current.neighbors) {
//             Tile& neighbor = _tiles[neighborIndex];
//             if (neighbor.isRevealed || neighbor.isFlagged || neighbor.hasMine) {
//                 continue;
//             }

//             neighbor.isRevealed = true;
//             if (neighbor.adjacentMines == 0) {
//                 stack.push_back(neighborIndex);
//             }
//         }
//     }

//     return false;
// }

// void Board::toggleFlag(int col, int row) {
//     if (!isInside(col, row)) {
//         return;
//     }

//     Tile& tile = _tiles[index(col, row)];
//     if (tile.isRevealed) {
//         return;
//     }

//     tile.isFlagged = !tile.isFlagged;
// }

// bool Board::hasWon() const {
//     for (const Tile& tile : _tiles) {
//         if (!tile.hasMine && !tile.isRevealed) {
//             return false;
//         }
//     }
//     return true;
// }

// void Board::autoFlagAllMines() {
//     for (Tile& tile : _tiles) {
//         if (tile.hasMine) {
//             tile.isFlagged = true;
//         }
//     }
// }

// int Board::minesRemaining() const {
//     return _mineCount - flagCount();
// }

// int Board::columns() const {
//     return _columns;
// }

// int Board::rows() const {
//     return _rows;
// }

// int Board::mineCount() const {
//     return _mineCount;
// }

// const Tile& Board::tileAt(int col, int row) const {
//     return _tiles[index(col, row)];
// }

// int Board::index(int col, int row) const {
//     return row * _columns + col;
// }

// bool Board::isInside(int col, int row) const {
//     return col >= 0 && col < _columns && row >= 0 && row < _rows;
// }

// void Board::clearBoard() {
//     for (Tile& tile : _tiles) {
//         tile.hasMine = false;
//         tile.isRevealed = false;
//         tile.isFlagged = false;
//         tile.adjacentMines = 0;
//     }
// }

// void Board::buildNeighborLists() {
//     for (int row = 0; row < _rows; ++row) {
//         for (int col = 0; col < _columns; ++col) {
//             Tile& tile = _tiles[index(col, row)];
//             tile.neighbors.clear();

//             for (int yOffset = -1; yOffset <= 1; yOffset++) {
//                 for (int xOffset = -1; xOffset <= 1; xOffset++) {
//                     if (xOffset == 0 && yOffset == 0) {
//                         continue;
//                     }
//                     const int neighborCol = col + xOffset;
//                     const int neighborRow = row + yOffset;
//                     if (isInside(neighborCol, neighborRow)) {
//                         tile.neighbors.push_back(index(neighborCol, neighborRow));
//                     }
//                 }
//             }
//         }
//     }
// }

// void Board::finalizeBoardState() {
//     for (Tile& tile : _tiles) {
//         tile.isRevealed = false;
//         tile.isFlagged = false;
//         tile.adjacentMines = 0;
//         if (tile.hasMine) {
//             continue;
//         }

//         for (const int neighborIndex : tile.neighbors) {
//             if (_tiles[neighborIndex].hasMine) {
//                 tile.adjacentMines++;
//             }
//         }
//     }
// }

// int Board::flagCount() const {
//     int count = 0;
//     for (const Tile& tile : _tiles) {
//         if (tile.isFlagged) {
//             count++;
//         }
//     }
//     return count;
// }
