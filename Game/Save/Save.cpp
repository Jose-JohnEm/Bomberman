/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#include "Save.hpp"

Game::Save::Save(const std::array<std::size_t, 7> &settings, const std::vector<Game::Player> &players, const Game::MapGeneration &map)
{
    std::string fileName(".backups/" + getCurrentDateTime() + ".backup");
    std::replace(fileName.begin(), fileName.end(), ' ', '-');
    std::ofstream backupFile(fileName);

    if (backupFile.is_open()) 
    {
        setSaveGameSettings(backupFile, settings);
        setSavePlayer(backupFile, players);
        setSaveMap(backupFile, map);
        backupFile.close();
    }
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