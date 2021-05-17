/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

inline void Raylib::XRay::initWindow(const int &width, const int &height, const std::string &title) const
{
    _window.initWindow(width, height, title);
}

inline bool Raylib::XRay::shouldCloseWindow(void) const
{
    return _window.windowShouldClose();
}

inline void Raylib::XRay::closeWindow(void) const
{
    _window.closeWindow();
}

inline void Raylib::XRay::drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) const
{
    Text tmpText;

    tmpText.drawText(text, posX, posY, fontSize, Color::Black());
}

inline void Raylib::XRay::drawTextFont(const std::string &text, const int &posX, const int &posY, const int &fontSize, const std::string &font, const std::string &color) const
{
    Text tmpText;
    Color tmpColor;

    tmpText.drawTextEx(font, text, std::make_pair(posX, posY), fontSize, 1, tmpColor.getColor(color));
}

inline void Raylib::XRay::beginDrawing(void) const
{
    Drawing drawing;

    drawing.beginDrawing();
    drawing.clearBackground(Color::Black());
}

inline void Raylib::XRay::endDrawing(void) const
{
    Drawing drawing;

    drawing.endDrawing();
}

inline void Raylib::XRay::display(void)
{
    (this->*_scenesFunc[_scene])();
}

inline bool Raylib::XRay::isInGameScene(void) const
{
    return false;
}

inline void Raylib::XRay::setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info)
{
    // TODO: Implement this function
}

inline void Raylib::XRay::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void Raylib::XRay::setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void Raylib::XRay::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    // TODO: Implement this function
}

inline const std::vector<std::string> &Raylib::XRay::getUserNames(void) const
{
    // TODO: Implement this function
    return _userNames;
}

inline IGraphical::Scene Raylib::XRay::getScene(void) const
{
    // TODO: Implement this function
    return _scene;
}

inline void Raylib::XRay::setScene(const Scene &scene)
{
    // TODO: Implement this function
}