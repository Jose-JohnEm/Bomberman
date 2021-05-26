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
//    ::InitAudioDevice();
//    timing.setTargetFPS(60);
    _scenesFunc.push_back(&XRay::displayMenu);
    _scenesFunc.push_back(&XRay::playMenu);
    _scenesFunc.push_back(&XRay::howToMenu);
    _scenesFunc.push_back(&XRay::settingsMenu);
    _scenesFunc.push_back(&XRay::modeScene);
    _scenesFunc.push_back(&XRay::mapScene);
    _scenesFunc.push_back(&XRay::loadGameScene);
    _scenesFunc.push_back(&XRay::quit);

    // Intro settings
    _intro = std::make_pair(true, &XRay::displayStudio);
}

XRay::~XRay()
{
}

bool XRay::mouseIsInBox(double x, double y, double x_x, double y_y)
{
    Raylib::Mouse mouse;

    double m_x = mouse.getMouseX(), m_y = mouse.getMouseY();
    if (x < m_x && m_x < x_x && y < m_y && m_y < y_y)
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
    _scene = MAPMENU;
    beginDrawing();
    // Some code
    endDrawing();
}

void XRay::modeScene(void) // TODO: To change ?
{
    // TODO: Put our encapsulation and Try to split function (Already did, but x_x)
    int i, a, b;
    static std::vector<std::pair<int, int>> letterAndFrame;

    Raylib::Texture player(Raylib::Image("resources/assets/player.png"));
    Raylib::Texture ia(Raylib::Image("resources/assets/playerr.png"));
    Raylib::Texture add(Raylib::Image("resources/assets/add.png"));
    Raylib::Texture remove(Raylib::Image("resources/assets/minus.png"));
    Raylib::Texture next(Raylib::Image("resources/assets/next.png"));
    Raylib::Texture prev(Raylib::Image("resources/assets/prev.png"));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));
    Raylib::Texture controls(Raylib::Image("resources/assets/X.png"));
    Raylib::Texture gamepad(Raylib::Image("resources/assets/gamepad.png"));
    Raylib::Text text;

    std::vector<std::pair<int, int>> removePos;
    std::vector<std::pair<int, int>> nextTab;
    std::vector<std::pair<int, int>> prevTab;

    std::vector<::Rectangle> textBox;
    std::vector<bool> mouseOnText;

    _scene = MODEMENU;

    for (size_t p = 0, a = 200; p < 4; p++, a += 400) {
        letterAndFrame.push_back(std::make_pair(0, 0));
        _userNames.push_back("");
        mouseOnText.push_back(false);
        if (p < allIntegers[2])
            textBox.push_back({ (float)a, 180, 225, 50 });
    }

    for (size_t p = 0; p < 4; p++) {
        mouseOnText[p] = (::CheckCollisionPointRec({(float)_mouse.getMouseX(), (float)_mouse.getMouseY()}, textBox[p])) ? true : false;
        if (mouseOnText[p]) {
            _mouse.setMouseCursor(MOUSE_CURSOR_IBEAM);

            for (int key = _keyboard.getCharPressed(); key > 0; key = _keyboard.getCharPressed())
                if ((key >= 32) && (key <= 125) && (letterAndFrame[p].first < 9)) {
                    _userNames[p][letterAndFrame[p].first] = (char)key;
                    letterAndFrame[p].first++;
                }

            if (_keyboard.isKeyPressed(KEY_BACKSPACE)) {
                letterAndFrame[p].first--;
                letterAndFrame[p].first = (letterAndFrame[p].first < 0) ? 0 : letterAndFrame[p].first;
                _userNames[p][letterAndFrame[p].first] = '\0';
            }
        } else
            _mouse.setMouseCursor(MOUSE_CURSOR_DEFAULT);

        letterAndFrame[p].second = (mouseOnText[p]) ? letterAndFrame[p].second+1 : 0;
    }

    beginDrawing();
    for (i = 0, a = 200, b = 300; allIntegers[2] < 5 && i < allIntegers[2]; i++, a += 400) {
        prev.drawTexture(a-54, allIntegers[1], Raylib::Color::White());
        if (playerTab[i]) {
            (controlsTab[i]) ? controls.drawTexture(a - 30, allIntegers[1] + 300, Raylib::Color::White()) : gamepad.drawTexture(a - 30, allIntegers[1] + 300, Raylib::Color::White());
            prev.drawTexture(a-84, allIntegers[1] + 340, Raylib::Color::White());
            next.drawTexture(a+250, allIntegers[1] + 340, Raylib::Color::White());
        }
        (playerTab[i]) ? player.drawTexture(a, b, Raylib::Color::White()) : ia.drawTexture(a, b, Raylib::Color::White());
        next.drawTexture(a+230, allIntegers[1], Raylib::Color::White());
        nextTab.push_back(std::make_pair(a+230, allIntegers[1]));
        prevTab.push_back(std::make_pair(a-54, allIntegers[1]));
        if (i != 0) {
            removePos.push_back(std::make_pair(a+240, allIntegers[1]-100));
            remove.drawTexture(a + 240, allIntegers[1]-100, Raylib::Color::White());
        }
    }
    if (allIntegers[2] != 4)
        add.drawTexture(allIntegers[0] + a, allIntegers[1], Raylib::Color::White());

    for (size_t p = 0; p < allIntegers[2]; p++) {
        if (playerTab[p]) {
            ::DrawRectangleRec(textBox[p], Raylib::Color::LightGray().getCStruct());
            (mouseOnText[p]) ? ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::Red().getCStruct()) : ::DrawRectangleLines(textBox[p].x, textBox[p].y, textBox[p].width, textBox[p].height, Raylib::Color::DarkGray().getCStruct());
            ::DrawText(_userNames[p].c_str(), textBox[p].x + 5, textBox[p].y + 8, 40, Raylib::Color::Maroon().getCStruct());

            if (mouseOnText[p] && letterAndFrame[p].first < 9)
                if (((letterAndFrame[p].second/20)%2) == 0)
                    text.drawText("_", textBox[p].x + 8 + text.measureText(_userNames[p].c_str(), 40), textBox[p].y + 12, 40, Raylib::Color::Maroon());
        }
    }

    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    allIntegers[2] += (allIntegers[2] != 4 && mouseIsInBox(allIntegers[0]+a, allIntegers[1], allIntegers[0]+a+150, allIntegers[1]+150) && _mouse.isButtonPressed(0)) ? 1 : 0;
    if (_mouse.isButtonPressed(0))
        for (size_t u = 0; u < nextTab.size(); u++) {
            playerTab[u] = (mouseIsInBox(nextTab[u].first, nextTab[u].second, nextTab[u].first+50, nextTab[u].second+49)) ? !playerTab[u] : playerTab[u];
            playerTab[u] = (mouseIsInBox(prevTab[u].first, prevTab[u].second, prevTab[u].first+50, prevTab[u].second+49)) ? !playerTab[u] : playerTab[u];
            controlsTab[u] = (mouseIsInBox(nextTab[u].first + 20, nextTab[u].second + 340, nextTab[u].first+70, nextTab[u].second+389) && playerTab[u]) ? !controlsTab[u] : controlsTab[u];
            controlsTab[u] = (mouseIsInBox(prevTab[u].first - 20, prevTab[u].second + 340, prevTab[u].first + 20, prevTab[u].second+389)  && playerTab[u]) ? !controlsTab[u] : controlsTab[u];
        }
    for (size_t u = 0; u < removePos.size(); u++)
        allIntegers[2] -= (mouseIsInBox(createBox(removePos[u].first, removePos[u].second, removePos[u].first+64, removePos[u].second+63)) && _mouse.isButtonPressed(0)) ? 1 : 0;
//    mapScene();
}

void XRay::loadGameScene(void) // TODO: To change ?
{
    Raylib::Texture load(Raylib::Image("resources/assets/loadscene.png"));
    Raylib::Texture branch(Raylib::Image("resources/assets/branch.png"));
    Raylib::Text file;

    _scene = LOADMENU;
    beginDrawing();
    load.drawTexture(0, 0, Raylib::Color::White());
    file.drawText("BACKUPS", 230, 210, 65, Raylib::Color::Black());
    for (size_t i = 0, y = 300; i < _backups.size(); i++, y += 100) {
        branch.drawTexture(150, y, Raylib::Color::White());
        file.drawText(_backups[i].substr(0, _backups[i].find('.')), 300, y + 20, 65, Raylib::Color::Black());
    }
    endDrawing();
}

void XRay::playMenu(void) // TODO: To change ?
{
    std::string back = std::string("resources/assets/") + std::string((mouseIsInBox(250, 900, 510, 965)) ? "BACK.png" : "back.png");
    std::string newgame = std::string("resources/assets/") + std::string((mouseIsInBox(180, 500, 700, 565)) ? "NEWGAME.png" : "newgame.png");
    std::string loadgame = std::string("resources/assets/") + std::string((mouseIsInBox(1140, 500, 1660, 565)) ? "LOADGAME.png" : "loadgame.png");

    Raylib::Texture ngame(Raylib::Image("resources/assets/nga.png"));
    Raylib::Texture lgame(Raylib::Image("resources/assets/lga.png"));
    Raylib::Texture backButton(Raylib::Image(back.c_str()));
    Raylib::Texture newGameButton(Raylib::Image(newgame.c_str()));
    Raylib::Texture loadGameButton(Raylib::Image(loadgame.c_str()));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));

    _scene = PLAYMENU;
    beginDrawing();
    ngame.drawTexture(0, 0, Raylib::Color::White());
    lgame.drawTexture(960, 0, Raylib::Color::White());
    backButton.drawTexture(250, 900, Raylib::Color::White());
    newGameButton.drawTexture(180, 500, Raylib::Color::White());
    loadGameButton.drawTexture(1140, 500, Raylib::Color::White());
    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    if (back.at(17) < 90 && _mouse.isButtonPressed(0))
        displayMenu();
    else if (newgame.at(17) < 90 && _mouse.isButtonPressed(0))
        modeScene();
    else if (loadgame.at(17) < 90 && _mouse.isButtonPressed(0))
        loadGameScene();
}

void XRay::howToMenu(void) // TODO: To change ?
{
    std::string howto = std::string("resources/assets/") + std::string((mouseIsInBox(700, 600, 815, 665)) ? "HOWTO.png" : "howto.png");
    std::string back = std::string("resources/assets/") + std::string((mouseIsInBox(20, 1000, 280, 1065)) ? "BACK.png" : "back.png");

    Raylib::Texture button(Raylib::Image(howto.c_str()));
    Raylib::Texture backButton(Raylib::Image(back.c_str()));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));

    _scene = HOWTOMENU;
    beginDrawing();
    button.drawTexture(700, 600, Raylib::Color::White());
    backButton.drawTexture(20, 1000, Raylib::Color::White());
    head.drawTexture(_mouse.getMouseX() - 32, _mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();

    if (back.at(17) < 90 && _mouse.isButtonPressed(0))
        displayMenu();
}

void XRay::settingsMenu(void) // TODO: To change ?
{
    std::string settings = std::string("resources/assets/") + std::string((mouseIsInBox(700, 700, 620, 765)) ? "SETTINGS.png" : "settings.png");
    std::string back = std::string("resources/assets/") + std::string((mouseIsInBox(20, 1000, 280, 1065)) ? "BACK.png" : "back.png");

    Raylib::Texture settingsButton(Raylib::Image(settings.c_str()));
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));
    Raylib::Texture backButton(Raylib::Image(back.c_str()));

    _scene = SETTINGSMENU;
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
    _scene = MAIN_MENU;
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
