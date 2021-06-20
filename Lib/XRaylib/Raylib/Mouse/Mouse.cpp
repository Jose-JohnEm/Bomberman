/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Mouse
*/

#include "Mouse.hpp"
#include "../../../Engine/Exception/MyException.hpp"

Raylib::Mouse::Mouse()
{
}

Raylib::Mouse::~Mouse()
{
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTryisButtonPressed() {
    try
    {   Raylib::Mouse test;
        size_t button;
        test.isButtonPressed(button);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisButtonDown() {
    try
    {   Raylib::Mouse test;
        size_t button;
        test.isButtonDown(button);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisButtonReleased() {
    try
    {   Raylib::Mouse test;
        size_t button;
        test.isButtonReleased(button);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisButtonUp() {
    try
    {   Raylib::Mouse test;
        size_t button;
        test.isButtonUp(button);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetMouseX() {
    try
    {   Raylib::Mouse test;
        test.getMouseX();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetMouseY() {
    try
    {   Raylib::Mouse test;
        test.getMouseY();
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}