/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Cursor
*/

inline void Raylib::Cursor::showCursor(void) const
{
    ::ShowCursor();
}

inline void Raylib::Cursor::hideCursor(void) const
{
    ::HideCursor();
}

inline bool Raylib::Cursor::isCursorHidden(void) const
{
    return ::IsCursorHidden();
}

inline void Raylib::Cursor::enableCursor(void) const
{
    ::EnableCursor();
}

inline void Raylib::Cursor::disableCursor(void) const
{
    ::DisableCursor();
}

inline bool Raylib::Cursor::isCursorOnScreen(void) const
{
    return ::IsCursorOnScreen();
}
