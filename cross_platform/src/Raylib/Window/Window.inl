/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

inline void Raylib::Window::initWindow(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

inline bool Raylib::Window::windowShouldClose(void)
{
    return (WindowShouldClose());
}

inline void Raylib::Window::closeWindow(void)
{
    CloseWindow();
}

inline void Raylib::Window::drawText(const char *text, int posX, int posY, int fontSize)
{
    DrawText(text, posX, posY, fontSize, GOLD);
}