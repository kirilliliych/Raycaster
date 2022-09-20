#include "displaywindow.hpp"

DisplayWindow::DisplayWindow(unsigned window_width, 
                             unsigned window_height, 
                             const char *window_name)
  : window_width_ (window_width),
    window_height_(window_height)
{
    assert(window_name != nullptr);

    strncpy(window_name_, window_name, MAX_WINDOW_NAME_LENGTH);
}

void DisplayWindow::create(unsigned window_width,
                           unsigned window_height,
                           const char *window_name)
{
    assert(window_name != nullptr);

    DisplayWindow(window_width, window_height, window_name);

    window_.create(sf::VideoMode(window_width, window_height), window_name);
}

void DisplayWindow::open()
{
    window_.create(sf::VideoMode(window_width_, window_height_), window_name_);
}

bool DisplayWindow::is_open()
{
    return window_.isOpen();
}

void DisplayWindow::close()
{
    window_.close();
}

bool DisplayWindow::poll_event(Event *event)
{
    assert(event != nullptr);

    return window_.pollEvent(event->get_event_ref());
}

void DisplayWindow::handle_events()
{
    Event event;
    while (poll_event(&event))
    {
        switch (event.get_event_type())
        {
            case sf::Event::Closed:
            {
                event_close(this);

                break;
            }
            
#ifdef SPACE_2D
            case sf::Event::KeyPressed:
            {
                event_key_pressed(this, &event);

                break;
            }

            case sf::Event::MouseButtonPressed:
            {
                event_mouse_button_pressed(this, &event);

                break;
            }
#endif
            default:
            {
                break;
            }
        }
    }
}

void DisplayWindow::add_drawable(Drawable *entity, CoordSys *axes, Point3d *beginning, Color *color)
{
    assert(entity    != nullptr);
    assert(axes      != nullptr);
    assert(beginning != nullptr);
    assert(color     != nullptr);

    object_buffer_.add(entity, axes, beginning, color);
}

void DisplayWindow::clear()
{
    window_.clear();
}

void DisplayWindow::display()
{
    window_.display();
}

void DisplayWindow::draw_image(Image *image, Pixel3d *origin)
{
    assert(image  != nullptr);
    assert(origin != nullptr);

    sf::RectangleShape picture(sf::Vector2f(image->get_width(), image->get_height()));
    picture.setPosition(sf::Vector2f(origin->get_x(), origin->get_y()));

    sf::Texture picture_texture{};
    picture_texture.loadFromImage(image->get_image_ref());
    picture.setTexture(&picture_texture);

    window_.draw(picture);
}

#ifdef SPACE_2D
void DisplayWindow::draw_vector(sf::Vertex *vector)
{
    assert(vector != nullptr);
    
    window_.draw(vector,     2, sf::Lines);
    window_.draw(vector + 1, 2, sf::Lines);
    window_.draw(vector + 3, 2, sf::Lines);
}

void DisplayWindow::draw_single_object(ObjSys *object_system_to_draw)
{
    Drawable *drawable_type_ptr = (Drawable *) object_system_to_draw->entity_;                   //  Base class Drawable contains variable type_ of type Drawable
                                                                                                 //  and all primitives (e.g. vectors) derive from him, therefore
                                                                                                 //  first sizeof(Drawable) bytes contain type_ variable
    switch (drawable_type_ptr->get_drawable_type())
    {
        case DrawableType::VECTOR:
        {
            sf::Vertex vector[VECTOR_ANCHOR_POINTS] = {};

            if (form_vector(object_system_to_draw, vector, this))
            {
                draw_vector(vector);
            }

            break;
        }

        case DrawableType::RECTANGLE:
        {
            Rectangle *rectangle = (Rectangle *) drawable_type_ptr; 

            draw_rectangle(rectangle);

            break;
        }

        case DrawableType::UNKNOWN:
        {
            std::cout << "Object with unknown type requires drawing" << std::endl;

            break;
        }
    }
}

void DisplayWindow::draw_objects()
{
    for (size_t obj_index = 0; obj_index < object_buffer_.size_; ++obj_index)
    {   
        draw_single_object(&object_buffer_.array_[obj_index]);
    }
}
#endif