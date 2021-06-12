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
    P_SKATE,
    P_BOMB,
    P_PASS,
    P_FIRE,
    P_LIFE
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
            * @brief Construct the Player object (Copy Constructor)
            *
            * @param name A const reference to a std::string
            * @param position A const reference to a std::pair of float
            * @param brokenWalls A const reference to a size_t
            * @param kills A const reference to a size_t
            * @param powerUps A const reference to a std::array of 5 int
            */
            Player(const std::string &name, const std::pair<float, float> &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps);

            /**
            * @brief Destroy the Player object
            */
            ~Player();

            /**
             * @brief Get the Name of the Player
             *
             * @return A string
             */
            std::string getName(void) const;

            /**
             * @brief Get the Positions of the Player
             *
             * @return A pair of floats
             */
            std::pair<float, float> getPositions(void) const;

            /**
             * @brief Get Broken Walls by the Player
             *
             * @return A size_t
             */
            size_t getBrokenWalls(void) const;

            /**
             * @brief Get Kills by the Player
             *
             * @return A size_t
             */
            size_t getKills(void) const;

            /**
             * @brief Get PowerUps gotten by the Player
             *
             * @return An Array of 5 (int)
             */
            std::array<int, 5> getPowerUps(void) const;

            /**
             * @brief Get the player ID
             *
             * @return An int which represents the ID of the player
             */
            int getID(void) const;

            /**
             * @brief Set the name of the player
             *
             * @param name A const reference to a string
             */
            void setName(const std::string &name);

            /**
             * @brief Set the Player positions
             *
             * @param positions A const reference to a pair of floats
             */
            void setPositions(const std::pair<float, float> &positions);

            /**
             * @brief Set the broken walls number
             *
             * @param brokenWalls A const reference to a size_t
             */
            void setBrokenWalls(const size_t &brokenWalls);

            /**
             * @brief Set the kills number
             *
             * @param kills A const reference to a size_t
             */
            void setKills(const size_t &kills);

            /**
             * @brief Set the powerUps of the player
             *
             * @param powerUps A const reference to an array of 5 int
             */
            void setPowerUps(const std::array<int, 5> &powerUps);

            /**
             * @brief Set the ID of the player
             */
            void setID(const int &ID);

        private:
            std::string _name; // Name of the player entitiy
            std::pair<float, float> _positions; // A pair of float for player positions (x, y)
            size_t _brokenWalls; // Amount of broken walls
            size_t _kills; // Amount of kills
            std::array<int, 5> _powerUps; // Amount of powerUps
            int _ID; // ID of the player
    };

    #include "Player.inl"
}

#endif /* !PLAYER_HPP_ */