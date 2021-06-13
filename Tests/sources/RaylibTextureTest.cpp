/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Texture/Texture.hpp"

TEST(TextureTest, setShapesTextureTest)
{
    try {
        Raylib::Texture test("default");
        Raylib::Texture texture("default");
        Raylib::Rectangle rectangle;
        texture.getCStruct();
        rectangle.getCStruct();
        test.setShapesTexture(texture,rectangle);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}

TEST(TextureTest, loadTextureTest)
{
    try {
        Raylib::Texture test("default");
        test.loadTexture("default");
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}

TEST(TextureTest, loadTextureFromImageTest)
{
    try {
        Raylib::Texture test("default");
        Raylib::Image image("default");
        test.loadTextureFromImage(image);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}

/*
TEST(TextureTest, beginTextureModeTest)
{
    try {
        Raylib::Texture test("default");
        Raylib::RenderTexture renderTexture;
        ::BeginTextureMode(renderTexture.getCStruct());
        test.beginTextureMode(renderTexture);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid billboard texture", ex.what());
    }
}
*/

