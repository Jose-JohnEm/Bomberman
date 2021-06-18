/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** ArtificialIntelligence
*/

#include "ArtificialIntelligence.hpp"

Game::ArtificialIntelligence::ArtificialIntelligence(const std::vector<AI> &AIs, const std::vector<Human> &humans, const std::vector<std::string> &map)
    : _AIs(AIs), _humans(humans), _map(map)
{
}