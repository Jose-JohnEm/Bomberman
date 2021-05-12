/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#ifndef XRAY_HPP_
#define XRAY_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include "IGraphical.hpp"
#include "Raylib/Window/Window.hpp"

namespace Raylib
{
    class XRay : public IGraphical {

        public:
        /**
         * @brief Construct a new Ray Lib object
         */
        XRay();

        /**
         * @brief Destroy the Ray Lib object
         */
        ~XRay() override;

        /**
         * @brief Initialize window
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        void initWindow(const int &width, const int &height, const std::string &title) override;

        /**
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        bool shouldCloseWindow() override;

        /**
         * @brief Set buffer to Draw textures
         */
        void beginDrawing() override;

        /**
         * @brief Unset buffer to Draw textures
         */
        void endDrawing() override;

        /**
         * @brief Close window
         */
        void closeWindow() override;

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         */
        void drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) override;

        private:
            Raylib::Window _window;
    };

    #include "XRay.inl"
}

#endif /* !XRAY_HPP_ */
