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
            std::vector<std::string> _map;
            Point _start;
            Point _target;
    };

    #include "Astar.inl"
}

#endif /* !ASTAR_HPP_ */
