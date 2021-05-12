/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    std::shared_ptr<IGraphical> lib(new Raylib::RayLib());
    _graphical.swap(lib);
    _graphical->initWindow(1920, 1080, "Bonberman");
}

Core::~Core()
{
}

int Core::run()
{
    while (!_graphical->shouldCloseWindow()) {
        _graphical->beginDrawing();
        _graphical->drawText("Congrats ! Our first Window", 190, 200, 50);
        _graphical->endDrawing();
    }
    _graphical->closeWindow();

    return 0;
}