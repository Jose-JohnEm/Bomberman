/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include "XRay.hpp"
#include "Interfaces/IGraphical.hpp"
<<<<<<< HEAD
=======
#include "../../Game/includes/Bomberman.hpp"
>>>>>>> release/v0.3
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

<<<<<<< HEAD
=======

>>>>>>> release/v0.3
        private:
            std::shared_ptr<IGraphical> _graphical;                             // Graphical instance
            std::shared_ptr<IGame> _game;                                       // Game instance

            std::string _currentGame = "bomberman";                             // Game name

            IGraphical::Scene _scene = IGraphical::MENU;                        // Current scene

            std::vector<std::string> _userNames;                                // User names
            std::vector<std::pair<std::string, std::string>> _gameHighScores;   // Game's high scores
            std::vector<std::string> _backups;                                  // Paths of Backup Files

<<<<<<< HEAD
            bool _isPaused;                                                     // Pause flag
=======
            bool _isPaused = false;                                                     // Pause flag
>>>>>>> release/v0.3
    };
}

#endif /* !CORE_HPP_ */