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
            ~Timing();

            /**
             * @brief Set Framerate Per Second
             *
             * @param fps An int
             */
            void setTargetFPS(const int &fps) const;

            /**
             * @brief Get Framerate Per Second
             *
             * @return The current FPS - int
             */
            int getFPS(void) const;

            /**
             * @brief Get frame time
             *
             * @return The time in seconds for last frame drawn (delta time) - float
             */
            float getFrameTime(void) const;

            /**
             * @brief Get time since window initialization
             *
             * @return The elapsed time in seconds since InitWindow() - double
             */
            double getTime(void) const;
    };

    #include "Timing.inl"
}

#endif /* !TIMING_HPP_ */
