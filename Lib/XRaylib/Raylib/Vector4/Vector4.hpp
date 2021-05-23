/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.hpp
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "raylib.h"

namespace Raylib
{
    class Vector4
    {
        public:

            Vector4(float x, float y, float z, float w);
            Vector4(const Vector4 &copy) = default;
            Vector4(::Vector4 vector);
            ~Vector4();

            Vector4 operator=(const Vector4 &copy);
            Vector4 operator=(const ::Vector4 &cvec);

            ::Vector4 getCStruct();
            
            float x;
            float y;
            float z;
            float w;

        private:
            ::Vector4 _vector;

    };

    #include "Vector4.inl"

}

#endif