/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

inline std::string Game::Save::getSaveFilename(void) const
{
    return _filename;
}

inline void Game::Save::setSaveFilename(std::string const & filename)
{
    _filename = filename;
}

inline std::string Game::Save::createSaveFile()
{
    std::string fileName(".backups/" + getCurrentDateTime() + ".backup");
    std::replace(fileName.begin(), fileName.end(), ' ', '-');
    std::ofstream backupFile(fileName);

    if (backupFile.is_open())
    {
        backupFile.close();
    }
    return fileName;
}

inline void Game::Save::setSaveGameSettings(const std::array<std::size_t, 7> &settings)
{
    std::ofstream backupFile(_filename);

    backupFile << "settings timestamp " << "value" << std::endl;
    backupFile << "settings sets_nbr " << "value" << std::endl;
    backupFile << "settings sets_id " << "value" << std::endl;
    backupFile << "settings time_game " << "value" << std::endl;
    backupFile << "settings time_remaining " << "value" << std::endl;
    backupFile << "settings ai_nbr " << "value" << std::endl;
    backupFile << "settings ai_lvl " << "value" << std::endl;
    backupFile << "settings players_nbr " << "value" << std::endl;
}