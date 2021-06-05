/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** InGame
*/

#include "XRay.hpp"

void XRay::displayPlayersPanels(std::vector<std::pair<size_t, size_t>> &panelPos)
{
    for (size_t u = 0; u < _allIntegers[2]; u++) {
        if (_controlsTab[u] == Resources::PLAYSTATIONYELLOW)
            _resources.at(PLAYSTATIONPANEL)->drawTexture(panelPos[u].first, panelPos[u].second, Raylib::Color::White());
        if (_controlsTab[u] == Resources::XBOXYELLOW)
            _resources.at(XBOXPANEL)->drawTexture(panelPos[u].first, panelPos[u].second, Raylib::Color::White());
        if (_controlsTab[u] == Resources::MOUSEYELLOW)
            _resources.at(MOUSEPANEL)->drawTexture(panelPos[u].first, panelPos[u].second, Raylib::Color::White());
        if (_controlsTab[u] == Resources::KEYBOARDYELLOW)
            _resources.at(KEYBOARDPANEL)->drawTexture(panelPos[u].first, panelPos[u].second, Raylib::Color::White());
    }
}

void XRay::displayPauseScene(void)
{
    if (_isPaused) {
        _resources.at(DEPAUSE)->drawTexture(10, 5, Raylib::Color::White());
        _resources.at(PAUSEBACK)->drawTexture(0, 0, Raylib::Color::White());
        (mouseIsInBox(createBox(460, 445, 460+470, 445+95)) ? _resources.at(RESUMEHOVER) : _resources.at(RESUME))->drawTexture(460, 445, Raylib::Color::White());
        (mouseIsInBox(createBox(460, 555, 460+470, 555+95)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(460, 555, Raylib::Color::White());
        (mouseIsInBox(createBox(460, 665, 460+470, 665+95)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(460, 665, Raylib::Color::White());
        (mouseIsInBox(createBox(460, 775, 460+470, 775+95)) ? _resources.at(HOMEHOVER) : _resources.at(Resources::HOME))->drawTexture(460, 775, Raylib::Color::White());
    } else
        _resources.at(PAUSE)->drawTexture(10, 5, Raylib::Color::White());
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Check if mouse is on button spot
    bool pauseButton = mouseIsInBox(createBox(10, 5, 122, 127)) ? true : false;

    bool resume = mouseIsInBox(createBox(460, 445, 460+470, 445+95)) ? true : false;
    bool restart = mouseIsInBox(createBox(460, 555, 460+470, 555+95)) ? true : false;
    bool save = mouseIsInBox(createBox(460, 665, 460+470, 665+95)) ? true : false;
    bool home = mouseIsInBox(createBox(460, 775, 460+470, 775+95)) ? true : false;

    // Lambda for panel pos
    auto panelLambda = [](size_t a) { return (a <= 2) ? std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}}
    : std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}, {20, 950}, {1500, 950}}; };

    // Position of all Panels in a vector of pair (x, y)
    static std::vector<std::pair<size_t, size_t>> panelPos = panelLambda(_allIntegers[2]);

    // Display Cinematic ready, 3, 2, 1, go
    if (m_isPaused == 2)
        displayCinematic("readygo", 0, 1000);

    // Draw scene
    beginDrawing();

    displayPlayersPanels(panelPos);
    displayPauseScene();
    displayMouse();
    endDrawing();

    if (pauseButton && Raylib::Mouse::isButtonPressed(0))
        _isPaused = true;
    if (resume && Raylib::Mouse::isButtonPressed(0))
        _isPaused = false;
    if (restart && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (save && Raylib::Mouse::isButtonPressed(0));
    if (home && Raylib::Mouse::isButtonPressed(0))
        displayMenuScene();
    m_isPaused = _isPaused;
}