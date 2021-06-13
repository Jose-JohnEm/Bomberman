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
    size_t iaOrNot = 0;
    _resources.at(PREVIOUS)->drawTexture(10, 400);
    _resources.at(NEXT)->drawTexture(910, 400);

    (mouseIsInBox(createBox(1160, 245, 1160+755, 245+83)) ? _resources.at(SIZE_HOVER) : _resources.at(SIZE))->drawTexture(1160, 245);
    (mouseIsInBox(createBox(1160, 455, 1160+755, 455+83)) ? _resources.at(SETS_HOVER) : _resources.at(Resources::SETS))->drawTexture(1160, 455);
    (mouseIsInBox(createBox(1160, 665, 1160+755, 665+83)) ? _resources.at(DURATION_HOVER) : _resources.at(Resources::DURATION))->drawTexture(1160, 665);
    _resources.at((Resources)((int)S7X7S + ((_sizeMap > 6 && _sizeMap < 20) ? (_sizeMap-7) / 2 : 0)))->drawTexture(1645, 260);
    _resources.at((Resources)((int)SET1SET + ((_sets > 0 && _sets < 6) ? _sets-1 : 0)))->drawTexture(1730, 465);
    _resources.at((Resources)((int)MIN1MIN + ((_duration > 0 && _duration < 6) ? _duration-1 : 0)))->drawTexture(1665, 675);
    for (size_t t = 0; t < _allIntegers[2] && t <_playerTab.size(); t++)
        iaOrNot += (!_playerTab[t]) ? 1 : 0;
    if (iaOrNot > 0) {
        (mouseIsInBox(createBox(1160, 875, 1160+755, 875+83)) ? _resources.at(AI_HOVER) : _resources.at(Resources::IA))->drawTexture(1160, 875);
        _resources.at((Resources)((int)EASY + ((_aiLevel > 0 && _aiLevel < 4) ? _aiLevel-1 : 0)))->drawTexture(1660, 898);
    }
}

void XRay::checkClickOnMapChoiceScene(void)
{
    // Click on Next and Prev buttons
    for (size_t y = 245; y <= 875; y += 210) {
        if (mouseIsInBox(createBox(1610, y+7, 1650, y+7+70))) {
            _sizeMap = (y == 245) ? ((_sizeMap > 7) ? _sizeMap-2 : 19) : _sizeMap;
            _sets = (y == 455) ? ((_sets > 1) ? _sets-1 : 5) : _sets;
            _duration = (y == 665) ? ((_duration > 1) ? _duration-1 : 5) : _duration;
            _aiLevel = (y == 875) ? ((_aiLevel > 1) ? _aiLevel-1 : 3) : _aiLevel;
        } else if (mouseIsInBox(createBox(1880, y+7, 1920, y+7+70))) {
            _sizeMap = (y == 245) ? ((_sizeMap < 19) ? _sizeMap+2 : 7) : _sizeMap;
            _sets = (y == 455) ? ((_sets < 5) ? _sets+1 : 1) : _sets;
            _duration = (y == 665) ? ((_duration < 5) ? _duration+1 : 1) : _duration;
            _aiLevel = (y == 875) ? ((_aiLevel < 3) ? _aiLevel+1 : 1) : _aiLevel;
        }
    }
}

void XRay::displayMapChoiceScene(void)
{
    // Set scene
    _scene = MAP_CHOICE;

    // Audio
    _musics.at(MSC_BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox(1700, 1000, 1918, 1061)) ? true : false;
    bool tmp = false;

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
        _sfx.at(SFX_HOME)->play();
        _pSelector.endMaps();
        (this->*_scenesBack[_scene])();
        _scenesBack[MAP_CHOICE] = _scenesBackBackup[MAP_CHOICE];
    }
    if (goNext && Raylib::Mouse::isButtonPressed(0)) {
        _mapType = _pSelector.getMapType();
        _scene = IN_GAME;
        beginDrawing(false);
        _resources.at(LOADINGFRAMEO)->drawTexture(0, 0);
        endDrawing();
        _pSelector.endMaps();
    }
    if (Raylib::Mouse::isButtonPressed(0)) {
        if (mouseIsInBox(createBox(10, 400, 160, 550)))
            _pSelector.prevMap();
        if (mouseIsInBox(createBox(900, 400, 1050, 550)))
            _pSelector.nextMap();
        checkClickOnMapChoiceScene();
    }
}
