/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

#include "Astar.hpp"

Game::Point::Point(const int &x, const int &y)
    : _x{x}, _y{y}
{
}

Game::Astar::Astar(const std::vector<std::string> &map, const Point &start, const Point &target)
    : _map(map),
    _mapDimensions(std::make_pair(map[0].size(), map.size())),
    _start(start),
    _target(target),
    _neighbors(
        {
            Point(-1, -1),
            Point(1, -1),
            Point(-1, 1),
            Point(1, 1),
            Point(0, -1),
            Point(-1, 0),
            Point(0, 1),
            Point(1, 0)
        }
    )
{
}

Game::Node::Node(const Point &positions, const Point &parentPositions, const int &g, const int &h)
    : _positions(positions), _parentPositions(parentPositions), _g(g), _h(h)
{
}

bool Game::Astar::targetIsFound(void)
{
    Node start(_start, 0, 0, calculateHValue(_start));

    _open.push_back(start);
    while (!_open.empty())
    {
        // Load the open list head
        Node openHead = _open.front();
        // Remove the open list head
        _open.pop_front();
        // Added it into closed list
        _close.push_back(openHead);
        if (targetIsReached(openHead))
        {
            return true;
        }
    }
    return false;
}

bool Game::Astar::targetIsReached(Node &openHead) //TODO: to continue
{
    Point neighbor;

    for (int i = 0; i < _neighbors.size(); i++)
    {
        // Select a specific slot
        neighbor = openHead._positions + _neighbors[i];
        if (isDestination(neighbor))
        {
            return true;
        }
        else if (isInMap(neighbor) && isUnBlocked(neighbor))
        {
        }
    }
    return false;
}

bool Game::Astar::isQualityNode(const Point &currentCell, const int &currentCost)
{
    // In closed list
    std::list<Node>::iterator itClose(std::find(_close.begin(), _close.end(), currentCell));

    if (itClose != _close.end())
    {
        if ((*itClose)._g + (*itClose)._h < currentCost)
        {
            return true;
        }
        else
        {
            _close.erase(itClose);
            return false;
        }
    }

    // In open list
    std::list<Node>::iterator itOpen(std::find(_open.begin(), _open.end(), currentCell));

    if (itOpen != _open.end())
    {
        if ((*itOpen)._g + (*itOpen)._h < currentCost)
        {
            return true;
        }
        else
        {
            _open.erase(itOpen);
            return false;
        }
    }
    return false;
}