/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerChoice
*/

#include "XRay.hpp"

void XRay::detectPlayerInput(void)
{
    Resources tmp;
    size_t t = 0;

    while (t < _allIntegers[2]-1 && _playerTab[t])
        t++;
    tmp = _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(0) && Raylib::Gamepad::isGamepadButtonPressed(0, 15)) ? PLAYSTATIONYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(1) && Raylib::Gamepad::isGamepadButtonPressed(1, 15)) ? XBOXYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Keyboard::getKeyPressed()) ? KEYBOARDYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Mouse::isButtonPressed(0)) ? MOUSEYELLOW : _controlsTab[t];
    for (size_t k = 0; k < t; k++)
        _controlsTab[t] = (_controlsTab[t] == _controlsTab[k]) ? tmp : _controlsTab[t];
    _playerTab[t] = (tmp != _controlsTab[t]) ? true : _playerTab[t];
    if (tmp != _controlsTab[t]) {
        _playersInput.pop_back();
        if (_controlsTab[t] == PLAYSTATIONYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(0)));
        if (_controlsTab[t] == XBOXYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new GamepadPlayerInput(1)));
        if (_controlsTab[t] == KEYBOARDYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new KeyboardPlayerInput()));
        if (_controlsTab[t] == MOUSEYELLOW)
            _playersInput.push_back(std::shared_ptr<IPlayerInput>(new MousePlayerInput()));
    }
}

void XRay::removePlayer(const std::vector<std::pair<int, int>> &removeButtons)
{
    for (size_t u = 0; u < removeButtons.size(); u++) {
        if (mouseIsInBox(createBox(removeButtons[u].first, removeButtons[u].second, removeButtons[u].first+64, removeButtons[u].second+63)) && Raylib::Mouse::isButtonPressed(0)) {
            _allIntegers[2] -= 1;
            if (_playerTab[u+1]) {
                _controlsTab.erase(_controlsTab.begin() + u + 1);
                _playersInput.erase(_playersInput.begin() + u + 1);
            }
            _playerTab.erase(_playerTab.begin() + u + 1);
            _pSelector.unload(u + 1);
        }
    }
}

void XRay::addPlayer(void)
{
    float a = 100 + (_allIntegers[2]*450);
    if (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && Raylib::Mouse::isButtonPressed(0)) {
        _allIntegers[2] += 1;
        _playerTab.push_back(false);
        _pSelector.load();
        _playersInput.push_back(std::shared_ptr<IPlayerInput>(new MousePlayerInput()));
    }
}

void XRay::manageNextOrPrev(void)
{
    auto glambda = [](size_t a) { return a == 40 ? 36 : 40; };

    _nextOrNot = 0;
    for (size_t u = 0; u < _allIntegers[2] && u < _playersInput.size(); u++) {
        _card[u] = (_playersInput[u]->shouldSimulateAClick()) ? glambda(_card[u]) : _card[u];
        if (!_playerTab[u])
            _card[u] = 40;
        if (_playersInput[u]->shouldChangeToPrev() && _playerTab[u])
            _pSelector.prev(u);
        if (_playersInput[u]->shouldChangeToNext() && _playerTab[u])
            _pSelector.next(u);
        _nextOrNot += _card[u];
    }
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removeButtons, int *x)
{
    int i, b;
    for (i = 0, (*x) = 100, b = 200; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*x) += 450) {
        (_playerTab[i]) ? _resources.at((Resources)(_card[i]+i))->drawTexture((*x), b) : _resources.at(AI)->drawTexture((*x), b);
        if (_playerTab[i])
            _resources.at((Resources)(size_t)((_controlsTab[i])+_card[i]-36))->drawTexture((*x)+109, b+9);
        if (i != 0)
            removeButtons.push_back(std::make_pair((*x)+307, b+9));
        if (_card[i] == 36) {
            Raylib::Text::drawText(_pSelector[i].getName(), 200 + 450 * i + ((180 - Raylib::Text::measureText(_pSelector[i].getName(), 50)) / 2), 595, 50, Raylib::Color::Black());
        }
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*x), _allIntegers[1]);
}

void XRay::displayBack(void)
{
    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= (-_resources.at(BG)->getCStruct().width/3 * 2)) _scrollingBack = 0;

    _resources.at(BG)->drawTexture(_scrollingBack, 0, 0.0f, 1.0f);
    _resources.at(BG)->drawTexture(_resources.at(BG)->getCStruct().width + _scrollingBack, 0, 0.0f, 1.0f);
}

void XRay::displayPlayerChoiceScene(void)
{
    // Set scene
    _scene = PLAYER_CHOICE;

    // Audio
    _musics.at(MSC_BOMBERMAN)->update();

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox(1700, 1000, 1918, 1061)) ? true : false;

    // Create containers
    std::vector<std::pair<int, int>> removeButtons;     // A vector of all remove buttons coordinates
    std::vector<bool> mouseOnText;                      // A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
    std::vector<Raylib::Rectangle> textBox;             // A vector of rectangle that represents the boxes of the pseudos

    // A int that represents the x coordinate of the last displayed card
    int x;

    // Detect Keyboard, Mouse, and Gamepad
    detectPlayerInput();

    // Draw scene
    beginDrawing();
    displayBack();

    displayCardsSettings(removeButtons, &x);
    (goBack ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000);
    (goNext ? _resources.at(NEXT_HOVER) : _resources.at(NEXTSCENE))->drawTexture(1700, 1000);

    _pSelector.drawPlayers();

    displayMouse();
    endDrawing();

    manageNextOrPrev();

    // Check and Manage Click on buttons
    removePlayer(removeButtons);
    addPlayer();


    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0)) {
        _sfx.at(SFX_HOME)->play();
        (this->*_scenesBack[_scene])();
        _scenesBack[PLAYER_CHOICE] = _scenesBackBackup[PLAYER_CHOICE];
    }
    if (goNext && Raylib::Mouse::isButtonPressed(0) && _nextOrNot == _allIntegers[2] * 40) {
        for (size_t o = 0; o < _allIntegers[2]; o++)
            _userNames.push_back(_pSelector[o].getName());
        displayMapChoiceScene();
    }
}