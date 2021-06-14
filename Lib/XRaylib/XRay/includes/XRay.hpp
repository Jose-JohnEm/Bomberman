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
#include <array>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include <thread>
#include <chrono>
#include <iterator>
#include <filesystem>
#include <thread>
#ifdef __linux__
    #include <dirent.h>
#endif

#include "IPlayerInput.hpp"
#include "MousePlayerInput.hpp"
#include "KeyboardPlayerInput.hpp"
#include "GamepadPlayerInput.hpp"
#include "Interfaces/IGraphical.hpp"
#include "Camera3D/Camera3D.hpp"
#include "Texture/Texture.hpp"
#include "Window/Window.hpp"
#include "Mouse/Mouse.hpp"
#include "Texture/Texture.hpp"
#include "Text/Text.hpp"
#include "Keyboard/Keyboard.hpp"
#include "Color/Color.hpp"
#include "Music/Music.hpp"
#include "Cursor/Cursor.hpp"
#include "Timing/Timing.hpp"
#include "Drawing/Drawing.hpp"
#include "Collision2D/Collision2D.hpp"
#include "Vector2/Vector2.hpp"
#include "Box.hpp"
#include "Cinematic.hpp"
#include "Resources.hpp"
#include "Input.hpp"
#include "PlayerSelector/Player.hpp"
#include "PlayerSelector/Selector.hpp"
#include "Audio/Audio.hpp"
#include "Sound/Sound.hpp"

class XRay : public IGraphical {

    public:

        /**
         * @brief Construct a new Ray Lib object
         */
        XRay(void);

        /**
         * @brief Destroy the Ray Lib object
         */
        ~XRay(void) override;

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
         * @param info A vector of vector of all the stats [Player -- (NameOfStat, Value)]...
         */
        void setPlayersStats(const std::vector<std::vector<std::pair<std::string, std::string>>> &info) override;

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
         * @brief Set the Map
         *
         * @param map A const std::vector<std::string>&
         */
        void setMap(std::vector<std::string> &map) override;

        /**
         * @brief Get Map Size and Type

         * @return A pair of size_t
         */
        std::pair<size_t, size_t> getMapSizeAndType() override;

        /**
         * @brief Get Game Settings
         *
         * @return An array of 8 size_t
         */
        std::array<size_t, 8> getGameSettings() override;

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
         * @brief Change the volume of all the music
         */
        void changeMusicVolume(void);

        /**
         * @brief Change the volume of all the sfx
         */
        void changeSfxVolume(void);

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
        void displayPlayerChoiceScene();

        /**
         * @brief Scene for Game
         */
        void displayInGameScene(void);

        /**
         * @brief Scene for Maps
         */
        void displayMapChoiceScene(void);

        /**
         * @brief Display Intro Scene
         */
        void displayStudio(void);

        /**
         * @brief Go to Another Scene
         */
        void goToAnotherScene();

        /**
         * @brief Go to Another Scene
         */
        void goToAnotherSceneFromVictory();

        /**
         * @brief Go to Another Scene
         */
        void goToAnotherSceneFromDefeat();

        /**
         * @brief Display specific cinematic
         *
         * @param cinematic Cinematic enum type, representing specific cinematic
         */
        void displayCinematic(const Cinematic &cinematic);

        /**
         * @brief Display a specific cinematic
         *
         * @param cinematicPathDirectory A string related to the specific cinematic directory
         * @param hideSkip A size_t corresponding to the cinematic frame when you must hide the skip button
         * @param gap Duration between each frame
         */
        void displayCinematic(const std::string &cinematicPathDirectory, const size_t &hideSkip = 0, const size_t &gap = 0) const;

        /**
         * @brief This function must display the current scene. It is used in the game loop
         */
        void display(void) override;

        /**
         * @brief This function manages the click on the different previous and next buttons
         */
        void manageNextOrPrev(void);

        /**
         * @brief Adds a new player to the board, if the limit is not exceeded.
         */
        void addPlayer(void);

        /**
         * @brief Remove the player of the board.
         *
         * @param removeButtons A vector of all remove buttons coordinates
         */
        void removePlayer(const std::vector<std::pair<int, int>> &removeButtons);

        /**
         * @brief This function display the mouse
         */
        void displayMouse(void) const;

        /**
         * @brief Set the Resources
         */
        void setResources(void);

        /**
         * @brief Set the Audio
         */
        void setAudioResources(void);

        /**
         * @brief Play a music in a thread
         */
        void playAndUpdateMusic(MusicResources music);

        /**
         * @brief Display Game Settings
         */
        void displayGameSettings(void);

        /**
         * @brief Detect New Input
         */
        void detectPlayerInput(void);

        /**
         * @brief Diplay Background Parallax
         */
        void displayBack(void);

        /**
         * @brief Display Pause Button and pause panel
         */
        void displayPauseScene(void);

        /**
         * @brief Load a game
         *
         * @param _pathToBackupFile A string that represents path to backup fiel
         */
        void loadThisBackup(const std::string &_pathToBackupFile);

        /**
         * @brief Display Victory Scene
         */
        void displayVictoryScene();

        /**
         * @brief Display Defeat Scene
         */
        void displayDefeatScene();

        /**
         * @brief Display Players Panels in the scene InGame
         *
         * @param panelPos Position of all Panels in a vector of pair (x, y)
         */
        void displayPlayersPanels(std::vector<std::pair<size_t, size_t>> &panelPos);

        /**
         * @brief This function displays all cards and their parameters
         *
         * @param removeButtons A vector of all remove buttons coordinates
         * @param nextButtons A vector of all next buttons coordinates
         * @param prevButtons A vector of all previous buttons coordinates
         * @param x A pointer to an int that represents the x coordinate of the last displayed card
         */
        void displayCardsSettings(std::vector<std::pair<int, int>> &removeButtons, int *x);

        /**
         * @brief This function counts the number of files in a specific directory
         *
         * @param path A filesystem path related to a directory
         * @return Number of files (size_t)
         */
        size_t countFilesDirectory(const std::filesystem::path &path) const;

        /**
         * @brief Initialize all the containers that refer to the boxes of the pseudos
         *
         * @param mouseOnText A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
         * @param textBox A vector of rectangle that represents the boxes of the pseudos
         */
        void setTextBox(std::vector<bool> &mouseOnText, std::vector<Raylib::Rectangle> &textBox);

        /**
         * @brief Update all the containers that refer to the boxes of the pseudos
         *
         * @param mouseOnText A vector of boolean that represents if mouse is on box to position n with n < mouseOnText.size()
         * @param textBox A vector of rectangle that represents the boxes of the pseudos
         */
        void updateTextBox(std::vector<bool> &mouseOnText, const std::vector<Raylib::Rectangle> &textBox);

        /**
         * @brief Set pointer to Load Function
         *
         * @param loadFunc A pointer to Load function in the core
         */
        void setLoadFunc(std::function<void (std::string)>) override;

        /**
         * @brief Set pointer to Save Function
         *
         * @param saveFunc A pointer to Save function in the core
         */
        void setSaveFunc(std::function<void (std::array<std::size_t, 8>)>) override;

        /**
         * @brief Set the Restart Func
         *
         * @param restartFunc A pointer to Restart function in the core
         */
        void setRestartFunc(std::function<void ()>) override;

        /**
         * @brief Set pointer to Settings Function
         *
         * @param settingsFunc A pointer to Settings function in the core
         */
        void setSettingsFunc(std::function<void (std::array<std::size_t, 8>)>) override;

        /**
         * @brief Check Click on MapChoiceScene
         */
        void checkClickOnMapChoiceScene();

        /**
         * @brief Get time in good format from clock and return in minutes and second
         *
         * @return Time in format (MIN : SECOND)
         */
        std::string getTimeInFormat(void);

        /**
         * @brief Draw Players Head
         *
         * @param i A size_t
         * @param x A size_t
         * @param y A size_t
         */
        void drawPlayersHead(size_t i, size_t x, size_t y);
        /**
         * @brief Get players Data to the Game
         * 
         * @return std::vector<PlayerData> represents all the players data
         */
        std::vector<CharDictionary> getPlayersData() override;

    private:
        Raylib::Window _window;                     // Game window

        /**
         * @brief Game Settings
         * A vector of size_t
         * [0] -- TIMESTAMP --- (NO)
         * [1] -- _sets °
         * [2] -- _currentSet °
         * [3] -- _duration °
         * [4] -- _remaining time --- (NO)
         * [5] -- _aiNumber °
         * [6] -- _aiLevel °
         * [7] -- _allIntegers[2] - _aiNumber °
         */
        std::array<size_t, 8> _gameSettings = {0, 1, 1, 60, 60, 0, 1, 1};
        size_t _mapType = 0;                        // Type of Map
        size_t _sizeMap = 5;                            // Size of Map
        double _startingTime;                  // Get Time from raylib
        double _lastFrameTime;                  // Get Time every frame from raylib
        std::vector<std::string> _map;              // Map
        float masterVolume;                         // Master volume
        float musicVolume;                         // Master volume
        float sfxVolume;                         // Master volume
        std::vector<std::string> _userNames;        // A vector of all the users names
        std::pair<bool, void (XRay::*)()> _intro;   // Intro pointer to function
        Scene _scene = MENU;                   // Current scene
        std::vector<void (XRay::*)()> _scenesFunc;  // Array of pointers to function (a scene, a function)
        std::function<void ()> _pointerToRestartFunc;   // Pointer to Restart Func
        std::function<void (std::array<std::size_t, 8>)> _pointerToSaveFunc;   // Pointer to Save Func
        std::function<void (std::array<std::size_t, 8>)> _pointerToSettingsFunc;   // Pointer to Settings Func
        std::function<void (std::string)> _pointerToLoadFunc;   // Pointer to Load Func

        std::vector<bool> _playerTab{true, false, false, false};                     // A vector of boolean that represents if the player is an AI or not
        std::vector<Resources> _controlsTab{UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN};                   // A vector of resources (See in Resources.hpp) that represents if the controls
        std::array<int, 3> _allIntegers = {50, 400, 1};   // An array of main positions on this scene
        std::vector<std::pair<int, int>> _letterAndFrame; // A vector of infos about the boxes of pseudos
        std::vector<size_t> _card{36, 36, 36, 36};        // Cards (Blue or Yellow)
        size_t _nextOrNot;                                // A size_t to know if can go to next scene or not
        std::map<Scene, void (XRay::*)()> _scenesBack;         // Map of pointers to function and Scene (a scene, a pointer to function)
        std::map<Scene, void (XRay::*)()> _scenesBackBackup;   // Map of pointers to function and Scene (a scene, a pointer to function)
        bool _isPaused = false;                            // Boolean to know if game is on pause or not
        int m_isPaused = 2;                                // Int to know if game is on pause or not
        float _scrollingBack = 0.0f;                      // A variable for parallax

        std::vector<std::vector<std::pair<std::string, std::string>>> _playersStats; // A vector of a vector all the stats by player [Player -- (NameOfStat, Value)]...
        std::vector<std::pair<std::string, std::string>> _scores;                 // A vector of pair (username, score)
        std::vector<std::pair<std::string, std::string>> _bestScores;             // A vector of pair (username, score), List of Bests Scores
        std::vector<std::shared_ptr<IEntity>> _gameInfos;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
        std::vector<std::string> _backups;                                        // A vector of all the paths to backups files as a const std::vector<std::string>&

        std::map<Resources, std::shared_ptr<Raylib::Texture>> _resources; // Texture dictionary
        std::map<MusicResources, std::shared_ptr<Raylib::Music>> _musics; // Music dictionary
        std::map<SfxResources, std::shared_ptr<Raylib::Sound>> _sfx; // SFX dictionary
        std::vector<std::shared_ptr<IPlayerInput>> _playersInput{std::shared_ptr<IPlayerInput>(new MousePlayerInput())};
        PlayerSelector::Selector _pSelector; // 3D Camera
};

#include "XRay.inl"

#endif /* !XRAY_HPP_ */