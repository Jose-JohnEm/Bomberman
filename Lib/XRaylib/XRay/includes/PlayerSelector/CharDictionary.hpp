/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** CharDictionary
*/

#ifndef CHARDICTIONARY_HPP_
#define CHARDICTIONARY_HPP_

#include <string>
#include <vector>
#include "Color/Color.hpp"

struct CharDictionary
{
    std::string obj;
    std::string texture;
    float scalable;
    std::string name;
    Raylib::Color color;
    std::vector<std::string> animations;
};

#endif /* !CHARDICTIONARY_HPP_ */
