/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Irrlicht
*/


inline void Irrlicht::initWindow(const int &width, const int &height, const std::string &title) const
{
}

inline bool Irrlicht::shouldCloseWindow(void) const
{
    return !(_device->run() && _driver);
}

inline void Irrlicht::closeWindow(void) const
{
}

inline void Irrlicht::drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) const
{
}

inline void Irrlicht::drawTextFont(const std::string &text, const int &posX, const int &posY, const int &fontSize, const std::string &font, const std::string &color) const
{
}

inline void Irrlicht::beginDrawing(void) const
{
}

inline void Irrlicht::endDrawing(void) const
{
}

inline void Irrlicht::display(void)
{
    (this->*_scenesFunc[_scene])();
}

inline bool Irrlicht::isInGameScene(void) const
{
    return false;
}

inline void Irrlicht::setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info)
{
    // TODO: Implement this function
}

inline void Irrlicht::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void Irrlicht::setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    // TODO: Implement this function
}

inline void Irrlicht::updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos)
{
    // TODO: Implement this function
}

inline const std::vector<std::string> &Irrlicht::getUserNames(void) const
{
    // TODO: Implement this function
    return _userNames;
}

inline IGraphical::Scene Irrlicht::getScene(void) const
{
    // TODO: Implement this function
    return _scene;
}

inline void Irrlicht::setScene(const Scene &scene)
{
    // TODO: Implement this function
}
