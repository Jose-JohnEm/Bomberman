/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.cpp
*/

#include "PlayerSelector/Player.hpp"

PlayerSelector::Player::Player(const std::string &obj, const std::string &texture, const float &scalable, const int &idCharacter)
: _persoModel(LoadModel(obj.c_str())), _persoTexture(Raylib::Texture(texture)), _idCharacter(idCharacter), _scalable(scalable)
{
    SetMaterialTexture(&_persoModel.materials[0], MAP_DIFFUSE, _persoTexture.getCStruct());
}

PlayerSelector::Player::~Player()
{
    
}

void PlayerSelector::Player::draw(const float &rotation, const Raylib::Vector3 &pos)
{
    DrawModelEx(_persoModel, pos.getCStruct(), {0, 1, 0}, rotation, {_scalable, _scalable, _scalable}, WHITE);
}

int PlayerSelector::Player::getId(void)
{
    return _idCharacter;
}