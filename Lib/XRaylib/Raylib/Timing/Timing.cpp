/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Timing
*/

#include "../../../Engine/Exception/MyException.hpp"

#include "Timing.hpp"

Raylib::Timing::Timing()
{
}

Raylib::Timing::~Timing()
{
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrysetTargetFPS() {
    try
    {   Raylib::Timing test;
        int fps;
        test.setTargetFPS(fps);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetFPSS() {
    try
    {   Raylib::Timing test;
        test.getFPS();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetFrameTime() {
    try
    {   Raylib::Timing test;
        test.getFrameTime();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetTime() {
    try
    {   Raylib::Timing test;
        test.getTime();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}