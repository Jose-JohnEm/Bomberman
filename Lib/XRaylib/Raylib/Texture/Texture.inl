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

//FIXME:inline void Raylib::Texture::setShapesTexture(Texture const &texture, Rectangle const &source) const
//FIXME:{
//FIXME:    ::SetShapesTexture(texture._texture, source.getCStruct());
//FIXME:}

inline Raylib::Texture &Raylib::Texture::loadTexture(const char *fileName)
{
    _texture = ::LoadTexture(fileName);
    return *this;
}

//FIXME:inline Raylib::Texture &Raylib::Texture::loadTextureFromImage(Image const &image)
//FIXME:{
//FIXME:    _texture = ::LoadTextureFromImage(image.getCStruct());
//FIXME:    return *this;
//FIXME:}

inline void Raylib::Texture::beginTextureMode(RenderTexture const &target) const
{
    ::BeginTextureMode(target.getCStruct());
}

inline void Raylib::Texture::endTextureMode(void) const
{
    ::EndTextureMode();
}

//FIXME:inline Raylib::Texture Raylib::Texture::loadTextureCubemap(Image const &image, int const &layout)
//FIXME:{
//FIXME:    _texture = ::LoadTextureCubemap(image.getCStruct(), layout);
//FIXME:    return *this;
//FIXME:}


inline void Raylib::Texture::updateTexture(Texture const &texture, const void *pixels) const
{
    ::UpdateTexture(texture._texture, pixels);
}

//FIXME:inline void Raylib::Texture::updateTextureRec(Texture const &texture, Rectangle const &rec, const void *pixels) const
//FIXME:{
//FIXME:    ::UpdateTextureRec(texture._texture, rec.getCStruct(), pixels);
//FIXME:}

inline void Raylib::Texture::genTextureMipmaps(Texture const *texture) const
{
    ::Texture c_texture = texture->getCStruct();

    ::GenTextureMipmaps(&c_texture);
}

inline void Raylib::Texture::setTextureFilter(Texture const &texture, int const &filter) const
{
    ::SetTextureFilter(texture._texture, filter);
}

inline void Raylib::Texture::setTextureWrap(Texture const &texture, int const &wrap) const
{
    ::SetTextureWrap(texture._texture, wrap);
}

inline Raylib::Texture Raylib::Texture::drawTexture(const int &posX, const int &posY, const Color &tint = Color::Black()) const
{
    ::DrawTexture(_texture, posX, posY, tint.getCStruct());
    return *this;
}

//FIXME:inline void Raylib::Texture::drawTextureV(Texture const &texture, Vector2 const &position, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureV(texture._texture, position, tint.getCStruct());
//FIXME:}
//FIXME:
//FIXME:inline void Raylib::Texture::drawTextureEx(Texture const &texture, Vector2 const &position, float const &rotation, float const &scale, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureEx(texture._texture, position, rotation, scale, tint.getCStruct());
//FIXME:}

//FIXME:inline void Raylib::Texture::drawTextureRec(Texture const &texture, Rectangle const &source, Vector2 const &position, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureRec(texture._texture, source.getCStruct(), position, tint.getCStruct());
//FIXME:}
//FIXME:
//FIXME:inline void Raylib::Texture::drawTextureQuad(Texture const &texture, Vector2 const &tiling, Vector2 const &offset, Rectangle const &quad, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureQuad(texture._texture, tiling, offset, quad.getCStruct(), tint.getCStruct());
//FIXME:}
//FIXME:
//FIXME:inline void Raylib::Texture::drawTextureTiled(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, float const &scale, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureTiled(texture._texture, source.getCStruct(), dest.getCStruct(), origin, rotation, scale, tint.getCStruct());
//FIXME:}
//FIXME:
//FIXME:inline void Raylib::Texture::drawTexturePro(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTexturePro(texture._texture, source.getCStruct(), dest.getCStruct(), origin, rotation, tint.getCStruct());
//FIXME:}
//FIXME:
//FIXME:inline void Raylib::Texture::drawTextureNPatch(Texture const &texture, NPatchInfo const &nPatchInfo, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black()) const
//FIXME:{
//FIXME:    ::DrawTextureNPatch(texture._texture, nPatchInfo, dest.getCStruct(), origin, rotation, tint.getCStruct());
//FIXME:}

//FIXME:inline void Raylib::Texture::drawTexturePoly(Texture texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointsCount, Color tint) const
//FIXME:{
//FIXME:    ::DrawTexturePoly(texture._texture, center, points, texcoords, pointsCount, tint.getCStruct());
//FIXME:}