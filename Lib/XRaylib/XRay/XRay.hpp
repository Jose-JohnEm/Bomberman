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
<<<<<<< HEAD
=======
#include "Keyboard/Keyboard.hpp"
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
#include "Color/Color.hpp"
#include "Cursor/Cursor.hpp"
#include "Timing/Timing.hpp"
#include "Drawing/Drawing.hpp"

typedef enum {
    UPPER_LEFT,
    LOW_LEFT,
    LOW_RIGHT,
    UPPER_RIGHT
} Box;

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
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        bool shouldCloseWindow(void) const override;

        /**
<<<<<<< HEAD
         * @brief Check if we are in the game scene
         *
         * @return true if we are in the game scene and false otherwise
         */
        bool isInGameScene(void) const override;

        /**
=======
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
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
        void setBestScores(const std::vector<std::pair<std::string, std::string>> &scores) override;

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
<<<<<<< HEAD
=======
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
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
         * @brief Set buffer to Draw textures
         */
        void beginDrawing(void) const override;

        /**
<<<<<<< HEAD
=======
         * @brief Set buffer to Draw textures
         * clear A boolean to know if he should clear
         */
        void beginDrawing(const bool &mustBeClear) const;

        /**
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
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
         * @param box Vector contains Box positions
         * @return true or false
         */
        bool mouseIsInBox(const std::vector<size_t> &box) const;

        /**
         * @brief Return a size_t vector contains the four corners values of a box
         *
         * @param box size_t represents upperLeftCorner
         * @param box size_t represents upperRightCorner
         * @param box size_t represents lowerLeftCorner
         * @param box size_t represents lowerRightCorner
         * @return size_t vector
         */
        std::vector<size_t> createBox(const size_t &upperLeftCorner, const size_t &upperRightCorner, const size_t &lowerLeftCorner, const size_t &lowerRightCorner) const;

        /**
<<<<<<< HEAD
         * @brief Display Menu
=======
         * @brief Display Main Menu
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
         */
        void displayMenu(void);

        /**
<<<<<<< HEAD
         * @brief Display Intro Scene
         */
        void displayTrace(void);

        /**
         * @brief Display Opening Scene
         */
        void displayIntro(void);
=======
         * @brief Display Play Scene
         */
        void playMenu(void);

        /**
         * @brief Display How to play Scene
         */
        void howToMenu(void);

        /**
         * @brief Display Settings Scene
         */
        void settingsMenu(void);

        /**
         * @brief Quit program
         */
        void quit(void);

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
        void mapScene(void);

        /**
         * @brief Display Intro Scene
         */
<<<<<<< HEAD
        void displayTrace(void);
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
=======
        void displayStudio(void);
>>>>>>> ad4eb87 (Added static keyword for all classes which can be used without instanciation)

        /**
         * @brief Display Opening Scene
         */
<<<<<<< HEAD
        void displayOpening(void);
=======
        void displayIntro(void);
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))

        /**
         * @brief This function must display the current scene. It is used in the game loop
         */
        void display(void) override;

    private:
        Raylib::Window _window;                     // Game window
<<<<<<< HEAD
        std::vector<std::string> _userNames;        // User names
        std::pair<bool, void (XRay::*)()> _intro;   // Intro pointer to function
        Scene _scene = INTRO;                       // Current scene
        std::vector<void (XRay::*)()> _scenesFunc;  // Array of pointers to function (a scene, a function)
=======
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
        std::vector<std::pair<std::string, std::string>> _bestScores;             // A vector of pair (username, score), List of Bests Scores
        std::vector<std::shared_ptr<IEntity>> _gameInfos;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
        std::vector<std::string> _backups;                                        // A vector of all the paths to backups files as a const std::vector<std::string>&
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
};

#include "XRay.inl"

#endif /* !XRAY_HPP_ */