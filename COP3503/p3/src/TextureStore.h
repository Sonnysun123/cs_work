#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

using namespace std;

class TextureStore {
    static unordered_map<string, sf::Texture> textures;
    static void load(const string& name);

public:
    static sf::Texture& get(const string& name);
};
