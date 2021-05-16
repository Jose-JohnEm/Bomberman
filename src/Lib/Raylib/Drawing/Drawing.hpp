/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Drawing
*/

#ifndef DRAWING_HPP_
#define DRAWING_HPP_

#include "../Color/Color.hpp"

namespace Raylib
{
    class Drawing {

        public:
            /**
             * @brief Construct a new Drawing object
             */
            Drawing();

            /**
             * @brief Destroy the Drawing object
             */
            ~Drawing();

            /**
             * @brief Set background color (framebuffer clear color)
             * 
             * @param color A Color Object
             */
            void clearBackground(const Color &color) const;

            /**
             * @brief Setup canvas (framebuffer) to start drawing
             */
            void beginDrawing(void) const;

            /**
             * @brief End canvas drawing and swap buffers (double buffering)
             */
            void endDrawing(void) const;
    };

    #include "Drawing.inl"
}

#endif /* !DRAWING_HPP_ */
