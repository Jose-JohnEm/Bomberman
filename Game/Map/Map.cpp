/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#include "Map.hpp"

Game::Map::Map()
{
}

Game::Map::Map(const size_t &width, const size_t &height)
    : _width{width + BORDER}, _height{height + BORDER}
{
    srand(time(NULL));
    create();
    fill('W');
    maze();
}

Game::Map::~Map()
{
}
