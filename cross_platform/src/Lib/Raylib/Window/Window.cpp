/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

#include "Window.hpp"

Raylib::Window::Window(const int &width, const int &height, const std::string &title, const bool &lateInit)
    : _width{width}, _height{height}, _name{title}, _lateToInit{}
{
    initWindow(width, height, title.c_str());
}

Raylib::Window::~Window()
{
}