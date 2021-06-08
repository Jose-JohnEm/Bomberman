/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Map
*/

#include "MapGeneration.hpp"

MapGeneration::MapGeneration()
{
    
}

MapGeneration::MapGeneration(const size_t &width, const size_t &height)
    : _width{width + BORDER}, _height{height + BORDER}
{
    if (width % 2 == 0 || width <= 3 || height < 3)
    {
        throw std::length_error("ERROR: Invalid map dimensions");
    }
    srand(time(NULL));
    create();
    fill(BREAK_WALL);
    maze();
    placeBorders();
    placeSolidWalls();
}

MapGeneration::~MapGeneration()
{
}

size_t MapGeneration::getWidth(void) const
{
    return _width - BORDER;
}

size_t MapGeneration::getHeight(void) const
{
    return _height - BORDER;
}

void MapGeneration::setWidth(const size_t width)
{
    _width = width + BORDER;
}

void MapGeneration::setHeight(const size_t height)
{
    _height = height + BORDER;
}

void MapGeneration::create(void)
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

void MapGeneration::fill(const char &character)
{
    for (std::string &row : _map)
    {
        std::fill(row.begin(), row.end(), character);
    }
}

void MapGeneration::dump(void) const
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

std::vector<std::string> MapGeneration::getMap(void) const
{
    return _map;
}

void MapGeneration::maze(void)
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

void MapGeneration::placeBorders(void)
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

void MapGeneration::placePlayers(const size_t &playersNumber)
{
    if (!(1 <= playersNumber && playersNumber <= 4))
    {
        throw std::invalid_argument("ERROR: Invalid number of players");
    }
    for (size_t i = 1; i <= playersNumber; i++)
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

void MapGeneration::placeSolidWalls(void)
{
    for (size_t y = 2; y < _height - 1; y += 2)
    {
        for (size_t x = 2; x < _width - BORDER; x += 2)
        {
            _map[y][x] = SOLID_WALL;
        }
    }
}