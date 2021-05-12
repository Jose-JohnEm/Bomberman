/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

inline void Raylib::XRay::initWindow(const int &width, const int &height, const std::string &title)
{
    _window.initWindow(width, height, title);
}

inline bool Raylib::XRay::shouldCloseWindow()
{
    return _window.windowShouldClose();
}

inline void Raylib::XRay::closeWindow()
{
    _window.closeWindow();
}

inline void Raylib::XRay::drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize)
{
    _window.drawText(text, posX, posY, fontSize);
}

inline void Raylib::XRay::beginDrawing()
{
    ::BeginDrawing(); //TODO: use our encapsulation
    ::ClearBackground(RAYWHITE); //TODO: use our encapsulation
}

inline void Raylib::XRay::endDrawing()
{
    ::EndDrawing(); //TODO: use our encapsulation
}