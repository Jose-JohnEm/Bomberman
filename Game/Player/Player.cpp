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
    _scalable(0.6),
    _color(Raylib::Color::Red())
{

}

Animator Game::Player::getAnimator(const std::vector<std::string> &animation_path)
{
    for (auto p : animation_path)
        std::cout << p << std::endl;
    if (animation_path.size() == 3)
        return Animator({animation_path[0], animation_path[1], animation_path[2]});
    else
        return Animator({"null", "null", "null"});
}

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
    : _name{name},
    _positions{positions},
    _kills{0},
    _brokenWalls{0},
    _powerUps{0},
    _model(obj_path, texture_path, getAnimator(animation_path)),
    _color(color),
    _scalable(scalable)
{
    std::cout << "Hey I'm a new player : " << name << std::endl;
}

Game::AI::AI(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
: Player(name, positions, obj_path, texture_path, animation_path, scalable, color)
{

}

Game::Human::Human(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
: Player(name, positions, obj_path, texture_path, animation_path, scalable, color)
{

}