/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Modeler.hpp
*/

#ifndef MODELER_HPP_
#define MODELER_HPP_

#include <string>
#include <vector>
#include "raylib.h"

#include "Clock.hpp"

#define FRAMETIME 0.03f

struct Animator
{
    const std::string WALK = "null";
    const std::string BOMB = "null";
    const std::string EMOTE = "null";
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
        ~Modeler();

        void makeWalk();
        void makeBomb();
        void makeEmote();

        Model &getModel();

        void update();

    private:

        bool isThereAnimationsPath(const Animator &animation_path) const;

        Model _model;
        std::vector<ModelAnimation> _animations;

        const bool _isAnimated;
        int _frame;

        Clock clock;
        int _currentAnimation;
};

#endif