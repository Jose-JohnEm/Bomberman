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

        private:
            int _width;
            int _height;
            std::string _name;
            bool _lateToInit;

        public:

        /**
         * @brief Construct a new Window object
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         * @param lateInit A boolean, True if window is already init, False otherwise
         */
        Window(const int &width = 1920, const int &height = 1080, const std::string &title = "Bomberman", bool lateInit = false);

        /**
         * @brief Destroy the Window object
         */
        ~Window();

        Window() = delete;
        Window(Window &&) = delete;
        Window &operator=(Window &&) = delete;
        Window &operator=(const Window &) = delete;

        /**
         * @brief Initialize window and OpenGL context
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        void initWindow(int width, int height, const char *title);

        /**
         * @brief Check if KEY_ESCAPE pressed or Close icon pressed
         *
         * @return A boolean (True OR False)
         */
        bool windowShouldClose(void);

        /**
         * @brief Close window
         */
        void closeWindow(void);

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         */
        void drawText(const char *text, int posX = 0, int posY = 0, int fontSize = 50);

    };
};

#include "Window/Window.inl"

#endif /* !WINDOW_HPP_ */
