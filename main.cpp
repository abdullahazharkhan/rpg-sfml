#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

#include "Player.cpp"
#include "Skeleton.cpp"
using namespace std;

int main()
{
    // ------------------------------------ INITIALIZATION ------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    
    Player player;
    Skeleton skeleton;

    player.initialize();
    skeleton.initialize();
    // ------------------------------------ INITIALIZATION ------------------------------------


    // ----------------------------------------- LOAD -----------------------------------------
    player.load();
    skeleton.load();
    // ----------------------------------------- LOAD -----------------------------------------

    // main game loop
    while (window.isOpen())
    {
        // ------------------------------------ UPDATE ------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.update();
        player.update(skeleton);

        // ------------------------------------ UPDATE ------------------------------------

        // ------------------------------------ DRAW ------------------------------------
        window.clear();
        player.draw(window);
        skeleton.draw(window);
        window.display();
        // ------------------------------------ DRAW ------------------------------------
    }

    return 0;
}