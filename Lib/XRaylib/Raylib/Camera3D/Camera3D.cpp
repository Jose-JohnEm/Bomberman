/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera3D
*/

#include "Camera3D.hpp"

Raylib::Camera3D::Camera3D()
{
}

Raylib::Camera3D::Camera3D(const ::Camera3D &camera3D) {
    set(camera3D);
}

Raylib::Camera3D::~Camera3D()
{
}
