
#include <iostream>
#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "conf.hpp"
#include "star.hpp"
#include "camera.hpp"

int main(void)
{
    auto window = sf::RenderWindow( {config::window_size.x, config::window_size.y}, "Rendering Project" );
    std::vector<star::Star> stars = star::createStars(config::star_count, config::far);
    camera::Camera* camera = new camera::Camera;
    camera = camera::CreateCamera(camera);

    // set the max_framerate
    window.setFramerateLimit(config::max_framerate);
    window.setPosition(config::window_offset);
    camera::DrawCamera(window, camera);

    while (window.isOpen())
    {
        config::dt = config::clock.restart().asSeconds();

        // process window related events
        events::ProcessEvents(window, camera);

        // process keyboard related events
        events::ProcessKeyBoardInput(window, camera);

        // have the stars travel towards us in the z-direction
        star::forwardTravel(stars);

        window.clear();

        // draw the stars with depth
        // star::renderStarsWithDepth(window, stars);

        // draw the stars with depth and as sprites
        star::renderStarsWithDepthUsingSprites(window, stars);

        window.display();
    }

    delete camera;

    return 0;
}