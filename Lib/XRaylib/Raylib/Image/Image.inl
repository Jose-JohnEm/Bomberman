/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Image
*/

inline ::Image Raylib::Image::getCStruct(void) const
{
    return _image;
}

inline void Raylib::Image::set(const ::Image &image)
{
    _image = image;
}

inline void Raylib::Image::set(const Image &image)
{
    _image = image._image;
}

inline Raylib::Image Raylib::Image::getScreenData(void)
{
    _image = ::GetScreenData();
    return *this;
}

inline Raylib::Image Raylib::Image::loadImage(const std::string &fileName)
{
    _image = ::LoadImage(fileName.c_str());
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageRaw(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize)
{
    _image = ::LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageAnim(const std::string &fileName, int *frames)
{
    _image = ::LoadImageAnim(fileName.c_str(), frames);
    return *this;
}

inline Raylib::Image Raylib::Image::loadImageFromMemory(const std::string &fileType, const std::string &fileData, const int &dataSize)
{
    set(::LoadImageFromMemory(fileType.c_str(), (const unsigned char *)fileData.c_str(), dataSize));
    return *this;
}

inline void Raylib::Image::unloadImage(void)
{
    if (_image.data != NULL) {
        ::UnloadImage(_image);
        _image.data = NULL;
    }
}

inline bool Raylib::Image::exportImage(const Image &image, const std::string &fileName) const
{
    return ::ExportImage(_image, fileName.c_str());
}

inline bool Raylib::Image::exportImageAsCode(const Image &image, const std::string &fileName) const
{
    return ::ExportImageAsCode(_image, fileName.c_str());
}

inline int Raylib::Image::getPixelDataSize(void) const
{
    return ::GetPixelDataSize(_image.width, _image.height, _image.format);
}

inline Raylib::Image &Raylib::Image::operator=(const Image &image)
{
    set(image);
    return *this;
}

inline Raylib::Image Raylib::Image::getTextureData(Texture const &texture) const
{
    ::GetTextureData(texture.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageColor(int const &width, int const &height, Color const &color)
{
    ::GenImageColor(width, height, color.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientV(int const &width, int const &height, Color const &top, Color const &bottom)
{
    ::GenImageGradientV(width, height, top.getCStruct(), bottom.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientH(int const &width, int const &height, Color const &left, Color const &right)
{
    ::GenImageGradientH(width, height, left.getCStruct(), right.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageGradientRadial(int const &width, int const &height, float density, Color inner, Color outer)
{
    ::GenImageGradientRadial(width, height, density, inner.getCStruct(), outer.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageChecked(int const &width, int const &height, int const &checksX, int const &checksY, Color col1, Color col2)
{
    ::GenImageChecked(width, height, checksX, checksY, col1.getCStruct(), col2.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::genImageWhiteNoise(int const &width, int const &height, float const &factor)
{
    ::GenImageWhiteNoise(width, height, factor);
    return *this;
}

inline Raylib::Image Raylib::Image::genImagePerlinNoise(int const &width, int const &height, int offsetX, int offsetY, float scale)
{
    ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    return *this;
}

inline Raylib::Image Raylib::Image::genImageCellular(int const &width, int const &height, int const &tileSize)
{
    ::GenImageCellular(width, height, tileSize);
    return *this;
}

inline Raylib::Image Raylib::Image::imageCopy(Image const &image)
{
    ::ImageCopy(image.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::imageFromImage(Image const &image, Rectangle const &rec)
{
    ::ImageFromImage(image.getCStruct(), rec.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::imageText(const char *text, int const &fontSize, Color const &color)
{
    ::ImageText(text, fontSize, color.getCStruct());
    return *this;
}

inline Raylib::Image Raylib::Image::imageTextEx(Font const &font, const char *text, float const &fontSize, float const &spacing, Color const &tint)
{
    ::ImageTextEx(font.getCStruct(), text, fontSize, spacing, tint.getCStruct());
    return *this;
}
inline void Raylib::Image::imageFormat(Image *image, int const &newFormat) const
{
    ::ImageFormat(&image->getCStruct(), newFormat);
}

inline void Raylib::Image::imageToPOT(Image *image, Color const &fill) const
{
    ::ImageToPOT(&image->getCStruct(), fill.getCStruct());
}

inline void Raylib::Image::imageCrop(Image *image, Rectangle const &crop) const
{
    ::ImageCrop(&image->getCStruct(), crop.getCStruct());
}

inline void Raylib::Image::imageAlphaCrop(Image *image, float const &threshold) const
{
    ::ImageAlphaCrop(&image->getCStruct(), threshold);
}

inline void Raylib::Image::imageAlphaClear(Image *image, Color const &color, float const &threshold) const
{
    ::ImageAlphaClear(&image->getCStruct(), color.getCStruct(), threshold);
}

inline void Raylib::Image::imageAlphaMask(Image *image, Image const &alphaMask) const
{
    ::ImageAlphaMask(&image->getCStruct(), alphaMask.getCStruct());
}

inline void Raylib::Image::imageAlphaPremultiply(Image *image) const
{
    ::ImageAlphaPremultiply(&image->getCStruct());
}

inline void Raylib::Image::imageResize(Image *image, int const &newWidth, int const &newHeight) const
{
    ::ImageResize(&image->getCStruct(), newWidth, newHeight);
}

inline void Raylib::Image::imageResizeNN(Image *image, int newWidth, int const &newHeight) const
{
    ::ImageResizeNN(&image->getCStruct(), newWidth, newHeight);
}

inline void Raylib::Image::imageResizeCanvas(Image *image, int const &newWidth, int const &newHeight, int const &offsetX, int const &offsetY, Color const &fill) const
{
    ::ImageResizeCanvas(&image->getCStruct(), newWidth, newHeight, offsetX, offsetY, fill.getCStruct());
}

inline void Raylib::Image::imageMipmaps(Image *image) const
{
    ::ImageMipmaps(&image->getCStruct());
}

inline void Raylib::Image::imageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp) const
{
    ::ImageDither(&image->getCStruct(), rBpp, gBpp, bBpp, aBpp);
}

inline void Raylib::Image::imageFlipVertical(Image *image) const
{
    ::ImageFlipVertical(&image->getCStruct());
}

inline void Raylib::Image::imageFlipHorizontal(Image *image) const
{
    ::ImageFlipHorizontal(&image->getCStruct());
}

inline void Raylib::Image::imageRotateCW(Image *image) const
{
    ::ImageRotateCW(&image->getCStruct());
}

inline void Raylib::Image::imageRotateCCW(Image *image) const
{
    ::ImageRotateCCW(&image->getCStruct());
}

inline void Raylib::Image::imageColorTint(Image *image, Color const &color) const
{
    ::ImageColorTint(&image->getCStruct(), color.getCStruct());
}

inline void Raylib::Image::imageColorInvert(Image *image) const
{
    ::ImageColorInvert(&image->getCStruct());
}

inline void Raylib::Image::imageColorGrayscale(Image *image) const
{
    ::ImageColorGrayscale(&image->getCStruct());
}

inline void Raylib::Image::imageColorContrast(Image *image, float const &contrast) const
{
    ::ImageColorContrast(&image->getCStruct(), contrast);
}

inline void Raylib::Image::imageColorBrightness(Image *image, int const &brightness)
{
    ::ImageColorBrightness(&image->getCStruct(), brightness);
}

inline void Raylib::Image::imageColorReplace(Image *image, Color const &color, Color const &replace)
{
    ::ImageColorReplace(&image->getCStruct(), color.getCStruct(), replace.getCStruct());
}

inline void Raylib::Image::unloadImageColors(Color *colors)
{
    ::UnloadImageColors(&colors->getCStruct());
}

inline void Raylib::Image::unloadImagePalette(Color *colors)
{
    ::UnloadImagePalette(&colors->getCStruct());
}

inline void Raylib::Image::imageClearBackground(Image *dst, Color const &color)
{
    ::ImageClearBackground(&dst->getCStruct(), color.getCStruct());
}

inline void Raylib::Image::imageDrawPixel(Image *dst, int const &posX, int const &posY, Color const &color)
{
    ::ImageDrawPixel(&dst->getCStruct(), posX, posY, color.getCStruct());
}

inline void Raylib::Image::imageDrawPixelV(Image *dst, Vector2 const &position, Color const &color)
{
    ::ImageDrawPixelV(&dst->getCStruct(), position, color.getCStruct());
}

inline void Raylib::Image::imageDrawLine(Image *dst, int const &startPosX, int const &startPosY, int const &endPosX, int const &endPosY, Color const &color)
{
    ::ImageDrawLine(&dst->getCStruct(), startPosX, startPosY, endPosX, endPosY, color.getCStruct());
}

inline void Raylib::Image::imageDrawLineV(Image *dst, Vector2 const &start, Vector2 const &end, Color const &color)
{
    ::ImageDrawLineV(&dst->getCStruct(), start, end, color.getCStruct());
}

inline void Raylib::Image::imageDrawCircle(Image *dst, int const &centerX, int const &centerY, int const &radius, Color const &color)
{
    ::ImageDrawCircle(&dst->getCStruct(), centerX, centerY, radius, color.getCStruct());
}

inline void Raylib::Image::imageDrawCircleV(Image *dst, Vector2 const &center, int const &radius, Color const &color)
{
    ::ImageDrawCircleV(&dst->getCStruct(), center, radius, color.getCStruct());
}

inline void Raylib::Image::imageDraw(Image *dst, Image const &src, Rectangle const &srcRec, Rectangle const &dstRec, Color const &tint)
{
    ::ImageDraw(&dst->getCStruct(), src.getCStruct(), srcRec.getCStruct(), dstRec.getCStruct(), tint.getCStruct());
}

inline void Raylib::Image::imageDrawText(Image *dst, const char *text, int const &posX, int const &posY, int const &fontSize, Color const &color) const
{
    ::ImageDrawText(&dst->getCStruct(), text, posX, posY, fontSize, color.getCStruct());
}

inline void Raylib::Image::imageDrawTextEx(Image *dst, Font const &font, const char *text, Vector2 const &position, float const &fontSize, float const &spacing, Color const &tint)
{
    ::ImageDrawTextEx(&dst->getCStruct(), font.getCStruct(), text, position, fontSize, spacing, tint.getCStruct());
}
