/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"

namespace Raylib
{
    class Image {

        public:
            /**
             * @brief Construct a new Image object
             */
            Image();

            /**
             * @brief Construct a new Image object
             *
             * @param image A image
             */
            Image(const Image &image);

            /**
             * @brief Construct a new Image object
             *
             * @param fileName A string
             */
            Image(const std::string &fileName);

            /**
             * @brief Overload of '=' operator
             *
             * @param Image A const reference to a Image
             * @return A Image
             */
            ::Image getCStruct() const;

            /**
             * @brief Construct a new Image object
             *
             * @param fileName A string
             * @param width A int
             * @param height A int
             * @param format A int
             * @param headerSize A int
             */
            Image(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

            /**
             * @brief Destroy the Image object
             */
            ~Image();

            /**
             * @brief Load image from file into CPU memory (RAM)
             *
             * @param fileName A const std::string
             * @return A Image
             */
            Image loadImage(const std::string &fileName);

            /**
             * @brief Load image from RAW file data
             *
             * @param fileName A const std::string
             * @param width A int
             * @param height A int
             * @param format A int
             * @param headerSize A int
             * @return A Image
             */
            Image loadImageRaw(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

            /**
             * @brief Load image sequence from file (frames appended to image.data)
             *
             * @param fileName A const std::string
             * @param frames A int *
             * @return A Image
             */
            Image loadImageAnim(const std::string &fileName, int *frames);

            /**
             * @brief Load image from memory buffer
             *
             * @param fileType A const std::string
             * @param fileData A const unsigned std::string
             * @param dataSize A int
             * @return A Image
             */
            Image loadImageFromMemory(const std::string &fileType, const std::string &fileData, const int &dataSize);

            /**
             * @brief Unload image from CPU memory (RAM)
             *
             * @param image A Image
             */
            void unloadImage(const Image &image);

            /**
             * @brief Export image data to file, returns true on success
             *
             * @param image A Image
             * @param fileName A const std::string
             * @return A boolean
             */
            bool exportImage(const Image &image, const std::string &fileName) const;

            /**
             * @brief Export image as code file defining an array of bytes, returns true on success
             *
             * @param image A Image
             * @param fileName A const std::string
             * @return true or false
             */
            bool exportImageAsCode(const Image &image, const std::string &fileName) const;

            /**
             * @brief Returns the pixel data size of the image.
             *
             * @return The pixel data size of the image.
             */
            int getPixelDataSize() const;

            /**
             * @brief Overload of '=' operator
             *
             * @param music A const reference to a Image
             * @return A reference to Image (Image &)
             */
            Image &operator=(const Image &image);

        private:
            /**
             * @brief Set Image
             *
             * @param image A Image C Structure
             */
            void set(const ::Image &image);

            /**
             * @brief Set Image
             *
             * @param image A const reference to a Image object
             */
            void set(const Image &image);

            void *_data;             // Image raw data
            int _width;              // Image base width
            int _height;             // Image base height
            int _mipmaps;            // Mipmap levels, 1 by default
            int _format;             // Data format (PixelFormat type)

            ::Image _image = {_data, _width, _height, _mipmaps, _format};
    };

    #include "Image.inl"
}

#endif /* !IMAGE_HPP_ */
