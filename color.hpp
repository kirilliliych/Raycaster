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
    double alpha_d_ = 1;

    sf::Color color_{};


    void limit_doubles()
    {
        if (red_d_ > 1)
        {
            red_d_ = 1;
        }

        if (green_d_ > 1)
        {
            green_d_ = 1;
        }

        if (blue_d_ > 1)
        {
            blue_d_ = 1;
        }

        if (alpha_d_ > 1)
        {
            alpha_d_ = 1;
        }

        if (red_d_ < 0)
        {
            red_d_ = 0;
        }

        if (green_d_ < 0)
        {
            green_d_ = 0;
        }

        if (blue_d_ < 0)
        {
            blue_d_ = 0;
        }

        if (alpha_d_ < 0)
        {
            alpha_d_ = 0;
        }

        update_ints();
    }

    void update_ints()
    {
        color_.r = (double) (red_d_   * COLOR_MAX_VALUE);
        color_.g = (double) (green_d_ * COLOR_MAX_VALUE);
        color_.b = (double) (blue_d_  * COLOR_MAX_VALUE);
    }

    void update_doubles()
    {
        red_d_   = (double) color_.r / COLOR_MAX_VALUE;
        green_d_ = (double) color_.g / COLOR_MAX_VALUE;
        blue_d_  = (double) color_.b / COLOR_MAX_VALUE;
    }

public:

    Color();

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = (uint8_t) 0xFF);

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

    double get_red_d()
    {
        return red_d_;
    }
    double get_green_d()
    {
        return green_d_;
    }
    double get_blue_d()
    {
        return blue_d_;
    }
    double get_alpha_d()
    {
        return alpha_d_;
    }
    
    const sf::Color &get_color_ref()
    {
        return color_;
    }

    void set_r(uint8_t r)
    {
        color_.r = r;

        red_d_ = (double) r / COLOR_MAX_VALUE;
    }
    void set_g(uint8_t g)
    {
        color_.g = g;

        green_d_ = (double) g / COLOR_MAX_VALUE;
    }
    void set_b(uint8_t b)
    {
        color_.b = b;

        blue_d_ = (double) b / COLOR_MAX_VALUE;
    }
    void set_a(uint8_t a)
    {
        color_.a = a;

        alpha_d_ = (double) a / COLOR_MAX_VALUE;
    }
    
    void set_red_d(double red_d)
    {
        red_d_ = red_d;

        limit_doubles();

        update_ints();
    }
    void set_green_d(double green_d)
    {
        green_d_ = green_d;

        limit_doubles();

        update_ints();
    }
    void set_blue_d(double blue_d)
    {
        blue_d_ = blue_d;

        limit_doubles();

        update_ints();
    }
    void set_alpha_d(double alpha_d)
    {
        alpha_d_ = alpha_d;

        limit_doubles();

        update_ints();
    }
    
    void set_color(uint32_t rgba)
    {
        color_.r = (uint8_t) ((rgba & 0xFF000000) >> 24);
        color_.g = (uint8_t) ((rgba & 0x00FF0000) >> 16);
        color_.b = (uint8_t) ((rgba & 0x0000FF00) >> 8);
        color_.a = (uint8_t)  (rgba & 0x000000FF);

        update_doubles();
    }


    void operator +=(const Color &another_color)
    {
        red_d_   += another_color.red_d_;
        green_d_ += another_color.green_d_;
        blue_d_  += another_color.blue_d_;
        
        limit_doubles();

        update_ints();
    }

    void operator *=(const Color &another_color)
    {
        red_d_   *= another_color.red_d_;
        green_d_ *= another_color.green_d_;
        blue_d_  *= another_color.blue_d_;

        limit_doubles();

        update_ints();
    }

    void operator *=(double scalar)
    {
        red_d_   *= scalar;
        green_d_ *= scalar;
        blue_d_  *= scalar;
        
        limit_doubles();

        update_ints();
    }

    Color operator +(const Color &another_color)
    {
        Color result = *this;

        result += another_color;

        result.limit_doubles();

        return result;
    }

    Color operator *(const Color &another_color)
    {
        Color result = *this;

        result *= another_color;

        result.limit_doubles();

        return result;
    }

    Color operator *(double scalar)
    {
        Color result = *this;

        result *= scalar;

        result.limit_doubles();

        return result;
    }

};



#endif