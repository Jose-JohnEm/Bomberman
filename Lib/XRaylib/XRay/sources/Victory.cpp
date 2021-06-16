/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Victory
*/

#include "XRay.hpp"

void XRay::goToAnotherSceneFromVictory()
{
    // Check if mouse is on button spot
    bool home = mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? true : false;
    bool restart = mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? true : false;
    bool save = (_gameSettings[7] + _gameSettings[5] < 2) && mouseIsInBox(createBox(380, 550, 380+375, 550+65)) ? true : false;
    bool nextlevel = (_gameSettings[7] + _gameSettings[5] < 2) && mouseIsInBox(createBox(380, 660, 380+375, 660+65)) ? true : false;

    // Call function that check click on button
    if (nextlevel && Raylib::Mouse::isButtonPressed(0)) {
        // Do here all manipulations to increase level
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (restart && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (save && Raylib::Mouse::isButtonPressed(0)) {
        beginDrawing(false);
        _resources.at(SAVED)->drawTexture(650, 20);
        endDrawing();
        _pointerToSaveFunc(_gameSettings, getPlayerControls());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (home && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        resetAll();
        displayMenuScene();
    }
}

void XRay::displayVictoryScene()
{
    // Set scene
    _scene = VICTORY;

    // Draw scene
    beginDrawing();
    _resources.at(VICTORYBG)->drawTexture(0, 0);
    (mouseIsInBox(createBox(380, 330, 380+375, 330+65)) ? _resources.at(HOMEHOVER) : _resources.at(HOME))->drawTexture(380, 330);
    (mouseIsInBox(createBox(380, 440, 380+375, 440+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(380, 440);
    if (_gameSettings[7] + _gameSettings[5] < 2) {
        (mouseIsInBox(createBox(380, 550, 380+375, 550+65)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(380, 550);
        (mouseIsInBox(createBox(380, 660, 380+375, 660+65)) ? _resources.at(NEXTLEVELHOVER) : _resources.at(Resources::NEXTLEVEL))->drawTexture(380, 660);
    }
    _resources.at(RANKING)->drawTexture(1030, 350);
    displayMouse();
    endDrawing();

    // Call function that check click on button
    goToAnotherSceneFromVictory();
}