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

    // Audio
    _musics.at(MSC_BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool onFullscreen = mouseIsInBox(createBox(1500, 200, 1725, 258)) ? true : false;
    bool onVolumeUp = mouseIsInBox(createBox(1700, 300, 1764, 364)) ? true : false;
    bool onVolumeDown = mouseIsInBox(createBox(1500, 300, 1564, 364)) ? true : false;

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);

    /// Draw scene
    beginDrawing();

    // Background
    _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());

    // Fullscreen
    fullscreenButton->drawTexture(1500, 200, Raylib::Color::White());
    Raylib::Text::drawText("Fullscreen :", 1200, 205, 48, Raylib::Color::Red());

    // Master Volume
    _resources.at(VOLUME_DOWN)->drawTexture(1500, 300, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)masterVolume), 1600, 305, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1700, 300, Raylib::Color::White());

    // Back button
    (mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[SETTINGS] = _scenesBackBackup[SETTINGS];
    }
    // Fullscreen bouton handling
    if (onFullscreen && Raylib::Mouse::isButtonPressed(0))
        Raylib::Window::toggleFullscreen();

    // Volume click action
    if (onVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        masterVolume -= 10;
        if (masterVolume < 0)
            masterVolume = 0;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }
    if (onVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        masterVolume += 10;
        if (masterVolume > 100)
            masterVolume = 100;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }
}