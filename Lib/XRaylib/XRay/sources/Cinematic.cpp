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
<<<<<<< HEAD
        displayCinematic("intro", 300);
=======
        displayCinematic("intro", 300, 0);
>>>>>>> release/v0.3
        break;
    default:
        break;
    }
}

<<<<<<< HEAD
void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip) const
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);

    // Hide the cursor
    if (Raylib::Cursor::isCursorOnScreen())
        Raylib::Cursor::hideCursor();

=======
void XRay::displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip, const size_t &gap) const
{
    size_t filesNumber = countFilesDirectory("resources/cinematic/" + cinematicPathDirectory);

>>>>>>> release/v0.3
    // Launch cinematic
    for (size_t i = 0; i < filesNumber && !(i < hideSkip && Raylib::Mouse::isButtonPressed(0) && mouseIsInBox(createBox(1760, 950, 1883, 1005))); i++)
    {
        // Set Textures
<<<<<<< HEAD
        std::shared_ptr<Raylib::Texture> skipButton = mouseIsInBox(createBox(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP);
=======
>>>>>>> release/v0.3
        Raylib::Texture frame(Raylib::Image("resources/cinematic/" + cinematicPathDirectory + "/frame" + std::to_string(i) + ".png"));

        // Draw cinematic
        beginDrawing();
<<<<<<< HEAD
        frame.drawTexture(0, 0, Raylib::Color::White());
        if (i < hideSkip)
            skipButton->drawTexture(1760, 950, Raylib::Color::White());
        displayMouse();
=======
        frame.drawTexture(0, 0);
        if (i < hideSkip) {
            (mouseIsInBox(createBox(1760, 950, 1883, 1005)) ? _resources.at(SKIP_HOVER) : _resources.at(SKIP))->drawTexture(1760, 950);
            displayMouse();
        }
        if (gap > 0)
        	std::this_thread::sleep_for(std::chrono::milliseconds(gap));
>>>>>>> release/v0.3
        endDrawing();
    }
}
