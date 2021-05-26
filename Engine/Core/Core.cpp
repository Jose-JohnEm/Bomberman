/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#include "Core.hpp"

Engine::Core::Core()
{
<<<<<<< HEAD
<<<<<<< HEAD:Engine/Core/Core.cpp
    std::shared_ptr<IGraphical> lib = std::make_shared<XRay>();
=======
//    std::shared_ptr<IGraphical> lib = std::make_shared<Raylib::XRay>();
    std::shared_ptr<IGraphical> lib = std::make_shared<Irrlicht>();
>>>>>>> 947524d (Push):src/Core/Core.cpp
=======
    std::shared_ptr<IGraphical> lib = std::make_shared<XRay>();
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))

    _graphical = std::move(lib);
}

Engine::Core::~Core()
{
}

void Engine::Core::run(void)
{
<<<<<<< HEAD
    while (!_graphical->shouldCloseWindow()) {
        _graphical->display();
        _scene = _graphical->getScene();
        if (_scene == IGraphical::GAME && _game) {
=======
    while (!_graphical->shouldCloseWindow() && _scene != IGraphical::END_GAME) {
        getBackupFiles();
        _graphical->display();
        _scene = _graphical->getScene();
        if (_scene == IGraphical::GAMEIN && _game) {
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
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
<<<<<<< HEAD
=======
        if (_graphical->getBackups() != _backups)
            _graphical->setBackups(_backups);
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
    }
    _graphical->closeWindow();
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
void Engine::Core::getBackupsFiles()
=======
void Engine::Core::getBackupFiles(void)
>>>>>>> 12c4491 (Cleaned Core code)
{
    std::string dirBackups(".backups/");
    std::filesystem::directory_iterator itBackups(dirBackups);

    _backups.clear();
    for (const auto &file: itBackups)
        if (file.path().filename().extension() == ".backup")
                _backups.push_back(file.path().filename());
}

<<<<<<< HEAD
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
void Engine::Core::saveBestsScores(void)
=======
void Engine::Core::saveBestScores(void)
>>>>>>> 12c4491 (Cleaned Core code)
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
<<<<<<< HEAD
    if (_graphical->getScene() != IGraphical::GAME || !_game->isGameOver())
=======
    if (_graphical->getScene() != IGraphical::GAMEIN || !_game->isGameOver())
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
        return false;
    _graphical->setScene(IGraphical::END_GAME);
    saveBestScores();
    _graphical->setBestScores(_gameHighScores);
    _graphical->setPlayersStats(_game->getPlayersStats());
    return true;
}