#include <SFML/Graphics.hpp>

#include <string>

#include "Board.h"
#include "Config.h"
#include "TextureStore.h"
#include "Ui.h"

int main() {
    GameConfig config;
    loadConfig("boards/config.cfg", config);

    TextureStore textures;
    textures.load("debug", "images/debug.png");
    textures.load("digits", "images/digits.png");
    textures.load("face_happy", "images/face_happy.png");
    textures.load("face_lose", "images/face_lose.png");
    textures.load("face_win", "images/face_win.png");
    textures.load("flag", "images/flag.png");
    textures.load("mine", "images/mine.png");
    textures.load("tile_hidden", "images/tile_hidden.png");
    textures.load("tile_revealed", "images/tile_revealed.png");
    textures.load("test_1", "images/test_1.png");
    textures.load("test_2", "images/test_2.png");
    textures.load("test_3", "images/test_3.png");
    for (int i = 1; i <= 8; ++i) {
        textures.load("number_" + std::to_string(i), "images/number_" + std::to_string(i) + ".png");
    }

    const int windowWidth = config.columns * kTileSize;
    const int windowHeight = config.rows * kTileSize + kUiHeight;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Minesweeper");
    window.setFramerateLimit(60);

    Board board(config.columns, config.rows, config.mines);
    bool debugMode = false;
    bool gameLost = false;
    bool gameWon = false;

    Button face;
    Button debugButton;
    Button test1Button;
    Button test2Button;
    Button test3Button;

    face.sprite.setTexture(textures.get("face_happy"));
    debugButton.sprite.setTexture(textures.get("debug"));
    test1Button.sprite.setTexture(textures.get("test_1"));
    test2Button.sprite.setTexture(textures.get("test_2"));
    test3Button.sprite.setTexture(textures.get("test_3"));

    face.sprite.setPosition((windowWidth / 2.0f) - 32.0f, static_cast<float>(config.rows * kTileSize));
    debugButton.sprite.setPosition(static_cast<float>(windowWidth - 304), static_cast<float>(config.rows * kTileSize));
    test1Button.sprite.setPosition(static_cast<float>(windowWidth - 240), static_cast<float>(config.rows * kTileSize));
    test2Button.sprite.setPosition(static_cast<float>(windowWidth - 176), static_cast<float>(config.rows * kTileSize));
    test3Button.sprite.setPosition(static_cast<float>(windowWidth - 112), static_cast<float>(config.rows * kTileSize));

    const auto resetRandomBoard = [&]() {
        board = Board(config.columns, config.rows, config.mines);
        debugMode = false;
        gameLost = false;
        gameWon = false;
    };

    const auto loadBoard = [&](const std::string& path) {
        if (board.loadFromFile(path)) {
            debugMode = false;
            gameLost = false;
            gameWon = false;
        }
    };

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type != sf::Event::MouseButtonPressed) {
                continue;
            }

            const sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            const int col = mousePosition.x / kTileSize;
            const int row = mousePosition.y / kTileSize;

            if (event.mouseButton.button == sf::Mouse::Left) {
                if (face.contains(mousePosition)) {
                    resetRandomBoard();
                    continue;
                }
                if (debugButton.contains(mousePosition)) {
                    debugMode = !debugMode;
                    continue;
                }
                if (test1Button.contains(mousePosition)) {
                    loadBoard("boards/testboard1.brd");
                    continue;
                }
                if (test2Button.contains(mousePosition)) {
                    loadBoard("boards/testboard2.brd");
                    continue;
                }
                if (test3Button.contains(mousePosition)) {
                    loadBoard("boards/testboard3.brd");
                    continue;
                }

                if (gameLost || gameWon || row >= config.rows) {
                    continue;
                }

                const bool hitMine = board.reveal(col, row);
                if (hitMine) {
                    gameLost = true;
                } else if (board.hasWon()) {
                    gameWon = true;
                    board.autoFlagAllMines();
                }
            }

            if (event.mouseButton.button == sf::Mouse::Right) {
                if (gameLost || gameWon || row >= config.rows) {
                    continue;
                }
                board.toggleFlag(col, row);
                if (board.hasWon()) {
                    gameWon = true;
                    board.autoFlagAllMines();
                }
            }
        }

        if (gameWon) {
            face.sprite.setTexture(textures.get("face_win"), true);
        } else if (gameLost) {
            face.sprite.setTexture(textures.get("face_lose"), true);
        } else {
            face.sprite.setTexture(textures.get("face_happy"), true);
        }

        window.clear(sf::Color::White);

        for (int row = 0; row < config.rows; ++row) {
            for (int col = 0; col < config.columns; ++col) {
                const Tile& tile = board.tileAt(col, row);
                const float drawX = static_cast<float>(col * kTileSize);
                const float drawY = static_cast<float>(row * kTileSize);

                sf::Sprite baseSprite(tile.isRevealed || (gameLost && tile.hasMine && !tile.isFlagged)
                                          ? textures.get("tile_revealed")
                                          : textures.get("tile_hidden"));
                baseSprite.setPosition(drawX, drawY);
                window.draw(baseSprite);

                const bool showMine = tile.hasMine && !tile.isFlagged && (gameLost || (debugMode && !gameWon));
                if (tile.isRevealed && !tile.hasMine && tile.adjacentMines > 0) {
                    sf::Sprite numberSprite(textures.get("number_" + std::to_string(tile.adjacentMines)));
                    numberSprite.setPosition(drawX, drawY);
                    window.draw(numberSprite);
                }

                if (showMine) {
                    sf::Sprite mineSprite(textures.get("mine"));
                    mineSprite.setPosition(drawX, drawY);
                    window.draw(mineSprite);
                }

                if (tile.isFlagged && !tile.isRevealed) {
                    sf::Sprite flagSprite(textures.get("flag"));
                    flagSprite.setPosition(drawX, drawY);
                    window.draw(flagSprite);
                }
            }
        }

        drawCounter(window, textures, board.minesRemaining(), 0.0f, static_cast<float>(config.rows * kTileSize));
        window.draw(face.sprite);
        window.draw(debugButton.sprite);
        window.draw(test1Button.sprite);
        window.draw(test2Button.sprite);
        window.draw(test3Button.sprite);

        window.display();
    }

    return 0;
}
