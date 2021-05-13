/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include "raylib.h"

namespace Raylib
{
    class Color {

        public:
            /**
             * @brief Construct a new Color object
             */
            Color();

            /**
             * @brief Destroy the Color object
             */
            ~Color();

            /**
             * @brief Overload of '=' operator
             *
             * @param color A Color Object
             * @return Color& - A reference to new Color object
             */
            Color &operator=(const ::Color &color);

            /**
             * @brief Returns color with alpha applied, alpha goes from 0.0f to 1.0f
             *
             * @param color A Color Object
             * @param alpha A float
             * @return A Color
             */
            Color fade(Color color, const float &alpha) const;

            /**
             * @brief Returns hexadecimal value for a Color
             *
             * @param color A Color Object
             * @return A size_t
             */
            size_t colorToInt(Color color) const;

            /**
             * @brief Returns a Color from HSV values, hue [0..360], saturation/value [0..1]
             *
             * @param hue A float
             * @param saturation A float
             * @param value A float
             * @return A Color
             */
            Color colorFromHSV(const float &hue, const float &saturation, const float &value) const;

            /**
             * @brief Returns color with alpha applied, alpha goes from 0.0f to 1.0f
             *
             * @param color A Color Object
             * @param alpha A float
             * @return A Color
             */
            Color colorAlpha(Color color, const float &alpha) const;

            /**
             * @brief Returns src alpha-blended into dst color with tint
             *
             * @param dst A Color
             * @param src A Color
             * @param tint A Color
             * @return A Color
             */
            Color colorAlphaBlend(Color dst, Color src, Color tint) const;

            /**
             * @brief Get Color structure from hexadecimal value
             *
             * @param hexValue A size_t
             * @return A Color
             */
            Color getColor(const size_t &hexValue) const;

            /**
             * @brief Get Color from a source pixel pointer of certain format
             *
             * @param srcPtr A pointer
             * @param format A size_t
             * @return A Color
             */
            Color getPixelColor(void *srcPtr, const size_t &format) const;

            /**
             * @brief Set color formatted into destination pixel pointer
             *
             * @param dstPtr A pointer
             * @param color A Color
             * @param format A size_t
             */
            void setPixelColor(void *dstPtr, Color color, const size_t &format) const;

            /**
             * @brief Get pixel data size in bytes for certain format
             *
             * @param width A size_t that represents width
             * @param height A size_t that represents height
             * @param format A size_t that represents format
             * @return A size_t
             */
            size_t getPixelDataSize(const size_t &width, const size_t &height, const size_t &format) const;

            /**
             * @brief Return color
             *
             * @param color Name of color
             */
            Color getColor(const std::string &color);

            /**
             * @brief Set background color (framebuffer clear color)
             *
             * @param color New background color
             */
            void clearBackground(Color color) const;

            /**
             * @brief Overload of '=' operator
             *
             * @param Color A const reference to a Color
             * @return A reference to Color (Color &)
             */
            ::Color getCStruct() const;

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color LightGray();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Gray();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color DarkGray();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Yellow();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Gold();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Orange();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Pink();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Red();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Maroon();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Green();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Lime();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color DarkGreen();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color SkyBlue();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Blue();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color DarkBlue();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Purple();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Violet();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color DarkPurple();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Beige();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Brown();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color DarkBrown();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color White();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Black();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Blank();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color Magenta();

            /**
             * @brief Return the Color that represents the name of the function
             * @return A Color
             */
            static Color RayWhite();

        private:
            /**
             * @brief Set Color
             *
             * @param color A Color C Structure
             */
            void set(const ::Color &color);

            /**
             * @brief Set Color
             *
             * @param color A const reference to a Color object
             */
            void set(const Color &color);

            unsigned char _r = 0; // Red saturation ( ? / 255)
            unsigned char _g = 0; // Green saturation ( ? / 255)
            unsigned char _b = 0; // Blue saturation ( ? / 255)
            unsigned char _a = 255;

            std::map<std::string, Raylib::Color (*)()> _colorFactory;
    };

    #include "Color.inl"
}

#endif /* !COLOR_HPP_ */
