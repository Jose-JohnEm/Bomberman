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

void Game::Save::parseBackup(std::ifstream &backupFile)
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
            parsePlayers(inputArguments);
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

void Game::Save::parseSettings(const std::vector<std::string> &settings)
{
    if (settings[1].compare("timestamp") == 0)
    {
        _settings[0] = std::stol(settings[2]);
    }
    else if (settings[1].compare("set_nbr") == 0)
    {
        _settings[1] = std::stol(settings[2]);
    }
    else if (settings[1].compare("set_id") == 0)
    {
        _settings[2] = std::stol(settings[2]);
    }
    else if (settings[1].compare("time_game") == 0)
    {
        _settings[3] = std::stol(settings[2]);
    }
    else if (settings[1].compare("time_remaining") == 0)
    {
        _settings[4] = std::stol(settings[2]);
    }
    else if (settings[1].compare("ai_nbr") == 0)
    {
        _settings[5] = std::stol(settings[2]);
    }
    else if (settings[1].compare("ai_lvl") == 0)
    {
        _settings[6] = std::stol(settings[2]);
    }
    else if (settings[1].compare("player_nbr") == 0)
    {
        _settings[7] = std::stol(settings[2]);
    }
    else
    {
        throw std::invalid_argument("ERROR: Invalid backup setting");
    }
}

// player 1 name Name
// player 1 positions 30,40
// player 1 powerups skate:1,bomb:0,pass:1,fire:1,life:0
// player 1 broken_walls 200
// player 1 kills 2

void Game::Save::parsePlayers(const std::vector<std::string> &playersInfos)
{
    Game::Player player1, player2, player3, player4;
    bool firstIsParse = false, secondIsParse = false, thirdIsParse = false, fourthIsParse = false;

    switch (std::stoi(playersInfos[1]))
    {
        case 1:
            if (!firstIsParse)
                player1.setID(std::stoi(playersInfos[1]));
            else
                firstIsParse = true;
            parsePlayer(player1, playersInfos);
            break;
        case 2:
            if (!secondIsParse)
                player2.setID(std::stoi(playersInfos[1]));
            else
                secondIsParse = true;
            parsePlayer(player2, playersInfos);
            break;
        case 3:
            if (!thirdIsParse)
                player3.setID(std::stoi(playersInfos[1]));
            else
                thirdIsParse = true;
            parsePlayer(player3, playersInfos);
            break;
        case 4:
            if (!fourthIsParse)
                player4.setID(std::stoi(playersInfos[1]));
            else
                fourthIsParse = true;
            parsePlayer(player4, playersInfos);
            break;
        default:
            throw std::invalid_argument("ERROR: Invalid player ID");
    }
}

void Game::Save::parsePlayer(Game::Player &player, const std::vector<std::string> &playerInfos) const
{
    if (playerInfos[2].compare("name") == 0)
    {
        player.setName(playerInfos[3]);
    }
    else if (playerInfos[2].compare("positions") == 0)
    {
    }
    else if (playerInfos[2].compare("powerups") == 0)
    {
    }
    else if (playerInfos[2].compare("broken_walls") == 0)
    {
    }
    else if (playerInfos[2].compare("kills") == 0)
    {
    }
    else
    {
        throw std::invalid_argument("ERROR: Invalid player infos");
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