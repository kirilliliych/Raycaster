#ifndef COORDSYS_HPP
#define COORDSYS_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "pixel3d.hpp"
#include "point3d.hpp"
#include "vector3d.hpp"


#define SPACE_3D

#ifdef SPACE_2D
const int COORD_SYS_ORIGIN_FICTIVE_COORD_VALUE  = -1337228;


class CoordSys                                                                                      // текст в текстуру?
{
private:

    double x_min_coord_ = 0;
    double y_min_coord_ = 0;
    double x_max_coord_ = 0;
    double y_max_coord_ = 0;
    double 
    
    Pixel3d area_rect_point1_{};
    Pixel3d area_rect_point2_{};
    Pixel3d origin_point_{};

    double x_scale_ = 0;
    double y_scale_ = 0;

    bool is_vulnerable_to_clicks_ = false;

    void update_x_scale();
    void update_y_scale();
    void update_origin_x_position();
    void update_origin_y_position();

public:

    Vector3d x_axis_{};           //
    Vector3d y_axis_{};           //  for drawing coordsys
    Point3d  x_axis_beginning_{}; //
    Point3d  y_axis_beginning_{}; //

    CoordSys()
    {
        x_axis_.set_is_axis_vector(true);
        y_axis_.set_is_axis_vector(true);
    }

    CoordSys(double x_min, double y_min,
             double x_max, double y_max,
             int x_area_rect_point_1, int y_area_rect_point_1,
             int x_area_rect_point_2, int y_area_rect_point_2,
             int x_origin_coord = COORD_SYS_ORIGIN_FICTIVE_COORD_VALUE,
             int y_origin_coord = COORD_SYS_ORIGIN_FICTIVE_COORD_VALUE);

    double get_x_min()
    {
        return x_min_coord_;
    }
    double get_y_min()
    {
        return y_min_coord_;
    }
    double get_x_max()
    {
        return x_max_coord_;
    }
    double get_y_max()
    {
        return y_max_coord_;
    }
    int get_left_border()
    {
        return area_rect_point1_.get_x();
    }
    int get_right_border()
    {
        return area_rect_point2_.get_x();
    }
    int get_top_border()
    {
        return area_rect_point1_.get_y();
    }
    int get_bottom_border()
    {
        return area_rect_point2_.get_y();
    }
    int get_x_origin()
    {
        return origin_point_.get_x();
    }
    int get_y_origin()
    {
        return origin_point_.get_y();
    }
    double get_x_scale()
    {
        return x_scale_;
    }
    double get_y_scale()
    {
        return y_scale_;
    }
    bool get_vulnerability_to_clicks_mode()
    {
        return is_vulnerable_to_clicks_;
    }

    const Pixel3d *get_top_left_border_coords()
    {
        return &area_rect_point1_;
    }
    const Pixel3d *get_bottom_right_border_coords()
    {
        return &area_rect_point2_;
    }

    void set_x_min(double x_min)
    {
        x_min_coord_ = x_min;
    }
    void set_y_min(double y_min)
    {
        y_min_coord_ = y_min;
    }
    void set_x_max(double x_max)
    {
        x_max_coord_ = x_max;
    }
    void set_y_max(double y_max)
    {
        y_max_coord_ = y_max;
    }
    void set_vulnerability_to_clicks_mode(bool vulnerability_to_clicks)
    {
        is_vulnerable_to_clicks_ = vulnerability_to_clicks;
    }
};
#endif

#endif