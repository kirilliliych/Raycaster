#include "image.hpp"

void Image::create(unsigned width, unsigned height, Color *color)
{
    assert(color != nullptr);

    width_  = width;
    height_ = height;

    image_.create(width, height, color->get_color_ref());
}

void Image::set_pixel(unsigned x_coord, unsigned y_coord, Color *color)
{
    assert(color != nullptr);

    image_.setPixel(x_coord, y_coord, color->get_color_ref());
}