/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Raylib::Rectangle::Rectangle(float x, float y, float width, float height)
{
    ::Rectangle _rectangle = {x, y, width, height};
}

//FIXME:Raylib::Rectangle::Rectangle(::Vector2 position, ::Vector2 size)
//FIXME:{
//FIXME:    ::Rectangle _rectangle = {position.x, position.y, size.x, size.y};
//FIXME:}
//FIXME:
//FIXME:Raylib::Rectangle::Rectangle(::Vector2 size)
//FIXME:{
//FIXME:    ::Rectangle _rectangle = {0, 0, size.x, size.y};
//FIXME:}
//FIXME:
//FIXME:Raylib::Rectangle::Rectangle(::Rectangle rec)
//FIXME:: _rectangle(rec)
//FIXME:{
//FIXME:
//FIXME:}

Raylib::Rectangle::~Rectangle()
{
}