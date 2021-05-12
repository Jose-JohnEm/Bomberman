/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

#include "Window/Window.hpp"

Raylib::Window::Window(const int &width, const int &height, const std::string &title, bool lateInit)
: _width(width), _height(height), _name(title), _lateToInit()
{
    InitWindow(width, height, title.c_str());
}

Raylib::Window::~Window()
{

}

void Raylib::Window::initWindow(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

bool Raylib::Window::windowShouldClose(void)
{
    return (WindowShouldClose());
}

void Raylib::Window::closeWindow(void)
{
    CloseWindow();
}

void Raylib::Window::drawText(const char *text, int posX, int posY, int fontSize)
{
    DrawText(text, posX, posY, fontSize, GOLD);
}