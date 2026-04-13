#include <stdexcept>
#include "TextureStore.h"

map<string, sf::Texture> TextureStore::textures;

void TextureStore::load(const string& name) {
    string path = "images/";
    path += name + ".png";
    // if (!textures[name].loadFromFile(path)) {
    //     throw runtime_error("Failed to load texture: " + path);
    // }
}

sf::Texture& TextureStore::get(const string& name) {
    if (textures.find(name) == textures.end()) {
        load(name);
    }
    return textures[name];
}