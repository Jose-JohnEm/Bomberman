/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Timing
*/

#ifndef TIMING_HPP_
#define TIMING_HPP_

#include "raylib.h"

namespace Raylib
{
    class Timing {

        public:
            /**
             * @brief Construct a new Timing object
             */
            Timing();

            /**
             * @brief Destroy the Timing object
             */
<<<<<<< HEAD
            ~Timing();
=======
            ~Timing(void);
>>>>>>> release/v0.3

            /**
             * @brief Set Framerate Per Second
             *
             * @param fps An int
             */
            static void setTargetFPS(const int &fps);

            /**
             * @brief Get Framerate Per Second
             *
             * @return The current FPS - int
             */
            static int getFPS(void);

            /**
             * @brief Get frame time
             *
             * @return The time in seconds for last frame drawn (delta time) - float
             */
            static float getFrameTime(void);

            /**
             * @brief Get time since window initialization
             *
<<<<<<< HEAD
             * @return The elapsed time in seconds since InitWindow() - double
=======
             * @return The elapsed time in seconds since InitWindow(void) - double
>>>>>>> release/v0.3
             */
            static double getTime(void);
    };

    #include "Timing.inl"
}

#endif /* !TIMING_HPP_ */
