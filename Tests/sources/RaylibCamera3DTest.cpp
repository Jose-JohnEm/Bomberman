/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Camera3D/Camera3D.hpp"

TEST(Camera3dTest, beginMode3DTest)
{
    try {
        Raylib::Camera3D test;
        Camera3D camera = { 0 };
        test.beginMode3D();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera settings", ex.what());
    }
}

TEST(Camera3dTest, endMode3DTest)
{
    try {
        Raylib::Camera3D test;
        test.endMode3D();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera settings", ex.what());
    }
}

TEST(Camera3dTest, setCameraModeTest)
{
    try {
        Raylib::Camera3D test;


    } catch (std::exception &ex) {

    }

}