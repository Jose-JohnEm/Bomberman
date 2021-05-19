/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Irrlicht
*/

#ifndef IRRLICHT_HPP_
#define IRRLICHT_HPP_

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
#include <irrlicht/irrlicht.h>
#include "IGraphical.hpp"

class Irrlicht : public IGraphical {

    public:
    /**
     * @brief Construct a new Ray Lib object
     */
    Irrlicht();

    /**
     * @brief Destroy the Ray Lib object
     */
    ~Irrlicht() override;

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
     * @brief Check if we are in the game scene
     *
     * @return true if we are in the game scene and false otherwise
     */
    bool isInGameScene(void) const override;

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
     * @brief Set buffer to Draw textures
     */
    void beginDrawing(void) const override;

    /**
     * @brief Unset buffer to Draw textures
     */
    void endDrawing(void) const override;

    /**
     * @brief Close window
     */
    void closeWindow(void) const override;

    /**
     * @brief Draw any Text in parameters
     *
     * @param text Text you want to display
     * @param posX Position on x
     * @param posX Position on y
     * @param fontSize Size of your text you want to display
     */
    void drawText(const std::string &text, const int &posX, const int &posY, const int &fontSize) const override;

    /**
     * @brief Draw any Text in parameters
     *
     * @param text Text you want to display
     * @param posX Position on x
     * @param posX Position on y
     * @param fontSize Size of your text you want to display
     * @param font Path to font
     * @param color A Color
     */
    void drawTextFont(const std::string &text, const int &posX, const int &posY, const int &fontSize, const std::string &font, const std::string &color) const override;

    /**
     * @brief Display Menu
     */
    void displayMenu(void);

    /**
     * @brief Display Intro Scene
     */
    void displayIntro(void);

    /**
     * @brief Display Opening Scene
     */
    void displayOpening(void);

    /**
     * @brief This function must display the current scene. It is used in the game loop
     */
    void display(void) override;

    private:

        irr::IrrlichtDevice *_device;                    // Device
        irr::video::IVideoDriver *_driver;               // Driver
        irr::scene::ISceneManager *_sceneManager;        // Scene Manager

        std::vector<std::string> _userNames;                    // User names
        std::pair<bool, void (Irrlicht::*)()> _intro;   // Intro pointer to function
        Scene _scene = INTRO;                                   // Current scene
        std::vector<void (Irrlicht::*)()> _scenesFunc;  // Array of pointers to function (a scene, a function)
};

#include "Irrlicht.inl"

#endif /* !IRRLICHT_HPP_ */