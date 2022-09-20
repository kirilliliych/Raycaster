#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "point3d.hpp"
#include "pixel3d.hpp"
#include "color.hpp"


class CoordSys;
class DisplayWindow;


const size_t VECTOR_ANCHOR_POINTS = 5;

const int VECTOR_ARROW_PARALLEL_COMPONENT_SQRT_PIXEL_LENGTH = 15;
const int VECTOR_ARROW_SIDE_COMPONENT_SQRT_PIXEL_LENGTH     = 8;


class Vector3d : public Drawable
{
private:

    double x_coord_ = 0;
    double y_coord_ = 0;
    double z_coord_ = 0;
    
    bool is_axis_vector_ = false;

public:
    
    Vector3d()
    {
        type_ = DrawableType::VECTOR;
    }

    Vector3d(double x_coord, double y_coord, double z_coord = 0);

    Vector3d(Point3d *beginning, Point3d *ending);

    Vector3d(Pixel3d *beginning, Pixel3d *ending);

    double get_x() const
    {
        return x_coord_;
    }
    double get_y() const
    {
        return y_coord_;
    }
    double get_z() const
    {
        return z_coord_;
    }

    bool get_is_axis_vector()
    {
        return is_axis_vector_;
    }

    void set_x(double x)
    {
        x_coord_ = x;
    }
    void set_y(double y)
    {
        y_coord_ = y;
    }
    void set_z(double z)
    {
        z_coord_ = z;
    }
    
    void set_is_axis_vector(bool is_axis_vector)
    {
        is_axis_vector_ = is_axis_vector;
    }

    void draw(DisplayWindow *window, CoordSys *axes, Point3d *beginning, Color *color); 
};


Vector3d operator +(const Vector3d &opd1, const Vector3d &opd2);

Vector3d operator -(const Vector3d &opd1, const Vector3d &opd2);

// do scalar

#endif
