/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.cpp
*/

#include "Modeler.hpp"

Modeler::Modeler(const std::string &obj_path, const std::string &texture_path, const Animator &animation_path)
: _model(LoadModel(obj_path.c_str())),
_isAnimated(isThereAnimationsPath(animation_path)),
_currentAnimation(WALK),
_frame(0)
{
    int fake_counter = 0;

    if (_isAnimated)
    {
        _animations.push_back(LoadModelAnimations(animation_path.WALK.c_str(), &fake_counter)[0]);
        _animations.push_back(LoadModelAnimations(animation_path.BOMB.c_str(), &fake_counter)[0]);
        _animations.push_back(LoadModelAnimations(animation_path.EMOTE.c_str(), &fake_counter)[0]);
    }

    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, LoadTexture(texture_path.c_str()));
}

Modeler::Modeler()
: _model(LoadModel("resources/players/3D/Bombermans/white_tpose.glb")),
_isAnimated(true),
_currentAnimation(WALK),
_frame(0)
{

    int fake_counter = 0;

    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_walking.glb", &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_bomb.glb", &fake_counter)[0]);
    _animations.push_back(LoadModelAnimations("resources/players/3D/Bombermans/animations/white_emote.glb", &fake_counter)[0]);

    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, LoadTexture("resources/players/3D/Bombermans/texture.png"));
}

Modeler::~Modeler()
{

}

bool Modeler::isThereAnimationsPath(const Animator &animation_path) const
{
    if (animation_path.EMOTE == "null" || animation_path.BOMB == "null" || animation_path.WALK == "null")
        return false;
    return true;
}

void Modeler::update()
{
    if (!_isAnimated)
        return;
    std::cout << "The model is animated !" << std::endl;
    if (clock.doesTimeElapsed(FRAMETIME)) {
        _frame++;
        std::cout << "The frame is incremented !" << std::endl;
        if (_frame >= _animations[_currentAnimation].frameCount)
            _frame = 0;
        std::cout << "The frame is good, lets update !" << std::endl;
        UpdateModelAnimation(_model, _animations[_currentAnimation], _frame);
        std::cout << "ITS UPDATED !!!" << std::endl;
    }
}

void Modeler::makeWalk()
{
    _currentAnimation = WALK;
}

void Modeler::makeBomb()
{
    _currentAnimation = BOMB;
}

void Modeler::makeEmote()
{
    _currentAnimation = EMOTE;
}

Model &Modeler::getModel()
{
    return _model;
}