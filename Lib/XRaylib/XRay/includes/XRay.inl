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

inline std::array<size_t, 8> XRay::getGameSettings()
{
    return _gameSettings;
}

inline void XRay::setRestartFunc(std::function<void ()> pointerToFunc)
{
    _pointerToRestartFunc = pointerToFunc;
}

inline void XRay::setLoadFunc(std::function<void (std::string)> pointerToFunc)
{
    _pointerToLoadFunc = pointerToFunc;
}

inline void XRay::setSaveFunc(std::function<void (std::array<std::size_t, 8>)> pointerToFunc)
{
    _pointerToSaveFunc = pointerToFunc;
}

inline void XRay::setSettingsFunc(std::function<void (std::array<std::size_t, 8>)> pointerToFunc)
{
    _pointerToSettingsFunc = pointerToFunc;
}

inline void XRay::setMap(std::vector<std::string> &map)
{
    _map = map;
}

inline std::pair<size_t, size_t> XRay::getMapSizeAndType()
{
    return std::make_pair(_sizeMap, _mapType);
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
    // Hide the cursor
    Raylib::Cursor::hideCursor();

    (this->*_scenesFunc[(int)_scene])();
}

inline void XRay::setPlayersStats(const std::vector<std::vector<std::pair<std::string, std::string>>> &info)
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

inline std::vector<CharDictionary> XRay::getPlayersData()
{
    return _pSelector.getPlayerData();
}