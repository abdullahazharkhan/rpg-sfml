#include "Player.h"
#include "Math.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void Player::initialize()
{
}

void Player::load()
{
    if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        cout << "Player image loaded" << endl;
        sprite.setTexture(texture);
        int XIndex = 0, YIndex = 0;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(1050, 400));
    }
    else
        cout << "Player image failed to load" << endl;
}

void Player::update(Skeleton &skeleton)
{
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.setPosition(position - sf::Vector2f(0, 0.5));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.setPosition(position + sf::Vector2f(0.5, 0));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.setPosition(position + sf::Vector2f(0, 0.5));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.setPosition(position - sf::Vector2f(0.5, 0));
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));

        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); ++i)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[bullets.size() - 1].getPosition();
        bulletDirection = Math::normalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); ++i)
    {
        window.draw(bullets[i]);
    }
}
