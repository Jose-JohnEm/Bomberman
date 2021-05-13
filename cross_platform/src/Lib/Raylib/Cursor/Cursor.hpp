/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cursor
*/

#ifndef CURSOR_HPP_
#define CURSOR_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Cursor {

        public:
            /**
             * @brief Construct a new Cursor object
             */
            Cursor();

            /**
             * @brief Destroy the Cursor object
             */
            ~Cursor();

            /**
             * @brief Shows cursor
             */
            void showCursor(void) const;

            /**
             * @brief Hides cursor
             */
            void hideCursor(void) const;

            /**
             * @brief Check if cursor is not visible
             *
             * @return true or false
             */
            bool isCursorHidden(void) const;

            /**
             * @brief Enables cursor (unlock cursor)
             */
            void enableCursor(void) const;

            /**
             * @brief Disables cursor (lock cursor)
             */
            void disableCursor(void) const;

            /**
             * @brief Check if cursor is on the current screen.
             *
             * @return true if cursor is on the current screen, false otherwise
             * @return false
             */
            bool isCursorOnScreen(void) const;

    };

    #include "Cursor.inl"
}

#endif /* !CURSOR_HPP_ */
