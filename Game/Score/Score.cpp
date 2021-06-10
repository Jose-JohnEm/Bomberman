/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

#include "Score.hpp"

Game::Score::Score(const std::array<std::size_t, 7> &settings, Game::Player const &player)
    : _settings(settings), _player(player)
{
    // Calcul the total of powerUps
    size_t powerUpsTotal = std::accumulate(_player.getPowerUps().begin(), _player.getPowerUps().end(), 0);

    // Calcul the score
    _score = ((_player.getKills() * 200) + (powerUpsTotal * 50) + (_player.getBrokenWalls() * 10)) * getCoefficient();
}

Game::Score::~Score()
{
}
