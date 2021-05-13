/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
#define MOUSE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Mouse {

        public:
            /**
             * @brief Construct a new Mouse object
             */
            Mouse();

            /**
             * @brief Destroy the Mouse object
             */
            ~Mouse();

            /**
             * @brief Detect if a mouse button has been pressed once
             *
             * @param button A size_t
             * @return true if $button has been pressed once, false otherwise
             */
            bool isButtonPressed(const size_t &button) const;

            /**
             * @brief Detect if a mouse button is being pressed
             *
             * @param button A size_t
             * @return true if $button is being pressed, false otherwise
             */
            bool isButtonDown(const size_t &button) const;

            /**
             * @brief Detect if a mouse button has been released once
             *
             * @param button A size_t
             * @return true if $button has been released once, false otherwise
             */
            bool isButtonReleased(const size_t &button) const;

            /**
             * @brief Detect if a mouse button is NOT being pressed
             *
             * @param button A size_t
             * @return true if $button is NOT being pressed, false otherwise
             */
            bool isButtonUp(const size_t &button) const;

            /**
             * @brief Returns mouse position X
             *
             * @return A size_t that represents position of mouse on x-axis
             */
            size_t getMouseX() const;

            /**
             * @brief Returns mouse position Y
             *
             * @return A size_t that represents position of mouse on y-axis
             */
            size_t getMouseY() const;

            /**
             * @brief Set the Mouse Position XY
             *
             * @param x Position of Mouse on x-axis
             * @param y Position of Mouse on y-axis
             */
            void setMousePosition(const size_t &x, const size_t &y) const;

            /**
             * @brief Set the Mouse Offset
             *
             * @param offsetX A size_t
             * @param offsetY A size_t
             */
            void setMouseOffset(const size_t &offsetX, const size_t &offsetY) const;

            /**
             * @brief Set the Mouse Scale
             *
             * @param scaleX A size_t
             * @param scaleY A size_t
             */
            void setMouseScale(const float &scaleX, const float &scaleY) const;

            /**
             * @brief Get the Mouse Wheel Move
             *
             * @return float, that represents mouse wheel move
             */
            float getMouseWheelMove() const;

            /**
             * @brief Set the Mouse Cursor
             *
             * @param cursor A size_t
             */
            void setMouseCursor(const size_t &cursor) const;

            /**
             * @brief Returns touch position X for touch point 0 (relative to screen size)
             *
             * @return A size_t
             */
            size_t getTouchX() const;

            /**
             * @brief Returns touch position Y for touch point 0 (relative to screen size)
             *
             * @return A size_t
             */
            size_t getTouchY() const;
    };

    #include "Mouse.inl"
}

#endif /* !MOUSE_HPP_ */
