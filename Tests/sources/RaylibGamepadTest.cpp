/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Gamepad/Gamepad.hpp"

TEST(GamepadTest, isGamepadAvailableTest)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadAvailable(1));
}

TEST(GamepadTest, isGamepadNameTest)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadName(1,"Xbox"));
}
/*
TEST(GamepadTest, getGamepadNameTest)
{
    try {
        Raylib::Gamepad test;
        test.getGamepadName(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Return gamepad internal name id", ex.what());
    }
}
*/

TEST(GamepadTest, isGamepadButtonPressed11Test)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadButtonPressed(1,1));
}

TEST(GamepadTest, isGamepadButtonDown11Test)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadButtonDown(1,1));
}

TEST(GamepadTest, isGamepadButtonReleased11Test)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadButtonReleased(1,1));
}

TEST(GamepadTest, isGamepadButtonUp11Test)
{
    Raylib::Gamepad test;
    EXPECT_EQ(false, test.isGamepadButtonUp(1,1));
}