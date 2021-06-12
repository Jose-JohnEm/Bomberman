/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <array>
#include <fstream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include "../includes/Settings.hpp"
#include "../Player/Player.hpp"
#include "../Map/Map.hpp"

namespace Game
{
    class Save
    {
        public:
            /**
            * @brief Construct the Save object to create a backup file (Copy Constructor)
            */
            Save(const std::array<std::size_t, 8> &settings, const std::vector<Game::Player> &player, const Game::Map &map);

            /**
            * @brief Construct the Save object to read a backup file and load its content into an IGame object (Copy Constructor)
            */
            Save(const std::string &fileName);

            /**
            * @brief Destroy the Save object
            */
            ~Save();

            /**
             * @brief Get the Settings arrray from the backup file
             *
             * @return An std::array<std::size_t, 8> which represents the Game settings
             */
            std::array<std::size_t, 8> getSettings(void) const;

            /**
             * @brief Get the Players from the backup file
             *
             * @return std::vector<Game::Player>
             */
            std::vector<Game::Player> getPlayers(void) const;

            /**
             * @brief Get the Map from the backup file
             *
             * @return Game::Map object
             */
            Game::Map getMap(void) const;

        private:
            std::array<std::size_t, 8> _settings; // An array of 7 size_t
            std::vector<Game::Player> _players; // A vector of players
            Game::Map _map; // The map

            /**
            * @brief Get the current date and time (for save's filename)
            *
            * @return A std::string
            */
            std::string getCurrentDateTime(void) const;

            /**
            * @brief Create a name for a new backup file
            *
            * @return A std::string
            */
            std::string createBackupName(void) const;

            /**
            * @brief Write game settings
            *
            * @param settings A reference to a stream
            */
            void writeSettings(std::ofstream &os) const;

            /**
            * @brief Write game players infos
            *
            * @param players A reference to a stream
            */
            void writePlayersInfos(std::ofstream &os) const;

            /**
            * @brief Write the map
            *
            * @param map A reference to a stream
            */
            void writeMap(std::ofstream &os) const;

            /**
             * @brief Parse a specific backup file
             *
             * @param backupFile An ifstream corresponding to a backup file
             */
            void parseBackup(std::ifstream &backupFile);

            /**
             * @brief Get the Input Arguments (line split by separator)
             *
             * @param line A const reference to a string (string get by getline function)
             * @param separator A const reference to a char (Use to split a string)
             * @return std::vector<std::string> (a vector composed of words's group)
             */
            std::vector<std::string> getInputArguments(const std::string &line, const char &separator) const;

            /**
             * @brief Parse settings informations
             *
             * @param settings A vector of strings containing settings
             */
            void parseSettings(const std::vector<std::string> &settings);

            /**
             * @brief Parse players informations
             *
             * @param playersInfos A vector of strings containing players infos
             */
            void parsePlayers(const std::vector<std::string> &playersInfos);

            /**
             * @brief Parse player informations
             *
             * @param player A Game::Player object
             * @param playersInfos A vector of strings containing player infos
             */
            void parsePlayer(Game::Player &player, const std::vector<std::string> &playerInfos) const;
    };

    #include "Save.inl"
}

#endif /* !SAVE_HPP_ */
