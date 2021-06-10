/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** main
*/

#include <iostream>
#include "Core/Core.hpp"
#include "../Game/Save/Save.hpp"
#include "../Game/Player/Player.hpp"
#include "../Game/Map/MapGeneration.hpp"

int main(void)
{
    std::array<size_t, 7> settings = {};
    std::vector<Game::Player> players;
    Game::MapGeneration map(15, 15);
    Game::Save save(settings, players, map);
    try {
        Engine::Core core;
        core.run();
    } catch (...) {
        std::cerr << "Error !! I catch something !" << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}