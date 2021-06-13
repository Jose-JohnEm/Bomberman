/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

#include "../includes/MotionlessEntity.hpp"

Raylib::Vector3 Game::MotionlessEntity::getPositions(void) const
{
    return _positions;
}

void Game::MotionlessEntity::setPositions(Raylib::Vector3 &vector)
{
    _positions = vector;
}

void Game::MotionlessEntity::setShouldDisplay(bool shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

bool Game::MotionlessEntity::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

void Game::SolidWall::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

void Game::BreakableWall::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

void Game::Floor::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[0].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

std::string Game::SolidWall::getType() const
{
    return ("Wall");
}

Game::SolidWall::SolidWall(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/wall.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Snow/wall.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Iron/wall.png")));
}

std::string Game::BreakableWall::getType() const
{
    return ("Wall");
}

Game::BreakableWall::BreakableWall(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/box.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Snow/box.png")));
    _textures.push_back(*(new Raylib::Texture("resources/map/Iron/box.png")));
}

std::string Game::Floor::getType() const
{
    return ("Floor");
}

Game::Floor::Floor(Raylib::Vector3 positions, size_t mapType)
{
    _positions = positions;
    _mapType = mapType;
    _textures.push_back(*(new Raylib::Texture("resources/map/Wood/floor.png")));
}

//TODO: inline!