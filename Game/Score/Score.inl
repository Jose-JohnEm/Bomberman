/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Score
*/

inline size_t Score::getScore() const
{
    return _score;
}

inline void Score::setScore(size_t const &score)
{
    size_t scorepowerups = std::accumulate(_player.getPowerUps().begin(), _player.getPowerUps().end(), 0);
    _score = (_player.getKills() * 200) + scorepowerups + (_player.getBrokenWalls() * 10);
}

inline float Score::getScoreMultiplicator(size_t const &score) const
{
    //TODO: Create Game::Settings Class
    //TODO: We must agree this method (Lucas & Mehdi) !
    // size_t score = getScore();
    // size_t percentage = (time * 100) / remaining_time;

    // if (percentage > time * 0.5)
    //     return 1.5;
    // else if (percentage > time * 0.3)
    //     return 1.3;
    // else if (percentage < time * 0.3)
    //     return 1;
    return 0;
}