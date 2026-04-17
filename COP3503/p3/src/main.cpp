#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Board.h"
#include "Config.h"
#include "TextureManager.h"
#include "Ui.h"
using namespace std;

void updateWinState(Board& board, bool& gameWon);
void resetRandomBoard(Board& board, const GameConfig& config, bool& debugMode, bool& gameLost, bool& gameWon);
void loadBoard(Board& board, const string& path, bool& debugMode, bool& gameLost, bool& gameWon);
void setButtonTextures(Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button);
void setButtonPositions(Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button, int windowWidth, int rowCount);
void drawBoard(sf::RenderWindow& window, const Board& board, const GameConfig& config, bool debugMode, bool gameLost, bool gameWon);
void drawGame(sf::RenderWindow& window, const Board& board, const GameConfig& config, Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button, bool debugMode, bool gameLost, bool gameWon);

int main() {
    GameConfig config;
    if (!loadConfig("boards/config.cfg", config)) {
        cout << "config.cfg not loaded" << endl;
        return 0;
    }
    cout << "Loaded config: " << config.columns << " columns, " << config.rows << " rows, " << config.mines << " mines" << endl;

    const int windowWidth = config.columns * TileSize;
    const int windowHeight = config.rows * TileSize + UiHeight;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Minesweeper");

    Board board(config.columns, config.rows, config.mines);
    bool debugMode = false;
    bool gameLost = false;
    bool gameWon = false;
    Button face;
    Button debugButton;
    Button test1Button;
    Button test2Button;
    Button test3Button;

    setButtonTextures(face, debugButton, test1Button, test2Button, test3Button);
    setButtonPositions(face, debugButton, test1Button, test2Button, test3Button, windowWidth, config.rows);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (!gameLost && !gameWon) {
                    updateWinState(board, gameWon);
                }

                const sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                const int col = mousePosition.x / TileSize;
                const int row = mousePosition.y / TileSize;

                bool clickIsInsideBoard = true;
                if (row >= config.rows) {
                    clickIsInsideBoard = false;
                }

                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (face.contains(mousePosition)) {
                        cout << "Reset button clicked" << endl;
                        resetRandomBoard(board, config, debugMode, gameLost, gameWon);
                        continue;
                    }

                    if (debugButton.contains(mousePosition)) {
                        if (!gameLost && !gameWon) {
                            if (debugMode) {
                                debugMode = false;
                            } else {
                                debugMode = true;
                            }

                            cout << "Debug mode state: " << debugMode << endl;
                        }
                        continue;
                    }

                    if (test1Button.contains(mousePosition)) {
                        cout << "Loading test board 1" << endl;
                        loadBoard(board, "boards/testboard1.brd", debugMode, gameLost, gameWon);
                        continue;
                    }

                    if (test2Button.contains(mousePosition)) {
                        cout << "Loading test board 2" << endl;
                        loadBoard(board, "boards/testboard2.brd", debugMode, gameLost, gameWon);
                        continue;
                    }

                    if (test3Button.contains(mousePosition)) {
                        cout << "Loading test board 3" << endl;
                        loadBoard(board, "boards/testboard3.brd", debugMode, gameLost, gameWon);
                        continue;
                    }

                    if (clickIsInsideBoard && !gameLost && !gameWon) {
                        cout << "Left click at row " << row << ", col " << col << endl;
                        bool hitMine = board.reveal(col, row);
                        if (hitMine) {
                            gameLost = true;
                            cout << "Hit a mine, game lost." << endl;
                        } else {
                            updateWinState(board, gameWon);
                        }
                    }
                }

                if (event.mouseButton.button == sf::Mouse::Right) {
                    if (clickIsInsideBoard && !gameLost && !gameWon) {
                        cout << "Right click at row " << row << ", col " << col << endl;
                        board.toggleFlag(col, row);
                    }
                }
            }
        }
        drawGame(window, board, config, face, debugButton, test1Button, test2Button, test3Button,
                 debugMode, gameLost, gameWon);
    }

    TextureManager::Clear();

    return 0;
}

void updateWinState(Board& board, bool& gameWon) {
    if (!gameWon && board.hasWon()) {
        gameWon = true;
        board.autoFlagAllMines();
        cout << "All safe tiles revealed, game won." << endl;
    }
}

void resetRandomBoard(Board& board, const GameConfig& config, bool& debugMode, bool& gameLost, bool& gameWon) {
    board = Board(config.columns, config.rows, config.mines);
    debugMode = false;
    gameLost = false;
    gameWon = false;
}

void loadBoard(Board& board, const string& path, bool& debugMode, bool& gameLost, bool& gameWon) {
    if (board.loadFromFile(path)) {
        debugMode = false;
        gameLost = false;
        gameWon = false;
    }
}

void setButtonTextures(Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button) {
    face.sprite.setTexture(TextureManager::GetTexture("face_happy"));
    debugButton.sprite.setTexture(TextureManager::GetTexture("debug"));
    test1Button.sprite.setTexture(TextureManager::GetTexture("test_1"));
    test2Button.sprite.setTexture(TextureManager::GetTexture("test_2"));
    test3Button.sprite.setTexture(TextureManager::GetTexture("test_3"));
}

void setButtonPositions(Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button, int windowWidth, int rowCount) {
    face.sprite.setPosition((windowWidth / 2.0f) - 32.0f, static_cast<float>(rowCount * TileSize));
    debugButton.sprite.setPosition(static_cast<float>(windowWidth - 304), static_cast<float>(rowCount * TileSize));
    test1Button.sprite.setPosition(static_cast<float>(windowWidth - 240), static_cast<float>(rowCount * TileSize));
    test2Button.sprite.setPosition(static_cast<float>(windowWidth - 176), static_cast<float>(rowCount * TileSize));
    test3Button.sprite.setPosition(static_cast<float>(windowWidth - 112), static_cast<float>(rowCount * TileSize));
}

void drawBoard(sf::RenderWindow& window, const Board& board, const GameConfig& config, bool debugMode, bool gameLost, bool gameWon) {
    for (int row = 0; row < config.rows; row++) {
        for (int col = 0; col < config.columns; ++col) {
            const Tile& tile = board.tileAt(col, row);
            const float drawX = static_cast<float>(col * TileSize);
            const float drawY = static_cast<float>(row * TileSize);

            bool shouldUseRevealedTile = false;
            if (tile.isRevealed) {
                shouldUseRevealedTile = true;
            }
            if (gameLost && tile.hasMine && !tile.isFlagged) {
                shouldUseRevealedTile = true;
            }

            sf::Sprite baseSprite(TextureManager::GetTexture("tile_hidden"));
            if (shouldUseRevealedTile) {
                baseSprite.setTexture(TextureManager::GetTexture("tile_revealed"), true);
            }
            baseSprite.setPosition(drawX, drawY);
            window.draw(baseSprite);

            bool showMine = false;
            if (tile.hasMine && !tile.isFlagged) {
                if (gameLost) {
                    showMine = true;
                }
                if (debugMode && !gameWon) {
                    showMine = true;
                }
            }

            if (tile.isRevealed && !tile.hasMine && tile.adjacentMines > 0) {
                sf::Sprite numberSprite(TextureManager::GetTexture("number_" + to_string(tile.adjacentMines)));
                numberSprite.setPosition(drawX, drawY);
                window.draw(numberSprite);
            }

            if (showMine) {
                sf::Sprite mineSprite(TextureManager::GetTexture("mine"));
                mineSprite.setPosition(drawX, drawY);
                window.draw(mineSprite);
            }

            if (tile.isFlagged && !tile.isRevealed) {
                sf::Sprite flagSprite(TextureManager::GetTexture("flag"));
                flagSprite.setPosition(drawX, drawY);
                window.draw(flagSprite);
            }
        }
    }
}

void drawGame(sf::RenderWindow& window, const Board& board, const GameConfig& config, Button& face, Button& debugButton, Button& test1Button, Button& test2Button, Button& test3Button, bool debugMode, bool gameLost, bool gameWon) {
    if (gameWon) {
        face.sprite.setTexture(TextureManager::GetTexture("face_win"), true);
    } else if (gameLost) {
        face.sprite.setTexture(TextureManager::GetTexture("face_lose"), true);
    } else {
        face.sprite.setTexture(TextureManager::GetTexture("face_happy"), true);
    }

    window.clear(sf::Color::White);
    drawBoard(window, board, config, debugMode, gameLost, gameWon);
    drawCounter(window, board.minesRemaining(), 0.0f, static_cast<float>(config.rows * TileSize));
    window.draw(face.sprite);
    window.draw(debugButton.sprite);
    window.draw(test1Button.sprite);
    window.draw(test2Button.sprite);
    window.draw(test3Button.sprite);
    window.display();
}
