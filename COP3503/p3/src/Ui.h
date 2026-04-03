#pragma once

#include <SFML/Graphics.hpp>

#include <array>

#include "TextureStore.h"

constexpr int kTileSize = 32;
constexpr int kUiHeight = 88;
constexpr int kDigitWidth = 21;
constexpr int kDigitHeight = 32;

struct Button {
    sf::Sprite sprite;

    bool contains(const sf::Vector2i& point) const;
};

std::array<int, 3> toThreeDigits(int value);
void drawCounter(sf::RenderWindow& window, const TextureStore& textures, int value, float x, float y);
