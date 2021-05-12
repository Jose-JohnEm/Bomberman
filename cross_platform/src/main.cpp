/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(void)
{
    try {
        Core core;
        core.run();
    } catch (...) {
        std::cerr << "Error !! I catch something !" << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}