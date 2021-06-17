/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Astar
*/

#ifndef ASTAR_HPP_
#define ASTAR_HPP_

#include <utility>

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

        private:
            int _x; // The abscissa coordinate
            int _y; // The ordinate coordinate
    };

    class Astar
    {
    };

    #include "Astar.inl"
}

#endif /* !ASTAR_HPP_ */
