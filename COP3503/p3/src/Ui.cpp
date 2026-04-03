#include "Ui.h"

#include <algorithm>

bool Button::contains(const sf::Vector2i& point) const {
    return sprite.getGlobalBounds().contains(static_cast<float>(point.x), static_cast<float>(point.y));
}

std::array<int, 3> toThreeDigits(int value) {
    const bool negative = value < 0;
    if (negative) {
        value = -value;
    }

    value = std::min(value, 999);
    std::array<int, 3> digits{
        (value / 100) % 10,
        (value / 10) % 10,
        value % 10,
    };

    if (negative) {
        digits[0] = 10;
    }

    return digits;
}

void drawCounter(sf::RenderWindow& window, const TextureStore& textures, int value, float x, float y) {
    sf::Sprite digitSprite(textures.get("digits"));
    const std::array<int, 3> digits = toThreeDigits(value);

    for (int i = 0; i < 3; ++i) {
        digitSprite.setTextureRect(sf::IntRect(digits[i] * kDigitWidth, 0, kDigitWidth, kDigitHeight));
        digitSprite.setPosition(x + static_cast<float>(i * kDigitWidth), y);
        window.draw(digitSprite);
    }
}
