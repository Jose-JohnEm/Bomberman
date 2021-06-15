/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** InGame
*/

#include "XRay.hpp"

std::string XRay::getTimeInFormat(void)
{
    int min = _gameSettings[4] / 60;
    int secs = _gameSettings[4] % 60;
    std::string time(std::string("0")+std::to_string(min)+std::string(":")
    +((secs >= 10) ? std::string("") : std::string("0"))+std::to_string(secs));

    return time;
}

void XRay::drawPlayersHead(size_t i, size_t x, size_t y)
{
    if (_userNames[i] == "Yellow")
        _resources.at(YELLOWBOMBERMAN)->drawTexture(x, y);
    if (_userNames[i] == "Red")
        _resources.at(REDBOMBERMAN)->drawTexture(x, y);
    if (_userNames[i] == "Blue")
        _resources.at(BLUEBOMBERMAN)->drawTexture(x, y);
    if (_userNames[i] == "Green")
        _resources.at(GREENBOMBERMAN)->drawTexture(x, y);
}

void XRay::displayPlayersPanels(std::vector<std::pair<size_t, size_t>> &panelPos)
{
    for (size_t u = 0; u < _allIntegers[2]; u++) {
        if (_controlsTab[u] == Resources::PLAYSTATIONYELLOW)
            _resources.at(PLAYSTATIONPANEL)->drawTexture(panelPos[u].first, panelPos[u].second);
        if (_controlsTab[u] == Resources::XBOXYELLOW)
            _resources.at(XBOXPANEL)->drawTexture(panelPos[u].first, panelPos[u].second);
        if (_controlsTab[u] == Resources::MOUSEYELLOW)
            _resources.at(MOUSEPANEL)->drawTexture(panelPos[u].first, panelPos[u].second);
        if (_controlsTab[u] == Resources::KEYBOARDYELLOW)
            _resources.at(KEYBOARDPANEL)->drawTexture(panelPos[u].first, panelPos[u].second);
        drawPlayersHead(u, panelPos[u].first-10, panelPos[u].second-180);
    }
    _resources.at(CLOCKBAR)->drawTexture(1600, 200);
    _resources.at(CLOCKBAR)->drawTexture(1600, 50);
    Raylib::Text::drawText(std::to_string(_gameSettings[2]), 1720, 75, 60, Raylib::Color::White());
    Raylib::Text::drawText(getTimeInFormat(), 1645, 225, 60, Raylib::Color::White());
}

void XRay::displayPauseScene(void)
{
    if (_isPaused) {
        _resources.at(DEPAUSE)->drawTexture(10, 5);
        _resources.at(PAUSEBACK)->drawTexture(0, 0);
        (mouseIsInBox(createBox(460, 445, 460+375, 445+65)) ? _resources.at(RESUMEHOVER) : _resources.at(RESUME))->drawTexture(460, 445);
        (mouseIsInBox(createBox(460, 555, 460+375, 555+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(460, 555);
        (mouseIsInBox(createBox(460, 665, 460+375, 665+65)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(460, 665);
        (mouseIsInBox(createBox(460, 775, 460+375, 775+65)) ? _resources.at(SETTINGSHOVER) : _resources.at(Resources::SETTING))->drawTexture(460, 775);
        (mouseIsInBox(createBox(460, 885, 460+375, 885+65)) ? _resources.at(HOMEHOVER) : _resources.at(Resources::HOME))->drawTexture(460, 885);
    } else
        _resources.at(PAUSE)->drawTexture(10, 5);
}

void XRay::goToAnotherScene()
{
    // Check if mouse is on button spot
    bool pauseButton = mouseIsInBox(createBox(10, 5, 122, 127)) ? true : false;
    bool resume = mouseIsInBox(createBox(460, 445, 460+375, 445+65)) ? true : false;
    bool restart = mouseIsInBox(createBox(460, 555, 460+375, 555+65)) ? true : false;
    bool save = mouseIsInBox(createBox(460, 665, 460+375, 665+65)) ? true : false;
    bool settings = mouseIsInBox(createBox(460, 775, 460+375, 775+65)) ? true : false;
    bool home = mouseIsInBox(createBox(460, 885, 460+375, 885+65)) ? true : false;

    // Go to another scene according to mouse position
    if (pauseButton && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = true;
        _lastFrameTime = Raylib::Timing::getTime();
    }
    if (_isPaused && resume && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        _startingTime += Raylib::Timing::getTime() - _lastFrameTime;
    }
    if (_isPaused && restart && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (_isPaused && save && Raylib::Mouse::isButtonPressed(0)) {
        beginDrawing(false);
        _resources.at(SAVED)->drawTexture(650, 20);
        endDrawing();
        _pointerToSaveFunc(_gameSettings);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (_isPaused && settings && Raylib::Mouse::isButtonPressed(0)) {
        _scenesBack[Scene::SETTINGS] = &XRay::displayInGameScene;
        displaySettingsScene();
    }
    if (_isPaused && home && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        resetAll();
        displayMenuScene();
    }
}

void XRay::managePlayersActions(void)
{
    for (size_t u = 0; u < _playersInput.size(); u++) {
        if (_playersInput[u]->shouldGoToEast())
            _playerActionsFunc(u, "goEast");
        if (_playersInput[u]->shouldGoToNorth())
            _playerActionsFunc(u, "goNorth");
        if (_playersInput[u]->shouldGoToSouth())
            _playerActionsFunc(u, "goSouth");
        if (_playersInput[u]->shouldGoToWest())
            _playerActionsFunc(u, "goWest");
        if (_playersInput[u]->shouldSimulateAClick())
            _playerActionsFunc(u, "dropBomb");
    }
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    float size_m = ((float)_sizeMap+1) / 2;

    // Lambda for panel pos
    auto panelLambda = [](size_t a) { return (a <= 2) ? std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}}
    : std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}, {20, 950}, {1500, 950}}; };

    // Position of all Panels in a vector of pair (x, y)
    static std::vector<std::pair<size_t, size_t>> panelPos = panelLambda(_allIntegers[2]);

    // Display Cinematic ready, 3, 2, 1, go
    if (m_isPaused == 2) {
        _camera = Raylib::Camera3D(Vector3{size_m, size_m * -0.3f, size_m * 2.2f}, Vector3{size_m, size_m, 0}, Vector3{0, 1, 0}, 50, 0);
        displayCinematic("loading", 0, 0);
        _resources.at(MAPCHOICEBG)->drawTexture(0, 0);
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _gameSettings[4] = _gameSettings[3];
    }

    // Next Set
    if (_gameSettings[4] == 0 && _gameSettings[2] < _gameSettings[1]) {
        _resources.at(MAPCHOICEBG)->drawTexture(0, 0);
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _gameSettings[2] += 1;
        _gameSettings[4] = _gameSettings[3];
    }

    // Draw scene
    beginDrawing();
    Raylib::Drawing::clearBackground(Raylib::Color::Brown());
    _camera.beginMode3D();
    for (size_t o = 0; o < _gameInfos.size(); o++)
        _gameInfos[o]->drawEntity();
    _camera.endMode3D();
    displayPlayersPanels(panelPos);
    displayPauseScene();
    displayMouse();
    endDrawing();

    m_isPaused = _isPaused;
    _gameSettings[4] = !_isPaused && _gameSettings[4] > 0 ? _gameSettings[3] - (Raylib::Timing::getTime() - _startingTime) : _gameSettings[4];

    managePlayersActions();
    // Call function that check click on button
    goToAnotherScene();

    if (Raylib::Keyboard::isKeyPressed(68))
        displayDefeatScene();
    if (Raylib::Keyboard::isKeyPressed(86))
        displayVictoryScene();
}