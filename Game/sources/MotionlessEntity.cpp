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

std::string Game::SolidWall::getType()
{
    return ("Wall");
}

std::string Game::MotionlessEntity::getPathToObj() const
{
    return _pathToObj;
}

std::vector<std::string> Game::MotionlessEntity::getPathToPngs() const
{
    return _pathToPngs;
}

Game::SolidWall::SolidWall(Raylib::Vector3 positions)
{
    _pathToObj = "resources/assets/3D/WoodBlock/UsefulStepWoodBlock1x1x1M.obj";
    _pathToPngs.push_back("resources/map/Wood/wall.png");
    _pathToPngs.push_back("resources/map/Snow/wall.png");
    _pathToPngs.push_back("resources/map/Iron/wall.png");
}

std::string Game::BreakableWall::getType()
{
    return ("Wall");
}

Game::BreakableWall::BreakableWall(Raylib::Vector3 positions)
{
    _pathToObj = "resources/assets/3D/WoodBlock/UsefulStepWoodBlock1x1x1M.obj";
    _pathToPngs.push_back("resources/map/Wood/box.png");
    _pathToPngs.push_back("resources/map/Snow/box.png");
    _pathToPngs.push_back("resources/map/Iron/box.png");
}