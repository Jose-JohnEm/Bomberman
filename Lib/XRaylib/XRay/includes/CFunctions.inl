/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** CFunctions
*/

inline std::pair<size_t, size_t> CFunctions::generatePairOfRandomIntegers(size_t limitOfFirst, size_t limitOfSecond)
{
    int i = 0, j = 0;

    srand((unsigned)time(0));
    i = (rand()%limitOfFirst)+0;
    srand((unsigned)time(0));
    j = (rand()%limitOfSecond)+0;

    return std::make_pair(i, j);
}
