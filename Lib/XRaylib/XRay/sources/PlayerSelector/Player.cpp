/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.cpp
*/

#include "PlayerSelector/Player.hpp"

PlayerSelector::Player::Player(const std::string &obj, const std::string &texture)
: _persoModel(LoadModel(obj.c_str())), _persoTexture(Raylib::Texture(texture))
{

    SetMaterialTexture(&_persoModel.materials[0], MAP_DIFFUSE, _persoTexture.getCStruct());
}

PlayerSelector::Player::~Player()
{

}

void PlayerSelector::Player::draw(const float &rotation, const Raylib::Vector3 &pos)
{
    DrawModelEx(_persoModel, pos.getCStruct(), {0, 1, 0}, rotation, {0.6, 0.6, 0.6}, WHITE);
}