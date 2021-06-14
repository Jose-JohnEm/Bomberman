/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.cpp
*/

#include "Modeler.hpp"

Modeler::Modeler(const std::string &obj_path, const std::string &texture_path, const Animator &animation_path)
: _model(LoadModel(texture_path.c_str())),
_isAnimated(isThereAnimationsPath(animation_path)),
_currentAnimation(WALK)
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
_currentAnimation(WALK)
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
    if (clock.doesTimeElapsed(FRAMETIME)) {
        _frame++;
        if (_frame >= _animations[_currentAnimation].frameCount)
            _frame = 0;
        UpdateModelAnimation(_model, _animations[_currentAnimation], _frame);
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