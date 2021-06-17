/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

#ifndef ASTAR_HPP_
#define ASTAR_HPP_

#include <utility>
#include <vector>
#include <string>
#include <array>

namespace Game
{
    class Point
    {
        public:
            /**
             * @brief Construct a new Point object
             *
             * @param x The abscissa coordinate
             * @param y The ordinate coordinate
             */
            Point(const int &x = 0, const int &y = 0);

            /**
             * @brief Equal operator
             *
             * @param point Point to compare
             * @return true if the points are the same, false otherwise
             */
            bool operator==(const Point &point) {
                return (point._x == _x && point._y == _y);
            }

            /**
             * @brief Add operator
             *
             * @param point Point to add
             * @return A new point with addition positions
             */
            Point operator+(const Point &point) {
                return Point(point._x + _x, point._y + _y);
            }

            const int _x; // The abscissa coordinate
            const int _y; // The ordinate coordinate
    };

    class Node
    {
        public:
            Point _positions; // Square positions
            Point _parentPositions; // Parent square positions
            int _g; // The movement cost to move from the starting point to a given square on the grid, following the path generated to get there
            int _h; // The estimated movement cost to move from that given square/node on the grid to the final destination
    };

    class Astar
    {
        public:
            /**
             * @brief Construct a new Astar object
             *
             * @param map The map
             * @param start The start point
             * @param target The end map
             */
            Astar(const std::vector<std::string> &map, const Point &start, const Point &target);

        private:
            std::vector<std::string> _map; // The map
            Point _start; // The start point
            Point _target; // The start point
            std::array<Point, 8> _neighbors; // An array of 8 points representing the 8 neighbors of the current node
            // #######
            // #0#4#1#
            // #######
            // #5#C#7#  THE NEIGHBORS[8]
            // #######
            // #2#6#3#
            // #######
    };

    #include "Astar.inl"
}

#endif /* !ASTAR_HPP_ */
