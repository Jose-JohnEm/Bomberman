/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

#include "Texture.hpp"

Raylib::Texture::Texture(const std::string &fileName)
{
    _texture = ::LoadTexture(fileName.c_str());
}

Raylib::Texture::Texture(const Raylib::Image &image)
{
    _texture = ::LoadTextureFromImage(image.getCStruct());
}

Raylib::Texture::~Texture()
{
    // FIXME: Find why shared_ptr in Xray segfault here
//    ::UnloadTexture(_texture);
}