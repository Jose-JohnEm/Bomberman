/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "raylib.h"

namespace Raylib
{
    class Vector3
    {
        public:

            Vector3(float x, float y, float z);
            Vector3(const Vector3 &copy) = default;
            Vector3(::Vector3 vector);
            ~Vector3();

            Vector3 operator=(const Vector3 &copy);
            Vector3 operator=(const ::Vector3 &cvec);

            ::Vector3 getCStruct();
            
            float x;
            float y;
            float z;

        private:
            ::Vector3 _vector;

    };

    #include "Vector3.inl"

}

#endif