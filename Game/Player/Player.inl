/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

inline std::string Game::Player::getName(void) const
{
    return _name;
}

inline Raylib::Vector3 Game::Player::getPositions(void) const
{
    return _positions;
}

inline size_t Game::Player::getBrokenWalls(void) const
{
    return _brokenWalls;
}

inline size_t Game::Player::getKills(void) const
{
    return _kills;
}

inline std::array<int, 5> Game::Player::getPowerUps(void) const
{
    return _powerUps;
}

inline int Game::Player::getID(void) const
{
    return _ID;
}

inline void Game::Player::setName(const std::string &name)
{
    _name = name;
}

inline void Game::Player::setPositions(Raylib::Vector3 &positions)
{
    _positions = positions;
}

inline void Game::Player::setBrokenWalls(const size_t &brokenWalls)
{
    _brokenWalls = brokenWalls;
}

inline void Game::Player::setKills(const size_t &kills)
{
    _kills = kills;
}

inline void Game::Player::setPowerUps(const std::array<int, 5> &powerUps)
{
    _powerUps = powerUps;
}

inline void Game::Player::setID(const int &ID)
{
    _ID = ID;
}

inline std::string Game::Human::getType() const
{
    return ("Human");
}

inline std::string Game::AI::getType() const
{
    return ("AI");
}

inline void Game::Player::drawEntity()
{
    float rad_rotation = (0 * PI) / 180;

    _model.getModel().transform = {
        0, 0, 1, 0,
        cosf(rad_rotation), sinf(rad_rotation), 0, 0,
        -sinf(rad_rotation), cosf(rad_rotation), 0, 0,
        0, 0, 0, 1
    };
    DrawModelEx(_model.getModel(), _positions.getCStruct(), {0, 0, 1}, _rotation, {_scalable, _scalable, _scalable}, _color.getCStruct());
}

inline void Game::Player::setColor(const Raylib::Color &color)
{
    _color = color;
}

inline void Game::Player::setColor(const std::string &color)
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

inline void Game::Player::setShouldDisplay(const bool &shouldDisplay)
{
    _shouldDisplay = shouldDisplay;
}

inline bool Game::Player::getShouldDisplay(void) const
{
    return _shouldDisplay;
}

inline float Game::Player::getScalable(void) const
{
    return _scalable;
}

inline void Game::Player::setScalable(const float &scalable)
{
    _scalable = scalable;
}