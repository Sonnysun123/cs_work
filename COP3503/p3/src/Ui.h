#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureStore.h"

using namespace std;

const int TileSize = 32;
const int UiHeight = 88;
const int DigitWidth = 21;
const int DigitHeight = 32;

struct Button {
    sf::Sprite sprite;
    bool contains(const sf::Vector2i& point) const;
};

vector<int> toThreeDigits(int value);
void drawCounter(sf::RenderWindow& window, int value, float x, float y);
