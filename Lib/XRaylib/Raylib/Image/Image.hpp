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
#include "Texture/Texture.hpp"
#include "Font/Font.hpp"

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
             * @brief Construct a new Image object
             *
             * @param fileName A string
             * @param width An int
             * @param height An int
             * @param format An int
             * @param headerSize An int
             */
            Image(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

            /**
             * @brief Destroy the Image object
             */
            ~Image();

             /**
             * @brief Get pixel data from screen buffer and return an Image (screenshot)
             *
             * @return A Image Class
             */
            Image getScreenData(void);

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
             * @param width An int
             * @param height An int
             * @param format An int
             * @param headerSize An int
             * @return A Image
             */
            Image loadImageRaw(const std::string &fileName, const int &width, const int &height, const int &format, const int &headerSize);

            /**
             * @brief Load image sequence from file (frames appended to image.data)
             *
             * @param fileName A const std::string
             * @param frames An int *
             * @return A Image
             */
            Image loadImageAnim(const std::string &fileName, int *frames);

            /**
             * @brief Load image from memory buffer
             *
             * @param fileType A const std::string
             * @param fileData A const unsigned std::string
             * @param dataSize An int
             * @return A Image
             */
            Image loadImageFromMemory(const std::string &fileType, const std::string &fileData, const int &dataSize);

            /**
             * @brief Unload image from CPU memory (RAM)
             *
             * @param image A Image
             */
            void unloadImage(void);

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
            int getPixelDataSize(void) const;

            /**
             * @brief Overload of '=' operator
             *
             * @param music A const reference to a Image
             * @return A reference to Image (Image &)
             */
            Image &operator=(const Image &image);

            /**
             * @brief Getter of Image structure (private attribute)
             *
             * @return An Image C structure
             */
            ::Image getCStruct(void) const;

             /**
             * @brief Get pixel data from GPU texture and return an Image
             *
             * @param texture A const reference to a Texture
             * @return A Image Class
             */
            Image getTextureData(Texture const &texture) const;

            /**
             * @brief Generate image: plain color
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param color A const pointer to a Class Color
             * @return A Image Class
             */
            Image genImageColor(int const &width, int const &height, Color const &color);

            /**
             * @brief Generate image: vertical gradient
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param top A const pointer to a Class Color
             * @param bottom A const pointer to a Class Color
             * @return A Image Class
             */
            Image genImageGradientV(int const &width, int const &height, Color const &top, Color const &bottom);

            /**
             * @brief Generate image: horizontal gradient
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param left A const pointer to a Class Color
             * @param right A const pointer to a Class Color
             * @return A Image Class
             */
            Image genImageGradientH(int const &width, int const &height, Color const &left, Color const &right);

            /**
             * @brief Generate image: radial gradient
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param inner A const pointer to a Class Color
             * @param outer A const pointer to a Class Color
             * @return A Image Class
             */
            Image genImageGradientRadial(int const &width, int const &height, float density, Color inner, Color outer);

            /**
             * @brief Generate image: checked
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param checksX A const reference to an int
             * @param checksY A const reference to an int
             * @param col1 A const pointer to a Class Color
             * @param col2 A const pointer to a Class Color
             * @return A Image Class
             */
            Image genImageChecked(int const &width, int const &height, int const &checksX, int const &checksY, Color col1, Color col2);

            /**
             * @brief Generate image: white noise
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param factor A const reference to a float
             * @return A Image Class
             */
            Image genImageWhiteNoise(int const &width, int const &height, float const &factor);

            /**
             * @brief Generate image: perlin noise
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param offsetX A const reference to an int
             * @param offsetY A const reference to an int
             * @param scale A const reference to a float
             * @return A Image Class
             */
            Image genImagePerlinNoise(int const &width, int const &height, int offsetX, int offsetY, float scale);

            /**
             * @brief Generate image: cellular algorithm. Bigger tileSize means bigger cells
             * 
             * @param width A const reference to an int
             * @param height A const reference to an int
             * @param tileSize A const reference to an int
             * @return A Image Class
             */
            Image genImageCellular(int const &width, int const &height, int const &tileSize);

            /**
             * @brief Create an image duplicate (useful for transformations)
             * 
             * @param image A const reference to a Class Image
             * @return A Image Class
             */
            Image imageCopy(Image const &image);

            /**
             * @brief Create an image from another image piece
             * 
             * @param image A const reference to a Class Image
             * @param rec A const reference to a Class Rectangle
             * @return A Image Class
             */
            Image imageFromImage(Image const &image, Rectangle const &rec);

            /**
             * @brief Create an image from text (default font)
             * 
             * @param text A const pointer to a char
             * @param fontSize A const reference to an int
             * @param color A const reference to a Class Color
             * @return A Image Class
             */
            Image imageText(const char *text, int const &fontSize, Color const &color);

            /**
             * @brief Create an image from text (custom sprite font)
             * 
             * @param font A const reference to a Class Font
             * @param text A const pointer to a char
             * @param fontSize A const pointer to a float
             * @param spacing A const pointer to a float
             * @param tint A const reference to a Class Color
             * @return A Image Class
             */
            Image imageTextEx(Font const &font, const char *text, float const &fontSize, float const &spacing, Color const &tint);

            /**
             * @brief Convert image data to desired format
             * 
             * @param image A const pointer to a Class Image
             * @param newFormat A const pointer to an int
             */
            void imageFormat(Image *image, int const &newFormat) const;

            /**
             * @brief Convert image to POT (power-of-two)
             * 
             * @param image A const pointer to a Class Image
             * @param fill A const pointer to a Class Color
             */
            void imageToPOT(Image *image, Color const &fill) const;

            /**
             * @brief Crop an image to a defined rectangle
             * 
             * @param image A const pointer to a Class Image
             * @param crop A const pointer to a Class Rectangle
             */
            void imageCrop(Image *image, Rectangle const &crop) const;

            /**
             * @brief Crop image depending on alpha value
             * 
             * @param image A const pointer to a Class Image
             * @param threshold A const pointer to a Class Rectangle
             */
            void imageAlphaCrop(Image *image, float const &threshold) const;

            /**
             * @brief Clear alpha channel to desired color
             * 
             * @param image A const pointer to a Class Image
             * @param color A const reference to a Class Color
             * @param threshold A const reference to a float
             */
            void imageAlphaClear(Image *image, Color const &color, float const &threshold) const;

            /**
             * @brief Apply alpha mask to image
             * 
             * @param image A const pointer to a Class Image
             * @param alphaMask A const reference to a Class Image
             */
            void imageAlphaMask(Image *image, Image const &alphaMask) const;

            /**
             * @brief Premultiply alpha channel
             * 
             * @param image A const pointer to a Class Image
             */
            void imageAlphaPremultiply(Image *image) const;

            /**
             * @brief Resize image (Bicubic scaling algorithm)
             * 
             * @param image A const pointer to a Class Image
             * @param newWidth A const reference to an int
             * @param newHeight A const reference to an int
             */
            void imageResize(Image *image, int const &newWidth, int const &newHeight) const;

            /**
             * @brief Resize image (Nearest-Neighbor scaling algorithm)
             * 
             * @param image A const pointer to a Class Image
             * @param newWidth A const reference to an int
             * @param newHeight A const reference to an int
             */
            void imageResizeNN(Image *image, int newWidth, int const &newHeight) const;

            /**
             * @brief Resize canvas and fill with color
             * 
             * @param image A const pointer to a Class Image
             * @param newWidth A const reference to an int
             * @param newHeight A const reference to an int
             * @param offsetX A const reference to an int
             * @param offsetY A const reference to an int
             * @param color A const reference to a Class Color
             */
            void imageResizeCanvas(Image *image, int const &newWidth, int const &newHeight, int const &offsetX, int const &offsetY, Color const &fill) const;
            
            /**
             * @brief Generate all mipmap levels for a provided image
             * 
             * @param image A const pointer to a Class Image
             */
            void imageMipmaps(Image *image) const;

            /**
             * @brief Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
             * 
             * @param image A const pointer to a Class Image
             * @param rBpp A const reference to an int
             * @param gBpp A const reference to an int
             * @param aBpp A const reference to an int
             */
            void imageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp) const;

            /**
             * @brief Flip image vertically
             * 
             * @param image A const pointer to a Class Image
             */
            void imageFlipVertical(Image *image) const;

            /**
             * @brief Flip image horizontally
             * 
             * @param image A const pointer to a Class Image
             */
            void imageFlipHorizontal(Image *image) const;

            /**
             * @brief Rotate image clockwise 90deg
             * 
             * @param image A const pointer to a Class Image
             */
            void imageRotateCW(Image *image) const;

            /**
             * @brief Rotate image counter-clockwise 90deg
             * 
             * @param image A const pointer to a Class Image
             */
            void imageRotateCCW(Image *image) const;

            /**
             * @brief Modify image color: tint
             * 
             * @param image A const pointer to a Class Image
             * @param image A const reference to a Class Color
             */
            void imageColorTint(Image *image, Color const &color) const;

            /**
             * @brief Modify image color: invert
             * 
             * @param image A const pointer to a Class Image
             */
            void imageColorInvert(Image *image) const;

            /**
             * @brief Modify image color: grayscale
             * 
             * @param image A const pointer to a Class Image
             */
            void imageColorGrayscale(Image *image) const;

            /**
             * @brief Modify image color: contrast (-100 to 100)
             * 
             * @param image A const pointer to a Class Image
             * @param contrast A const pointer to a float
             */
            void imageColorContrast(Image *image, float const &contrast) const;

            /**
             * @brief Modify image color: brightness (-255 to 255)
             * 
             * @param image A const pointer to a Class Image
             * @param brightness A const pointer to a float
             */
            void imageColorBrightness(Image *image, int const &brightness);

            /**
             * @brief Modify image color: replace color
             * 
             * @param image A const pointer to a Class Image
             * @param color A const reference to a Class Color
             * @param replace A const reference to a Class Color
             */
            void imageColorReplace(Image *image, Color const &color, Color const &replace);

            /**
             * @brief Load color data from image as a Color array (RGBA - 32bit)
             * 
             * @param image A const reference to a Class Image
             * @return A Class Color
             */
            Color *loadImageColors(Image const &image);

            /**
             * @brief Load colors palette from image as a Color array (RGBA - 32bit)
             * 
             * @param image A const reference to a Class Image
             * @param maxPaletteSize A const reference to an int
             * @param colorCount A const pointer to an int
             * @return A Class Color
             */
            Color *loadImagePalette(Image const &image, int const &maxPaletteSize, int *colorsCount);

            /**
             * @brief Unload color data loaded with LoadImageColors()
             * 
             * @param colors A const pointer to a Class Color
             */
            void unloadImageColors(Color *colors);

            /**
             * @brief Unload colors palette loaded with LoadImagePalette()
             * 
             * @param colors A const pointer to a Class Color
             */
            void unloadImagePalette(Color *colors);

            /**
             * @brief Get image alpha border rectangle
             * 
             * @param image A const reference to a Class Image
             * @param threshold A const reference to a float
             */
            Rectangle getImageAlphaBorder(Image const &image, float const &threshold);

            /**
             * @brief Clear image background with given color
             * 
             * @param dst A const reference to a Class Image
             * @param color A const reference to a Class color
             */
            void imageClearBackground(Image *dst, Color const &color);

            /**
             * @brief Draw pixel within an image
             * 
             * @param dst A const pointer to a Class Image
             * @param posX A const reference to an int
             * @param posY A const reference to an int
             * @param color A const reference to a Class Color
             */
            void imageDrawPixel(Image *dst, int const &posX, int const &posY, Color const &color);

            /**
             * @brief Draw pixel within an image (Vector version)
             * 
             * @param dst A const pointer to a Class Image
             * @param position A const reference to a Class Vector2
             * @param color A const reference to a Class color
             */
            void imageDrawPixelV(Image *dst, Vector2 const &position, Color const &color);

            /**
             * @brief Draw pixel within an image (Vector version)
             * 
             * @param dst A const pointer to a Class Image
             * @param startPosX A const reference to an int
             * @param startPosY A const reference to an int
             * @param endPosX A const reference to an int
             * @param endPosY A const reference to an int
             * @param color A const reference to a Class color
             */
            void imageDrawLine(Image *dst, int const &startPosX, int const &startPosY, int const &endPosX, int const &endPosY, Color const &olor);

            /**
             * @brief Draw line within an image (Vector version)
             * 
             * @param dst A const pointer to a Class Image
             * @param start A const reference to a Class Vector2
             * @param end A const reference to a Class Vector2
             * @param color A const reference to a Class color
             */
            void imageDrawLineV(Image *dst, Vector2 const &start, Vector2 const &end, Color const &color);

            /**
             * @brief Draw circle within an image
             * 
             * @param dst A const pointer to a Class Image
             * @param centerX A const reference to an int
             * @param centerY A const reference to an int
             * @param radius A const reference to an int
             * @param color A const reference to a Class color
             */
            void imageDrawCircle(Image *dst, int const &centerX, int const &centerY, int const &radius, Color const &color);

            /**
             * @brief Draw circle within an image (Vector version)
             * 
             * @param dst A const pointer to a Class Image
             * @param center A const reference to a Class Vector2
             * @param radius A const reference to an int
             * @param color A const reference to a Class color
             */
            void imageDrawCircleV(Image *dst, Vector2 const &center, int const &radius, Color const &color);

            /**
             * @brief Draw a source image within a destination image (tint applied to source)
             * 
             * @param dst A const pointer to a Class Image
             * @param src A const reference to a Class Image
             * @param srcRec A const reference to a Class Image
             * @param dstRec A const reference to a Class Image
             * @param tint A const reference to a Class color
             */
            void imageDraw(Image *dst, Image const &src, Rectangle const &srcRec, Rectangle const &dstRec, Color const &tint);

            /**
             * @brief Draw a source image within a destination image (tint applied to source)
             * 
             * @param dst A const pointer to a Class Image
             * @param text A const pointer to a char
             * @param posX A const reference to an int
             * @param posX A const reference to an int
             * @param fontSize A const reference to an int
             * @param tint A const reference to a Class color
             */
            void imageDrawText(Image *dst, const char *text, int const &posX, int const &posY, int const &fontSize, Color const &color) const;

            /**
             * @brief Draw text (custom sprite font) within an image (destination)
             * 
             * @param dst A const pointer to a Class Image
             * @param font A const reference to a Class Font
             * @param text A const pointer to a char
             * @param position A const reference to a Class Vector2
             * @param fontSize A const reference to a float
             * @param spacing A const reference to a float
             * @param tint A const reference to a Class color
             */
            void imageDrawTextEx(Image *dst, Font const &font, const char *text, Vector2 const &position, float const &fontSize, float const &spacing, Color const &tint);


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

            ::Image _image; // Image C structure
    };

    #include "Image.inl"
}

#endif /* !IMAGE_HPP_ */
