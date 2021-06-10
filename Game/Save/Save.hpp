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
#include <algorithm>
#include "../includes/Settings.hpp"
#include "../Player/Player.hpp"
#include "../Map/MapGeneration.hpp"

namespace Game
{
    class Save
    {
        public:
            /**
            * @brief Construct the Save object to load a backup file (Copy Constructor)
            */
            Save(const std::array<std::size_t, 8> &settings, const std::vector<Game::Player> &player, const Game::MapGeneration &map);

            /**
            * @brief Construct the Save object to unload a backup file (Copy Constructor)
            */
            Save(const std::string &fileName);

            /**
            * @brief Destroy the Save object
            */
            ~Save();

        private:
            std::array<std::size_t, 8> _settings; // An array of 7 size_t
            std::vector<Game::Player> _players; // A vector of players
            Game::MapGeneration _map; // The map

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
    };

    #include "Save.inl"
}

#endif /* !SAVE_HPP_ */
