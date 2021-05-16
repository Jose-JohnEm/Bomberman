/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Font
*/

void Raylib::Font::unload() const
{
    ::UnloadFont(_font);
}

Raylib::Font &Raylib::Font::operator=(const Font &font)
{
    set(font);
    return *this;
}

void Raylib::Font::set(const ::Font &font)
{
    _font = font;
}

void Raylib::Font::set(const Font &font)
{
    _font = font._font;
}