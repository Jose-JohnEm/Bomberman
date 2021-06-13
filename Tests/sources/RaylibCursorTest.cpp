/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Cursor/Cursor.hpp"

TEST(CursorTest, showCursorTest)
{
    try {
        Raylib::Cursor test;
        test.showCursor();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid Shows cursor", ex.what());
    }
}

TEST(CursorTest, hideCursorTest)
{
    try {
        Raylib::Cursor test;
        test.hideCursor();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid hide cursor", ex.what());
    }
}

TEST(CursorTest, isCursorHiddenTestTrue)
{
    Raylib::Cursor test;
    EXPECT_EQ(true, test.isCursorHidden());
}

TEST(CursorTest, isCursorHiddenTestFalse)
{
    Raylib::Cursor test;
    EXPECT_EQ(false, test.isCursorHidden());
}

TEST(CursorTest, enableCursorTest)
{
    try {
        Raylib::Cursor test;
        test.enableCursor();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid enable cursor", ex.what());
    }
}

TEST(CursorTest, disableCursorTest)
{
    try {
        Raylib::Cursor test;
        test.disableCursor();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid disable cursor", ex.what());
    }
}

TEST(CursorTest, isCursorOnScreenTestTrue)
{
    Raylib::Cursor test;
    EXPECT_EQ(true, test.isCursorOnScreen());
}

TEST(CursorTest, isCursorOnScreenTestFalse)
{
    Raylib::Cursor test;
    EXPECT_EQ(false, test.isCursorOnScreen());
}