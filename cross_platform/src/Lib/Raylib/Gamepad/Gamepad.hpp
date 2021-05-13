/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Gamepad {

        public:
            /**
             * @brief Construct a new Gamepad object
             */
            Gamepad();

            /**
             * @brief Destroy the Gamepad object
             */
            ~Gamepad();

            /**
             * @brief Detect if a gamepad is available
             *
             * @param gamepad
             * @return true if a gamepad is available, otherwise false
             */
            bool isGamepadAvailable(const int &gamepad) const;

            /**
             * @brief Check gamepad name (if available)
             *
             * @param gamepad A int
             * @param name A string
             * @return true or false
             */
            bool isGamepadName(const int &gamepad, const std::string &name) const;

            /**
             * @brief Return gamepad internal name id
             *
             * @param gamepad A int
             * @return const std::string
             */
            std::string getGamepadName(const int &gamepad) const;

            /**
             * @brief Detect if a gamepad button has been pressed once
             *
             * @param gamepad A int
             * @param button A int
             * @return true or false
             */
            bool isGamepadButtonPressed(const int &gamepad, const int &button) const;

            /**
             * @brief Detect if a gamepad button is being pressed
             *
             * @param gamepad A int
             * @param button A int
             * @return true or false
             */
            bool isGamepadButtonDown(const int &gamepad, const int &button) const;

            /**
             * @brief Detect if a gamepad button has been released once
             *
             * @param gamepad A int
             * @param button A int
             * @return true or false
             */
            bool isGamepadButtonReleased(const int &gamepad, const int &button) const;

            /**
             * @brief Detect if a gamepad button is NOT being pressed
             *
             * @param gamepad A int
             * @param button A int
             * @return true or false
             */
            bool isGamepadButtonUp(const int &gamepad, const int &button) const;

            /**
             * @brief Get the last gamepad button pressed
             *
             * @return A int
             */
            int getGamepadButtonPressed(void) const;

            /**
             * @brief Return gamepad axis count for a gamepad
             *
             * @param gamepad A int
             * @return A int
             */
            int getGamepadAxisCount(const int &gamepad) const;

            /**
             * @brief Return axis movement value for a gamepad axis
             *
             * @param gamepad A int
             * @param axis A int
             * @return A float
             */
            float getGamepadAxisMovement(const int &gamepad, const int &axis) const;

            /**
             * @brief Set internal gamepad mappings (SDL_GameControllerDB)
             *
             * @param mappings A string
             * @return A int
             */
            int setGamepadMappings(const std::string &mappings) const;
    };

    #include "Gamepad.inl"
}

#endif /* !GAMEPAD_HPP_ */
