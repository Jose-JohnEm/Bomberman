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

        private:
            std::array<std::size_t, 7> _settings; // An array of 7 size_t
            std::vector<Game::Player> _players; // A vector of players
            Game::MapGeneration _map; // The map

            // TODO: doc
            std::string getCurrentDateTime(void) const;
    };

    #include "Save.inl"
}

#endif /* !SAVE_HPP_ */
