/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map.hpp
*/

#include <vector>
#include <string>
#include "Color/Color.hpp"
#include "Texture/Texture.hpp"
#include <filesystem>

namespace PlayerSelector
{
    class Map
    {

        public:

            /**
             * @brief Construct a new Map object
             * 
             * @param models pair of models with their scalable values
             * @param asciiMap the ascii map to print
             */
            Map(std::vector<std::pair<Model, float>> models, std::vector<std::string> &asciiMap);

            /**
             * @brief Destroy the Map object
             * 
             */
            ~Map();

            /**
             * @brief Set the next map texture
             * 
             */
            void next();

            /**
             * @brief Set the prev map texture
             * 
             */
            void prev();

            /**
             * @brief Print the 3D Map
             * 
             */
            void draw();

            /**
             * @brief Get the Map Type (Floor, Wall or Box)
             * 
             * @return The map type
             */
            size_t getMapType() const;

            enum ModelMode
            {
                FLOOR,
                WALL,
                BOX
            };

            /**
             * @brief Get the Ascii Map
             * 
             * @return The map as vector of strings 
             */
            std::vector<std::string> getMap() const;

            /**
             * @brief Get the Textures object
             * 
             * @return All the textures 
             */
            std::vector<Texture2D> getTextures() const;

        private:
            std::vector<std::vector<Texture2D>> _textures;
            std::vector<std::string> _charMap;
            std::vector<std::pair<Model, float>> _characters;

            int _nbTextures;
            int current;
            float _COEF;

    };
}
