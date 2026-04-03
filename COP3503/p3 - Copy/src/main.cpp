#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdexcept>

#include "Board.h"
#include "TextureManager.h"

int main() {
    try {
        TextureManager textures;
        textures.loadAll();

        Board board;
        if (!board.loadConfig("boards/config.cfg")) {
            std::cerr << "Warning: failed to load boards/config.cfg, using default 25x16 with 50 mines.\n";
        }

        sf::RenderWindow window(
            sf::VideoMode(static_cast<unsigned int>(board.getWindowWidth()), static_cast<unsigned int>(board.getWindowHeight())),
            "Minesweeper",
            sf::Style::Titlebar | sf::Style::Close
        );
        window.setFramerateLimit(60);

        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    const int mouseX = event.mouseButton.x;
                    const int mouseY = event.mouseButton.y;

                    if (event.mouseButton.button == sf::Mouse::Left) {
                        board.handleLeftClick(mouseX, mouseY);
                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        board.handleRightClick(mouseX, mouseY);
                    }

                    if (window.getSize().x != static_cast<unsigned int>(board.getWindowWidth()) ||
                        window.getSize().y != static_cast<unsigned int>(board.getWindowHeight())) {
                        window.create(
                            sf::VideoMode(static_cast<unsigned int>(board.getWindowWidth()), static_cast<unsigned int>(board.getWindowHeight())),
                            "Minesweeper",
                            sf::Style::Titlebar | sf::Style::Close
                        );
                        window.setFramerateLimit(60);
                    }
                }
            }

            window.clear(sf::Color::White);
            board.draw(window, textures);
            window.display();
        }
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    return 0;
}
