/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

#include "MotionlessEntity.hpp"

Game::SolidWall::SolidWall(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Iron/wall.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Snow/wall.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/wall.png")));
}

Game::BreakableWall::BreakableWall(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Iron/box.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Snow/box.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/box.png")));
}

Game::Floor::Floor(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Iron/floor.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Snow/floor.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/floor.png")));
}