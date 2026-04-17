#include "Test.h"
#include <SFML/Graphics/Text.hpp>
#include <unordered_map>

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName) {
    string path = "image/";
    path += fileName + ".png";
}
