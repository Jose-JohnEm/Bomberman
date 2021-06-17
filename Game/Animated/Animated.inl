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
    float rad_rotation = (0 * PI) / 180;

    if (!_moving)
        _model.makeEmote();
    else
        _moving = false;

    _model.update();
    _model.getModel().transform = {
        0, 0, 1, 0,
        cosf(rad_rotation), sinf(rad_rotation), 0, 0,
        -sinf(rad_rotation), cosf(rad_rotation), 0, 0,
        0, 0, 0, 1
    };
    DrawModelEx(_model.getModel(), _positions.getCStruct(), {0, 0, 1}, _rotation, {_scalable, _scalable, _scalable}, _color.getCStruct());
}

inline void Game::Bomb::drawEntity()
{
    Raylib::Vector3 pos = Animated::getPositions();

    if (_bZoneX.first != 0 && _bZoneX.second != 0 && _bZoneY.first != 0 && _bZoneY.second != 0)
    {
        for (int i = 0; i < _bZoneX.second; i++)
            DrawCube({(float)_bZoneX.first + i, pos.y, pos.z}, 1 , 1, 1, RED);
        for (int i = 0; i < _bZoneY.second; i++)
            DrawCube({pos.x, (float)_bZoneY.first - i, pos.z}, 1, 1, 1, RED);
        //DrawCircle3D(Animated::getPositions().getCStruct(), 2, {0,0,0}, 0, RED);
    }
    Animated::drawEntity();
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
    _explosing = false;
    return _fire;
}

inline bool Game::Bomb::isExploding()
{
    return _explosing;
}

inline bool Game::Bomb::hasExplode()
{
    return _exploded;
}

inline std::string Game::Bomb::getType() const
{
    return "Bomb";
}

inline void Game::Bomb::update()
{
    if (clock.doesTimeElapsed(4, false))
    {
        _explosing = false;
        _exploded = true;
    }
    else if (clock.doesTimeElapsed(3, false) && _bZoneX.first == 0 && _bZoneX.second == 0 && _bZoneY.first == 0 && _bZoneY.second == 0)
        _explosing = true;
}

inline void Game::Bomb::setBombzone(std::vector<std::string> map)
{

    std::cout << "Map apres la bombe" << std::endl;
    for (auto line: map)
        std::cout << line << std::endl;
    std::cout << std::endl << std::endl<< std::endl;

    Raylib::Vector3 pos = Animated::getPositions();


    std::cout << "Position de la bombe {" << pos.x << ", " << pos.y << "}" << std::endl;

    pos.y = map.size() - pos.y;


    _bZoneX.first = (int)pos.x;
    _bZoneX.second = 0;

    for (int i = 1; map[pos.y][pos.x - i] == 'X'; i++)
        _bZoneX.first--;
    for (int i = 0; map[pos.y][_bZoneX.first + i] == 'X'; i++)
        _bZoneX.second++;

    _bZoneY.first = (int)pos.y;
    _bZoneY.second = 0;

    for (int i = 1; map[pos.y - i][pos.x] == 'X'; i++)
        _bZoneY.first--;
    for (int i = 0; map[_bZoneY.first + i][pos.x] == 'X'; i++)
        _bZoneY.second++;

    _bZoneY.first = map.size() - _bZoneY.first;
    std::cout << "BZoneX {" << _bZoneX.first << ", " << _bZoneX.second << "}" << std::endl;
    std::cout << "BZoneY {" << _bZoneY.first << ", " << _bZoneY.second << "}" << std::endl;
}