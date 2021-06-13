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

void Game::Bomberman::initEntities() //TODO: pushback player
{
    float x;
    float y = 0;
    float scale;

    for (const std::string &line : _map) {
        x = 0;
        for (const char &c : line) {
            if (c == 'W' || c == 'E')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::SolidWall(Raylib::Vector3(x, y, 0), _mapType)));
            if (c == 'M')
                _entities.push_back(std::shared_ptr<IEntity>(new Game::BreakableWall(Raylib::Vector3(x, y, 0), _mapType)));
            _entities.push_back(std::shared_ptr<IEntity>(new Game::Floor(Raylib::Vector3(x, y, -0.4f), _mapType)));
            x++;
        }
        y++;
    }
}

std::vector<std::string> &Game::Bomberman::getMap(size_t size)
{
    if (_map.size() != size+2) {
        Game::Map newMap(size, size, _userNames.size());

        std::cout << " YAOI " << _userNames.size() << std::endl;
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
/*    for (size_t i = 0; i < _scores.size(); i++) {
        _scores[i].second = "0";
        for (size_t j = 0; j < _playersStats[i].size(); j++)
            _playersStats[i][j].second = "0";
    }
*/
    // Reset Entities
}

void Game::Bomberman::saveGame(const std::array<std::size_t, 8> &settings)
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
    map.setHeight(_map.size()); //TODO: Check the dimensions
    map.setWidth(_map[0].size());
    map.setMap(_map);

    // Save it all
    Game::Save save(settings, players, map);
    std::cout << "I save" << std::endl;
}

std::shared_ptr<IGame> Game::Bomberman::loadGame(const std::string &backupFilePath)
{
    // Game::Save load(backupFilePath);

    //_map = load.getMap();
    //_settings = load.getSettings();
    // TODO: TO IMPLEMENT
    std::cout << "I load " << backupFilePath << std::endl;
    return nullptr;
}

void Game::Bomberman::updateGame(void)
{
    static int i = 0;
    if (i == 0) {
        initEntities();
        initPlayersStats();
    }
    if (_gameOver) {
        updateEntities();
        updateScores();
        updatePlayersStats();
    }
    i++;
}