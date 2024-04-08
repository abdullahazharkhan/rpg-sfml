#include "Math.h"
#include <SFML/Graphics.hpp>

sf::Vector2f Math::normalizeVector(sf::Vector2f vector)
{
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}