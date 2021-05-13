/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Window {

        public:
        /**
         * @brief Construct a new Window object
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         * @param lateInit A boolean, True if window is already init, False otherwise
         */
        Window(const int &width = 1920, const int &height = 1080, const std::string &title = "Bomberman", const bool &lateInit = false);

        /**
         * @brief Destroy the Window object
         */
        ~Window();

        /**
         * @brief Initialize window and OpenGL context
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        void initWindow(const int &width, const int &height, const std::string &title) const;

        /**
         * @brief Check if KEY_ESCAPE pressed or Close icon pressed
         *
         * @return A boolean (True OR False)
         */
        bool windowShouldClose(void) const;

        /**
         * @brief Close window
         */
        void closeWindow(void) const;

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         */
        void drawText(const std::string &text, const int &posX = 0, const int &posY = 0, const int &fontSize = 50) const;

        private:
            int _width;
            int _height;
            std::string _name;
            bool _lateToInit;
    };

    #include "Window.inl"

}

#endif /* !WINDOW_HPP_ */
