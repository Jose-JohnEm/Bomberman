/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#include "Player.hpp"

Game::Player::Player()
{
}

Game::Player::Player(const std::string &name, const std::pair<float, float> &positions, const size_t &kills, const size_t &brokenWalls, const std::array<size_t, 5> &powerUps)
: _name{name}, _positions{positions}, _kills{kills}, _brokenWalls{brokenWalls}, _powerUps{powerUps}
{

}


Game::Player::~Player()
{
}
