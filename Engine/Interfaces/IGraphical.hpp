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
            /// This scene is the intro of our game
            INTRO,
            /// This scene is the main menu of our game
            MAIN_MENU,
            /// This is the game scene, it should display the game. It can display game information, buttons
            /// (restart, go to main menu, pause game).
            GAME,
            PLAYMENU,
            HOWTOMENU,
            SETTINGSMENU,
            /// This scene is the main menu of our game
            MODEMENU,
            MAPMENU,
            LOADMENU,
            DRAWMENU,
            GAMEIN,
            PAUSEIN,
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
<<<<<<< HEAD
         * @brief Check if we are in the game scene
         *
         * @return true if we are in the game scene and false otherwise
         */
        virtual bool isInGameScene(void) const = 0;

        /**
=======
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
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
         * @param info A map of all the stats [PlayerName -- (NameOfStat, Value)]...
         */
        virtual void setPlayersStats(const std::map<std::string, std::pair<std::string, std::string>> &info) = 0;

        /**
         * @brief Get the Users Names
         *
         * @return A vector of all the users names as a const std::vector<std::string>&
         */
        virtual const std::vector<std::string> &getUserNames(void) const = 0;

        /**
<<<<<<< HEAD
=======
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
>>>>>>> aea5ca9 (Add Backups, NewGame, LoadGame and Players Scenes (PrinceIsGod))
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
};

#endif /* !IGRAPHICAL_HPP_ */
