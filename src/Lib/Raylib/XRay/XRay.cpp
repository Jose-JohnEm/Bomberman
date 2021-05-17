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

    timing.setTargetFPS(120);
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
    Drawing drawing;
    Texture indie(Image("resources/assets/indieTitle.png"));
    Texture studio(Image("resources/assets/studioTitle.png"));

    _scene = INTRO;
    for (int f = 0, x = 0, y = 0; timing.getTime() < 5.4f; f += 1) {
        x = -100 + f;
        y = 1500 - f;
        beginDrawing();
        drawing.clearBackground(Color::White());
        studio.drawTexture(y, 1080 / 2 - 100, Color::White());
        indie.drawTexture(x, 1080 / 2 - 100, Color::White());
        endDrawing();
    }
    while (timing.getTime() < 7.5f);
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
//    _scene = MAIN_MENU;
    if (cursor.isCursorOnScreen())
        cursor.hideCursor();
    beginDrawing();
    head.drawTexture(mouse.getMouseX() - 32, mouse.getMouseY() - 32, Color::White());
    title.drawTexture(1920 / 4, 40, Color::White());
    endDrawing();
}
