#ifndef LIGHT_SOURCE_HPP
#define LIGHT_SOURCE_HPP

#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class LightSource
{
public:

    Pixel3d position_{};
    Color   color_{};
};


#endif