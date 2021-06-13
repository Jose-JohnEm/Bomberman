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

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps)
    : _name{name}, _positions{positions}, _kills{kills}, _brokenWalls{brokenWalls}, _powerUps{powerUps}
{

}

Game::AI::AI()
{
}

Game::Human::Human()
{
}