#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureStore.h"

const int TileSize = 32;
const int UiHeight = 88;
const int DigitWidth = 21;
const int DigitHeight = 32;

// Loads every texture file the game uses into the texture store
void LoadAllTextures(TextureStore& textures);

struct Button {
    sf::Sprite sprite;
    // Checks whether a mouse position is inside this button sprite
    bool contains(const sf::Vector2i& point) const;
};

// Breaks one number into three digit values for the counter display
std::vector<int> toThreeDigits(int value);
// Draws the counter at the screen position
void drawCounter(sf::RenderWindow& window, const TextureStore& textures, int value, float x, float y);
