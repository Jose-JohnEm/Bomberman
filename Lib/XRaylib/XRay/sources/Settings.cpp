/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Settings
*/

#include "XRay.hpp"

void XRay::displaySettingsScene(void)
{
    // Set scene
    _scene = SETTINGS;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool clickFullscreen = mouseIsInBox(createBox(1500, 200, 1725, 258)) ? true : false;
    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);
//    Raylib::Text::drawText();

    // Draw scene
    beginDrawing();
    _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());
    backButton->drawTexture(20, 1000, Raylib::Color::White());
    fullscreenButton->drawTexture(1500, 200, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0))
        displayMenuScene();
    // Fullscreen bouton handling
    if (clickFullscreen && Raylib::Mouse::isButtonPressed(0))
        Raylib::Window::toggleFullscreen();
}