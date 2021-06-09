/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GameMode
*/

#include "XRay.hpp"

void XRay::displayGameModeScene(void)
{
    // Set scene
    _scene = GAME_MODE;

    // Audio
    _musics.at(MSC_BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool goNewGame = mouseIsInBox(createBox(180, 500, 738+180, 500+109)) ? true : false;
    bool goLoadGame = mouseIsInBox(createBox(1140, 500, 1140+738, 500+109)) ? true : false;

    // Draw scene
    beginDrawing();
    if (Raylib::Mouse::getMouseX() < 960)
        _resources.at(NEWGAME_BG)->drawTexture(0, 0);
    else
        _resources.at(LOADGAME_BG)->drawTexture(0, 0);
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    (goNewGame ? _resources.at(NEWGAME_HOVER) : _resources.at(NEWGAME))->drawTexture(180, 500);
    (goLoadGame ? _resources.at(LOADGAME_HOVER) : _resources.at(LOADGAME))->drawTexture(1140, 500);
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[GAME_MODE] = _scenesBackBackup[GAME_MODE];
    }
    else if (goNewGame && Raylib::Mouse::isButtonPressed(0))
    {
        _pSelector.firstLoad();
        displayPlayerChoiceScene();
    }
    else if (goLoadGame && Raylib::Mouse::isButtonPressed(0))
    {
        displayLoadGameScene();
    }
}