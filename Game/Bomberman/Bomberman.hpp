/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-prince.miyigbena
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include <map>
#include "Interfaces/IGame.hpp"
#include "../Map/Map.hpp"
#include "../Save/Save.hpp"
#include "../MotionlessEntity/MotionlessEntity.hpp"

namespace Game
{
    class Bomberman : public IGame {

        public:

            /**
             * @brief Construct a new Bomberman object
             */
            Bomberman();

            /**
             * @brief Destroy the Bomberman object
             */
            ~Bomberman() override;

            /**
             * @brief Call this function to restart the entire game. The game must reset himself.
             */
            void restart(void) override;

            /**
             * @brief Call this function to save the game.
             *
             * @param settings Backup Container
             */
            void saveGame(const std::array<std::size_t, 8> &settings) override;

            /**
             * @brief Call this function to load a game.
             *
             * @param backupFilePath Backup File Path
             */
            void loadGame(const std::string &backupFilePath) override;

            /**
             * @brief Set the Users Names
             *
             * @param userNames A vector of all the users names as a const std::vector<std::string>&
             */
            void setUserNames(const std::vector<std::string> &userNames) override;

            /**
             * @brief Set the game settings
             *
             * @param settings An array of 8 size_t
             */
            void setSettings(const std::array<std::size_t, 8> &settings) override;

            /**
             * @brief Get the game settings
             *
             * @return An array of 8 size_t
             */
            std::array<std::size_t, 8> getSettings(void) const override;

            /**
             * @brief Getter for the score
             *
             * @return A array of pair (Player, Score) of the current game
             */
            const std::vector<std::pair<std::string, std::string>> &getScores(void) const override;

            /**
             * @brief Get the Entities
             *
             * @return Return all the game's entities to display in a const std::vector<std::shared_ptr<Thing>>&
             */
            const std::vector<std::shared_ptr<IEntity>> &getEntities(void) const override;

            /**
             * @brief Get the Players Stats
             *
             * @return All the stats [PlayerName -- (NameOfStat, Value)] in a vector of vector
             */
            const std::vector<std::vector<std::pair<std::string, std::string>>> &getPlayersStats(void) const override;

            /**
             * @brief updateGame function should be called in a loop. It's used to advance the game and update all logic.
             * The game must manage time on it's own.
             */
            void updateGame(void) override;

            /**
             * @brief Check if the game is over
             * @return bool which indicate if the game is over
             */
            bool isGameOver(void) const override;

            /**
             * @brief Get the name of the game
             * @return Name of the game
             */
            const std::string &getGameName(void) const override;

            /**
             * @brief This function is to init all entities (_entites)
             */
            void initEntities();

            /**
             * @brief This function is to init all player(s) stats
             */
            void initPlayersStats();

            /**
             * @brief This function is to update state of all entities (_entites)
             */
            void updateEntities();

            /**
             * @brief This function is to update score(s) of player(s)
             */
            void updateScores();

            /**
             * @brief This function is to update player(s) stats
             */
            void updatePlayersStats();

            /**
             * @brief Get the Map
             */
            std::vector<std::string> &getMap(const size_t &size) override;

            /**
             * @brief Set the Map Type
             *
             * @param mapType A size_t
             */
            void setMapType(const std::size_t &mapType) override;

            /**
             * @brief Do A player Action
             *
             * @param pos Pos of player [0 -- 1 -- 2 -- 3]
             * @param action Action in a string ["goEast", "goNorth", "goSouth", "goWest", "dropBomb"]
             */
            void doPlayerAction(const size_t pos, const std::string action) override;

            /**
             * @brief Set the current Players data
             *
             * @param playersData Dictionary of the players' data
             */
            void setPlayers(const std::vector<CharDictionary> &playersData) override;

        private:
            std::array<std::size_t, 8> _settings; // Game settings
            std::vector<std::string> _map; // Game map
            std::size_t _mapType;                             // A size_t that represents map type
            std::vector<std::vector<std::pair<std::string, std::string>>> _playersStats; // A vector of vector all the stats [Player -- (NameOfStat, Value)]...
            std::vector<std::pair<std::string, std::string>> _scores;                 // A vector of pair (username, score)
            std::vector<std::shared_ptr<IEntity>> _entities;                         // A vector of shared pointer that represent all the entities to display. Ex : Map, Score, UserInfo, Button

            bool _gameOver = false;                             // A boolean to know if the game is over or not
            bool _isPaused;                             // A boolean to know if the game is in pause or not
            std::string _gameName;                      // A string that represents the game name
            std::vector<std::string> _userNames;        // A vector of all the users names
            std::vector<CharDictionary> _players;
    };
}

#include "Bomberman.inl"

#endif /* !BOMBERMAN_HPP_ */