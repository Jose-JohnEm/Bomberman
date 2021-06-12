/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Game/Player/Player.hpp"

TEST(PlayerTests, name)
{
    Game::Player player;

    player.setName("PlayerName");
    EXPECT_EQ(player.getName(), "PlayerName");
}

TEST(PlayerTests, brokenWall)
{
    Game::Player player;

    player.setBrokenWalls(200);
    EXPECT_EQ(200, player.getBrokenWalls());

}

TEST(PlayerTests, kills)
{
    Game::Player player;

    player.setKills(2);
    EXPECT_EQ(player.getKills(), 2);
}

TEST(PlayerTests, positions)
{
    Game::Player player;

    player.setPositions({30, 40});
    EXPECT_EQ(player.getPositions().first, 30);
    EXPECT_EQ(player.getPositions().second, 40);
}

TEST(PlayerTests, powerUps)
{
    Game::Player player;

    player.setPowerUps({1, 0, 1, 1, 0});
    std::array<size_t, 5> powerups = player.getPowerUps();

    EXPECT_EQ(powerups[P_SKATE], 1);
    EXPECT_EQ(powerups[P_BOMB], 0);
    EXPECT_EQ(powerups[P_PASS], 1);
    EXPECT_EQ(powerups[P_FIRE], 1);
    EXPECT_EQ(powerups[P_LIFE], 0);
}