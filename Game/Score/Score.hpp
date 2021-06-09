/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include "../Player/Player.hpp"

namespace Game
{
    class Score
    {
        public:
            /**
            * @brief Construct the Score object
            * 
            * @param player A const reference to Class Player
            */
            Score(Player const &player);

            /**
            * @brief Destroy the Score object
            */
            ~Score();

            /**
             * @brief Get the Score of the Player
             *
             * @return A size_t
             */
            size_t getScore() const;

            /**
             * @brief Set the Score of the Player
             *
             * @param score A const reference to a size_t
             */
            void setScore(size_t const &score);

            /**
             * @brief Get the mulitiplicator of Player's score
             *
             * @return A size_t
             */
            float getScoreMultiplicator(size_t const &score) const;
        private:
            size_t _score;
            Player _player;
    };

    #include "Score.inl"
}
#endif /* !SCORE_HPP_ */
