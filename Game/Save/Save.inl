/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

inline void Game::Save::setSaveGameSettings(std::ofstream &backupFile, const std::array<std::size_t, 7> &settings)
{
    backupFile << "settings timestamp " << "value" << std::endl;
    backupFile << "settings sets_nbr " << "value" << std::endl;
    backupFile << "settings sets_id " << "value" << std::endl;
    backupFile << "settings time_game " << "value" << std::endl;
    backupFile << "settings time_remaining " << "value" << std::endl;
    backupFile << "settings ai_nbr " << "value" << std::endl;
    backupFile << "settings ai_lvl " << "value" << std::endl;
    backupFile << "settings players_nbr " << "value" << std::endl;
}

inline void Game::Save::setSavePlayer(std::ofstream &backupFile, const std::vector<Game::Player> &players)
{
    backupFile << "settings name " << "value" << std::endl;
    backupFile << "settings life " << "value" << std::endl;
    backupFile << "settings pos " << "value" << std::endl;
    backupFile << "settings powerups " << "value" << std::endl;
    backupFile << "settings broken_walls " << "value" << std::endl;
    backupFile << "settings kills " << "value" << std::endl;
}

inline void Game::Save::setSaveMap(std::ofstream &backupFile, const Game::MapGeneration &map)
{
    backupFile << "settings width " << "value" << std::endl;
    backupFile << "settings height " << "value" << std::endl;
    backupFile << "settings map " << "value" << std::endl;
}