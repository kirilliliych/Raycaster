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
    Color ball_color{LIME};
    ball.set_color(ball_color);

    LightSource light_source{};
    // light_source.position_.set_pixel3d(200, 200, 300);
    light_source.color_.set_color(WHITE);

    Color ambient_light{0.2, 0.2, 0.2};

    Pixel3d camera_position{400, 400, 600};

    double light_source_rotating_parameter = 0;

    window.open();
    while (window.is_open())
    {
        light_source.position_.set_pixel3d(300 + 300 * sin(light_source_rotating_parameter), 300 + 300 * sin(light_source_rotating_parameter), 300 + sin(light_source_rotating_parameter));
        Color image_background_color{WHITE};
        Image sphere_image{};
        sphere_image.create(window_width, window_height, &image_background_color);

        window.handle_events();

        window.clear();

        ball.draw(&sphere_image, &light_source, &ambient_light, &camera_position);

        Pixel3d sphere_picture_origin{0, 0};
        window.draw_image(&sphere_image, &sphere_picture_origin);

        window.display();

        light_source_rotating_parameter += 0.05;
    }
    
    return 0;
}