/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "raylib.h"

namespace Raylib
{
    class Vector2
    {
        public:

            Vector2(float x, float y);
            Vector2(const Vector2 &copy) = default;
            Vector2(::Vector2 vector);
            ~Vector2();

            Vector2 operator=(const Vector2 &copy);
            Vector2 operator=(const ::Vector2 &cvec);

            ::Vector2 getCStruct();
            
            float x;
            float y;

        private:
            ::Vector2 _vector;

    };

    #include "Vector2.inl"

}

#endif