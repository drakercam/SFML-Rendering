#ifndef CONF_HPP
#define CONF_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <vector>

namespace config
{   
    // window config
    const unsigned int max_framerate = 120;
    sf::Vector2u const window_size = { 1920u, 1080u };
    sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);
    sf::Vector2i const window_offset = { -5, 0 };
    const float delta_time = 1.0f / static_cast<float>(max_framerate);

    // clock for delta_time movment smoothing
    inline sf::Clock clock;
    inline float dt;

    // star config
    const unsigned int star_count = 10000;
    const float star_radius = 15.0f;

    inline std::vector<sf::Color> colors =
    {
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color::Yellow
    };

    const unsigned int num_colors = colors.size();
    
    const float far = 10.0f; // max value z can take for our stars
    const float near = 0.5f; // min value z can take for our stars
    const float speed = 1.0f; // for forward travel

    inline unsigned int first = 0;

}

#endif