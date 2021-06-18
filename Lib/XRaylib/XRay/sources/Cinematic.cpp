/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cinematic
*/

#include "XRay.hpp"
#include "../../../Engine/Exception/MyException.hpp"

void XRay::displayCinematic(const Cinematic &cinematic)
{
    switch (cinematic) {
        case INTRO:
            if (!_sfx.at(SFX_OPENNING)->isPlaying())
                _sfx.at(SFX_OPENNING)->play();
            displayCinematic(CFunctions::generatePairOfRandomIntegers(2, 1).first ? "intro1" : "intro2", 300, 1);
            if (_sfx.at(SFX_OPENNING)->isPlaying())
                _sfx.at(SFX_OPENNING)->stop();
            break;
        default:
            break;
    }
}

void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip, const size_t &gap) const
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);
    Clock clock;

    // Launch cinematic
    size_t i = 0;

//    for (size_t i = 0; i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005))) && clock.doesTimeElapsed(0.01); i++)
    while (i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005)))) {

        if (clock.doesTimeElapsed(0.001)) {
            // Set Textures
            Raylib::Texture frame(Raylib::Image("resources/cinematic/" + cinematicPathDirectory + "/frame" + std::to_string(i) + ".png"));

            // Draw cinematic
            beginDrawing();
            Raylib::Drawing::clearBackground(Raylib::Color::Black());
            frame.drawTexture(0, 0);
            if (i < hideSkip) {
                (mouseIsInBox(createBox(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP))->drawTexture(1760, 950);
                displayMouse();
            }
            if (gap > 0)
                std::this_thread::sleep_for(std::chrono::milliseconds(gap));
            endDrawing();
            i++;
        }
    }
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydisplayCinematic() {
    try
    {   XRay test;
        Cinematic cinematic;
    	test.displayCinematic(cinematic);
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}