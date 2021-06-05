/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

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
    Raylib::Drawing::beginDrawing();
    Raylib::Drawing::clearBackground(Raylib::Color::White());
}

inline void XRay::beginDrawing(const bool &mustBeClear) const
{
    Raylib::Drawing::beginDrawing();
    if (mustBeClear)
        Raylib::Drawing::clearBackground(Raylib::Color::White());
}

inline void XRay::endDrawing(void) const
{
    Raylib::Drawing::endDrawing();
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

inline bool XRay::mouseIsInBox(const std::vector<size_t> &box) const
{
    std::pair<size_t, size_t> mousePosition = std::make_pair(Raylib::Mouse::getMouseX(), Raylib::Mouse::getMouseY());

    if (box[UPPER_LEFT] <= mousePosition.first && mousePosition.first <= box[LOW_RIGHT]
    && box[LOW_LEFT] <= mousePosition.second && mousePosition.second <= box[UPPER_RIGHT])
        return true;
    return false;
}

inline std::vector<size_t> XRay::createBox(const size_t &upperLeftCorner, const size_t &upperRightCorner, const size_t &lowerLeftCorner, const size_t &lowerRightCorner) const
{
    std::vector<size_t> box;

    box.reserve(4);
    box.push_back(upperLeftCorner);
    box.push_back(upperRightCorner);
    box.push_back(lowerLeftCorner);
    box.push_back(lowerRightCorner);
    return box;
}

inline void XRay::displayMouse(void) const
{
    _resources.at(HEAD)->drawTexture(Raylib::Mouse::getMouseX() - 15, Raylib::Mouse::getMouseY() - 15, Raylib::Color::White());
}

inline size_t XRay::countFilesDirectory(const std::filesystem::path &path) const
{
    return (std::size_t)std::distance(std::filesystem::directory_iterator{path}, std::filesystem::directory_iterator{});
}