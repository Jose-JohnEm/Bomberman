/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector3.cpp
*/

#include "Vector3.hpp"

Raylib::Vector3::Vector3(float x, float y, float z)
: _vector({x, y, z})
{

}

Raylib::Vector3::Vector3(::Vector3 cVec)
: _vector(cVec)
{

}

Raylib::Vector3::~Vector3()
{
    
}