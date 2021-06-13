/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

inline Raylib::Vector3 Game::MotionlessEntity::getPositions(void) const
{
    return _positions;
}

inline void Game::MotionlessEntity::setPositions(Raylib::Vector3 &vector)
{
    _positions = vector;
}

inline void Game::MotionlessEntity::setShouldDisplay(const bool &shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

inline bool Game::MotionlessEntity::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

inline void Game::SolidWall::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

inline void Game::BreakableWall::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[_mapType].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

inline void Game::Floor::drawEntity()
{
    // TODO: USE ENCAPSULATION
    DrawCubeTexture(_textures[0].getCStruct(), _positions.getCStruct(), 1.0f, 1.0f, 1.0f, WHITE);
}

inline std::string Game::SolidWall::getType() const
{
    return ("Wall");
}

inline std::string Game::BreakableWall::getType() const
{
    return ("Wall");
}

inline std::string Game::Floor::getType() const
{
    return ("Floor");
}