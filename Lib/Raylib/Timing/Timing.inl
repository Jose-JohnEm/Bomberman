/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Timing
*/

inline void Raylib::Timing::setTargetFPS(const int &fps) const
{
    ::SetTargetFPS(fps);
}

inline int Raylib::Timing::getFPS(void) const
{
    return ::GetFPS();
}

inline float Raylib::Timing::getFrameTime(void) const
{
    return ::GetFrameTime();
}

inline double Raylib::Timing::getTime(void) const
{
    return ::GetTime();
}
