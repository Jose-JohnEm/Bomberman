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
    bool goPlay = mouseIsInBox(createBox(100, 500, 360, 565)) ? true : false;
    bool goHowToPlay = mouseIsInBox(createBox(100, 600, 815, 665)) ? true : false;
    bool goSettings = mouseIsInBox(createBox(100, 700, 620, 765)) ? true : false;
    bool quit = mouseIsInBox(createBox(100, 800, 360, 865)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> playButton = mouseIsInBox(createBox(100, 500, 360, 565)) ? _resources.at(PLAY_HOVER) : _resources.at(PLAY);
    std::shared_ptr<Raylib::Texture> howToPlayButton = mouseIsInBox(createBox(100, 600, 815, 665)) ? _resources.at(HOW_TO_PLAY_HOVER) : _resources.at(Resources::HOW_TO_PLAY);
    std::shared_ptr<Raylib::Texture> settingsButton = mouseIsInBox(createBox(100, 700, 620, 765)) ? _resources.at(SETTINGS_HOVER) : _resources.at(Resources::SETTINGS);
    std::shared_ptr<Raylib::Texture> quitButton = mouseIsInBox(createBox(100, 800, 360, 865)) ? _resources.at(QUIT_HOVER) : _resources.at(QUIT);

    // Hide the cursor
    if (Raylib::Cursor::isCursorOnScreen())
        Raylib::Cursor::hideCursor();

    // Draw scene
    beginDrawing();
    _resources.at(MENU_TITLE)->drawTexture(1920 / 4 + 100, 40, Raylib::Color::White());
    _resources.at(BOMBER_THINKING)->drawTexture(1920 / 4 - 80, 130, Raylib::Color::White());
    _resources.at(BOMBER_TEAM)->drawTexture(1420, 600, Raylib::Color::White());
    playButton->drawTexture(100, 500, Raylib::Color::White());
    howToPlayButton->drawTexture(100, 600, Raylib::Color::White());
    settingsButton->drawTexture(100, 700, Raylib::Color::White());
    quitButton->drawTexture(100, 800, Raylib::Color::White());
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