#pragma once
#include "gameobject.h"

class Player : public Gameobject
{
public:
    Player();
    void update(float delta_time) override;
private:
    bool m_key_pressed;
};