/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#include "Save.hpp"

Game::Save::Save(const std::array<std::size_t, 8> &settings, const std::vector<Game::Player> &players, const Game::Map &map)
    : _settings(settings), _players(players), _map(map)
{
    std::string fileName = createBackupName();
    std::ofstream backupFile(fileName);

    if (backupFile.is_open())
    {
        writeSettings(backupFile);
        writePlayersInfos(backupFile);
        writeMap(backupFile);
        backupFile.close();
    }
}

Game::Save::Save(const std::string &fileName)
{
    std::ifstream backupFile(fileName);

    if (backupFile.is_open())
    {
        parseBackup(backupFile);
        backupFile.close();
    }
}

Game::Save::~Save()
{
}

void Game::Save::parseBackup(std::ifstream &backupFile) const
{
    std::string line;

    while (getline(backupFile, line))
    {
        std::vector<std::string> inputArguments = getInputArguments(line);
        if (inputArguments[0].compare("settings") == 0)
        {
            std::cout << "Setting" << std::endl;
        }
        else if (inputArguments[0].compare("player") == 0)
        {
            std::cout << "Player" << std::endl;
        }
        else if (inputArguments[0].compare("map") == 0)
        {
            std::cout << "Map dimensions" << std::endl;
        }
        else
        {
            std::cout << "Map char" << std::endl;
        }
    }
}

std::vector<std::string> Game::Save::getInputArguments(const std::string &line) const
{
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> inputArguments;

    while (std::getline(ss, token, ' ')) {
        inputArguments.push_back(token);
    }
    return inputArguments;
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