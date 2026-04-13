#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <stdexcept>
#include <string>
using namespace std;
class TextureStore {

    std::map<std::string, sf::Texture> _textures;
public:
    // Loads one texture from a file and stores it by name
    void load(const std::string& name, const std::string& path) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            throw std::runtime_error("Failed to load texture: " + path);
        }
        _textures[name] = texture;
    }

    // Returns a stored texture using its name
    const sf::Texture& get(const std::string& name) const {
        return _textures.at(name);
    }


};
