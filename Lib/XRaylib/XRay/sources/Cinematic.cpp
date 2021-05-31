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

void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip) const//TODO: To change ? (Lucas (Prince) J'ai diminué la cinématique)
{
    std::string path, skip, str = "1";

    // Hide the cursor
    if (Raylib::Cursor::isCursorOnScreen())
        Raylib::Cursor::hideCursor();

    for (int i = 1; str != "357" && !(i < 300 && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005)));) {
        path = "resources/cinematic/intro/frame" + str + ".png";
        skip = std::string("resources/assets/") + std::string((mouseIsInBox(createBox(1760, 950, 1883, 1005))) ? "skipHover.png" : "skip.png");
        Raylib::Texture frame(Raylib::Image(path.c_str()));
        Raylib::Texture skipButton(Raylib::Image(skip.c_str()));

        beginDrawing();
        frame.drawTexture(0, 0, Raylib::Color::White());
        if (i < 300)
            skipButton.drawTexture(1760, 950, Raylib::Color::White());
        displayMouse();
        endDrawing();

        i++;
        str = std::to_string(i);
    }
}
