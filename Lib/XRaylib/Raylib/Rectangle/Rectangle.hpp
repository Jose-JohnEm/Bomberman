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
            void drawRectangle(int const &posX, int const &posY, int const &width, int const &height, Color const &color) const;
            void drawRectangleV(::Vector2 const &position, ::Vector2 const &size, Color const &color) const;
            void drawRectangleRec(Rectangle const &rec, Color const &color) const;
            void drawRectanglePro(Rectangle const &rec, ::Vector2 const &origin, float const &rotation, Color const &color) const;
            void drawRectangleGradientV(int const &posX, int const &posY, int const &width, int const &height, Color const &color1, Color const &color2) const;
            void drawRectangleGradientH(int const &posX, int const &posY, int const &width, int const &height, Color const &color1, Color const &color2) const;
            void drawRectangleGradientEx(Rectangle const &rec, Color const &col1, Color const &col2, Color const &col3, Color const &col4) const;
            void drawRectangleLines(int const &posX, int const &posY, int const &width, int const &height, Color const &color) const;
            void drawRectangleLinesEx(Rectangle const &rec, int const &lineThick, Color const &color) const;
            void drawRectangleRounded(Rectangle const &rec, float const &roundness, int const &segments, Color const &color) const;
            void drawRectangleRoundedLines(Rectangle const &rec, float const &roundness, int const &segments, int const &lineThick, Color const &color) const;
            void imageDrawRectangle(Image *dst, int const &posX, int const &posY, int const &width, int const &height, Color const &color) const;
            void imageDrawRectangleV(Image *dst, ::Vector2 const &position, ::Vector2 const &size, Color const &color) const;
            void imageDrawRectangleRec(Image *dst, Rectangle const &rec, Color const &color) const;
            void imageDrawRectangleLines(Image *dst, Rectangle const &rec, int const &thick, Color const &color) const;
            ::Rectangle getImageAlphaBorder(Image const &image, float const &threshold) const;
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
