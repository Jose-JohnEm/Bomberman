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

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(250, 900, 510, 965)) ? true : false;
    bool goNewGame = mouseIsInBox(createBox(180, 500, 700, 565)) ? true : false;
    bool goLoadGame = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(250, 900, 510, 965)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);
    std::shared_ptr<Raylib::Texture> newGameButton = mouseIsInBox(createBox(180, 500, 700, 565)) ? _resources.at(NEWGAME_HOVER) : _resources.at(NEWGAME);
    std::shared_ptr<Raylib::Texture> loadGameButton = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? _resources.at(LOADGAME_HOVER) : _resources.at(LOADGAME);

    // Draw scene
    beginDrawing();
    _resources.at(NEWGAME_BG)->drawTexture(0, 0, Raylib::Color::White());
    _resources.at(LOADGAME_BG)->drawTexture(960, 0, Raylib::Color::White());
    backButton->drawTexture(250, 900, Raylib::Color::White());
    newGameButton->drawTexture(180, 500, Raylib::Color::White());
    loadGameButton->drawTexture(1140, 500, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0))
    {
        _pSelector.unload();
        displayMenuScene();
    }
    else if (goNewGame && Raylib::Mouse::isButtonPressed(0))
    {
        _pSelector.load();
        displayPlayerChoiceScene();
    }
    else if (goLoadGame && Raylib::Mouse::isButtonPressed(0))
    {
        _pSelector.unload();
        displayLoadGameScene();
    }
}