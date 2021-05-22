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

inline ::Texture Raylib::Texture::getCStruct(void) const
{
    return _texture;
}

inline void Raylib::Texture::set(const ::Texture &texture)
{
    _texture = texture;
}

inline void Raylib::Texture::set(const Texture &texture)
{
    _texture = texture._texture;
}

inline void Raylib::Texture::setShapesTexture(Texture const &texture, Rectangle const &source) const
{
    ::SetShapesTexture(texture._texture, source.getCStruct());
}

inline Raylib::Texture &Raylib::Texture::loadTexture(const char *fileName)
{
    _texture = ::LoadTexture(fileName);
    return *this;
}

inline Raylib::Texture &Raylib::Texture::loadTextureFromImage(Image const &image)
{
    _texture = ::LoadTextureFromImage(image.getCStruct());
    return *this;
}

inline void Raylib::Texture::beginTextureMode(RenderTexture const &target) const
{
    ::BeginTextureMode(target.getCStruct());
}

inline void Raylib::Texture::endTextureMode(void) const
{
    ::EndTextureMode();
}

inline Raylib::TextureCubemap Raylib::Texture::loadTextureCubemap(Image const &image, int const &layout)
{
    _texture = ::LoadTextureCubemap(image.getCStruct(), layout);
    return *this;
}


inline void Raylib::Texture::updateTexture(Texture const &texture, const void *pixels) const
{

}

inline void Raylib::Texture::updateTextureRec(Texture const &texture, Rectangle const &rec, const void *pixels) const
{

}

inline Raylib::Image Raylib::Texture::getTextureData(Texture const &texture) const
{

}

inline Raylib::Image Raylib::Texture::getScreenData(void) const
{

}

inline void Raylib::Texture::genTextureMipmaps(Texture const *texture) const
{
    
}

inline void Raylib::Texture::setTextureFilter(Texture const &texture, int const &filter) const
{

}
inline void Raylib::Texture::setTextureWrap(Texture const &texture, int const &wrap) const
{

}

inline Raylib::Texture Raylib::Texture::drawTexture(const int &posX, const int &posY, const Color &tint = Color::Black()) const
{
    ::DrawTexture(_texture, posX, posY, tint.getCStruct());
    return *this;
}

inline void Raylib::Texture::drawTextureV(Texture const &texture, Vector2 const &position, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTextureEx(Texture const &texture, Vector2 const &position, float const &rotation, float const &scale, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTextureRec(Texture const &texture, Rectangle const &source, Vector2 const &position, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTextureQuad(Texture const &texture, Vector2 const &tiling, Vector2 const &offset, Rectangle const &quad, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTextureTiled(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, float const &scale, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTexturePro(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black()) const
{

}

inline void Raylib::Texture::drawTextureNPatch(Texture const &texture, NPatchInfo const &nPatchInfo, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black()) const
{

}

inline void drawTexturePoly(Texture texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointsCount, Color tint)
{

}

inline void Raylib::Texture::set(const ::Texture &texture)
{

}

inline void Raylib::Texture::set(const Texture &texture)
{

}