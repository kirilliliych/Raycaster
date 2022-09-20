#include "sphere.hpp"
#include "utilities.hpp"


void Sphere::draw(Image *image, LightSource *light_source, Pixel3d *camera)
{
    assert(image        != nullptr);
    assert(light_source != nullptr);
    assert(camera       != nullptr);

    // sphere_render func; render_pixel
    for (int x_pos = 0; x_pos < image->get_width(); ++x_pos)
    {
        for (int y_pos = 0; y_pos < image->get_height(); ++y_pos)
        {
            Pixel3d cur_pixel{x_pos, y_pos};
            if (!is_in_sphere_2d(&cur_pixel, this))
            {
                Color out_of_sphere_color{(uint8_t) 0x70, (uint8_t) 0x80, (uint8_t) 0x90};         // grey
                image->set_pixel(x_pos, y_pos, &out_of_sphere_color);
            }
            else
            {
                // image->set_pixel(x_pos, y_pos, &color_);

                cur_pixel.set_z(get_sphere_point_z_coord(this, x_pos, y_pos));                     // z axis goes towards us

                Vector3d light_ray_vector{&cur_pixel, &light_source->position_};
                Vector3d normal_vector{&origin_, &cur_pixel};

                // std::cout << "x1: " << light_ray_vector.get_x() << " y1: " << light_ray_vector.get_y() << std::endl;
                // std::cout << "x2: " << normal_vector.get_x() << " y2: " << normal_vector.get_y() << std::endl;

                
                double cos_Lambert_law = cos_between_vectors(&light_ray_vector,
                                                             &normal_vector);
            
                // multiply_vector(&normal_vector, 2 * cos_Lambert_law);                           // sqrt?
                
                // Vector3d reflected_light_ray_vector = normal_vector - light_ray_vector;
                // Vector3d camera_vector{&cur_pixel, camera};
                // double cos_specular_base = cos_between_vectors(&reflected_light_ray_vector,
                //                                                &camera_vector);
                
                // double specular = pow(cos_specular_base, SPECULAR_DEG);
                
                // if (cos_Lambert_law < DOUBLE_COMPARISON_PRECISION)
                // {
                //     cos_Lambert_law = 0;
                // }
                // if (cos_specular_base < DOUBLE_COMPARISON_PRECISION)
                // {
                //     cos_specular_base = 0;
                // }


            }
        }
    }
}