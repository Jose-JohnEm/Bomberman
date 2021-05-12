/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** RayLib
*/

#include "XRay.hpp"

Raylib::XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    SetTargetFPS(60);
}

Raylib::XRay::~XRay()
{
}

void Raylib::XRay::initWindow(int width, int height, const char *title)
{
//    this->_window.initWindow(width)
//  elle est initialisée à la création on verra son sort
    return;
}

bool Raylib::XRay::shouldCloseWindow()
{
    return this->_window.windowShouldClose();
}

void Raylib::XRay::closeWindow()
{
    this->_window.closeWindow();
}

void Raylib::XRay::drawText(const char *text, int posX, int posY, int fontSize)
{
    this->_window.drawText(text, posX, posY, fontSize);
}

void Raylib::XRay::beginDrawing()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Raylib::XRay::endDrawing()
{
    EndDrawing();
}