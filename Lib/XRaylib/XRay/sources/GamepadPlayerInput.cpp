/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GamepadPlayerInput
*/

#include "GamepadPlayerInput.hpp"
#include "../../../Engine/Exception/MyException.hpp"

GamepadPlayerInput::GamepadPlayerInput(size_t pos)
{
    _pos = pos;
}

GamepadPlayerInput::~GamepadPlayerInput()
{
}

bool GamepadPlayerInput::shouldGoToEast(void) const
{
    return Raylib::Gamepad::isGamepadButtonDown(_pos, 2);
}

bool GamepadPlayerInput::shouldGoToWest(void) const
{
    return Raylib::Gamepad::isGamepadButtonDown(_pos, 4);
}

bool GamepadPlayerInput::shouldGoToNorth(void) const
{
    return Raylib::Gamepad::isGamepadButtonDown(_pos, 1);
}

bool GamepadPlayerInput::shouldGoToSouth(void) const
{
    return Raylib::Gamepad::isGamepadButtonDown(_pos, 3);
}

bool GamepadPlayerInput::shouldChangeToPrev(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 4);
}

bool GamepadPlayerInput::shouldChangeToNext(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 2);
}

bool GamepadPlayerInput::shouldSimulateAClick(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 7);
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTryGamepadException() {
    try
    {   GamepadPlayerInput test;
        test.shouldGoToEast();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldGoToWest();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldGoToNorth();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldGoToSouth();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldChangeToPrev();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldChangeToNext();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {   GamepadPlayerInput test;
        test.shouldSimulateAClick();

    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}