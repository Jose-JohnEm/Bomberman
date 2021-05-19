/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Window
*/

inline void Raylib::Window::initWindow(const int &width, const int &height, const std::string &title) const
{
    ::InitWindow(width, height, title.c_str());
}

inline bool Raylib::Window::windowShouldClose(void) const
{
    return ::WindowShouldClose();
}

inline void Raylib::Window::closeWindow(void) const
{
    ::CloseWindow();
}