/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GamePArty.hpp
*/

#include <vector>
#include <string>
#include "raylib.h"
#include "PlayerSelector/Selector.hpp"
#include "MapGeneration.hpp"

typedef std::vector<std::string> PMap;
typedef std::vector<std::pair<Model, float>> PModelsCharacter;
typedef std::vector<Texture> LTextures;

#define COEF (float)0.4

class GameParty
{
    public:
        GameParty(PModelsCharacter models, LTextures textures);
        ~GameParty();

        void draw();

        
        enum ModelMode
        {
            FLOOR,
            WALL,
            BOX
        };

    private:
        PMap _map;
        PModelsCharacter _models;
        LTextures _textures;
        Raylib::Camera3D _camera;
};
