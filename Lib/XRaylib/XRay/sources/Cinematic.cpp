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
        displayCinematic("intro", 300, 0);
        break;
    default:
        break;
    }
}

void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip, const size_t &gap) const
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);

    if (!_musics.at(MSC_OPENNING)->isPlaying()) {
        std::thread tMusic(&XRay::playAndUpdateMusic, this, MSC_OPENNING);
        tMusic.detach();
    }

    // Launch cinematic
    for (size_t i = 0; i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005))); i++)
    {
        // Set Textures
        Raylib::Texture frame(Raylib::Image("resources/cinematic/" + cinematicPathDirectory + "/frame" + std::to_string(i) + ".png"));

        // Draw cinematic
        beginDrawing();
        frame.drawTexture(0, 0);
        if (i < hideSkip) {
            (mouseIsInBox(createBox(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP))->drawTexture(1760, 950);
            displayMouse();
        }
        if (gap > 0)
        	std::this_thread::sleep_for(std::chrono::milliseconds(gap));
        endDrawing();
    }

    _musics.at(MSC_OPENNING)->stop();
}
