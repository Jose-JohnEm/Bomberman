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

<<<<<<< HEAD
    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);

    // Draw scene
    beginDrawing();
    backButton->drawTexture(20, 1000, Raylib::Color::White());
=======
    // Audio
    _musics.at(MSC_BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Draw scene
    beginDrawing();
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
>>>>>>> release/v0.3
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
<<<<<<< HEAD
    if (goBack && Raylib::Mouse::isButtonPressed(0))
        displayMenuScene();
=======
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[HELP] = _scenesBackBackup[HELP];
    }
>>>>>>> release/v0.3
}