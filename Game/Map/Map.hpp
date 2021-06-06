/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

namespace Game
{
    class Map
    {
        public:
            /**
            * @brief Construct the Map object
            */
            Map();

            /**
            * @brief Construct the Map object (Copy Constructor)
            *
            * @param width Width of the map
            * @param height Height of the map
            */
            Map(const size_t &width, const size_t &height);

            /**
            * @brief Destroy the Map object
            */
            ~Map();

            /**
             * @brief Getter for map width
             *
             * @return Width of the map (size_t)
             */
            size_t getWidth(void) const;

            /**
             * @brief Getter for map heigth
             *
             * @return Heigth of the map (size_t)
             */
            size_t getHeitgh(void) const;

            /**
             * @brief Setter for map width
             *
             * @param width A const reference to an size_t
             */
            void setWidth(const size_t width) const;

            /**
             * @brief Setter for map heigth
             *
             * @param heigth A const reference to an size_t
             */
            void setHeitgh(const size_t heigth) const;

        private:
            size_t _width; // Width of the map
            size_t _height; // Height of the map
            std::vector<std::vector<char>> _map; // Map
    };

    #include "Map.inl"
}

#endif /* !MAP_HPP_ */
