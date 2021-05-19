/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Mouse
*/

inline bool Raylib::Mouse::isButtonPressed(const size_t &button) const
{
    return ::IsMouseButtonPressed(button);
}

inline bool Raylib::Mouse::isButtonDown(const size_t &button) const
{
    return ::IsMouseButtonDown(button);
}

inline bool Raylib::Mouse::isButtonReleased(const size_t &button) const
{
    return ::IsMouseButtonReleased(button);
}

inline bool Raylib::Mouse::isButtonUp(const size_t &button) const
{
    return ::IsMouseButtonUp(button);
}

inline size_t Raylib::Mouse::getMouseX(void) const
{
    return ::GetMouseX();
}

inline size_t Raylib::Mouse::getMouseY(void) const
{
    return ::GetMouseY();
}

inline void Raylib::Mouse::setMousePosition(const size_t &x, const size_t &y) const
{
    ::SetMousePosition(x, y);
}

inline void Raylib::Mouse::setMouseOffset(const size_t &offsetX, const size_t &offsetY) const
{
    ::SetMouseOffset(offsetX, offsetY);
}

inline void Raylib::Mouse::setMouseScale(const float &scaleX, const float &scaleY) const
{
    ::SetMouseScale(scaleX, scaleY);
}

inline float Raylib::Mouse::getMouseWheelMove(void) const
{
    return ::GetMouseWheelMove();
}

inline void Raylib::Mouse::setMouseCursor(const size_t &cursor) const
{
    ::SetMouseCursor(cursor);
}

inline size_t Raylib::Mouse::getTouchX(void) const
{
    return ::GetTouchX();
}

inline size_t Raylib::Mouse::getTouchY(void) const
{
    return ::GetTouchY();
}