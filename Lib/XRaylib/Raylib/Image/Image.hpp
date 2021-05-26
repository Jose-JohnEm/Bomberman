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
             * @brief Load image from file into CPU memory (RAM)
             * 
             * @param fileName A const pointer to a char
             * @return A Image Class
             */
            Image LoadImage(const char *fileName);

            /**
             * @brief Load image from RAW file data
             * 
             * @param fileName A const pointer to a char
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param format A const reference to a int
             * @param headerSize A const reference to a int
             * @return A Image Class
             */
            Image LoadImageRaw(const char *fileName, int const &width, int const &height, int const &format, int const &headerSize);

            /**
             * @brief Load image sequence from file (frames appended to image.data)
             * 
             * @param fileName A const pointer to a char
             * @param frames A const pointer to a int
             * @return A Image Class
             */
            Image LoadImageAnim(const char *fileName, int *frames);

            /**
             * @brief Load image from memory buffer
             * 
             * @param fileType A const pointer to a char
             * @param fileData A const pointer to a unsigned char
             * @param dataSize A const reference to a int
             * @return A Image Class
             */
            Image LoadImageFromMemory(const char *fileType, const unsigned char *fileData, int const &dataSize);

            /**
             * @brief Unload image from CPU memory (RAM)
             * 
             * @param image A const reference to a Class Image
             */
            void UnloadImage(Image const &image) const;

            /**
             * @brief Export image data to file, returns true on success
             * 
             * @param image A const reference to a Class Image
             * @param fileType A const pointer to a char
             * @return A boolean
             */
            bool ExportImage(Image const &image, const char *fileName) const;

            /**
             * @brief Export image as code file defining an array of bytes, returns true on success
             * 
             * @param image A const reference to a Class Image
             * @param fileType A const pointer to a char
             * @return A boolean
             */
            bool ExportImageAsCode(Image const &image, const char *fileType) const;

            /**
             * @brief Generate image: plain color
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param color A const pointer to a Class Color
             * @return A Image Class
             */
            Image GenImageColor(int const &width, int const &height, Color const &color);

            /**
             * @brief Generate image: vertical gradient
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param top A const pointer to a Class Color
             * @param bottom A const pointer to a Class Color
             * @return A Image Class
             */
            Image GenImageGradientV(int const &width, int const &height, Color const &top, Color const &bottom);

            /**
             * @brief Generate image: horizontal gradient
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param left A const pointer to a Class Color
             * @param right A const pointer to a Class Color
             * @return A Image Class
             */
            Image GenImageGradientH(int const &width, int const &height, Color const &left, Color const &right);

            /**
             * @brief Generate image: radial gradient
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param inner A const pointer to a Class Color
             * @param outer A const pointer to a Class Color
             * @return A Image Class
             */
            Image GenImageGradientRadial(int const &width, int const &height, float density, Color inner, Color outer);

            /**
             * @brief Generate image: checked
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param checksX A const reference to a int
             * @param checksY A const reference to a int
             * @param col1 A const pointer to a Class Color
             * @param col2 A const pointer to a Class Color
             * @return A Image Class
             */
            Image GenImageChecked(int const &width, int const &height, int const &checksX, int const &checksY, Color col1, Color col2);

            /**
             * @brief Generate image: white noise
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param factor A const reference to a float
             * @return A Image Class
             */
            Image GenImageWhiteNoise(int const &width, int const &height, float const &factor);

            /**
             * @brief Generate image: perlin noise
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param offsetX A const reference to a int
             * @param offsetY A const reference to a int
             * @param scale A const reference to a float
             * @return A Image Class
             */
            Image GenImagePerlinNoise(int const &width, int const &height, int offsetX, int offsetY, float scale);

            /**
             * @brief Generate image: cellular algorithm. Bigger tileSize means bigger cells
             * 
             * @param width A const reference to a int
             * @param height A const reference to a int
             * @param tileSize A const reference to a int
             * @return A Image Class
             */
            Image GenImageCellular(int const &width, int const &height, int const &tileSize);

            /**
             * @brief Create an image duplicate (useful for transformations)
             * 
             * @param image A const reference to a Class Image
             * @return A Image Class
             */
            Image ImageCopy(Image const &image);

            /**
             * @brief Create an image from another image piece
             * 
             * @param image A const reference to a Class Image
             * @param rec A const reference to a Class Rectangle
             * @return A Image Class
             */
            Image ImageFromImage(Image const &image, Rectangle const &rec);

            /**
             * @brief Create an image from text (default font)
             * 
             * @param text A const pointer to a char
             * @param fontSize A const reference to a int
             * @param color A const reference to a Class Color
             * @return A Image Class
             */
            Image ImageText(const char *text, int const &fontSize, Color const &color);

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
            Image ImageTextEx(Font const &font, const char *text, float const &fontSize, float const &spacing, Color const &tint);

            /**
             * @brief Convert image data to desired format
             * 
             * @param image A const pointer to a Class Image
             * @param newFormat A const pointer to a int
             */
            void ImageFormat(Image *image, int const &newFormat);

            /**
             * @brief Convert image to POT (power-of-two)
             * 
             * @param image A const pointer to a Class Image
             * @param fill A const pointer to a Class Color
             */
            void ImageToPOT(Image *image, Color const &fill);

            /**
             * @brief Crop an image to a defined rectangle
             * 
             * @param image A const pointer to a Class Image
             * @param crop A const pointer to a Class Rectangle
             */
            void ImageCrop(Image *image, Rectangle const &crop);

            /**
             * @brief Crop image depending on alpha value
             * 
             * @param image A const pointer to a Class Image
             * @param threshold A const pointer to a Class Rectangle
             */
            void ImageAlphaCrop(Image *image, float const &threshold);

            /**
             * @brief Clear alpha channel to desired color
             * 
             * @param image A const pointer to a Class Image
             * @param color A const reference to a Class Color
             * @param threshold A const reference to a float
             */
            void ImageAlphaClear(Image *image, Color const &color, float const &threshold);

            /**
             * @brief Apply alpha mask to image
             * 
             * @param image A const pointer to a Class Image
             * @param alphaMask A const reference to a Class Image
             */
            void ImageAlphaMask(Image *image, Image const &alphaMask);

    void ImageAlphaPremultiply(Image *image);                                                          // Premultiply alpha channel
    void ImageResize(Image *image, int newWidth, int newHeight);                                       // Resize image (Bicubic scaling algorithm)
    void ImageResizeNN(Image *image, int newWidth,int newHeight);                                      // Resize image (Nearest-Neighbor scaling algorithm)
    void ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);  // Resize canvas and fill with color
    void ImageMipmaps(Image *image);                                                                   // Generate all mipmap levels for a provided image
    void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
    void ImageFlipVertical(Image *image);                                                              // Flip image vertically
    void ImageFlipHorizontal(Image *image);                                                            // Flip image horizontally
    void ImageRotateCW(Image *image);                                                                  // Rotate image clockwise 90deg
    void ImageRotateCCW(Image *image);                                                                 // Rotate image counter-clockwise 90deg
    void ImageColorTint(Image *image, Color color);                                                    // Modify image color: tint
    void ImageColorInvert(Image *image);                                                               // Modify image color: invert
    void ImageColorGrayscale(Image *image);                                                            // Modify image color: grayscale
    void ImageColorContrast(Image *image, float contrast);                                             // Modify image color: contrast (-100 to 100)
    void ImageColorBrightness(Image *image, int brightness);                                           // Modify image color: brightness (-255 to 255)
    void ImageColorReplace(Image *image, Color color, Color replace);                                  // Modify image color: replace color
    Color *LoadImageColors(Image image);                                                               // Load color data from image as a Color array (RGBA - 32bit)
    Color *LoadImagePalette(Image image, int maxPaletteSize, int *colorsCount);                        // Load colors palette from image as a Color array (RGBA - 32bit)
    void UnloadImageColors(Color *colors);                                                             // Unload color data loaded with LoadImageColors()
    void UnloadImagePalette(Color *colors);                                                            // Unload colors palette loaded with LoadImagePalette()
    Rectangle GetImageAlphaBorder(Image image, float threshold);                                       // Get image alpha border rectangle

    // Image drawing functions
    // NOTE: Image software-rendering functions (CPU)
    void ImageClearBackground(Image *dst, Color color);                                                // Clear image background with given color
    void ImageDrawPixel(Image *dst, int posX, int posY, Color color);                                  // Draw pixel within an image
    void ImageDrawPixelV(Image *dst, Vector2 position, Color color);                                   // Draw pixel within an image (Vector version)
    void ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color); // Draw line within an image
    void ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);                          // Draw line within an image (Vector version)
    void ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);               // Draw circle within an image
    void ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);                        // Draw circle within an image (Vector version)    void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);             // Draw a source image within a destination image (tint applied to source)
    void ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);   // Draw text (using default font) within an image (destination)
    void ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text (custom sprite font) within an image (destination)


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
