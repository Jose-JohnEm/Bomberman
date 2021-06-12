/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

inline size_t Game::Map::getWidth(void) const
{
    return _width - BORDER;
}

inline size_t Game::Map::getHeight(void) const
{
    return _height - BORDER;
}

inline void Game::Map::setWidth(const size_t width)
{
    _width = width + BORDER;
}

inline void Game::Map::setHeight(const size_t height)
{
    _height = height + BORDER;
}

inline void Game::Map::create(void)
{
    _map.reserve(_height);
    for (size_t y = 0; y < _height; y++)
    {
        std::string row;
        row.reserve(_width);
        for (size_t x = 0; x < _width; x++)
        {
            row.push_back('0');
        }
        _map.push_back(row);
    }
}

inline void Game::Map::fill(const char &character)
{
    for (std::string &row : _map)
    {
        std::fill(row.begin(), row.end(), character);
    }
}

inline void Game::Map::dump(void) const
{
    for (const std::string &row : _map)
    {
        for (const char &character : row)
        {
            std::cout << character;
        }
        std::cout << std::endl;
    }
}

inline std::vector<std::string> Game::Map::getMap(void) const
{
    return _map;
}

inline void Game::Map::maze(void)
{
    int choice = 0;

    for (size_t y = 0; y < _height; y += 2)
    {
        for (size_t x = 0; x < _width; x += 2)
        {
            _map[y][x] = EMPTY_SPACE;
            if (y != 0 && x != 0)
            {
                choice = rand() % 2;
                _map[(choice) ? y : y - 1][(choice) ? x - 1 : x] = EMPTY_SPACE;
            }
        }
    }
}

inline void Game::Map::placeBorders(void)
{
    // Place upper and lower borders
    std::fill(_map[0].begin(), _map[0].end(), EDGE);
    std::fill(_map[_height - 1].begin(), _map[_height - 1].end(), EDGE);
    // Place left and right borders
    for (size_t y = 0; y < _height; y++)
    {
        for (size_t x = 0; x < _width; x++)
        {
            if (x == 0 || x == _width - 1)
            {
                _map[y][x] = EDGE;
            }
        }
    }
}

inline void Game::Map::placePlayers(void)
{
    if (!(1 <= _playersNumber && _playersNumber <= 4))
    {
        throw std::invalid_argument("ERROR: Invalid number of players");
    }
    for (size_t i = 1; i <= _playersNumber; i++)
    {
        if (i == 1)
        {
            _map[1][1] = PLAYER_ONE;
        }
        else if (i == 2)
        {
            _map[_height - BORDER][1] = PLAYER_TWO;
        }
        else if (i == 3)
        {
            _map[_height - BORDER][_width - BORDER] = PLAYER_THREE;
        }
        else
        {
            _map[1][_width - BORDER] = PLAYER_FOUR;
        }
    }
}

inline void Game::Map::placeSolidWalls(void)
{
    for (size_t y = 2; y < _height - 1; y += 2)
    {
        for (size_t x = 2; x < _width - BORDER; x += 2)
        {
            _map[y][x] = SOLID_WALL;
        }
    }
}

inline void Game::Map::setPlayersAreas(const size_t &areaSize)
{
    for (size_t player = 1; player <= _playersNumber; player++)
    {
        for (size_t i = 1; i <= areaSize; i++)
        {
            switch (player)
            {
                case 1:
                    _map[1][1 + i] = EMPTY_SPACE;
                    _map[1 + i][1] = EMPTY_SPACE;
                    break;
                case 2:
                    _map[_height - BORDER][1 + i] = EMPTY_SPACE;
                    _map[_height - BORDER - i][1] = EMPTY_SPACE;
                    break;
                case 3:
                    _map[_height - BORDER][_width - BORDER - i] = EMPTY_SPACE;
                    _map[_height - BORDER - i][_width - BORDER] = EMPTY_SPACE;
                case 4:
                    _map[1][_width - BORDER - i] = EMPTY_SPACE;
                    _map[1 + i][_width - BORDER] = EMPTY_SPACE;
                default:
                    break;
            }
        }
    }
}

inline void Game::Map::setMap(const std::vector<std::string> &map)
{
    _map = map;
}