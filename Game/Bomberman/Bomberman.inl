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

inline void Game::Bomberman::doPlayerAction(const size_t playerID, const std::string action)
{
    //"goEast", "goNorth", "goSouth", "goWest", "dropBomb"]
    if (action == "goEast"
    || action == "goNorth"
    || action == "goSouth"
    || action == "goWest") {
        for (const std::shared_ptr<IEntity> &entity : _entities) {
            if (entity->getType().compare("Human") == 0) {
                if (dynamic_cast<Game::Human *>(entity.get()) != nullptr && playerID == dynamic_cast<Game::Human *>(entity.get())->getID())
                {

                    if (checkPlayerPosition(action, *dynamic_cast<Game::Human *>(entity.get())))
                        dynamic_cast<Game::Human *>(entity.get())->move(action);
                }
            }
        }
    }
}

inline bool round90(float x, float y)
{
    return (y - 0.1f < x && y + 0.1f > x) ? true : false;
}

inline bool Game::Bomberman::checkPlayerPosition(const std::string action, Human &human)
{
    std::pair<int, int> positions = human.getPositions2D();
    Raylib::Vector3 pos3D = human.getPositions();
    std::map<std::string, std::pair<int, int>> direction = {
        {"goEast", {-1, 0}},
        {"goNorth", {0, -1}},
        {"goSouth", {0, 1}},
        {"goWest", {1, 0}}
    };

    positions.second = _map.size() - positions.second;
    if (_map[direction[action].second + positions.second][direction[action].first + positions.first] != 'W' && _map[direction[action].second + positions.second][direction[action].first + positions.first] != 'M' && _map[direction[action].second + positions.second][direction[action].first + positions.first] != 'E') {
        return true;
    } else if (human.getPowerUps()[P_PASS] > 0 && checkPlayerPositionPass(action, direction[action].second * 2 + positions.second, direction[action].first * 2 + positions.first) == true)
        return true;
/*    if ((abs(pos3D.x - positions.first) < abs(direction[action].first) / 2 && action == "goEast" && action == "goWest") ||
        (abs(pos3D.y - positions.second) < abs(direction[action].second) / 2 && action == "goNorth" && action == "goSouth"))*/
    if ((!round90(pos3D.x, positions.first) && (action == "goEast" || action == "goWest")) || (!round90(pos3D.y, human.getPositions2D().second) && (action == "goNorth" || action == "goSouth")))
        return true;
    return false;
}

inline void Game::Bomberman::updateMap(const Raylib::Vector3 &playerPos, const int &y, const int &x)
{
    _map[y][x] = _map[playerPos.y][playerPos.x];
    _map[playerPos.y][playerPos.x] = '*';
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