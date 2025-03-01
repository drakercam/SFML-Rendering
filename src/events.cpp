
#include "events.hpp"

namespace events
{
    void ProcessEvents(sf::RenderWindow& window, camera::Camera* view)
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
    }

    void ProcessKeyBoardInput(sf::RenderWindow& window, camera::Camera* view)
    {
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            movement.y -= view->cameraSpeed * config::dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            movement.y += view->cameraSpeed * config::dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            movement.x -= view->cameraSpeed * config::dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            movement.x += view->cameraSpeed * config::dt;
        }

        if (movement.x != 0.0f || movement.y != 0.0f)
        {
            // std::cout << "Moving camera by (" << movement.x << ", " << movement.y << ")" << std::endl;
            camera::MoveCamera(window, view, movement.x, movement.y);
        }
    }
}