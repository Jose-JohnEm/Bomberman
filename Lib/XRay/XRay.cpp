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
    _intro = std::make_pair(true, &XRay::displayIntro);
}

XRay::~XRay()
{
}

void XRay::displayIntro(void) // TODO: To change ?
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
        studio.drawTexture(y, 1080 / 2 - 100, Raylib::Color::White());
        indie.drawTexture(x, 1080 / 2 - 100, Raylib::Color::White());
        endDrawing();
    }
    while (timing.getTime() < 7.5f);
    _intro.first = false;
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
    head.drawTexture(mouse.getMouseX() - 32, mouse.getMouseY() - 32, Raylib::Color::White());
    title.drawTexture(1920 / 4, 40, Raylib::Color::White());
    endDrawing();
}
