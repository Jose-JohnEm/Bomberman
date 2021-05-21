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
#include "Image/Image.hpp"
#include "Color/Color.hpp"
#include "Rectangle/Rectangle.hpp"

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

            /**
             * @brief Set texture and rectangle to be used on shapes drawing
             *
             * @param texture A Texture Object
             * @param source A Rectangle Object
             */
            void SetShapesTexture(Raylib::Texture const &texture, Rectangle const &source) const;

            /**
             * @brief Load texture from file into GPU memory (VRAM)
             *
             * @param texture A Texture Object
             * @param source A Rectangle Object
             * @return A reference to the texture - Texture&
             */
            Texture2D &LoadTexture(const char *fileName) const;

            /**
             * @brief Load texture from image data
             *
             * @param image A const reference to the Image Object
             * @return A reference to the texture - Texture&
             */
            Texture2D &LoadTextureFromImage(Raylib::Image const &image);
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

            ::Texture _texture; // Texture C structure
    };

    #include "Texture.inl"
}

#endif /* !TEXTURE_HPP_ */
