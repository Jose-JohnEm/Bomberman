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
        } else
            throw "ERROR : Wrong directory (Ressources - Map)";
    }
    nb_textures = res.size();
    return res;
}

PlayerSelector::Map::Map(std::vector<std::pair<Model, float>> models, std::vector<std::string> &asciiMap)
: _textures(findTexturesAvailable(_nbTextures)),
current(0),
_COEF(0.3),
_characters(models)
{
    std::cout << "------------ Generated Map ------------" << std::endl;
    for (auto &line : asciiMap)
    {
        std::cout << line << std::endl;
    }
    _charMap = asciiMap;
}

PlayerSelector::Map::~Map()
{
}

std::vector<std::string> PlayerSelector::Map::getMap() const
{
    return _charMap;
}

std::vector<Texture2D> PlayerSelector::Map::getTextures() const
{
    return _textures[current];
}

void PlayerSelector::Map::next()
{
    current = (current + 1 == _textures.size()) ? 0 : current + 1;
}

void PlayerSelector::Map::prev()
{
    current = (current == 0) ? _textures.size() - 1 : current - 1;
}

size_t PlayerSelector::Map::getMapType() const
{
    return current;
}

void PlayerSelector::Map::draw()
{
    float x;
    float y = 0;
    float scale;

    std::cout << "LINE " << _charMap.size() << std::endl;

    for (const std::string &line : _charMap)
    {
        x = 0;
        for (const char &c : line)
        {
            if (c == '1' || c == '2' || c == '3' || c == '4')
            {
                scale = _characters[c - '1'].second * 0.35;
                DrawModelEx(_characters[c - '1'].first, {x * _COEF - (float)2.4, y * _COEF - (float)0.5, 0}, {1, 0, 0}, 90, {scale, scale, scale}, Raylib::Color::White().getCStruct());
            }
            if (c == 'W' || c == 'E')
            {
                DrawCubeTexture(_textures[current][WALL], {x * _COEF - (float)2.4, y * _COEF - (float)0.5, 0}, _COEF, _COEF, _COEF, Raylib::Color::White().getCStruct());
            }
            if (c == 'M')
            {
                DrawCubeTexture(_textures[current][BOX], {x * _COEF - (float)2.4, y * _COEF - (float)0.5, 0}, _COEF, _COEF, _COEF, Raylib::Color::White().getCStruct());
            }
            DrawCubeTexture(_textures[current][FLOOR], {x * _COEF - (float)2.4, y * _COEF - (float)0.5, -_COEF}, _COEF, _COEF, _COEF, Raylib::Color::Gray().getCStruct());
            x++;
        }
        y++;
    }
}