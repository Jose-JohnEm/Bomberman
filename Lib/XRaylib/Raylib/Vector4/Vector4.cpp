/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector4.cpp
*/

#include "Vector4.hpp"

Raylib::Vector4::Vector4(float x, float y, float z, float w)
: _vector({x, y, z, w})
{
}

Raylib::Vector4::Vector4(::Vector4 cVec)
: _vector(cVec)
{
}

Raylib::Vector4::~Vector4()
{
}