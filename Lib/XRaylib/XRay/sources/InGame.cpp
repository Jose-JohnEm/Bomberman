/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** InGame
*/

#include "XRay.hpp"
#include "../../../Engine/Exception/MyException.hpp"

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

void XRay::displayPlayersPanels(std::vector<std::pair<size_t, size_t>> &_panelPos)
{
    for (size_t u = 0; u < (_gameSettings[7] + _gameSettings[5]); u++) {
        if (_controlsTab[u] == Resources::PLAYSTATIONYELLOW)
            _resources.at(PLAYSTATIONPANEL)->drawTexture(_panelPos[u].first, _panelPos[u].second);
        if (_controlsTab[u] == Resources::XBOXYELLOW)
            _resources.at(XBOXPANEL)->drawTexture(_panelPos[u].first, _panelPos[u].second);
        if (_controlsTab[u] == Resources::MOUSEYELLOW) {
            _resources.at(MOUSEPANEL)->drawTexture(_panelPos[u].first, _panelPos[u].second);
            _resources.at(MOUSERADAR)->drawTexture(1600, 40);
        }
        if (_controlsTab[u] == Resources::KEYBOARDYELLOW)
            _resources.at(KEYBOARDPANEL)->drawTexture(_panelPos[u].first, _panelPos[u].second);
        drawPlayersHead(u, _panelPos[u].first-10, _panelPos[u].second-180);
    }
    _resources.at(CLOCKBAR)->drawTexture(600, 0);
    _resources.at(CLOCKBAR)->drawTexture(1200, 0);
    Raylib::Text::drawText(std::to_string(_gameSettings[2]), 720, 15, 60, Raylib::Color::White());
    Raylib::Text::drawText(getTimeInFormat(), 1245, 15, 60, Raylib::Color::White());
}

void XRay::displayPauseScene(void)
{
    if (_isPaused) {
        _resources.at(DEPAUSE)->drawTexture(10, 5);
        _resources.at(PAUSEBACK)->drawTexture(0, 0);
        (mouseIsInBox(createBox<size_t>(460, 445, 460+375, 445+65)) ? _resources.at(RESUMEHOVER) : _resources.at(RESUME))->drawTexture(460, 445);
        (mouseIsInBox(createBox<size_t>(460, 555, 460+375, 555+65)) ? _resources.at(RESTARTHOVER) : _resources.at(Resources::RESTART))->drawTexture(460, 555);
        (mouseIsInBox(createBox<size_t>(460, 665, 460+375, 665+65)) ? _resources.at(SAVEHOVER) : _resources.at(Resources::SAVE))->drawTexture(460, 665);
        (mouseIsInBox(createBox<size_t>(460, 775, 460+375, 775+65)) ? _resources.at(SETTINGSHOVER) : _resources.at(Resources::SETTING))->drawTexture(460, 775);
        (mouseIsInBox(createBox<size_t>(460, 885, 460+375, 885+65)) ? _resources.at(HOMEHOVER) : _resources.at(Resources::HOME))->drawTexture(460, 885);
    } else
        _resources.at(PAUSE)->drawTexture(10, 5);
}

void XRay::goToAnotherScene()
{
    // Check if mouse is on button spot
    bool pauseButton = mouseIsInBox(createBox<size_t>(10, 5, 122, 127)) ? true : false;
    bool resume = mouseIsInBox(createBox<size_t>(460, 445, 460+375, 445+65)) ? true : false;
    bool restart = mouseIsInBox(createBox<size_t>(460, 555, 460+375, 555+65)) ? true : false;
    bool save = mouseIsInBox(createBox<size_t>(460, 665, 460+375, 665+65)) ? true : false;
    bool settings = mouseIsInBox(createBox<size_t>(460, 775, 460+375, 775+65)) ? true : false;
    bool home = mouseIsInBox(createBox<size_t>(460, 885, 460+375, 885+65)) ? true : false;

    // Go to another scene according to mouse position
    if (pauseButton && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = true;
        _sfx.at(SFX_KLICK)->play();
        _lastFrameTime = Raylib::Timing::getTime();
    }
    if (_isPaused && resume && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        _sfx.at(SFX_KLICK)->play();
        _startingTime += Raylib::Timing::getTime() - _lastFrameTime;
    }
    if (_isPaused && restart && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_KLICK)->play();
        _isPaused = false;
        m_isPaused = 2;
        _pointerToRestartFunc();
        displayCinematic("loading", 0, 0);
        displayInGameScene();
    }
    if (_isPaused && save && Raylib::Mouse::isButtonPressed(0)) {
        beginDrawing(false);
        _sfx.at(SFX_KLICK)->play();
        _resources.at(SAVED)->drawTexture(650, 20);
        endDrawing();
        _pointerToSaveFunc(_gameSettings, getPlayerControls());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (_isPaused && settings && Raylib::Mouse::isButtonPressed(0)) {
        _scenesBack[Scene::SETTINGS] = &XRay::displayInGameScene;
        _sfx.at(SFX_SETTING)->play();
        displaySettingsScene();
    }
    if (_isPaused && home && Raylib::Mouse::isButtonPressed(0)) {
        _isPaused = false;
        _sfx.at(SFX_HOME)->play();
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

void XRay::checkEndScenario(void)
{
    size_t i = 0;

    while (i < _gameInfos.size() && _gameInfos[i]->getType().compare("Human") != 0)
        i++;
    if (_gameSettings[7] == 1) {
        if (_musics.at(MSC_GAME)->isPlaying())
            _musics.at(MSC_GAME)->stop();
        if (_gameInfos[i]->getShouldDisplay())
            displayVictoryScene();
        else
            displayDefeatScene();
    } else {
        if (_musics.at(MSC_GAME)->isPlaying())
            _musics.at(MSC_GAME)->stop();
        displayVictoryScene();
    }
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Declaration of two variables
    float size_m = (static_cast<float>(_sizeMap+1)) / 2;
    size_t deadPlayers = 0;

    // Lambda for panel pos
    auto panelLambda = [](size_t a) { return (a <= 2) ? std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}}
                                                      : std::vector<std::pair<size_t, size_t>>{{20, 500}, {1500, 500}, {20, 950}, {1500, 950}}; };

    // Display Cinematic ready, 3, 2, 1, go
    if (m_isPaused == 2) {
        _panelPos = panelLambda(_gameSettings[7] + _gameSettings[5]);
        _camera = Raylib::Camera3D(Vector3{size_m, size_m * -0.3f, size_m * 2.2f}, Vector3{size_m, size_m, 0}, Vector3{0, 1, 0}, 50, 0);
        displayCinematic("loading", 0, 0);
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _gameSettings[4] = _gameSettings[3];
    }

    // Next Set
    if (_gameSettings[4] == 0 && _gameSettings[2] < _gameSettings[1]) {
        displayCinematic("readygo", 0, 1000);
        _startingTime = Raylib::Timing::getTime();
        _lastFrameTime = Raylib::Timing::getTime();
        _pointerToRestartFunc();
        _gameSettings[2] += 1;
        _gameSettings[4] = _gameSettings[3];

    }

    // Stop bomberman music
    if (_musics.at(MSC_BOMBERMAN)->isPlaying())
        _musics.at(MSC_BOMBERMAN)->stop();
    // Play music
    playMusic(MSC_GAME);

    // Draw scene
    beginDrawing();
    Raylib::Drawing::clearBackground(Raylib::Color::Brown());
    _camera.beginMode3D();
    for (size_t o = 0; o < _gameInfos.size(); o++)
        if (_gameInfos[o]->getShouldDisplay())
            _gameInfos[o]->drawEntity();
    _camera.endMode3D();
    displayPlayersPanels(_panelPos);
    displayPauseScene();
    displayMouse();
    endDrawing();

    m_isPaused = _isPaused;
    _gameSettings[4] = !_isPaused && _gameSettings[4] > 0 ? _gameSettings[3] - (Raylib::Timing::getTime() - _startingTime) : _gameSettings[4];

    // Call function that check players input
    managePlayersActions();

    // Call function that check click on button
    goToAnotherScene();

    // End Scenario
    for (size_t i = 0; i < _gameInfos.size(); i++)
        if (!_gameInfos[i]->getType().compare("Human"))
            deadPlayers += _gameInfos[i]->getShouldDisplay() ? 0 : 1;

    if (deadPlayers == _gameSettings[7] || (_gameSettings[2] >= _gameSettings[1] && _gameSettings[4] == 0))
        checkEndScenario();
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrygetTimeInFormat() {
    try
    {   XRay test;
        test.getTimeInFormat();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydrawPlayersHead() {
    try
    {   XRay test;
        size_t i;
        size_t x;
        size_t y;
        test.drawPlayersHead(i,x,y);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayPlayersPanels() {
    try
    {   XRay test;
        std::vector<std::pair<size_t, size_t>> _panelPos;
        test.displayPlayersPanels(_panelPos);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayPauseScene() {
    try
    {   XRay test;
        test.displayPauseScene();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydgoToAnotherScene() {
    try
    {   XRay test;
        test.goToAnotherScene();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymanagePlayersActions() {
    try
    {   XRay test;
        test.managePlayersActions();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrydisplayInGameScene() {
    try
    {   XRay test;
        test.displayInGameScene();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
