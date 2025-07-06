#include "gameobject.h"
#include <iostream>
#include "sprite_renderer.h"

Gameobject::Gameobject() : m_delete_flag(false) {}

void Gameobject::update_components()
{
    for (auto& component : m_components)
    {
        if (component)
        {
            component->update();
        }
    }
}

void Gameobject::add_component(Component* component)
{
   
      m_components.push_back(component);
    
}

void Gameobject::draw(sf::RenderWindow& window)
{
   
    for(auto& component : m_components)
    {
        if (component)
            component->draw(window);
    }
}

void Gameobject::destroy()
{
    m_delete_flag = true;
}

bool Gameobject::check_delete_flag_status() const
{
    return m_delete_flag;
}

Gameobject::~Gameobject()
{
    for (Component* comp : m_components)
    {
        delete comp;
    }
    m_components.clear();
}