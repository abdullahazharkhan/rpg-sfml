#include <SFML/Graphics.hpp>
#pragma once

class Skeleton
{
private:
    sf::Texture texture;

public:
    sf::Sprite sprite;

public:
    void initialize();
    void load();
    void update();
    void draw(sf::RenderWindow &);
};