/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Music
*/

#include "Music.hpp"

Raylib::Music::Music()
{
}

Raylib::Music::Music(const Music &music)
{
    set(music);
}

Raylib::Music::Music(const std::string &fileName)
{
    _music = ::LoadMusicStream(fileName.c_str());
}

Raylib::Music::Music(const std::string &fileType, const std::string &data, const int &dataSize)
{
    _music = ::LoadMusicStreamFromMemory(fileType.c_str(), (unsigned char *)data.c_str(), dataSize);
}

Raylib::Music::~Music()
{
    ::UnloadMusicStream(_music);
}