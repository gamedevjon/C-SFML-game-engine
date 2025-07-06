#pragma once
#include <vector>
#include <memory>               // For std::unique_ptr
#include <SFML/Graphics.hpp>    // Needed for sf::RenderWindow
#include "component.h"

class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();
    
    virtual void update(float delta_time) = 0;
    void update_components();
    void add_component(Component* component);
    virtual void draw(sf::RenderWindow& window);
    void destroy();
    bool check_delete_flag_status() const;

protected:
    std::vector<Component*> m_components;
    bool m_delete_flag = false;
};