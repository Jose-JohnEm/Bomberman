/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.cpp
*/

#include "PlayerSelector.hpp"

PlayerSelector::PlayerSelector()
: camera(nullptr), perso(nullptr), texture(nullptr), _rotationAxis(0)
{
    std::cout  << std::endl << "####### Start Player Selector #######"  << std::endl << std::endl;
}

PlayerSelector::~PlayerSelector()
{

}

void PlayerSelector::load()
{
    std::cout << std::endl << "######## Load Player Selector ########" << std::endl << std::endl;
    
    if (camera != nullptr || perso != nullptr || texture != nullptr)
        return;

    std::cout << std::endl << "######## Init Player Selector ########" << std::endl << std::endl;

    Raylib::Vector3 pos(0, 0, 10);
    Raylib::Vector3 target(0, 0, 0);
    Raylib::Vector3 up(0, 1, 0);

    camera = new Raylib::Camera3D(pos, target, up, 30);
    std::cout << "Camera OK" << std::endl;

    camera->updateCamera();
    
    perso = new Model(LoadModel("resources/players/3D/Smiley Yellow Suit/smiley.obj"));
    std::cout << "Model OK" << std::endl;
    
    texture = new Raylib::Texture("resources/players/3D/Smiley Yellow Suit/smileyface_c.png");
    std::cout << "texture OK" << std::endl;

    
    SetMaterialTexture(&perso->materials[0], MAP_DIFFUSE, texture->getCStruct());
    
    camera->setCameraMode(CAMERA_FREE);

}

void PlayerSelector::unload()
{   
    std::cout << std::endl << "######## End Player Selector ########" << std::endl << std::endl;

    if (camera == nullptr || perso == nullptr || texture == nullptr)
        return;

    delete camera;
    delete perso;
    delete texture;
}

void PlayerSelector::updateRotationAxis()
{
    _rotationAxis += 0.24;
    
    if (_rotationAxis > 360)
        _rotationAxis -= 360;
}

void PlayerSelector::draw()
{
    camera->beginMode3D();

    DrawModelEx(*perso, {-3.25, -0.15, 0}, {0, 1, 0}, _rotationAxis, {0.6, 0.6, 0.6}, WHITE);
    
    updateRotationAxis();
    camera->endMode3D();
}