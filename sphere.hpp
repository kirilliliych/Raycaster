#ifndef SPHERE_HPP
#define SPHERE_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "image.hpp"
#include "vector3d.hpp"
#include "pixel3d.hpp"
#include "lightsource.hpp"


const size_t SPECULAR_DEG = 11;


class Sphere
{
private:

    Pixel3d origin_{};

    Color color_{};
    
    double radius_ = 0;

public:

    Sphere(){};

    Sphere(Pixel3d origin, double radius)
      : origin_(origin),
        radius_(radius)
    {
        assert(std::isfinite(radius));
        assert(radius > 0);
    }
    
    Sphere(int x_origin, int y_origin, int z_origin, double radius)
      :  radius_(radius)
    {
        assert(std::isfinite(radius));
        assert(radius > 0);

        origin_.set_x(x_origin);
        origin_.set_y(y_origin);
        origin_.set_z(z_origin);
    }

    int get_x_origin()
    {
        return origin_.get_x();
    }
    int get_y_origin()
    {
        return origin_.get_y();
    }
    int get_z_origin()
    {
        return origin_.get_z();
    }
    double get_radius()
    {
        return radius_;
    }
    Color get_color()
    {
        return color_;
    }

    void set_x_origin(int x_origin)
    {
        origin_.set_x(x_origin);
    }
    void set_y_origin(int y_origin)
    {
        origin_.set_y(y_origin);
    }
    void set_z_origin(int z_origin)
    {
        origin_.set_z(z_origin);
    }
    void set_radius(double radius)
    {
        assert(std::isfinite(radius));
        assert(radius > 0);

        radius_ = radius;
    }

    void set_color(Color color)
    {
        color_ = color;
    }

    void draw(Image *image, LightSource *light_source, Color *ambient_light, Pixel3d *camera);
};



#endif