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
    bool onMasterVolumeUp = mouseIsInBox(createBox(1700, 300, 1764, 364)) ? true : false;
    bool onMasterVolumeDown = mouseIsInBox(createBox(1500, 300, 1564, 364)) ? true : false;
    bool onMusicVolumeUp = mouseIsInBox(createBox(1700, 400, 1764, 464)) ? true : false;
    bool onMusicVolumeDown = mouseIsInBox(createBox(1500, 400, 1564, 464)) ? true : false;
    bool onSfxVolumeUp = mouseIsInBox(createBox(1700, 500, 1764, 564)) ? true : false;
    bool onSfxVolumeDown = mouseIsInBox(createBox(1500, 500, 1564, 564)) ? true : false;

    // On / off buton for fullscreen button
    std::shared_ptr<Raylib::Texture> fullscreenButton = _resources.at(Raylib::Window::isWindowFullscreen() ? ON : OFF);

    /// Draw scene
    beginDrawing();

    // Background
    _resources.at(SETTING_BG)->drawTexture(0, 0, Raylib::Color::White());

    // Fullscreen
    fullscreenButton->drawTexture(1500, 200, Raylib::Color::White());
    Raylib::Text::drawText("Fullscreen :", 1200, 205, 48, Raylib::Color::Yellow());

    // Master Volume
    Raylib::Text::drawText("Global volume :", 1100, 305, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1500, 300, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)masterVolume), 1600, 305, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1700, 300, Raylib::Color::White());

    // Music volume
    Raylib::Text::drawText("Music volume :", 1100, 405, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1500, 400, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)musicVolume), 1600, 405, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1700, 400, Raylib::Color::White());

    // Sfx volume
    Raylib::Text::drawText("Sfx volume :", 1100, 505, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_DOWN)->drawTexture(1500, 500, Raylib::Color::White());
    Raylib::Text::drawText(std::to_string((int)sfxVolume), 1600, 505, 48, Raylib::Color::Yellow());
    _resources.at(VOLUME_UP)->drawTexture(1700, 500, Raylib::Color::White());

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
