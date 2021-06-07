/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map.cpp
*/

#include "PlayerSelector/Map.hpp"

std::vector<std::vector<Texture>> findTexturesAvailable(int &nb_textures)
{
    std::vector<std::vector<Texture>> res;
    std::vector<std::string> files;
    bool isThereThree;

    for (const auto & dir : std::filesystem::directory_iterator("resources/map"))
    {
        isThereThree = false;

        if (dir.is_directory())
        {
            for (const auto &f : std::filesystem::directory_iterator(dir.path()))
            {
                files.push_back(f.path().filename().string());
            }
 
            if (files.end() != find(files.begin(), files.end(), "wall.png") &&
                files.end() != find(files.begin(), files.end(), "floor.png") &&
                files.end() != find(files.begin(), files.end(), "box.png"))
            {
                res.push_back({
                    Raylib::Texture(dir.path().string() + "/floor.png").getCStruct(),
                    Raylib::Texture(dir.path().string() + "/wall.png").getCStruct(),
                    Raylib::Texture(dir.path().string() + "/box.png").getCStruct()
                });
            }
        }
    }
    nb_textures = res.size();
    return res;
}

PlayerSelector::Map::Map()
: _textures(findTexturesAvailable(_nbTextures)),
current(0),
_COEF(0.4),
_charMap(
{
    {"XXXXX"},
    {"X CCX"},
    {"X X X"},
    {"XCCCX"},
    {"XXXXX"}
})
{
    
}

PlayerSelector::Map::~Map()
{
    
}

void PlayerSelector::Map::next()
{
    current = (current + 1 == _textures.size()) ? 0 : current + 1;
}

void PlayerSelector::Map::prev()
{
    current = (current == 0) ? _textures.size() - 1 : current - 1;
}

void PlayerSelector::Map::draw()
{
    float x;
    float y = 0;

    for (const std::string &line : _charMap)
    {
        x = 0;
        for (const char &c : line)
        {
            if (c == 'X')
            {
                DrawCubeTexture(_textures[current][WALL], {x * _COEF - (float)2.2, y * _COEF - (float)0.5, 0}, _COEF, _COEF, _COEF, Raylib::Color::Red().getCStruct());
            }
            if (c == 'C')
            {
                DrawCubeTexture(_textures[current][BOX], {x * _COEF - (float)2.2, y * _COEF - (float)0.5, 0}, _COEF, _COEF, _COEF, Raylib::Color::Yellow().getCStruct());
            }
            DrawCubeTexture(_textures[current][FLOOR], {x * _COEF - (float)2.2, y * _COEF - (float)0.5, -_COEF}, _COEF, _COEF, _COEF, Raylib::Color::Gray().getCStruct());
            x++;
        }
        y++;
    }
}