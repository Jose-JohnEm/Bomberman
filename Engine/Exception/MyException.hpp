/*
** MyException.hpp for B-YEP-400-LYN-4-1-indiestudio-lucas.guichard in /Users/charlesvictormahouve/delivery/B-YEP-400-LYN-4-1-indiestudio-lucas.guichard/Engine/Exception
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  Fri Jun 18 3:56:43 PM 2021 charles mahouve
** Last update Sat Jun 18 3:58:39 PM 2021 charles mahouve
*/
#include <vector>
#include <istream>
#include <algorithm>
#include <iostream>
#include <exception>
#include <cassert>
#include <assert.h>

#ifndef MYEXCEPTION_HPP_
#define MYEXCEPTION_HPP_

namespace Engine
{
    class MyException : public std::exception
    {

    public:
        /**
         * @brief Detect if a certain functions hits and exception
         *
         * @param file
         * @param line
         * @param func
         * @param info
         * @return info // about the type of exception that occured
         * @return func // the name of the aforomentioned function
         */
        MyException(const char *msg, const char *file_, int line_, const char *func_, const char *info_ = "") : std::exception(),
        file(file_),line(line_),func(func_),info(info_)
        {
        }

         /**
         * @brief gzt the file
         */
        const char *get_file() const { return file; }

        /**
         * @brief gt the line
         */
        int get_line() const { return line; }

        /**
         * @brief gt the function
         */
        const char *get_func() const { return func; }

        /**
         * @brief gt the type of exceptions
         */

        const char *get_info() const { return info; }

        // all the functions taht test here in static with comments
        //XRAY
        static int catchThrowTrydisplayStudio();
        static int catchThrowTrydisplayTeamPresentation();
        static int catchThrowTryplayMusic();
        static int catchThrowTryplayAndUpdateMusic();
        static int catchThrowTrygoToAnotherSceneFromVictory();
        static int catchThrowTrydisplayVictoryScene();
        static int catchThrowTryupdateTransitionManager();
        static int catchThrowTrydisplaySettingsScene();
        static int catchThrowTrychangeMusicVolume();
        static int catchThrowTrychangeSfxVolume();
        static int catchThrowTrydetectPlayerInput();
        static int catchThrowTryremovePlayer();
        static int catchThrowTryaddPlayer();
        static int catchThrowTrymanageNextOrPrev();
        static int catchThrowTrydisplayCardsSettings();
        static int catchThrowTrydisplayBack();
        static int catchThrowTrydisplayPlayerChoiceScene();
        static int catchThrowTryshouldGoToEast();
        static int catchThrowTryshouldGoToWest();
        static int catchThrowTryshouldGoToNorth();
        static int catchThrowTryshouldGoToSouth();
        static int catchThrowTryshouldChangeToPrev();
        static int catchThrowTryshouldChangeToNext();
        static int catchThrowTryshouldSimulateAClick();
        static int catchThrowTryupdate();
        static int catchThrowTrymakeWalk();
        static int catchThrowTrymakeBomb();
        static int catchThrowTrymakeEmote();
        static int catchThrowTrydisplayMenuScene();
        static int catchThrowTrydisplayGameSettings();
        static int catchThrowTrycheckClickOnMapChoiceScene();
        static int catchThrowTrydisplayMapChoiceScene();
        static int catchThrowTryloadThisBackup();
        static int catchThrowTrydisplayLoadGameScene();
        static int catchThrowTryKeyboardException();
        static int catchThrowTryupdateGamepad();
        static int catchThrowTrygetTimeInFormat();
        static int catchThrowTrydrawPlayersHead();
        static int catchThrowTrydisplayPlayersPanels();
        static int catchThrowTrydisplayPauseScene();
        static int catchThrowTrydgoToAnotherScene();
        static int catchThrowTrymanagePlayersActions();
        static int catchThrowTrydisplayInGameScene();
        static int catchThrowTrydisplayHowToPlayScene();
        static int catchThrowTryGamepadException();
        static int catchThrowTrygoToAnotherSceneFromDefeat();
        static int catchThrowTrydisplayDefeatScenet();
        static int catchThrowTrydoesTimeElapsed();
        static int catchThrowTrygetElapsedTime();
        static int catchThrowTrydisplayCinematic();

        // RAYLIB_SRCS
        static int catchThrowTrywindowShouldClose();
        static int catchThrowTrycloseWindow();
        static int catchThrowTrysetWindowIcon();
        static int catchThrowTryisWindowFullscreen();
        static int catchThrowTrytoggleFullscreen();
        static int catchThrowTrysetTargetFPS();
        static int catchThrowTrygetFPSS();
        static int catchThrowTrygetFrameTime();
        static int catchThrowTrygetTime();
        static int catchThrowTrydrawText();
        static int catchThrowTrymeasureText();
        static int catchThrowTrytextIsEqual();
        static int catchThrowTrytextLength();
        static int catchThrowTryRectangle();
        static int catchThrowTrydrawRectangleV();
        static int catchThrowTrydrawRectanglePro();
        static int catchThrowTryunloadMusic();
        static int catchThrowTryisButtonPressed();
        static int catchThrowTryisButtonDown();
        static int catchThrowTryisButtonReleased();
        static int catchThrowTryisButtonUp();
        static int catchThrowTrygetMouseX();
        static int catchThrowTrygetMouseY();
        static int catchThrowTryisKeyPressed();
        static int catchThrowTryisKeyDown();
        static int catchThrowTryisKeyReleased();
        static int catchThrowTryisKeyUp();
        static int catchThrowTrygetKeyPressed();
        static int catchThrowTrygetCharPressed();

    private:
        /// This stores the file name
        const char *file;
        /// This stores the actiual line
        int line;
        /// This stores the function
        const char *func;
        /// This stores  the exception info
        const char *info;
    };

} // namespace Engine

#endif /* !MYEXCEPTION_HPP_ */
