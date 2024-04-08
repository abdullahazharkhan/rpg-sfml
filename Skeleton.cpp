#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include <iostream>
using namespace std;

void Skeleton::initialize()
{
}

void Skeleton::load()
{
    if (texture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
    {
        cout << "skeleton image loaded" << endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(400, 200));
        int XIndex = 0, YIndex = 2;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }
    else
        cout << "skeleton image failed to load" << endl;
}

void Skeleton::update()
{
}

void Skeleton::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
