/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Keyboard
*/

inline bool Raylib::Keyboard::isKeyPressed(const size_t &key) const
{
    return ::IsKeyPressed(key);
}

inline bool Raylib::Keyboard::isKeyDown(const size_t &key) const
{
    return ::IsKeyDown(key);
}

inline bool Raylib::Keyboard::isKeyReleased(const size_t &key) const
{
    return ::IsKeyReleased(key);
}

inline bool Raylib::Keyboard::isKeyUp(const size_t &key) const
{
    return ::IsKeyUp(key);
}

inline void Raylib::Keyboard::setExitKey(const size_t &key) const
{
    ::SetExitKey(key);
}

inline size_t Raylib::Keyboard::getKeyPressed(void) const
{
    return ::GetKeyPressed();
}

inline size_t Raylib::Keyboard::getCharPressed(void) const
{
    return ::GetCharPressed();
}
