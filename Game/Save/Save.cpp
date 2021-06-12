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
        std::vector<std::string> inputArguments = getInputArguments(line, ' ');
        if (inputArguments[0].compare("settings") == 0)
        {
            parseSettings(inputArguments);
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

void Game::Save::parseSettings(const std::vector<std::string> &settings) const
{
    if (settings[1].compare("timestamp") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("set_nbr") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("set_id") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("time_game") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("time_remaining") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("ai_nbr") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("ai_lvl") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else if (settings[1].compare("player_nbr") == 0)
    {
        std::cout << settings[2] << std::endl;
    }
    else
    {
        throw std::invalid_argument("ERROR: Invalid backup setting");
    }
}

std::vector<std::string> Game::Save::getInputArguments(const std::string &line, const char &separator) const
{
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> inputArguments;

    while (std::getline(ss, token, separator)) {
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