#ifndef POINT3D_HPP
#define POINT3D_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Point3d
{
private:
    
    double x_ = 0;
    double y_ = 0;
    double z_ = 0;

public:

    Point3d(){};

    Point3d(double x, double y, double z = 0)
      : x_(x),
        y_(y),
        z_(z)
    {
        assert(std::isfinite(x_));
        assert(std::isfinite(y_));
        assert(std::isfinite(z_));
    }

    double get_x() const
    {
        return x_;
    }
    double get_y() const
    {
        return y_;
    }
    double get_z() const
    {
        return z_;
    }

    void set_x(double x)
    {
        x_ = x;
    }
    void set_y(double y)
    {
        y_ = y;
    }
    void set_z(double z)
    {
        z_ = z;
    }

    void set_point3d(double x, double y, double z = 0)
    {
        assert(std::isfinite(x));
        assert(std::isfinite(y));
        assert(std::isfinite(z));

        x_ = x;
        y_ = y;
        z_ = z;
    }
};

#endif