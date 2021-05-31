/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Raylib::Rectangle::Rectangle(float x, float y, float width, float height)
: _rectangle({x, y, width, height})
{

}

Raylib::Rectangle::Rectangle(const Vector2 &position, const Vector2 &size)
: _rectangle({position.x, position.y, size.x, size.y})
{

}

Raylib::Rectangle::Rectangle(const Vector2 &size)
: _rectangle({0, 0, size.x, size.y})
{

}

Raylib::Rectangle::Rectangle(::Rectangle rec)
: _rectangle(rec)
{

}

Raylib::Rectangle::~Rectangle()
{

}