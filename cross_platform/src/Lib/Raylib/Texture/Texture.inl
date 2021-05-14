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
    _id = texture.id;
    _width = texture.width;
    _height = texture.height;
    _mipmaps = texture.mipmaps;
    _format = texture.format;
}

inline void Raylib::Texture::set(const Texture &texture)
{
    _id = texture._id;
    _width = texture._width;
    _height = texture._height;
    _mipmaps = texture._mipmaps;
    _format = texture._format;
}

inline Raylib::Texture &Raylib::Texture::drawTexture(const int &posX, const int &posY, const Raylib::Color &tint)
{
    ::DrawTexture(_texture, posX, posY, tint.getCStruct());
    return *this;
}
