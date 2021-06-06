/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

inline size_t Game::Map::getWidth(void) const
{
    return _width;
}

inline size_t Game::Map::getHeight(void) const
{
    return _height;
}

inline void Game::Map::setWidth(const size_t width)
{
    _width = width;
}

inline void Game::Map::setHeight(const size_t height)
{
    _height = height;
}

inline void Game::Map::create(void)
{
    _map.reserve(_height);
    for (size_t y = 0; y < _height; y++)
    {
        std::vector<char> row;
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
    for (std::vector<char> &row : _map)
    {
        std::fill(row.begin(), row.end(), character);
    }
}

inline void Game::Map::dump(void) const
{
    for (const std::vector<char> &_row : _map)
    {
        for (const char &character : _row)
        {
            std::cout << character;
        }
        std::cout << std::endl;
    }
}

inline std::vector<std::vector<char>> Game::Map::getMap(void) const
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
            _map[y][x] = '*';
            if (y == 0 || x == 0)
            {
                _map[y][x] = 'W';
            }
            else
            {
                choice = rand() % 2;
                _map[(choice) ? y : y - 1][(choice) ? x - 1 : x] = '*';
            }
        }
    }
}