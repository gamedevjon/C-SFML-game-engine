#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "gameobject.h"

class Game
{
public:
    static Game& get_instance();
    sf::RenderWindow& get_window();
    void init();
    void process_input();
    void update(float delta_time);
    void draw();
    void add_gameobject(Gameobject* obj);
    //remove copy constructor & assignment operator for singleton 
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
private:
    Game();
    ~Game() = default;
    bool m_game_initialized;
    sf::RenderWindow m_window;

    std::vector<Gameobject*> m_objects_in_scene;
    std::vector<Gameobject*> m_queue_to_delete;
    std::vector<Gameobject*> m_queue_to_add;
};