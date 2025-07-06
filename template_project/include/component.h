#pragma once
#include <SFML/Graphics.hpp>

class Component
{
public:
    virtual ~Component() = default;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
private:
};