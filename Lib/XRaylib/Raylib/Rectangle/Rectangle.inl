/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Rectangle
*/

inline Raylib::Rectangle &Raylib::Rectangle::operator=(const Rectangle &rectangle)
{
    set(rectangle);
    return *this;
}

inline void Raylib::Rectangle::set(const ::Rectangle &rectangle)
{
    _rectangle = rectangle;
}

inline void Raylib::Rectangle::set(const Rectangle &rectangle)
{
    _rectangle = rectangle._rectangle;
}

inline ::Rectangle Raylib::Rectangle::getCStruct() const
{
    return _rectangle;
}

inline void Raylib::Rectangle::drawRectangle(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const
{
    return ::DrawRectangle(posX, posY, width, height, color.getCStruct());
}


inline void Raylib::Rectangle::drawRectangleV(::Vector2 const &position, ::Vector2 const &size, Raylib::Color const &color) const
{
    return ::DrawRectangleV(position, size, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRec(Raylib::Rectangle const &rec, Raylib::Color const &color) const
{
    return ::DrawRectangleRec(rec.getCStruct(), color.getCStruct());
}


inline void Raylib::Rectangle::drawRectanglePro(Raylib::Rectangle const &rec, ::Vector2 const &origin, float const &rotation, Raylib::Color const &color) const
{
    return  ::DrawRectanglePro(rec.getCStruct(), origin, rotation, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleGradientV(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color1, Raylib::Color const &color2) const
{
    return ::DrawRectangleGradientV(posX, posY, width, height, color1.getCStruct(), color2.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleGradientH(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color1, Raylib::Color const &color2) const
{
    return ::DrawRectangleGradientH(posX, posY, width, height, color1.getCStruct(), color2.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleGradientEx(Raylib::Rectangle const &rec, Raylib::Color const &col1, Raylib::Color const &col2, Raylib::Color const &col3, Raylib::Color const &col4) const
{
    return ::DrawRectangleGradientEx(rec.getCStruct(), col1.getCStruct(), col2.getCStruct(), col3.getCStruct(), col4.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleLines(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const
{
    return ::DrawRectangleLines(posX, posY, width, height, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleLinesEx(Raylib::Rectangle const &rec, int const &lineThick, Raylib::Color const &color) const
{
    return ::DrawRectangleLinesEx(rec.getCStruct(), lineThick, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRounded(Raylib::Rectangle const &rec, float const &roundness, int const &segments, Raylib::Color const &color) const
{
    return ::DrawRectangleRounded(rec.getCStruct(), roundness, segments, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRoundedLines(Raylib::Rectangle const &rec, float const &roundness, int const &segments, int const &lineThick, Raylib::Color const &color) const
{
    return ::DrawRectangleRoundedLines(rec.getCStruct(), roundness, segments, lineThick, color.getCStruct());
}

inline void Raylib::Rectangle::imageDrawRectangle(Image *dst, int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const
{
    ::Image c_dst = dst->getCStruct();

    return ::ImageDrawRectangle(&c_dst, posX, posY, width, height, color.getCStruct());
}

inline void Raylib::Rectangle::imageDrawRectangleV(Raylib::Image *dst, ::Vector2 const &position, ::Vector2 const &size, Raylib::Color const &color) const
{
    ::Image c_dst = dst->getCStruct();

    return ::ImageDrawRectangleV(&c_dst, position, size, color.getCStruct());
}

inline void Raylib::Rectangle::imageDrawRectangleRec(Raylib::Image *dst, Raylib::Rectangle const &rec, Raylib::Color const &color) const
{
    ::Image c_dst = dst->getCStruct();

    return ::ImageDrawRectangleRec(&c_dst, rec.getCStruct(), color.getCStruct());
}

inline void Raylib::Rectangle::imageDrawRectangleLines(Raylib::Image *dst, Raylib::Rectangle const &rec, int const &thick, Raylib::Color const &color) const
{
    ::Image c_dst = dst->getCStruct();

    return ::ImageDrawRectangleLines(&c_dst, rec.getCStruct(), thick, color.getCStruct());
}

inline ::Rectangle Raylib::Rectangle::getImageAlphaBorder(Raylib::Image const &image, float const &threshold) const
{
    return ::GetImageAlphaBorder(image.getCStruct(), threshold);
}