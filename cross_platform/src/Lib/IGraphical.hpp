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
#include "../Game/IEntity.hpp"

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
         * @brief Initialize window and OpenGL context
         *
         * @param width Width of the Window
         * @param height Height of the Window
         * @param title Title of the Window
         */
        virtual void initWindow(const int &width, const int &height, const std::string &title) = 0;

        /**
         * @brief Check if the window should be close
         *
         * @return true if the window should close and false otherwise
         */
        virtual bool shouldCloseWindow(void) = 0;

        /**
         * @brief Check if we are in the game scene
         *
         * @return true if we are in the game scene and false otherwise
         */
        virtual bool isInGameScene(void) = 0;

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
        virtual void setBestsScores(const std::vector<std::pair<std::string, std::string>> &scores) = 0;

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
        virtual const std::vector<std::string> &getUsersNames(void) = 0;

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
        virtual void setScene(Scene scene) = 0;

        /**
         * @brief Close window
         */
        virtual void closeWindow(void) = 0;

        /**
         * @brief Set buffer to Draw textures
         */
        virtual void beginDrawing(void) = 0;

        /**
         * @brief Unset buffer to Draw textures
         */
        virtual void endDrawing(void) = 0;

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         */
        virtual void drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) = 0;

        /**
         * @brief Draw any Text in parameters
         *
         * @param text Text you want to display
         * @param posX Position on x
         * @param posX Position on y
         * @param fontSize Size of your text you want to display
         * @param font Path to font
         */
        virtual void drawTextFont(const std::string &text, const int &posX, const int &posY, const int &fontSize, const std::string &font, const std::string &color) = 0;

        /**
         * @brief This function must display the current scene. It is used in the game loop
         */
        virtual void display(void) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
