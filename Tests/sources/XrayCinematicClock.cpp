/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** MapTests
*/

#include <gtest/gtest.h>
#include "../Lib/XRaylib/XRay/includes/Clock.hpp"

TEST(ClockTest, ElapsedTimepassResetfalse)
{

     Clock clock;

    EXPECT_EQ(true, clock.doesTimeElapsed(0, false));
}

TEST(ClockTest, ElapsedTimepassReseTtrue)
{
     Clock clock;

    EXPECT_EQ(true, clock.doesTimeElapsed(0, true));
}
//Clock::doesTimeElapsed(const float &time, const bool &reset)

//float Clock::getElapsedTime()

TEST(ClockTest, getElapsedTimePassTrue)
{
     Clock clock;

    EXPECT_EQ(false, clock.doesTimeElapsed(100, true));
}