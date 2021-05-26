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
#include "Box.hpp"
#include "Cinematic.hpp"
#include "Resources.hpp"
#include "Input.hpp"

class XRay : public IGraphical {

    public:

    // TODO: Créer une classe pour le bail de gamepad dans xray là bon travail lucas
        enum GamePadTouch {
            UP,
            RIGHT,
            DOWN,
            LEFT,
            TRIANGLE,
            ROND,
            CROIX,
            CARRE,
            L1,
            L2,
            R1,
            R2,
            SHARE,
            UNKNOWN,
            OPTIONS,
            L3,
            R3
        };


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
        void beginDrawing(const bool &mustBeClear) const;

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
         * @brief Display Main Menu
         */
        void displayMenuScene(void);

        /**
         * @brief Display Play Scene
         */
        void displayGameModeScene(void);

        /**
         * @brief Display How to play Scene
         */
        void displayHowToPlayScene(void);

        /**
         * @brief Display Settings Scene
         */
        void displaySettingsScene(void);

        /**
         * @brief Quit program
         */
        void quitGame(void);

        /**
         * @brief Display Settings Scene
         */
        void displayLoadGameScene(void);

        /**
         * @brief Scene for Modes
         */
        void displayPlayerChoiceScene(void);

        /**
         * @brief Scene for Maps
         */
        void displayInGameScene(void);

        /**
         * @brief Display Intro Scene
         */
        void displayStudio(void);

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

        // TODO: documentation
        void setTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> &textBox);
        void updateTextBox(std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox);
        void setAddBox(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, const int &a);
        void addPlayer(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox);
        void removePlayer(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, std::vector<bool> &mouseOnText, std::vector<::Rectangle> textBox);
        void displayCards(const std::vector<bool> &mouseOnText, const std::vector<::Rectangle> &textBox);
        void displayMouse(void) const;
        void setResources(void);
        void displayCardsSettings(std::vector<std::pair<int, int>> &removePos, std::vector<std::pair<int, int>> &nextTab, std::vector<std::pair<int, int>> &prevTab, int *a);

    private:
        Raylib::Window _window;                     // Game window

        ::Music music;
        std::vector<std::string> _userNames;        // A vector of all the users names
        std::pair<bool, void (XRay::*)()> _intro;   // Intro pointer to function
        Scene _scene = MENU;                   // Current scene
        std::vector<void (XRay::*)()> _scenesFunc;  // Array of pointers to function (a scene, a function)

        std::vector<bool> _playerTab;
        std::vector<bool> _controlsTab;
        std::array<int, 3> _allIntegers = {50, 400, 1};
        std::vector<std::pair<int, int>> _letterAndFrame;

        std::map<std::string, std::pair<std::string, std::string>> _playersStats; // A map of all the stats [PlayerName -- (NameOfStat, Value)]...
        std::vector<std::pair<std::string, std::string>> _scores;                 // A vector of pair (username, score)
        std::vector<std::pair<std::string, std::string>> _bestScores;             // A vector of pair (username, score), List of Bests Scores
        std::vector<std::shared_ptr<IEntity>> _gameInfos;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
        std::vector<std::string> _backups;                                        // A vector of all the paths to backups files as a const std::vector<std::string>&
        std::vector<Raylib::Texture> _textures;

        std::map<Resources, std::shared_ptr<Raylib::Texture>> _resources;
};

#include "XRay.inl"

#endif /* !XRAY_HPP_ */