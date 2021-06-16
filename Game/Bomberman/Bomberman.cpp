/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#include "Bomberman.hpp"

Game::Bomberman::Bomberman(void)
    : _gameName{"Bomberman"}, _gameOver{false}
{
}

Game::Bomberman::~Bomberman(void)
{
}

void Game::Bomberman::initEntities()
{
    float x;
    float y = _map.size();
    float scale;
    int dic_index = 0;

    _entities.clear();

    for (const std::string &line : _map) {
        x = 0;
        for (const char &c : line) {
            if ((c == 'H' || c == 'A') && dic_index < _players.size())
            {
                if (c == 'H')
                    _entities.push_back(std::shared_ptr<IEntity>(new Game::Human(_players[dic_index].name, dic_index, {x, y, 0}, _players[dic_index].obj, _players[dic_index].texture, _players[dic_index].animations, _players[dic_index].scalable, _players[dic_index].color)));
                else if (c == 'A')
                    _entities.push_back(std::shared_ptr<IEntity>(new Game::AI(_players[dic_index].name, dic_index, {x, y, 0}, _players[dic_index].obj, _players[dic_index].texture, _players[dic_index].animations, _players[dic_index].scalable, _players[dic_index].color)));
                dic_index++;
            }
            else if (c == 'W' || c == 'E')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3(x, y, 0), _mapType)));
            else if (c == 'M')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::BreakableWall(Raylib::Vector3(x, y, 0), _mapType)));
            _entities.push_back(std::shared_ptr<IEntity>(new Game::Floor(Raylib::Vector3(x, y, -1), _mapType)));
            x++;
        }
        y--;
    }
}

std::vector<std::string> &Game::Bomberman::getMap()
{
    return _map;
}

std::vector<std::string> &Game::Bomberman::getMap(const size_t &size)
{
    if (_map.size() != size+2) {
        Game::Map newMap(size, size, std::make_pair(_settings[HUMAN_NBR], _settings[AI_NBR]));
        _map = newMap.getMap();
    }
    return _map;
}

void Game::Bomberman::initPlayersStats()
{
    _playersStats.clear();
    _scores.clear();
    for (size_t i = 0; i < _userNames.size(); i++) {
        _scores.push_back(std::make_pair(_userNames[i], "0"));
    }
}

void Game::Bomberman::updateEntities()
{
}

void Game::Bomberman::updateScores()
{
}

void Game::Bomberman::updatePlayersStats()
{
}

void Game::Bomberman::restart(void)
{
    // Reset Scores
    // TODO: TO IMPLEMENT
    std::cout << "I restart" << std::endl;
    _reinit = 0;
/*    for (size_t i = 0; i < _scores.size(); i++) {
        _scores[i].second = "0";
        for (size_t j = 0; j < _playersStats[i].size(); j++)
            _playersStats[i][j].second = "0";
    }
*/
    // Reset Entities
}

void Game::Bomberman::saveGame(std::array<std::size_t, 9> settings, std::vector<std::string> playerControls)
{
    // Get players entities
    std::vector<std::shared_ptr<Game::Player>> players;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if (entity->getType().compare("Human") == 0)
        {
            players.push_back(std::make_shared<Game::Human>(*dynamic_cast<Game::Human *>(entity.get())));
        }
        else if (entity->getType().compare("AI") == 0)
        {
            players.push_back(std::make_shared<Game::AI>(*dynamic_cast<Game::AI *>(entity.get())));
        }
    }

    // Get Map
    Game::Map map;
    map.setHeight(_map.size() - 2);
    map.setWidth(_map[0].size() - 2);
    map.setMap(_map);

    // Save it all
    settings[TIMESTAMP] = std::time(0);
    settings[WORLD] = _mapType;
    Game::Save save(settings, players, playerControls, map);
    std::cout << "I save" << std::endl;
}

void Game::Bomberman::loadGame(const std::string &backupFilePath)
{
    // Parse data
    Game::Save load(".backups/" + backupFilePath);

    // Load players
    std::vector<std::shared_ptr<Game::Player>> players = load.getPlayers();
    for (const std::shared_ptr<Game::Player> &player : players)
    {
        _entities.push_back(player);
    }

    // Load the user names
    _userNames = load.getUserNames();

    // Load player controls
    _playerControls = load.getPlayerControls();

    // Load map
    _map = load.getMap().getMap();

    // Load the settings
    _settings = load.getSettings();

    std::cout << "I load " << backupFilePath << std::endl;
}

void Game::Bomberman::setPlayers(const std::vector<CharDictionary> &playersData)
{
    _players = playersData;
}

void Game::Bomberman::updateGame(void)
{
    if (_reinit == 0) {
        initEntities();
        initPlayersStats();
        _reinit++;
    }
    if (_gameOver) {
        updateEntities();
        updateScores();
        updatePlayersStats();
    }
}