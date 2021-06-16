/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** HowToPlay
*/

#include "XRay.hpp"

void XRay::displayHowToPlayScene(void)
{
    // Set scene
    _scene = HELP;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Draw scene
    beginDrawing();

    //Background
    _resources.at(HOWTO_BG)->drawTexture(0, 0, Raylib::Color::White());

    _resources.at(PREVIOUS)->drawTexture(50, 500);
    _resources.at(NEXT)->drawTexture(1754, 500);

    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[HELP] = _scenesBackBackup[HELP];
    }
}