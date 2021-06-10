/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#include "Save.hpp"

Game::Save::Save(const std::array<std::size_t, 7> &settings, const std::vector<Game::Player> &players, const Game::MapGeneration &map)
{
    std::string filename = createSaveFile();
    setSaveFilename(filename);
}

Game::Save::Save(const std::string &filename)
{

}

Game::Save::~Save()
{
}

std::string Game::Save::getCurrentDateTime(void) const
{
    std::time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std::string currentDateTime = asctime(timeinfo);
    currentDateTime.erase(std::prev(currentDateTime.end()));
    return currentDateTime;
}