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
    std::list<Point> path;
    std::pair<int, int> point;
    int xAI = 0, yAI = 0, xHuman = 0, yHuman = 0, xTarget = 0, yTarget = 0, currentDistance = 0;

    for (const Game::AI &AI : _AIs)
    {
        // Get AI positions
        Raylib::Vector3 AIPositions = AI.getPositions();
        xAI = static_cast<int>(std::round(AIPositions.x));
        yAI = static_cast<int>(std::round(AIPositions.y));

        for (const Game::Human &human : _humans)
        {
            // Get human positions
            Raylib::Vector3 humanPositions = human.getPositions();
            xHuman = static_cast<int>(std::round(humanPositions.x));
            yHuman = static_cast<int>(std::round(humanPositions.y));

            // Calcul euclidean distance
            currentDistance = calculateDistance(Point(xAI, yAI), Point(xHuman, yHuman));

            // Set the smallest distance
            smallestDistance = (currentDistance < smallestDistance) ? currentDistance : smallestDistance;

            // Set the target positions
            if (smallestDistance == currentDistance)
            {
                targetPositions = humanPositions;
                xTarget = static_cast<int>(std::round(targetPositions.x));
                yTarget = static_cast<int>(std::round(targetPositions.y));
            }
        }

        // Display the target
        std::cout << "AI n°" << AI.getID() << " Target " << xTarget << "," << (_map.size() - yTarget) << std::endl;

        // Run Astar algorithm
        Astar astar(_map, Point(xAI, (_map.size() - yAI)), Point(xTarget, (_map.size() - yTarget)));

        if (astar.targetIsFound())
        {
            // Get the path finding
            astar.fillPath(path);
            std::cout << "AI n°" << AI.getID();
            for(const Point &point : path)
            {
                std::cout << " (" << point._x << "," << point._y << ")";
            }
            std::cout << std::endl;

            // Get the next destination
            std::cout << "AI n°" << AI.getID() << " Next destination " << path.front()._x << "," << path.front()._y << std::endl;
            std::cout << "AI n°" << AI.getID() << " Positions " << xAI << "," << (_map.size() - yAI) << std::endl;
            point = std::make_pair(path.front()._x - xAI, path.front()._y - (_map.size() - yAI));
            std::cout << "AI n°" << AI.getID() << " " << convertPointIntoAction(point) << std::endl;

            // Order the AI to do this action
            // Bomberman game;
            // game.doPlayerAction(AI.getID(), convertPointIntoDirection(point));

            // Clear the path
            path.clear();
        }
        else
        {
            // Drop a bomb
        }
    }
}