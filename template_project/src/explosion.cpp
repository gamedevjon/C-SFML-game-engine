#include "explosion.h"
#include "sprite_renderer.h" // make sure this is included so SpriteRenderer is known
#include <iostream>
#include <memory> // required for std::make_unique
#include "game.h"

Explosion::Explosion() : m_life_time(0), m_time_eslapsed(0)
{
    std::cout << "Exploision Initiated\n";
    m_life_time = 5.0f;
    m_time_eslapsed = 0.f;
    SpriteRenderer* sprite = new SpriteRenderer("resources/sprites/explosion.png");
    

    //configure the sprite
    m_frame_width = 512;
    m_frame_height = 512;
    m_frame_rows = 8;
    m_frame_columns = 8;
    m_total_frames = 64;
    m_frame_duration = 0.01f;
    m_current_frame = 0;

    sprite->get_sprite().setOrigin(m_frame_width/2, m_frame_height/2);
    sprite->get_sprite().setPosition(Game::get_instance().get_window().getSize().x / 2, Game::get_instance().get_window().getSize().y/2);
    sprite->get_sprite().setTextureRect(sf::IntRect(0 * m_frame_width, 0 * m_frame_height, m_frame_width, m_frame_height));
    
    this->add_component(sprite);
    m_sprite = &sprite->get_sprite();
}

Explosion::~Explosion()
{

}

void Explosion::update(float delta_time)
{
   

    //start animating
    

    if (m_anim_clock.getElapsedTime().asSeconds() > m_frame_duration)
    {
        if (m_current_frame == (m_total_frames - 1))
        {
            //done with full cycle;
            m_current_frame = 0;
            destroy();
        }
        m_current_frame = (m_current_frame + 1) % m_total_frames;
        int row = m_current_frame / m_frame_columns;
        int col = m_current_frame % m_frame_columns;
        m_sprite->setTextureRect(sf::IntRect(col * m_frame_width, row * m_frame_height, m_frame_width, m_frame_height));
        m_anim_clock.restart();
    }
    
    
}