/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "raylib.h"

//TODO: const &parameter
//TODO: trailing spaces

namespace Raylib
{
    class Vector2
    {
        public:


            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param x x coordinate
             * @param y y coordinate
             * @param z z coordinate
             * @param w w coordinate
             */
            Vector2(float x, float y);

            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param copy Vector2 class instance
             */
            Vector2(const Vector2 &copy) = default;

            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param vector Vector2 C Raylib strutcture instance
             */
            Vector2(::Vector2 vector);

            /**
             * @brief Destroy the Vector 2 object
             * 
             */
            ~Vector2();

            /**
             * @brief Assign to a Vector2 from a Vector2 class instance
             * 
             * @param copy Vector2 class instance
             * @return Vector2 
             */
            Vector2 operator=(const Vector2 &copy);

            /**
             * @brief Assign to a Vector2 from a Vector2 C Raylib structure instance
             * 
             * @param cvec Vector2 C Raylib structure instance
             * @return Vector2 
             */
            Vector2 operator=(const ::Vector2 &cvec);

            /**
             * @brief Get the Vector2 C Raylib structure instance
             * 
             * @return Vector2 C Raylib structure instance
             */
            ::Vector2 getCStruct();
            
            float x; //TODO: doc
            float y;//TODO: doc

        private:
            ::Vector2 _vector;//TODO: doc

    };

    #include "Vector2.inl"

}

#endif