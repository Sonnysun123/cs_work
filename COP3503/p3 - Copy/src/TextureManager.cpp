#include "TextureManager.h"

#include <stdexcept>

bool TextureManager::loadAll() {
    loadTexture("tile_hidden", "images/tile_hidden.png");
    loadTexture("tile_revealed", "images/tile_revealed.png");
    loadTexture("mine", "images/mine.png");
    loadTexture("flag", "images/flag.png");
    loadTexture("face_happy", "images/face_happy.png");
    loadTexture("face_win", "images/face_win.png");
    loadTexture("face_lose", "images/face_lose.png");
    loadTexture("debug", "images/debug.png");
    loadTexture("test_1", "images/test_1.png");
    loadTexture("test_2", "images/test_2.png");
    loadTexture("test_3", "images/test_3.png");
    loadTexture("digits", "images/digits.png");

    for (int i = 1; i <= 8; ++i) {
        loadTexture("number_" + std::to_string(i), "images/number_" + std::to_string(i) + ".png");
    }

    return true;
}

const sf::Texture& TextureManager::get(const std::string& key) const {
    auto it = textures.find(key);
    if (it == textures.end()) {
        throw std::runtime_error("Missing texture key: " + key);
    }
    return it->second;
}

void TextureManager::loadTexture(const std::string& key, const std::string& relativePath) {
    sf::Texture texture;
    if (!texture.loadFromFile(relativePath)) {
        throw std::runtime_error("Failed to load texture: " + relativePath);
    }
    textures.emplace(key, std::move(texture));
}
