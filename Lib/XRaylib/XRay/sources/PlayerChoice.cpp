/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerChoice
*/

#include "XRay.hpp"


void XRay::setTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> &textBox) // TODO: To change ?
{
    for (size_t p = 0, a = 200; p < 4; p++, a += 400) {
        _letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        if (p < _allIntegers[2])
            textBox.push_back({ (float)a, 180, 225, 50 });
    }
}

void XRay::updateTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox) // TODO: To change ? // Remmove good player 
{
    for (size_t i = 0; i < mouseOnText.size(); i++) {
        mouseOnText[i] = (::CheckCollisionPointRec({(float)Raylib::Mouse::getMouseX(), (float)Raylib::Mouse::getMouseY()}, textBox[i])) ? true : false;
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

void XRay::setAddBox(const std::vector<std::pair<int, int>> &removePos, const std::vector<std::pair<int, int>> &nextTab, const std::vector<std::pair<int, int>> &prevTab, const int &a)// TODO: To change ?
{
    _allIntegers[2] += (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && Raylib::Mouse::isButtonPressed(0)) ? 1 : 0;
    if (Raylib::Mouse::isButtonPressed(0))
        for (size_t u = 0; u < nextTab.size(); u++) {
            _playerTab[u] = (mouseIsInBox(createBox(nextTab[u].first, nextTab[u].second, nextTab[u].first+50, nextTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _playerTab[u] = (mouseIsInBox(createBox(prevTab[u].first, prevTab[u].second, prevTab[u].first+50, prevTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(nextTab[u].first + 20, nextTab[u].second + 340, nextTab[u].first+70, nextTab[u].second+389)) && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(prevTab[u].first - 20, prevTab[u].second + 340, prevTab[u].first + 20, prevTab[u].second+389))  && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
        }
    for (size_t u = 0; u < removePos.size(); u++) {
        _allIntegers[2] -= mouseIsInBox(createBox(removePos[u].first, removePos[u].second, removePos[u].first+64, removePos[u].second+63)) && Raylib::Mouse::isButtonPressed(0) ? 1 : 0;
    }
}

void XRay::displayCards(const std::vector<bool> &mouseOnText, const std::vector<::Rectangle> &textBox)// TODO: To change ?
{
    Raylib::Text text;
    for (size_t p = 0; p < _allIntegers[2]; p++) {
        if (_playerTab[p]) {
            ::DrawRectangleRec(textBox[p], Raylib::Color::LightGray().getCStruct());
            (mouseOnText[p]) ? ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::Red().getCStruct()) : ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::DarkGray().getCStruct());
            ::DrawText(_userNames[p].c_str(), textBox[p].x + 5, textBox[p].y + 8, 40, Raylib::Color::Maroon().getCStruct());

            if (mouseOnText[p] && _letterAndFrame[p].first < 9)
                if (((_letterAndFrame[p].second/20)%2) == 0)
                    text.drawText("_", textBox[p].x + 8 + text.measureText(_userNames[p].c_str(), 40), textBox[p].y + 12, 40, Raylib::Color::Maroon());
        }
    }
}


void XRay::displayCardsSettings(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, int *a)// TODO: To change ?
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

void XRay::displayPlayerChoiceScene(void) // TODO: To change ?
{
    _scene = PLAYER_CHOICE;

    std::vector<std::pair<int, int>> removePos;
    std::vector<std::pair<int, int>> nextTab;
    std::vector<std::pair<int, int>> prevTab;

    std::vector<bool> mouseOnText;
    std::vector<::Rectangle> textBox;


    int a;

    setTextBox(mouseOnText, textBox);
    updateTextBox(mouseOnText, textBox);

    beginDrawing();
    displayCards(mouseOnText, textBox);
    displayCardsSettings(removePos, nextTab, prevTab, &a);
    displayMouse();
    endDrawing();

    setAddBox(removePos, nextTab, prevTab, a);
}