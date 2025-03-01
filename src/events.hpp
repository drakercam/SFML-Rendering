#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include "camera.hpp"
#include <iostream>

namespace events
{
    void ProcessEvents(sf::RenderWindow& window, camera::Camera* view);

    void ProcessKeyBoardInput(sf::RenderWindow& window, camera::Camera* view);
}

#endif