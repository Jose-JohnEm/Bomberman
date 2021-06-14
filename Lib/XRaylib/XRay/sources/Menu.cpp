/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Menu
*/

#include "XRay.hpp"

void XRay::displayMenuScene(void)
{
    // Set scene
    _scene = MENU;

    // Check if mouse is on button spot
    bool goPlay = mouseIsInBox(createBox(1160, 245, 1160+755, 245+132)) ? true : false;
    bool goHowToPlay = mouseIsInBox(createBox(1160, 455, 1160+755, 455+132)) ? true : false;
    bool goSettings = mouseIsInBox(createBox(1160, 665, 1160+755, 665+132)) ? true : false;
    bool quit = mouseIsInBox(createBox(1160, 875, 1160+755, 875+132)) ? true : false;

    // Display INDIE STUDIO
    if (_intro.first == true)
        (this->*_intro.second)();

    // Music
    if (!_musics.at(MSC_BOMBERMAN)->isPlaying()) {
        std::thread tMusic(&XRay::playAndUpdateMusic, this, MSC_BOMBERMAN);
        tMusic.detach();
    }

    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= -_resources.at(PARALLAX)->getCStruct().width/2) _scrollingBack = 0;

    // Draw scene
    beginDrawing();
    _resources.at(PARALLAX)->drawTexture(_scrollingBack, 0, 0.0f, 1.0f);
    _resources.at(PARALLAX)->drawTexture(_resources.at(PARALLAX)->getCStruct().width + _scrollingBack, 0, 0.0f, 1.0f);

    (goPlay ? _resources.at(PLAY_HOVER) : _resources.at(PLAY))->drawTexture(1160, 245);
    (goHowToPlay ? _resources.at(HELP_HOVER) : _resources.at(Resources::HELP))->drawTexture(1160, 455);
    (goSettings ? _resources.at(SETTINGS_HOVER) : _resources.at(Resources::SETTINGS))->drawTexture(1160, 665);
    (quit ? _resources.at(QUIT_HOVER) : _resources.at(QUIT))->drawTexture(1160, 875);

    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goPlay && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        displayGameModeScene();
    } else if (goHowToPlay && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        displayHowToPlayScene();
    } else if (goSettings && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_SETTING)->play();
        displaySettingsScene();
    } else if (quit && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_ENTER)->play();
        quitGame();
    }
}