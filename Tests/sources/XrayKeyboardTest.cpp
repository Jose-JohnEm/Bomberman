/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/KeyboardPlayerInput.hpp"

//KeyboardPlayerInput::KeyboardPlayerInput(size_t pos)
/*
TEST(KeyboardTest, pass)
{
    try {
        KeyboardPlayerInput input;
        auto res = input.KeyboardPlayerInput()
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Keyboard player inputs", ex.what());
    }
}
*/
//KeyboardPlayerInput::shouldGoToEast(void) const

TEST(KeyboardTest, shouldGoToEast)
{

    KeyboardPlayerInput input;

    auto res = input.shouldGoToEast();
    
    EXPECT_EQ(false,res);
}


TEST(KeyboardTest, shouldGoToWest)
{
    KeyboardPlayerInput input;

    auto res = input.shouldGoToWest();
    
    EXPECT_EQ(false,res);
}

TEST(KeyboardTest, shouldGoToNorth)
{

    KeyboardPlayerInput input;

    auto res = input.shouldGoToNorth();
    
    EXPECT_EQ(false,res);
}

TEST(KeyboardTest, shouldGoToSouth)
{
    KeyboardPlayerInput input;

    auto res = input.shouldGoToSouth();
    
    EXPECT_EQ(false,res);
}

TEST(KeyboardTest, shouldChangeToPrev)
{
    KeyboardPlayerInput input;

    auto res = input.shouldChangeToPrev();
    
    EXPECT_EQ(false,res);
}

TEST(KeyboardTest, shouldChangeToNext)
{
    KeyboardPlayerInput input;

    auto res = input.shouldChangeToNext();
    
    EXPECT_EQ(false,res);
}

TEST(KeyboardTest, shouldSimulateAClick)
{
    KeyboardPlayerInput input;

    auto res = input.shouldSimulateAClick();
    
    EXPECT_EQ(false,res);
}
