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
    drawing.clearBackground(Raylib::Color::Black());
}

inline void XRay::endDrawing(void) const
{
    Raylib::Drawing drawing;

    drawing.endDrawing();
}

inline void XRay::display(void)
{
    (this->*_scenesFunc[_scene])();
}

inline bool XRay::isInGameScene(void) const
{
    return false;
}

inline void XRay::setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info)
{
    // TODO: Implement this function
}

inline void XRay::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void XRay::setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void XRay::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    // TODO: Implement this function
}

inline const std::vector<std::string> &XRay::getUserNames(void) const
{
    // TODO: Implement this function
    return _userNames;
}

inline IGraphical::Scene XRay::getScene(void) const
{
    // TODO: Implement this function
    return _scene;
}

inline void XRay::setScene(const Scene &scene)
{
    // TODO: Implement this function
}