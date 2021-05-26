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
        displayIntroCinematic();
        break;
    default:
        break;
    }
}

void XRay::displayIntroCinematic(void)
{
    std::string path, skip, str = "1";

    for (int i = 1; str != "2326" && !(i < 2300 && _mouse.isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005)));) {
        path = "resources/cinematic/data/frame" + str + ".png";
        skip = std::string("resources/assets/") + std::string((mouseIsInBox(createBox(1760, 950, 1883, 1005))) ? "sskip.png" : "skip.png");
        Raylib::Texture frame(Raylib::Image(path.c_str()));
        Raylib::Texture skipButton(Raylib::Image(skip.c_str()));

        beginDrawing();
        frame.drawTexture(0, 0, Raylib::Color::White());
        if (i < 2300)
            skipButton.drawTexture(1760, 950, Raylib::Color::White());
        endDrawing();

        i++;
        str = std::to_string(i);
    }
}
