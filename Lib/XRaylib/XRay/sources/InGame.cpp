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

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Lambda for panel pos
    auto panelLambda = [](size_t a) { return (a <= 2) ? std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}}
    : std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}, {20, 950}, {1500, 950}}; };

    // Position of all Panels in a vector of pair (x, y)
    static std::vector<std::pair<size_t, size_t>> panelPos = panelLambda(_allIntegers[2]);

    // Draw scene
    beginDrawing();

    displayPlayersPanels(panelPos);
    // Some code

    endDrawing();
}