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

    // Audio
    _musics.at(BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Draw scene
    beginDrawing();
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        (this->*_scenesBack[_scene])();
        _scenesBack[HELP] = _scenesBackBackup[HELP];
    }
}