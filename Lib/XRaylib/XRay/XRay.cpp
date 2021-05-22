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
    Raylib::Timing timing;

    timing.setTargetFPS(120);
    _scenesFunc.push_back(&XRay::displayMenu);
    _intro = std::make_pair(true, &XRay::displayTrace);
}

XRay::~XRay()
{
}

bool XRay::mouseIsInBox(double x, double y, double x_x, double y_y) TODO: To change ?
{
    Raylib::Mouse mouse;

    double m_x = mouse.getMouseX(), m_y = mouse.getMouseY();
    if (x < m_x && m_x < x_x && y < m_y && m_y < y_y)
        return true;
    return false;
}

void XRay::displayTrace(void) // TODO: To change ?
{
    Raylib::Text text;
    Raylib::Timing timing;
    Raylib::Drawing drawing;
    Raylib::Texture indie(Raylib::Image("resources/assets/indieTitle.png"));
    Raylib::Texture studio(Raylib::Image("resources/assets/studioTitle.png"));

    _scene = INTRO;
    for (int f = 0, x = 0, y = 0; timing.getTime() < 5.4f; f += 1) {
        x = -100 + f;
        y = 1500 - f;
        beginDrawing();
        drawing.clearBackground(Raylib::Color::White());
        indie.drawTexture(x, 1080 / 2 - 100, Raylib::Color::White());
        studio.drawTexture(y, 1080 / 2 - 100, Raylib::Color::White());
        endDrawing();
    }
    while (timing.getTime() < 7.5f);
    _intro.first = false;
    displayIntro();
}

void XRay::displayIntro(void) // TODO: To change ?
{
    Raylib::Timing timing;
    Raylib::Mouse mouse;
    std::string path;
    int i = 1;

    for (std::string str = "001"; str != "321";) {
        path = "resources/cinematic/Intro/ezgif-frame-" + str + ".png";
        std::string skip = "resources/assets/";
        skip += (mouseIsInBox(1760, 950, 1883, 1005) == true) ? "sskip.png" : "skiip.png";
        Raylib::Texture frame(Raylib::Image(path.c_str()));
        Raylib::Texture skipButton(Raylib::Image(skip.c_str()));

        beginDrawing();
        frame.drawTexture(0, 0, Raylib::Color::White());
        skipButton.drawTexture(1760, 950, Raylib::Color::White());
        endDrawing();

        i++;
        str = (i < 100) ? ((i < 10) ? "00" + std::to_string(i) : "0" + std::to_string(i)) : std::to_string(i);
        if (mouse.isButtonPressed(0))
            break;
    }
}

void XRay::displayMenu(void) // TODO: To change ?
{
    Raylib::Texture head(Raylib::Image("resources/assets/head.png"));
    Raylib::Texture title(Raylib::Image("resources/assets/title.png"));
    Raylib::Cursor cursor;
    Raylib::Mouse mouse;

    if (_intro.first == true)
        (this->*_intro.second)();
//    _scene = MAIN_MENU;
    if (cursor.isCursorOnScreen())
        cursor.hideCursor();
    beginDrawing();
    title.drawTexture(1920 / 4, 40, Raylib::Color::White());
    head.drawTexture(mouse.getMouseX() - 32, mouse.getMouseY() - 32, Raylib::Color::White());
    endDrawing();
}
