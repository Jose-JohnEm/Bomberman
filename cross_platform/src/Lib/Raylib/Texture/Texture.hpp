/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Raylib/Image/Image.hpp"
#include "Raylib/Color/Color.hpp"

namespace Raylib
{
    class Texture {

        public:
            /**
             * @brief Construct a new Texture object
             */
            Texture(const std::string &fileName);

            /**
             * @brief Construct a new Texture object
             */
            Texture(const Raylib::Image &image);

            /**
             * @brief Destroy the Texture object
             */
            ~Texture();

            /**
             * @brief Overload of '=' operator
             *
             * @param music A const reference to a Texture
             * @return A reference to Texture (Texture &)
             */
            Texture &operator=(const Texture &texture);

            /**
             * @brief Draw a Texture2D with position XY
             *
             * @param posX A size_t
             * @param posY A size_t
             * @param tint A Color
             * @return A reference to the texture - Texture&
             */
            Texture &drawTexture(const int &posX, const int &posY, const Color &tint = Color::Black());

        private:
            /**
             * @brief Set Texture
             *
             * @param texture A Texture C Structure
             */
            void set(const ::Texture &texture);

            /**
             * @brief Set Texture
             *
             * @param texture A const reference to a Texture object
             */
            void set(const Texture &texture);

            unsigned int _id;        // OpenGL texture id
            int _width;              // Texture base width
            int _height;             // Texture base height
            int _mipmaps;            // Mipmap levels, 1 by default
            int _format;             // Data format (PixelFormat type)

            ::Texture _texture = {_id, _width, _height, _mipmaps, _format};
    };

    #include "Texture.inl"
}

#endif /* !TEXTURE_HPP_ */
