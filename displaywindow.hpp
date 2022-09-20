#ifndef DISPLAYWINDOW_HPP
#define DISPLAYWINDOW_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "objsysarr.hpp"
#include "event.hpp"
#include "coordsys.hpp"
#include "point3d.hpp"
#include "objsys.hpp"
#include "drawable.hpp"
#include "vector3d.hpp"
#include "utilities.hpp"

#define SPACE_3D

const size_t MAX_WINDOW_NAME_LENGTH             = 31;
const size_t STANDARD_WINDOW_WIDTH              = 800;
const size_t STANDARD_WINDOW_HEIGHT             = 600;

static const char *STANDARD_WINDOW_NAME = "SFML Window";


class DisplayWindow
{
private:

    unsigned window_width_  = 0;
    unsigned window_height_ = 0;

    ObjSysArr object_buffer_{};

    char window_name_[MAX_WINDOW_NAME_LENGTH] = {};

    sf::RenderWindow window_{};
    
public:

    DisplayWindow(){};

    DisplayWindow(unsigned window_width  = STANDARD_WINDOW_WIDTH, 
                  unsigned window_height = STANDARD_WINDOW_HEIGHT, 
                  const char *window_name = STANDARD_WINDOW_NAME);
    
    void create(unsigned window_width  = STANDARD_WINDOW_WIDTH,
                unsigned window_height = STANDARD_WINDOW_HEIGHT,
                const char *window_name = STANDARD_WINDOW_NAME);

    void open();

    bool is_open();

    bool poll_event(Event *event);

    void close();

    void handle_events();

    void add_drawable(Drawable *entity, CoordSys *axis, Point3d *beginning, Color *color);
    
    void handle_draw_requests();

    void clear();

    void display();

    void draw_image(Image *image, Pixel3d *origin);

    #ifdef SPACE_2D
    void draw_vector(sf::Vertex *vector);

    void draw_single_object(ObjSys *object_to_draw);

    void draw_objects();
    #endif
   
    unsigned get_width()
    {
        return window_width_;
    }
    unsigned get_height()
    {
        return window_height_;  
    }

    ObjSysArr *get_object_buffer()
    {
        return &object_buffer_;
    }
};

#endif