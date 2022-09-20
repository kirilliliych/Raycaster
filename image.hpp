#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "color.hpp"


class Image
{
private:

    unsigned width_  = 0;
    unsigned height_ = 0;

    sf::Image image_{};

public:

    Image(){};

    void create(unsigned width, unsigned height, Color *color);

    void set_pixel(unsigned x_coord, unsigned y_coord, Color *color);

    unsigned get_width()
    {
        return width_;
    }
    unsigned get_height()
    {
        return height_;
    }

    const sf::Image &get_image_ref()
    {
        return image_;
    }

};

#endif