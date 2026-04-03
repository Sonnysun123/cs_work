#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    bool loadAll();
    const sf::Texture& get(const std::string& key) const;

private:
    std::map<std::string, sf::Texture> textures;
    void loadTexture(const std::string& key, const std::string& relativePath);
};

#endif
