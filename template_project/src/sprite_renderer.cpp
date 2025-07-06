#include "sprite_renderer.h"
#include <iostream>

SpriteRenderer::SpriteRenderer(const std::string& file)
{
    std::cout << "SpriteRenderer Initiated" << std::endl;

    m_texture = new sf::Texture();

    if (m_texture->loadFromFile(file))
    {
        std::cout << "successfully loaded png sprite sheet" << std::endl;
        m_sprite.setTexture(*m_texture);
    }
    else
    {
        std::cout << "Error reading file: " << file << std::endl;
        delete m_texture;
        m_texture = nullptr;
    }
}

void SpriteRenderer::update()
{
    // For example purposes, you might move the sprite
    // m_sprite.setPosition(newX, newY);
}

void SpriteRenderer::draw(sf::RenderWindow& window)
{
    
    if (m_texture)
        window.draw(m_sprite);
   
}

SpriteRenderer::~SpriteRenderer()
{
    std::cout << "Cleaning up sprite renderer component" << std::endl;
    delete m_texture;
    m_texture = nullptr;
}

void SpriteRenderer::set_origin(float x, float y)
{
    m_sprite.setOrigin(x, y);
}

void SpriteRenderer::set_position(float x, float y)
{
    m_sprite.setPosition(x, y);
}

void SpriteRenderer::set_default_frame(int column, int row, int width, int height)
{
    m_sprite.setTextureRect(sf::IntRect(column, row, width, height));
}

sf::Sprite& SpriteRenderer::get_sprite()
{
    return m_sprite;
}
