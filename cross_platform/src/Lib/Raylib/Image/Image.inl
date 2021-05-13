/*
** EPITECH PROJECT, 2021
** cross_platform
** File description:
** Image
*/

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

inline void Raylib::Image::unloadImage(const Image &image)
{
    if (_data != NULL) {
        ::UnloadImage(_image);
        _data = NULL;
    }
}

inline bool Raylib::Image::exportImage(const Image &image, const std::string &fileName)
{
    return ::ExportImage(_image, fileName.c_str());
}

inline bool Raylib::Image::exportImageAsCode(const Image &image, const std::string &fileName)
{
    return ::ExportImageAsCode(_image, fileName.c_str());
}

inline int Raylib::Image::getPixelDataSize()
{
    return ::GetPixelDataSize(_width, _height, _format);
}

inline ::Image Raylib::Image::getCStruct() const
{
    return _image;
}

inline void Raylib::Image::set(const ::Image &image)
{
    _data = image.data;
    _width = image.width;
    _height = image.height;
    _mipmaps = image.mipmaps;
    _format = image.format;
}

inline void Raylib::Image::set(const Image &image)
{
    _data = image._data;
    _width = image._width;
    _height = image._height;
    _mipmaps = image._mipmaps;
    _format = image._format;
}

inline Raylib::Image &Raylib::Image::operator=(const Image &image)
{
    set(image);
    return *this;
}