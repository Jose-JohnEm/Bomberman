/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

#include "Score.hpp"

Game::Score::Score(const std::array<std::size_t, 8> &settings, Game::Player const &player)
    : _settings(settings), _player(player)
{
    std::array<int, 5> powerUps = _player.getPowerUps();
    // Calcul the total of powerUps
    size_t powerUpsTotal = std::accumulate(powerUps.begin(), powerUps.end(), 0);

    // Calcul the score
    _score = ((_player.getKills() * 200) + (powerUpsTotal * 50) + (_player.getBrokenWalls() * 10)) * getCoefficient();
}

Game::Score::~Score()
{
}
