/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** LoadGame
*/

#include "XRay.hpp"

void XRay::loadThisBackup(const std::string &_pathToBackupFile)
{
    _pointerToLoadFunc(_pathToBackupFile);
    displayCinematic("loading", 0, 0);
    _scene = IN_GAME;
}

void XRay::displayLoadGameScene(void)
{
    // Set scene
    _scene = LOAD_GAME;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Vertical axis
    size_t ordinate = 300;
    size_t u = 0;

    // Draw scene
    beginDrawing();
    _resources.at(LOADSCENE)->drawTexture(0, 0);
    Raylib::Text::drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (; u < _backups.size(); u++) {
        if (mouseIsInBox(createBox(300, ordinate + 20, 1100, ordinate + 85)))
            _resources.at(BACKUPBAR)->drawTexture(295, ordinate + 10);
        _resources.at(BRANCH)->drawTexture(150, ordinate);
        Raylib::Text::drawText(_backups[u].substr(0, _backups[u].find('.')), 300, ordinate + 20, 65, Raylib::Color::Black());
        ordinate += 100;
    }
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    displayMouse();
    endDrawing();

    for (u = 0, ordinate = 300; u < _backups.size(); u++, ordinate += 100)
        if (Raylib::Mouse::isButtonDown(0) && mouseIsInBox(createBox(300, ordinate + 20, 1100, ordinate + 85)))
            loadThisBackup(_backups[u]);
    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[LOAD_GAME] = _scenesBackBackup[LOAD_GAME];
    }
}