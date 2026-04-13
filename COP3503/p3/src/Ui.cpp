#include "Ui.h"
using namespace std;

void LoadAllTextures(TextureStore& textures) {
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
        textures.load("number_" + to_string(i), "images/number_" + to_string(i) + ".png");
    }
}

bool Button::contains(const sf::Vector2i& point) const {
    return sprite.getGlobalBounds().contains(static_cast<float>(point.x), static_cast<float>(point.y));
}

vector<int> toThreeDigits(int value) {
    bool negative = false;
    if (value < 0) {
        negative = true;
    }
    if (negative) {
        value = -value;
    }
    value = min(value, 999);
    int hundredsDigit = value / 100;
    int tensDigit = (value / 10) % 10;
    int onesDigit = value % 10;

    vector<int> digits;
    digits.push_back(hundredsDigit);
    digits.push_back(tensDigit);
    digits.push_back(onesDigit);
    if (negative) {
        digits[0] = 10;
    }

    return digits;
}

void drawCounter(sf::RenderWindow& window, const TextureStore& textures, int value, float x, float y) {
    sf::Sprite digitSprite(textures.get("digits"));
    vector<int> digits = toThreeDigits(value);
    for (int i = 0; i < 3; ++i) {
        digitSprite.setTextureRect(sf::IntRect(digits[i] * DigitWidth, 0, DigitWidth, DigitHeight));
        digitSprite.setPosition(x + static_cast<float>(i * DigitWidth), y);
        window.draw(digitSprite);
    }
}
