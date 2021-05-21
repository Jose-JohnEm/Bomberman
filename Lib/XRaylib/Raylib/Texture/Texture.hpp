/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>
#include <iostream>
#include "raylib.h"
#include "Image/Image.hpp"
#include "Color/Color.hpp"
#include "Rectangle/Rectangle.hpp"

namespace Raylib
{
    class Texture {

        public:
            /**
             * @brief Construct a new Texture object
             */
            Texture(const std::string &fileName);

            /**
             * @brief Construct a new Texture object
             */
            Texture(const Image &image);

            /**
             * @brief Destroy the Texture object
             */
            ~Texture();

            /**
             * @brief Overload of '=' operator
             *
             * @param music A const reference to a Texture
             * @return A reference to Texture (Texture &)
             */
            Texture &operator=(const Texture &texture);

            /**
             * @brief Set texture and rectangle to be used on shapes drawing
             *
             * @param texture A Texture Object
             * @param source A Rectangle Object
             */
            void SetShapesTexture(Texture const &texture, Rectangle const &source) const;

            /**
             * @brief Load texture from file into GPU memory (VRAM)
             *
             * @param texture A Texture Object
             * @param source A Rectangle Object
             * @return A reference to the texture - Texture&
             */
            Texture &LoadTexture(const char *fileName) const;

            /**
             * @brief Load texture from image data
             *
             * @param image A const reference to the Image Object
             * @return A reference to the texture - Texture&
             */
            Texture &LoadTextureFromImage(Image const &image) const;

            /**
             * @brief Initializes render texture for drawing
             *
             * @param target A const reference to the RenderTexture Object
             */
            void BeginTextureMode(RenderTexture const &target) const;

            /**
             * @brief Ends drawing to render texture
             */
            void EndTextureMode(void) const;

            /**
             * @brief Set shader uniform value for texture (sampler2d)
             *
             * @param shader A const reference to the Shader Object
             * @param locIndex A const reference to a Int
             * @param texture A const reference to the Texture Object
             */
            void SetShaderValueTexture(Shader const &shader, int const &locIndex, Texture const &texture) const;

            /**
             * @brief Load cubemap from image, multiple image cubemap layouts supported
             *
             * @param image A const reference to the Image Object
             * @param layout A const reference to a Int
             * @param texture A const reference to the Texture Object
             * @return A TextureCubemap
             */
            TextureCubemap LoadTextureCubemap(Image const &image, int const &layout) const;
 
             /**
             * @brief Load texture for rendering (framebuffer)
             *
             * @param width A const reference to a Int
             * @param height A const reference to a Int
             * @return A RenderTexture
             */
            RenderTexture LoadRenderTexture(int const &width, int const &height) const;

             /**
             * @brief Unload texture from GPU memory (VRAM)
             *
             * @param texture A const reference to a Texture
             */
            void UnloadTexture(Texture const &texture) const;

             /**
             * @brief Unload render texture from GPU memory (VRAM)
             *
             * @param texture A const reference to a Texture
             */
            void UnloadRenderTexture(RenderTexture const &target) const;

             /**
             * @brief Update GPU texture with new data
             *
             * @param texture A const reference to a Texture
             * @param pixels A const to a void *
             */
            void UpdateTexture(Texture const &texture, const void *pixels) const;


             /**
             * @brief Update GPU texture rectangle with new data
             *
             * @param texture A const reference to a Texture
             */
            void UpdateTextureRec(Texture const &texture, Rectangle const &rec, const void *pixels) const;

             /**
             * @brief Get pixel data from GPU texture and return an Image
             *
             * @param texture A const reference to a Texture
             * @return A Image Class
             */
            Image GetTextureData(Texture const &texture) const;

             /**
             * @brief Get pixel data from screen buffer and return an Image (screenshot)
             *
             * @return A Image Class
             */
            Image GetScreenData(void) const;

             /**
             * @brief Generate GPU mipmaps for a texture
             *
             * @param texture A const pointer to a Texture
             */
            void GenTextureMipmaps(Texture const *texture) const;

             /**
             * @brief Set texture scaling filter mode
             *
             * @return A Image Class
             */
            void SetTextureFilter(Texture const &texture, int const &filter) const;

             /**
             * @brief Set texture wrapping mode
             *
             * @param texture A const pointer to a Texture
             * @param wrap A const reference to a int
             */
            void SetTextureWrap(Texture const &texture, int const &wrap) const;

            /**
             * @brief Draw a Texture with position XY
             *
             * @param posX A int
             * @param posY A int
             * @param tint A Color
             * @return A reference to the texture - Texture&
             */
            Texture &drawTexture(const int &posX, const int &posY, const Color &tint = Color::Black()) const;

            /**
             * @brief Draw a Texture with position defined as Vector2
             *
             * @param texture A const pointer to a Texture
             * @param position A const reference to a Vector2
             * @param tint A const reference to a Color
             */
            void DrawTextureV(Texture const &texture, Vector2 const &position, Color const &tint = Color::Black()) const;

            /**
             * @brief Draw a Texture with extended parameters
             *
             * @param texture A const pointer to a Texture
             * @param position A const reference to a Vector2
             * @param rotation A const reference to a float
             * @param scale A const reference to a float
             * @param tint A const reference to a Color
             */
            void DrawTextureEx(Texture const &texture, Vector2 const &position, float const &rotation, float const &scale, Color const &tint = Color::Black()) const;

            /**
             * @brief Draw a part of a texture defined by a rectangle
             *
             * @param texture A const pointer to a Texture
             * @param position A const reference to a Vector2
             * @param rotation A const reference to a float
             * @param scale A const reference to a float
             * @param tint A const reference to a Color
             */
            void DrawTextureRec(Texture const &texture, Rectangle const &source, Vector2 const &position, Color const &tint = Color::Black()) const;

            /**
             * @brief Draw texture quad with tiling and offset parameters
             *
             * @param texture A const pointer to a Texture
             * @param tiling A const reference to a Vector2
             * @param offset A const reference to a Vector2
             * @param quad A const reference to a Rectangle
             * @param tint A const reference to a Color
             */
            void DrawTextureQuad(Texture const &texture, Vector2 const &tiling, Vector2 const &offset, Rectangle const &quad, Color const &tint = Color::Black()) const;

            /**
             * @brief Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
             *
             * @param texture A const pointer to a Texture
             * @param source A const reference to a Rectangle
             * @param dest A const reference to a Rectangle
             * @param origin A const reference to a Vector2
             * @param rotation A const reference to a float
             * @param scale A const reference to a float
             * @param tint A const reference to a Color
             */
            void DrawTextureTiled(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, float const &scale, Color const &tint = Color::Black()) const;

            /**
             * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
             *
             * @param texture A const pointer to a Texture
             * @param tiling A const reference to a Vector2
             * @param offset A const reference to a Vector2
             * @param quad A const reference to a Rectangle
             * @param tint A const reference to a Color
             * @return A reference to the texture - Texture&
             */
            void DrawTexturePro(Texture const &texture, Rectangle const &source, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black()) const;

            /**
             * @brief Draws a texture (or part of it) that stretches or shrinks nicely
             *
             * @param texture A const pointer to a Texture
             * @param tiling A const reference to a Vector2
             * @param offset A const reference to a Vector2
             * @param quad A const reference to a Rectangle
             * @param tint A const reference to a Color
             * @return A reference to the texture - Texture&
             */
            void DrawTextureNPatch(Texture const &texture, NPatchInfo const &nPatchInfo, Rectangle const &dest, Vector2 const &origin, float const &rotation, Color const &tint = Color::Black());

            /**
             * @brief Draw a textured polygon
             *
             * @param texture A const pointer to a Texture
             * @param tiling A const reference to a Vector2
             * @param offset A const reference to a Vector2
             * @param quad A const reference to a Rectangle
             * @param tint A const reference to a Color
             * @return A reference to the texture - Texture&
             */
            void DrawTexturePoly(Texture texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointsCount, Color tint);

        private:
            /**
             * @brief Set Texture
             *
             * @param texture A Texture C Structure
             */
            void set(const ::Texture &texture);

            /**
             * @brief Set Texture
             *
             * @param texture A const reference to a Texture object
             */
            void set(const Texture &texture);

            ::Texture _texture; // Texture C structure
    };

    #include "Texture.inl"
}

#endif /* !TEXTURE_HPP_ */
