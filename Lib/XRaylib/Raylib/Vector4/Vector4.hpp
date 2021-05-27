/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "raylib.h"

//TODO: const &parameter
//TODO: trailing spaces

namespace Raylib
{
    class Vector4
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
            Vector4(float x, float y, float z, float w);

            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param copy Vector4 class instance
             */
            Vector4(const Vector4 &copy) = default;

            /**
             * @brief Construct a new Vector 4 object
             * 
             * @param vector Vector4 C Raylib strutcture instance
             */
            Vector4(::Vector4 vector);

            /**
             * @brief Destroy the Vector 4 object
             * 
             */
            ~Vector4();

            /**
             * @brief Assign to a Vector4 from a Vector4 class instance
             * 
             * @param copy Vector4 class instance
             * @return Vector4 
             */
            Vector4 operator=(const Vector4 &copy);

            /**
             * @brief Assign to a Vector4 from a Vector4 C Raylib structure instance
             * 
             * @param cvec Vector4 C Raylib structure instance
             * @return Vector4 
             */
            Vector4 operator=(const ::Vector4 &cvec);

            /**
             * @brief Get the Vector4 C Raylib structure instance
             * 
             * @return Vector4 C Raylib structure instance
             */
            ::Vector4 getCStruct() const;
            
            /**
            * @brief The x position
            *
            */
            float x;
            /**
            * @brief The y position
            *
            */
            float y;
            /**
            * @brief The z position
            *
            */
            float z;
            /**
            * @brief The w position
            *
            */
            float w;

        private:
            /**
            * @brief Declaration of a Vector4
            *
            */
            ::Vector4 _vector;

    };

    #include "Vector4.inl"

}

#endif