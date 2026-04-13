#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <stdexcept>
#include <string>
using namespace std;

class TextureStore {

    map<string, sf::Texture> _textures;
public:
    // Loads one texture from a file and stores it by name
    void load(const string& name, const string& path) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            throw runtime_error("Failed to load texture: " + path);
        }
        _textures[name] = texture;
    }

    // Returns a stored texture using its name
    const sf::Texture& get(const string& name) const {
        return _textures.at(name);
    }


};
