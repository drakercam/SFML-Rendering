#ifndef STAR_HPP
#define STAR_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "conf.hpp"
#include <vector>
#include <random>

namespace star
{
    struct Star
    {
        sf::Vector2f position;
        float z = 1.0f;
    };

    std::vector<Star> createStars(unsigned int count, float scale)
    {
        std::vector<Star> stars;
        stars.reserve(count);

        // random num generator for positions
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.0f, 1.0f);

        // define a zone which is star free
        const sf::Vector2f window_world_size = config::window_size_f * config::near;
        const sf::FloatRect star_free_zone = {-window_world_size * 0.5f, window_world_size};


        // randomly distribute stars across the screen
        for (unsigned int i = count; i > 0; --i)
        {
            const float x = (dist(gen) - 0.5) * config::window_size_f.x * scale;
            const float y = (dist(gen) - 0.5) * config::window_size_f.y * scale;
            const float z = (dist(gen) - 0.5) * (config::far - config::near) + config::near;

            // discard any star that falls into this star free zone
            if (star_free_zone.contains(x, y))
            {
                ++i;
                continue;
            }

            // otherwise we'll add it to the stars vector
            stars.push_back({{x, y}, z});
        }

        // depth ordering
        std::sort(stars.begin(), stars.end(), [](Star const& s_1, Star const& s_2) {
            return s_1.z > s_2.z;
        });

        return stars;
    }

    void renderStarsWithDepth(sf::RenderWindow& win, std::vector<Star>& stars)
    {
        const unsigned int size = stars.size();
        sf::CircleShape shape{config::star_radius};
        shape.setOrigin(config::star_radius, config::star_radius);

        for (unsigned int i = 0; i < size; ++i)
        {   
            const unsigned int index = (i + config::first) % size;
            const Star& star = stars[index];
            const float scale = 1.0f / star.z;
            shape.setPosition(star.position * scale + config::window_size_f * 0.5f);
            shape.setScale(scale, scale);

            const float depth_ratio = (star.z - config::near) / (config::far - config::near);
            const float color_ratio = 1.0f - depth_ratio;
            const auto color = static_cast<uint8_t>(color_ratio*255.0f);
            shape.setFillColor({color, 0, color});
            win.draw(shape);
        }
    }

    void renderStarsWithDepthUsingSprites(sf::RenderWindow& win, std::vector<Star>& stars)
    {
        const unsigned int size = stars.size();
        sf::Sprite shape;
        sf::Texture shape_texture;
        shape_texture.loadFromFile("textures/stars.png");
        shape.setTexture(shape_texture);
        shape.setOrigin(shape.getGlobalBounds().width / 2.0f, shape.getGlobalBounds().height / 2.0f);

        for (unsigned int i = 0; i < size; ++i)
        {   
            const unsigned int index = (i + config::first) % size;
            const Star& star = stars[index];
            const float scale = 1.0f / star.z;
            shape.setPosition(star.position * scale + config::window_size_f * 0.5f);
            shape.setScale(0.5*scale, 0.5*scale);

            const float depth_ratio = (star.z - config::near) / (config::far - config::near);
            const float color_ratio = 1.0f - depth_ratio;
            const auto color = static_cast<uint8_t>(color_ratio*255.0f);
            shape.setColor({color, 0, color});
            win.draw(shape);
        }
    }

    // function to make a forward traveling effect
    void forwardTravel(std::vector<Star>& stars)
    {
        const unsigned int size = stars.size();

        for (unsigned int i = size - 1; i > 0; --i)
        {
            stars[i].z -= config::speed * config::delta_time;

            if (stars[i].z < config::near)
            {
                // offset the star by the excess travel it made behind near to keep spacing constant
                stars[i].z = config::far - (config::near - stars[i].z);

                // this star is now the first we need to draw because it is further away from us
                config::first = i;
            }
        }
    }

    void render(sf::RenderWindow& win, std::vector<Star>& stars)
    {
        const unsigned int size = stars.size();

        sf::CircleShape shape{config::star_radius};
        shape.setOrigin(config::star_radius, config::star_radius);

        for (unsigned int i = 0; i < size; ++i)
        {
            
        }
    }
}

#endif