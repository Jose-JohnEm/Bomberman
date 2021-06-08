/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map Choice Scene
** ///// Credit
** @by PrinceIsGod aka CMasterp
*/

#include "XRay.hpp"

void XRay::displayGameSettings(void)
{
    _resources.at(PREVIOUS)->drawTexture(10, 400);
    _resources.at(NEXT)->drawTexture(910, 400);

    (mouseIsInBox(createBox(1160, 245, 1160+755, 245+83)) ? _resources.at(SIZE_HOVER) : _resources.at(SIZE))->drawTexture(1160, 245);
    (mouseIsInBox(createBox(1160, 455, 1160+755, 455+83)) ? _resources.at(SETS_HOVER) : _resources.at(Resources::SETS))->drawTexture(1160, 455);
    (mouseIsInBox(createBox(1160, 665, 1160+755, 665+83)) ? _resources.at(DURATION_HOVER) : _resources.at(Resources::DURATION))->drawTexture(1160, 665);
    (mouseIsInBox(createBox(1160, 875, 1160+755, 875+83)) ? _resources.at(AI_HOVER) : _resources.at(Resources::IA))->drawTexture(1160, 875);

    if (Raylib::Mouse::isButtonPressed(0))
    {
        if (mouseIsInBox(createBox(10, 400, 160, 550)))
            _pSelector.prevMap();
        if (mouseIsInBox(createBox(900, 400, 1050, 550)))
            _pSelector.nextMap();
    }
}

void XRay::displayMapChoiceScene(void)
{
    // Set scene
    _scene = MAP_CHOICE;

    // Audio
    _musics.at(BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox(1700, 1000, 1918, 1061)) ? true : false;

    // Draw scene
    beginDrawing();
    displayBack();

    displayGameSettings();
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    (goNext ? _resources.at(NEXT_HOVER) : _resources.at(NEXTSCENE))->drawTexture(1700, 1000);

    _pSelector.drawMaps();
    displayMouse();

    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        (this->*_scenesBack[_scene])();
        _scenesBack[MAP_CHOICE] = _scenesBackBackup[MAP_CHOICE];
        _pSelector.endMaps();
    }
    if (goNext && Raylib::Mouse::isButtonPressed(0)) {
        displayCinematic("loading", 0, 0);
        displayInGameScene();
        _pSelector.endMaps();
    }
}
