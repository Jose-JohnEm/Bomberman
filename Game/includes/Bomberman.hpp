/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include "Interfaces/IGame.hpp"

namespace Game
{
    class Bomberman : public IGame {
        public:
            Bomberman();
            ~Bomberman();

        private:
    };
}

#include "Bomberman.inl"

#endif /* !BOMBERMAN_HPP_ */