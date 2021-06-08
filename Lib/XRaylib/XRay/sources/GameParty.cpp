/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GameParty.cpp
*/

#include "GameParty.hpp"

GameParty::GameParty(PModelsCharacter models, LTextures textures)
:_models(models),
_textures(textures)
{
    MapGeneration mp(15, 15);
    mp.placePlayers(models.size());
    _map = mp.getMap();

    _camera = Raylib::Camera3D(Vector3({(float)mp.getHeight() / 5, (float)mp.getWidth() / 5 - 2, 10}), Vector3({(float)mp.getHeight() / 5, (float)mp.getWidth() / 5, 0}));
}

GameParty::~GameParty()
{

}

void GameParty::draw()
{
    _camera.beginMode3D();

    
    float x;
    float y = 0;
    float scale;

    for (const std::string &line : _map)
    {
        x = 0;
        for (const char &c : line)
        {
            if (c == '1' || c == '2' || c == '3' || c == '4')
            {

                scale = _models[c - '1'].second * 0.35;
                DrawModelEx(_models[c - '1'].first, {x * COEF, y * COEF, 0}, {1, 0, 0}, 90, {scale, scale, scale}, Raylib::Color::White().getCStruct());
            }
            if (c == 'W' || c == 'E')
            {
                DrawCubeTexture(_textures[WALL], {x * COEF, y * COEF, 0}, COEF, COEF, COEF, Raylib::Color::White().getCStruct());
            }
            if (c == 'M')
            {
                DrawCubeTexture(_textures[BOX], {x * COEF, y * COEF, 0}, COEF, COEF, COEF, Raylib::Color::White().getCStruct());
            }
            DrawCubeTexture(_textures[FLOOR], {x * COEF, y * COEF, -COEF}, COEF, COEF, COEF, Raylib::Color::Gray().getCStruct());
            x++;
        }
        y++;
    }

    _camera.endMode3D();
}