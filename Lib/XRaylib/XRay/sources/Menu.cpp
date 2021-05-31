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

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> playButton = mouseIsInBox(createBox(1160, 245, 1160+755, 245+132)) ? _resources.at(PLAY_HOVER) : _resources.at(PLAY);
    std::shared_ptr<Raylib::Texture> howToPlayButton = mouseIsInBox(createBox(1160, 455, 1160+755, 455+132)) ? _resources.at(HELP_HOVER) : _resources.at(Resources::HELP);
    std::shared_ptr<Raylib::Texture> settingsButton = mouseIsInBox(createBox(1160, 665, 1160+755, 665+132)) ? _resources.at(SETTINGS_HOVER) : _resources.at(Resources::SETTINGS);
    std::shared_ptr<Raylib::Texture> quitButton = mouseIsInBox(createBox(1160, 875, 1160+755, 875+132)) ? _resources.at(QUIT_HOVER) : _resources.at(QUIT);

    // Hide the cursor
    if (Raylib::Cursor::isCursorOnScreen())
        Raylib::Cursor::hideCursor();

    // Display INDIE STUDIO
    if (_intro.first == true)
        (this->*_intro.second)();

    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= -_resources.at(PARALLAX)->getCStruct().width/2) _scrollingBack = 0;

    // Draw scene
    beginDrawing();
    _resources.at(PARALLAX)->drawTextureEx(*_resources.at(PARALLAX).get(), *(new Raylib::Vector2(_scrollingBack, 0)), 0.0f, 1.0f, Raylib::Color::White());
    _resources.at(PARALLAX)->drawTextureEx(*_resources.at(PARALLAX).get(), *(new Raylib::Vector2(_resources.at(PARALLAX)->getCStruct().width + _scrollingBack, 0)), 0.0f, 1.0f, Raylib::Color::White());

    playButton->drawTexture(1160, 245, Raylib::Color::White());
    howToPlayButton->drawTexture(1160, 455, Raylib::Color::White());
    settingsButton->drawTexture(1160, 665, Raylib::Color::White());
    quitButton->drawTexture(1160, 875, Raylib::Color::White());

    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goPlay && Raylib::Mouse::isButtonPressed(0))
        displayGameModeScene();
    else if (goHowToPlay && Raylib::Mouse::isButtonPressed(0))
        displayHowToPlayScene();
    else if (goSettings && Raylib::Mouse::isButtonPressed(0))
        displaySettingsScene();
    else if (quit && Raylib::Mouse::isButtonPressed(0))
        quitGame();
}