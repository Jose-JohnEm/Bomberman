/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

inline Raylib::Texture &Raylib::Texture::operator=(const Texture &texture)
{
    set(texture);
    return *this;
}

inline void Raylib::Texture::set(const ::Texture &texture)
{
    _texture = texture;
}

inline void Raylib::Texture::set(const Texture &texture)
{
    _texture = texture._texture;
}

inline Raylib::Texture &Raylib::Texture::drawTexture(const int &posX, const int &posY, const Raylib::Color &tint)
{
    ::DrawTexture(_texture, posX, posY, tint.getCStruct());
    return *this;
}
