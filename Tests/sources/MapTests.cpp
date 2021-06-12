/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "../Game/Map/Map.hpp"

TEST(MapTest, pass)
{
    try {
        Game::Map map(15, 15, 4);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_width_dimension)
{
    try {
        Game::Map map(0, 15, 4);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_height_dimension)
{
    try {
        Game::Map map(15, 0, 4);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(MapTest, fail_player)
{
    try {
        Game::Map map(15, 15, 0);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid number of players", ex.what());
    }
}

TEST(MapTest, getWidth)
{
    Game::Map map(15, 15, 4);

    EXPECT_EQ(15, map.getWidth());
}

TEST(MapTest, getHeight)
{
    Game::Map map(15, 15, 4);

    EXPECT_EQ(15, map.getHeight());
}

TEST(MapTest, setWidth)
{
    Game::Map map(15, 15, 4);

    map.setWidth(21);
    EXPECT_EQ(21, map.getWidth());
}

TEST(MapTest, setHeight)
{
    Game::Map map(15, 15, 4);

    map.setHeight(21);
    EXPECT_EQ(21, map.getHeight());
}

TEST(MapTest, isMapEmpty)
{
    Game::Map map(15, 15, 4);

    EXPECT_EQ(map.getMap().empty(), false);
}