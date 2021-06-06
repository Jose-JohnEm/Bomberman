/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Defeat
*/

#include "XRay.hpp"

void XRay::goToAnotherSceneFromDefeat()
{
    // Check if mouse is on button spot
    bool home = mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? true : false;
    bool restart = mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? true : false;

    // Call function that check click on button
    if (restart && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (home && Raylib::Mouse::isButtonPressed(0))
        displayMenuScene();
}

void XRay::displayDefeatScene()
{
    // Set scene
    _scene = DEFEAT;

    // Draw scene
    beginDrawing();
    _resources.at(DEFEATBG)->drawTexture(0, 0);
    (mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? _resources.at(HOMEHOVER) : _resources.at(HOME))->drawTexture(380, 330);
    (mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(380, 440);
    _resources.at(RANKING)->drawTexture(1030, 350);
    displayMouse();
    endDrawing();

    // Call function that check click on button
    goToAnotherSceneFromDefeat();
}