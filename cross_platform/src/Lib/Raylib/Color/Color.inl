/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Color
*/

inline void Raylib::Color::set(const ::Color &color)
{
    _color = color;
}

inline void Raylib::Color::set(const Color &color)
{
    _color = color._color;
}

inline Raylib::Color &Raylib::Color::operator=(const ::Color &color)
{
    set(color);
    return *this;
}

inline ::Color Raylib::Color::getCStruct() const
{
    return _color;
}

inline Raylib::Color Raylib::Color::getColor(const std::string &color)
{
    return _colorFactory[color]();
}

inline Raylib::Color Raylib::Color::fade(Raylib::Color color, const float &alpha) const
{
    Raylib::Color col;

    col.set(::Fade(color.getCStruct(), alpha));
    return col;
}

inline size_t Raylib::Color::colorToInt(Raylib::Color color) const
{
    return ::ColorToInt(color.getCStruct());
}

inline Raylib::Color Raylib::Color::colorFromHSV(const float &hue, const float &saturation, const float &value) const
{
    Raylib::Color col;

    col.set(::ColorFromHSV(hue, saturation, value));
    return col;
}

inline Raylib::Color Raylib::Color::colorAlpha(Raylib::Color color, const float &alpha) const
{
    Raylib::Color col;

    col.set(::ColorAlpha(color.getCStruct(), alpha));
    return col;
}

inline Raylib::Color Raylib::Color::colorAlphaBlend(Color dst, Color src, Color tint) const
{
    Raylib::Color col;

    col.set(::ColorAlphaBlend(dst.getCStruct(), src.getCStruct(), tint.getCStruct()));
    return col;
}

inline Raylib::Color Raylib::Color::getColor(const size_t &hexValue) const
{
    Raylib::Color col;

    col.set(::GetColor(hexValue));
    return col;
}

inline Raylib::Color Raylib::Color::getPixelColor(void *srcPtr, const size_t &format) const
{
    Raylib::Color col;

    col.set(::GetPixelColor(srcPtr, format));
    return col;
}

inline void Raylib::Color::setPixelColor(void *dstPtr, Raylib::Color color, const size_t &format) const
{
    ::SetPixelColor(dstPtr, color.getCStruct(), format);
}

inline size_t Raylib::Color::getPixelDataSize(const size_t &width, const size_t &height, const size_t &format) const
{
    return ::GetPixelDataSize(width, height, format);
}

inline void Raylib::Color::clearBackground(Raylib::Color color) const //TODO: move in another class -> Drawing ?
{
    ::ClearBackground(color.getCStruct());
}

inline Raylib::Color Raylib::Color::LightGray()
{
    Raylib::Color col;

    col.set(::LIGHTGRAY);
    return col;
}

inline Raylib::Color Raylib::Color::Gray()
{
    Raylib::Color col;

    col.set(::GRAY);
    return col;
}

inline Raylib::Color Raylib::Color::DarkGray()
{
    Raylib::Color col;

    col.set(::DARKGRAY);
    return col;
}

inline Raylib::Color Raylib::Color::Yellow()
{
    Raylib::Color col;

    col.set(::YELLOW);
    return col;
}

inline Raylib::Color Raylib::Color::Gold()
{
    Raylib::Color col;

    col.set(::GOLD);
    return col;
}

inline Raylib::Color Raylib::Color::Orange()
{
    Raylib::Color col;

    col.set(::ORANGE);
    return col;
}

inline Raylib::Color Raylib::Color::Pink()
{
    Raylib::Color col;

    col.set(::PINK);
    return col;
}

inline Raylib::Color Raylib::Color::Red()
{
    Raylib::Color col;

    col.set(::RED);
    return col;
}

inline Raylib::Color Raylib::Color::Maroon()
{
    Raylib::Color col;

    col.set(::MAROON);
    return col;
}

inline Raylib::Color Raylib::Color::Green()
{
    Raylib::Color col;

    col.set(::GREEN);
    return col;
}

inline Raylib::Color Raylib::Color::Lime()
{
    Raylib::Color col;

    col.set(::LIME);
    return col;
}

inline Raylib::Color Raylib::Color::DarkGreen()
{
    Raylib::Color col;

    col.set(::DARKGREEN);
    return col;
}

inline Raylib::Color Raylib::Color::SkyBlue()
{
    Raylib::Color col;

    col.set(::SKYBLUE);
    return col;
}

inline Raylib::Color Raylib::Color::Blue()
{
    Raylib::Color col;

    col.set(::BLUE);
    return col;
}

inline Raylib::Color Raylib::Color::DarkBlue()
{
    Raylib::Color col;

    col.set(::DARKBLUE);
    return col;
}

inline Raylib::Color Raylib::Color::Purple()
{
    Raylib::Color col;

    col.set(::PURPLE);
    return col;
}

inline Raylib::Color Raylib::Color::Violet()
{
    Raylib::Color col;

    col.set(::VIOLET);
    return col;
}

inline Raylib::Color Raylib::Color::DarkPurple()
{
    Raylib::Color col;

    col.set(::DARKPURPLE);
    return col;
}

inline Raylib::Color Raylib::Color::Beige()
{
    Raylib::Color col;

    col.set(::BEIGE);
    return col;
}

inline Raylib::Color Raylib::Color::Brown()
{
    Raylib::Color col;

    col.set(::BROWN);
    return col;
}

inline Raylib::Color Raylib::Color::DarkBrown()
{
    Raylib::Color col;

    col.set(::DARKBROWN);
    return col;
}

inline Raylib::Color Raylib::Color::White()
{
    Raylib::Color col;

    col.set(::WHITE);
    return col;
}

inline Raylib::Color Raylib::Color::Black()
{
    Raylib::Color col;

    col.set(::BLACK);
    return col;
}

inline Raylib::Color Raylib::Color::Blank()
{
    Raylib::Color col;

    col.set(::BLANK);
    return col;
}

inline Raylib::Color Raylib::Color::Magenta()
{
    Raylib::Color col;

    col.set(::MAGENTA);
    return col;
}

inline Raylib::Color Raylib::Color::RayWhite()
{
    Raylib::Color col;

    col.set(::RAYWHITE);
    return col;
}