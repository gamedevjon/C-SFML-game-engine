#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "component.h"

class SpriteRenderer : public Component
{
public:
    SpriteRenderer(const std::string& file);
    void update() override;
    void draw(sf::RenderWindow& window) override;
    ~SpriteRenderer();
    void set_origin(float x, float y);
    void set_position(float x, float y);
    void set_default_frame(int column, int row, int width, int height);

    sf::Sprite& get_sprite();
    
private:
    sf::Texture* m_texture;
    sf::Sprite m_sprite;
    
};