#include "player.h"
#include "game.h"
#include "explosion.h"
#include <iostream>
#include <memory>

Player::Player() : m_key_pressed(false) { std::cout << "Player Initialized\n"; }

void Player::update(float delta_time)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!m_key_pressed)
        {
            m_key_pressed = true;

            std::cout << "SPACE is PRESSED" << std::endl;
            
            Explosion* bomb = new Explosion();
        
            //bomb->add_component(new SpriteRenderer("resources/sprites/explosion.png"));

            Game::get_instance().add_gameobject(bomb);
        }
    }
    else
    {
        m_key_pressed = false;
    }
}


