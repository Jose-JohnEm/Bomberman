/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "IEntity.hpp"

class IGame {

    public:
        /**
         * @brief Destroy the IGame object
         */
        virtual ~IGame() = default;

        /**
         * @brief Getter for the score
         * @return Score of the current game in string
         */
        virtual const std::string &getScore() const = 0;

        /**
         * @brief Call this function to restart the entire game. The game must reset himself.
         */
        virtual void restart() = 0;

        /**
         * @brief Getter for the score
         *
         * @return A array of pair (Player, Score) of the current game
         */
        virtual const std::vector<std::pair<std::string, std::string>> &getScores() const = 0;

        /**
         * @brief Get the Entities
         *
         * @return Return all the game's entities to display in a const std::vector<std::shared_ptr<Thing>>&
         */
        virtual const std::vector<std::shared_ptr<IEntity>> &getEntities() const = 0;

        /**
         * @brief Get the Players Stats
         *
         * @return All the stats [PlayerName -- (NameOfStat, Value)] in a map
         */
        virtual const std::map<std::string, std::pair<std::string, std::string>> &getPlayersStats() const = 0;

        /**
         * @brief updateGame function should be called in a loop. It's used to advance the game and update all logic.
         * The game must manage time on it's own.
         */
        virtual void updateGame() = 0;

        /**
         * @brief Check if the game is over
         * @return bool which indicate if the game is over
         */
        virtual bool isGameOver() const = 0;

        /**
         * @brief Get the name of the game
         * @return Name of the game
         */
        virtual const std::string &getGameName() const = 0;
};

#endif /* !IGAME_HPP_ */
