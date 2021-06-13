/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Camera3D/Camera3D.hpp"

/*
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

TEST(Camera3dTest, setCameraMode1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraMode(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera mode", ex.what());
    }
}
*/
TEST(Camera3dTest, updateCameraTest)
{
    try {
        Raylib::Camera3D test;
        test.updateCamera();
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera update", ex.what());
    }
}

TEST(Camera3dTest, setCameraPanControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraPanControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera pan control", ex.what());
    }
}

TEST(Camera3dTest, setCameraAltControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraAltControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera altitude control", ex.what());
    }
}

TEST(Camera3dTest, setCameraSmoothZoomControl1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraSmoothZoomControl(1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera Smooth Zoom Control", ex.what());
    }
}

TEST(Camera3dTest, setCameraMoveControls1Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraMoveControls(1,1,1,1,1,1);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera move controls", ex.what());
    }
}

TEST(Camera3dTest, setCameraMoveControls0Test)
{
    try {
        Raylib::Camera3D test;
        test.setCameraMoveControls(0,0,0,0,0,0);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid camera move controls", ex.what());
    }
}

/*

TEST(Camera3dTest, drawBillboardTest)
{
    try {
        Raylib::Camera3D test;
        Raylib::Color gray;
        Image image = LoadImage("../../resources/assets/bg.png");
        Texture2D texture = LoadTextureFromImage(image);
        Rectangle rectangle = { 0., 0 , 0, 0};
        Vector3 vector = { 0.0f, 0.0f , 0.0f };
        float a = 1.0;
        auto red = gray.Gray();
        Raylib::Color color = red ;

        test.drawBillboard(texture,vector,a,red);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}

TEST(Camera3dTest, drawBillboardRecTest)
{
    try {
        Raylib::Camera3D test;
        Raylib::Color gray;
        Image image = LoadImage("../../resources/assets/bg.png");
        Texture2D texture = LoadTextureFromImage(image);
        Rectangle rectangle = { 0., 0 , 0, 0};
        Vector3 vector = { 0.0f, 0.0f , 0.0f };
        float a = 1.0;
        auto red = gray.Gray();
        Raylib::Color color = red ;

        test.drawBillboardRec(texture,rectangle,vector,a,red);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid illboard texture defined by source", ex.what());
    }
}

*/