#include "TextureManager.h"

#include <stdexcept>

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string textureName) {
    string path = "images/";
    path += textureName + ".png";

    if (!textures[textureName].loadFromFile(path)) {
        throw runtime_error("Failed to load texture: " + path);
    }
}

sf::Texture& TextureManager::GetTexture(string textureName) {
    if (textures.find(textureName) == textures.end()) {
        LoadTexture(textureName);
    }

    return textures[textureName];
}

void TextureManager::Clear() {
    textures.clear();
}
