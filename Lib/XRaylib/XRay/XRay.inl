/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

inline void XRay::initWindow(const int &width, const int &height, const std::string &title) const
{
    _window.initWindow(width, height, title);
}

inline bool XRay::shouldCloseWindow(void) const
{
    return _window.windowShouldClose();
}

inline void XRay::closeWindow(void) const
{
    _window.closeWindow();
}

inline void XRay::beginDrawing(void) const
{
    Raylib::Drawing drawing;

    drawing.beginDrawing();
    drawing.clearBackground(Raylib::Color::White());
}

inline void XRay::beginDrawing(const bool &mustBeClear) const
{
    Raylib::Drawing drawing;

    drawing.beginDrawing();
    if (mustBeClear)
        drawing.clearBackground(Raylib::Color::White());
}

inline void XRay::endDrawing(void) const
{
    Raylib::Drawing drawing;

    drawing.endDrawing();
}

inline void XRay::display(void)
{
    (this->*_scenesFunc[(int)_scene])();
}

inline void XRay::setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info)
{
    _playersStats = info;
}

inline void XRay::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

inline void XRay::setBestScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _bestScores = scores;
}

inline void XRay::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    _gameInfos = gameInfos;
}

inline const std::vector<std::string> &XRay::getUserNames(void) const
{
    return _userNames;
}

inline IGraphical::Scene XRay::getScene(void) const
{
    return _scene;
}

inline void XRay::setScene(const Scene &scene)
{
    _scene = scene;
}

inline const std::vector<std::string> &XRay::getBackups(void) const
{
    return _backups;
}

inline void XRay::setBackups(const std::vector<std::string> &backups)
{
    _backups = backups;
}
