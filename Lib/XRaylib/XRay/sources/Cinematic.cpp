/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cinematic
*/

#include "XRay.hpp"

void XRay::displayCinematic(const Cinematic &cinematic)
{
    switch (cinematic)
    {
    case INTRO:
        displayCinematic("intro", 300);
        break;
    default:
        break;
    }
}

void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip) const
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);

    // Launch cinematic
    for (size_t i = 0; i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005))); i++)
    {
        // Set Textures
        Raylib::Texture frame(Raylib::Image("resources/cinematic/" + cinematicPathDirectory + "/frame" + std::to_string(i) + ".png"));

        // Draw cinematic
        beginDrawing();
        frame.drawTexture(0, 0, Raylib::Color::White());
        if (i < hideSkip)
            (mouseIsInBox(createBox(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP))->drawTexture(1760, 950, Raylib::Color::White());
        displayMouse();
        endDrawing();
    }
}
