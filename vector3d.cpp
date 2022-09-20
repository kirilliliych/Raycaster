#include "vector3d.hpp"
#include "displaywindow.hpp"
#include "coordsys.hpp"


Vector3d::Vector3d(double x_coord, double y_coord, double z_coord)
  : x_coord_(x_coord),
    y_coord_(y_coord),
    z_coord_(z_coord)
{
    assert(std::isfinite(x_coord));
    assert(std::isfinite(y_coord));
    assert(std::isfinite(z_coord));

    type_ = DrawableType::VECTOR;
}

Vector3d::Vector3d(Point3d *beginning, Point3d *ending)
{
    assert(beginning != nullptr);
    assert(ending    != nullptr);

    x_coord_ = ending->get_x() - beginning->get_x();
    y_coord_ = ending->get_y() - beginning->get_y();
    z_coord_ = ending->get_z() - beginning->get_z();

    type_ = DrawableType::VECTOR;
}

Vector3d::Vector3d(Pixel3d *beginning, Pixel3d *ending)
{
    assert(beginning != nullptr);
    assert(ending    != nullptr);

    x_coord_ = ending->get_x() - beginning->get_x();
    y_coord_ = ending->get_y() - beginning->get_y();
    z_coord_ = ending->get_z() - beginning->get_z();

    type_ = DrawableType::VECTOR;
}

void Vector3d::draw(DisplayWindow *window, CoordSys *axes, Point3d *beginning, Color *color)
{
    assert(window    != nullptr);
    assert(axes      != nullptr);
    assert(beginning != nullptr);
    assert(color     != nullptr);
    
    window->add_drawable((Drawable *) this, axes, beginning, color);
}

Vector3d operator +(const Vector3d &opd1, const Vector3d &opd2)
{
    return Vector3d{opd1.get_x() + opd2.get_x(), 
                    opd1.get_y() + opd2.get_y(), 
                    opd1.get_z() + opd2.get_z()};
}

Vector3d operator -(const Vector3d &opd1, const Vector3d &opd2)
{
    return Vector3d{opd1.get_x() - opd2.get_x(), 
                    opd1.get_y() - opd2.get_y(),
                    opd1.get_z() - opd2.get_z()};
}

