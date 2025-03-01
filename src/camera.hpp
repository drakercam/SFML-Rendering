#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "conf.hpp"

namespace camera
{   
    struct Camera
    {
        sf::View view;
        sf::Vector2f center_position;
        float cameraSpeed;
    };

    Camera* CreateCamera(Camera* view);
    void DrawCamera(sf::RenderWindow& win, Camera* view);
    void MoveCamera(sf::RenderWindow& win, Camera* view, float x, float y);
}

#endif