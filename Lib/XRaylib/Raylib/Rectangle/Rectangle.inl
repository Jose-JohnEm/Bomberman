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


inline ::Rectangle Raylib::Rectangle::getCStruct(void) const
{
    return _rectangle;

}

inline void Raylib::Rectangle::drawRectangle(int const &posX, int const &posY, int const &width, int const &height, Color const &color) const
{
    return ::DrawRectangle(posX, posY, width, height, color.getCStruct());
}


inline void Raylib::Rectangle::drawRectangleV(const Vector2 &position, const Vector2 &size, const Color &color) const
{
    return ::DrawRectangleV(position.getCStruct(), size.getCStruct(), color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRec(Rectangle const &rec, Color const &color) const
{
    return ::DrawRectangleRec(rec.getCStruct(), color.getCStruct());
}

//FIXME:inline void Raylib::Rectangle::drawRectanglePro(Rectangle const &rec, ::Vector2 const &origin, float const &rotation, Color const &color) const
//FIXME:{
//FIXME:    return  ::DrawRectanglePro(rec.getCStruct(), origin, rotation, color.getCStruct());
//FIXME:}

inline void Raylib::Rectangle::drawRectangleGradientV(int const &posX, int const &posY, int const &width, int const &height, Color const &color1, Color const &color2) const
{
    return ::DrawRectangleGradientV(posX, posY, width, height, color1.getCStruct(), color2.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleGradientH(int const &posX, int const &posY, int const &width, int const &height, Color const &color1, Color const &color2) const
{
    return ::DrawRectangleGradientH(posX, posY, width, height, color1.getCStruct(), color2.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleGradientEx(Rectangle const &rec, Color const &col1, Color const &col2, Color const &col3, Color const &col4) const
{
    return ::DrawRectangleGradientEx(rec.getCStruct(), col1.getCStruct(), col2.getCStruct(), col3.getCStruct(), col4.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleLines(int const &posX, int const &posY, int const &width, int const &height, Color const &color) const
{
    return ::DrawRectangleLines(posX, posY, width, height, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleLinesEx(Rectangle const &rec, int const &lineThick, Color const &color) const
{
    return ::DrawRectangleLinesEx(rec.getCStruct(), lineThick, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRounded(Rectangle const &rec, float const &roundness, int const &segments, Color const &color) const
{
    return ::DrawRectangleRounded(rec.getCStruct(), roundness, segments, color.getCStruct());
}

inline void Raylib::Rectangle::drawRectangleRoundedLines(Rectangle const &rec, float const &roundness, int const &segments, int const &lineThick, Color const &color) const
{
    return ::DrawRectangleRoundedLines(rec.getCStruct(), roundness, segments, lineThick, color.getCStruct());
}