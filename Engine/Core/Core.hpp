/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <utility>
#include "XRay.hpp"
#include "Interfaces/IGraphical.hpp"
#include "Interfaces/IGame.hpp"

namespace Engine
{
    class Core {

        public:
            /**
             * @brief Construct a new Core object
             */
            Core();

            /**
             * @brief Destroy the Core object
             */
            ~Core();

            /**
             * @brief Run the core
             */
            void run(void);

            /**
             * @brief Break cleanly the game loop and save informations
             *
             * @return true or false
             */
            bool endGame(void);

            /**
             * @brief Save the best score(s) in a file
             */
            void saveBestScores(void);

            /**
             * @brief Get Backup Files
             */
            void getBackupFiles(void);

        private:
            std::shared_ptr<IGraphical> _graphical;                             // Graphical instance
            std::shared_ptr<IGame> _game;                                       // Game instance

            std::string _currentGame = "bomberman";                             // Game name

            IGraphical::Scene _scene;                                           // Current scene

            std::vector<std::string> _userNames;                                // User names
            std::vector<std::pair<std::string, std::string>> _gameHighScores;   // Game's high scores

            std::vector<std::string> _backups;                                // Paths of Backups Files

            bool _isPaused;                                                     // Pause flag
    };
}


#endif /* !CORE_HPP_ */