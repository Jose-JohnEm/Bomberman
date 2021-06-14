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
    : _name{name},
    _positions{positions},
    _kills{kills},
    _brokenWalls{brokenWalls},
    _powerUps{powerUps},
    _model("resources/players/3D/Bombermans/white_tpose.glb", "resources/players/3D/Bombermans/texture.png", {}),
    _color(Raylib::Color::Red())
{

}

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const Animator &animation_path, const Raylib::Color color)
    : _name{name},
    _positions{positions},
    _kills{0},
    _brokenWalls{0},
    _powerUps{0},
    _model(obj_path, texture_path, animation_path),
    _color(color)
{

}

Game::AI::AI(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const Animator &animation_path, const Raylib::Color color)
: Player(name, positions, obj_path, texture_path, animation_path, color)
{

}

Game::Human::Human(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const Animator &animation_path, const Raylib::Color color)
: Player(name, positions, obj_path, texture_path, animation_path, color)
{

}