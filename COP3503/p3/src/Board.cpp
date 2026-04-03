#include "Board.h"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <random>
#include <string>
#include <vector>

Board::Board(int columns, int rows, int mineCount)
    : columns_(columns), rows_(rows), mineCount_(mineCount), tiles_(columns * rows) {
    buildNeighborLists();
    resetRandom();
}

void Board::resetRandom() {
    clearBoard();

    std::vector<int> indices(tiles_.size());
    for (std::size_t i = 0; i < indices.size(); ++i) {
        indices[i] = static_cast<int>(i);
    }

    static std::mt19937 generator(std::random_device{}());
    std::shuffle(indices.begin(), indices.end(), generator);
    for (int i = 0; i < mineCount_; ++i) {
        tiles_[indices[i]].hasMine = true;
    }

    finalizeBoardState();
}

bool Board::loadFromFile(const std::string& path) {
    std::ifstream input(path);
    if (!input) {
        return false;
    }

    clearBoard();
    std::string line;
    int row = 0;
    int loadedMineCount = 0;
    while (std::getline(input, line) && row < rows_) {
        for (int col = 0; col < columns_ && col < static_cast<int>(line.size()); ++col) {
            const bool isMine = line[col] == '1';
            Tile& tile = tiles_[index(col, row)];
            tile.hasMine = isMine;
            if (isMine) {
                ++loadedMineCount;
            }
        }
        ++row;
    }

    mineCount_ = loadedMineCount;
    finalizeBoardState();
    return true;
}

bool Board::reveal(int col, int row) {
    if (!isInside(col, row)) {
        return false;
    }

    Tile& start = tiles_[index(col, row)];
    if (start.isFlagged || start.isRevealed) {
        return false;
    }

    start.isRevealed = true;
    if (start.hasMine) {
        return true;
    }

    if (start.adjacentMines != 0) {
        return false;
    }

    std::vector<int> stack{index(col, row)};
    while (!stack.empty()) {
        const int currentIndex = stack.back();
        stack.pop_back();
        Tile& current = tiles_[currentIndex];

        for (const int neighborIndex : current.neighbors) {
            Tile& neighbor = tiles_[neighborIndex];
            if (neighbor.isRevealed || neighbor.isFlagged || neighbor.hasMine) {
                continue;
            }

            neighbor.isRevealed = true;
            if (neighbor.adjacentMines == 0) {
                stack.push_back(neighborIndex);
            }
        }
    }

    return false;
}

void Board::toggleFlag(int col, int row) {
    if (!isInside(col, row)) {
        return;
    }

    Tile& tile = tiles_[index(col, row)];
    if (tile.isRevealed) {
        return;
    }

    tile.isFlagged = !tile.isFlagged;
}

bool Board::hasWon() const {
    for (const Tile& tile : tiles_) {
        if (!tile.hasMine && !tile.isRevealed) {
            return false;
        }
    }
    return true;
}

void Board::autoFlagAllMines() {
    for (Tile& tile : tiles_) {
        if (tile.hasMine) {
            tile.isFlagged = true;
        }
    }
}

int Board::minesRemaining() const {
    return mineCount_ - flagCount();
}

int Board::columns() const {
    return columns_;
}

int Board::rows() const {
    return rows_;
}

int Board::mineCount() const {
    return mineCount_;
}

const Tile& Board::tileAt(int col, int row) const {
    return tiles_[index(col, row)];
}

int Board::index(int col, int row) const {
    return row * columns_ + col;
}

bool Board::isInside(int col, int row) const {
    return col >= 0 && col < columns_ && row >= 0 && row < rows_;
}

void Board::clearBoard() {
    for (Tile& tile : tiles_) {
        tile.hasMine = false;
        tile.isRevealed = false;
        tile.isFlagged = false;
        tile.adjacentMines = 0;
    }
}

void Board::buildNeighborLists() {
    for (int row = 0; row < rows_; ++row) {
        for (int col = 0; col < columns_; ++col) {
            Tile& tile = tiles_[index(col, row)];
            tile.neighbors.clear();

            for (int yOffset = -1; yOffset <= 1; ++yOffset) {
                for (int xOffset = -1; xOffset <= 1; ++xOffset) {
                    if (xOffset == 0 && yOffset == 0) {
                        continue;
                    }

                    const int neighborCol = col + xOffset;
                    const int neighborRow = row + yOffset;
                    if (isInside(neighborCol, neighborRow)) {
                        tile.neighbors.push_back(index(neighborCol, neighborRow));
                    }
                }
            }
        }
    }
}

void Board::finalizeBoardState() {
    for (Tile& tile : tiles_) {
        tile.isRevealed = false;
        tile.isFlagged = false;
        tile.adjacentMines = 0;
        if (tile.hasMine) {
            continue;
        }

        for (const int neighborIndex : tile.neighbors) {
            if (tiles_[neighborIndex].hasMine) {
                ++tile.adjacentMines;
            }
        }
    }
}

int Board::flagCount() const {
    int count = 0;
    for (const Tile& tile : tiles_) {
        if (tile.isFlagged) {
            ++count;
        }
    }
    return count;
}
