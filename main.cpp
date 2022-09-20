#include <ctime>
#include "displaywindow.hpp"
#include "vector3d.hpp"
#include "lightsource.hpp"
#include "color.hpp"


int main()
{
    unsigned window_width  = 800;
    unsigned window_height = 800;
    DisplayWindow window{window_width, window_height, "Raycaster"};

    Sphere ball{400, 400, 0, 150};
    Color ball_color{(uint8_t) 0x32, (uint8_t) 0xCD, (uint8_t) 0x32};
    ball.set_color(ball_color);

    LightSource light_source{};
    light_source.position_.set_pixel3d(400, 400, 700);
    light_source.color_.set_color(0xFFFF32FF);

    Color ambient_light{0.01, 0.01, 0.01};

    Pixel3d camera_position{400, 400, 900};

    window.open();
    while (window.is_open())
    {
        Color image_background_color{(uint8_t) 0xFF, (uint8_t) 0xFF, (uint8_t) 0xFF};
        Image sphere_image{};
        sphere_image.create(window_width, window_height, &image_background_color);

        window.handle_events();

        window.clear();

        ball.draw(&sphere_image, &light_source, &ambient_light, &camera_position);

        Pixel3d sphere_picture_origin{0, 0};
        window.draw_image(&sphere_image, &sphere_picture_origin);

        window.display();
    }
    
    return 0;
}