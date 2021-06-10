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
            Save(const std::array<std::size_t, 7> &settings, const std::vector<Game::Player> &player, const Game::MapGeneration &map);

            /**
            * @brief Construct the Save object to unload a backup file (Copy Constructor)
            */
            Save(const std::string &filename);

            /**
            * @brief Destroy the Save object
            */
            ~Save();

            /**
            * @brief Write the save of game's settings
            * 
            * @param settings A const reference to a std::array
            */
           void setSaveGameSettings(std::ofstream &backupFile, const std::array<std::size_t, 7> &settings);

            /**
            * @brief Write the save of game's players
            * 
            * @param players A const reference to a std::vector of Player
            */
           void setSavePlayer(std::ofstream &backupFile, const std::vector<Game::Player> &players);

            /**
            * @brief Write the save of game's map
            * 
            * @param map A const reference to a std::array
            */
           void setSaveMap(std::ofstream &backupFile, const Game::MapGeneration &map);

        private:
            std::array<std::size_t, 7> _settings; // An array of 7 size_t
            std::vector<Game::Player> _players; // A vector of players
            Game::MapGeneration _map; // The map

            /**
            * @brief Get the current date and time (for save's filename)
            * 
            * @return A std::string
            */
            std::string getCurrentDateTime(void) const;
    };

    #include "Save.inl"
}

#endif /* !SAVE_HPP_ */
