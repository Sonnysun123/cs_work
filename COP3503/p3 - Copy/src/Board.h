#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "TextureManager.h"
#include "Tile.h"

class Board {
public:
    Board();

    bool loadConfig(const std::string& configPath);
    void randomize();
    bool loadFromBoardFile(const std::string& boardPath);

    void handleLeftClick(int pixelX, int pixelY);
    void handleRightClick(int pixelX, int pixelY);
    void toggleDebug();

    void draw(sf::RenderWindow& window, const TextureManager& textures) const;

    int getWindowWidth() const;
    int getWindowHeight() const;

private:
    static constexpr int kTileSize = 32;
    static constexpr int kControlPanelHeight = 100;
    static constexpr int kButtonSize = 64;
    static constexpr int kDigitWidth = 21;
    static constexpr int kDigitHeight = 32;

    int columns;
    int rows;
    int totalMines;
    int flagsPlaced;
    bool debugMode;
    bool gameLost;
    bool gameWon;
    std::vector<Tile> tiles;

    Tile* tileAt(int row, int col);
    const Tile* tileAt(int row, int col) const;
    Tile* tileFromPixel(int pixelX, int pixelY);
    const Tile* tileFromPixel(int pixelX, int pixelY) const;

    void createEmptyGrid();
    void connectNeighbors();
    void recalculateAdjacency();
    void clearBoardState(bool clearMines);
    void placeRandomMines(int mineCount);
    void revealTile(Tile& tile);
    void revealAllMines();
    void updateWinState();
    void markAllMinesFlagged();
    int countRevealedSafeTiles() const;
    int totalSafeTiles() const;

    sf::IntRect getFaceBounds() const;
    sf::IntRect getDebugBounds() const;
    sf::IntRect getTest1Bounds() const;
    sf::IntRect getTest2Bounds() const;
    sf::IntRect getTest3Bounds() const;
    bool containsPoint(const sf::IntRect& rect, int x, int y) const;

    void drawCounter(sf::RenderWindow& window, const TextureManager& textures) const;
    void drawButton(sf::RenderWindow& window, const sf::Texture& texture, int x, int y) const;
};

#endif
