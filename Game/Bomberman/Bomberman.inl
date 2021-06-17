/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Bomberman
*/

inline void Game::Bomberman::setMapType(const std::size_t &mapType)
{
    _mapType = mapType;
}

inline const std::vector<std::pair<std::string, std::string>> &Game::Bomberman::getScores(void) const
{
    return _scores;
}

inline const std::vector<std::shared_ptr<IEntity>> &Game::Bomberman::getEntities(void) const
{
    return _entities;
}

inline const std::vector<std::vector<std::pair<std::string, std::string>>> &Game::Bomberman::getPlayersStats(void) const
{
    return _playersStats;
}

inline bool Game::Bomberman::isGameOver(void) const
{
    return _gameOver;
}

inline const std::string &Game::Bomberman::getGameName(void) const
{
    return _gameName;
}

inline void Game::Bomberman::setUserNames(const std::vector<std::string> &userNames)
{
    _userNames = userNames;
}

inline void Game::Bomberman::setSettings(const std::array<std::size_t, 9> &settings)
{
    _settings = settings;
}

inline Game::Player &Game::Bomberman::findPlayer(const size_t &id)
{
    Game::Player *res = nullptr;

    for (const std::shared_ptr<IEntity> &entity : _entities)
    {
        if ((res = dynamic_cast<Game::Player *>(entity.get())) != nullptr && id == res->getID())
            return *res;
    }
    return findPlayer(id - 1);
}

inline void Game::Bomberman::doDropBomb(const size_t &playerID, std::pair<int, int> position)
{
    _entities.push_back(std::shared_ptr<IEntity>(new Game::Bomb({(float)position.first, (float)position.second, 0}, 1)));
}

inline void Game::Bomberman::doPlayerAction(const size_t playerID, const std::string action)
{
    //"goEast", "goNorth", "goSouth", "goWest", "dropBomb"]
    if (action == "goEast" || action == "goNorth" || action == "goSouth" || action == "goWest") {
        if (checkPlayerPosition(action, findPlayer(playerID)))
        {
            findPlayer(playerID).move(action);
        }
    }
    if (action == "dropBomb")
    {
        if (findPlayer(playerID).dropBomb())
            doDropBomb(playerID, findPlayer(playerID).getPositions2D());
    }
}

inline bool round90(float x, float y)
{
    return (y - 0.1f < x && y + 0.1f > x) ? true : false;
}

inline bool Game::Bomberman::checkPlayerPosition(const std::string action, Player &player)
{
    std::pair<int, int> positions = player.getPositions2D();
    Raylib::Vector3 pos3D = player.getPositions();
    std::map<std::string, std::pair<int, int>> direction = {
        {"goEast", {-1, 0}},
        {"goNorth", {0, -1}},
        {"goSouth", {0, 1}},
        {"goWest", {1, 0}}
    };

    bool collision = CheckCollisionSpheres(pos3D.getCStruct(), 0.4,  {(float)positions.first + direction[action].first, (float)positions.second + direction[action].second, 0}, 0.4);

    std::cout << "<<<< Position du perso : { " << pos3D.getCStruct().x << ", " << pos3D.getCStruct().y << ", " << pos3D.getCStruct().z << "}"<< std::endl;
    std::cout << "<<<< Position du mur : { " << direction[action].first + positions.first << ", " << direction[action].second + positions.second << ", " << 0 << "}"<< std::endl;
    std::cout << "<<<< DIAGO ! : " << collision << std::endl;

    if (collision && _map[direction[action].second + positions.second][direction[action].first + positions.first] != '*')
    {
        Raylib::Vector3 p1(pos3D.x, positions.second, pos3D.z);
        Raylib::Vector3 p2(positions.first, pos3D.y, pos3D.z);

        if (action == "goEast" || action == "goWest")
            player.setPositions(p1);
        if (action == "goNorth" || action == "goSouth")
            player.setPositions(p2);
    }

    positions.second = _map.size() - positions.second;
    for (auto i: _map)
        std::cout << i << std::endl;
    if (_map[direction[action].second + positions.second][direction[action].first + positions.first] == '*') {
        return true;
    } else if (player.getPowerUps()[P_PASS] > 0 && checkPlayerPositionPass(action, direction[action].second * 2 + positions.second, direction[action].first * 2 + positions.first) == true)
    positions.second = _map.size() - positions.second;
    if (_map[direction[action].second + positions.second][direction[action].first + positions.first] != 'W' && _map[direction[action].second + positions.second][direction[action].first + positions.first] != 'M' && _map[direction[action].second + positions.second][direction[action].first + positions.first] != 'E') {
        return true;
    } else if (player.getPowerUps()[P_PASS] > 0 && checkPlayerPositionPass(action, direction[action].second * 2 + positions.second, direction[action].first * 2 + positions.first) == true) {
        updateMap(positions, direction[action].second * 2 + positions.second, direction[action].first * 2 + positions.first);
        return true;
    }
    if ((!round90(pos3D.x, positions.first) && (action == "goEast" || action == "goWest")) || (!round90(pos3D.y, player.getPositions2D().second) && (action == "goNorth" || action == "goSouth")))
        return true;
    return false;
}

inline void Game::Bomberman::updateMap(const std::pair<int, int> &playerPos, const int &y, const int &x)
{
    _map[y][x] = _map[playerPos.second][playerPos.first];
    _map[playerPos.second][playerPos.first] = '*';
}

inline bool Game::Bomberman::checkPlayerPositionPass(const std::string action, const int &y, const int &x)
{
    if (y < 0 || x < 0 || y > _map.size() || x > _map.size())
        return false;
    if (_map[y][x] == '*')
        return true;
    return false;
}

inline std::array<std::size_t, 9> Game::Bomberman::getSettings(void) const
{
    return _settings;
}

inline const std::vector<std::string> &Game::Bomberman::getUserNames(void) const
{
    return _userNames;
}

inline const std::vector<std::string> &Game::Bomberman::getPlayerControls(void) const
{
    return _playerControls;
}