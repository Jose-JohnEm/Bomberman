/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

inline float Game::ArtificialIntelligence::calculateDistance(const Point &start, const Point &end) const
{
    return std::sqrt(std::pow(end._x - start._x, 2) + std::pow(end._y - start._y, 2));
}