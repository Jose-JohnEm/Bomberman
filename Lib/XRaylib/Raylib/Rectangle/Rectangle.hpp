/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Color/Color.hpp"
#include "Image/Image.hpp"
#include "Texture/Texture.hpp"


namespace Raylib
{
    class Rectangle {

        public:
            /**
             * @brief Construct a new Rectangle object with parameters
             * 
             * @param x Position X
             * @param y Position Y
             * @param width The width of the rectangle
             * @param height The height of the rectangle
             */
            Rectangle(float x = 0, float y = 0, float width = 0, float height = 0);
            Rectangle(::Vector2 position, ::Vector2 size);
            Rectangle(::Vector2 size);
            Rectangle &operator=(const Rectangle &rectangle);

            /**
             * @brief Destroy the Rectangle object
             */
            ~Rectangle();
            ::Rectangle getCStruct(void) const;
            void drawRectangle(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const;
            void drawRectangleV(::Vector2 const &position, ::Vector2 const &size, Raylib::Color const &color) const;
            void drawRectangleRec(Raylib::Rectangle const &rec, Raylib::Color const &color) const;
            void drawRectanglePro(Raylib::Rectangle const &rec, ::Vector2 const &origin, float const &rotation, Raylib::Color const &color) const;
            void drawRectangleGradientV(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color1, Raylib::Color const &color2) const;
            void drawRectangleGradientH(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color1, Raylib::Color const &color2) const;
            void drawRectangleGradientEx(Raylib::Rectangle const &rec, Raylib::Color const &col1, Raylib::Color const &col2, Raylib::Color const &col3, Raylib::Color const &col4) const;
            void drawRectangleLines(int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const;
            void drawRectangleLinesEx(Raylib::Rectangle const &rec, int const &lineThick, Raylib::Color const &color) const;
            void drawRectangleRounded(Raylib::Rectangle const &rec, float const &roundness, int const &segments, Raylib::Color const &color) const;
            void drawRectangleRoundedLines(Raylib::Rectangle const &rec, float const &roundness, int const &segments, int const &lineThick, Raylib::Color const &color) const;
            void imageDrawRectangle(Raylib::Image *dst, int const &posX, int const &posY, int const &width, int const &height, Raylib::Color const &color) const;
            void imageDrawRectangleV(Raylib::Image *dst, ::Vector2 const &position, ::Vector2 const &size, Raylib::Color const &color) const;
            void imageDrawRectangleRec(Raylib::Image *dst, Raylib::Rectangle const &rec, Raylib::Color const &color) const;
            void imageDrawRectangleLines(Raylib::Image *dst, Raylib::Rectangle const &rec, int const &thick, Raylib::Color const &color) const;
            ::Rectangle getImageAlphaBorder(Raylib::Image const &image, float const &threshold) const;
        private:
            /**
             * @brief Set Rectangle
             *
             * @param Rectangle A Rectangle C Structure
             */
            void set(const ::Rectangle &texture);

            /**
             * @brief Set Rectangle
             *
             * @param Rectangle A const reference to a Rectangle object
             */
            void set(const Rectangle &texture);

            ::Rectangle _rectangle; // Rectangle C structure
    };

    #include "Rectangle.inl"
}

#endif /* !RECTANGLE_HPP_ */
