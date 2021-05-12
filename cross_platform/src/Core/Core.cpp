/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    std::shared_ptr<IGraphical> lib = std::make_shared<Raylib::XRay>();

    _graphical = std::move(lib);
    _graphical->initWindow(1920, 1080, "Bomberman");
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
    return EXIT_SUCCESS;
}