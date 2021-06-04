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
    bool onFullscreen = mouseIsInBox(createBox(1500, 200, 1725, 258)) ? true : false;

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);

    /// Draw scene
    beginDrawing();

    //Background
    _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());

    // Fullscreen
    fullscreenButton->drawTexture(1500, 200, Raylib::Color::White());
    Raylib::Text::drawText("Fullscreen :", 1200, 205, 48, Raylib::Color::Red());

    // Back button
    (mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0))
        displayMenuScene();
    // Fullscreen bouton handling
    if (onFullscreen && Raylib::Mouse::isButtonPressed(0))
        Raylib::Window::toggleFullscreen();
}