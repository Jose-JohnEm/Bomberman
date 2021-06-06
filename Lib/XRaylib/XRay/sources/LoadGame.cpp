/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** LoadGame
*/

#include "XRay.hpp"

void XRay::loadThisBackup(const std::string &_pathToBackupFile)
{
    // Add deserialization and loading of data
    // hereeeee (je suis gentil d'où je mets ça ... :/ c'est évident !!! Allez hop hop !!)

    displayCinematic("loading", 0, 0);
    displayInGameScene();
}

void XRay::displayLoadGameScene(void)
{
    // Set scene
    _scene = LOAD_GAME;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;

    // Vertical axis
    size_t ordinate = 300;

    // Draw scene
    beginDrawing();
    _resources.at(LOADSCENE)->drawTexture(0, 0);
    Raylib::Text::drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (const std::string &backup : _backups) {
        if (mouseIsInBox(createBox(300, ordinate + 20, 300+(65 * backup.substr(0, backup.find('.')).length()), ordinate + 85)))
            _resources.at(BACKUPBAR)->drawTexture(295, ordinate + 10);
        if (mouseIsInBox(createBox(300, ordinate + 20, 300+(65 * backup.substr(0, backup.find('.')).length()), ordinate + 85)) && Raylib::Mouse::isButtonPressed(0)) {
            loadThisBackup(backup);
            return ;
        }
        _resources.at(BRANCH)->drawTexture(150, ordinate);
        Raylib::Text::drawText(backup.substr(0, backup.find('.')), 300, ordinate + 20, 65, Raylib::Color::Black());
        ordinate += 100;
    }
    (mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        (this->*_scenesBack[_scene])();
        _scenesBack[LOAD_GAME] = _scenesBackBackup[LOAD_GAME];
    }
}