/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Camera3D
*/

#include "Camera3D.hpp"

<<<<<<< HEAD
Raylib::Camera3D::Camera3D()
{
}

Raylib::Camera3D::Camera3D(const ::Camera3D &camera3D) {
=======
Raylib::Camera3D::Camera3D(const Vector3 &position, const Vector3 &target, const Vector3 &up, const float &fovy, const int &projection)
: _camera3D({position.getCStruct(), target.getCStruct(), up.getCStruct(), fovy, projection})
{
    
}

Raylib::Camera3D::Camera3D(const ::Camera3D &camera3D)
{
>>>>>>> release/v0.3
    set(camera3D);
}

Raylib::Camera3D::~Camera3D()
{
}
