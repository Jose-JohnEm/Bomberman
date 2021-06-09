/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

inline std::string Player::getName() const
{
    return _name;
}

inline std::pair<float, float> Player::getPositions() const
{
    return _positions;
}

inline size_t Player::getBrokenWalls() const
{
    return _brokenWalls;
}

inline size_t Player::getKills() const
{
    return _kills;
}

inline std::array<size_t, 7> getPowerUps() const
{
    return _powerUps;
}

inline void Player::setName(const std::string &name)
{
    _name = name;
}

inline void Player::setPositions(const std::pair<float, float> &positions)
{
    _positions = positions;
}

inline void Player::setBrokenWalls(const size_t &brokenWalls)
{
    _brokenWalls = brokenWalls
}

inline void Player::setKills(const size_t &kills)
{
    _kills = kills;
}

inline void setPowerUps(const std::array<size_t, 5> &powerUps)
{
    _powerUps = powerUps;
}
