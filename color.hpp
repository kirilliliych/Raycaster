#ifndef COLOR_HPP
#define COLOR_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


const uint8_t COLOR_MAX_VALUE = 0xFF;


class Color
{
private:
    
    double red_d_   = 0;
    double green_d_ = 0;
    double blue_d_  = 0; 
    double alpha_d_ = 0;

    sf::Color color_{};

public:

    Color();

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF);

    Color(double r, double g, double b, double a = 1);

    uint8_t get_r()
    {
        return color_.r;
    }
    uint8_t get_g()
    {
        return color_.g;
    }
    uint8_t get_b()
    {
        return color_.b;
    }
    uint8_t get_a()
    {
        return color_.a;
    }
    

    const sf::Color &get_color_ref()
    {
        return color_;
    }

    void set_r(uint8_t r)
    {
        color_.r = r;

        red_d_ = r / COLOR_MAX_VALUE;
    }
    void set_g(uint8_t g)
    {
        color_.g = g;

        green_d_ = g / COLOR_MAX_VALUE;
    }
    void set_b(uint8_t b)
    {
        color_.b = b;

        blue_d_ = b / COLOR_MAX_VALUE;
    }
    void set_a(uint8_t a)
    {
        color_.a = a;

        alpha_d_ = a / COLOR_MAX_VALUE;
    }
    
    void set_color(uint32_t rgba)
    {
        color_.r = (uint8_t) ((rgba & 0xFF000000) >> 24);
        color_.g = (uint8_t) ((rgba & 0x00FF0000) >> 16);
        color_.b = (uint8_t) ((rgba & 0x0000FF00) >> 8);
        color_.a = (uint8_t)  (rgba & 0x000000FF);

        red_d_   = color_.r / COLOR_MAX_VALUE;
        green_d_ = color_.g / COLOR_MAX_VALUE;
        blue_d_  = color_.b / COLOR_MAX_VALUE;
        alpha_d_ = color_.a / COLOR_MAX_VALUE;
    }
};

#endif