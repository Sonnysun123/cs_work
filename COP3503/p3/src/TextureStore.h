#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <stdexcept>
#include <string>

class TextureStore {
public:
    void load(const std::string& name, const std::string& path) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            throw std::runtime_error("Failed to load texture: " + path);
        }
        textures_.emplace(name, std::move(texture));
    }

    const sf::Texture& get(const std::string& name) const {
        return textures_.at(name);
    }

private:
    std::map<std::string, sf::Texture> textures_;
};
