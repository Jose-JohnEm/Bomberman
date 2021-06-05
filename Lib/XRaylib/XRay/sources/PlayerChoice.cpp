/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerChoice
*/

#include "XRay.hpp"

void XRay::detectPlayerInput()
{
    Resources tmp;
    size_t t = 0;

    for (; t < _allIntegers[2]-1 && _playerTab[t]; t++);
    tmp = _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(0) && Raylib::Gamepad::isGamepadButtonPressed(0, 15)) ? PLAYSTATIONYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Gamepad::isGamepadAvailable(1) && Raylib::Gamepad::isGamepadButtonPressed(1, 15)) ? XBOXYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Keyboard::getKeyPressed()) ? KEYBOARDYELLOW : _controlsTab[t];
    _controlsTab[t] = (Raylib::Mouse::isButtonPressed(0)) ? MOUSEYELLOW : _controlsTab[t];
    for (size_t k = 0; k < t; k++)
        _controlsTab[t] = (_controlsTab[t] == _controlsTab[k]) ? tmp : _controlsTab[t];
    _playerTab[t] = (tmp != _controlsTab[t]) ? true : _playerTab[t];
}

void XRay::removePlayer(const std::vector<std::pair<int, int>> &removeButtons)
{
    for (size_t u = 0; u < removeButtons.size(); u++) {
        if (mouseIsInBox(createBox(removeButtons[u].first, removeButtons[u].second, removeButtons[u].first+64, removeButtons[u].second+63)) && Raylib::Mouse::isButtonPressed(0)) {
            _allIntegers[2] -= 1;
            if (_playerTab[u+1])
                _controlsTab.erase(_controlsTab.begin() + u + 1);
            _playerTab.erase(_playerTab.begin() + u + 1);
        }
    }
}

void XRay::addPlayer()
{
    float a = 100 + (_allIntegers[2]*450);
    if (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && Raylib::Mouse::isButtonPressed(0)) {
        _allIntegers[2] += 1;
        _playerTab.push_back(false);
    }
}

void XRay::manageNextOrPrev()
{
    auto glambda = [](size_t a) { return a == 40 ? 36 : 40; };

    _nextOrNot = 0;
    for (size_t u = 0; u < _allIntegers[2]; u++) {
        if (_controlsTab[u] == Resources::PLAYSTATIONYELLOW)
            _card[u] = Raylib::Gamepad::isGamepadButtonPressed(0, 7) ? glambda(_card[u]) : _card[u];
        if (_controlsTab[u] == Resources::XBOXYELLOW)
            _card[u] = Raylib::Gamepad::isGamepadButtonPressed(1, 7) ? glambda(_card[u]) : _card[u];
        if (_controlsTab[u] == Resources::MOUSEYELLOW)
            _card[u] = Raylib::Mouse::isButtonPressed(1) ? glambda(_card[u]) : _card[u];
        if (_controlsTab[u] == Resources::KEYBOARDYELLOW)
            _card[u] = (Raylib::Keyboard::getKeyPressed() == 32) ? glambda(_card[u]) : _card[u];
        _nextOrNot += _card[u];
    }
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removeButtons, int *x)
{
    int i, b;
    for (i = 0, (*x) = 100, b = 200; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*x) += 450) {
        (_playerTab[i]) ? _resources.at((Resources)(_card[i]+i))->drawTexture((*x), b, Raylib::Color::White()) : _resources.at(AI)->drawTexture((*x), b, Raylib::Color::White());
        if (_playerTab[i])
            _resources.at((Resources)(size_t)((_controlsTab[i])+_card[i]-36))->drawTexture((*x)+109, b+9, Raylib::Color::White());
        if (i != 0)
            removeButtons.push_back(std::make_pair((*x)+307, b+9));
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*x), _allIntegers[1], Raylib::Color::White());
}

void XRay::displayBack()
{
    // Parallax update
    _scrollingBack -= 0.1f;
    if (_scrollingBack <= (-_resources.at(BG)->getCStruct().width/3 * 2)) _scrollingBack = 0;

    _resources.at(BG)->drawTextureEx(*_resources.at(BG).get(), *(new Raylib::Vector2(_scrollingBack, 0)), 0.0f, 1.0f, Raylib::Color::White());
    _resources.at(BG)->drawTextureEx(*_resources.at(BG).get(), *(new Raylib::Vector2(_resources.at(BG)->getCStruct().width + _scrollingBack, 0)), 0.0f, 1.0f, Raylib::Color::White());
}

void XRay::displayPlayerChoiceScene(void)
{
    // Set scene
    _scene = PLAYER_CHOICE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(20, 1000, 280, 1065)) ? true : false;
    bool goNext = mouseIsInBox(createBox(1700, 1000, 1918, 1061)) ? true : false;

    // Create containers
    std::vector<std::pair<int, int>> removeButtons;     // A vector of all remove buttons coordinates
    std::vector<bool> mouseOnText;                      // A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
    std::vector<Raylib::Rectangle> textBox;             // A vector of rectangle that represents the boxes of the pseudos

    // A int that represents the x coordinate of the last displayed card
    int x;

    // Initialize and Update all the containers that refer to the boxes of the pseudos
    detectPlayerInput();

    // Draw scene
    beginDrawing();
    displayBack();

    displayCardsSettings(removeButtons, &x);
    (mouseIsInBox(createBox(20, 1000, 280, 1065)) ? _resources.at(BACK_HOVER) : _resources.at(BACK))->drawTexture(20, 1000, Raylib::Color::White());
    (mouseIsInBox(createBox(1700, 1000, 1918, 1061)) ? _resources.at(NEXT_HOVER) : _resources.at(NEXTSCENE))->drawTexture(1700, 1000, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Check and Manage Click on buttons
    addPlayer();
    removePlayer(removeButtons);

    manageNextOrPrev();

    // Go to another scene according to mouse position
    if (goBack && Raylib::Mouse::isButtonPressed(0))
        displayGameModeScene();
    if (goNext && Raylib::Mouse::isButtonPressed(0) && _nextOrNot == _allIntegers[2] * 40)
        displayMapChoiceScene();
}