/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include "IEntity.hpp"

class IGraphical {

    public:
        enum Scene {
            /// This scene is the main menu of our game
            MENU,
            /// This scene is the one used to choose the game mode
            GAME_MODE,
            /// This scene represents the HELP section, containing information such as how to play etc
            HELP,
            /// This scene represents the settings section
            SETTINGS,
            /// This scene is the one used to choose the players and the different game parameters
            PLAYER_CHOICE,
<<<<<<< HEAD
=======
            /// This scene is the one used to choose map, sets and time
            MAP_CHOICE,
>>>>>>> release/v0.3
            /// This scene is the one used to load a game backup
            LOAD_GAME,
            /// This is the scene where the game is in progress
            IN_GAME,
<<<<<<< HEAD
=======
            /// This is the scene where the display winner options
            VICTORY,
            /// This is the scene where the display loser options
            DEFEAT,
>>>>>>> release/v0.3
            /// This scene represents the end of the game
            END_GAME
        };

        /**
         * @brief Destroy the IGraphical object
         */
        virtual ~IGraphical(void) = default;

        /**
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        virtual bool shouldCloseWindow(void) const = 0;

        /**
         * @brief This function sets the list of scores. First element of the pair is the username, the second is the score.
         *
         * @param scores A vector of pair (username, score)
         */
        virtual void setScores(const std::vector<std::pair<std::string, std::string>> &scores) = 0;

        /**
         * @brief This function sets the list of bests scores. First element of the pair is the username, the second is the score.
         *
         * @param scores A vector of pair (username, score)
         */
        virtual void setBestScores(const std::vector<std::pair<std::string, std::string>> &scores) = 0;

        /**
         * @brief This is called in a loop when the game is running. This vector contains entities that should be displayed in the game scene.
         *
         * @param gameInfos A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button
         */
        virtual void updateGameInfos(const std::vector<std::shared_ptr<IEntity>> &gameInfos) = 0;

        /**
         * @brief This is called in a loop when the game is running. Sets the current informations about players and their stats. The first element of the pair
         *  is the category (e.g. Score), the second is the value (e.g. 200).
         *
<<<<<<< HEAD
         * @param info A map of all the stats [PlayerName -- (NameOfStat, Value)]...
         */
        virtual void setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info) = 0;
=======
         * @param info A vector of a vector all the stats by player [Player -- (NameOfStat, Value)]...
         */
        virtual void setPlayersStats(const std::vector<std::vector<std::pair<std::string, std::string>>> &info) = 0;
>>>>>>> release/v0.3

        /**
         * @brief Get the Users Names
         *
         * @return A vector of all the users names as a const std::vector<std::string>&
         */
        virtual const std::vector<std::string> &getUserNames(void) const = 0;

        /**
         * @brief Get the paths to all backups files
         *
         * @return A vector of all the paths to backups files as a const std::vector<std::string>&
         */
        virtual const std::vector<std::string> &getBackups(void) const = 0;

        /**
         * @brief Get the paths to all backups files
         *
         * @param backups A vector of all the paths to backups files as a const std::vector<std::string>&
         */
        virtual void setBackups(const std::vector<std::string> &backups) = 0;

        /**
         * @brief Returns the current scene.
         *
         * @return The scene (MAIN_MENU, GAME, END_GAME...), the step where we are in the window
         */
        virtual Scene getScene(void) const = 0;

        /**
         * @brief Set the current scene.
         *
         * @param scene The scene (MAIN_MENU, GAME, END_GAME...), the step where we are in the window
         */
        virtual void setScene(const Scene &scene) = 0;

        /**
         * @brief Close window
         */
        virtual void closeWindow(void) const = 0;

        /**
         * @brief Set buffer to Draw textures
         */
        virtual void beginDrawing(void) const = 0;

        /**
         * @brief Unset buffer to Draw textures
         */
        virtual void endDrawing(void) const = 0;

        /**
         * @brief This function must display the current scene. It is used in the game loop
         */
        virtual void display(void) = 0;
<<<<<<< HEAD
=======

        /**
         * @brief Set the Map
         *
         * @param map A const std::vector<std::string>&
         */
        virtual void setMap(std::vector<std::string> &map) = 0;

        /**
         * @brief Get the size and type of Map
         *
         * @return A pair of size_t
         */
        virtual std::pair<size_t, size_t> getMapSizeAndType() = 0;
>>>>>>> release/v0.3
};

#endif /* !IGRAPHICAL_HPP_ */
