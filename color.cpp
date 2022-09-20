#include "color.hpp"
#include "utilities.hpp"

Color::Color()
  : red_d_  (1),
    green_d_(1),
    blue_d_ (1),
    alpha_d_(1)
{
    color_.r = COLOR_MAX_VALUE;
    color_.g = COLOR_MAX_VALUE;
    color_.b = COLOR_MAX_VALUE;
    color_.a = COLOR_MAX_VALUE;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    color_.r = r;
    color_.g = g;
    color_.b = b;
    color_.a = a;

    update_doubles();
}

Color::Color(double r, double g, double b, double a)
{
    assert(std::isfinite(r));
    assert(std::isfinite(g));
    assert(std::isfinite(b));
    assert(std::isfinite(a));

    red_d_   = min(r, (double) 1);
    green_d_ = min(g, (double) 1);
    blue_d_  = min(b, (double) 1);
    alpha_d_ = min(a, (double) 1);

    red_d_   = max(red_d_,   (double) 0);
    green_d_ = max(green_d_, (double) 0);
    blue_d_  = max(blue_d_,  (double) 0);
    alpha_d_ = max(alpha_d_, (double) 0);

    update_ints();
}