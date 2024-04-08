#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.h"
#include <vector>
using namespace std;
#pragma once

class Player
{
private:
    sf::Texture texture;

    vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;

public:
    sf::Sprite sprite;

public:
    void initialize();
    void load();
    void update(Skeleton &);
    void draw(sf::RenderWindow &);
};