/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.hpp
*/

#ifndef PLAYERSELECTOR_SELECTOR
#define PLAYERSELECTOR_SELECTOR

#include "Camera3D/Camera3D.hpp"
#include "Texture/Texture.hpp"
#include "raylib.h"
#include "PlayerSelector/Player.hpp"
#include <filesystem>

#define POS_1 Raylib::Vector3(-3.25, -0.15, 0)
#define POS_2 Raylib::Vector3(-1.25, -0.15, 0)
#define POS_3 Raylib::Vector3(0.80, -0.15, 0)
#define POS_4 Raylib::Vector3(2.80, -0.15, 0)

namespace PlayerSelector
{
    class Selector
    {
        public:
            Selector();
            ~Selector();

            void load();
            void unload(const int &id);
            void unloadAll();
            void draw();
            void next(const int &player);
            void prev(const int &player);

            std::vector<Raylib::Vector3> POS;

        private:

            void updateRotationAxis();

            Raylib::Camera3D *camera;
            std::vector<PlayerSelector::Player> _players;
            int _nbCharacters;
            std::vector<std::pair<std::string, std::string>> _charaDictionary;  

            float _rotationAxis;
    };
}

#endif