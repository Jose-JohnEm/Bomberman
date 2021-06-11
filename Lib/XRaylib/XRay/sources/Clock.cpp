/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

Clock::Clock()
:_start(clock())
{

}

Clock::~Clock()
{

}

bool Clock::doesTimeElapsed(const float &time, const bool &reset)
{
    bool res = false;

    if ((float)(clock() - _start) / CLOCKS_PER_SEC >= time)
    {
        res = true;
        if (reset)
            _start = clock();
    }
    return res;
}

float Clock::getElapsedTime()
{
    return (float)(clock() - _start / CLOCKS_PER_SEC);
}