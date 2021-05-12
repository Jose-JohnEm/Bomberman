/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"

Raylib::XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    ::SetTargetFPS(60); //TODO: use our encapsulation
}

Raylib::XRay::~XRay()
{
}