/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/GamepadPlayerInput.hpp"

//GamepadPlayerInput::GamepadPlayerInput(size_t pos)
/*
TEST(GamePadTest, passWith1)
{

    IPlayerInput::GamepadPlayerInput input;
    input.GamepadPlayerInput(1);
    
    EXPECT_EQ(input.GamepadPlayerInput(1), 1);

}

TEST(GamePadTest, passWith0)
{
    try {
        GamepadPlayerInput::GamepadPlayerInput GamepadPlayerInput(0)
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid gamepad player inputs", ex.what());
    }
}

TEST(GamePadTest, passWithNull)
{
    try {
        GamepadPlayerInput::GamepadPlayerInput GamepadPlayerInput()
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid gamepad player inputs", ex.what());
    }
}

*/

//GamepadPlayerInput::shouldGoToEast(void) const

TEST(GamePadTest, shouldGoToEast)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToEast();
    
    EXPECT_EQ(4,res);
}

TEST(GamePadTest, shouldGoToWest)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToWest();
    
    EXPECT_EQ(2,res);
}

TEST(GamePadTest, shouldGoToNorth)
{

    GamepadPlayerInput input;

    auto res = input.shouldGoToNorth();
    
    EXPECT_EQ(1,res);
}

TEST(GamePadTest, shouldGoToSouth)
{
    GamepadPlayerInput input;

    auto res = input.shouldGoToSouth();
    
    EXPECT_EQ(3,res);
}

TEST(GamePadTest, shouldChangeToPrev)
{
    GamepadPlayerInput input;

    auto res = input.shouldChangeToPrev();
    
    EXPECT_EQ(4,res);
}

TEST(GamePadTest, shouldChangeToNext)
{
    GamepadPlayerInput input;

    auto res = input.shouldChangeToNext();
    
    EXPECT_EQ(2,res);
}

TEST(GamePadTest, shouldSimulateAClick)
{
    GamepadPlayerInput input;

    auto res = input.shouldSimulateAClick();
    
    EXPECT_EQ(7,res);
}

