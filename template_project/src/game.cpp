#include "game.h"
#include <iostream>
#include "gameobject.h"
#include "player.h"
#include "sprite_renderer.h"

Game &Game::get_instance()
{
    static Game instance;
    return instance;
}

sf::RenderWindow& Game::get_window()
{
    return m_window;
}

void Game::process_input()
{
     sf::Event event;
     while (m_window.pollEvent(event))
     {
        if (event.type == sf::Event::Closed)
            m_window.close();

        /*if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                std::cout << "Space Key Event Pressed" << std::endl;
            }
        }*/
     }
}

void Game::update(float delta_time)
{
    //loop through all game objects and update
    for(auto& object : m_objects_in_scene)
    {
        object->update(delta_time);
        object->update_components();
            //check for deletion

        if (object->check_delete_flag_status() == true)
        {
            m_queue_to_delete.push_back(object);
        } 
    }

  
    for (auto& obj : m_queue_to_delete)
    {
        auto it = std::find(m_objects_in_scene.begin(), m_objects_in_scene.end(), obj);
        if (it != m_objects_in_scene.end())
        {
            delete *it;
            m_objects_in_scene.erase(it);
        }
    }
    m_queue_to_delete.clear();  

    //Any new gameObjects get created this frame?
    for(auto& object : m_queue_to_add)
    {
        m_objects_in_scene.push_back(object);
    }
    m_queue_to_add.clear();
        
}




void Game::draw()
{
    m_window.clear(sf::Color::Black);
   
    for(auto& obj : m_objects_in_scene)
    {
        if (obj)
            obj->draw(m_window);
    }

    m_window.display();
}

void Game::add_gameobject(Gameobject* obj)
{
    m_queue_to_add.push_back(obj);
}

void Game::init()
{
    if (m_game_initialized == false)
    {
        m_game_initialized = true;
        //create window
        m_window.create(sf::VideoMode(800, 600), "Game Engine");
        sf::Clock clock;

        ///my game stuff///
        Player* player = new Player();
        add_gameobject(player);
       

        while (m_window.isOpen())
        {
            float delta_time = clock.restart().asSeconds();
            process_input();
            update(delta_time);
            draw();
        }

    }       
}

//private functions
Game::Game() : m_game_initialized(false) {}


