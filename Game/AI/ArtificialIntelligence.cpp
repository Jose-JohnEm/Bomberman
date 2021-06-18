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
    if (AIs.empty())
    {
        throw std::invalid_argument("ERROR: No AIs");
    }
}

void Game::ArtificialIntelligence::run(void) const
{
    for (const Game::AI &AI : _AIs)
    {
        // Get AI positions
        Raylib::Vector3 AIPositions = AI.getPositions();
        float xAI = AIPositions.x, yAI = AIPositions.y;
        for (const Game::Human &human : _humans)
        {
            // Get human positions
            Raylib::Vector3 humanPositions = human.getPositions();
            float xHuman = humanPositions.x, yHuman = humanPositions.y;
            std::cout << "Distance between AI n°" << AI.getID() << " and human n°" << human.getID() << " : " << calculateDistance(Point(xAI, yAI), Point(xHuman, yHuman)) << std::endl;
        }
    }
}