#include "Ui.h"
using namespace std;

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

void drawCounter(sf::RenderWindow& window, int value, float x, float y) {
    sf::Sprite digitSprite(TextureManager::GetTexture("digits"));
    vector<int> digits = toThreeDigits(value);
    for (int i = 0; i < 3; ++i) {
        digitSprite.setTextureRect(sf::IntRect(digits[i] * DigitWidth, 0, DigitWidth, DigitHeight));
        digitSprite.setPosition(x + static_cast<float>(i * DigitWidth), y);
        window.draw(digitSprite);
    }
}
