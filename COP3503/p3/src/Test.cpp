#include "Test.h"
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName) {
    string path = "image/";
    path += fileName + ".png";

    textures[fileName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string texturename) {
    if (textures.find(texturename) == textures.end())
        LoadTexture(texturename);

    return textures[texturename];
}

void TextureManager::Clear() {
    textures.clear(); //get rid of all stored objects
}