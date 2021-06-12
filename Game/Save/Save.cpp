/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#include "Save.hpp"

Game::Save::Save(const std::array<std::size_t, 8> &settings, const std::array<Game::Player, 4> &players, const Game::Map &map)
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

// map dimensions 15,15
// EEEEEEEEEEEEEEEEE
// E1**MMMM*MMMM**4E
// E*W*W*WMW*W*W*W*E
// E**M*MMMMM*M*M**E
// EMWMW*W*WMWMWMWME
// EM*M*MMM*MMMMMMME
// EMWMW*WMW*W*W*WME
// EMMM*M*MMMMM*M*ME
// E*WMWMW*W*WMWMWME
// EM*MMM*MMMMMMMMME
// EMW*WMW*W*W*W*W*E
// EM*M*M*M*M*MMMMME
// EMWMWMWMWMW*W*WME
// E*MM*M*M*MMMMM**E
// E*WMWMWMW*W*WMW*E
// E2**MM*MMMMM***3E
// EEEEEEEEEEEEEEEEE

void Game::Save::parseBackup(std::ifstream &backupFile)
{
    std::string line;
    std::vector<std::string> map;

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
            std::vector<std::string> dimensions = getInputArguments(inputArguments[2], ',');
            _map.setWidth(std::stol(dimensions[0]));
            _map.setHeight(std::stol(dimensions[1]));
        }
        else
        {
            map.push_back(line);
        }
    }

    // Set the map
    _map.setMap(map);
}

void Game::Save::parseSettings(const std::vector<std::string> &settings)
{
    if (settings[1].compare("timestamp") == 0)
    {
        _settings[0] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("set_nbr") == 0)
    {
        _settings[1] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("set_id") == 0)
    {
        _settings[2] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("time_game") == 0)
    {
        _settings[3] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("time_remaining") == 0)
    {
        _settings[4] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("ai_nbr") == 0)
    {
        _settings[5] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("ai_lvl") == 0)
    {
        _settings[6] = std::stoul(settings[2]);
    }
    else if (settings[1].compare("player_nbr") == 0)
    {
        _settings[7] = std::stoul(settings[2]);
    }
    else
    {
        throw std::invalid_argument("ERROR: Invalid backup setting");
    }
}

void Game::Save::parsePlayers(const std::vector<std::string> &playersInfos)
{
    bool firstIsParse = false, secondIsParse = false, thirdIsParse = false, fourthIsParse = false;

    switch (std::stoi(playersInfos[1]))
    {
        case 1:
            if (!firstIsParse)
                _players[0].setID(std::stoi(playersInfos[1]));
            else
                firstIsParse = true;
            parsePlayer(_players[0], playersInfos);
            break;
        case 2:
            if (!secondIsParse)
                _players[1].setID(std::stoi(playersInfos[1]));
            else
                secondIsParse = true;
            parsePlayer(_players[1], playersInfos);
            break;
        case 3:
            if (!thirdIsParse)
                _players[2].setID(std::stoi(playersInfos[1]));
            else
                thirdIsParse = true;
            parsePlayer(_players[2], playersInfos);
            break;
        case 4:
            if (!fourthIsParse)
                _players[3].setID(std::stoi(playersInfos[1]));
            else
                fourthIsParse = true;
            parsePlayer(_players[3], playersInfos);
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
        std::vector<std::string> positions = getInputArguments(playerInfos[3], ',');
        player.setPositions(std::make_pair(std::stof(positions[0]), std::stof(positions[1])));
    }
    else if (playerInfos[2].compare("powerups") == 0)
    {
        std::vector<std::string> powerups = getInputArguments(playerInfos[3], ',');
        player.setPowerUps(
            {
                atoi(powerups[P_SKATE].c_str() + (powerups[P_SKATE].size() - 1)),
                atoi(powerups[P_BOMB].c_str() + (powerups[P_BOMB].size() - 1)),
                atoi(powerups[P_PASS].c_str() + (powerups[P_PASS].size() - 1)),
                atoi(powerups[P_FIRE].c_str() + (powerups[P_FIRE].size() - 1)),
                atoi(powerups[P_LIFE].c_str() + (powerups[P_LIFE].size() - 1))
            }
        );
    }
    else if (playerInfos[2].compare("broken_walls") == 0)
    {
        player.setBrokenWalls(std::stoul(playerInfos[3]));
    }
    else if (playerInfos[2].compare("kills") == 0)
    {
        player.setKills(std::stoul(playerInfos[3]));
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