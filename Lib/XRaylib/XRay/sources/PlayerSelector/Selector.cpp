/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.cpp
*/

#include "PlayerSelector/Selector.hpp"

PlayerSelector::Selector::Selector()
: camera(nullptr), _rotationAxis(0), _players({})
{
    POS.push_back(POS_1);
    POS.push_back(POS_2);
    POS.push_back(POS_3);
    POS.push_back(POS_4);

    std::cout  << std::endl << "####### Start Player Selector #######"  << std::endl << std::endl;
}

PlayerSelector::Selector::~Selector()
{

}

void PlayerSelector::Selector::load()
{
    std::cout << std::endl << "######## Load Player Selector ########" << std::endl << std::endl;
    
    if (_players.size() == 4)
        return;
    if (!camera)
    {
        Raylib::Vector3 pos(0, 0, 10);
        Raylib::Vector3 target(0, 0, 0);
        Raylib::Vector3 up(0, 1, 0);

        camera = new Raylib::Camera3D(pos, target, up, 30);
        std::cout << "Camera OK" << std::endl;

        camera->updateCamera();

        camera->setCameraMode(CAMERA_FREE);
    }

    std::cout << std::endl << "######## Init Player Selector ########" << std::endl << std::endl;

    _players.push_back(Player({"resources/players/3D/Smiley Yellow Suit/smiley.obj", "resources/players/3D/Smiley Yellow Suit/smileyface_c.png"}));


}

void PlayerSelector::Selector::unload()
{   
    std::cout << std::endl << "######## End Player Selector ########" << std::endl << std::endl;

    if (_players.size() == 0)
        return;

    _players.pop_back();
}

void PlayerSelector::Selector::unloadAll()
{
    for (PlayerSelector::Player &player : _players)
    {
        unload();
    }

    delete camera;
}

void PlayerSelector::Selector::updateRotationAxis()
{
    _rotationAxis += 0.24;

    if (_rotationAxis > 360)
        _rotationAxis -= 360;
}

void PlayerSelector::Selector::draw()
{
    char i = 0;
    
    camera->beginMode3D();

    for (PlayerSelector::Player &player : _players)
    {
        player.draw(_rotationAxis, POS[i]);
        i++;
    }
    
    updateRotationAxis();
    camera->endMode3D();
}