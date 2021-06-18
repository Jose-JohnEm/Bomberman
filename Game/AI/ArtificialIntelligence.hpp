/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

#ifndef ARTIFICIALINTELLIGENCE_HPP_
#define ARTIFICIALINTELLIGENCE_HPP_

#include "../Player/Player.hpp"

namespace Game
{
    class ArtificialIntelligence
    {
        public:
            /**
             * @brief Construct a new ArtificialIntelligence object
             *
             * @param AIs A vector of AI objects
             * @param humans A vector of Human objects
             * @param map The game map
             */
            ArtificialIntelligence(const std::vector<AI> &AIs, const std::vector<Human> &humans, const std::vector<std::string> &map);

        private:
            std::vector<AI> _AIs; // A vector of AI objects
            std::vector<Human> _humans; // A vector of Human objects
            std::vector<std::string> _map; // The game map
    };

    #include "ArtificialIntelligence.inl"
}

#endif /* !ARTIFICIALINTELLIGENCE_HPP_ */
