/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** RayLib
*/

#include "RayLib.hpp"

Raylib::RayLib::RayLib()
: _window(1920, 1080, "Bomberman")
{
    SetTargetFPS(60);
}

Raylib::RayLib::~RayLib()
{

}


void Raylib::RayLib::initWindow(int width, int height, const char *title)
{
//    this->_window.initWindow(width)
//  elle est initialisée à la création on verra son sort
    return;
}

bool Raylib::RayLib::shouldCloseWindow()
{
    return this->_window.windowShouldClose();
}

void Raylib::RayLib::closeWindow()
{
    this->_window.closeWindow();
}

void Raylib::RayLib::drawText(const char *text, int posX, int posY, int fontSize)
{
    this->_window.drawText(text, posX, posY, fontSize);
}

void Raylib::RayLib::beginDrawing()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Raylib::RayLib::endDrawing()
{
    EndDrawing();
}