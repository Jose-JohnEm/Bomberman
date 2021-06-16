/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Animated.inl
*/

inline Raylib::Vector3 Game::Animated::getPositions(void) const
{
    return _positions;
}

inline void Game::Animated::setPositions(Raylib::Vector3 &positions)
{
    _positions = positions;
}

inline void Game::Animated::drawEntity()
{
    std::cout << "-- I will update --" << std::endl;
    _model.update();

    std::cout << "-- I will display --" << std::endl;

    DrawModelEx(_model.getModel(), _positions.getCStruct(), {1, 0, 0}, 90, {_scalable, _scalable, _scalable}, _color.getCStruct());
}

inline void Game::Animated::setColor(const Raylib::Color &color)
{
    _color = color;
}

inline void Game::Animated::setColor(const std::string &color)
{
    if (color.compare("Blue") == 0
    || color.compare("Green") == 0
    || color.compare("Yellow") == 0
    || color.compare("Red") == 0)
    {
        std::map<std::string, Raylib::Color> colors = {
            {"Blue", Raylib::Color::Blue()},
            {"Green", Raylib::Color::Green()},
            {"Yellow", Raylib::Color::Yellow()},
            {"Red", Raylib::Color::Red()}
        };
        setColor(colors[color]);
    }
}

inline void Game::Animated::setShouldDisplay(const bool &shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

inline bool Game::Animated::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

inline float Game::Animated::getScalable(void) const
{
    return _scalable;
}

inline void Game::Animated::setScalable(const float &scalable)
{
    _scalable = scalable;
}

inline int Game::Bomb::makeExplode()
{
    return _fire;
}

inline bool Game::Bomb::isExploding()
{
    return clock.doesTimeElapsed(3, false);
}

inline bool Game::Bomb::hasExplode()
{
    return clock.doesTimeElapsed(4, false);
}