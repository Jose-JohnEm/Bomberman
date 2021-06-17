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
    }
    return false;
}