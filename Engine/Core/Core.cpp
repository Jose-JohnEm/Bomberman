/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Engine::Core::Core()
: _graphical{std::make_shared<XRay>()}, _game{std::make_shared<Game::Bomberman>()}, _userNames{{""}}
{
    _graphical->setLoadFunc([this] (std::string filepath) {this->loadGame(filepath);});
    _graphical->setSaveFunc([this] (std::array<std::size_t, 8> settings) {this->saveGame(settings);});
    _graphical->setRestartFunc([this] () {this->restartGame();});
}

Engine::Core::~Core()
{
}

void Engine::Core::saveGame(std::array<std::size_t, 8> settings)
{
    _game->saveGame(settings);
}

void Engine::Core::loadGame(std::string filepath)
{
    _game->loadGame(filepath);
}

void Engine::Core::restartGame()
{
    _game->restart();
}

void Engine::Core::run(void)
{
    while (_scene != IGraphical::END_GAME && !_graphical->shouldCloseWindow()) {
        getBackupFiles();
        _graphical->display();
        _scene = _graphical->getScene();
        if (_scene == IGraphical::MAP_CHOICE || (_graphical->getMapSizeAndType().first > 5 && _scene < IGraphical::MAP_CHOICE)) {
            _game->setUserNames(_graphical->getUserNames());
            _graphical->setMap(_game->getMap(5));
        }
        if (_scene == IGraphical::IN_GAME && _game) {
            if (_userNames != _graphical->getUserNames()) {
                _userNames = _graphical->getUserNames();
                _game->setMapType(_graphical->getMapSizeAndType().second);
                _game->setUserNames(_graphical->getUserNames());
                _graphical->setMap(_game->getMap(_graphical->getMapSizeAndType().first));
            }
            if (!_isPaused)
                _game->updateGame();
            if (!_game->isGameOver() && !endGame()) {
                _graphical->setScores(_game->getScores());
                _graphical->updateGameInfos(_game->getEntities());
                _graphical->setPlayersStats(_game->getPlayersStats());
            }
        }
        if (_graphical->getBackups() != _backups)
            _graphical->setBackups(_backups);
    }
    _graphical->closeWindow();
}

void Engine::Core::getBackupFiles(void)
{
    std::string dirBackups(".backups/");
    std::filesystem::directory_iterator itBackups(dirBackups);

    _backups.clear();
    for (const auto &file: itBackups)
        if (file.path().filename().extension() == ".backup")
                _backups.push_back(file.path().filename().string());
}

void Engine::Core::saveBestScores(void)
{
    // Get all scores and sort them in ascending order
    std::vector<std::pair<std::string, std::string>> _scores =  _game->getScores();

    for(auto& s: _scores)
        _gameHighScores.emplace_back(s);
    std::sort(_gameHighScores.begin(), _gameHighScores.end(), [](const auto &a, const auto &b){
        return std::stoi(a.second.c_str()) >= std::stoi(b.second.c_str());
    });

    // Keep only the top 10 scores
    if (_gameHighScores.size() > 10)
        _gameHighScores.erase(_gameHighScores.begin() + 10, _gameHighScores.end());

    // Write in file
    std::string dirBestScores(".scores/");
    std::string path(dirBestScores + _currentGame);
    std::ofstream fileScores(path);

    if (!fileScores.good())
        throw "ERROR: problem with score's file";
    for (const auto &score : _gameHighScores)
        fileScores << (score.first.empty() ? "Unknown" : score.first) << " " << score.second << std::endl;
    fileScores.close();
}

bool Engine::Core::endGame(void)
{
    if (_graphical->getScene() != IGraphical::IN_GAME || !_game->isGameOver())
        return false;
    _graphical->setScene(IGraphical::END_GAME);
    saveBestScores();
    _graphical->setBestScores(_gameHighScores);
    _graphical->setPlayersStats(_game->getPlayersStats());
    return true;
}