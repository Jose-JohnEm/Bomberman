/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Keyboard {

        public:
            /**
             * @brief Construct a new Keyboard object
             */
            Keyboard();

            /**
             * @brief Destroy the Keyboard object
             */
            ~Keyboard();

            /**
             * @brief Detect if a key has been pressed once
             *
             * @param key A size_t
             * @return true if key has been pressed once, false otherwise
             */
            bool isKeyPressed(const size_t &key) const;

            /**
             * @brief Detect if a key is being pressed
             *
             * @param key A size_t
             * @return true if key is being pressed, false otherwise
             */
            bool isKeyDown(const size_t &key) const;

            /**
             * @brief Detect if a key has been released once
             *
             * @param key A size_t
             * @return true if key has been released once, false otherwise
             */
            bool isKeyReleased(const size_t &key) const;

            /**
             * @brief Detect if a key is NOT being pressed
             *
             * @param key A size_t
             * @return true if key is NOT being pressed, false otherwise
             */
            bool isKeyUp(const size_t &key) const;

            /**
             * @brief Set a custom key to exit program (default is ESC)
             *
             * @param key A size_t
             */
            void setExitKey(const size_t &key) const;

            /**
             * @brief Get key pressed (keycode), call it multiple times for keys queued
             *
             * @return A size_t
             */
            size_t getKeyPressed(void) const;

            /**
             * @brief Get char pressed (unicode), call it multiple times for chars queued
             *
             * @return A size_t
             */
            size_t getCharPressed(void) const;
    };

    #include "Keyboard.inl"
}

#endif /* !KEYBOARD_HPP_ */
