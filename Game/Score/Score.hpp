/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <string>

namespace Game
{
    class Score
    {
        public:
            /**
            * @brief Construct the Score object
            */
            Score();

            /**
            * @brief Destroy the Score object
            */
            ~Score();
            size_t getScore() const;
            void setScore(size_t const &score);
        private:
            size_t _score;
    };

    #include "Score.inl"
}
#endif /* !SCORE_HPP_ */
