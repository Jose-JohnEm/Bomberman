/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.hpp
*/

#ifndef MODELER_HPP_
#define MODELER_HPP_

//TODO: GLOBAL REVIEW (raylib out the encapsulation! no documentation!)

#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"
#include "Clock.hpp"

#define FRAMETIME 0.03f

struct Animator
{
    std::string WALK = "null";
    std::string BOMB = "null";
    std::string EMOTE = "null";
};

enum AnimSequence {
    WALK,
    BOMB,
    EMOTE
};

class Modeler
{
    public:

        Modeler();
        Modeler(const std::string &obj_path, const std::string &texture_path, const Animator &animation_path);

        Modeler& operator=(Modeler model);

        ~Modeler();

        void makeWalk();
        void makeBomb();
        void makeEmote();

        Model &getModel();

        void update();

        std::string getObjPath();
        std::string getTexturePath();
        Animator getAnimationPath();


    private:

        bool isThereAnimationsPath(const Animator &animation_path) const;

        Model _model;
        std::string _model_path;
        std::string _texture_path;
        std::vector<ModelAnimation> _animations;
        Animator _animator;

        bool _isAnimated;
        int _frame;

        Clock clock;
        int _currentAnimation;
};

#endif