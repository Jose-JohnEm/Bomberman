/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#include "MapGeneration.hpp"

Game::MapGeneration::MapGeneration()
{
}

Game::MapGeneration::MapGeneration(const size_t &width, const size_t &height)
    : _width{width + BORDER}, _height{height + BORDER}
{
    if (width % 2 == 0 || width <= 3 || height < 3)
    {
        throw std::length_error("ERROR: Invalid map dimensions");
    }
    srand(time(NULL));
    create();
    fill(BREAK_WALL);
    maze();
    placeBorders();
    placeSolidWalls();
}

Game::MapGeneration::~MapGeneration()
{
}
