/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Matrix.cpp
*/

#include "Matrix/Matrix.hpp"

Raylib::Matrix::Matrix(float m0 = 0, float m1 = 0, float m2 = 0, float m3 = 0, float m4 = 0, float m5 = 0, float m6 = 0, float m7 = 0, float m8 = 0, float m9 = 0, float m10 = 0, float m11 = 0, float m12 = 0, float m13 = 0, float m14 = 0, float m15 = 0)
: _matrix({m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15})
{

}

Raylib::Matrix::Matrix(::Matrix matrix)
: _matrix(matrix)
{
}

Raylib::Matrix::Matrix(Camera3D cam)
: _matrix(::GetCameraMatrix(cam.getCStruct()))
{

}

Raylib::Matrix::Matrix(::Camera3D cam)
: _matrix(::GetCameraMatrix(cam))
{
}

Raylib::Matrix::Matrix(Camera2D cam)
: _matrix(::GetCameraMatrix2D(cam.getCStruct()))
{
}

Raylib::Matrix::Matrix(::Camera2D cam)
: _matrix(::GetCameraMatrix2D(cam))
{
}

Raylib::Matrix::~Matrix()
{

}