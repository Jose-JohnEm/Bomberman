/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/MousePlayerInput.hpp"

//MousePlayerInput::MousePlayerInput(size_t pos)
/*
TEST(MousePlayerTest, passWith1)
{

    IPlayerInput::MousePlayerInput input;
    input.MousePlayerInput(1);
    
    EXPECT_EQ(input.MousePlayerInput(1), 1);

}

TEST(MousePlayerTest, passWith0)
{
    try {
        MousePlayerInput::MousePlayerInput MousePlayerInput(0)
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid gamepad player inputs", ex.what());
    }
}

TEST(MousePlayerTest, passWithNull)
{
    try {
        MousePlayerInput::MousePlayerInput MousePlayerInput()
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid gamepad player inputs", ex.what());
    }
}

*/

//MousePlayerInput::shouldGoToEast(void) const
// to fixxxxxxx

TEST(MousePlayerTest, shouldGoToEast)
{
    MousePlayerInput input;

    auto res = input.shouldGoToEast();
    
    EXPECT_EQ(4,res);
}

TEST(MousePlayerTest, shouldGoToWest)
{
    MousePlayerInput input;

    auto res = input.shouldGoToWest();
    
    EXPECT_EQ(2,res);
}

TEST(MousePlayerTest, shouldGoToNorth)
{

    MousePlayerInput input;

    auto res = input.shouldGoToNorth();
    
    EXPECT_EQ(1,res);
}

TEST(MousePlayerTest, shouldGoToSouth)
{
    MousePlayerInput input;

    auto res = input.shouldGoToSouth();
    
    EXPECT_EQ(3,res);
}

TEST(MousePlayerTest, shouldChangeToPrev)
{
    MousePlayerInput input;

    auto res = input.shouldChangeToPrev();
    
    EXPECT_EQ(4,res);
}

TEST(MousePlayerTest, shouldChangeToNext)
{
    MousePlayerInput input;

    auto res = input.shouldChangeToNext();
    
    EXPECT_EQ(2,res);
}

TEST(MousePlayerTest, shouldSimulateAClick)
{
    MousePlayerInput input;

    auto res = input.shouldSimulateAClick();
    
    EXPECT_EQ(7,res);
}