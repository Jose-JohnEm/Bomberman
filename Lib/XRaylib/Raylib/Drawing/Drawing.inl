/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Drawing
*/

inline void Raylib::Drawing::clearBackground(const Color &color)
{
    ::ClearBackground(color.getCStruct());
}

inline void Raylib::Drawing::beginDrawing(void)
{
    ::BeginDrawing();
}

inline void Raylib::Drawing::endDrawing(void)
{
    ::EndDrawing();
}