/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

/*#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATIONs(R)3 Controller"
#endif
*/

#include <iostream>
#include "Text/Text.hpp"
#include "Gamepad/Gamepad.hpp"
#include "Mouse/Mouse.hpp"

class Input {
    public:

        enum GamePadTouch {
            UP,
            RIGHT,
            DOWN,
            LEFT,
            TRIANGLE,
            ROND,
            CROIX,
            CARRE,
            L1,
            L2,
            R1,
            R2,
            SHARE,
            UNKNOWN,
            OPTIONS,
            L3,
            R3
        };

        /**
         * @brief Construct a new Input object
         */
        Input();

        /**
         * @brief Destroy the Input object
         */
        ~Input();

        /**
         * @brief Get and Set Gamepad Input
         */
        static void updateGamepad();

    private:
        std::map<GamePadTouch, int> _inputs;

};

#endif /* !XRAY_HPP_ */