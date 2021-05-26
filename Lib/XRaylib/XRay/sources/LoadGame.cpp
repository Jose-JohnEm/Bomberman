/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** LoadGame
*/

#include "XRay.hpp"

void XRay::displayLoadGameScene(void)
{
    // Set scene
    _scene = LOAD_GAME;

    // Vertical axis
    size_t ordinate = 300;

    // Draw scene
    beginDrawing();
    _resources.at(LOADSCENE)->drawTexture(0, 0, Raylib::Color::White());
    Raylib::Text::drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (const std::string &backup : _backups) {
        _resources.at(BRANCH)->drawTexture(150, ordinate, Raylib::Color::White());
        Raylib::Text::drawText(backup.substr(0, backup.find('.')), 300, ordinate + 20, 65, Raylib::Color::Black());
        ordinate += 100;
    }
    endDrawing();
}