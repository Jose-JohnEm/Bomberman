/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <array>
#include <utility>
#include <string>

typedef enum {
    SKATE,
    BOMB,
    PASS,
    FIRE,
    LIFE
} Powerups;

namespace Game
{
    class Player
    {
        public:
           /**
            * @brief Construct the Player object
            */
            Player();

            /**
            * @brief Destroy the Player object
            */
            ~Player();

        private:
            std::string _name; // Name of the player entitiy
            std::pair<float, float> _positions; // A pair of float for player positions (x, y)
            int _brokenWalls; // Amount of broken walls
            int _kills; // Amount of kills
            std::array<size_t, 5> _powerups; // Amount of powerups
    };

    #include "Player.inl"
}
#endif /* !PLAYER_HPP_ */
