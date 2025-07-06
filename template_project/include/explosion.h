#pragma once
#include "gameobject.h"
#include "sprite_renderer.h"

class Explosion : public Gameobject
{
public:
    Explosion();
    ~Explosion();
    void update(float delta_time) override;
private:
    float m_life_time;
    float m_time_eslapsed;
    int m_frame_width;
    int m_frame_height;
    int m_frame_rows;
    int m_frame_columns;
    int m_total_frames;
    float m_frame_duration;
    int m_current_frame;
    sf::Sprite* m_sprite;
    sf::Clock m_anim_clock;
};