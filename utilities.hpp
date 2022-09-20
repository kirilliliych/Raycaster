#ifndef UTILITIES_HPP
#define UTILITIES_HPP


#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "point3d.hpp"
#include "vector3d.hpp"
#include "objsys.hpp"
#include "event.hpp"
#include "sphere.hpp"


#define SPACE_3D


const double DOUBLE_COMPARISON_PRECISION = 0.001;

static const void *ABSENT_PTR_POISONED_VALUE = (const void *) 0xDEADBEEF;


bool is_in_rectangle(const Point3d *point, const Point3d *rect_angle1, const Point3d *rect_angle2);

bool is_in_rectangle(const Pixel3d *point, const Pixel3d *rect_angle1, const Pixel3d *rect_angle2);

void multiply_vector(Vector3d *vector, double multiplier);

double get_vector_length_square(Vector3d *vector);

void normalize_vector(Vector3d *vector);

void set_vector_length(Vector3d *vector, double length);

void sleep(double seconds);

void event_close(DisplayWindow *window);

double get_square(double value);

int get_square(int value);

bool is_in_sphere_2d(Pixel3d *pixel, Sphere *sphere);

int get_sphere_point_z_coord(Sphere *sphere, int x_pos, int y_pos);

void build_vector(Vector3d *vector, Point3d *beginning, Point3d *ending);

double scalar_multiplication(Vector3d *opd1, Vector3d *opd2);

double cos_between_vectors(Vector3d *opd1, Vector3d *opd2);

int min(int val1, int val2);

int max(int val1, int val2);

double min(double val1, double val2);

double max(double val1, double val2);

void dump_vector(Vector3d *vector);

#ifdef SPACE_2D
void event_key_pressed(DisplayWindow *window, Event *event);

void event_mouse_button_pressed(DisplayWindow *window, Event *event);

bool form_line(ObjSys *object_system_to_draw, sf::Vertex *line, DisplayWindow *window);

void form_arrow(ObjSys *object_system_to_draw, sf::Vertex *vector, DisplayWindow *window);

bool form_vector(ObjSys *object_system_to_draw, sf::Vertex *vector, DisplayWindow *window);

void rotate_vector(Vector3d *vector_to_rotate, double angle, double seconds_to_sleep);

void process_clickable_entities(DisplayWindow *window, Pixel3d *mouse_click_position);

void process_clickable_vector(DisplayWindow *window, Vector3d *vector, CoordSys *axes, 
                              Point3d *beginnning, Pixel3d *mouse_click_position);

void draw_coordsys(DisplayWindow *window, CoordSys *axes, Color *color);
#endif


#endif