/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

inline size_t Game::Map::getWidth(void) const
{
    return _width;
}

inline size_t Game::Map::getHeight(void) const
{
    return _height;
}

inline void Game::Map::setWidth(const size_t width)
{
    _width = width;
}

inline void Game::Map::setHeight(const size_t height)
{
    _height = height;
}