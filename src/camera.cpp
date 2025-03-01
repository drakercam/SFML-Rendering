#include "camera.hpp"

namespace camera
{
    Camera* CreateCamera(Camera* view)
    {
        view->view = sf::View(sf::FloatRect(0, 0, 960, 540));
        view->view.setCenter(1920 / 2, 1080 / 2);
        view->center_position = view->view.getCenter();
        view->cameraSpeed = 300.0f;

        return view;
    }

    void DrawCamera(sf::RenderWindow& win, Camera* view)
    {
        win.setView(view->view);
    }

    void MoveCamera(sf::RenderWindow& win, Camera* view, float x, float y)
    {
        view->view.move({x, y});
        win.setView(view->view);
    }
}