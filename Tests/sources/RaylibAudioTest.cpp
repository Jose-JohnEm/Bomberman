/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** PlayerTests
*/

#include <gtest/gtest.h>
#include "../Tests/Lib/XRaylib/Raylib/Audio/Audio.hpp"



TEST(AudioTest, initAudioDeviceTest)
{
    try {
        Audio test;
        test.initAudioDevice(void);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(AudioTest, initAudioDeviceTest)
{
    try {
        Audio test;
        test.closeAudioDevice(void;
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid map dimensions", ex.what());
    }
}

TEST(AudioTest, isAudioDeviceReady)
{
    Audio test;

    auto res = input.isAudioDeviceReady(void);
    
    EXPECT_EQ(true,res);
}

TEST(AudioTest, setMasterVolume1)
{
    try {
        Audio test;
        test.setMasterVolume(1.0);
    } catch (std::exception &ex) {
        EXPECT_STREQ("ERROR: Invalid volume parameters", ex.what());
    }
}