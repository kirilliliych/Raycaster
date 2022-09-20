#include "sphere.hpp"
#include "utilities.hpp"

void dump_color(Color pixel_color)
{
    printf("%lg, %lg, %lg\n", pixel_color.get_red_d(), pixel_color.get_green_d(), pixel_color.get_blue_d());
    printf("%u, %u, %u\n", pixel_color.get_r(), pixel_color.get_g(), pixel_color.get_b());
}

void Sphere::draw(Image *image, LightSource *light_source, Color *ambient_light, Pixel3d *camera)
{
    assert(image         != nullptr);
    assert(light_source  != nullptr);
    assert(ambient_light != nullptr);
    assert(camera        != nullptr);

    // sphere_render func; render_pixel
    for (int x_pos = 0; x_pos < image->get_width(); ++x_pos)
    {
        for (int y_pos = 0; y_pos < image->get_height(); ++y_pos)
        {
            Pixel3d cur_pixel{x_pos, y_pos, 0};
            if (!is_in_sphere_2d(&cur_pixel, this))
            {
                Color out_of_sphere_color{(uint8_t) 0x70, (uint8_t) 0x80, (uint8_t) 0x90};         // grey
                image->set_pixel(x_pos, y_pos, &out_of_sphere_color);
            }
            else
            {
                // image->set_pixel(x_pos, y_pos, &color_);
                
                int z_pos = get_sphere_point_z_coord(this, abs(x_pos - origin_.get_x()), abs(y_pos - origin_.get_y()));
                cur_pixel.set_z(z_pos);
                // cur_pixel.set_z(get_sphere_point_z_coord(this, abs(x_pos - origin_.get_x()), abs(y_pos - origin_.get_y()))) ; // z axis goes towards us

                Vector3d light_ray_vector{&cur_pixel, &light_source->position_};
                Vector3d normal_vector{&origin_, &cur_pixel};
                // std::cout << "x_pos: " << x_pos << " y_pos: " << y_pos << " z_pos: " << z_pos << std::endl;
                // std::cout << "x1: " << light_ray_vector.get_x() << " y1: " << light_ray_vector.get_y() << " z1: " << light_ray_vector.get_z() << std::endl;
                // std::cout << "x2: " << normal_vector.get_x()    << " y2: " << normal_vector.get_y()    << " z2: " << normal_vector.get_z()    << std::endl;

                double cos_Lambert_law = cos_between_vectors(&light_ray_vector,
                                                             &normal_vector);

                // printf("cos_Lambert_law: %lg\n", cos_Lambert_law);

                if (!std::isfinite(cos_Lambert_law) || (cos_Lambert_law < DOUBLE_COMPARISON_PRECISION))
                {
                    cos_Lambert_law = 0;
                }

                Color Lambert_component  = color_ * light_source->color_ * cos_Lambert_law;
                Color ambient_component  = color_ * light_source->color_ * *ambient_light;
                Color pixel_color = Lambert_component + ambient_component;
                if (cos_Lambert_law > 0.5)
                {   std::cout << "Lambert_component " << std::endl;
                    dump_color(color_ * light_source->color_);
                    std::cout << "ambient_component " << std::endl;
                    dump_color(color_ * light_source->color_ * *ambient_light);
                }

                if (cos_Lambert_law > 0)
                {
                    // std::cout << "first:" << "x2: " << normal_vector.get_x()    << " y2: " << normal_vector.get_y()    << " z2: " << normal_vector.get_z()    << std::endl;
                    multiply_vector(&normal_vector, 2 * cos_Lambert_law);                         // sqrt?
                    // std::cout << "second:" << "x2: " << normal_vector.get_x()    << " y2: " << normal_vector.get_y()    << " z2: " << normal_vector.get_z()    << std::endl;
                    
                    Vector3d reflected_light_ray_vector = normal_vector - light_ray_vector;
                    Vector3d camera_vector{&cur_pixel, camera};
                    double cos_specular_base = (cos_between_vectors(&reflected_light_ray_vector,
                                                                    &camera_vector));

                    if (!std::isfinite(cos_specular_base) || (cos_specular_base < DOUBLE_COMPARISON_PRECISION))
                    {
                        cos_specular_base = 0;
                    }
                    
                    double specular = pow(cos_specular_base, SPECULAR_DEG);

                    Color specular_component = light_source->color_ * cos_specular_base;

                    pixel_color += specular_component;
                }
                

                image->set_pixel(x_pos, y_pos, &pixel_color);
            }
        }
    }
}