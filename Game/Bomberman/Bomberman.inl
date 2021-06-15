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
    std::cout << "AAAAAAAAAAAA" << std::endl;
    //"goEast", "goNorth", "goSouth", "goWest", "dropBomb"]
    if (action == "goEast"
    || action == "goNorth"
    || action == "goSouth"
    || action == "goWest") {
        for (const std::shared_ptr<IEntity> &entity : _entities) {
            if (entity->getType().compare("Human") == 0) {
                std::cout << "OKOKOK - " << std::make_shared<Game::Human>(*dynamic_cast<Game::Human *>(entity.get()))->getID() << std::endl;
            }
        }
    }
}

inline std::array<std::size_t, 9> Game::Bomberman::getSettings(void) const
{
    return _settings;
}
