/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"

XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    // Set resources
    setResources();

    // Scenes
    _scenesFunc.push_back(&XRay::displayMenu);
    _scenesFunc.push_back(&XRay::displayGameModeScene);
    _scenesFunc.push_back(&XRay::howToMenu);
    _scenesFunc.push_back(&XRay::displaySettingsScene);
    _scenesFunc.push_back(&XRay::displayPlayerChoiceScene);
    _scenesFunc.push_back(&XRay::mapScene);
    _scenesFunc.push_back(&XRay::displayLoadGameScene);
    _scenesFunc.push_back(&XRay::quit);

    // Intro settings
    _intro = std::make_pair(true, &XRay::displayStudio);
}

XRay::~XRay()
{
}

void XRay::setResources(void)
{
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(ADD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/add.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(REMOVE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/remove.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(PREVIOUS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/previous.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(NEXT, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/next.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(CONTROLS, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/controls.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(GAMEPAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/gamepad.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(HUMAN, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/human.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(AI, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/ai.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(HEAD, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/head.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(LOADGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(LOADGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(LOADGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadGameHover.png"))));
    _resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(NEWGAME, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGame.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(NEWGAME_BG, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameBG.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(NEWGAME_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/newGameHover.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(LOADSCENE, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/loadScene.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(BRANCH, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/branch.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(BACK, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/back.png"))));
	_resources.insert(std::pair<Resources, std::shared_ptr<Raylib::Texture>>(BACK_HOVER, std::make_shared<Raylib::Texture>(Raylib::Image("resources/assets/backHover.png"))));

}

bool XRay::mouseIsInBox(const std::vector<size_t> &box) const
{
    Raylib::Mouse mouse;

    if (box[UPPER_LEFT] <= mousePosition.first && mousePosition.first <= box[LOW_RIGHT]
    && box[LOW_LEFT] <= mousePosition.second && mousePosition.second <= box[UPPER_RIGHT])
        return true;
    return false;
}

std::vector<size_t> XRay::createBox(const size_t &upperLeftCorner, const size_t &upperRightCorner, const size_t &lowerLeftCorner, const size_t &lowerRightCorner) const
{
    std::vector<size_t> box;

    box.reserve(4);
    box.push_back(upperLeftCorner);
    box.push_back(upperRightCorner);
    box.push_back(lowerLeftCorner);
    box.push_back(lowerRightCorner);
    return box;
}

void XRay::mapScene(void)
{
    _scene = IN_GAME;
    beginDrawing();
    // Some code
    endDrawing();
}

void XRay::setTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> &textBox)
{
    for (size_t p = 0, a = 200; p < 4; p++, a += 400) {
        _letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        if (p < _allIntegers[2])
            textBox.push_back({ (float)a, 180, 225, 50 });
    }
}

void XRay::updateTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox)
{
    for (size_t i = 0; i < mouseOnText.size(); i++) {
        mouseOnText[i] = (::CheckCollisionPointRec({(float)_mouse.getMouseX(), (float)_mouse.getMouseY()}, textBox[i])) ? true : false;
        if (mouseOnText[i]) {
            _mouse.setMouseCursor(MOUSE_CURSOR_IBEAM);

            for (int key = _keyboard.getCharPressed(); key > 0; key = _keyboard.getCharPressed())
                if ((key >= 32) && (key <= 125) && (_letterAndFrame[i].first < 9)) {
                    _userNames[i].push_back(key);
                    _letterAndFrame[i].first++;
                }

            if (_keyboard.isKeyPressed(KEY_BACKSPACE) && _userNames[i].size() > 0) {
                _letterAndFrame[i].first--;
                if (_letterAndFrame[i].first < 0)
                    _letterAndFrame[i].first = 0;
                else
                    _userNames[i].pop_back();
            }

        } else
            _mouse.setMouseCursor(MOUSE_CURSOR_DEFAULT);

        _letterAndFrame[i].second = (mouseOnText[i]) ? _letterAndFrame[i].second+1 : 0;
    }
}

void XRay::setAddBox(const std::vector<std::pair<int, int>> &removePos, const std::vector<std::pair<int, int>> &nextTab, const std::vector<std::pair<int, int>> &prevTab, const int &a)
{
    _allIntegers[2] += (_allIntegers[2] != 4 && mouseIsInBox(createBox(_allIntegers[0]+a, _allIntegers[1], _allIntegers[0]+a+150, _allIntegers[1]+150)) && _mouse.isButtonPressed(0)) ? 1 : 0;
    if (_mouse.isButtonPressed(0))
        for (size_t u = 0; u < nextTab.size(); u++) {
            _playerTab[u] = (mouseIsInBox(createBox(nextTab[u].first, nextTab[u].second, nextTab[u].first+50, nextTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _playerTab[u] = (mouseIsInBox(createBox(prevTab[u].first, prevTab[u].second, prevTab[u].first+50, prevTab[u].second+49))) ? !_playerTab[u] : _playerTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(nextTab[u].first + 20, nextTab[u].second + 340, nextTab[u].first+70, nextTab[u].second+389)) && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
            _controlsTab[u] = (mouseIsInBox(createBox(prevTab[u].first - 20, prevTab[u].second + 340, prevTab[u].first + 20, prevTab[u].second+389))  && _playerTab[u]) ? !_controlsTab[u] : _controlsTab[u];
        }
    for (size_t u = 0; u < removePos.size(); u++) {
        _allIntegers[2] -= mouseIsInBox(createBox(removePos[u].first, removePos[u].second, removePos[u].first+64, removePos[u].second+63)) && _mouse.isButtonPressed(0) ? 1 : 0;
    }
}

void XRay::displayCards(const std::vector<bool> &mouseOnText, const std::vector<::Rectangle> &textBox)
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

void XRay::displayMouse(void)
{
    _resources.at(HEAD)->drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
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

void XRay::displayPlayerChoiceScene(void) // TODO: To change ?
{
    // TODO: Put our encapsulation and Try to split function (Already did, but x_x)
    //Raylib::Texture head(Raylib::Image("resources/assets/head.png"));

    std::vector<std::pair<int, int>> removePos;
    std::vector<std::pair<int, int>> nextTab;
    std::vector<std::pair<int, int>> prevTab;

    std::vector<bool> mouseOnText;
    std::vector<::Rectangle> textBox;

    _scene = PLAYER_CHOICE;

    int a;

    setTextBox(mouseOnText, textBox);

    updateTextBox(mouseOnText, textBox);

    beginDrawing();

    displayCardsSettings(removePos, nextTab, prevTab, &a);
    displayCards(mouseOnText, textBox);
    displayMouse();
    endDrawing();

    setAddBox(removePos, nextTab, prevTab, a);

//    mapScene();
}

void XRay::displayLoadGameScene(void) // TODO: To change ?
{
    Raylib::Text file;

    _scene = LOAD_GAME;
    beginDrawing();
    _resources.at(LOADSCENE)->drawTexture(0, 0, Raylib::Color::White());
    file.drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (size_t i = 0, y = 300; i < _backups.size(); i++, y += 100) {
        _resources.at(BRANCH)->drawTexture(150, y, Raylib::Color::White());
        file.drawText(_backups[i].substr(0, _backups[i].find('.')), 300, y + 20, 65, Raylib::Color::Black());
    }
    endDrawing();
}
//TODO: pointer to function between drawing method
void XRay::displayGameModeScene(void) // TODO: To change ?
{
    // Set scene
    _scene = GAME_MODE;

    // Check if mouse is on button spot
    bool goBack = mouseIsInBox(createBox(250, 900, 510, 965)) ? true : false;
    bool goNewGame = mouseIsInBox(createBox(180, 500, 700, 565)) ? true : false;
    bool goLoadGame = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? true : false;

    // Set specific texture according to mouse position
    std::shared_ptr<Raylib::Texture> backButton = mouseIsInBox(createBox(250, 900, 510, 965)) ? _resources.at(BACK_HOVER) : _resources.at(BACK);
    std::shared_ptr<Raylib::Texture> newGameButton = mouseIsInBox(createBox(180, 500, 700, 565)) ? _resources.at(NEWGAME_HOVER) : _resources.at(NEWGAME);
    std::shared_ptr<Raylib::Texture> loadGameButton = mouseIsInBox(createBox(1140, 500, 1660, 565)) ? _resources.at(LOADGAME_HOVER) : _resources.at(LOADGAME);

    // Draw scene
    beginDrawing();
    _resources.at(NEWGAME_BG)->drawTexture(0, 0, Raylib::Color::White());
    _resources.at(LOADGAME_BG)->drawTexture(960, 0, Raylib::Color::White());
    backButton->drawTexture(250, 900, Raylib::Color::White());
    newGameButton->drawTexture(180, 500, Raylib::Color::White());
    loadGameButton->drawTexture(1140, 500, Raylib::Color::White());
    displayMouse();
    endDrawing();

    // Go to another scene according to mouse position
    if (goBack && _mouse.isButtonPressed(0))
        displayMenu();
    else if (goNewGame && _mouse.isButtonPressed(0))
        displayPlayerChoiceScene();
    else if (goLoadGame && _mouse.isButtonPressed(0))
        displayLoadGameScene();
}

void XRay::howToMenu(void) // TODO: To change ?
{
    std::string howto = std::string("resources/assets/") + std::string((mouseIsInBox(700, 600, 815, 665)) ? "HOWTO.png" : "howto.png");
    std::string back = std::string("resources/assets/") + std::string((mouseIsInBox(20, 1000, 280, 1065)) ? "BACK.png" : "back.png");

    Raylib::Texture button(Raylib::Image(howto.c_str()));
    Raylib::Texture backButton(Raylib::Image(back.c_str()));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));

    _scene = HOW_TO_PLAY;
    beginDrawing();
    button.drawTexture(700, 600, Raylib::Color::White());
    backButton.drawTexture(20, 1000, Raylib::Color::White());
    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    if (back.at(17) < 90 && _mouse.isButtonPressed(0))
        displayMenu();
}

void XRay::displaySettingsScene(void) // TODO: To change ?
{
    std::string settings = std::string("resources/assets/") + std::string((mouseIsInBox(700, 700, 620, 765)) ? "SETTINGS.png" : "settings.png");
    std::string back = std::string("resources/assets/") + std::string((mouseIsInBox(20, 1000, 280, 1065)) ? "BACK.png" : "back.png");

    Raylib::Texture settingsButton(Raylib::Image(settings.c_str()));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));
    Raylib::Texture backButton(Raylib::Image(back.c_str()));

    _scene = SETTINGS;
    beginDrawing();
    settingsButton.drawTexture(700, 600, Raylib::Color::White());
    backButton.drawTexture(20, 1000, Raylib::Color::White());
    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    if (back.at(17) < 90 && _mouse.isButtonPressed(0))
        displayMenu();
}

void XRay::quit(void) // TODO: To change ?
{
    _scene = END_GAME;
}

void XRay::displayStudio(void) // TODO: To change ?
{
    Raylib::Text text;
    Raylib::Timing timing;
    Raylib::Texture indie(Raylib::Image("resources/assets/indieTitle.png"));
    Raylib::Texture studio(Raylib::Image("resources/assets/studioTitle.png"));

    beginDrawing();
    indie.drawTexture(500, 1080 / 2 - 100, Raylib::Color::White());
    studio.drawTexture(900, 1080 / 2 - 100, Raylib::Color::White());
    endDrawing();
    for (double t = timing.getTime(); timing.getTime() - t < 2;);
    _intro.first = false;
//    displayIntro();
}

void XRay::displayIntro(void) // TODO: To change ?
{
    std::string path, skip, str = "1";

    for (int i = 1; str != "2326" && !(i < 2300 && _mouse.isButtonPressed(0) && mouseIsInBox(1760, 950, 1883, 1005));) {
        path = "resources/cinematic/data/frame" + str + ".png";
        skip = std::string("resources/assets/") + std::string((mouseIsInBox(1760, 950, 1883, 1005)) ? "sskip.png" : "skip.png");
        Raylib::Texture frame(Raylib::Image(path.c_str()));
        Raylib::Texture skipButton(Raylib::Image(skip.c_str()));

        beginDrawing();
        frame.drawTexture(0, 0, Raylib::Color::White());
        if (i < 2300)
            skipButton.drawTexture(1760, 950, Raylib::Color::White());
        endDrawing();

        i++;
        str = std::to_string(i);
    }
}

void XRay::displayMenu(void) // TODO: To change ?
{
    // TODO: Faire un vector de Texture et display dans une boucle plus clean (J'ai essayé ça a pas marché)

    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));
    Raylib::Texture title(Raylib::Image("resources/assets/Title.png"));
    Raylib::Texture man(Raylib::Image("resources/assets/bomb.png"));
    Raylib::Texture team(Raylib::Image("resources/assets/men.png"));

//    Raylib::Music music("resources/assets/aa.mp3");
    std::vector<std::string> _menuButtons;
    _menuButtons.push_back(std::string("resources/assets/") + std::string((mouseIsInBox(100, 500, 360, 565)) ? "PLAY.png" : "play.png"));
    Raylib::Texture playButton(Raylib::Image(_menuButtons[0].c_str()));
    _menuButtons.push_back(std::string("resources/assets/") + std::string((mouseIsInBox(100, 600, 815, 665)) ? "HOWTO.png" : "howto.png"));
    Raylib::Texture howtoButton(Raylib::Image(_menuButtons[1].c_str()));
    _menuButtons.push_back(std::string("resources/assets/") + std::string((mouseIsInBox(100, 700, 620, 765)) ? "SETTINGS.png" : "settings.png"));
    Raylib::Texture settingsButton(Raylib::Image(_menuButtons[2].c_str()));
    _menuButtons.push_back(std::string("resources/assets/") + std::string((mouseIsInBox(100, 800, 360, 865)) ? "QUIT.png" : "quit.png"));
    Raylib::Texture quitButton(Raylib::Image(_menuButtons[3].c_str()));

//    LoadMusicStream("resources/assets/aa.mp3");
//    PlayMusicStream(LoadMusicStream("resources/assets/aa.mp3"));
    if (_intro.first == true)
        (this->*_intro.second)();
    _scene = MENU;
//    ::UpdateMusicStream(music);
    if (_cursor.isCursorOnScreen())
        _cursor.hideCursor();
//    if (!music.isPlaying())
//        music.playMusic();
    beginDrawing();
    team.drawTexture(1420, 600, Raylib::Color::White());
    man.drawTexture(1920 / 4 - 80, 130, Raylib::Color::White());
    playButton.drawTexture(100, 500, Raylib::Color::White());
    howtoButton.drawTexture(100, 600, Raylib::Color::White());
    settingsButton.drawTexture(100, 700, Raylib::Color::White());
    quitButton.drawTexture(100, 800, Raylib::Color::White());
    title.drawTexture(1920 / 4 + 100, 40, Raylib::Color::White());
    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    for (size_t i = 0; i < _menuButtons.size() - 1; i++) {
        if (_menuButtons[3].at(17) < 90 && _mouse.isButtonPressed(0))
            quit();
        else if (_menuButtons[i].at(17) < 90 && _mouse.isButtonPressed(0))
            (this->*_scenesFunc[i + 1])();
    }
}
