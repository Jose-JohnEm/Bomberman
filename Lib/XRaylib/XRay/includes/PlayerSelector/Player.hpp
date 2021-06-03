/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.hpp
*/

#ifndef PLAYERSELECTOR_PLAYER
#define PLAYERSELECTOR_PLAYER

#include "raylib.h"
#include "Texture/Texture.hpp"
#include "Vector3/Vector3.hpp"

namespace PlayerSelector
{
    class Player
    {
        public:

            Player(const std::string &obj, const std::string &texture, const int &idCharacter);
            ~Player();

            void draw(const float &rotation, const Raylib::Vector3 &pos);
            int getId(void);


        private:
            int _idCharacter;
            Model _persoModel;
            Raylib::Texture _persoTexture;
    };
    
} // namespace PlayerSelector

#endif