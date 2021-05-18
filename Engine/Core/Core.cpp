/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Engine::Core::Core()
{
    //    std::shared_ptr<IGraphical> lib = std::make_shared<Raylib::XRay>();
    std::shared_ptr<IGraphical> lib = std::make_shared<Irrlicht>();

    _graphical = std::move(lib);
    _graphical->initWindow(1920, 1080, "Bomberman");
}

Engine::Core::~Core()
{
}

void Engine::Core::run(void)
{
    while (!_graphical->shouldCloseWindow()) {
        _graphical->display();
        _scene = _graphical->getScene();
        if (_scene == IGraphical::GAME && _game) {
            if (!_isPaused)
                _game->updateGame();
            if (!_game->isGameOver() && !endGame()) {
                _graphical->setScores(_game->getScores());
                _graphical->updateGameInfos(_game->getEntities());
                _graphical->setPlayersStats(_game->getPlayersStats());
            }
        }
        if (_graphical->getUserNames() != _userNames)
            _userNames = _graphical->getUserNames();
    }
    _graphical->closeWindow();
}

void Engine::Core::saveBestsScores(void)
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
        return;
    for (const auto &score : _gameHighScores)
        fileScores << (score.first.empty() ? "Unknown" : score.first) << " " << score.second << std::endl;
    fileScores.close();
}

bool Engine::Core::endGame(void)
{
    if (_graphical->getScene() != IGraphical::GAME || !_game->isGameOver())
        return false;
    _graphical->setScene(IGraphical::END_GAME);
    saveBestsScores();
    _graphical->setBestsScores(_gameHighScores);
    _graphical->setPlayersStats(_game->getPlayersStats());
    return true;
}