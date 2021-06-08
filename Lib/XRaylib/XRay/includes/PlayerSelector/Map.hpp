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
#include "MapGeneration.hpp"
#include <filesystem>

namespace PlayerSelector
{
    class Map
    {

        public:
            Map(std::vector<std::pair<Model, float>> models);
            ~Map();

            void next();
            void prev();
            void draw();


            enum ModelMode
            {
                FLOOR,
                WALL,
                BOX
            };
            std::vector<std::string> getMap() const;
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
