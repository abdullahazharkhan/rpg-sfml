#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    // ------------------------------------ INITIALIZATION ------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    // ------------------------------------ INITIALIZATION ------------------------------------

    // ------------------------------------ LOAD ------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
    {
        cout << "Player image loaded" << endl;
        playerSprite.setTexture(playerTexture);
        int XIndex = 7, YIndex = 2;
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else
    {
        cout << "Player image failed to load" << endl;
    }
    // ------------------------------------ LOAD ------------------------------------

    // main game loop
    while (window.isOpen())
    {
        // ------------------------------------ UPDATE ------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            /* bad code, takes time to register key press
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::W) {
                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position - sf::Vector2f(0, 10));
                } else if(event.key.code == sf::Keyboard::D) {
                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position + sf::Vector2f(10, 0));
                } else if(event.key.code == sf::Keyboard::S) {
                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position + sf::Vector2f(0, 10));
                } else if(event.key.code == sf::Keyboard::A) {
                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position - sf::Vector2f(10, 0));
                }
            }
            */
        }

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            playerSprite.setPosition(position - sf::Vector2f(0, 0.1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerSprite.setPosition(position + sf::Vector2f(0.1, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, 0.1));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerSprite.setPosition(position - sf::Vector2f(0.1, 0));
        }
        // ------------------------------------ UPDATE ------------------------------------

        // ------------------------------------ DRAW ------------------------------------
        window.clear();
        window.draw(playerSprite);
        window.display();
        // ------------------------------------ DRAW ------------------------------------
    }

    return 0;
}