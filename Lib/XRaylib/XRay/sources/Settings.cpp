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
    bool onFullscreen = mouseIsInBox(createBox(1200, 210, 1425, 268)) ? true : false;
    bool onMasterVolumeDown = mouseIsInBox(createBox(1185, 300, 1249, 364)) ? true : false;
    bool onMasterVolumeUp = mouseIsInBox(createBox(1390, 300, 1454, 364)) ? true : false;
    bool onMusicVolumeDown = mouseIsInBox(createBox(1185, 390, 1249, 454)) ? true : false;
    bool onMusicVolumeUp = mouseIsInBox(createBox(1390, 390, 1764, 454)) ? true : false;
    bool onSfxVolumeDown = mouseIsInBox(createBox(1185, 475, 1249, 539)) ? true : false;
    bool onSfxVolumeUp = mouseIsInBox(createBox(1390, 475, 1764, 539)) ? true : false;
    bool onMods = mouseIsInBox(createBox(1200, 600, 1425, 658)) ? true : false;

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);
    std::shared_ptr<Raylib::Texture> modsButton = _resources.at(_pSelector.isModsAvailable() ? ON : OFF);

    /// Draw scene
    beginDrawing();

    // Background
    _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());

    // Fullscreen
    Raylib::Text::drawText("Fullscreen :", 765, 210, 48, Raylib::Color::Yellow());
    fullscreenButton->drawTexture(1200, 210, Raylib::Color::White());

    // Master Volume
    Raylib::Text::drawText("Global volume :", 765, 310, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1185, 300, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)masterVolume), 1290, 310, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1390, 300, Raylib::Color::White());

    // Music volume
    Raylib::Text::drawText("Music volume :", 765, 400, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1185, 390, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)musicVolume), 1290, 400, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1390, 390, Raylib::Color::White());

    // Sfx volume
    Raylib::Text::drawText("Sfx volume :", 765, 490, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1185, 475, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)sfxVolume), 1290, 490, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1390, 475, Raylib::Color::White());

    // Mods
    Raylib::Text::drawText("Mods :", 765, 600, 48, Raylib::Color::Yellow());
    modsButton->drawTexture(1200, 600, Raylib::Color::White());

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
    if (onFullscreen && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_TURN_OFF)->play();
        Raylib::Window::toggleFullscreen();
    }

    // Master volume click action
    if (onMasterVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        masterVolume -= 10;
        if (masterVolume < 0)
            masterVolume = 0;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }
    if (onMasterVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        masterVolume += 10;
        if (masterVolume > 100)
            masterVolume = 100;
        Raylib::Audio::setMasterVolume(masterVolume / 100);
    }

    // Music volume click action
    if (onMusicVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        musicVolume -= 10;
        if (musicVolume < 0)
            musicVolume = 0;
        changeMusicVolume();
    }
    if (onMusicVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        musicVolume += 10;
        if (musicVolume > 100)
            musicVolume = 100;
        changeMusicVolume();
    }

    // Sfx volume click action
    if (onSfxVolumeDown && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        sfxVolume -= 10;
        if (sfxVolume < 0)
            sfxVolume = 0;
        changeSfxVolume();
    }
    if (onSfxVolumeUp && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_NOCK)->play();
        sfxVolume += 10;
        if (sfxVolume > 100)
            sfxVolume = 100;
        changeSfxVolume();
    }
    // Mods bouton handling
    if (onMods && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_TURN_OFF)->play();
        _pSelector.toggleModsAvailable();
    }
}

void XRay::changeMusicVolume() {
    for (auto &i : _musics) {
        i.second->setVolume(musicVolume / 100);
    }
};

void XRay::changeSfxVolume() {
    for (auto &i : _sfx) {
        i.second->setVolume(sfxVolume / 100);
    }
};
