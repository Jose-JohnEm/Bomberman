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

            Player(const std::string &obj, const std::string &texture, const float &scalable, const int &idCharacter, const std::string &name);
            ~Player();

            void draw(const float &rotation, const Raylib::Vector3 &pos) const;
            int getId(void) const;
            const std::string getName() const;
            std::pair<Model, float> getModel() const;


        private:
            std::string _name;
            int _idCharacter;
            float _scalable;
            Model _persoModel;
            Raylib::Texture _persoTexture;
    };
    
} // namespace PlayerSelector

#endif