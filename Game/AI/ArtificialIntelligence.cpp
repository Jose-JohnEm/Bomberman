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
    int smallestDistance = _map.size() * 2;
    Raylib::Vector3 targetPositions = {0, 0, 0};

    for (const Game::AI &AI : _AIs)
    {
        // Get AI positions
        Raylib::Vector3 AIPositions = AI.getPositions();

        for (const Game::Human &human : _humans)
        {
            // Get human positions
            Raylib::Vector3 humanPositions = human.getPositions();

            // Calcul euclidean distance
            int currentDistance = calculateDistance(Point(AIPositions.x, AIPositions.y), Point(humanPositions.x, humanPositions.y));

            // Set the smallest distance
            smallestDistance = (currentDistance < smallestDistance) ? currentDistance : smallestDistance;

            // Set the target positions
            if (smallestDistance == currentDistance)
            {
                targetPositions = humanPositions;
            }
        }

        // Run Astar algorithm
        Astar astar(_map, Point(AIPositions.x, AIPositions.y), Point(targetPositions.x, targetPositions.y));

        if (astar.targetIsFound())
        {
            // Get the path finding
            std::list<Point> path;
            astar.fillPath(path);

            // Get the next direction
            std::pair<int, int> point = std::make_pair((*path.begin() + 1)._x - AIPositions.x,  (*path.begin() + 1)._y - AIPositions.y);
            std::cout << "AI n°" << AI.getID() << " " << convertPointIntoDirection(point) << std::endl;

            // Move the AI to this direction
            // Bomberman game;
            // game.doPlayerAction(AI.getID(), convertPointIntoDirection(point));
        }
        else
        {
            // Drop a bomb
        }
    }
}