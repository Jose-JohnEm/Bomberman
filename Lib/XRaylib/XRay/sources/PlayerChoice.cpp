/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerChoice
*/

#include "XRay.hpp"

void XRay::setTextBox(std::vector<bool> &mouseOnText, std::vector<Raylib::Rectangle> &textBox)
{
    for (size_t p = 0, a = 200; p < 4; p++, a += 400) {
        _letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        if (p < _allIntegers[2])
            textBox.push_back(*(new Raylib::Rectangle((float)a, 180, 225, 50)));
        _playerTab.push_back(true);
        _controlsTab.push_back(true);
    }
}

void XRay::updateTextBox(std::vector<bool> &mouseOnText, const std::vector<Raylib::Rectangle> &textBox)
{
    for (size_t i = 0; i < mouseOnText.size() && i < textBox.size(); i++) {
        mouseOnText[i] = (Raylib::Collision2D::checkCollision(Raylib::Vector2((float)Raylib::Mouse::getMouseX(), (float)Raylib::Mouse::getMouseY()), textBox[i])) ? true : false;
        if (mouseOnText[i]) {
            Raylib::Mouse::setMouseCursor(MOUSE_CURSOR_IBEAM);

            for (int key = Raylib::Keyboard::getCharPressed(); key > 0; key = Raylib::Keyboard::getCharPressed())
                if ((key >= 32) && (key <= 125) && (_letterAndFrame[i].first < 9)) {
                    _userNames[i].push_back(key);
                    _letterAndFrame[i].first++;
                }

            if (Raylib::Keyboard::isKeyPressed(KEY_BACKSPACE) && _userNames[i].size() > 0) {
                _letterAndFrame[i].first--;
                if (_letterAndFrame[i].first < 0)
                    _letterAndFrame[i].first = 0;
                else
                    _userNames[i].pop_back();
            }

        } else
            Raylib::Mouse::setMouseCursor(MOUSE_CURSOR_DEFAULT);

        _letterAndFrame[i].second = (mouseOnText[i]) ? _letterAndFrame[i].second+1 : 0;
    }
}

void XRay::removePlayer(const std::vector<std::pair<int, int>> &removeButtons)
{
    for (size_t u = 0; u < removeButtons.size(); u++) {
        if (mouseIsInBox(createBox(removeButtons[u].first, removeButtons[u].second, removeButtons[u].first+64, removeButtons[u].second+63)) && Raylib::Mouse::isButtonPressed(0)) {
            _allIntegers[2] -= 1;
            if (_playerTab[u+1]) {
                _controlsTab.erase(_controlsTab.begin() + u + 1);
                _letterAndFrame.erase(_letterAndFrame.begin() + u + 1);
                _userNames.erase(_userNames.begin() + u + 1);
            }
            _playerTab.erase(_playerTab.begin() + u + 1);

            _pSelector.unload(u + 1);
        }
    }
}

void XRay::addPlayer(std::vector<bool> &mouseOnText, std::vector<Raylib::Rectangle> textBox)
{
    float a = 200 + (textBox.size()*400);
    if (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && Raylib::Mouse::isButtonPressed(0)) {
        _allIntegers[2] += 1;
        _letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        textBox.push_back(*(new Raylib::Rectangle((float)a, 180, 225, 50)));
        _controlsTab.push_back(true);
        _playerTab.push_back(true);

        _pSelector.load();
    }
}

void XRay::manageNextOrPrev(const std::vector<std::pair<int, int>> &nextDifficultyButtons, const std::vector<std::pair<int, int>> &prevDifficultyButtons, const std::vector<std::pair<int, int>> &nextCharacterButtons, const std::vector<std::pair<int, int>> &prevCharacterButtons)
{
    if (Raylib::Mouse::isButtonPressed(0))
        for (size_t u = 0; u < nextDifficultyButtons.size(); u++) {
            _playerTab[u] = (mouseIsInBox(createBox(nextDifficultyButtons[u].first, nextDifficultyButtons[u].second, nextDifficultyButtons[u].first+50, nextDifficultyButtons[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _playerTab[u] = (mouseIsInBox(createBox(prevDifficultyButtons[u].first, prevDifficultyButtons[u].second, prevDifficultyButtons[u].first+50, prevDifficultyButtons[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(nextDifficultyButtons[u].first + 20, nextDifficultyButtons[u].second + 340, nextDifficultyButtons[u].first+70, nextDifficultyButtons[u].second+389)) && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(prevDifficultyButtons[u].first - 20, prevDifficultyButtons[u].second + 340, prevDifficultyButtons[u].first + 20, prevDifficultyButtons[u].second+389))  && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];

            if (mouseIsInBox(createBox(nextCharacterButtons[u].first, nextCharacterButtons[u].second, nextCharacterButtons[u].first+50, nextCharacterButtons[u].second+49)))
                _pSelector.next(u);
            if (mouseIsInBox(createBox(prevCharacterButtons[u].first, prevCharacterButtons[u].second, prevCharacterButtons[u].first+50, prevCharacterButtons[u].second+49)))
                _pSelector.prev(u);
        }
}

void XRay::displayBoxes(const std::vector<bool> &mouseOnText, const std::vector<Raylib::Rectangle> &textBox)
{
    for (size_t p = 0; p < _allIntegers[2]; p++) {
        if (_playerTab[p]) {
            Raylib::Rectangle::drawRectangleRec(textBox[p], Raylib::Color::LightGray());
            (mouseOnText[p]) ? Raylib::Rectangle::drawRectangleLines(textBox[p].getCStruct().x, textBox[p].getCStruct().y, textBox[p].getCStruct().width, textBox[p].getCStruct().height, Raylib::Color::Red()) : ::DrawRectangleLines(textBox[p].getCStruct().x, textBox[p].getCStruct().y, textBox[p].getCStruct().width, textBox[p].getCStruct().height, Raylib::Color::DarkGray().getCStruct());
            Raylib::Text::drawText(_userNames[p].c_str(), textBox[p].getCStruct().x + 5, textBox[p].getCStruct().y + 8, 40, Raylib::Color::Maroon());

            if (mouseOnText[p] && _letterAndFrame[p].first < 9)
                if (((_letterAndFrame[p].second/20)%10) == 0)
                    Raylib::Text::drawText("_", textBox[p].getCStruct().x + 8 + Raylib::Text::measureText(_userNames[p].c_str(), 40), textBox[p].getCStruct().y + 12, 40, Raylib::Color::Maroon());
        }
    }
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removeButtons, std::vector<std::pair<int, int>> &nextDifficultyButtons, std::vector<std::pair<int, int>> &prevDifficultyButtons, std::vector<std::pair<int, int>> &nextCharacterButtons, std::vector<std::pair<int, int>> &prevCharacterButtons, int *x)
{
    int i, b;
    for (i = 0, (*x) = 200, b = 300; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*x) += 400) {
        _resources.at(PREVIOUS)->drawTexture((*x)-54, _allIntegers[1] + 180, Raylib::Color::White());
        _resources.at(PREVIOUS)->drawTexture((*x)-84, _allIntegers[1], Raylib::Color::White());
        if (_playerTab[i]) {
            (_controlsTab[i]) ? _resources.at(CONTROLS)->drawTexture((*x) - 30, _allIntegers[1] + 300, Raylib::Color::White()) : _resources.at(GAMEPAD)->drawTexture((*x) - 30, _allIntegers[1] + 300, Raylib::Color::White());
            _resources.at(PREVIOUS)->drawTexture((*x)-84, _allIntegers[1] + 340, Raylib::Color::White());
            _resources.at(NEXT)->drawTexture((*x)+250, _allIntegers[1] + 340, Raylib::Color::White());
        }
        (_playerTab[i]) ? _resources.at(HUMAN)->drawTexture((*x), b, Raylib::Color::White()) : _resources.at(AI)->drawTexture((*x), b, Raylib::Color::White());
        _resources.at(NEXT)->drawTexture((*x)+230, _allIntegers[1] + 180, Raylib::Color::White());
        _resources.at(NEXT)->drawTexture((*x)+250, _allIntegers[1], Raylib::Color::White());
        nextDifficultyButtons.push_back(std::make_pair((*x) + 230, _allIntegers[1] + 180));
        prevDifficultyButtons.push_back(std::make_pair((*x) - 54, _allIntegers[1] + 180));
        nextCharacterButtons.push_back(std::make_pair((*x) + 230, _allIntegers[1]));
        prevCharacterButtons.push_back(std::make_pair((*x) - 54, _allIntegers[1]));
        if (i != 0) {
            removeButtons.push_back(std::make_pair((*x)+240, _allIntegers[1]-100));
            _resources.at(REMOVE)->drawTexture((*x) + 240, _allIntegers[1]-100, Raylib::Color::White());
        }
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*x), _allIntegers[1], Raylib::Color::White());
}

void XRay::displayPlayerChoiceScene(void)
{
    // Set scene
    _scene = PLAYER_CHOICE;

    // Create containers
    std::vector<std::pair<int, int>> removeButtons;     // A vector of all remove buttons coordinates
    std::vector<std::pair<int, int>> nextDifficultyButtons;       // A vector of all next difficulty buttons coordinates
    std::vector<std::pair<int, int>> prevDifficultyButtons;       // A vector of all previous difficulty buttons coordinates
    std::vector<std::pair<int, int>> nextCharacterButtons;       // A vector of all next Character buttons coordinates
    std::vector<std::pair<int, int>> prevCharacterButtons;       // A vector of all previous Character buttons coordinates

    // Create containers
    std::vector<bool> mouseOnText;                      // A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
    std::vector<Raylib::Rectangle> textBox;             // A vector of rectangle that represents the boxes of the pseudos
    
    // A int that represents the x coordinate of the last displayed card
    int x;

    // Initialize and Update all the containers that refer to the boxes of the pseudos
    setTextBox(mouseOnText, textBox);
    updateTextBox(mouseOnText, textBox);

    // Draw scene
    beginDrawing();

    displayBoxes(mouseOnText, textBox);
    displayCardsSettings(removeButtons, nextDifficultyButtons, prevDifficultyButtons, nextCharacterButtons, prevCharacterButtons, &x);
    displayMouse();

    _pSelector.draw();
    
    endDrawing();

    // Check and Manage Click on buttons
    addPlayer(mouseOnText, textBox);
    manageNextOrPrev(nextDifficultyButtons, prevDifficultyButtons, nextCharacterButtons, prevCharacterButtons);
    removePlayer(removeButtons);
}