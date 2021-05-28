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

void XRay::updateTextBox(std::vector<bool> &mouseOnText, std::vector<Raylib::Rectangle> textBox)
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

void XRay::removePlayer(std::vector<std::pair<int, int>> &removePos, std::vector<bool> &mouseOnText, std::vector<Raylib::Rectangle> textBox)
{
    for (size_t u = 0; u < removePos.size(); u++) {
        if (mouseIsInBox(createBox(removePos[u].first, removePos[u].second, removePos[u].first+64, removePos[u].second+63)) && Raylib::Mouse::isButtonPressed(0)) {
            _allIntegers[2] -= 1;
            if (_playerTab[u+1]) {
                _controlsTab.erase(_controlsTab.begin() + u + 1);
                _letterAndFrame.erase(_letterAndFrame.begin() + u + 1);
                _userNames.erase(_userNames.begin() + u + 1);
            }
            _playerTab.erase(_playerTab.begin() + u + 1);
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
    }
}

void XRay::manageNextOrPrev(std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab)
{
    if (Raylib::Mouse::isButtonPressed(0))
        for (size_t u = 0; u < nextTab.size(); u++) {
            _playerTab[u] = (mouseIsInBox(createBox(nextTab[u].first, nextTab[u].second, nextTab[u].first+50, nextTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _playerTab[u] = (mouseIsInBox(createBox(prevTab[u].first, prevTab[u].second, prevTab[u].first+50, prevTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(nextTab[u].first + 20, nextTab[u].second + 340, nextTab[u].first+70, nextTab[u].second+389)) && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(prevTab[u].first - 20, prevTab[u].second + 340, prevTab[u].first + 20, prevTab[u].second+389))  && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
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
                if (((_letterAndFrame[p].second/20)%2) == 0)
                    Raylib::Text::drawText("_", textBox[p].getCStruct().x + 8 + Raylib::Text::measureText(_userNames[p].c_str(), 40), textBox[p].getCStruct().y + 12, 40, Raylib::Color::Maroon());
        }
    }
}

void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, int *a)
{
    int i, b;
    for (i = 0, (*a) = 200, b = 300; _allIntegers[2] < 5 && i < _allIntegers[2]; i++, (*a) += 400) {
        _resources.at(PREVIOUS)->drawTexture((*a)-54, _allIntegers[1], Raylib::Color::White());
        if (_playerTab[i]) {
            (_controlsTab[i]) ? _resources.at(CONTROLS)->drawTexture((*a) - 30, _allIntegers[1] + 300, Raylib::Color::White()) : _resources.at(GAMEPAD)->drawTexture((*a) - 30, _allIntegers[1] + 300, Raylib::Color::White());
            _resources.at(PREVIOUS)->drawTexture((*a)-84, _allIntegers[1] + 340, Raylib::Color::White());
            _resources.at(NEXT)->drawTexture((*a)+250, _allIntegers[1] + 340, Raylib::Color::White());
        }
        (_playerTab[i]) ? _resources.at(HUMAN)->drawTexture((*a), b, Raylib::Color::White()) : _resources.at(AI)->drawTexture((*a), b, Raylib::Color::White());
        _resources.at(NEXT)->drawTexture((*a)+230, _allIntegers[1], Raylib::Color::White());
        nextTab.push_back(std::make_pair((*a)+230, _allIntegers[1]));
        prevTab.push_back(std::make_pair((*a)-54, _allIntegers[1]));
        if (i != 0) {
            removePos.push_back(std::make_pair((*a)+240, _allIntegers[1]-100));
            _resources.at(REMOVE)->drawTexture((*a) + 240, _allIntegers[1]-100, Raylib::Color::White());
        }
    }
    if (_allIntegers[2] != 4)
        _resources.at(ADD)->drawTexture(_allIntegers[0] + (*a), _allIntegers[1], Raylib::Color::White());
}

void XRay::displayPlayerChoiceScene(void)// TODO doc
{
    _scene = PLAYER_CHOICE;

    std::vector<std::pair<int, int>> removePos;
    std::vector<std::pair<int, int>> nextTab;
    std::vector<std::pair<int, int>> prevTab;

    std::vector<bool> mouseOnText;
    std::vector<Raylib::Rectangle> textBox;

    int a;

    setTextBox(mouseOnText, textBox);
    updateTextBox(mouseOnText, textBox);

    beginDrawing();
    displayBoxes(mouseOnText, textBox);
    displayCardsSettings(removePos, nextTab, prevTab, &a);
    displayMouse();
    endDrawing();

    addPlayer(mouseOnText, textBox);
    manageNextOrPrev(nextTab, prevTab);
    removePlayer(removePos, mouseOnText, textBox);
}