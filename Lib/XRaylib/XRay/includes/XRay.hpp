/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** XRay
*/

#ifndef XRAY_HPP_
#define XRAY_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include <thread>
#include <chrono>
#include "Interfaces/IGraphical.hpp"
#include "Window/Window.hpp"
#include "Mouse/Mouse.hpp"
#include "Texture/Texture.hpp"
#include "Text/Text.hpp"
#include "Keyboard/Keyboard.hpp"
#include "Color/Color.hpp"
#include "Cursor/Cursor.hpp"
#include "Timing/Timing.hpp"
#include "Drawing/Drawing.hpp"

typedef enum {
    INTRO
} Cinematic;

class XRay : public IGraphical {

    public:
        /**
         * @brief Construct a new Ray Lib object
         */
        XRay();

        /**
         * @brief Destroy the Ray Lib object
         */
        ~XRay() override;

        /**
         * @brief Initialize window
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        void initWindow(const int &width, const int &height, const std::string &title) const override;

        /**
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        bool shouldCloseWindow(void) const override;

        /**
         * @brief This function sets the list of scores. First element of the pair is the username, the second is the score.
         *
         * @param scores A vector of pair (username, score)
         */
        void setScores(const std::vector<std::pair<std::string, std::string>> &scores) override;

        /**
         * @brief This function sets the list of bests scores. First element of the pair is the username, the second is the score.
         *
         * @param scores A vector of pair (username, score)
         */
        void setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores) override;

        /**
         * @brief This is called in a loop when the game is running. This vector contains entities that should be displayed in the game scene.
         *
         * @param gameInfos A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
         */
        void updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos) override;

        /**
         * @brief This is called in a loop when the game is running. Sets the current informations about players and their stats. The first element of the pair
         *  is the category (e.g. Score), the second is the value (e.g. 200).
         *
         * @param info A map of all the stats [PlayerName -- (NameOfStat, Value)]...
         */
        void setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info) override;

        /**
         * @brief Get the Users Names
         *
         * @return A vector of all the users names as a const std::vector<std::string>&
         */
        const std::vector<std::string> &getUserNames(void) const override;

        /**
         * @brief Returns the current scene.
         *
         * @return The scene (MAIN_MENU, GAME, END_GAME), the step where we are in the window
         */
        Scene getScene(void) const override;

        /**
         * @brief Set the current scene.
         *
         * @param scene The scene (MAIN_MENU, GAME, END_GAME), the step where we are in the window
         */
        void setScene(const Scene &scene) override;

        /**
         * @brief Get the paths to all backups files
         *
         * @return A vector of all the paths to backups files as a const std::vector<std::string>&
         */
        const std::vector<std::string> &getBackups(void) const override;

        /**
         * @brief Get the paths to all backups files
         *
         * @param A vector of all the paths to backups files as a const std::vector<std::string>&
         */
        void setBackups(const std::vector<std::string> &) override;

        /**
         * @brief Set buffer to Draw textures
         */
        void beginDrawing(void) const override;

        /**
         * @brief Set buffer to Draw textures
         * clear A boolean to know if he should clear
         */
        void beginDrawing(bool clear) const;

        /**
         * @brief Unset buffer to Draw textures
         */
        void endDrawing(void) const override;

        /**
         * @brief Close window
         */
        void closeWindow(void) const override;

        /**
         * @brief Return true if the mouse is in the region and false otherwise
         *
         * @param x Upper Left Corner
         * @param y Upper Right Corner
         * @param x_x Lower Left Corner
         * @param y_y Lower Left Corner
         * @return true or false
         */
        bool mouseIsInBox(double x, double y, double x_x, double y_y);

        /**
         * @brief Display Main Menu
         */
        void displayMenuScene(void);

        /**
         * @brief Display Play Scene
         */
        void playMenu(void);

        /**
         * @brief Display How to play Scene
         */
        void displayHowToPlayScene(void);

        /**
         * @brief Display Settings Scene
         */
        void settingsMenu(void);

        /**
         * @brief Quit program
         */
        void quitGame(void);

        /**
         * @brief Display Settings Scene
         */
        void loadGameScene(void);

        /**
         * @brief Scene for Modes
         */
        void modeScene(void);

        /**
         * @brief Scene for Maps
         */
        void displayInGameScene(void);

        /**
         * @brief Display Intro Scene
         */
        void displayTrace(void);

        /**
         * @brief Display specific cinematic
         * 
         * @param cinematic Cinematic enum type, representing specific cinematic
         */
        void displayCinematic(const Cinematic &cinematic);

        /**
         * @brief Display Opening Scene
         */
        void displayIntroCinematic(void);

        /**
         * @brief This function must display the current scene. It is used in the game loop
         */
        void display(void) override;

    private:
        Raylib::Window _window;                     // Game window
        Raylib::Mouse _mouse;                       // Game Mouse
        Raylib::Cursor _cursor;                     // Game cursor
        Raylib::Keyboard _keyboard;                   // Game keyboard

        ::Music music;
        std::vector<std::string> _userNames;        // A vector of all the users names
        std::pair<bool, void (XRay::*)()> _intro;   // Intro pointer to function
        Scene _scene = MAIN_MENU;                   // Current scene
        std::vector<void (XRay::*)()> _scenesFunc;  // Array of pointers to function (a scene, a function)

        std::array<bool, 4> playerTab = {true, true, true, true};
        std::array<bool, 4> controlsTab = {true, true, true, true};
        std::array<int, 3> allIntegers = {50, 400, 1};

        std::map<std::string, std::pair<std::string, std::string>> _playersStats; // A map of all the stats [PlayerName -- (NameOfStat, Value)]...
        std::vector<std::pair<std::string, std::string>> _scores;                 // A vector of pair (username, score)
        std::vector<std::pair<std::string, std::string>> _bestsScores;            // A vector of pair (username, score), List of Bests Scores
        std::vector<std::shared_ptr<IEntity>> _gameInfos;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
        std::vector<std::string> _backups;                                        // A vector of all the paths to backups files as a const std::vector<std::string>&
};

#include "XRay.inl"

#endif /* !XRAY_HPP_ */