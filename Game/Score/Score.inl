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
    _score = score * getScoreMultiplicator();
}

inline float Score::getScoreMultiplicator() const
{
    // size_t score = getScore();
    // size_t percentage = (time * 100) / remaining_time;

    // if (percentage > time * 0.5)
    //     return 1.5;
    // else if (percentage > time * 0.3)
    //     return 1.3;
    // else if (percentage < time * 0.3)
    //     return 1;

}