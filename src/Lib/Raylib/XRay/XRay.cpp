/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#include "XRay.hpp"

Raylib::XRay::XRay()
    : _window(1920, 1080, "Bomberman")
{
    Timing timing;

    timing.setTargetFPS(60);
    _scenesFunc.push_back(&Raylib::XRay::displayMenu);
    _intro = std::make_pair(true, &Raylib::XRay::displayIntro);
}

Raylib::XRay::~XRay()
{
}

void Raylib::XRay::displayIntro(void) // TODO: To change ?
{
    Text text;
    Timing timing;

    _scene = INTRO;
    for (int f = 0, x = 0, y = 0; timing.getTime() < 8.5f; f += 2) {
        x = -10 + f;
        y = 1600 - f;
        beginDrawing();
        text.drawTextEx("resources/fonts/sega.ttf", "INDIE", std::make_pair(y, 1080 / 2 - 100), 100, 1, Color::DarkBlue());
        text.drawTextEx("resources/fonts/sega.ttf", "STUDIO", std::make_pair(x, 1080 / 2 - 100), 100, 1, Color::DarkBlue());
        endDrawing();
    }
    while (timing.getTime() < 10);
    _intro.first = false;
}

void Raylib::XRay::displayMenu(void) // TODO: To change ?
{
    Texture head(Image("resources/assets/head.png"));
    Texture title(Image("resources/assets/title.png"));
    Cursor cursor;
    Mouse mouse;

    if (_intro.first == true)
        (this->*_intro.second)();
    _scene = MAIN_MENU;
    if (cursor.isCursorOnScreen())
        cursor.hideCursor();
    beginDrawing();
    head.drawTexture(mouse.getMouseX() - 32, mouse.getMouseY() - 32, Color::White());
    title.drawTexture(1920 / 4, 40, Color::White());
    endDrawing();
}
