/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
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

inline Raylib::Image &Raylib::Image::operator=(const Image &image)
{
    set(image);
    return *this;
}