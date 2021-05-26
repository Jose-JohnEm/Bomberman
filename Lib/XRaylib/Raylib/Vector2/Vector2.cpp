/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.cpp
*/

#include "Vector2.hpp"

Raylib::Vector2::Vector2(float x, float y)
: _vector({x, y})
{
}

Raylib::Vector2::Vector2(::Vector2 cVec)
: _vector(cVec)
{
}

Raylib::Vector2::~Vector2()
{
}