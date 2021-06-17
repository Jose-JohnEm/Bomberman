/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

inline float Game::Astar::calculateHValue(const Point &currentCell) const
{
    return std::sqrt(std::pow(_target._x - currentCell._x, 2) + std::pow(_target._y - currentCell._y, 2));
}