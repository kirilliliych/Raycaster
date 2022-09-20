#ifndef PIXEL3D_HPP
#define PIXEL3D_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Pixel3d
{
private:
    
    int x_ = 0;
    int y_ = 0;
    int z_ = 0;

public:

    Pixel3d(){};

    Pixel3d(int x, int y, int z = 0)
      : x_(x),
        y_(y),
        z_(z)
    {}

    int get_x() const
    {
        return x_;
    }
    int get_y() const
    {
        return y_;
    }
    int get_z() const
    {
        return z_;
    }

    void set_x(int x)
    {
        x_ = x;
    }
    void set_y(int y)
    {
        y_ = y;
    }
    void set_z(int z)
    {
        z_ = z;
    }

    void set_pixel3d(int x, int y, int z = 0)
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }
};

#endif