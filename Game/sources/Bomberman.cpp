/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#include "../includes/Bomberman.hpp"

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