#include "Board.h"

#include <algorithm>
#include <fstream>
#include <queue>
#include <random>
#include <sstream>
#include <stdexcept>

Board::Board()
    : columns(25), rows(16), totalMines(50), flagsPlaced(0), debugMode(false), gameLost(false), gameWon(false) {
    createEmptyGrid();
    randomize();
}

bool Board::loadConfig(const std::string& configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        return false;
    }

    int newColumns = 0;
    int newRows = 0;
    int newMines = 0;
    file >> newColumns >> newRows >> newMines;

    if (!file || newColumns <= 0 || newRows <= 0 || newMines < 0 || newMines > newColumns * newRows) {
        return false;
    }

    columns = newColumns;
    rows = newRows;
    totalMines = newMines;
    createEmptyGrid();
    randomize();
    return true;
}

void Board::randomize() {
    clearBoardState(true);
    placeRandomMines(totalMines);
    recalculateAdjacency();
}

bool Board::loadFromBoardFile(const std::string& boardPath) {
    std::ifstream file(boardPath);
    if (!file.is_open()) {
        return false;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    if (static_cast<int>(lines.size()) != rows) {
        return false;
    }

    for (const std::string& currentLine : lines) {
        if (static_cast<int>(currentLine.size()) != columns) {
            return false;
        }
        for (char ch : currentLine) {
            if (ch != '0' && ch != '1') {
                return false;
            }
        }
    }

    clearBoardState(true);
    totalMines = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            Tile* tile = tileAt(r, c);
            tile->hasMine = (lines[r][c] == '1');
            if (tile->hasMine) {
                ++totalMines;
            }
        }
    }

    recalculateAdjacency();
    return true;
}

void Board::handleLeftClick(int pixelX, int pixelY) {
    if (containsPoint(getFaceBounds(), pixelX, pixelY)) {
        randomize();
        return;
    }

    if (containsPoint(getDebugBounds(), pixelX, pixelY)) {
        toggleDebug();
        return;
    }

    if (containsPoint(getTest1Bounds(), pixelX, pixelY)) {
        loadFromBoardFile("boards/testBoard1.brd");
        return;
    }

    if (containsPoint(getTest2Bounds(), pixelX, pixelY)) {
        loadFromBoardFile("boards/testBoard2.brd");
        return;
    }

    if (containsPoint(getTest3Bounds(), pixelX, pixelY)) {
        loadFromBoardFile("boards/testBoard3.brd");
        return;
    }

    if (gameLost || gameWon) {
        return;
    }

    Tile* clickedTile = tileFromPixel(pixelX, pixelY);
    if (clickedTile == nullptr || clickedTile->flagged || clickedTile->revealed) {
        return;
    }

    revealTile(*clickedTile);
    updateWinState();
}

void Board::handleRightClick(int pixelX, int pixelY) {
    if (gameLost || gameWon) {
        return;
    }

    Tile* clickedTile = tileFromPixel(pixelX, pixelY);
    if (clickedTile == nullptr || clickedTile->revealed) {
        return;
    }

    clickedTile->flagged = !clickedTile->flagged;
    flagsPlaced += clickedTile->flagged ? 1 : -1;
}

void Board::toggleDebug() {
    if (!gameWon) {
        debugMode = !debugMode;
    }
}

void Board::draw(sf::RenderWindow& window, const TextureManager& textures) const {
    for (const Tile& tile : tiles) {
        const int x = tile.col * kTileSize;
        const int y = tile.row * kTileSize;

        sf::Sprite base(tile.revealed ? textures.get("tile_revealed") : textures.get("tile_hidden"));
        base.setPosition(static_cast<float>(x), static_cast<float>(y));
        window.draw(base);

        if (tile.revealed) {
            if (tile.hasMine) {
                sf::Sprite mine(textures.get("mine"));
                mine.setPosition(static_cast<float>(x), static_cast<float>(y));
                window.draw(mine);
            } else if (tile.adjacentMines > 0) {
                sf::Sprite number(textures.get("number_" + std::to_string(tile.adjacentMines)));
                number.setPosition(static_cast<float>(x), static_cast<float>(y));
                window.draw(number);
            }
        }

        if (tile.flagged) {
            sf::Sprite flag(textures.get("flag"));
            flag.setPosition(static_cast<float>(x), static_cast<float>(y));
            window.draw(flag);
        }

        if (debugMode && tile.hasMine && !gameLost && !gameWon) {
            sf::Sprite mine(textures.get("mine"));
            mine.setPosition(static_cast<float>(x), static_cast<float>(y));
            window.draw(mine);
        }
    }

    drawCounter(window, textures);

    const sf::Texture& faceTexture = gameWon ? textures.get("face_win")
                                             : (gameLost ? textures.get("face_lose") : textures.get("face_happy"));
    drawButton(window, faceTexture, getFaceBounds().left, getFaceBounds().top);
    drawButton(window, textures.get("debug"), getDebugBounds().left, getDebugBounds().top);
    drawButton(window, textures.get("test_1"), getTest1Bounds().left, getTest1Bounds().top);
    drawButton(window, textures.get("test_2"), getTest2Bounds().left, getTest2Bounds().top);
    drawButton(window, textures.get("test_3"), getTest3Bounds().left, getTest3Bounds().top);
}

int Board::getWindowWidth() const {
    return columns * kTileSize;
}

int Board::getWindowHeight() const {
    return rows * kTileSize + kControlPanelHeight;
}

Tile* Board::tileAt(int rowValue, int colValue) {
    if (rowValue < 0 || rowValue >= rows || colValue < 0 || colValue >= columns) {
        return nullptr;
    }
    return &tiles[static_cast<std::size_t>(rowValue * columns + colValue)];
}

const Tile* Board::tileAt(int rowValue, int colValue) const {
    if (rowValue < 0 || rowValue >= rows || colValue < 0 || colValue >= columns) {
        return nullptr;
    }
    return &tiles[static_cast<std::size_t>(rowValue * columns + colValue)];
}

Tile* Board::tileFromPixel(int pixelX, int pixelY) {
    if (pixelX < 0 || pixelY < 0 || pixelX >= columns * kTileSize || pixelY >= rows * kTileSize) {
        return nullptr;
    }
    return tileAt(pixelY / kTileSize, pixelX / kTileSize);
}

const Tile* Board::tileFromPixel(int pixelX, int pixelY) const {
    if (pixelX < 0 || pixelY < 0 || pixelX >= columns * kTileSize || pixelY >= rows * kTileSize) {
        return nullptr;
    }
    return tileAt(pixelY / kTileSize, pixelX / kTileSize);
}

void Board::createEmptyGrid() {
    tiles.assign(static_cast<std::size_t>(rows * columns), Tile{});

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            Tile& tile = tiles[static_cast<std::size_t>(r * columns + c)];
            tile.row = r;
            tile.col = c;
            tile.neighbors.clear();
            tile.resetState();
        }
    }

    connectNeighbors();
    flagsPlaced = 0;
    debugMode = false;
    gameLost = false;
    gameWon = false;
}

void Board::connectNeighbors() {
    for (Tile& tile : tiles) {
        tile.neighbors.clear();
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                Tile* neighbor = tileAt(tile.row + dr, tile.col + dc);
                if (neighbor != nullptr) {
                    tile.neighbors.push_back(neighbor);
                }
            }
        }
    }
}

void Board::recalculateAdjacency() {
    for (Tile& tile : tiles) {
        tile.adjacentMines = 0;
        for (Tile* neighbor : tile.neighbors) {
            if (neighbor != nullptr && neighbor->hasMine) {
                ++tile.adjacentMines;
            }
        }
    }
}

void Board::clearBoardState(bool clearMines) {
    for (Tile& tile : tiles) {
        tile.revealed = false;
        tile.flagged = false;
        tile.adjacentMines = 0;
        if (clearMines) {
            tile.hasMine = false;
        }
    }

    flagsPlaced = 0;
    debugMode = false;
    gameLost = false;
    gameWon = false;
}

void Board::placeRandomMines(int mineCount) {
    std::vector<int> positions(static_cast<std::size_t>(rows * columns));
    for (int i = 0; i < rows * columns; ++i) {
        positions[static_cast<std::size_t>(i)] = i;
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(positions.begin(), positions.end(), generator);

    for (int i = 0; i < mineCount; ++i) {
        tiles[static_cast<std::size_t>(positions[static_cast<std::size_t>(i)])].hasMine = true;
    }
}

void Board::revealTile(Tile& startTile) {
    if (startTile.flagged || startTile.revealed) {
        return;
    }

    if (startTile.hasMine) {
        startTile.revealed = true;
        gameLost = true;
        revealAllMines();
        return;
    }

    std::queue<Tile*> frontier;
    frontier.push(&startTile);

    while (!frontier.empty()) {
        Tile* current = frontier.front();
        frontier.pop();

        if (current == nullptr || current->revealed || current->flagged) {
            continue;
        }

        current->revealed = true;

        if (current->adjacentMines != 0) {
            continue;
        }

        for (Tile* neighbor : current->neighbors) {
            if (neighbor == nullptr || neighbor->revealed || neighbor->flagged || neighbor->hasMine) {
                continue;
            }
            frontier.push(neighbor);
        }
    }
}

void Board::revealAllMines() {
    for (Tile& tile : tiles) {
        if (tile.hasMine) {
            tile.revealed = true;
        }
    }
}

void Board::updateWinState() {
    if (gameLost) {
        return;
    }

    if (countRevealedSafeTiles() == totalSafeTiles()) {
        gameWon = true;
        debugMode = false;
        markAllMinesFlagged();
    }
}

void Board::markAllMinesFlagged() {
    for (Tile& tile : tiles) {
        if (tile.hasMine) {
            tile.flagged = true;
        }
    }
    flagsPlaced = totalMines;
}

int Board::countRevealedSafeTiles() const {
    int revealedSafe = 0;
    for (const Tile& tile : tiles) {
        if (tile.revealed && !tile.hasMine) {
            ++revealedSafe;
        }
    }
    return revealedSafe;
}

int Board::totalSafeTiles() const {
    return rows * columns - totalMines;
}

sf::IntRect Board::getFaceBounds() const {
    const int x = (columns * kTileSize / 2) - (kButtonSize / 2);
    const int y = rows * kTileSize + 16;
    return {x, y, kButtonSize, kButtonSize};
}

sf::IntRect Board::getDebugBounds() const {
    const int x = (columns * kTileSize) - 304;
    const int y = rows * kTileSize + 16;
    return {x, y, kButtonSize, kButtonSize};
}

sf::IntRect Board::getTest1Bounds() const {
    const int x = (columns * kTileSize) - 240;
    const int y = rows * kTileSize + 16;
    return {x, y, kButtonSize, kButtonSize};
}

sf::IntRect Board::getTest2Bounds() const {
    const int x = (columns * kTileSize) - 176;
    const int y = rows * kTileSize + 16;
    return {x, y, kButtonSize, kButtonSize};
}

sf::IntRect Board::getTest3Bounds() const {
    const int x = (columns * kTileSize) - 112;
    const int y = rows * kTileSize + 16;
    return {x, y, kButtonSize, kButtonSize};
}

bool Board::containsPoint(const sf::IntRect& rect, int x, int y) const {
    return rect.contains(x, y);
}

void Board::drawCounter(sf::RenderWindow& window, const TextureManager& textures) const {
    int displayValue = totalMines - flagsPlaced;
    const bool isNegative = displayValue < 0;
    int absoluteValue = std::abs(displayValue);

    int hundreds = (absoluteValue / 100) % 10;
    int tens = (absoluteValue / 10) % 10;
    int ones = absoluteValue % 10;

    const sf::Texture& digitsTexture = textures.get("digits");
    const int y = rows * kTileSize + 16;

    auto drawDigit = [&](int digitIndex, int x) {
        sf::Sprite digit(digitsTexture);
        digit.setTextureRect(sf::IntRect(digitIndex * kDigitWidth, 0, kDigitWidth, kDigitHeight));
        digit.setPosition(static_cast<float>(x), static_cast<float>(y));
        window.draw(digit);
    };

    if (isNegative) {
        drawDigit(10, 0);
    } else {
        drawDigit(0, 0);
    }

    drawDigit(hundreds, kDigitWidth);
    drawDigit(tens, kDigitWidth * 2);
    drawDigit(ones, kDigitWidth * 3);
}

void Board::drawButton(sf::RenderWindow& window, const sf::Texture& texture, int x, int y) const {
    sf::Sprite sprite(texture);
    sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    window.draw(sprite);
}
